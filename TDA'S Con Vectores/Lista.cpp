//---------------------------------------------------------------------------

#pragma hdrstop

#include "Lista.h"

Lista::Lista(): cantidad(0) {}

bool Lista::vacia() { return cantidad == 0; }

direccion Lista::primero() {
    return 0;
}

direccion Lista::siguiente(direccion dir) {
    if (vacia())
        return -1;
    if (fin())
        return -1;
    return dir + 1;
}

direccion Lista::anterior(direccion dir) {
	return dir - 1;
}


direccion Lista::fin() {
    return cantidad;
}

bool Lista::llena() { return cantidad == max; }

void Lista::inserta_primero(int dato) {
    if (llena())
        throw Exception("No hay espacio");
    for (int i = cantidad; i > 0; i--)
        datos[i] = datos[i - 1];
    datos[0] = dato;
    cantidad++;
}

void Lista::inserta_final(int dato) {
    if (llena())
        throw Exception("No hay espacio");
    datos[cantidad] = dato;
    cantidad++;
}

void Lista::inserta(direccion dir, int dato) {
    if (llena())
		throw Exception("No hay espacio");
	if (dir >= 0 && dir <= cantidad) {
		for (int i = cantidad; i > dir; i--)
            datos[i] = datos[i - 1];
        datos[dir] = dato;
		cantidad++;
    } else
        throw Exception("direccion invalida");
}

void Lista::suprime(direccion dir) {
    if (dir >= 0 && dir < cantidad) {
        for (int i = dir; i < cantidad - 1; i++) {
            datos[i] = datos[i + 1];
        }
        cantidad--;
    }
}

void Lista::modifica(direccion dir, int dato) {
    if (dir >= 0 && dir < cantidad)
        datos[dir] =  dato;
    else
        throw Exception("direccion invalida");
}

int Lista::recupera(direccion dir) {
    if (dir >= 0 && dir < cantidad)
		return datos[dir];
    else
        throw Exception("direccion invalida");
}

void Lista::elimina_dato(int dato) {
    int act = 0;
    int sig = 0;
    while (act < cantidad) {
        sig = act + 1;
		if (datos[act] == dato) {
			suprime(act);
			sig = 0;
            act = 0;
		}
        act = sig;
    }
}

void Lista::anule() {
    while (cantidad > 0)
        suprime(0);
}

void Lista::mostrar(TCanvas *canvas, int x, int y) {
    canvas->Font->Size = 12;
    TRect rect(x, y, 500, y + 20);
    canvas->Brush->Color = clGradientActiveCaption;
    canvas->FillRect(rect);

    if (vacia())
        canvas->TextOut(x, y, "Lista vacia");
    else {
        string listP = "<";
        for (direccion x = 0; x < cantidad; ++x) {
            listP += to_string(recupera(x));
            if (x < cantidad - 1) {
                listP += ", ";
            }
        }
        listP += ">";
        canvas->TextOut(x, y, listP.c_str());
    }
}


//---------------------------------------------------------------------------
#pragma package(smart_init)
