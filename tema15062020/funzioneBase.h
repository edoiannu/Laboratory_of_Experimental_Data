#ifndef __FunzioneBase__
#define __FunzioneBase__

#include<cmath>

class FunzioneBase {

  public:

  virtual double Eval (double) const=0;
  virtual ~FunzioneBase() {;};

};

class Fun1 : public FunzioneBase{

	double Eval (double x) const override {return pow(x,3)*log(sqrt(M_E+x*x));};
};

#endif // __FunzioneBase__
