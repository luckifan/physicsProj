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

SpringSystem::SpringSystem(double m, double sc, double x, double v) : mass(m), k(sc), x0(x), v0(v), omega(sqrt(sc/m)) {
	amp = sqrt(pow(x0, 2) + pow(v0/omega, 2));
	delta = acos(x0/amp);
	T = 2 * PI / omega;
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
void SpringSystem::write(string fileName, double posArr[], double velArr[], double times[], int size) {
	fstream fs (fileName, fstream::out);
	if (fs.is_open()) {
		fs << "time,x-position,velocity\n";
		for (int i = 0; i <= size; i++) {
			fs << times[i] << ',' << posArr[i] << 				',' << velArr[i] << endl;
		}

		fs.close();
	} else {cout << "err";}
}
double SpringSystem::getPeriod() {
	return T;
}


