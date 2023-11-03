﻿//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Pacman.h"
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
int xc,yc;TColor colorFondo;
void dibujar_pacman(int &mov,int &up,int &down)
{
	//int xc = Form1->Width/2,yc= Form1->Height/2;
	// Bloquear el lienzo para cambios seguros.
	Form1->Canvas->Lock();
	//TColor colorFondo = TColor(RGB(32, 33, 39));
	// Dibujar el cuerpo amarillo de Pac-Man (un c�rculo).
	Form1->Canvas->Pen->Color = colorFondo;
	Form1->Canvas->Brush->Color = clYellow;
	Form1->Canvas->Ellipse(0+mov, yc-100, 200+mov, yc+100);

	// Dibujar una seccion de Pac-Man (un triangulo) como una boca abierta.

	Form1->Canvas->Pen->Color = colorFondo;
	Form1->Canvas->Brush->Color = colorFondo;
	//Generamos los vertices para formar un triangulo que cortara la elipta
	//y formar la boca del pacman
	TPoint points[3];
	points[0] = TPoint(200+mov, yc-100+up);
	points[1] = TPoint(200+mov, yc+100+down);
	points[2] = TPoint(60+mov, yc);
	Form1->Canvas->Polygon(points, 2);

	// Desbloquear el lienzo para permitir futuros cambios.
	Form1->Canvas->Unlock();
}
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift, int X, int Y)
{
	Label1->Caption = "X: "+IntToStr(X)+" Y: "+IntToStr(Y);
}
//---------------------------------------------------------------------------
int movement = 0,movUp = 0,movDown = 0,cont = 0;bool estado = true;
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    // Limpia el area anterior de Pac-Man.
	Form1->Canvas->Brush->Color = colorFondo;  // Establece el color de fondo.
    //Se anade un cuadrado que cubre el fondo del pacman para tapar el rastro
	Form1->Canvas->FillRect(Rect(0, yc - 100, Form1->Width, yc + 100));

	//se establece el incremento en el movimiento del pac man
	if(movement + 200 <= Form1->Width+200)
		movement+=7;
	else
		movement = -200;
	//haciendo uso de la bandera "estado" se verifica cuando la boca del pac man
	//debe abrirse y cerrarse
	if(estado){
		movUp+=10;
		movDown-=10;
	}
	else{
		movUp-=10;
		movDown+=10;
	}
	if(movUp + yc-100 == yc-100)
		estado = true;
	if(movUp + yc-100 == yc)
		estado = false;
	Form1->Canvas->Refresh();
	dibujar_pacman(movement, movUp, movDown);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	xc = Form1->Width/2;yc= Form1->Height/2;
	colorFondo = TColor(RGB(32, 33, 39));
}
//---------------------------------------------------------------------------

