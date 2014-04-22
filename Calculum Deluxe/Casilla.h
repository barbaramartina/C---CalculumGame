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

#ifndef CasillaH
#define CasillaH

#include <System.hpp>
#include <ExtCtrls.hpp>

#include "Ficha.h"
#include "image_fichas.h"


class Casilla{
        private:
                AnsiString fondo;
                Ficha *ficha;
                int factor;
        public:
                Casilla();
                Casilla(AnsiString,int);
                ~Casilla();
                void setFicha(Ficha *);
                        /* coloca una ficha en la casilla */
                Ficha * getFicha();
                void delFicha();
                void setFactor(int);
                        /* setea el factor por el cual se multiplica el valor de la ficha */
                int getFactor();
                void setFondo(AnsiString );
                        /* setea el tipo de fondo que tendra la casilla */
                void mostrar(TImage *,int,int,image_fichas *);
                Casilla *operator=(Casilla &c){
                  this->fondo=c.fondo;
                  this->factor=c.factor;
                  this->ficha=c.ficha;
                  return this;
                };

};
//---------------------------------------------------------------------------
#endif
