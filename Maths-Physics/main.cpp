//
//  main.cpp
//  Maths-Physics
//
//  Created by Dan Underwood on 28/02/2017.
//  Copyright © 2017 Dan Underwood. All rights reserved.
//

#include <iostream>
#include "Functions.cpp"
#include "CalculusMachine.cpp"

using namespace MathsPhysics;

int main() {
    
    CalculusMachine cm;
    Legendre leg300(300);
    Sine sin;
    
    //std::cout << leg3.Compute(5) << "\n";
    //cm.FindZeroes(leg300, 1, 0, 0.001);
    
    //cm.FindZeroes(sin, 1080 * M_PI/180, 0, 0.001 * M_PI/180);
    cm.FindZeroes(sin, 1080 * M_PI/180, 0, 0.001 * M_PI/180);
    
    //std::cout << cm.AreaUnderCurve(sin, 100 * M_PI/180, 0, 0.001 * M_PI/180) << "\n";
    return 0;
}