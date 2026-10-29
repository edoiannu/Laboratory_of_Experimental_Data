//RooT
#include "TGraph.h"
#include "TCanvas.h"
#include "TApplication.h"
#include "TAxis.h"

#include<iostream>
#include<fstream>

#include "EquazioniDifferenziali.h"

using namespace std;

int main(){

    double h=0.01;
    double t=0.;
    double tmax=600.;

    double T10=289.37;
    double T20=323.15;
    double K1=0.002;
    double K2=0.01;
    double K3=0.0004;

    ofstream fo("soluzione.txt");

    vector<double> T_ideale={289.37};
    vector<double> T_reale={289.37, 0.};

    TApplication myApp("myApp", 0, 0);

    TGraph myIdealGraph;
    TGraph myRealGraph;
    unsigned int count=0;

    CalorimetroIdeale myIdealCalor(K1, K2, T10, T20);
    CalorimetroReale myRealCalor(K1, K2, K3, T10, T20);
    RungeKutta myRunge;

    while(t<tmax){
        T_ideale=myRunge.Passo(t,T_ideale,h,myIdealCalor);
        T_reale=myRunge.Passo(t,T_reale,h,myRealCalor);
        myIdealGraph.SetPoint(count, t, T_ideale[0]);
        myRealGraph.SetPoint(count, t, T_reale[0]);
        t+=h;
        count++;
    }

    TCanvas myCanva("canva", "Calorimetro", 800, 500);
    myCanva.Divide(2, 1);

    fo<<"Calorimetro ideale - temperatura raggiunta dal sistema a 600 sec = "<<T_ideale[0]<<endl;
    fo<<endl<<"Calorimetro reale - temperatura raggiunta dal sistema a 600 sec = "<<T_reale[0]<<endl;

    myCanva.cd(1);
    myIdealGraph.SetTitle("Calorimetro ideale");
    myIdealGraph.GetXaxis()->SetTitle("Tempo [s]");
    myIdealGraph.GetYaxis()->SetTitle("Temperatura [K]");
    myIdealGraph.Draw();

    myCanva.cd(2);
    myRealGraph.SetTitle("Calorimetro reale");
    myRealGraph.GetXaxis()->SetTitle("Tempo [s]");
    myRealGraph.GetYaxis()->SetTitle("Temperatura [K]");
    myRealGraph.Draw();

    myApp.Run();

    fo.close();

    return 0;
}