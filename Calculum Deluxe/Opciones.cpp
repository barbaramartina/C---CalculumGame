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

#include "Opciones.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
bool TForm2::checkJugadores(){
  if (j1->Checked==true || j2->Checked==true || j3->Checked==true || j4->Checked==true )
        return true;
  else
        return false;

};
//---------------------------------------------------------------------------
void __fastcall TForm2::j1Click(TObject *Sender)
{
  jugadores=1;
  j2->Checked=false;
  j3->Checked=false;
  j4->Checked=false;


}
//---------------------------------------------------------------------------
void __fastcall TForm2::j2Click(TObject *Sender)
{
  jugadores=2;
  j1->Checked=false;
  j3->Checked=false;
  j4->Checked=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::j3Click(TObject *Sender)
{
  jugadores=3;
  j2->Checked=false;
  j1->Checked=false;
  j4->Checked=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::j4Click(TObject *Sender)
{
  jugadores=4;
  j2->Checked=false;
  j3->Checked=false;
  j1->Checked=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::buttonPlayClick(TObject *Sender)
{
 if (checkJugadores()){
   Form1->comenzar(jugadores);
   Form1->Enabled=true;
   Form1->Align=alNone;
   Form2->Visible=false;
 };
}
//---------------------------------------------------------------------------


void __fastcall TForm2::FormCreate(TObject *Sender)
{
   Form2->Left=33;
   Form2->Top=15;       
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
  Form1->Close();        
}
//---------------------------------------------------------------------------

