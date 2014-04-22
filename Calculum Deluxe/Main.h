//---------------------------------------------------------------------------
//
//  Licensed to the Apache Software Foundation (ASF) under one
//  or more contributor license agreements.  See the NOTICE file
//  distributed with this work for additional information
//  regarding copyright ownership.  The ASF licenses this file
//  to you under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance
//  with the License.  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing,
//  software distributed under the License is distributed on an
//  "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
//  KIND, either express or implied.  See the License for the
//  specific language governing permissions and limitations
//  under the License.
//

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------

#include <System.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <System.hpp>
#include <Graphics.hpp>

#include "Suma.h"
#include "Resta.h"
#include "Division.h"
#include "Multiplicacion.h"
#include "Jugadas.h"

#include "image_fichas.h"
#include "Ficha.h"
#include "Sonidos.h"
#include "JugadorPC.h"
#include "Jugador.h"
#include "Tablero.h"
#include "Lista.cpp"
#include "GameCalculum.h"
#include "Opciones.h"



#define ERRORJUGADA 0

#define POSRECOMENZARX 373
#define POSMUSICX 437
#define POSCOMPROBARX 303
#define POSDESHACERX 233
#define POSPASARX 165
#define SIMBOLOY 564

#define ANCHOCARA 62
#define LARGOCARA 77
#define DESPLAZAR 50


#define ERRORJUGADA 0
#define EXITO 1

#define POSFICHASJUGADORX1 166
#define POSFICHASJUGADORY1 14
#define POSFICHASJUGADORX2 493
#define POSFICHASJUGADORY2 103
#define POSFICHASJUGADORX3 416
#define POSFICHASJUGADORY3 424
#define POSFICHASJUGADORX4 89
#define POSFICHASJUGADORY4 337

#define COMIENZOMATRIZX  161
#define COMIENZOMATRIZY  97
#define ANCHOMATRIZ 16
#define LARGOMATRIZ 16

#define  PASAR 0
#define  DESHACER 1
#define  COMPROBAR 2
#define  NUEVO 3
#define  DESHABILITAR 4
#define  HABILITAR 5


#define ANCHOSIMBOLOS 44
#define LARGOSIMBOLOS 25

#define MAX 99
#define MIN 1









//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TTimer *TimerAnimar;
        TEdit *score1;
        TEdit *score2;
        TEdit *score3;
        TEdit *score4;
        TTimer *TimerFestejar;
        TTimer *TimerComprobar;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall TimerAnimarTimer(TObject *Sender);
        void __fastcall Image1Click(TObject *Sender);
        void __fastcall TimerFestejarTimer(TObject *Sender);
        void __fastcall TimerComprobarTimer(TObject *Sender);
        void __fastcall mostrarJugadasClick(TObject *Sender);


private:	// User declarations
        GameCalculum *game;
        Sonidos *sounds;
        image_fichas *imagenes;
        int cantJugadores;
        bool music;
        int posX;
        int posY;
        int numeroFicha;
      

public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        void __fastcall comenzar(int);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
