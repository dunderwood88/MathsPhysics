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
     unsigned int _degree;
	 unsigned int _order;
    
    double p0(){
        return 1;
    }
    
    double p1(double value){
        return value;
    }
    
public:
    
    Legendre(unsigned int deg){
        _degree = deg;
		_order = 0;
    }

	Legendre(unsigned int deg, unsigned int ord) {
		_degree = deg;
		_order = ord;
	}
    
    virtual double Compute(double value){
        
        if (_degree == 0){
            return p0();
        }
        else if (_degree == 1){
            return p1(value);
        }
        else{
            
            double pn = 0;
            double pTemp1 = p1(value);
            double pTemp2 = p0();
            
            for (int i = 1; i < _degree; i++) {
                
                pn = (((2 * i + 1) * value * pTemp1) - (i * pTemp2))/(i + 1);
                pTemp2 = pTemp1;
                pTemp1 = pn;
            }
            
            return pn;
        }
    }
};

class GaussLegendreWeights : public IFunction {

private:
	Legendre _leg;

public:

	GaussLegendreWeights(Legendre& leg) :_leg(leg) {
		
	}

	virtual double Compute(double value) {

		return 2 / ((1 - (value * value))*(_leg.Compute(value)*_leg.Compute(value)));
	}
};

class AssocLegendre : public IFunction {

private:
	unsigned int _degree;
	unsigned int _order;

public:
	AssocLegendre(unsigned int deg, unsigned int ord) {
		_degree = deg;
		_order = ord;
	}

	virtual double Compute(double value) {

		if (_order < 0 || _order > _degree) {
			std::cout << "Bad arguments.\n";
			return 0;
		}


		double pmm = 1;

		if (_order > 0) {

			double somx2 = sqrt((1 - value) * (1 + value));
			double fact = 1;

			for (int i = 1; i <= _order; i++) {

				pmm *= -fact;// *somx2;
				fact += 2;

				//std::cout << sqrt((1 - value) * (1 + value)) << "\n";
			}
		}

		if (_degree == _order) {
			return pmm;
		}
		else {
			double pmmp1 = value * ((2 * _order) + 1) * pmm;

			if (_degree == (_order + 1)) {
				return pmmp1;
			}
			else {

				double pll;

				for (double ll = _order + 2; ll <= _degree; ll++) {

					pll = ((value * ((2 * ll) - 1) * pmmp1) - (ll + _order - 1)) / (ll - _order);
					pmm = pmmp1;
					pmmp1 = pll;

				}
				return pll;
			}
		}

	}
};