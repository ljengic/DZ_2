#include <stdio.h>
#include <math.h>
#include <cmplx.h>

#define PI M_PI	

typedef double cmplx_t[2];


void cmplx_div(cmplx_t a, cmplx_t b, cmplx_t c){
	double mag_a=cmplx_mag(a);
	double mag_b=cmplx_mag(b);
	
	double phs_a=cmplx_phs(a);
	double phs_b=cmplx_phs(b);

	double mag_c=mag_a/mag_b;
	double phs_c=phs_a-phs_b;

	c[0]=cmplx_real(mag_c,phs_c);
	c[1]=cmplx_imag(mag_c,phs_c);
}


void cmplx_mul(cmplx_t a, cmplx_t b, cmplx_t c){
        double mag_a=cmplx_mag(a);
        double mag_b=cmplx_mag(b);

        double phs_a=cmplx_phs(a);
        double phs_b=cmplx_phs(b);

        double mag_c=mag_a*mag_b;
        double phs_c=phs_a+phs_b;

        c[0]=cmplx_real(mag_c,phs_c);
        c[1]=cmplx_imag(mag_c,phs_c);
}


double cmplx_mag(cmplx_t a){
	return sqrt(a[0]*a[0]+a[1]*a[1]);
}


double cmplx_phs(cmplx_t a){
	double fi=atan(a[1]/a[0]);
	double x=a[0];
	double y=a[1];
	if(x==0 && y>0) return PI/2;
	if(x==0 && y<0) return -PI/2;
	if(x<0 && y>=0) return fi+PI;
	if(x<0 && y<=0) return fi-PI;
	return fi;
}


double cmplx_real(double mag, double phs){
	return mag*cos(phs);
}


double cmplx_imag(double mag, double phs){
	return mag*sin(phs);
}


void cmplx_dft(cmplx_t *input, cmplx_t *output, int N){
	cmplx_t sol,temp;
	double fi;
	for(int i=0;i<N;i++){
		 output[i][0]=0;
                 output[i][1]=0;
		for(int j=0;j<N;j++){

			fi=-2*PI*(1./N)*i*j;
			temp[0]=cmplx_real(1,fi);
			temp[1]=cmplx_imag(1,fi);
			cmplx_mul(input[j],temp,sol);

			output[i][0]+=sol[0];
			output[i][1]+=sol[1];
		}
	}
}


void cmplx_idft(cmplx_t *input, cmplx_t *output, int N){
        cmplx_t sol,temp;
        double fi;
        for(int i=0;i<N;i++){
		 output[i][0]=0;
                 output[i][1]=0;

                for(int j=0;j<N;j++){

                        fi=2*PI*(1./N)*i*j;
                        temp[0]=cmplx_real(1,fi);
                        temp[1]=cmplx_imag(1,fi);
                        cmplx_mul(input[j],temp,sol);

                        output[i][0]+=sol[0];
                        output[i][1]+=sol[1];
                }
		output[i][0]*=(1./N);
		output[i][1]*=(1./N);

        }

}

