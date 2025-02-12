//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	mem = new CSMemoria();
	if (mem) {
		ShowMessage("Memoria creada");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	if (!mem)
		ShowMessage("Crear memoria primero");
	else {
		string1 ids = Edit1->Text;
		mem->new_espacio(ids.c_str());
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
    if (!mem)
		ShowMessage("Crear memoria primero");
	else {
		int dir = StrToInt(Edit2->Text);
		mem->delete_espacio(dir);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
    if (!mem)
		ShowMessage("Crear memoria primero");
	else {
		int dir = StrToInt(Edit3->Text);
		string1 ids = Edit4->Text;
		int dato = StrToInt(Edit5->Text);
		mem->poner_dato(dir, ids.c_str(), dato);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
    if (!mem)
		ShowMessage("Crear memoria primero");
	else {
		int a = StrToInt(Edit6->Text);
		int b = StrToInt(Edit7->Text);
		mem->mostrar(Form1->Canvas, a, b);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	if (!mem)
		ShowMessage("Crear memoria primero");
	else {
		list = new Lista(mem);
		if (list)
			ShowMessage("Lista creada");
	}


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	if (!list)
		ShowMessage("Crear lista primero");
	else {
		int dato = StrToInt(Edit8->Text);
		list->inserta(list->primero(), dato);
		//list->inserta_primero(dato);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	if (!list)
		ShowMessage("Crear lista primero");
	else {
		int dato = StrToInt(Edit9->Text);
		list->inserta(list->fin(), dato);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
	if (!list)
		ShowMessage("Crear lista primero");
	else
		list->mostrar(Form1->Canvas, 168, 260);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
	if (!mem)
		ShowMessage("Crear memoria primero");
	else {
		pol = new PolinomioM(mem);
		pol1 = new PolinomioM(mem);
		if (pol)
			ShowMessage("Polinomio creado");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
	 if (!pol)
		ShowMessage("Crear polinomio primero");
	else {
		int coef = StrToInt(Edit10->Text);
		int exp = StrToInt(Edit11->Text);
		pol->poner_termino(coef, exp);
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button13Click(TObject *Sender)
{
	if (!pol)
		ShowMessage("Crear polinomio primero");
	else
		pol->mostrar(Form1->Canvas, 168, 380);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button22Click(TObject *Sender)
{
	//pol->anula();                                  /*
	double x = StrToFloat(Edit12->Text);
	Edit12->Text =  pol->evaluar(x);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button23Click(TObject *Sender)
{
    if (pol2)
		pol->anula();
	pol = new PolinomioM(mem);
	pol2->suma(pol, pol1);
	pol2->mostrar(Form1->Canvas, 500, 386);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{   if (pol2)
		pol2->anula();
	pol2 = new PolinomioM(mem);
	pol2->derivar(pol);
	pol2->mostrar(Form1->Canvas, 168, 349);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
	if (!mem)
		ShowMessage("Crear memoria primero");
	else {
		conj_A = new ConjuntoL(mem);
		if (conj_A) {
			ShowMessage("Conjunto creado");
		}
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button15Click(TObject *Sender)
{
	if (!mem)
		ShowMessage("Crear memoria primero");
	else {
		conj_B = new ConjuntoL(mem);
		if (conj_B) {
			ShowMessage("Conjunto creado");
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button16Click(TObject *Sender)
{
    if (!mem)
		ShowMessage("Crear memoria primero");
	else {
		conj_C = new ConjuntoL(mem);
		if (conj_C) {
			ShowMessage("Conjunto creado");
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button17Click(TObject *Sender)
{
    String conj = InputBox("�A que conjunto? A, B, C", "Conjunto: ", "");
	if (conj.Length() == 1) {
		switch (conj[1]) {
			case 'A': {
				if (conj_A) {
					int dato = StrToInt(InputBox("Ingrese un elemento","elemento: ",""));
					conj_A->inserta(dato);
				} else
					ShowMessage("Primero crear el conjunto A");
				break;
			}
			case 'B': {
				if (conj_B) {
					int dato = StrToInt(InputBox("Ingrese un elemento","elemento: ",""));
					conj_B->inserta(dato);
				} else
					ShowMessage("Primero crear el conjunto B");
				break;
			}
			case 'C': {
				if (conj_C) {
					int dato = StrToInt(InputBox("Ingrese un elemento","elemento: ",""));
					conj_C->inserta(dato);
				} else
					ShowMessage("Primero crear el conjunto C");
				break;
			}
            default:
				ShowMessage("Conjunto no v�lido. Por favor, elija A, B o C.");
				break;
		}
	} else
		ShowMessage("Entrada no v�lida. Por favor, ingrese un solo car�cter (A, B o C).");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button18Click(TObject *Sender)
{
    String conj = InputBox("�A que conjunto? A, B, C", "Conjunto: ", "");
	if (conj.Length() == 1) {
		switch (conj[1]) {
			case 'A': {
				if (conj_A) {
					conj_A->mostrar(Form1->Canvas, "A = ", 168, 411);
				} else
					ShowMessage("Primero crear el conjunto A");
				break;
			}
			case 'B': {
				if (conj_B) {
					conj_B->mostrar(Form1->Canvas, "B = ", 168, 442);
				} else
					ShowMessage("Primero crear el conjunto B");
				break;
			}
			case 'C': {
				if (conj_C) {
					conj_C->mostrar(Form1->Canvas, "C = ", 168, 473);
				} else
					ShowMessage("Primero crear el conjunto C");
				break;
			}
			default:
				ShowMessage("Conjunto no v�lido. Por favor, elija A, B o C.");
				break;
		}
	} else
		ShowMessage("Entrada no v�lida. Por favor, ingrese un solo car�cter (A, B o C).");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button19Click(TObject *Sender)
{
	if (conj_C)
		conj_C->anula();
	conj_C = new ConjuntoL(mem);
	conj_A->unir(conj_B, conj_C);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button20Click(TObject *Sender)
{
	if (conj_C)
		conj_C->anula();
	conj_C = new ConjuntoL(mem);
	conj_A->interseccion(conj_B, conj_C);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button21Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button24Click(TObject *Sender)
{
	if (!mem)
		ShowMessage("Crear memoria primero");
	else {
		x = new Matriz_dispersa(mem);
		if (x)
		ShowMessage("Matriz dispersa creada");
	}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button28Click(TObject *Sender)
{
    if (!x)
		ShowMessage("Crear la matriz dispersa");
	else {
		int f = StrToInt(Edit13->Text);
		int c = StrToInt(Edit14->Text);
		x->dimencionar(f, c);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button25Click(TObject *Sender)
{
    if (!x)
		ShowMessage("Crear la matriz dispersa");
	else {
		int valor = StrToInt(Edit15->Text);
		x->definir_valor_repetido(valor);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button26Click(TObject *Sender)
{
    if (!x)
		ShowMessage("Crear la matriz dispersa");
	else {
		int f = StrToInt(Edit16->Text);
		int c = StrToInt(Edit17->Text);
		int dato = StrToInt(Edit18->Text);
		x->poner_dato(f, c, dato);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button27Click(TObject *Sender)
{
    if (!x)
		ShowMessage("Crear la matriz dispersa");
	else {
        x->dibujar_matriz(Form1->Canvas, 886, 130, 25, 25);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button29Click(TObject *Sender)
{
    if (!mem)
		ShowMessage("Crear memoria primero");
	else {
		pila = new Pilas(mem);
		if (pila)
			ShowMessage("Pila creada");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button30Click(TObject *Sender)
{
    if (!pila)
		ShowMessage("Crear la pila primero");
	else {
		double dato = StrToFloat(Edit19->Text);
		pila->poner(dato);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button31Click(TObject *Sender)
{
    if (!pila)
		ShowMessage("Crear la pila primero");
	else {
		double dato;
		pila->sacar(dato);
		pila->mostrar(Form1->Canvas, 1048, 473);
		Edit20->Text = dato;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button32Click(TObject *Sender)
{
    if (!pila)
		ShowMessage("Crear la pila primero");
	else {
		string infija = AnsiString(Edit21->Text).c_str();
		string posfija = pila->prefija_a_posfija(infija, mem);
		Edit22->Text = posfija.c_str();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button33Click(TObject *Sender)
{
    std::string posfija = AnsiString(Edit22->Text).c_str();
	ShowMessage(FloatToStr(pila->evaluar_posfija(posfija, mem)));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button34Click(TObject *Sender)
{
    if (!pila)
		ShowMessage("Crear la matriz dispersa");
	else {
		pila->mostrar(Form1->Canvas, 1048, 473);
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button35Click(TObject *Sender)
{
    if (cola)
		delete cola;
    cola = new Cola(mem);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button36Click(TObject *Sender)
{
    if (!cola)
		ShowMessage("Crear la cola primero");
	else {
		int dato = StrToInt(Edit23->Text);
		cola->poner(dato);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button37Click(TObject *Sender)
{
    if (!cola)
		ShowMessage("Crear la cola primero");
	else {
		int dato;
		cola->sacar(dato);
		Edit24->Text = dato;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button38Click(TObject *Sender)
{
    if (!cola)
		ShowMessage("Crear la cola dispersa");
	else {
		cola->mostrar(Form1->Canvas, 896, 597);
	}
}
//---------------------------------------------------------------------------

