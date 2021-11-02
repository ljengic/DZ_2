#include <stdio.h>
#include <cmplx.h>

int main(){

cmplx_t a={0,0};

double faza=cmplx_phs(a);

printf("\nTest funkcije cmplx_phs:\n");

printf("faza od a = %.6lf\n",faza);

return 0;
}




