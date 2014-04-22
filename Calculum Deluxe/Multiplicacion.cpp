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

#include "Multiplicacion.h"


//------------------------------------------------
Multiplicacion::Multiplicacion(int max,int min):Operacion_Aritmetica(){
    Max_Rango=max;
    Min_Rango=min;

};
//------------------------------------------------
Multiplicacion::~Multiplicacion(){
};
//------------------------------------------------
AnsiString Multiplicacion::toString(){
        return " Multiplicaciòn ";
}
//------------------------------------------------
int Multiplicacion::eval(int primero,int segundo){
        if (((primero*segundo)>this->Max_Rango) || ((primero*segundo)<this->Min_Rango))  /* cheque validez de la operacion*/
                return this->Max_Rango+1;          /* si es invalida retorna un valor mas alla del rango*/
        else
                return primero*segundo;
};

//---------------------------------------------------------------------------

#pragma package(smart_init)
