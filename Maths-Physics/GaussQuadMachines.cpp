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

public:

	GaussLegQuadMachine(unsigned int deg) : _leg(deg) {

	}

	GaussLegQuadMachine(unsigned int deg, unsigned int ord) : _leg(deg, ord) {
	}


	std::vector<std::vector<long double>> PointsAndWeights() {

		std::vector<long double> _zeroes = FindZeroes(_leg, 1, 0, 0.000001);
		std::vector<std::vector<long double>> _pointsAndWeights(_zeroes.size(), std::vector<long double>(_zeroes.size()));

		for (int i = 0; i < _zeroes.size(); i++) {

			long double _weight = 2 / ((1 - (_zeroes[i] * _zeroes[i])) * (_leg.Derivative(_zeroes[i]) * _leg.Derivative(_zeroes[i])));

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
        
		long double upperLim = 1;
		long double lowerLim = 0;

		std::vector<long double> _zeroes;
		std::vector<long double> _tempZeroes;

		while (_zeroes.size() < _degree) {

			_tempZeroes = FindZeroes(_lag, upperLim, lowerLim, 0.000001);

			for each (long double z in _tempZeroes)
			{
				_zeroes.push_back(z);
			}

			lowerLim = upperLim;
			upperLim += 1;
		}

        std::vector<std::vector<long double>> _pointsAndWeights(_zeroes.size(), std::vector<long double>(_zeroes.size()));
        
        for (int i = 0; i < _zeroes.size(); i++) {
            
            long double _weight = 1/(_zeroes[i] *(_lag.Derivative(_zeroes[i]) * _lag.Derivative(_zeroes[i])));
            
            _pointsAndWeights[i][0] = _zeroes[i];
            _pointsAndWeights[i][1] = _weight;
        }
        
        return _pointsAndWeights;
    }

	//Faster method by Stroud and Secrest/Press et al.
	//std::vector<std::vector<long double>> FastPointsAndWeights() {
	void FastPointsAndWeights(){
	
		std::vector<long double> _zeroes(_degree);
		long double _point;

		for (int i = 1; i <= _degree; i++) {

			if (i == 1) {

				_point = ((1 + _order) * (3 + (92 * _order))) / (1 + (2.4 * _degree) + (1.8 * _order));
			}
			else if (i == 2) {

				_point += (15 + (25 * _order)) / (1 + (9 * _order) + (2.5 * _degree));
			}
			else {

				_point += (((1 + (2.55 * (i - 2))) / (1.9 * (i - 2))) + ((1.26 * (i - 2) * _degree) / (1 + 3.5 * (i - 2)))) * ((_point - _zeroes[i - 2])/(1 + (3 * _order)));
			}

			long double _refPoint;
			Laguerre _lag2(_degree - 1, _order);

			//Newton-Raphson iteration
			for (int iter = 0; iter < 1; iter++) {
				
				_refPoint = _point;
				//_point = _refPoint - (_lag.Compute(_refPoint)/_lag.Derivative(_refPoint));
				//_point = _refPoint - (_lag.Compute(_refPoint) / _lag2.Compute(_refPoint));
			}

			_zeroes.push_back(_point);
			std::cout << _point << std::endl;
		}

	
	}
};