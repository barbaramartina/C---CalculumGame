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

#include "Tablero.h"

//-------------------------------------------------
/*
  Se inicializan todas las posiciones de la matriz
  con casillas en cada una de ellas
*/
void Tablero::inicmatriz(Matriz<Casilla> *m){
    for (int i=0; i<ANCHO; i++)
       for (int j=0; j<LARGO; j++)
            m->set(new Casilla(),i,j);

};
//-------------------------------------------------
Tablero::Tablero(){
       matriz=new Matriz<Casilla>(ANCHO,LARGO);
       inicmatriz(matriz);
       operaciones=NULL;
};
//-------------------------------------------------
Tablero::Tablero(Lista<Operacion_Aritmetica> *op){
       randomize();
       operaciones=op;
       matriz=new Matriz<Casilla>(ANCHO,LARGO);
       inicmatriz(matriz);
       // En cada una de las posiciones se van agregando fichas con los valores y fondos que
       // le corresponden segun la posicion que ocupan.
       for (int i=0; i<ANCHO; i++)
         for (int j=0; j<LARGO; j++){
             //si estoy en las posiciones del medio
             if (((i==POSMEDIO1) || (i==POSMEDIO2)) && ((j==POSMEDIO1) || (j==POSMEDIO2))){
                int value=random(MAX)+1;
                matriz->get(i,j)->setFicha(new Ficha(value));
                matriz->get(i,j)->setFactor(VALORSIMPLE);
                matriz->get(i,j)->setFondo("fondo");
             }
             else
                //si esta en las diagonales el valor sera doble
                if ((i==j && i!=7 && i!=8) || (i==(ANCHO-1-j) && i!=7 && i!=8)){
                        matriz->get(i,j)->setFactor(VALORDOBLE);
                        matriz->get(i,j)->setFondo("plus_1");
                }
                else
                   //setea los valores triples
                   if ((i>=COMIENZOXTRIPLE || i<=FINXTRIPLE) && (j==YTRIPLE1 || j==YTRIPLE2)){
                        matriz->get(i,j)->setFactor(VALORTRIPLE);
                        matriz->get(i,j)->setFondo("plus_2");
                   }
                   //si es cualquiera de las otras posiciones
                   else{
                        matriz->get(i,j)->setFactor(VALORSIMPLE);
                        matriz->get(i,j)->setFondo("fondo");
                   };


         };

};
//-------------------------------------------------
Tablero::~Tablero(){
        delete(matriz);
        delete(operaciones);
};
//-------------------------------------------------
Casilla *Tablero::getCasilla(Posicion *p){
        return matriz->get(p->GetI(),p->GetJ());
}
//-------------------------------------------------
/*
  Dadas una ficha y una posicion realiza la jugada
  la cual es devuelta en la variable j, en caso de existir.
*/
int Tablero::hacerJugada(Ficha *f,Posicion *p,Jugada *&j){
    if (this->jugadaValida(f,p,j)){
         matriz->get(p->GetI(),p->GetJ())->setFicha(f);
         return EXITO;
    }
    else
       return ERROR;


};
//-------------------------------------------------
void Tablero::deshacerJugada(Posicion *p){
       matriz->get(p->GetI(),p->GetJ())->delFicha();
};
//-------------------------------------------------
/*
   Dada una posicion y una direccion de busqueda, se analiza en el tablero
   si en esa direccion existen dos casillas que poseen fichas, estas
   dos casillas son las adyacentes a la posicion p en la direccion dir.
*/
Lista<Posicion> * Tablero::getPosicionesAdyacentes(Posicion *p,int dir){
        Lista<Posicion> *lista=new Lista<Posicion>;  //aqui se retornaran las posiciones adyacentes
        Posicion *p1=NULL;
        Posicion *p2=NULL;

        switch (dir)
        {
          case ARR: if (((matriz->posValida(p->GetI()-1,p->GetJ())) &&  (matriz->get(p->GetI()-1,p->GetJ())->getFicha()!=NULL))
                        && ((matriz->posValida(p->GetI()-2,p->GetJ()))  && (matriz->get(p->GetI()-2,p->GetJ())->getFicha()!=NULL))){
                        p1=new Posicion(p->GetI()-1,p->GetJ()) ;
                        p2=new Posicion(p->GetI()-2,p->GetJ()) ;
                    };
                    break;

          case ABA: if (((matriz->posValida(p->GetI()+1,p->GetJ())) &&  (matriz->get(p->GetI()+1,p->GetJ())->getFicha()!=NULL))
                        && ((matriz->posValida(p->GetI()+2,p->GetJ()))  && (matriz->get(p->GetI()+2,p->GetJ())->getFicha()!=NULL))){
                        p1=new Posicion(p->GetI()+2,p->GetJ()) ;
                        p2=new Posicion(p->GetI()+2,p->GetJ()) ;
                    };
                    break;

        case IZQ:  if (((matriz->posValida(p->GetI(),p->GetJ()-1)) &&  (matriz->get(p->GetI(),p->GetJ()-1)->getFicha()!=NULL))
                        && ((matriz->posValida(p->GetI(),p->GetJ()-2))  && (matriz->get(p->GetI(),p->GetJ()-2)->getFicha()!=NULL))){
                        p1=new Posicion(p->GetI(),p->GetJ()-1) ;
                        p2=new Posicion(p->GetI(),p->GetJ()-2) ;
                    };
                    break;

         case DER: if (((matriz->posValida(p->GetI(),p->GetJ()+1)) &&  (matriz->get(p->GetI(),p->GetJ()+1)->getFicha()!=NULL))
                        && ((matriz->posValida(p->GetI(),p->GetJ()+2))  && (matriz->get(p->GetI(),p->GetJ()+2)->getFicha()!=NULL))){
                        p1=new Posicion(p->GetI(),p->GetJ()+1) ;
                        p2=new Posicion(p->GetI(),p->GetJ()+2) ;
                    };
                    break;

         };

       //si hay dos casillas adyacentes ocupadas por fichas
          if ((p1!=NULL) && (p2!=NULL)){
               lista->agregar(p1);
               lista->agregar(p2);
               return lista;
          }       //sino retorna nulo
          else
              return NULL;


};
//-------------------------------------------------
Lista<Operacion_Aritmetica> *Tablero::getOperaciones(){
        return operaciones;
};
//-------------------------------------------------
/*
  En este metodo se recorre todo el tablero en busca de aquellas posiciones
  que no esten ocupadas por ninguna ficha, y que ademas tengan dos casillas
  adyacentes que esten ocupadas por fichas, o sea retorna aquellas posiciones
  libres en las cuales hay posibilidad de realizar alguna jugada.
*/
Lista<Posicion> *Tablero::getPosicionesLibres(){
        Lista<Posicion> *rtdo=new Lista<Posicion>;   //aqui se guardan todas las posiciones libres
        Lista<Posicion> *aux=NULL;


        for (int i=0; i<matriz->getSizeX(); i++)
                for (int j=0; j<matriz->getSizeY(); j++){
                        //si la casilla en esa posicion no posee ficha esta libre
                        if ((matriz->get(i,j)->getFicha()==NULL)){
                            bool adyacentes=false;
                            int dir=0;
                            Posicion *p_ij=new Posicion(i,j);
                            //chequea que tenga adyacentes en cualquier direccion
                            while ((dir<DIR) && (!adyacentes)){
                              aux=this->getPosicionesAdyacentes(p_ij,dir);
                              dir++;
                              if (aux!=NULL){
                                adyacentes=true;
                                rtdo->agregar(p_ij);
                              };
                            };

                        };

                 };
        return rtdo;
};
//-------------------------------------------------
bool Tablero::jugadaValida(Ficha *f,Posicion *p,Jugada *&j){
     int cant_operados=0; //indica en cuantas direcciones se opero
     bool opero=false;
     Ficha *uno;
     Ficha *dos;
     Posicion *aux_p;
     Lista<Posicion> *posiciones;

      if (matriz->get(p->GetI(),p->GetJ())->getFicha()==NULL){
        int i=0;
        //mientras no se analicen todas las direcciones y siga habiendo posibilidad de jugar
        while  (i<DIR)  {
           //obtiene las posiciones adyacentes a p en la direccion i
           posiciones=this->getPosicionesAdyacentes(p,i);
           opero=false;    //indica que aun no se realizo operacion en la direccion i
           //si hay adyacentes
           if (posiciones!=NULL){

                //se analiza la primera operacion disponible del tablero
                Operacion_Aritmetica *aux_op=operaciones->primero();

                //mientras haya operaciones y no se halla operado
                while ((aux_op!=NULL) && (!opero)){
                    //se obtienen de las posiciones adyacentes, las fichas que poseen
                    aux_p=posiciones->primero();
                    uno=matriz->get(aux_p->GetI(),aux_p->GetJ())->getFicha();
                    aux_p=posiciones->siguiente();
                    dos=matriz->get(aux_p->GetI(),aux_p->GetJ())->getFicha();

                    //se analiza si hay operacion valida con esas fichas de derecha a izquierda o a la inversa
                    if ((f->getValor()==aux_op->eval(uno->getValor(),dos->getValor())) ||(f->getValor()==aux_op->eval(dos->getValor(),uno->getValor()))) {
                        opero=true;
                        cant_operados++;
                        //si aun no se ha creado una jugada se la crea
                        if (j==NULL)
                                j=new Jugada(f,uno,dos,aux_op,p);
                    };

                    //se analiza la proxima operacion disponible
                    aux_op=operaciones->siguiente();
               };

                //si habiendo analizado todas la operaciones, aun no opero, ya no sera posible jugar en esa posicion
                if (!opero) {
                        //si se habia creado alguna jugada se anula
                        if (j!=NULL)
                          j=NULL;
                        //se retorna error porque la jugada ya no es valida
                        return ERROR;
                };

            };
         i++;    //se analiza la proxima direccion
     };
     };

     //retorna 1 si se opero correctamente
     return (cant_operados!=0);

};
//-------------------------------------------------
void Tablero::clonar(Tablero *origen){
  this->operaciones=origen->operaciones;
  this->matriz->clonar(origen->matriz);

};
//-------------------------------------------------
bool Tablero::masMovimientos(Lista<Ficha> *fichas){
  Ficha *ficha_aux;
  Posicion *p_aux;
  bool hayJugada=false;

  Lista<Posicion> *posicionesPosibles=this->getPosicionesLibres();

  ficha_aux=fichas->primero() ;
  while ((ficha_aux!=NULL) && (!hayJugada)){
     p_aux=posicionesPosibles->primero();
     while ((p_aux!=NULL) && (!hayJugada)){
        Jugada *j=NULL;
        if (this->jugadaValida(ficha_aux,p_aux,j))
          hayJugada=true;
        else
          p_aux=posicionesPosibles->siguiente();
     };
     ficha_aux=fichas->siguiente();
   };

  return hayJugada;
};
//-------------------------------------------------
int Tablero::getValorFicha(Posicion *p){
   if (matriz->get(p->GetI(),p->GetJ())->getFicha()!=NULL)
        return (matriz->get(p->GetI(),p->GetJ())->getFicha()->getValor()*matriz->get(p->GetI(),p->GetJ())->getFactor());
   else
        return 0;

};
//-------------------------------------------------
void Tablero::mostrar(TImage *im,int x, int y,image_fichas *recursos){
  Casilla *aux_c;

  for (int i=0; i<matriz->getSizeX(); i++)
        for (int j=0; j<matriz->getSizeY(); j++){
          aux_c=matriz->get(i,j);
          aux_c->mostrar(im,x+(ANCHOFICHA*i),y+(ANCHOFICHA*j),recursos);
        };

};
//---------------------------------------------------------------------------

#pragma package(smart_init)
