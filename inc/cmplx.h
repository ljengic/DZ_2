#include <math.h>
#define PI M_PI 

typedef float cmplx_t[2];


// c = a / b;
void cmplx_div(cmplx_t a, cmplx_t b, cmplx_t c);

// c = a * b;
void cmplx_mul(cmplx_t a, cmplx_t b, cmplx_t c);

// returns |a|
float cmplx_mag(cmplx_t a);

// returns phase in radians of a 
float cmplx_phs(cmplx_t a);

// returns real part of mag/_phs
float cmplx_real(float mag, float phs);

// returns imaginary part of mag/_phs
float cmplx_imag(float mag, float phs);

// returns dft transformation of complex input signal
void cmplx_dft(cmplx_t *input, cmplx_t *output, int N);

// returns inverse dft transformation of complex input signal
void cmplx_idft(cmplx_t *input, cmplx_t *output, int N);
