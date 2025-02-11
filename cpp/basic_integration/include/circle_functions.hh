#ifndef CIRCLE_FUNCTIONS
#define CIRCLE_FUNCTIONS

#include <math.h>

//------------------------------------------------------------------------------
//
// The area under which is piR^2/4
//
//------------------------------------------------------------------------------
double 
circular_arc_2D( double x, double* params) 
//------------------------------------------------------------------------------
{
  double R = params[0];
  if (x > R){
    return 0.;
  }
  return sqrt( R*R - x*x);
};




//------------------------------------------------------------------------------
//
// specifically for determining Pi from the above via mean/variance
// see https://math.stackexchange.com/questions/19119/approximating-pi-using-monte-carlo-integratio
// f = sqrt(1-x^2)
// Var[<f>] = Int_{0}^{1} f^2 - ( Int_{0}^{1} f )^2
//          = (x - x^3/3)|0,1 - pi/4
//          = (2/3) - pi/4 
//
//------------------------------------------------------------------------------
double 
circular_arc_2D_variance( unsigned long N, double range_i, double range_f )
//------------------------------------------------------------------------------
{
  double V = range_f - range_i;
  double var = (2./3) - (M_PI/4)*(M_PI/4);
  return V*sqrt( var/N );
};


//------------------------------------------------------------------------------
//
// The volume under which is (1/8)*(4/3)piR^3 = (1/6)piR^3
//
//------------------------------------------------------------------------------
double 
sphereical_shell_3D( double x, double y, double* params) 
//------------------------------------------------------------------------------
{
  double R = params[0];
  return sqrt( R*R - x*x - y*y);
};


#endif
