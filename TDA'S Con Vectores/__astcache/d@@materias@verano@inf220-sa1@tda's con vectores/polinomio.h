//---------------------------------------------------------------------------

#ifndef PolinomioH
#define PolinomioH
#include "Lista.h"

struct NodoP {
    int coef;
    int exp;
};

NodoP *vec;
class Polinomio {
private:
    int nt;
    direccion buscar_termino(int i);
    direccion buscar_exponente(int exp);
public:
    Polinomio();
    bool es_cero();
    int grado();
    int coeficiente(int exp);
    int exponente(int ntr);
    void asignar_coef(int coef, int exp);
    void poner_termino(int coef, int exp);
    int numero_terminos();
    void operacion(Polinomio *p1, Polinomio *p2, int signo);
    void suma(Polinomio *p1, Polinomio *p2);
    void resta(Polinomio *p1, Polinomio *p2);
    void multiplicar(Polinomio *p1, Polinomio *p2);
    void suprime(int exp);
    double evaluar(double x);
    void derivar();
    void mostrar(TCanvas *canvas, int x, int y);
};
//---------------------------------------------------------------------------
#endif
