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

#ifndef GameCalculumH
#define GameCalculumH



#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <System.hpp>





#include "Jugador.h"
#include "JugadorPC.h"

#include "Lista.cpp"
#include "Tablero.h"

#include "Suma.h"
#include "Resta.h"
#include "Division.h"
#include "Multiplicacion.h"

#include "image_fichas.h"

#include "Ficha.h"
#include "Sonidos.h"
#include "Animacion.h"




#define MAXFICHAS 7
#define ANCHOFICHA 20
#define LARGOFICHA 20

#define COSTADO 1
#define LARGO 0

#define ERRORJUGADA 0
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





#define ANCHOSIMBOLOS 44
#define LARGOSIMBOLOS 25



#define POSRECOMENZARX 375
#define POSMUSICX 438
#define POSCOMPROBARX 310
#define POSDESHACERX 236
#define POSPASARX 169
#define SIMBOLOY 533

#define ANCHOCARA 62
#define LARGOCARA 77
#define DESPLAZAR 50

#define ANCHOTURNO  25
#define SOUNDSIMPLE  1
#define SOUNDDOBLE  2
#define SOUNDTRIPLE 3
#define SOUNDERROR  4
#define SOUNDTURNO  5





class GameCalculum{
        private:

           int cantJugadores;
           int turno;
           Jugador **jugadores;
           JugadorPC *jPC;
           Tablero *tablero;
           Posicion *getPosicionMatriz(int,int);
           Lista<Operacion_Aritmetica> *operaciones;
           int max_Rango;
           int min_Rango;
           Sonidos *sounds;
           TImage *dibujoTablero;

           Animacion *happy1,*happy2,*happy3,*happy4;
           Animacion *working1,*working2,*working3,*working4;

           bool bjugando,bExisten,bdeshacer,bcomprobar,bcomprobando,bpasar,bnuevo,bhabilitarM,bdeshabilitarM;

           int fichaSeleccionada;

           Graphics::TBitmap *fondoSeleccionada,*gturno,*gExisten,*gNoExisten,*deshacer,*comprobar,*pasar,*nuevo,*habilitar,*deshabilitar;

           Graphics::TBitmap **inicImagenes(int,AnsiString,AnsiString);

           Graphics::TBitmap *fondo;



        public:

            GameCalculum(TImage *,Sonidos *,int,int,int);
            ~GameCalculum();
            void pasarTurno();
            void comprobarJugadas();
            int jugar(int,int,int);
            int getNumeroFicha(int,int);
            void setJugando();
            void unSetJugando();
            void deshacerJugada();
            bool jugando();
            int getCantJugadores();
            JugadorPC *getJugadorPC();
            Tablero * getTablero();
            int getTurno();
            void mostrarScore(TEdit *,TEdit *,TEdit *,TEdit *);
            void setFichaSelecionada(int);
            void mostrar(image_fichas *,TEdit *,TEdit *,TEdit *,TEdit *);
            void animarWorker(TImage *);
            void desanimarWorker();
            void reAnimarWorker();
            void desanimarHappy();
            void reAnimarHappy();
            void animarHappy(TImage *);
            void mostrarDeshacer();
            void noMostrarDeshacer();
            void mostrarComprobando();
            void noMostrarComprobando();
            void mostrarNuevo();
            void noMostrarNuevo();
            void mostrarComprobar();
            void noMostrarComprobar();
            void mostrarHabilitar();
            void noMostrarHabilitar();
            void mostrarDeshabilitar();
            void noMostrarDeshabilitar();
            void mostrarPasar();
            void noMostrarPasar();








};

//---------------------------------------------------------------------------
#endif
