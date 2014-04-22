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

#ifndef MatrizH
#define MatrizH
#include "Casilla.h"

//---------------------------------------------------------------------------
template <class T> class Matriz{
   private:
           T ***matriz;
           int tamX,tamY;
   public:
           Matriz(int,int);
          ~Matriz();
           int getSizeX();
           int getSizeY();
           T *get(int,int);
           void del(int,int);
                /* borra el elemento ubicado en la posicion indicada
                   chequeando que la posicion sea valida
                   y este ocupada.
                */
           void set(T*,int,int);
                /* ubica en la posicion indicada el elemento dado
                   chequeando que la posicion sea valida
                   y la misma no este ocupada.
                */
           bool posValida(int,int);
           bool posOcupada(int,int);
           void clonar(Matriz<T> *origen);
                /* Clona la matriz origen en la matriz actual
                   copiando sus elementos.
                */
};
//---------------------------------------------------------------------------
#endif

