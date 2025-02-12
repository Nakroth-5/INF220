﻿//---------------------------------------------------------------------------

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
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	lista = new Lista();
	if (lista) {
		ShowMessage("Lista creada");
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	if (!lista)
		ShowMessage("Primero crear la lista");
	else {
		int dato = StrToInt(Edit1->Text);
		lista->inserta(lista->primero(), dato);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	if (!lista)
		ShowMessage("Primero crear la lista");
	else {
		int dato = StrToInt(Edit2->Text);
		lista->inserta(lista->fin(), dato);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
    if (!lista)
		ShowMessage("Primero crear la lista");
	else {
		lista->mostrar(Form1->Canvas, 144, 93);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	pol = new PolinomioP();
	if (pol) {
		ShowMessage("Polinomio creado");
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
	if (!pol)
		ShowMessage("Primero crear el polinomio");
	else {
		int coef = StrToInt(Edit3->Text);
		int exp = StrToInt(Edit4->Text);
		pol->poner_termino(coef, exp);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
    if (!pol)
		ShowMessage("Primero crear el polinomio");
	else {
		/*pol1 = new PolinomioL();
		pol1->derivar(pol);
		pol1->mostrar(Form1->Canvas, 144, 186); */
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
    if (!pol)
		ShowMessage("Primero crear el polinomio");
	else {
		int exp = StrToInt(Edit5->Text);
		pol->suprime(exp);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button16Click(TObject *Sender)
{
    if (!pol)
		ShowMessage("Primero crear el polinomio");
	else {
		pol->mostrar(Form1->Canvas, 144, 248);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
	conj_A = new ConjuntoL();
	if (conj_A) {
		ShowMessage("Conjunto creado");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
	conj_B = new ConjuntoL();
	if (conj_B) {
		ShowMessage("Conjunto creado");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
	conj_C = new ConjuntoL();
	if (conj_C) {
		ShowMessage("Conjunto creado");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
	String conj = InputBox("¿A que conjunto? A, B, C", "Conjunto: ", "");
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
				ShowMessage("Conjunto no válido. Por favor, elija A, B o C.");
				break;
		}
	} else
		ShowMessage("Entrada no válida. Por favor, ingrese un solo carácter (A, B o C).");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
	conj_C = new ConjuntoL();
	conj_A->unir(conj_B, conj_C);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
	conj_C = new ConjuntoL();
	conj_A->interseccion(conj_B, conj_C);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button15Click(TObject *Sender)
{
	String conj = InputBox("¿A que conjunto? A, B, C", "Conjunto: ", "");
	if (conj.Length() == 1) {
		switch (conj[1]) {
			case 'A': {
				if (conj_A) {
					conj_A->mostrar(Form1->Canvas, "A = ", 144, 279);
				} else
					ShowMessage("Primero crear el conjunto A");
				break;
			}
			case 'B': {
				if (conj_B) {
					conj_B->mostrar(Form1->Canvas, "B = ", 144, 310);
				} else
					ShowMessage("Primero crear el conjunto B");
				break;
			}
			case 'C': {
				if (conj_C) {
					conj_C->mostrar(Form1->Canvas, "C = ", 144, 341);
				} else
					ShowMessage("Primero crear el conjunto C");
				break;
			}
			default:
				ShowMessage("Conjunto no válido. Por favor, elija A, B o C.");
				break;
		}
	} else
		ShowMessage("Entrada no válida. Por favor, ingrese un solo carácter (A, B o C).");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button17Click(TObject *Sender)
{
	x = new Matriz_dispersa1();
	if (x) {
		ShowMessage("Matriz dispersa creada");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button18Click(TObject *Sender)
{
	if (!x)
		ShowMessage("Crear la matriz dispersa");
	else {
		int f = StrToInt(Edit6->Text);
		int c = StrToInt(Edit7->Text);
		x->dimencionar(f, c);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button19Click(TObject *Sender)
{
    if (!x)
		ShowMessage("Crear la matriz dispersa");
	else {
		int valor = StrToInt(Edit8->Text);
		x->definir_valor_repetido(valor);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button20Click(TObject *Sender)
{
   if (!x)
		ShowMessage("Crear la matriz dispersa");
	else {
		int f = StrToInt(Edit9->Text);
		int c = StrToInt(Edit10->Text);
		int dato = StrToInt(Edit11->Text);
		x->poner_dato(f, c, dato);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button21Click(TObject *Sender)
{
    if (!x)
		ShowMessage("Crear la matriz dispersa");
	else {
        x->dibujar_matriz(Form1->Canvas, 512, 124, 25, 25);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button22Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

