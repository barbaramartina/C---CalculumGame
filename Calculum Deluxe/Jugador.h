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

#ifndef JugadorH
#define JugadorH

#include <System.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>

#include "Lista.cpp"
#include "Ficha.h"
#include "Tablero.h"
#include "Jugada.h"
#include "Posicion.h"
#include "image_fichas.h"


#define MAXFICHAS 7
#define ANCHOFICHA 20
#define LARGOFICHA 20
#define ANCHOCARA 62
#define LARGOCARA 77
#define DESPLAZAR 50


#define ERRORJUGADA 0
#define SIMPLE 1
#define DOBLE 4
#define TRIPLE 5


#define COSTADO 1
#define ABAJO 0




class  Jugador{
        protected:
                Graphics::TBitmap *fondoHabilitado;
                Graphics::TBitmap *cara;
                int numero;
                Lista<Ficha> *fichas_totales;
                Lista<Ficha> *fichas_jugadas;
                Lista<Jugada> *jugadas;
                int score;
                int max_Rango;
                int min_Rango;
        public:
                Jugador(int,int,int);
                ~Jugador();
                void actualizarFichas();
                        /* Reasigna un conjunto de fichas al jugador
                           igual a la cantidad de fichas maxima.
                           Las fichas se regeneran en su totalidad
                        */
                void actualizarFichasJugadas(Ficha *);
                        /* coloca la ficha dada en las fichas ya jugadas
                           Sacandola de las fichas totales.
                        */
                void mostrarFichas(TImage *,int,int,int,image_fichas *);
                        /* Se encargara de mostrar las fichas del jugador
                           sobre el image dado.
                        */
                void mostrar(TImage *,int,int,int,image_fichas *);
                bool fichaJugada(Ficha *);
                        /* retorna true si la ficha ha sido jugada */
                int getScore();
                int hacerJugada(Ficha *,Posicion *,Tablero *);
                        /* realiza una jugada con la ficha dada en la posicion
                           y tablero correspondiente
                        */
                void deshacerJugada(Tablero *);
                void vaciarJugadas();
                        /* vacia las jugadas que actualmente posee el jugador */
                Ficha *getFicha(int);
                        /* retorna la ficha correspondiente al numero dado */
                Lista<Jugada> *getJugadas();
                Lista<Ficha> *getFichasValidas();
                        /* retorna las fichas que le quedan por jugar aun */









};
//---------------------------------------------------------------------------
#endif
