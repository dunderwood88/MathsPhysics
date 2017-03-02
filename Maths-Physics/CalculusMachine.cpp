//
//  CalculusMachine.cpp
//  Maths-Physics
//
//  Created by Dan Underwood on 28/02/2017.
//  Copyright © 2017 Dan Underwood. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <stdio.h>
#include "ICalculusMachine.hpp"

using namespace MathsPhysics;

class CalculusMachine: public ICalculusMachine {
    
public:

    virtual std::vector<long double> FindZeroes(IFunction& func, long double upperLim, long double lowerLim, long double step){
       
		std::vector<long double> vec;

        if(upperLim < lowerLim){
            std::cout << "upper limit is less than lower limit\n";
			return vec;
        }
       

        long double prevPoint = lowerLim;
		
        
        for(long double point = lowerLim; point < upperLim + step; point += step){
            
            if(func.Compute(point) == 0 || point == 0){

				vec.push_back(point);
            }
            else if(func.Compute(point) * func.Compute(prevPoint) < 0){
				
				vec.push_back((point + prevPoint) / 2);
            }
            
            prevPoint = point;
        }

		

		return vec;
    }
    
    virtual long double AreaUnderCurve(IFunction& func, long double upperLim, long double lowerLim, long double step){
        
        if(upperLim < lowerLim){
            std::cout << "upper limit is less than lower limit\n";
            return 0;
        }
        
        long double area = 0;
        
        for(long double point = lowerLim; point < upperLim; point += step){
            
            area += func.Compute(point)*step;
        }
        
        return area;
    }
    
};