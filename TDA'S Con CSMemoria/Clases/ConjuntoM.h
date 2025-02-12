//---------------------------------------------------------------------------

#ifndef ConjuntoMH
#define ConjuntoMH
#include "CSMemoria.h"
class ConjuntoM {
private:
	direccion ptrConjunto;
	int cantidad;
    CSMemoria *m;
public:
    ConjuntoM (CSMemoria *mem);
	~ConjuntoM();
    bool vacio();
    bool pertenece(int elemento);
    void inserta(int elemento);
    int cardinal();
    int ordinal(int elemento);
	void suprime(int elemento);
	void unir(ConjuntoM *c1, ConjuntoM *&c2);
	void interseccion(ConjuntoM *c1, ConjuntoM *&c2);
    int muestrea();
    void mostrar(TCanvas *canvas, String conj, int x, int y);
};
//---------------------------------------------------------------------------
#endif
