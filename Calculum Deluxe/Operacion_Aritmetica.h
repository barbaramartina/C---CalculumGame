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

#ifndef Operacion_AritmeticaH
#define Operacion_AritmeticaH

#include <System.hpp>



class Operacion_Aritmetica{
        protected:
                int Max_Rango;
                        /* Valor maximo al que pueden llegar los resultados */
                int Min_Rango;
                        /* Valor minimo al que pueden llegar los resultados */

        public:
                Operacion_Aritmetica(){};
                Operacion_Aritmetica(int,int){};
                virtual int  eval(int,int)=0;
                        /* Retorna el resultado de aplicar la operacion a dos valores */
                virtual AnsiString toString()=0;
                bool equal(Operacion_Aritmetica &op){
                        return this->Max_Rango==op.Max_Rango &&
                        this->Min_Rango==op.Min_Rango ;
                        };
                        /* retorna true si las dos operaciones son iguales*/


      
                
};
//---------------------------------------------------------------------------
#endif
