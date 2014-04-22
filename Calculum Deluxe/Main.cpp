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

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
     Image1->Picture->LoadFromFile("images\\fondos\\tablero.bmp");
     cantJugadores=-1;
     posX=0;
     posY=0;
     numeroFicha=-1;

};
//---------------------------------------------------------------------------
void __fastcall TForm1::comenzar(int c){
        cantJugadores=c;
        imagenes=new image_fichas(MAX,MIN);
        game=new GameCalculum(Image1,sounds,cantJugadores,MAX,MIN);
        TimerAnimar->Enabled=true;
};
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
     Form1->ClientHeight=600;
     Form1->ClientWidth=600;
     Form1->Left=241;
     Form1->Top=43;
     Form1->Enabled=false;
     Form2->Visible=true;
     sounds=new Sonidos();
     sounds->setMusica();
     music=true;

};
//---------------------------------------------------------------------------


void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
  posX=X;
  posY=Y;


  if (posX>=POSCOMPROBARX && posX<=POSCOMPROBARX+ANCHOSIMBOLOS && posY>=SIMBOLOY && posX<=SIMBOLOY+LARGOSIMBOLOS)
  {
     if (TimerComprobar->Enabled==false)
          game->mostrarComprobar();
   }
  else
          game->noMostrarComprobar();


  if (posX>=POSPASARX && posX<=POSPASARX+ANCHOSIMBOLOS && posY>=SIMBOLOY && posX<=SIMBOLOY+LARGOSIMBOLOS)
          game->mostrarPasar();
  else
          game->noMostrarPasar();


  if (posX>=POSDESHACERX && posX<=POSDESHACERX+ANCHOSIMBOLOS && posY>=SIMBOLOY && posX<=SIMBOLOY+LARGOSIMBOLOS)
          game->mostrarDeshacer();
  else
          game->noMostrarDeshacer();


  if (posX>=POSRECOMENZARX && posX<=POSRECOMENZARX+ANCHOSIMBOLOS && posY>=SIMBOLOY && posX<=SIMBOLOY+LARGOSIMBOLOS)
          game->mostrarNuevo();
  else
          game->noMostrarNuevo();


  if (posX>=POSMUSICX && posX<=POSMUSICX+ANCHOSIMBOLOS && posY>=SIMBOLOY && posX<=SIMBOLOY+LARGOSIMBOLOS){
      if (music)
        game->mostrarDeshabilitar();
      else
        game->mostrarHabilitar();
  }
  else{
        game->noMostrarDeshabilitar();
        game->noMostrarHabilitar();
  };

}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerAnimarTimer(TObject *Sender)
{
   game->mostrar(imagenes,score1,score2,score3,score4);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1Click(TObject *Sender)
{

  //si el click se hizo sobre una ficha de Jugador
  if (game->getNumeroFicha(posX,posY)!=-1){
         numeroFicha=game->getNumeroFicha(posX,posY);
         game->setFichaSelecionada(numeroFicha);
         //el juego esta en marcha
         game->setJugando();
   }
   else{
       //si el juego esta en marcha
       if (game->jugando()){
         //se ejecuta
         int aux=game->jugar(numeroFicha,posX,posY);
         //si la jugada fue un exito el jugador festeja
         if (aux!=ERRORJUGADA){
           game->desanimarWorker();
           game->reAnimarHappy();
           TimerFestejar->Enabled=true;
         };
         //el juego culmina por el momento
         game->setFichaSelecionada(-1);
         numeroFicha=-1;
         game->unSetJugando();
       };
   };

  if (posX>=POSCOMPROBARX && posX<=POSCOMPROBARX+ANCHOSIMBOLOS && posY>=SIMBOLOY && posX<=SIMBOLOY+LARGOSIMBOLOS)
  {
          game->noMostrarComprobar();
          game->comprobarJugadas();
          game->mostrarComprobando();
          TimerComprobar->Enabled=true;
  };

  if (posX>=POSPASARX && posX<=POSPASARX+ANCHOSIMBOLOS && posY>=SIMBOLOY && posX<=SIMBOLOY+LARGOSIMBOLOS){
          //pasa el turno
          game->pasarTurno();
          if (cantJugadores==1)
                mostrarJugadasClick(this);
          // si estaba en medio de una jugada, esta culmina
          if (game->jugando()){
                game->unSetJugando();
                game->setFichaSelecionada(-1);
                numeroFicha=-1;
          };

  };
  if (posX>=POSDESHACERX && posX<=POSDESHACERX+ANCHOSIMBOLOS && posY>=SIMBOLOY && posX<=SIMBOLOY+LARGOSIMBOLOS)
          game->deshacerJugada();

  if (posX>=POSRECOMENZARX && posX<=POSRECOMENZARX+ANCHOSIMBOLOS && posY>=SIMBOLOY && posX<=SIMBOLOY+LARGOSIMBOLOS)
  {
         Form1->Enabled=false;
         delete(imagenes);
         delete(game);
         Form3->jugadas->Clear();
         Form3->Visible=false;
         cantJugadores=-1;
         posX=0;
         posY=0;
         numeroFicha=-1;
         TimerAnimar->Enabled=false;
         Form2->Visible=true;

  };
  if (posX>=POSMUSICX && posX<=POSMUSICX+ANCHOSIMBOLOS && posY>=SIMBOLOY && posX<=SIMBOLOY+LARGOSIMBOLOS){
      if (music){
        game->noMostrarDeshabilitar();
        sounds->unSetMusica();
      }
      else{
        game->noMostrarHabilitar();
        sounds->setMusica();
      };
      music=!music;
   };
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerFestejarTimer(TObject *Sender)
{
   game->desanimarHappy();
   game->reAnimarWorker();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerComprobarTimer(TObject *Sender)
{
     game->noMostrarComprobando();
     game->mostrarComprobar();
     TimerComprobar->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::mostrarJugadasClick(TObject *Sender)
{
           Form3->mostrar(game->getJugadorPC()->getJugadas());
}
//---------------------------------------------------------------------------

