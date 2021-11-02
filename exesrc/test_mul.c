#include <stdio.h>
#include <cmplx.h>

int main(){

cmplx_t a={0,0};
cmplx_t b={1,0};
cmplx_t c;

cmplx_mul(a,b,c);

printf("\nTest funkcije cmplx_mul:\n");

printf("a*b = %.6lf + %.6lf*i\n",c[0],c[1]);

return 0;
}

