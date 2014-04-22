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


#pragma hdrstop

#include "JugadorPC.h"
//-------------------------------------------------
JugadorPC::JugadorPC(int num,int max,int min):Jugador(num,max,min){

};
//-------------------------------------------------
JugadorPC::~JugadorPC(){
};
//-------------------------------------------------
int JugadorPC::hacerJugadaPC(Tablero *t){
    int maxP=-MAXINT;
    int actual=0;

    //tablero usado durante el backtracking
    Tablero *aux_tablero=new Tablero();
    aux_tablero->clonar(t);

    Lista<Jugada> *auxiliar=new Lista<Jugada>;
    Lista<Jugada> *finales=new Lista<Jugada>;


    back(&maxP,&actual,auxiliar,finales,fichas_totales,aux_tablero);


    //plasma las jugadas sobre el tablero del juego
    int aux_int;
    for (Jugada *aux_Jugada=finales->primero(); aux_Jugada!=NULL; aux_Jugada=finales->siguiente())
      aux_int=this->hacerJugada(aux_Jugada->getFicha(),aux_Jugada->getPosicion(),t);





};
//----------------------------------------------------
void JugadorPC::back(int *maxPtos,int *actualPtos,Lista<Jugada> *jugadas,Lista<Jugada> *final,Lista<Ficha> *fichas,Tablero *tablero_aux)  {
        Ficha *ficha_aux;
        Posicion *p_aux;

        //obtiene las posiciones en las que es posible hacer una jugada
        Lista<Posicion> *posicionesPosibles=tablero_aux->getPosicionesLibres();


        //recorre cada una de las fichas del jugador PC
        for (int tamanio=fichas->tamanio() ; tamanio>0 ; tamanio--){
            ficha_aux=fichas->get(tamanio-1);
            //elimina de a una ficha
            fichas->eliminar(ficha_aux);
            p_aux=posicionesPosibles->primero();

            //ciclando sobre todas las posiciones de jugada posible
            while (p_aux!=NULL){
             Jugada *j=NULL;
             //analiza si la jugada con la ficha actual es valida en el tablero
             if (tablero_aux->hacerJugada(ficha_aux,p_aux,j)!=ERRORJUGADA){
                //agrega la jugada a las jugadas parciales
                jugadas->agregar(j);
                //actualiza puntaje del jugador
                *actualPtos+=ficha_aux->getValor();

                back(maxPtos,actualPtos,jugadas,final,fichas,tablero_aux);

                //se va quedando con las jugadas que le dan mas puntaje
                if (*actualPtos>*maxPtos){
                  *maxPtos=*actualPtos;
                  final->clonar(jugadas);
                };

                jugadas->eliminar(j);
                *actualPtos-=ficha_aux->getValor();
                tablero_aux->deshacerJugada(p_aux);
              };
              p_aux=posicionesPosibles->siguiente();
            };

            fichas->agregar(ficha_aux);
        };

};
//---------------------------------------------------------------------------

#pragma package(smart_init)

