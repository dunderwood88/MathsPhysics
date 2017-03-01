//
//  CalculusMachine.hpp
//  Maths-Physics
//
//  Created by Dan Underwood on 28/02/2017.
//  Copyright © 2017 Dan Underwood. All rights reserved.
//

#include <stdio.h>
#include "IFunction.h"

//using namespace MathsPhysics;

#ifndef ICalculusMachine_hpp
#define ICalculusMachine_hpp

namespace MathsPhysics {
    
    class ICalculusMachine {
        
    public:
        virtual ~ICalculusMachine() {}
        virtual double AreaUnderCurve(IFunction& func, double upperLim, double lowerLim, double step) = 0;
        virtual void FindZeroes(IFunction& func, double upperLim, double lowerLim, double step) = 0;
    };
}



#endif /* ICalculusMachine_hpp */
