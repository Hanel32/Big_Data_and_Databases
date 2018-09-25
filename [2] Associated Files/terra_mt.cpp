#include <stdio.h>
#include "mkl_vsl.h"

int main(){
	double r[1000]; /* buffer for random numbers */
	double s; /* average */
	VSLStreamStatePtr stream;
	int i, j;
	
	/* Initializing */
	s = 0.0;
	vslNewStream( &stream, VSL_BRNG_MT19937, 777 );			
	for ( i=0; i<1000000; i++ ) {
		vdRngGaussian( VSL_RNG_METHOD_GAUSSIAN_ICDF, stream, 1000, r, 1.0, 2.0 );
		for ( j=0; j<1000; j++ ) {
			s += r[j];
		}
	}
	s /= 1000000000.0;
	
	/* Deleting the stream */
	vslDeleteStream( &stream );
	/* Printing results */
	printf( "Sample mean of normal distribution = %f\n", s );
	return 0;
}
