/**
 * @file myProj.cpp
 * @brief Simulate and visualize Harmonic Oscillations
 * @author Cele Rodriguez <celerod@usc.edu>
 * @date 2025-10-18
 */
#include <string>
#include "HO.h"
#include <cmath>
#include <iostream>

using namespace std;

int main(void) {
    SpringSystem sys;
    double time = 0.0;
    double totalTime = 10 * sys.getPeriod();
    int size = (int) (totalTime * 10);
    double timeArr[size + 1];
    double posArr[size + 1];
    double velArr[size +1];
    double mom[size + 1];
    double kinEn[size + 1];
    double potEn[size + 1];

    for (int i = 0; i <= size; i += 1) {
        timeArr[i] = time;
	time += 0.1;
    }
    sys.shmPosition(timeArr, posArr, size);
    sys.shmVelocity(timeArr, velArr, size);
    sys.momentum(timeArr, mom, velArr, size);
    sys.kinEnergy(timeArr, kinEn, mom, size);
    sys.potEnergy(timeArr, potEn, posArr, size);
    sys.write("shm.csv", posArr, velArr, mom, kinEn, potEn, timeArr, size);

    sys.dampedPosition(timeArr, posArr, size);
    sys.dampedVelocity(timeArr, velArr, size);
    sys.momentum(timeArr, mom, velArr, size);
    sys.kinEnergy(timeArr, kinEn, mom, size);
    sys.potEnergy(timeArr, potEn, posArr, size);
    sys.write("damped.csv", posArr, velArr, mom, kinEn, potEn, timeArr, size);
    
    sys.forcedPosition(timeArr, posArr, size);
    sys.forcedVelocity(timeArr, velArr, size);
    sys.momentum(timeArr, mom, velArr, size);
    sys.kinEnergy(timeArr, kinEn, mom, size);
    sys.potEnergy(timeArr, potEn, posArr, size);
    sys.write("forced.csv", posArr, velArr, mom, kinEn, potEn, timeArr, size);


}
