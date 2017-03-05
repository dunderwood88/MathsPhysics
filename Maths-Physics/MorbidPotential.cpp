//
//  MorbidPotential.cpp
//  Maths-Physics
//
//  Created by Dan Underwood on 05/03/2017.
//  Copyright © 2017 Dan Underwood. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "IPotential.h"
#include "Functions.cpp"

class MorbidPotential: public Potential{
    
public:

    virtual long double Compute(long double bond1, long double bond2, long double cosX){
        
        long double pot = 0.0;
        long double eqRho = 75.4781;
        Morse morse1(2.2251, 0.958290), morse2(2.2251, 0.958290), morse3(2.2251, 0.958290);
        
        long double f0[3] = {18988.7, 1586.4, 5003.5};
        long double f1[3] = {-7023.0, -3138.0, -4050.0};
        long double f11[3] = {42892.0, -2330.0, -4338.0};
        long double f13[2] = {-1030.0, 4694.0};
        long double f111[2] = {693.0, 3769.0};
        long double f113[2] = {-1262.0, 9961.0};
        long double f1111[1] = {2222.0};
        long double f1113[1] = {-202.0};
        
        //First compute the purely bending potential component
        for(int i = 0; i < sizeof(f0)/sizeof(long double); i++){
            
            pot += f0[i]*powl((cosl(eqRho) - cosX), i + 2);
            
        }
        
        
        for(int i = 0; i < sizeof(f1)/sizeof(long double); i++){
            
            pot += f1[i]*powl((cosl(eqRho) - cosX), i + 1);
            
        }
        
        pot *= morse1.Compute(<#long double &dispR#>)
        
        
        
        return pot;
    }
};
