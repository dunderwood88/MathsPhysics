//
//  main.cpp
//  Maths-Physics
//
//  Created by Dan Underwood on 28/02/2017.
//  Copyright © 2017 Dan Underwood. All rights reserved.
//

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include "Functions.cpp"
#include "CalculusMachine.cpp"

using namespace MathsPhysics;

int main() {
    
    /*CalculusMachine cm;
    Legendre leg3(3);
	GaussLegendreWeights glw(leg3);
    Sine sin;*/
    
    //std::cout << leg3.Compute(5) << "\n";
    //cm.FindZeroes(leg3, 1, 0, 0.001);


    
    //cm.FindZeroes(sin, 1080 * M_PI/180, 0, 0.001 * M_PI/180);
    //cm.FindZeroes(sin, 1080 * M_PI/180, 0, 0.001 * M_PI/180);
    
	AssocLegendre asLeg53(2, 1);

	std::cout <<  asLeg53.Compute(5) << "\n";

	std::cin.get();
    return 0;
}