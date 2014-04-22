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

#include "Division.h"


//------------------------------------------------
Division::Division(int max,int min):Operacion_Aritmetica(){
    Max_Rango=max;
    Min_Rango=min;

};
//------------------------------------------------
Division::~Division(){
};
//------------------------------------------------
AnsiString Division::toString(){
        return " Divisiòn ";
}
//------------------------------------------------
int Division::eval(int primero,int segundo){
    if (segundo!=0){
        if ((primero%segundo)==0)
                return primero/segundo;
        else
                return this->Max_Rango+1;
                        /* Si la division no es entera
                           la Operacion no se permite.
                           Se retorna un numero Invalido
                        */
    };

    return 0;
};

//---------------------------------------------------------------------------

#pragma package(smart_init)
