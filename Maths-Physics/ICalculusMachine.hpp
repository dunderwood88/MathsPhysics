//
//  CalculusMachine.hpp
//  Maths-Physics
//
//  Created by Dan Underwood on 28/02/2017.
//  Copyright © 2017 Dan Underwood. All rights reserved.
//

//using namespace MathsPhysics;

#ifndef ICalculusMachine_hpp
#define ICalculusMachine_hpp

#include "IFunction.h"

namespace MathsPhysics {
    
    class ICalculusMachine {
        
    public:
        virtual ~ICalculusMachine() {}
        virtual long double AreaUnderCurve(IFunction& func, long double upperLim, long double lowerLim, long double step) = 0;
        virtual std::vector<long double> FindZeroes(IFunction& func, long double upperLim, long double lowerLim, long double step) = 0;
    };
}



#endif /* ICalculusMachine_hpp */
