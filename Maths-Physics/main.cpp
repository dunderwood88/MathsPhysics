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
    
    GaussLegQuadMachine _gasLeg(130);
    
    for(int i = 0; i <_gasLeg.PointsAndWeights()[0].size(); i++){
        
        std::cout << _gasLeg.PointsAndWeights()[i][0] << " " << _gasLeg.PointsAndWeights()[i][1] << std::endl;
    }
    
    GaussLagQuadMachine _gasLag(10,5);
    
    
    
    for(int i = 0; i < _gasLag.FastPointsAndWeights()[0].size(); i++){
        
        std::cout << _gasLag.FastPointsAndWeights()[i][0] << " " << _gasLag.FastPointsAndWeights()[i][1] << std::endl;
        
    }
    
    
    

	//std::getchar();
    return 0;
}