#include<iostream>
#include"integral.h"

using namespace std;

Integral::Integral(double a, double b){
    checkInterval (a,b);
    m_nstep = 0;
    m_h = 0; 
    m_sum = 0;
    m_integral =0;
  }

void Integral::checkInterval(double a, double b){
		m_a=min(a, b);
		m_b=max(a, b);
		if(a>b) m_sign=-1;
		else m_sign=1;
  }

Simpson::Simpson(double a, double b):Integral(a, b){}

double Simpson::Integra(unsigned int nstep, FunzioneBase& f){

		if(nstep==0) {cout<<"Error number of steps is negative"<<endl; exit(-1);}

		m_nstep=nstep;
		m_h=(m_b-m_a)/m_nstep;

		double f0=f.Eval(m_a);
		double fN=f.Eval(m_b);

		m_sum=f0+fN;

		for(unsigned int i=1; i<m_nstep; i++){
			if(i%2==0){
			m_sum+=2*f.Eval(m_a+i*m_h);
			}
			else {m_sum+=4*f.Eval(m_a+i*m_h);
			}
		}
		m_integral=(f0+m_sign*m_sum+fN)*(m_h/3);
		return m_integral;
  }

Midpoint::Midpoint(double a, double b):Integral(a, b){}

double Midpoint::Integra(unsigned int nstep, FunzioneBase& f){

		if(nstep==0) {cout<<"Error number of steps is negative"<<endl; exit(-1);}

		m_nstep=nstep;
		m_h=(m_b-m_a)/m_nstep;
		double integrale=0;

		m_sum=0;

		for(unsigned int i=0; i<m_nstep; i++){
			m_sum+=f.Eval(m_a+(i+0.5)*m_h);
		}
		m_integral=m_sign*m_sum*m_h;
		return m_integral;
  }

Midright::Midright(double a, double b):Integral(a,b){}

double Midright::Integra(unsigned int nstep, FunzioneBase& f){

		if(nstep==0) {cout<<"Error number of steps is negative"<<endl; exit(-1);}

		m_nstep=nstep;
		m_h=(m_b-m_a)/m_nstep;
		double integrale=0;

		m_sum=0;

		for(unsigned int i=0; i<m_nstep; i++){
			m_sum+=f.Eval(m_a+(i+1)*m_h);
		}
		m_integral=m_sign*m_sum*m_h;
		return m_integral;
  }

Trapezoidi::Trapezoidi (double a, double b): Integral (a, b){};

double Trapezoidi::Integra(unsigned int nstep, FunzioneBase& f){

		m_nstep=nstep;
		m_h=(m_b-m_a)/m_nstep;
		m_sum=(f.Eval(m_a)+f.Eval(m_b))*0.5;
		m_integral=m_sum;

		for(int i=1; i<m_nstep-1; i++)	{
					m_sum+=f.Eval(m_a+m_h*i);
			}
			m_integral=m_sum*m_h;
		
		return m_integral;
  }

//precisione fissata

/*

class Integral {

 public:
  
  Integral (double a, double b){
    checkInterval (a,b);
    m_nstep = 0;
    m_h = 0; 
    m_sum =0;
    m_integral =0;
		m_prec=0;
		m_err=0;
  }

  virtual double Integra(double prec, FunzioneBase& f) = 0;

 protected:

  void checkInterval (double a, double b){
		m_a=min(a, b);
		m_b=max(a, b);
		if(a>b) m_sign=-1;
		else m_sign=1;
  }

  unsigned int m_nstep;
  double m_a, m_b;
  double m_sum, m_integral, m_h, m_prec, m_err;
  int m_sign;
};

// derived class : Midpoint integrator

class Trapezoidi : public Integral {

 public:

  Trapezoidi (double a, double b) : Integral (a, b){;};

  double Integra(double prec, FunzioneBase& f) override{

		if(prec==0) {cout<<"Error precision is negative"<<endl; exit(-1);}

		m_prec=prec;
		m_nstep=2;
		m_h=(m_b-m_a)/m_nstep;
		m_sum=(f.Eval(m_a)+f.Eval(m_b))*0.5;
		m_integral=m_sum*m_h;

		while (true){
			double integral_2=m_integral;
			m_nstep *= 2;
			m_h /= 2;
			for(int i=1; i<m_nstep-1; i+=2)	{
					m_sum+=f.Eval(m_a+m_h*i);
			}
			m_integral=m_sum*m_h;
			m_err=(4./3.)*abs(integral_2-m_integral);
			
			if(m_err<m_prec) break;
		}//(m_err>m_prec)
		
		return m_integral;
  };

};

*/

