//
//  CalculusMachine.cpp
//  Maths-Physics
//
//  Created by Dan Underwood on 28/02/2017.
//  Copyright © 2017 Dan Underwood. All rights reserved.
//

#include <iostream>
#include "ICalculusMachine.hpp"
#include "IFunction.h"

using namespace MathsPhysics;

class CalculusMachine: public ICalculusMachine {
    
public:

    virtual void FindZeroes(IFunction& func, double upperLim, double lowerLim, double step){
        
        if(upperLim < lowerLim){
            std::cout << "upper limit is less than lower limit\n";
            return;
        }
        
        double prevPoint = lowerLim;
		
        
        for(double point = lowerLim; point < upperLim + step; point += step){
            
            if(func.Compute(point) == 0 || point == 0){
                std::cout << point << "\n";
            }
            else if(func.Compute(point) * func.Compute(prevPoint) < 0){
                std::cout << (point + prevPoint)/2 << "\n";
            }
            
            prevPoint = point;
        }
    }
    
    virtual double AreaUnderCurve(IFunction& func, double upperLim, double lowerLim, double step){
        
        if(upperLim < lowerLim){
            std::cout << "upper limit is less than lower limit\n";
            return 0;
        }
        
        double area = 0;
        
        for(double point = lowerLim; point < upperLim; point += step){
            
            area += func.Compute(point)*step;
        }
        
        return area;
    }
};