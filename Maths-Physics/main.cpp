//
//  main.cpp
//  Maths-Physics
//
//  Created by Dan Underwood on 28/02/2017.
//  Copyright © 2017 Dan Underwood. All rights reserved.
//

//#define _USE_MATH_DEFINES

//#include <iostream>
//#include <random>
//#include "GaussQuadMachines.cpp"
//#include <Accelerate/Accelerate.h>

//using namespace MathsPhysics;

//int main() {
    
    /*GaussLegQuadMachine _gasLeg(130);
    
    for(int i = 0; i <_gasLeg.PointsAndWeights()[0].size(); i++){
        
        std::cout << _gasLeg.PointsAndWeights()[i][0] << " " << _gasLeg.PointsAndWeights()[i][1] << std::endl;
    }
    
    GaussLagQuadMachine _gasLag(10,5);
    
    
    
    for(int i = 0; i < _gasLag.FastPointsAndWeights()[0].size(); i++){
        
        std::cout << _gasLag.FastPointsAndWeights()[i][0] << " " << _gasLag.FastPointsAndWeights()[i][1] << std::endl;
        
    }*/
    
    /*
    //Random numbers
    std::mt19937_64 rnd;
    std::uniform_real_distribution<double> doubleDist(0, 1);
    
    //Create Arrays that represent the matrices A,B,C
    const int n = 2;
    double*  A = new double[n*n];
    double*  B = new double[n*n];
    double*  C = new double[n*n];
    
    //Fill A and B with random numbers
    for(uint i =0; i <n; i++){
        for(uint j=0; j<n; j++){
            A[i*n+j] = 2;//doubleDist(rnd);
            B[i*n+j] = 3;//doubleDist(rnd);
        }
    }
    
    //Calculate A*B=C
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, n, n, n, 1.0, A, n, B, n, 0.0, C, n);
    
    for(uint i = 0; i < n; i++){
        std::cout << C[i] << std::endl;
    }
    
    //Clean up
    delete[] A;
    delete[] B;
    delete[] C;
    

     */
    
    
    
     
	//std::getchar();
//    return 0;
//}


#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <Accelerate/Accelerate.h>


/* DSYEV prototype */
extern "C"{
    void dsyev( char* jobz, char* uplo, int* n, double* a, int* lda,
               double* w, double* work, int* lwork, int* info );
}
/* Auxiliary routines prototypes */
extern "C"{
    void print_matrix( char* desc, int m, int n, double* a, int lda );
}
/* Parameters */
#define N 10
#define LDA N

/* Main program */
int main() {
    /* Locals */
    int n = N, lda = LDA, info, lwork;
    double wkopt;
    double* work;
    /* Local arrays */
    double w[N];
    double a[LDA*N] = {
        1.0, 0.0, 0.0, 2.0, 1.0, 0.0, 0.0, 2.0, 1.0, 0.0, 0.0, 2.0, 1.0, 0.0, 0.0, 2.0, 1.0, 0.0, 0.0, 2.0
    };
    /* Executable statements */
    printf( " DSYEV Example Program Results\n" );
    /* Query and allocate the optimal workspace */
    lwork = -1;
    dsyev( "V", "L", &n, a, &lda, w, &wkopt, &lwork, &info );
    lwork = (int)wkopt;

    work = new double[lwork];
    /* Solve eigenproblem */
    dsyev( "V", "L", &n, a, &lda, w, work, &lwork, &info );
    /* Check for convergence */
    if( info > 0 ) {
        printf( "The algorithm failed to compute eigenvalues.\n" );
        exit( 1 );
    }
    /* Print eigenvalues */
    print_matrix( "Eigenvalues", 1, n, w, 1 );
    /* Print eigenvectors */
    print_matrix( "Eigenvectors (stored columnwise)", n, n, a, lda );
    /* Free workspace */
    delete [] work;
    exit( 0 );
} /* End of DSYEV Example */

/* Auxiliary routine: printing a matrix */
void print_matrix( char* desc, int m, int n, double* a, int lda ) {
    int i, j;
    printf( "\n %s\n", desc );
    for( i = 0; i < m; i++ ) {
        for( j = 0; j < n; j++ ) printf( " %6.2f", a[i+j*lda] );
        printf( "\n" );
    }
}