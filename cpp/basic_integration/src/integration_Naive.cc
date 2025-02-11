#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "integration_Naive.hh"

//------------------------------------------------------------------------------
//
// A single x,y trial from a sample with many trials.  Optionally return the 
// x & y coordinates 
//
//------------------------------------------------------------------------------
unsigned
naive_trial_1D( double (*function)(double, double*), 
		double* params, 
		double range_i, double range_f, 
		Points2D* opt_points )
//------------------------------------------------------------------------------
{
  // generate x and y values
  // Q: why sample x, y from U([0, dim])? I would not assume x, y=f(x) distributed similarly. 
  double dim = (range_f-range_i);
  double x = dim*rand()/RAND_MAX;
  double y = dim*rand()/RAND_MAX;

  // optionally prepare to return points
  if( opt_points != NULL ) { 
    opt_points->x = x;
    opt_points->y = y;
  }

  // check if inside
  if( y <= function( x, params ) )
    return 1;
  return 0;

}

//------------------------------------------------------------------------------
//
// Integrate by looping over many trials
//
//------------------------------------------------------------------------------
double
integrate_1D_Naive( double (*function)(double, double*), 
		    double* params, 
		    double range_i, double range_f, 
		    unsigned long ntrials, 
		    Points2D* opt_points )
//------------------------------------------------------------------------------
{

  double dim = (range_f-range_i);
  double V = dim*dim;
  unsigned long ninside=0;
  for( int i=0; i<ntrials; i++ ) {

    unsigned inside=0;

    if( opt_points != NULL ) { 
      inside = naive_trial_1D( function, params, range_i, range_f, opt_points );
      printf( "i: %d x: %lf y: %lf\n", inside, opt_points->x, opt_points->y);
    } else { 
      inside = naive_trial_1D( function, params, range_i, range_f );
    }
    ninside += inside;
  } // trials
  return V*(double)ninside/ntrials;
}


//------------------------------------------------------------------------------
//
// A single x,y trial from a sample with many trials.  Optionally return the 
// x & y coordinates 
//
//------------------------------------------------------------------------------
unsigned
naive_trial_2D( double (*function)(double, double, double*), 
                double* params, 
                double range_i, double range_f, 
                Points3D* opt_points )
//------------------------------------------------------------------------------
{
  double dim = (range_f-range_i);
  double x = dim*rand()/RAND_MAX;
  double y = dim*rand()/RAND_MAX;
  double z = dim*rand()/RAND_MAX;

  if( opt_points != NULL ) { 
    opt_points->x = x;
    opt_points->y = y;
    opt_points->z = z;
  }

  if( z <= function( x, y, params ) )
    return 1;
  return 0;

}



//------------------------------------------------------------------------------
//
// Integrate by looping over many trials
//
//------------------------------------------------------------------------------
double
integrate_2D_Naive( double (*function)(double, double, double*), 
                    double* params, 
                    double range_i, double range_f, 
                    unsigned long ntrials, 
                    Points3D* opt_points )
//------------------------------------------------------------------------------
{

  double dim = (range_f-range_i);
  double V = dim*dim*dim;
  unsigned long ninside=0;
  for( int i=0; i<ntrials; i++ ) {

    unsigned inside=0;

    if( opt_points != NULL ) { 
      inside = naive_trial_2D( function, params, range_i, range_f, opt_points );
      printf( "i: %d x: %lf y: %lf z: %lf\n", inside, opt_points->x, opt_points->y, opt_points->z);
    } else { 
      inside = naive_trial_2D( function, params, range_i, range_f );
    }
    ninside += inside;
  } // trials

  return V*(double)ninside/ntrials;
}




//------------------------------------------------------------------------------
//
// Generic, independent of the function being integrated
// Notes: 
// Var[phat] = Var[k/N] = (1/N^2)Var[k]
//                      = (1/N^2)( N*phat*(1-phat) )
//                      = phat(1-phat)/N 
//
//------------------------------------------------------------------------------
double 
binomial_error( unsigned long N, unsigned long k ) 
//------------------------------------------------------------------------------
{
  double phat = (double)k/N;
  return sqrt( phat*(1.-phat)/N );
}
