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
	    double x0;
	    double v0;
	    double omega;
	    double amp;
	    double delta;
	    double T;
        
	public:
	    SpringSystem(
	        double m = 1.0,
	        double sc = 4.0,
	        double x = 1.0,
	        double v = 0
	    );

	    
            void shmPosition(double time[], double arr[], int size);
	    void shmVelocity(double time[], double arr[], int size);
	    void write(string fileName, double posArr[], double velArr[], double times[], int size);
	    double getPeriod();
};

double dampedOsc( );

double forcedDamped();
#endif
