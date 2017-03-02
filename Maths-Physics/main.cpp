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
    
	GaussLegQuadMachine gasLeg(10);

	std::vector<std::vector<long double>> pw = gasLeg.PointsAndWeights();

	

	//for (int i = 0; i < pw.size(); i++) {

		//std::cout << pw[1][1] << " " << pw[1][0] << "\n";
	
	
	std::getchar();
    return 0;
}