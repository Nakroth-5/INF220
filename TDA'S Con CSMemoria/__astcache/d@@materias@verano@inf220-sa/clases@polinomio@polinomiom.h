//---------------------------------------------------------------------------

#ifndef PolinomioMH
#define PolinomioMH
#include "CSMemoria.h"
#include <vcl.h>
class PolinomioM {
private:
    direccion ptrPoli;
    direccion buscar_exponente(int exp);
    direccion buscar_termino(int i);
    int nt;
    CSMemoria *m;
public:
    PolinomioM (CSMemoria *mem);
    ~PolinomioM();
    bool es_cero();
    int grado();
    int coeficiente(int exp);
    void asignar_coef(int coef, int exp);
    void poner_termino(int coef, int exp);
    int numero_terminos() { return nt; }
	int exponente(int ntr);
    void operacion(PolinomioM *p1, PolinomioM *p2, int signo);
	void suma(PolinomioM *p1, PolinomioM *p2);
	void resta(PolinomioM *p1, PolinomioM *p2);
	void multiplicar(PolinomioM *p1, PolinomioM *p2);
	void suprime(int exp);
    double evaluar(double x);
    void derivar(PolinomioM *p1);
    void mostrar(TCanvas *canvas, int x, int y);
};
//---------------------------------------------------------------------------
#endif
