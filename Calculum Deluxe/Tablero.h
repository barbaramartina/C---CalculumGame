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

#ifndef TableroH
#define TableroH


#include <ExtCtrls.hpp>
#include <Graphics.hpp>

#include "Matriz.h"
#include "Posicion.h"
#include "Lista.cpp"
#include "Ficha.h"
#include "image_fichas.h"
#include "Operacion_Aritmetica.h"


#define DER 0
#define IZQ 1
#define ARR 2
#define ABA 3
#define DIR 4

#define ANCHOFICHA 20
#define ANCHO 16
#define LARGO 16

#define POSMEDIO1 7
#define POSMEDIO2 8
#define VALORSIMPLE 1
#define VALORDOBLE 2
#define VALORTRIPLE 3
#define COMIENZOXTRIPLE 6
#define FINXTRIPLE 10
#define YTRIPLE1 3
#define YTRIPLE2 12


#define SIMPLE 1
#define DOBLE 4
#define TRIPLE 5
#define ERROR 0
#define MAX 99
#define MIN 1
#define EXITO 10


class Tablero{
        private:
                Matriz<Casilla> *matriz;
                Lista<Operacion_Aritmetica> *operaciones;
                void inicmatriz(Matriz<Casilla> *);


        public:
                Tablero(Lista<Operacion_Aritmetica> *);
                Tablero();
                ~Tablero();
                int hacerJugada(Ficha *,Posicion *,Jugada *&);
                        /* Coloca la ficha en la posicion dada
                           siempre y cuando la jugada sea correcta
                        */
                void deshacerJugada(Posicion *);
                        /* Saca de la posicion indicada la ficha que habia
                           sido colocada
                        */
                Lista<Posicion> *getPosicionesLibres();
                        /* Recorre las casillas de la matriz analizando cual
                           de ellas esta libre y representa una posibilidad
                           de realizar una jugada
                        */
                Lista<Posicion> *getPosicionesAdyacentes(Posicion *,int);
                        /* retorna una lista de uno o dos elementos con los
                           adyacentes de la posicion dada, en la direccion indicada
                        */
                 bool jugadaValida(Ficha *f,Posicion *,Jugada *&);
                        /* Analiza si es factible colocar esa ficha en la posicion dada
                           viendo para ello si existe alguna operacion Aritmetica
                        */
                void clonar(Tablero *);
                        /* realiza una copia del tablero pasado como parametro */
                int getValorFicha(Posicion *);
                        /* retorna el valor de la ficha que ocupa la posicion pasada
                           como parametro
                        */
                Casilla * getCasilla(Posicion *);
                bool masMovimientos(Lista<Ficha> *);
                        /* retorna true en caso de que, segun el estado del tablero
                           actual, halla alguna posible jugada para realizar con la
                           lista de fichas que le es dado como parametro
                        */
                void mostrar(TImage *,int,int,image_fichas *);
                Lista<Operacion_Aritmetica> *getOperaciones();
                        /* retorna una lista con las operaciones aritmeticas que
                           son parte del tablero
                        */
              


};
//---------------------------------------------------------------------------
#endif
