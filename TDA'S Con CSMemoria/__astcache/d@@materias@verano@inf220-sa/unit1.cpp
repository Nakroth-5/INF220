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

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	mem = new CSMemoria();
	if (mem)
		ShowMessage("Memoria creada");
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
		list = new ListaM(mem);
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
		//list->inserta(list->primero(), dato);
        list->inserta_primero(dato);
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
		pol->mostrar(Form1->Canvas, 168, 384);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
    if (!mem)
		ShowMessage("Crear memoria primero");
	else {
		pol = new PolinomioM(mem);
		if (pol)
			ShowMessage("Polinomio creado");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button22Click(TObject *Sender)
{                                      /*
	double x = StrToFloat(Edit12->Text);
	Edit12->Text =  pol->evaluar(x); */
	int coef = StrToInt(Edit10->Text);
	int exp = StrToInt(Edit11->Text);
	pol1->poner_termino(coef, exp);
	pol1->mostrar(Form1->Canvas, 500, 350);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button23Click(TObject *Sender)
{
	pol = new PolinomioM(mem);
	pol2->suma(pol, pol1);
	pol2->mostrar(Form1->Canvas, 500, 386);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
	pol2->derivar(pol);
	pol2->mostrar(Form1->Canvas, 500, 386);
}
//---------------------------------------------------------------------------

