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

#include "Jugador.h"

//----------------------------------------------
Jugador::Jugador(int num,int max,int min){
  numero=num;
  fondoHabilitado=new Graphics::TBitmap;
  AnsiString aux=IntToStr(numero)+".bmp";
  fondoHabilitado->LoadFromFile("images\\Fichas\\ficha_3.bmp");
  cara=new Graphics::TBitmap;
  cara->LoadFromFile("images\\players\\player_"+aux);
  fichas_totales=new Lista<Ficha>;
  fichas_jugadas=new Lista<Ficha>;
  jugadas=new Lista<Jugada>;
  score=0;
  max_Rango=max;
  min_Rango=min;

};
//----------------------------------------------
Jugador::~Jugador(){
  delete(fichas_totales);
  delete(fichas_jugadas);
};
//----------------------------------------------
void Jugador::actualizarFichas(){
  fichas_totales->vaciar();
  for (int j=0; j<MAXFICHAS; j++)
    fichas_totales->agregar(new Ficha(random(max_Rango)+1));

  fichas_jugadas->vaciar();
};
//----------------------------------------------
void Jugador::actualizarFichasJugadas(Ficha *f){
    fichas_jugadas->agregar(f);
    fichas_totales->eliminar(f);
};
//----------------------------------------------
Ficha *Jugador::getFicha(int pos){
  if (pos<=fichas_totales->tamanio())
        return fichas_totales->get(pos);
  else
        return NULL;
};
//----------------------------------------------
Lista<Ficha> *Jugador::getFichasValidas(){
  return fichas_totales;
};
//----------------------------------------------
void Jugador::vaciarJugadas(){
  jugadas->vaciar();
};
//----------------------------------------------
void Jugador::mostrar(TImage *im,int x,int y,int dir,image_fichas *resource){
  im->Picture->Bitmap->Canvas->Draw(x,y,cara);
  switch (numero)
  {
     case 0: mostrarFichas(im,x+ANCHOCARA+DESPLAZAR,y,dir,resource);
     break;
     case 1: mostrarFichas(im,x+ANCHOCARA,y+LARGOCARA+DESPLAZAR,dir,resource);
     break;
     case 2: mostrarFichas(im,x-DESPLAZAR-(MAXFICHAS*ANCHOFICHA),y+LARGOCARA,dir,resource);
     break;
     case 3: mostrarFichas(im,x-ANCHOFICHA,y-DESPLAZAR-(MAXFICHAS*ANCHOFICHA),dir,resource);
     break;
  }


};
//----------------------------------------------
void Jugador::mostrarFichas(TImage *im,int x,int y,int dir,image_fichas *resource){
    int auxY=y;
    int auxX=x;
    Ficha *auxF;

    switch (dir)
    {
         case COSTADO: for (auxF=fichas_totales->primero();auxF!=NULL; auxF=fichas_totales->siguiente()){
                         im->Picture->Bitmap->Canvas->Draw(auxX,y,fondoHabilitado);
                         auxF->mostrar(im,auxX,y,resource);
                          auxX+=ANCHOFICHA;
                       };
          break;
         case ABAJO:   for (auxF=fichas_totales->primero();auxF!=NULL; auxF=fichas_totales->siguiente()){
                         im->Picture->Bitmap->Canvas->Draw(x,auxY,fondoHabilitado);
                         auxF->mostrar(im,x,auxY,resource);
                         auxY+=LARGOFICHA;
                       };
         break;
    };




};
//----------------------------------------------
bool Jugador::fichaJugada(Ficha *f){
     return fichas_jugadas->pertenece(f);
};
//----------------------------------------------
Lista<Jugada> *Jugador::getJugadas(){
        return jugadas;
}
//----------------------------------------------
int Jugador::getScore(){
        return score;
};
//----------------------------------------------
int Jugador::hacerJugada(Ficha *ficha,Posicion *posi,Tablero *t){
     //si la ficha no ha sido jugada
     if (fichas_totales->pertenece(ficha)){
          Jugada *j=NULL;
         int aux=t->hacerJugada(ficha,posi,j);
         // si la jugada fue exitosa
         if (aux!=ERRORJUGADA){
               actualizarFichasJugadas(ficha);
               score+=t->getValorFicha(posi);
               jugadas->agregar(j);
               return aux;
         }
         else
                //arroja el error
                return ERRORJUGADA;
     }
     else
        return ERRORJUGADA;
};
//----------------------------------------------
void Jugador::deshacerJugada(Tablero *t){
  if (jugadas->tamanio()!=0){
     fichas_totales->agregar(jugadas->primero()->getFicha());
     fichas_jugadas->eliminar(jugadas->primero()->getFicha());
     score-=t->getValorFicha(jugadas->primero()->getPosicion());
     t->deshacerJugada(jugadas->primero()->getPosicion());
     jugadas->eliminar(jugadas->primero());
  };
};
//---------------------------------------------------------------------------

#pragma package(smart_init)
