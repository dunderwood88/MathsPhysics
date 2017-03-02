//
//  CalculusMachine.cpp
//  Maths-Physics
//
//  Created by Dan Underwood on 28/02/2017.
//  Copyright © 2017 Dan Underwood. All rights reserved.
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

	GaussLegQuadMachine(unsigned int deg): _leg(deg) {

	}

	GaussLegQuadMachine(unsigned int deg, unsigned int ord): _leg(deg, ord) {
	}


	std::vector<std::vector<long double>> PointsAndWeights() {

		std::vector<long double> _zeroes = FindZeroes(_leg, 1, 0, 0.001);
		std::vector<std::vector<long double>> _pointsAndWeights(_zeroes.size(), std::vector<long double>(_zeroes.size()));

		for (int i = 0; i < _zeroes.size(); i++) {

			long double _weight = 2 / ((1 - (_zeroes[i] * _zeroes[i])) * (_leg.Derivative(_zeroes[i]) * _leg.Derivative(_zeroes[i])));

			_pointsAndWeights[i][0] = _zeroes[i];
			_pointsAndWeights[i][1] = _weight;
		}

		return _pointsAndWeights;
	}
};