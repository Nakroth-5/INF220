z ----���3�  \ R E G I S T R Y \ M A C H I N E \ S O F T W A R E \ M i c r o s o f t \ V i s u a l S t u d i o   S e t u p   

MatrizD_2_nodos::MatrizD_2_nodos(): ptrFila(nullptr), dimf(0), dimc(0), nt(0), rep(0) {}

void MatrizD_2_nodos::dimencionar(int df, int dc) {
    dimf = df; dimc = dc;
}

int MatrizD_2_nodos::dimencion_columna() { return dimc; }

int MatrizD_2_nodos::dimencion_fila() { return dimf; }

bool MatrizD_2_nodos::direccion_valida(int f, int c) {
    if ((f > 0 && f <= dimencion_fila()) && (c > 0 && c <= dimencion_columna()))
        return true;
    return false;
}

MatrizD_2_nodos::direccion MatrizD_2_nodos::buscar_nodo_f(int f) {
    for (direccion x = ptrFila; x; x = x->fila_sig) {
        if (x->fila == f)
            return x;
    }
    return nullptr;
}

MatrizD_2_nodos::direccion MatrizD_2_nodos::buscar_nodo_c(direccion nodo_f, int c) {
    if (!nodo_f) return nullptr;
    for (NodoC* x = nodo_f->PtrCol; x; x = x->col_sig) {
        if (x->columna == c)
            return x;
    }
    return nullptr;
}

void MatrizD_2_nodos::poner_dato(int f, int c, int valor) {
    if (!direccion_valida(f, c))
        throw Exception("Error fuera de rango");
    direccion dir_fila = buscar_nodo_f(f);
    if (!dir_fila) {
        dir_fila = new NodoF();
        dir_fila->fila = f;
        dir_fila->PtrCol = nullptr;
        dir_fila->fila_sig = ptrFila;
        dir_fila->fila_ant = nullptr;
        if (ptrFila)
            ptrFila->fila_ant = dir_fila;
        ptrFila = dir_fila;
    }

    NodoC* dir_columna = buscar_nodo_c(dir_fila, c);
    if (!dir_columna) {
        dir_columna = new NodoC();
        dir_columna->columna = c;
        dir_columna->col_sig = dir_fila->PtrCol;
        dir_fila->PtrCol = dir_columna;
    }
    dir_columna->dato = valor;
}

void MatrizD_2_nodos::dibujar(TCanvas *canvas, int x, int y,
                               int ancho_celda, int alto_celda, const string &mensaje, TColor color, bool con_borde) {

    TRect rect(x, y, x + ancho_celda, y + alto\ R E G I S T R Y \ M A C H I N E \ S O F T W A R E \ W O W 6 4 3 2 N o d e \ M i c r o s o f t \ V i s u a l S t u d i o   S e t u p   (con_borde) {
        canvas->Pen->Color = clBlack;
        canvas->MoveTo(x, y);
        canvas->LineTo(x + ancho_celda, y);
        canvas->LineTo(x + ancho_celda, y + alto_celda);
        canvas->LineTo(x, y + alto_celda);
        canvas->LineTo(x, y);
    }
}

void MatrizD_2_nodos::dibujar_matriz(TCanvas *canvas, int x_inicial, int y_inicial, int ancho_celda, int alto_celda) {
    canvas->Brush->Color = clGradientActiveCaption;  // Color de fondo del canvas
    TRect rect(x_inicial, y_inicial, 1000, 1000);   // Área del canvas
    canvas->FillRect(rect);                         // Rellenar el área con el color de fondo

    int x, y;
    for (int fila = 1; fila <= dimf; ++fila) {
        for (int columna = 1; columna <= dimc; ++columna) {
            x = x_inicial + (columna - 1) * ancho_celda;  // Posición X de la celda
            y = y_inicial + (fila - 1) * alto_celda;      // Posición Y de la celda

            NodoF* nodoF = buscar_nodo_f(fila);        // Buscar nodo de fila
            NodoC* nodoC = nullptr;
            if (nodoF != nullptr) {
                nodoC = buscar_nodo_c(nodoF, columna);  // Buscar nodo de columna
            }

            string mensaje;
            TColor color;
            if (nodoC != nullptr) {
                mensaje = to_string(nodoC->dato);  // Mostrar el valor del nodo de columna
                color = clSkyBlue;                 // Color para celdas con valores no nulos
            } else {
                mensaje = to_string(rep);          // Mostrar el valor repetido
                color = clWhite;                   // Color para celdas con valores nulos
            }

            dibujar(canvas, x, y, ancho_celda, alto_celda, mensaje, color, true);  // Dibujar la celda
        \ R E G I S \ R E G I S T R Y \ M A C H I N E \ S O F T W A R E \ W O W 6 4 3 2 N o d e \ M i c r o s o f t \ V i s u a l