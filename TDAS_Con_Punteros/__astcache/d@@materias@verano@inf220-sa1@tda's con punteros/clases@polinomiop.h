//---------------------------------------------------------------------------

#ifndef PolinomioPH
#define PolinomioPH
#include <vcl.h>
#include <math.h>


class PolinomioP {
private:
    struct NodoPol {
		int coef;
		int exp;
        NodoPol *sig;
        NodoPol(int coef, int exp): coef(coef), exp(exp), sig(nullptr) {}
	};
	typedef NodoPol *direccion;

    direccion ptrPoli;
    direccion buscar_exponente(int exp);
    direccion buscar_termino(int i);
    int nt;
public:
	PolinomioP();
	~PolinomioP();
    bool es_cero();
    int grado();
    int coeficiente(int exp);
    void asignar_coef(int coef, int exp);
    void poner_termino(int coef, int exp);
    int numero_terminos();
    int exponente(int ntr);
    void suma(PolinomioP *p1, PolinomioP *p2);
    void resta(PolinomioP *p1, PolinomioP *p2);
	void multiplicar(PolinomioP *p1, PolinomioP *p2);
    void suprime(int exp);
    double evaluar(double x);
    void derivar(PolinomioP *p1);
    void mostrar(TCanvas *canvas, int x, int y);
};
//---------------------------------------------------------------------------
#endif
