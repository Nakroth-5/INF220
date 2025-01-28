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
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    lista = new Lista();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	if (!lista)
		ShowMessage("Crear lista primero");
	else {
		int dato = StrToInt(Edit1->Text);
		lista->inserta(lista->primero(), dato);
		//list->inserta_primero(dato);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	if (!lista)
		ShowMessage("Crear lista primero");
	else {
		int dato = StrToInt(Edit2->Text);
		lista->inserta(lista->fin(), dato);
		//list->inserta_primero(dato);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	if (!lista)
		ShowMessage("Crear lista primero");
	else {
        lista->mostrar(Form1->Canvas, 182, 133);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
    if (!lista)
		ShowMessage("Crear lista primero");
	else {
		//int dato = StrToInt(Edit3->Text);
		//lista->elimina_dato(dato);
        lista->anule();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
	pol = new Polinomio();
	pol1 = new Polinomio();
	pol2 = new Polinomio();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
	if (!pol)
		ShowMessage("Crear polinomio primero");
	else {
		int coef = StrToInt(Edit4->Text);
		int exp = StrToInt(Edit5->Text);
		pol->poner_termino(coef, exp);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
    if (!pol)
		ShowMessage("Crear polinomio primero");
	else
		pol->mostrar(Form1->Canvas, 182, 257);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
