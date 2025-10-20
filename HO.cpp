/**
 * @file HO.cpp
 * @brief Implementations to simulate and visualize Harmonic Oscillations
 * @author Cele Rodriguez <celerodr@usc.edu>
 * @date 2025-10-18
 */
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include "HO.h"

using namespace std;

SpringSystem::SpringSystem(double m, double sc, double rc, double x, double v, double af, double om2) : omega2(om2), ampf(af), mass(m), k(sc), b(rc), beta(rc/(2 * m)), x0(x), v0(v), omega(sqrt(sc/m)) {
	amp = sqrt(pow(x0, 2) + pow(v0/omega, 2));
	delta = acos(x0/amp);
	T = 2 * PI / omega;
	omega1 = beta < omega ? sqrt(pow(omega,2) - pow(beta, 2)) : 0;
	deltaf = atan(2 * beta * omega2 / (pow(omega,2) - pow(omega2, 2)));
}
void SpringSystem::shmPosition(double time[], double arr[], int size) {
  for (int i = 0; i <= size; i++) {
  	arr[i] = amp * cos(omega * time[i] - delta);  
  }
}
void SpringSystem::shmVelocity(double time[], double arr[], int size) {
	for (int i = 0; i <= size; i++) {
		arr[i] = -amp * omega * sin(omega * time[i] -delta);
	}
}
void SpringSystem::write(string fileName, double posArr[], double velArr[], double mom[], double kin[], double pot[], double times[], int size) {
	fstream fs (fileName, fstream::out);
	if (fs.is_open()) {
		fs << "time,x-position,velocity,momentum,kinetic energy,potential energy\n";
		for (int i = 0; i <= size; i++) {
			fs << times[i] << ',' << posArr[i] << 				',' << velArr[i] << ',' <<  mom[i] 
		   << ',' << kin[i] << ',' << pot[i] << endl;
		}

		fs.close();
	} else {cout << "err";}
}
double SpringSystem::getPeriod() {
	return T;
}

void SpringSystem::momentum(double time[], double mom[], double vel[], int size) {
	for (int i = 0; i <= size; i++) {
		mom[i] = mass * vel[i];
	}
}

void SpringSystem::kinEnergy(double time[], double kin[], double mom[], int size) {
	for (int i = 0; i <= size; i++) {
		kin[i] = pow(mom[i], 2) / (2 * mass);
		
	}
}

void SpringSystem::potEnergy(double time[], double pot[], double pos[], int size) {
	for (int i = 0; i <= size; i++) {
		pot[i] = k * pow(pos[i], 2) / 2;
	}
}

void SpringSystem::dampedPosition(double time[], double arr[], int size) {
	if (abs(beta-omega) < 0.1) {
		cout << "eq\n";
		double c1 = x0;
		double c2 = v0 + beta * x0;
	
		for (int i = 0; i <= size; i++) {
			arr[i] = pow(2.71828, -beta * time[i]) * (c1 + c2 * time[i]);	
		}
	} else if (beta > omega) {
		cout << "great\n";
		double r1 = -beta + sqrt(pow(beta, 2) - pow(omega, 2));
		double r2 = -beta - sqrt(pow(beta, 2) - pow(omega, 2));
		double c1 = (r2 * x0 - v0) / (r2 - r1); 
		double c2 = x0 - c1;
		double exp1 = -(beta - sqrt(pow(beta, 2) - pow(omega, 2)));
		double exp2 = -(beta + sqrt(pow(beta, 2) - pow(omega, 2)));
		for (int i = 0; i <= size; i++) {
		
			arr[i] = c1 * pow(2.71828, exp1 * time[i]) + c2 * pow(2.71828, exp2 * time[i]); 
		}
	} else {
		
		cout << "less\n";
for (int i = 0; i <= size; i++) {
			arr[i] = amp * pow(2.71828, -beta * time[i] ) * cos(omega1 * time[i] - delta);
		}

	}
}

void SpringSystem::dampedVelocity(double time[], double arr[], int size) {
	cout << omega << endl;
	if (abs(beta - omega) < 0.1) {
	double c1 = x0;
		double c2 = v0 + beta * x0;
		cout << c1 << ' ' << c2 << endl;
		for (int i = 0; i <= size; i++) {
			arr[i] = pow(2.71828, -beta * time[i]) * (-beta * c1 + c2 - c2 * beta * time[i]); 
		}
		}
	 else if (beta > omega) {
		double r1 = -beta + sqrt(pow(beta, 2) - pow(omega, 2));
		double r2 = -beta - sqrt(pow(beta, 2) - pow(omega, 2));
		double c1 = (r2 * x0 - v0) / (r2 - r1); 

		double c2 = x0 - c1;
		double exp1 = -(beta - sqrt(pow(beta, 2) - pow(omega, 2)));
		double exp2 = -(beta + sqrt(pow(beta, 2) - pow(omega, 2)));
		cout << c1 << ' ' << c2 << ' ' << exp1 << ' ' << exp2 << endl;
		for (int i = 0; i <= size; i++) {
		
			arr[i] = exp1 * c1 * pow(2.71828, exp1 * time[i]) + exp2 * c2 * pow(2.71828, exp2 * time[i]); 
		}
	} else {
		for (int i = 0; i <= size; i++) {
			arr[i] = amp * pow(2.71828, -beta * time[i] ) * (-beta * cos(omega1 * time[i] - delta) - omega1 * sin(omega1 * time[i] - delta));
			}	
	}
}

void SpringSystem::forcedPosition(double time[], double arr[], int size) {

	double f0 = ampf/mass;
	double A = sqrt(pow(f0, 2)  / (pow(pow(omega, 2) - pow(omega2, 2), 2) + pow(2 * beta * omega2, 2)));
	dampedPosition(time, arr, size);

	for (int i = 0; i <= size; i++) {
		arr[i] += A * cos(omega2 * time[i] - deltaf);
	}
}

void SpringSystem::forcedVelocity(double time[], double arr[], int size) {
	double f0 = ampf/mass;
	double A = sqrt(pow(f0, 2)  / (pow(pow(omega, 2) - pow(omega2, 2), 2) + pow(2 * beta * omega2, 2)));

	dampedVelocity(time, arr, size);

	for (int i = 0; i <= size; i++) {
		arr[i] += -A * omega2 * sin(omega2 * time[i] - deltaf);
	}

}

