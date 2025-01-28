//---------------------------------------------------------------------------

#ifndef ConjuntoPH
#define ConjuntoPH

class ConjuntoP {
private:
    struct NodoC {
        int dato;
        NodoC *sig;
    };
    typedef NodoC *direccion;
    direccion ptrConjunto;
    int cantidad;
public:
    ConjuntoP ();
    ~ConjuntoP();
    bool vacio();
    bool pertenece(int elemento);
    void inserta(int elemento);
    int cardinal();
    int ordinal(int elemento);
    void suprime(int elemento);
    int muestrea();
    void anula();
    void unir(ConjuntoP *c1, ConjuntoP *&c2);
    void interseccion(ConjuntoP *c1, ConjuntoP *&c2);
    void mostrar(TCanvas *canvas, String conj, int x, int y);
};
//---------------------------------------------------------------------------
#endif
