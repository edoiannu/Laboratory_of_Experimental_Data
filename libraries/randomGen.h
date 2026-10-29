#ifndef __RANDOMGEN_H__
#define __RANDOMGEN_H__

#include <cmath>

class RandomGen{

  public:
     RandomGen(unsigned int s){
			 m_seed=s;
			 m_a=1664525;
			 m_c=1013904223;
			 m_m=pow(2, 31);
		 };

     void SetA(unsigned int a) {m_a = a;};
     void SetC(unsigned int c) {m_c = c;};
     void SetM(unsigned int m) {m_m = m;};

     double Rand(){
			 double x=(m_a*m_seed+m_c)%m_m;
			 m_seed=x;
			 return x/(m_m-1);
		 };
		 
			//distribuzione uniforme
     double Unif(double xmin, double xmax){

			 if(xmin>xmax){
				 double appo=xmin;
				 xmin=xmax;
				 xmax=appo;
			 };
			 return Rand()*(xmax-xmin)+xmin;
		 };

			//distribuzione esponenziale
     double Exp(double mean){
			 	return -(mean)*log(1.-Rand());
		 };
		 
		 	//distribuzione gaussiana (box-muller)
     double Gauss(double mean, double sigma){
			 double t=Rand();
			 double s=Rand();
			 double x=sqrt(-2.*log(1.-s))*cos(2.*M_PI*t);
			 return mean+x*sigma;
		 };

			//distribuzione gaussiana (accept reject)
     double GaussAR(double mean, double sigma){
			 double t=Rand();
			 double s=Rand();
			 double a=-3.*sigma;
			 double b=3.*sigma;
			 double x=a+(b-a)*s;
			 double y=(1./(sigma*sqrt(2*M_PI)))*t;

			 if(y<fGauss(x, mean, sigma)){
				 return x;
			 }
	
		 };

  private:
     unsigned int m_a, m_c, m_m;
     unsigned int m_seed;

		 double fGauss(double x, double mean, double sigma){
			 return (1./(sigma*sqrt(2*M_PI)))*pow(M_E, (-pow((x-mean), 2)/(2*pow(sigma, 2))));
		 }
};

#endif
