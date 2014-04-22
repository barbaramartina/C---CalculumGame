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

#include "Casilla.h"
//----------------------------------
Casilla::Casilla(){
   fondo=NULL;
   ficha=NULL;
   factor=0;
};
//----------------------------------
Casilla::Casilla(AnsiString f,int fac){
   fondo=f;
   ficha=NULL;
   factor=fac;
};
//----------------------------------
Casilla::~Casilla(){
   delete(ficha);
};
//----------------------------------
void Casilla::setFactor(int f){
        factor=f;
};
//----------------------------------
void Casilla::setFondo(AnsiString f){
        fondo=f;
};
//----------------------------------
int Casilla ::getFactor(){
  return factor;
};
//----------------------------------
void Casilla::setFicha(Ficha *f){
   ficha=f;
};
//----------------------------------
Ficha * Casilla::getFicha(){
   return ficha;
};
//----------------------------------
void Casilla::delFicha(){
   ficha=NULL;
};
//----------------------------------
void Casilla::mostrar(TImage *imag,int x,int y,image_fichas *resource){
     imag->Picture->Bitmap->Canvas->Draw(x,y,resource->getFondo(fondo));
     if (ficha!=NULL)
       ficha->mostrar(imag,x,y,resource);
};
//---------------------------------------------------------------------------

#pragma package(smart_init)
