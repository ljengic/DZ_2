#include <stdio.h>
#include <cmplx.h>

int main(){

cmplx_t a[5]={{1,0},{0,0},{-1,0},{0,0},{1,0}};
cmplx_t b[5];

cmplx_dft(a,b,5);

printf("\nTest funkcije cmplx_dft:\n");

for(int i=0;i<5;i++)
        printf("b[i] = %.6lf + %.6lf*i\n",b[i][0],b[i][1]);

return 0;
}

