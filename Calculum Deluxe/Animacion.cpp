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

#include "Animacion.h"
//-----------------------------------------
Animacion::Animacion(int cantI,int x,int y,Graphics::TBitmap **imag){
        cantImagenes=cantI;
        posX= x;
        posY= y;
        imagenes=imag;
        nroImagen=0;
        animarAhora=false;

};
//-----------------------------------------
Animacion::~Animacion(){
       delete(imagenes);
};
//-----------------------------------------
void Animacion::proxImagen(){
        if (nroImagen< cantImagenes-1)
                nroImagen++;
        else
        nroImagen=0;

};
//-----------------------------------------
void Animacion::animar(TImage *fondo){
        if (animarAhora){
                fondo->Picture->Bitmap->Canvas->Draw(posX,posY,imagenes[nroImagen]);
                proxImagen();
        }
};
//-----------------------------------------
void Animacion::setAnimar(){
        animarAhora= true;
};
//-----------------------------------------
void Animacion::desanimar(){
        animarAhora= false;
};
//-----------------------------------------



#pragma package(smart_init)
