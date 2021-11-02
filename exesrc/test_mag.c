#include <stdio.h>
#include <cmplx.h>

int main(){

cmplx_t a={0,0};

double magnituda=cmplx_mag(a);

printf("\nTest funkcije cmplx_mag:\n");

printf("magnituda od a = %.6lf\n",magnituda);

return 0;
}




