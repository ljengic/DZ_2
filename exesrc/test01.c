#include <stdio.h>
#include <cmplx.h>

typedef double cmplx_t[2];

int main(){

cmplx_t a[5]={{5,0},{7,0},{3,0},{2,0},{1,0}};
cmplx_t b[5];

cmplx_dft(a,b,5);

for(int i=0;i<5;i++)
printf("b[i] = %.6lf + i%.6lf\n",b[i][0],b[i][1]);

printf("\n\n");

cmplx_idft(b,a,5);

for(int i=0;i<5;i++)
printf("a[i] = %.6lf + i%.6lf\n",a[i][0],a[i][1]);



return 0;
}

