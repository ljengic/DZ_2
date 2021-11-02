#include <stdio.h>
#include <math.h>
#include <cmplx.h>	

void cmplx_div(cmplx_t a, cmplx_t b, cmplx_t c){
	float mag_a=cmplx_mag(a);
	float mag_b=cmplx_mag(b);
	
	float phs_a=cmplx_phs(a);
	float phs_b=cmplx_phs(b);

	float mag_c=mag_a/mag_b;
	float phs_c=phs_a-phs_b;

	c[0]=cmplx_real(mag_c,phs_c);
	c[1]=cmplx_imag(mag_c,phs_c);
}


void cmplx_mul(cmplx_t a, cmplx_t b, cmplx_t c){
        float mag_a=cmplx_mag(a);
        float mag_b=cmplx_mag(b);

        float phs_a=cmplx_phs(a);
        float phs_b=cmplx_phs(b);

        float mag_c=mag_a*mag_b;
        float phs_c=phs_a+phs_b;

        c[0]=cmplx_real(mag_c,phs_c);
        c[1]=cmplx_imag(mag_c,phs_c);
}


float cmplx_mag(cmplx_t a){
	return sqrt(a[0]*a[0]+a[1]*a[1]);
}


float cmplx_phs(cmplx_t a){
        float x=a[0];
        float y=a[1];

	if(y==0 && x>=0) return 0;
	if(y==0 && x<0) return PI;
	float fi=atan(a[1]/a[0]);
	if(x==0 && y>0) return PI/2;
	if(x==0 && y<0) return -PI/2;
	if(x<0 && y>0) return fi+PI;
	if(x<0 && y<0) return fi-PI;
	return fi;
}


float cmplx_real(float mag, float phs){
	return mag*cos(phs);
}


float cmplx_imag(float mag, float phs){
	return mag*sin(phs);
}


void cmplx_dft(cmplx_t *input, cmplx_t *output, int N){
	cmplx_t sol,temp;
	float fi;
	for(int i=0;i<N;i++){
		 output[i][0]=0.;
                 output[i][1]=0.;
		for(int j=0;j<N;j++){

			fi=-2*PI*(1./N)*i*j;
			temp[0]=cmplx_real(1.,fi);
			temp[1]=cmplx_imag(1.,fi);
			cmplx_mul(input[j],temp,sol);

			output[i][0]+=sol[0];
			output[i][1]+=sol[1];
		}
	}
}


void cmplx_idft(cmplx_t *input, cmplx_t *output, int N){
        cmplx_t sol,temp;
        float fi;
        for(int i=0;i<N;i++){
		 output[i][0]=0.;
                 output[i][1]=0.;

                for(int j=0;j<N;j++){

                        fi=2*PI*(1./N)*i*j;
                        temp[0]=cmplx_real(1.,fi);
                        temp[1]=cmplx_imag(1.,fi);
                        cmplx_mul(input[j],temp,sol);

                        output[i][0]+=sol[0];
                        output[i][1]+=sol[1];
                }
		output[i][0]*=(1./N);
		output[i][1]*=(1./N);

        }

}

