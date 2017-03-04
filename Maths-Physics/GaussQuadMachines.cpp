//
//  CalculusMachine.cpp
//  Maths-Physics
//
//  Created by Dan Underwood on 28/02/2017.
//  Copyright � 2017 Dan Underwood. All rights reserved.
//

#include "CalculusMachine.cpp"
#include "Functions.cpp"
#include <iostream>
//#include "IGaussQuadFunction.h"

using namespace MathsPhysics;


class GaussLegQuadMachine : public CalculusMachine {

private:
	Legendre _leg;
    unsigned int _degree;
    unsigned int _order;

public:

	GaussLegQuadMachine(unsigned int deg) : _leg(deg) {
        _degree = deg;
        _order = 0;
	}

	GaussLegQuadMachine(unsigned int deg, unsigned int ord) : _leg(deg, ord) {
        _degree = deg;
        _order = ord;
	}


	std::vector<std::vector<long double>> PointsAndWeights() {
        
        Legendre _leg2(_degree - 1, _order);
        long double _dlag;

        //Brute force method, interval is 0 - 1
		std::vector<long double> _zeroes = FindZeroes(_leg, 1, 0, 0.0001);
		std::vector<std::vector<long double>> _pointsAndWeights(_zeroes.size(), std::vector<long double>(_zeroes.size()));

		for (int i = 0; i < _zeroes.size(); i++) {
            
            _dlag = (_degree / (((_zeroes[i] * _zeroes[i]) - 1))) * ((_zeroes[i] * _leg.Compute(_zeroes[i])) - ((_order + 1) * _leg2.Compute(_zeroes[i])));

			long double _weight = 2 / ((1 - (_zeroes[i] * _zeroes[i])) * (_dlag * _dlag));

			_pointsAndWeights[i][0] = _zeroes[i];
			_pointsAndWeights[i][1] = _weight;
		}

		return _pointsAndWeights;
	}
};




class GaussLagQuadMachine: public CalculusMachine{
    
private:
    Laguerre _lag;
	unsigned int _degree;
	unsigned int _order;
    
public:
    
	GaussLagQuadMachine(unsigned int deg) : _lag(deg) {
		_degree = deg;
		_order = 0;
	}
    
    GaussLagQuadMachine(unsigned int deg, unsigned int ord): _lag(deg, ord) {
		_degree = deg;
		_order = ord;
    }
    
    
	//This method is pretty slow for large _degree.
    std::vector<std::vector<long double>> PointsAndWeights() {
        
		long double _upperLim = 1;
		long double _lowerLim = 0;
        long double _gamma = tgammal(_degree + _order);

		std::vector<long double> _zeroes;
		std::vector<long double> _tempZeroes;
        
        Laguerre _lag2(_degree - 1, _order);

		while (_zeroes.size() < _degree) {

			_tempZeroes = FindZeroes(_lag, _upperLim, _lowerLim, 0.000001);

            for (int i = 0; i < _tempZeroes.size(); i++)
			{
				_zeroes.push_back(_tempZeroes[i]);
			}

			_lowerLim = _upperLim;
			_upperLim += 1;
		}

        std::vector<std::vector<long double>> _pointsAndWeights(_zeroes.size(), std::vector<long double>(_zeroes.size()));
        
        for (int i = 0; i < _zeroes.size(); i++) {
            
            std::cout << _zeroes[i] << std::endl;
            
            long double _weight = (_gamma * _zeroes[i])/(Factorial(_degree)*(_degree + _order)*(_lag2.Compute(_zeroes[i]) * _lag2.Compute(_zeroes[i])));
            
            _pointsAndWeights[i][0] = _zeroes[i];
            _pointsAndWeights[i][1] = _weight;
        }
        
        return _pointsAndWeights;
    }
    
    

	//Faster method by Stroud and Secrest/Press et al.
	std::vector<std::vector<long double>> FastPointsAndWeights() {

	
		std::vector<long double> _zeroes;
        std::vector<std::vector<long double>> _pointsAndWeights(_degree, std::vector<long double>(_degree));
		
        long double _point = 0;
        long double _refPoint;
        long double _gamma = tgammal(_degree + _order);
        Laguerre _lag2(_degree - 1, _order);
        
		for (int i = 1; i <= _degree; i++) {

			if (i == 1) {

				_point = ((1 + _order) * (3 + (0.92 * _order))) / (1 + (2.4 * _degree) + (1.8 * _order));
			}
			else if (i == 2) {

				_point += (15 + (6.25 * _order)) / (1 + (0.9 * _order) + (2.5 * _degree));
			}
			else {
                
                _point += (((1.0 + (2.55 * (i - 2)))/(1.9 * (i - 2))) + ((1.26 * (i - 2) * _order)/(1 + (3.5 * (i - 2))))) * ((_point - _zeroes[i - 3])/(1 + (0.3 * _order)));
                
			}
            

			//Newton-Raphson iteration
			for (int iter = 0; iter < 10; iter++) {
				
				_refPoint = _point;
                _point = _refPoint - (_lag.Compute(_point) / Derivative(_point));
                
                if(fabsl(_point - _refPoint) <= 0.00000001)
                    break;
                
			}
            
			_zeroes.push_back(_point);
            
            long double _weight = (_gamma * _point)/(Factorial(_degree)*(_degree + _order)*(_lag2.Compute(_point) * _lag2.Compute(_point)));
            
            _pointsAndWeights[i - 1][0] = _zeroes[i - 1];
            _pointsAndWeights[i - 1][1] = _weight;
		}
        
        return _pointsAndWeights;
	
	}
    
    long double Derivative(long double value){
        
        Laguerre _lag2(_degree - 1, _order);
        
        //Compute the derivative of the polynomial w.r.t. _point, using _lag2, the polynomial of previous degree
        return ((_degree * _lag.Compute(value)) - ((_degree + _order) * _lag2.Compute(value)))/value;
        
    }
    
    unsigned int Factorial(unsigned int n){
        
        if (n == 1){
            return 1;
        }
        else{
            return n * Factorial(n - 1);
        }
    }
};