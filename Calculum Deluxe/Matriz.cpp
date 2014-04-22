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
#include "Matriz.h"
#pragma package(smart_init)
template class Matriz<Casilla>;
//---------------------------------------------------------------------------
template <class T> Matriz<T>::Matriz(int x,int y){
   matriz = new T**[x];
   for (int i=0; i<y; i++){
      matriz[i] = new T*[y];
      for (int j=0;j<x;j++)
         matriz[i][j] = NULL;
   }
   tamX=x;
   tamY=y;
};
//---------------------------------------------------------------------------
template <class T> Matriz<T>::~Matriz(){
   for(int j=0;j<this->getSizeY();delete matriz[j++]);
   delete matriz;
};
//---------------------------------------------------------------------------
template <class T> int Matriz<T>::getSizeX(){
   return tamX;
};
//---------------------------------------------------------------------------
template <class T> int Matriz<T>::getSizeY(){
   return tamY;
};
//---------------------------------------------------------------------------
template <class T> T *Matriz<T>::get(int x,int y){
   if (!this->posValida(x,y)) return NULL;
   return matriz[x][y];
};
//---------------------------------------------------------------------------
template <class T> void Matriz<T>::set(T* elem,int x,int y){
   if ((this->posValida(x,y))&& (!this->posOcupada(x,y)))
      matriz[x][y]=elem;

};
//---------------------------------------------------------------------------
template <class T> bool Matriz<T>::posValida(int x,int y){
   if (x<0 || x>=this->getSizeX() || y<0 || y>=this->getSizeY()) return false;
   return true;
};
//---------------------------------------------------------------------------
template <class T> bool Matriz<T>::posOcupada(int x,int y){
        T *aux=this->get(x,y);
        return aux!=NULL;
};
//---------------------------------------------------------------------------
template <class T> void Matriz<T>::del(int x,int y){
        if ((this->posValida(x,y)) && (this->posOcupada(x,y)))
           this->set(NULL,x,y);

};
//---------------------------------------------------------------------------
template <class T> void Matriz<T>::clonar(Matriz<T> *origen){
      	T *tmp;
        for (int i=0; i<origen->getSizeX(); i++)
          for (int j=0; j<origen->getSizeY(); j++){
		tmp=new T;
                if (origen->get(i,j)!=NULL)
	              *tmp=*origen->get(i,j);
                else
                      tmp=NULL;

		matriz[i][j]=tmp;

   
          };
        
};
//---------------------------------------------------------------------------



