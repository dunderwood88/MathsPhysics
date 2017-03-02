//
//  main.cpp
//  Maths-Physics
//
//  Created by Dan Underwood on 28/02/2017.
//  Copyright © 2017 Dan Underwood. All rights reserved.
//

#define _USE_MATH_DEFINES

#include <iostream>
#include "GaussQuadMachines.cpp"

using namespace MathsPhysics;

int main() {
    
	//GaussLegQuadMachine gasLeg(30);
    GaussLagQuadMachine gasLag(30);

	std::vector<std::vector<long double>> pw = gasLag.PointsAndWeights();

	for (int i = 0; i < pw[0].size(); i++) {

        std::cout << pw[i][0] << " " << pw[i][1] << std::endl;

	}

	//std::getchar();
    return 0;
}