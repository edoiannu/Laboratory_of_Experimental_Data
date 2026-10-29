//RooT
#include "TGraph.h"
#include "TCanvas.h"
#include "TApplication.h"
#include "TAxis.h"
#include "TH1F.h"
#include "TF1.h"

#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
#include<iomanip>
#include"integral.h"
#include"integralMC.h"

using namespace std;

int main(){

    Fun1 f1;
    double f1_exp=(3./16.)*pow(M_E, 2);
    double integral=0.;

    ofstream fo("soluzione.txt");

    Midpoint myInt1(0, sqrt(M_E));

    TApplication myApp("myApp",0,0); 

    TGraph Graph1;

    fo<<"1) Andamento dell'errore in funzione del numero di punti - metodo midpoint"<<endl;
    fo<<"n punti"<<setw(5)<<"\t"<<"errore"<<endl;

    for(int i=1; i<=10; i++){
        integral=myInt1.Integra(pow(2,i), f1);
        fo<<pow(2,i)<<setw(8)<<"\t"<<abs(integral-f1_exp)<<endl;
        Graph1.SetPoint(i-1, sqrt(M_E)/pow(2,i), abs(integral-f1_exp));
    }

    TCanvas canva1("canva1", "1", 400, 400);

    TF1 *fit1=new TF1("f1", "[0]*x^[1]");

    Graph1.Fit(fit1, "Q");

    Graph1.SetTitle("1) Andamento dell'errore in funzione del numero di punti - metodo midpoint");
    Graph1.GetXaxis()->SetTitle("lunghezza passo");
    Graph1.GetYaxis()->SetTitle("errore");

    Graph1.Draw("ALP*");
	Graph1.SetMarkerColor(kRed);

    fo<<endl<<"2) metodo midpoint - noto l'andamento dell'errore in funzione del passo h come come err=k1*h^k2 i valori k1 e k2 sono "<<endl;
    fo<<"k1 = "<<fit1->GetParameter(0)<<endl;
    fo<<"k2 = "<<fit1->GetParameter(1)<<endl;

    Midright myInt2(0, sqrt(M_E));

    TGraph Graph2;

    fo<<endl<<"3) Andamento dell'errore in funzione del numero di punti - metodo midright"<<endl;
    fo<<"n punti"<<setw(5)<<"\t"<<"errore"<<endl;

    for(int i=1; i<=10; i++){
        integral=myInt2.Integra(pow(2,i), f1);
        fo<<pow(2,i)<<setw(8)<<"\t"<<abs(integral-f1_exp)<<endl;
        Graph2.SetPoint(i-1, sqrt(M_E)/pow(2,i), abs(integral-f1_exp));
    }

    TCanvas canva2("canva2", "2", 400, 400);

    TF1 *fit2=new TF1("f2", "[0]*x^[1]");

    Graph2.Fit(fit2, "Q");

    Graph2.SetTitle("3) Andamento dell'errore in funzione del numero di punti - metodo midright");
    Graph2.GetXaxis()->SetTitle("lunghezza passo");
    Graph2.GetYaxis()->SetTitle("errore");

    Graph2.Draw("ALP*");
	Graph2.SetMarkerColor(kRed);

    fo<<endl<<"4) metodo midright - noto l'andamento dell'errore in funzione del passo h come come err=k1*h^k2 i valori k1 e k2 sono "<<endl;
    fo<<"k1 = "<<fit2->GetParameter(0)<<endl;
    fo<<"k2 = "<<fit2->GetParameter(1)<<endl;

    TCanvas canva3("canva3", "3", 700, 400);

    TH1F Histo1("histo1", "5) metodo della media - 1000 valori dell'integrale con 16 estrazioni", 100, 0, 3);
    TGraph StdDev;

    IntegralMC myInt3(1);

    for(int i=0; i<1000; i++)
    Histo1.Fill(myInt3.IntegralAVE(0, sqrt(M_E), &f1, 16));

    Histo1.GetXaxis()->SetTitle("Valore integrale");
	Histo1.GetYaxis()->SetTitle("Uscite");

    Histo1.Draw();

    fo<<endl<<"5) errore del calcolo dell'integrale ripetuto 1000 volte con 16 estrazioni = "<<Histo1.GetStdDev()<<endl;

    //errore integrale midpoint con 16 punti

    double err=abs(myInt1.Integra(16, f1)-f1_exp);

    //studio dell'andamento dell'errore nel metodo della media

    TCanvas canva4("canva4", "4", 800, 500);
    canva4.Divide(3, 2);

    vector<double> v1(1000);
	vector<double> v2(1000);
	vector<double> v3(1000);
	vector<double> v4(1000);
	vector<double> v5(1000);

    vector<vector<double>> v = {v1, v2, v3, v4, v5};
    vector<unsigned int> points={100, 500, 1000, 5000, 10000};

    TH1F int1("int1","100 punti", 100, 0, 3);
	TH1F int2("int2","500 punti", 100, 0, 3);
	TH1F int3("int3","1000 punti", 100, 0, 3);
	TH1F int4("int4","5000 punti", 100, 0, 3);
	TH1F int5("int5","10000 punti", 100, 0, 3);
	TGraph DevStd;

    vector<TH1F> vintegral = {int1, int2, int3, int4, int5};

    for(int k=0; k<5; k++){
	for(int i=0; i<1000; i++){
		vintegral[k].Fill(myInt3.IntegralAVE(0, sqrt(M_E), &f1, points[k]));
	}
	}

    for(int k=1; k<=5; k++){
		canva4.cd(k);
		vintegral[k-1].Draw();
	}

    canva4.cd(6);
	for(int i=0; i<5; i++){
		DevStd.SetPoint(i, points[i], vintegral[i].GetStdDev());
	}
	Graph2.SetMarkerColor(kRed);
    DevStd.Draw("ALP*");

    //andamento dell'errore come K*radq(N)

    TF1 *fit3=new TF1("f3", "[0]*pow(x,-0.5)");

	DevStd.Fit(fit3, "Q");

    //troviamo il valore del coefficiente k

    double k=fit3->GetParameter(0);

    unsigned int punti=int(pow(k/err, 2));

    fo<<endl<<"6) numero di punti necessari al metodo della media per ottenere la stessa precisione che si ottiene"<<endl;
    fo<<"con il metodo del midpoint a 16 punti = "<<punti<<endl;

    //punto 7 balza

    myApp.Run();

    return 0;
}