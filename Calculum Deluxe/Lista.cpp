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


#include <iostream.h>
#include <conio.h>
#include <System.hpp>

#include "Posicion.h"
#include "Ficha.h"
#include "Operacion_Aritmetica.h"
#include "Jugada.h"






#ifndef LISTA_CPP
#define LISTA_CPP


template <class T>

class Lista
{
	class Nodo{
	public:
		Nodo * sig;
		T *elem;
	};


	Nodo* raiz, *actual;
	int longitud;

  public:
	Lista();
	~Lista();
	void vaciar();
		/*Borra todo el contenido de la lista	*/
        void agregar(T *elem);
	void eliminar(T *elem);
		/*Elimina la posici¢n en la lista */
	T *primero();
		/*Iterador, utilizado junto con siguiente() para recorrer
		  la lista.  Devuelve el primer elemento de la lista y ubica
		  alli el cursor (para iniciar un recorrido sobre la misma).
		  Si la lista esta vacia devuelve NULL.
		*/
	T *siguiente();
		/*Iterador, devuelve el siguiente elemento en un recorrido
		  secuencial de la lista.
		*/
        T *Lista<T>::pertenece (T *elem);
                /* Retorna el elemento si es que este pertenece a la Lista
                   Retorna NULL en caso contrario.
                */
	int tamanio();
        T *get(int);
	void clonar(Lista<T> *origen);
		/*Efectua una copia de la lista.  Tambien duplica los objetos
		  que contiene.
		*/
};


template <class T>
Lista<T>::Lista(){raiz=actual=NULL; longitud=0;}

//--------------------------------
template <class T>
Lista<T>::~Lista(){vaciar();}
//--------------------------------
template <class T>
void Lista<T>::vaciar()
{Nodo *aux = raiz;
	while(raiz != NULL)
	{aux = raiz;
	 raiz = raiz->sig;
	 delete aux;
	}
 longitud=0;
}
//--------------------------------
template <class T>
void Lista<T>::agregar (T *elem)
{	Nodo *aux = new Nodo;
        aux->elem=elem;
	aux->sig = raiz;
	raiz = aux;
	longitud++;
}

//--------------------------------
template <class T>
void Lista<T>::eliminar (T *elem)
{// si el elemento no esta no pasa nada
	Nodo *aux2, *aux1 = raiz;

	if(raiz == NULL) return;
	//primer caso

	if ((raiz->elem)->equal(*elem))
		{raiz = raiz->sig;
		 longitud--;
		 delete aux1;
		 return;
		}

	aux2 = aux1->sig;
	while (aux2 != NULL)
		{if ((aux2->elem)->equal(*elem))
			{aux1->sig = aux2->sig;
			 longitud--;
			 delete aux2;
			 return;
			}
		else
			{aux1=aux2;
			 aux2=aux2->sig;
			}
		}

}
//--------------------------------
template <class T>
T *Lista<T>::get(int pos){
    if (pos<longitud){
      Nodo *aux1=raiz;
      T *aux=new T;
      int i;
      for (i=0; i<pos; i++)
           aux1=aux1->sig;
      aux=aux1->elem;
      return aux;
    }
    else
        return NULL;
};
//--------------------------------
template <class T>
T *Lista<T>::pertenece (T *elem)
{// NULL si no existe y sino la posición
	Nodo *aux = raiz;
	while (aux != NULL)
		{if ((aux->elem)->equal(*elem))
			 return (aux->elem);
		else
			 aux=aux->sig;
		}
	return NULL;
}
//--------------------------------
template <class T>
T *Lista<T>::primero()
{
	if (raiz == NULL)
		return(NULL);
	else{
		actual=raiz;
		return(raiz->elem);
	}
}

//--------------------------------
template <class T>
T *Lista<T>::siguiente()
{
	if (actual == NULL)
		return(NULL);
	else
		if (actual->sig == NULL)
			return(NULL);
		else
		{  actual = actual->sig;
		   return(actual->elem);
		}
}
//--------------------------------
template <class T>
int Lista<T>:: tamanio()
{ return(longitud);};
//--------------------------------
template <class T>
void Lista<T>::clonar(Lista<T> *origen){
	vaciar();
	T *tmp;
	for (T *aux=origen->primero();aux;aux=origen->siguiente()){
		tmp=new T;
		*tmp=*aux;
		agregar(tmp);
	}
}

//------------------------------------------------
//------------------------------------------------

#pragma option -Jgd
Lista<Operacion_Aritmetica>;
Lista<Ficha>;
Lista<Posicion>;
Lista<Jugada>;









#endif
