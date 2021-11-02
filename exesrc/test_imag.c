#include <stdio.h>
#include <cmplx.h>

int main(){

double m=5,p=0.54;

double imaginarni=cmplx_imag(m,p);

printf("\nTest funkcije cmplx_imag:\n");

printf("Imaginarni dio od a = %.6lf\n",imaginarni);

return 0;
}



