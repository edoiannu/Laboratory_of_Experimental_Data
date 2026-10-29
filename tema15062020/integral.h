#ifndef __INTEGRAL_H__
#define __INTEGRAL_H__

#include "funzioneBase.h"

class Integral {

 public:
  
  Integral (double a, double b);

  virtual double Integra(unsigned int nstep, FunzioneBase& f) = 0;

    protected:

  void checkInterval (double a, double b);

  unsigned int m_nstep;
  double m_a, m_b;
  double m_sum, m_integral, m_h;
  int m_sign;
};

class Simpson : public Integral {

 public:

  Simpson (double a, double b);

  double Integra(unsigned int nstep, FunzioneBase& f) override;

};

class Midpoint : public Integral {

 	public:

	Midpoint (double a, double b);

    double Integra(unsigned int nstep, FunzioneBase& f) override;

};

class Midright : public Integral {

 	public:

	Midright (double a, double b);

    double Integra(unsigned int nstep, FunzioneBase& f) override;

};


class Trapezoidi : public Integral {

 public:

  Trapezoidi (double a, double b);

  double Integra(unsigned int nstep, FunzioneBase& f) override;


};

#endif // __INTEGRAL_H__
