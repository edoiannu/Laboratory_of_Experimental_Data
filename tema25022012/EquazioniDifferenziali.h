#ifndef __EquazioniDifferenziali_h__
#define __EquazioniDifferenziali_h__

#include "VectorOperations.h"
#include<cmath>

using namespace std;

class FunzioneVettorialeBase {

public:
  virtual vector<double> Eval(double t, const vector<double> & T) const = 0;
	virtual ~FunzioneVettorialeBase() {;};
};

class CalorimetroIdeale : public FunzioneVettorialeBase {

public:

  	CalorimetroIdeale(double K1, double K2, double T10, double T20) {
			m_K1 = K1;
            m_K2 = K2;
            m_T10 = T10;
            m_T20 = T20;
    };

  	vector<double> Eval(double t, const vector<double> & T) const override {
		
        vector<double> derivata(1);

		derivata[0]=(m_K1*m_T20 + m_K2*m_T10) - T[0]*(m_K1 + m_K2);

		return derivata;
  }

private:
  double m_K1, m_K2, m_T10, m_T20;
};

class CalorimetroReale : public FunzioneVettorialeBase {

public:

  	CalorimetroReale(double K1, double K2, double K3, double T10, double T20) {
			m_K1 = K1;
            m_K2 = K2;
            m_K3 = K3;
            m_T10 = T10;
            m_T20 = T20;
            m_gamma = 0.5*(m_K1 + m_K2 + m_K3);
            m_rho2 = m_K1*m_K3;
    };

  	vector<double> Eval(double t, const vector<double> & T) const override {
		
        vector<double> derivata(2);

		derivata[0]=T[1];
        derivata[1]=-2*m_gamma*T[1]-m_rho2*T[0];

		return derivata;
  }

private:
  double m_K1, m_K2, m_K3, m_T10, m_T20, m_gamma, m_rho2;
};

class EquazioneDifferenzialeBase {
public:
  virtual vector<double> Passo(double t, const vector<double> &x, double h, FunzioneVettorialeBase &f) const = 0;
	virtual ~EquazioneDifferenzialeBase() {;};
};

class RungeKutta : public EquazioneDifferenzialeBase {
public:
  virtual vector<double> Passo(double t, const vector<double> &x, double h, FunzioneVettorialeBase &f) const override {

		vector<double> k1(2), k2(2), k3(2), k4(2);

		k1=f.Eval(t,x);
		k2=f.Eval(t+h/2.,x+k1*(h/2.));
		k3=f.Eval(t+h/2.,x+k2*(h/2.));
		k4=f.Eval(t+h,x+k3*h);

		return x+(k1+2.*k2+2.*k3+k4)*(h/6.);
  }

private:
	double m_omega0;
};

#endif // __EquazioniDifferenziali_h__
