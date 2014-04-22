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

#ifndef JugadorPCH
#define JugadorPCH

#include <Values.h>

#include "Jugador.h"


#define MAXFICHAS 7
#define ANCHOFICHA 20
#define ERRORJUGADA 0
#define EXITO 1






class JugadorPC:public Jugador{
        private:
                void back(int *,int *,Lista<Jugada> *,Lista<Jugada> *,Lista<Ficha> *,Tablero *);
        public:
                JugadorPC(int,int,int);
                ~JugadorPC();
                int hacerJugadaPC(Tablero *);
                        /* Realiza las jugadas resultantes del backtracking
                           y luego las plasma sobre el tablero
                        */


};
//---------------------------------------------------------------------------
#endif
