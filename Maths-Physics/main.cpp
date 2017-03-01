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
    
	Legendre asLeg(130);
    Laguerre asLag(30,0);

	//std::cout <<  asLeg.Compute(0.5) << "\n";
    //std::cout <<  asLag.Compute(5) << "\n";
    
    CalculusMachine cm;
    
    //cm.FindZeroes(asLeg, 1, 0, 0.001);
    cm.GaussPointsAndWeights(asLeg, 1, 0, 0.001);
    
    return 0;
}