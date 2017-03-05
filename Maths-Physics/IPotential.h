//
//  IPotential.h
//  Maths-Physics
//
//  Created by Dan Underwood on 05/03/2017.
//  Copyright © 2017 Dan Underwood. All rights reserved.
//

#ifndef IPotential_h
#define IPotential_h

class Potential {
    
public:
    virtual long double Compute(long double bond1, long double bond2, long double cosX) = 0;
    virtual ~Potential();
    
};

#endif /* IPotential_h */
