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
    SpringSystem sys1;
    double time = 0.0;
    double totalTime = 10 * sys1.getPeriod();
    int size = (int) (totalTime * 10);
    double timeArr[size + 1];
    double PosArr[size + 1];
    double VelArr[size +1];

    for (int i = 0; i <= size; i += 1) {
        timeArr[i] = time;
	time += 0.1;
    }

    sys1.shmPosition(timeArr, PosArr, size);
    sys1.shmVelocity(timeArr, VelArr, size);
    sys1.write("shm.csv", PosArr, VelArr, timeArr, size);
}
