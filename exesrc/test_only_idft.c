#include <stdio.h>
#include <cmplx.h>

int main(){

cmplx_t b[5]={{5,0},{5,7},{0,2},{3,4},{1,1}};
cmplx_t a[5];

cmplx_idft(b,a,5);

printf("\nTest funkcije cmplx_idft:\n");

for(int i=0;i<5;i++)
        printf("a[i] = %.6lf + %.6lf*i\n",a[i][0],a[i][1]);

return 0;
}

