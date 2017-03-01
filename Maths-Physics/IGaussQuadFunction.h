//
//  IGaussQuadFunction.h
//  Maths-Physics
//
//  Created by Dan Underwood on 01/03/2017.
//  Copyright © 2017 Dan Underwood. All rights reserved.
//

#include "IFunction.h"

#ifndef IGaussQuadFunction_h
#define IGaussQuadFunction_h

namespace MathsPhysics {
    
    class IGaussQuadFunction: public IFunction {
        
    public:
        virtual ~IGaussQuadFunction() {}
        virtual double Derivative(double x) = 0;
    };
};

#endif /* IGaussQuadFunction_h */
