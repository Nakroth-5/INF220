//---------------------------------------------------------------------------

#ifndef ConjuntoLH
#define ConjuntoLH
#include "Lista.h"
class ConjuntoL {
private:
    Lista *lista;
public:
    ConjuntoL ();
    bool vacio();
    bool pertenece(int elemento);
    void inserta(int elemento);
    int cardinal();
    int ordinal(int elemento);
    int muestrea();
    void suprime(int elemento);
    void anula();
    void unir(ConjuntoL *c1, ConjuntoL *&c2);
    void interseccion(ConjuntoL *c1, ConjuntoL *&c2);
    void mostrar(TCanvas *canvas, String conj,int x, int y);
};
//---------------------------------------------------------------------------
#endif
