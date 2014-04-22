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
#include "image_fichas.h"

//-------------------------------------------------
image_fichas::image_fichas(int max,int min){
       max_Rango=max;
       min_Rango=min;
       images=new Graphics::TBitmap **[2];
       int i;
       AnsiString ruta;
       images[0]=new Graphics::TBitmap *[max_Rango];
       for (i=0 ;i<max_Rango; i++){
          ruta=IntToStr(i+1)+".bmp";
          images[0][i]=new Graphics::TBitmap();
          images[0][i]->LoadFromFile("images\\Fichas\\ficha"+ruta);
          images[0][i]->Transparent=true;
          images[0][i]->TransparentColor=images[0][i]->Canvas->Pixels[0][0];


       };
       images[1]=new Graphics::TBitmap *[TIPOS];
       for (i=0; i<TIPOS; i++){
          ruta=IntToStr(i)+".bmp";
          images[1][i]=new Graphics::TBitmap();
          images[1][i]->LoadFromFile("images\\Fichas\\ficha_"+ruta);
          
       };


};

//-------------------------------------------------
image_fichas::~image_fichas(){
        int i;
        for (i=0; i<max_Rango-1; i++)
          delete(images[0][i]);
        for (i=1; i<(-min_Rango); i++)
          delete(images[1][i]);



        delete(images[0]);
        delete(images[1]);
  




};
//-------------------------------------------------
Graphics::TBitmap  *image_fichas::getImage(int numero){

       if ((numero<max_Rango+1) && (numero>min_Rango-1))
         return images[0][numero-1];

        return NULL;

};
//-------------------------------------------------
Graphics::TBitmap  *image_fichas::getFondo(AnsiString nombre){
      if (nombre=="fondo")
        return images[1][FONDO_COMUN];
      else{
           if (nombre=="plus_1")
                return images[1][FONDO_PLUS_1];
           else
                if (nombre=="plus_2")
                    return images[1][FONDO_PLUS_2];
                else
                    return NULL;
        };
};
//---------------------------------------------------------------------------

#pragma package(smart_init)
