//
//  IFunction.h
//  Maths-Physics
//
//  Created by Dan Underwood on 28/02/2017.
//  Copyright © 2017 Dan Underwood. All rights reserved.
//

#ifndef IFunction_h
#define IFunction_h

namespace MathsPhysics {
    
    class IFunction {
        
    public:
        virtual ~IFunction() {}
        virtual double Compute(double value) = 0;
    };
};

#endif /* IFunction_h */