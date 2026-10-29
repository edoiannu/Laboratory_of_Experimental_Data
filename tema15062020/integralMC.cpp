#include "integralMC.h"
#include<cmath>

IntegralMC::IntegralMC (unsigned int seed){m_myrand=new RandomGen(seed);
m_errore=0.;}

IntegralMC::~IntegralMC(){}

double IntegralMC::IntegralHoM(double min, double max, double fmax, FunzioneBase *f, int punti){
		
    int n_hit=0;
    
    for(int i=0; i<punti; i++){
        double x=m_myrand->Unif(min, max);
        double y=m_myrand->Unif(0, 1);

        if(y<f->Eval(x)){
            n_hit++;
        }
    }

    double integral=(max-min)*fmax*(double(n_hit)/double(punti));

    return integral;

}

double IntegralMC::IntegralAVE(double min, double max, FunzioneBase *f, int punti){

    double sum=0;
    double x=0;
    
    for(int i=0; i<punti; i++){
        x=m_myrand->Unif(min, max);
        sum+=f->Eval(x);
    }

    double integral=(max-min)*double(sum/punti);
    
    return integral;
}