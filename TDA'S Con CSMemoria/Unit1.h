//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CSMemoria.h"
#include "Lista.h"
#include "PolinomioM.h"
#include "PolinomioL.h"
#include "ConjuntoM.h"
#include "ConjuntoL.h"
#include "Matriz_dispersa.h"
#include "Pilas.h"
#include "PilasL.h"
#include <Vcl.ComCtrls.hpp>
#include "Cola.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	TButton *Button11;
	TButton *Button12;
	TButton *Button13;
	TButton *Button14;
	TButton *Button15;
	TButton *Button16;
	TButton *Button17;
	TButton *Button18;
	TButton *Button19;
	TButton *Button20;
	TButton *Button21;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TEdit *Edit8;
	TEdit *Edit9;
	TEdit *Edit10;
	TEdit *Edit11;
	TButton *Button22;
	TEdit *Edit12;
	TButton *Button23;
	TButton *Button24;
	TButton *Button25;
	TButton *Button26;
	TButton *Button27;
	TEdit *Edit13;
	TEdit *Edit14;
	TEdit *Edit15;
	TEdit *Edit16;
	TButton *Button28;
	TEdit *Edit17;
	TEdit *Edit18;
	TButton *Button29;
	TButton *Button30;
	TButton *Button31;
	TButton *Button32;
	TButton *Button33;
	TButton *Button34;
	TEdit *Edit19;
	TEdit *Edit20;
	TEdit *Edit21;
	TEdit *Edit22;
	TButton *Button35;
	TButton *Button36;
	TButton *Button37;
	TButton *Button38;
	TEdit *Edit23;
	TEdit *Edit24;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Button13Click(TObject *Sender);
	void __fastcall Button14Click(TObject *Sender);
	void __fastcall Button22Click(TObject *Sender);
	void __fastcall Button23Click(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall Button15Click(TObject *Sender);
	void __fastcall Button16Click(TObject *Sender);
	void __fastcall Button17Click(TObject *Sender);
	void __fastcall Button18Click(TObject *Sender);
	void __fastcall Button19Click(TObject *Sender);
	void __fastcall Button20Click(TObject *Sender);
	void __fastcall Button21Click(TObject *Sender);
	void __fastcall Button24Click(TObject *Sender);
	void __fastcall Button28Click(TObject *Sender);
	void __fastcall Button25Click(TObject *Sender);
	void __fastcall Button26Click(TObject *Sender);
	void __fastcall Button27Click(TObject *Sender);
	void __fastcall Button29Click(TObject *Sender);
	void __fastcall Button30Click(TObject *Sender);
	void __fastcall Button31Click(TObject *Sender);
	void __fastcall Button32Click(TObject *Sender);
	void __fastcall Button33Click(TObject *Sender);
	void __fastcall Button34Click(TObject *Sender);
	void __fastcall Button35Click(TObject *Sender);
	void __fastcall Button36Click(TObject *Sender);
	void __fastcall Button37Click(TObject *Sender);
	void __fastcall Button38Click(TObject *Sender);

private:	// User declarations
	CSMemoria *mem;
	Lista *list;
	PolinomioM *pol, *pol1, *pol2;
	//PolinomioL* pol, *pol1, *pol2;
	//ConjuntoM *conj_A, *conj_B, *conj_C;
	ConjuntoL *conj_A, *conj_B, *conj_C;
	Matriz_dispersa *x;
	Pilas* pila;
	//PilasL* pila;
    Cola* cola;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
