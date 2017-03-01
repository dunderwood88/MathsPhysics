//
//  Function.cpp
//  Maths-Physics
//
//  Created by Dan Underwood on 28/02/2017.
//  Copyright © 2017 Dan Underwood. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "IFunction.h"

using namespace MathsPhysics;

class Sine: public IFunction{
    
public:
    virtual double Compute(double value){
        
        return sin(value);
    }
};

class Cosine: public IFunction{
    
public:
    virtual double Compute(double value){
        
        return cos(value);
    }
};

class Legendre: public IFunction{
    
private:
    int _rank;
    
    double p0(){
        return 1;
    }
    
    double p1(double value){
        return value;
    }
    
public:
    
    Legendre(double rank){
        _rank = rank;
    }
    
    virtual double Compute(double value){
        
        if (_rank == 0){
            return p0();
        }
        else if (_rank == 1){
            return p1(value);
        }
        else{
            
            double pn = 0;
            double pTemp1 = p1(value);
            double pTemp2 = p0();
            
            for (int i = 1; i < _rank; i++) {
                
                pn = (((2 * i + 1) * value * pTemp1) - (i * pTemp2))/(i + 1);
                pTemp2 = pTemp1;
                pTemp1 = pn;
            }
            
            return pn;
        }
    }
};


