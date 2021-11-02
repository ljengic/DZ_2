#include <math.h>
#include <stdio.h>
#include <cmplx.h>
#include <io.h>

const int maxn=5;

int main(){

cmplx_t a[maxn];
cmplx_t b[maxn];

float t=0;

for(int i=0;i<maxn;i++){
	float val=sin(2*PI*50*t);
	a[i][0]=val;
	a[i][1]=0;
	t+=0.005;
}

cmplx_dft(a,b,maxn);

float vrijednosti[2*maxn];

for(int i=0;i<2*maxn;i++){
	float temp = (i%2==0)?b[i/2][0]:b[i/2][1];
	vrijednosti[i]=temp;
}

int f=open("./data/test.bin",O_WRONLY);

for(int i=0;i<2*maxn;i++){
        void *a = (void *) &vrijednosti[i];
        int vrijednost_ieee = *((int *) a);
        int vrijednost_cijeli_broj = (int) vrijednosti[i];

        write_word(f,vrijednost_ieee);
}

return 0;
}

