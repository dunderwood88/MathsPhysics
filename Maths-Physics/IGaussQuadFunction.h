//
//  IGaussQuadFunction.h
//  Maths-Physics
//
//  Created by Dan Underwood on 01/03/2017.
//  Copyright © 2017 Dan Underwood. All rights reserved.
//

#ifndef IGaussQuadFunction_h
#define IGaussQuadFunction_h

#include "IFunction.h"

namespace MathsPhysics {
    
    class IGaussQuadFunction: public IFunction {
        
    public:
        virtual ~IGaussQuadFunction() {}
        virtual long double Derivative(long double x) = 0;
    };
};

#endif /* IGaussQuadFunction_h */
