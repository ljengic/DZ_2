#include <io.h>
#include <stdio.h>
#include <cmplx.h>

const int maxn=5;

int main(){

cmplx_t a[maxn];
cmplx_t b[maxn];

int f=open("./data/test.bin",O_RDONLY);

for(int i=0;i<2*maxn;i++){

        int vrijednost_ieee = read_word(f);
        void *a2 = (void *) &vrijednost_ieee;
        float vrijednost = *((float *) a2);

        a[i/2][i%2]=vrijednost;

}

cmplx_idft(a,b,5);


for(int i=0;i<maxn;i++){
	printf("IDFT  b[%d] = %.6lf +%.6lf*i\n",i,b[i][0],b[i][1]);
}

return 0;
}

