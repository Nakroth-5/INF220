//---------------------------------------------------------------------------

#ifndef PolinomioLH
#define PolinomioLH
#include "Lista.h"
#include <vcl.h>

class PolinomioL {
private:
	Lista *pol;
	direccion buscar_termino(int i);
	direccion buscar_exponente(int exp);
public:
	PolinomioL();
    ~PolinomioL();
    bool es_cero();
    int grado();
    int coeficiente(int exp);
    void asignar_coef(int coef, int exp);
    void poner_termino(int coef, int exp);
    int numero_terminos() { return pol->getLongitud() / 2; }
    int exponente(int ntr);
    void operacion(PolinomioL *p1, PolinomioL *p2, int signo);
    void suma(PolinomioL *p1, PolinomioL *p2);
    void resta(PolinomioL *p1, PolinomioL *p2);
    void multiplicar(PolinomioL *p1, PolinomioL *p2);
    void suprime(int exp);
    double evaluar(double x);
    void derivar();
    void mostrar(TCanvas *canvas, int x, int y);
};
//---------------------------------------------------------------------------
#endif
