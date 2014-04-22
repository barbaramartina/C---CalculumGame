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

#include "Ficha.h"

//-----------------------------------------
Ficha::Ficha(){
        valor=INVALIDO;
};
//-----------------------------------------
Ficha::Ficha(int val){
        valor=val;
};
//-----------------------------------------
Ficha::~Ficha(){
};
//-----------------------------------------
bool Ficha::equal(Ficha &f){
  return (this->valor==f.valor);
};
//-----------------------------------------
void Ficha::setValor(int numero){
        valor=numero;
};
//-----------------------------------------
int Ficha::getValor(){
        return valor;
};
//-----------------------------------------
void Ficha::mostrar(TImage *imagen,int x,int y,image_fichas *im){
             Graphics::TBitmap *aux=im->getImage(valor);
             imagen->Picture->Bitmap->Canvas->Draw(x,y,aux);
};
//---------------------------------------------------------------------------

#pragma package(smart_init)


