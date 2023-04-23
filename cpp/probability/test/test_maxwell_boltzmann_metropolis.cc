#include <stdio.h>
#include <stdlib.h>
#include "probability.hh"

unsigned count_reject=0, count_metro=0;

int main(int argc, char** argv) {

  if( argc < 2 ) {
    fprintf(stderr,"Error : need at least one argument (random seed)\n");
    return -1;
  }

  srand(strtoul(argv[1],NULL,10));

  double a = 1.;
  if (argc > 2) {
    a = strtod(argv[2], NULL);
  }

  
  // double params[2] = {0.25,1.};
  double params[1] = {a};
  double range_i = 0.;
  double range_f = 20.;

  double x_reject, x_metro;

  // warm up MH
  x_metro = range_i + rand()*((range_f-range_i)/RAND_MAX);
  for( int i=0; i<5000000; i++ ) 
    x_metro =  sample_pdf_metropolis( &pdf_maxwell_boltzmann, (double*)&params, range_i, range_f, x_metro);

  for( int i=0; i<200000; i++ ) { 
    // x_reject = sample_pdf_rejection( &pdf_maxwell_boltzmann, (double*)&params, range_i, range_f);
    x_metro  = sample_pdf_metropolis( &pdf_maxwell_boltzmann, (double*)&params, range_i, range_f, x_metro);
    // printf( "%d %lf %lf\n", i, x_reject, x_metro);
    printf( "i: %d val: %lf\n", i, x_metro);
  }

  fprintf(stderr, "count_reject: %d\tcount_metro: %d\n", count_reject, count_metro);


}
