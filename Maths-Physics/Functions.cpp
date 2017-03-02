//
//  Function.cpp
//  Maths-Physics
//
//  Created by Dan Underwood on 28/02/2017.
//  Copyright © 2017 Dan Underwood. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <math.h>
#include "IGaussQuadFunction.h"

using namespace MathsPhysics;

class Legendre: public IGaussQuadFunction{
    
private:
    int _degree;
    int _order;
    
public:

    Legendre(unsigned int deg) {
        _degree = deg;
        _order = 0;
    }
    

    Legendre(unsigned int deg, unsigned int ord) {
        _degree = deg;
        _order = ord;
    }

	void Set(unsigned int deg, unsigned int ord) {
		_degree = deg;
		_order = ord;
	}
    
    virtual long double Derivative(long double x){
        
		_degree -= 1;
		long double legDegRev = Compute(x);
		_degree += 1;
		
		return (_degree / ((x * x) - 1)) * ((x * Compute(x)) - ((_order + 1) * legDegRev));

    }
    
    virtual long double Compute(long double value) {
        
        /*if (_order > _degree || std::abs(value) > 1.0) {
            std::cout << _order << " " << _degree << " " << std::abs(value) << " Bad arguments.\n";
            return NULL;
        }*/
        
        
        long double pmm = 1;
        
        if (_order > 0) {
            
            long double somx2 = sqrt((1 - value) * (1 + value));
            long double fact = 1;
            
            for (int i = 1; i <= _order; i++) {
                
                pmm *= -fact * somx2;
                fact += 2;
            }
        }
        
        if (_degree == _order) {
            return pmm;
        }
        else {
            long double pmmp1 = value * ((2 * _order) + 1) * pmm;
            
            if (_degree == (_order + 1)) {
                return pmmp1;
            }
            else {
                
                long double pll = 0;
                
                for (long double ll = _order + 2; ll <= _degree; ll++) {
                    
                    pll = ((value * ((2 * ll) - 1) * pmmp1) - ((ll + _order - 1) * pmm)) / (ll - _order);
                    
                    pmm = pmmp1;
                    pmmp1 = pll;
                    
                }
                return pll;
            }
        }
        
    }
    
};



/*class Laguerre: public IFunction{
    
private:
    int _degree;
    int _order;
    
public:
    
    Laguerre(unsigned int deg){
        _degree = deg;
        _order = 0;
    }
    
    Laguerre(unsigned int deg, unsigned int ord){
        _degree = deg;
        _order = ord;
    }
    
    virtual long double Derivative(long double x){
        
        //What to do??
        //return -Laguerre(_degree - 1, _order + 1).Compute(x);
    }
    
    virtual long double Compute(long double value){
        
        double p0 = 1;
        double p1 = 1 + _order - value;
        
        if (_degree == 0){
            return p0;
        }
        else if (_degree == 1){
            return p1;
        }
        else{
            
            double pn = 0;
            
            for (int i = 1; i < _degree; i++){
                
                pn = ((((2 * i) + 1 + _order - value) * p1) - ((i + _order) * p0))/(i + 1);
                
                p0 = p1;
                p1 = pn;
                
            }
            
            return pn;
        }
        
    }
};



class Sine: public IFunction{

public:
virtual long double Compute(long double value){

return sinl(value);
}
};

class Cosine: public IFunction{

public:
virtual long double Compute(long double value){

return cosl(value);
}
};*/