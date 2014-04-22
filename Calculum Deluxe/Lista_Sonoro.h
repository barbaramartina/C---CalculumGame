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

#ifndef phListaH
#define phListaH

//---------------------------------------------------------------------------
template <class T>
class TLista{
  private:
    T **elementos;
    int cantidad,posicion,tamano;
    void mergeSort(int inicio, int fin, T** aux){
      if(inicio<fin){
        int medio=(inicio+fin)/2;
        mergeSort(inicio,medio,aux);
        mergeSort(medio+1,fin,aux);
        for(int i=inicio; i<=fin; i++) aux[i]=elementos[i];
        int i1=inicio,i2=medio+1,i=inicio;
        while (i1<=medio && i2<=fin) elementos[i++]=((*aux[i1])<(*aux[i2]))?aux[i1++]:aux[i2++];
        while (i1<=medio) elementos[i++]=aux[i1++];
        while (i2<=fin) elementos[i++]=aux[i2++];
      }
    }

  public:
    bool ordenada;

    TLista(){tamano=1; elementos=new T*[tamano]; cantidad=posicion=0; ordenada=true;}
    ~TLista(){eliminarTodos(); delete elementos;}
    T* operator [] (int pos){return (pos<cantidad)?elementos[pos]:0;}
    T* primero(){posicion=0; return siguiente();}
    T* siguiente(){return (posicion<cantidad)?elementos[posicion++]:0;}
    int cantidadElementos(){return cantidad;}
    void eliminar(T*elem){sacar(elem); delete elem;}
    void eliminarTodos(){while(cantidad) delete elementos[--cantidad];}
    void vaciarSinEliminar(){cantidad=0;}
    void agregar(T *p){
      elementos[cantidad++]=p;
      if (cantidad==tamano){
        tamano*=2;
        T **aux=new T*[tamano];
        for(int i=0; i<cantidad; i++) aux[i]=elementos[i];
        delete elementos;
        elementos=aux;
      }
      ordenada=cantidad<2;
    }

    bool pertenece(T *p){
      for(int i=0; i<cantidad; i++) if (elementos[i]==p) return true;
      return false;
    }

    void ordenar(){
      if(!ordenada){
        T** aux=new T*[cantidad];
        mergeSort(0,cantidad-1,aux);
        delete aux;
        ordenada=true;
      }
    }

    bool estaOrdenada(){
      for(int i=0; i<cantidad-1; i++)
        if (*elementos[i+1]<*elementos[i]) return false;
      return true;
    }

    void sacar(T*elem){
      int i;
      for(i=0; (i<cantidad) && (elementos[i]!=elem); i++);
      if(i<cantidad) elementos[i]=elementos[--cantidad];
    }

    int hayUnoIgual(T*elem){
      for(int i=0; i<cantidad; i++)
         if (*(elementos[i])==*elem) return i;
      return -1;
    }
};



#endif
