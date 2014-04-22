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

#ifndef OpcionesH
#define OpcionesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <System.hpp>
#include <Buttons.hpp> 
#include <ExtCtrls.hpp>
#include <Graphics.hpp>

#include "Main.h"
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *buttonPlay;
        TCheckBox *j1;
        TCheckBox *j2;
        TCheckBox *j3;
        TCheckBox *j4;
        TLabel *Label1;
        TImage *Image1;
        TImage *Image2;
        TImage *Image3;
        TImage *Image4;
        void __fastcall j1Click(TObject *Sender);
        void __fastcall j2Click(TObject *Sender);
        void __fastcall j3Click(TObject *Sender);
        void __fastcall j4Click(TObject *Sender);
        void __fastcall buttonPlayClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
        bool checkJugadores();
        int jugadores;

public:		// User declarations
        __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
