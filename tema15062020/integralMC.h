#ifndef __INTEGRALMC_H__
#define __INTEGRALMC_H__

#include"RandomGen.h"
#include"funzioneBase.h"

using namespace std;

class IntegralMC{

	public:

	IntegralMC (unsigned int seed);
	~IntegralMC();

	double IntegralHoM(double min, double max, double fmax, FunzioneBase *f, int punti);

	double IntegralAVE(double min, double max, FunzioneBase *f, int punti);
	
	private:

	RandomGen * m_myrand;
	double m_errore;
	unsigned int m_punti;

};

#endif