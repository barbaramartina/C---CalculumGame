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

#ifndef FichaH
#define FichaH

#define INVALIDO 1000

#include <Graphics.hpp>
#include <ExtCtrls.hpp>
#include <system.hpp>

#include "image_fichas.h"


class Ficha{
        private:
                int valor;
        public:
                Ficha();
                Ficha(int);
                ~Ficha();
                void setValor(int);
                int getValor();
                void mostrar(TImage *,int,int,image_fichas *);
                        /* metodo por el cual una ficha muestra su fondo
                           y su valor si es que lo tiene , en el Image dado
                        */
                bool equal(Ficha &f);
                        /* retorna true si las dos fichas son iguales*/
                Ficha * operator =(Ficha &f){
                        this->valor=f.valor;
                        return this;

                };





                



} ;
//---------------------------------------------------------------------------
#endif
