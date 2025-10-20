/**
 * @file HO.h
 * @brief Header file for HO.cpp
 * @author Cele Rodriguez <celerodr@usc.edu>
 * @date 2025-10-18
 */
#ifndef HO_H
#define HO_H
#include <string>
using namespace std;

#define PI 3.14159265


class SpringSystem {
	private:
	    double mass;
	    double k;
	    double b;
	    double beta;
	    double x0;
	    double v0;
	    double omega;
	    double omega1;
	    double omega2;
	    double amp;
	    double ampf;
	    double delta;
	    double deltaf;
	    double T;
        
	public:
	    SpringSystem(
	        double m = 1.0,
	        double sc = 4.0,
		double b = 0.5,
	        double x = 1.0,
	        double v = 0,
		double af = 1,
		double om2 = 2
	    );

	    
            void shmPosition(double time[], double arr[], int size);
	    
	    void shmVelocity(double time[], double arr[], int size);

	    void dampedPosition(double time[], double arr[], int size);

	    void dampedVelocity(double time[], double arr[], int size);

	    void forcedVelocity(double time[], double arr[], int size);

	    void forcedPosition(double time[], double arr[], int size);

	    void momentum(double time[], double arr[], double arr2[], int size);

	    void kinEnergy(double time[], double arr[], double arr2[], int size);

	    void potEnergy(double time[], double arr[], double arr2[], int size);

	    void write(string fileName, double posArr[], double velArr[], double mom[], double kin[], double pot[], double times[], int size);

	    double getPeriod();
};
#endif
