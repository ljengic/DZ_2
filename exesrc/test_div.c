#include <stdio.h>
#include <cmplx.h>

int main(){

cmplx_t a={5,0};
cmplx_t b={3,2};
cmplx_t c;

cmplx_div(a,b,c);

printf("\nTest funkcije cmplx_div:\n");

printf("a/b = %.6lf + %.6lf*i\n",c[0],c[1]);

return 0;
}


