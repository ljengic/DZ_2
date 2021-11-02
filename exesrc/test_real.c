#include <stdio.h>
#include <cmplx.h>

int main(){

double m=5,p=0.54;

double realni=cmplx_real(m,p);

printf("\nTest funkcije cmplx_real:\n");

printf("Realni dio od a = %.6lf\n",realni);

return 0;
}



