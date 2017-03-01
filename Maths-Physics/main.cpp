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
    
    Legendre leg3(30);
    CalculusMachine cm;
    
    cm.GaussPointsAndWeights(leg3, 1, 0, 0.001);
    
    
    //std::cout << leg3.Compute(0.5) << "\n";
    //std::cout << leg3.Derivative(0.5) << "\n";
    
    return 0;
}