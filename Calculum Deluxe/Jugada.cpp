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

#include "Jugada.h"

//---------------------------------------------
Jugada::Jugada(){
        f1=NULL;
        f2=NULL;
        f3=NULL;
        operacion=NULL ;
        pos=NULL ;
};
//---------------------------------------------
Jugada::Jugada(Ficha *f,Ficha *f2,Ficha *f3,Operacion_Aritmetica *oper,Posicion *p){
        this->f1=f;
        this->f2=f2;
        this->f3=f3;
        operacion=oper;
        pos=p ;
};
//---------------------------------------------
Jugada::~Jugada(){
        delete(f1);
        delete(f2);
        delete(f3);
        delete(operacion);
        delete(pos);
};
//---------------------------------------------
Ficha *Jugada::getFicha(){
        return f1;
};
//---------------------------------------------
AnsiString Jugada::toString(){
       return operacion->toString()+" ( "+IntToStr(f2->getValor())+" , "+IntToStr(f3->getValor())+" )  = "+IntToStr(f1->getValor());
}
//---------------------------------------------
Posicion *Jugada::getPosicion(){
        return pos;
};
//---------------------------------------------
bool Jugada::equal(Jugada &j){
 return ((this->f1==j.f1) &&
         (this->pos==j.pos));
};
//---------------------------------------------------------------------------

#pragma package(smart_init)
