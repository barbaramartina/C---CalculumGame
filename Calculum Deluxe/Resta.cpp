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

#include "Resta.h"


//------------------------------------------------
Resta::Resta(int max,int min):Operacion_Aritmetica(){
    Max_Rango=max;
    Min_Rango=min;

};
//------------------------------------------------
Resta::~Resta(){
};
//------------------------------------------------
AnsiString Resta::toString(){
        return " Resta ";
}
//------------------------------------------------
int Resta::eval(int primero,int segundo){
      if (primero-segundo>=Min_Rango)
        return primero-segundo;
      else
        return Max_Rango+1;
};
//---------------------------------------------------------------------------

#pragma package(smart_init)