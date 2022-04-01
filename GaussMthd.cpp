//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop
#include <dir.h>
#include "GaussMthd.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	StatusBar1-> Panels-> Items [0] -> Text = L" Welcome to Linear Algebra! " ;
	// Form1->Button2->Enabled = false;
	Form1->Button3->Enabled = false;
	Button5->Enabled = false;
	Button6->Enabled = false;
	//PathmaArts1->Enabled = false;
    save_as = false;

	if (StringGrid1->RowCount<2)
		Deleteequation1->Enabled = false;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)   //Exit Button
{
	Close();
}
//---------------------------------------------------------------------------
 int TForm1::Calc(void)
{
  int u,k,m,i,j;
  int f_exit;
  float t;

  u = 0;
  f_not = false;
  while (u!=n)
  {
    u++;
    k=u;
	while (A[k][u]==0)
    {
      k++;
      if (k>n)
      {
        f_not = true;   // system is not determined
		return 0;
      }
    }
    if (k!=u)
    {
      for (m = u; m<=n+1; m++)
      {
        t = A[u][m];
        A[u][m] = A[k][m];
        A[k][m] = t;
      }
    }

    for (j = n+1; j >= u; j--)
      A[u][j] = A[u][j]/A[u][u];

    m = n + 1;
    if ((k+1)<=n)
      for (i = k+1; i <= n; i++)
        for (j = u+1; j <= m; j++)
		  A[i][j] = A[i][j]-A[i][u] * A[u][j];
  }

  // Building the array of results
  for (i = n; i >= 1; i--)
  {
	X[i] = A[i][m];
	if (i!=1)
	  for (k = i-1; k>=1; k--)
		A[k][m] = A[k][m] - A[k][i] * X[i];
  }
  return 1; // is solution
}
void __fastcall TForm1::Button3Click(TObject *Sender)    //Calculate Button

{
	int i,j;

	 try
	  {
		if (Edit1->Text ==L"")
		{
		c = 0;
		}
		else
		c = StrToInt(Form1->Edit1->Text);
		//ShowMessage (L"Succeeded");
		// MessageDlg("The calculation roots of the equation has been set successfully!", mtInformation, TMsgDlgButtons() << mbOK, 0);
		StatusBar1-> Panels-> Items [0] -> Text = L" Accuracy set to "+Edit1->Text;
	  }
	  catch (...)
	  {
		switch (Application->MessageBox(L"Invalid value set to Accuracy",
										L"Gauss Method v1.0", MB_OK|MB_ICONERROR))

			case ID_OK:
		{
			Edit1->SetFocus();
			Abort();
		}

	  }

      try
	  {
	  // Building the matrix A
	  for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		  A[i][j] = StrToFloat(Form1->StringGrid1->Cells[j][i]);

		// Column B
	  for (i = 1; i <= n; i++)
		A[i][n+1] = StrToFloat(Form1->StringGrid1->Cells[n+1][i]);
	  }
	  catch (...)

	  {
        	StringGrid1->Row = i ;  //нужно вычесть 1, т.к. перед проверкой условия выхода из цикла последний раз сработает row++
			StringGrid1->Col = j;
			StatusBar1-> Panels-> Items [0] -> Text = L"Please check the value in  Equation No: " + UnicodeString(i) + L"   Value: " + UnicodeString(j);
			StringGrid1->SetFocus();
		switch (Application->MessageBox(L"Invalid values detected",
										L"Gauss Method v1.0", MB_OK|MB_ICONERROR))

			case ID_OK:
		{
			Abort();
		}
	  }

	  StringGrid2->ColWidths[0]=40;
	  for (i = 1; i <= n; i++)
		Form1->StringGrid2->Cells[0][i-1] = "X[" + IntToStr(i) + "]=";
		Calc();
	  if (!f_not)
	   {
        StringGrid2->ColWidths[1]=c*10+40;
		// X - array of results
		for (i=1; i<=n; i++)
		  Form1->StringGrid2->Cells[1][i-1] = FloatToStrF(X[i],ffFixed,c+5,c);
		  //Form2->ShowModal(); // show the result form
	   }

	  else
	   {  	StatusBar1-> Panels-> Items [0] -> Text = L" An error occured! " ;
			Button5->Enabled = false;

			for (int i = StringGrid1-> FixedCols; i <StringGrid2-> ColCount; i ++)
			StringGrid2-> Cols [i] -> Clear ();

			switch (Application->MessageBox(L"System not determined!",
										L"Gauss Method v1.0", MB_OK|MB_ICONERROR))

			case ID_OK:
		{
			Abort();
		}
	   }

	   Button5->Enabled = true;
	   StatusBar1-> Panels-> Items [0] -> Text = L" Successfully calculated! " ;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)     //New Button
{
	int i,j;
	if ((StatusBar1-> Panels-> Items [0] -> Text == L" Successfully Created")
		||save_as == true//(StringGrid1->EditorMode==true) //Save Changes
		&& !(StatusBar1-> Panels-> Items [0] -> Text == L" Edits successfully saved to: "+ SaveDialog1-> FileName))
		{
		//|| (StatusBar1-> Panels-> Items [0] -> Text == L" Successfully calculated! "
		switch (Application->MessageBox(L"Do you want to save changes before create a new?", L"Save changes", MB_YESNOCANCEL|MB_ICONQUESTION))
			{
			case ID_YES:
				{
					SaveDialog1->DefaultExt="gmt";

				if ( SaveDialog1->Execute())
					{
						StringGrid1->Cols[0]->Clear();
						TStringList *tsl=new TStringList;

						for(int i=1;i<StringGrid1->RowCount;i++)
						{
							tsl->StrictDelimiter=true;
							tsl->Delimiter=' ';
							tsl->Append(StringGrid1->Rows[i]->DelimitedText);
						}
						tsl->SaveToFile(SaveDialog1->FileName);
						delete tsl;
						StatusBar1-> Panels-> Items [0] -> Text = L" Edits successfully saved to: "+ SaveDialog1-> FileName;
						for (int J = 1; J < n+1; J++)
							StringGrid1->Cells[0][J] = IntToStr(J) /*+ ")"*/;
						save_as = false;
						Button6->Enabled = false;
                    break;
				}
				case ID_NO:
				{
					break;
				}
				case ID_CANCEL:
				{
					Abort();
				}
			}
		}
		}

	if (Form2->ShowModal()==mrOk)
	{
	try
	 {
		StringGrid1->RowHeights[0]=0;
		StringGrid2->RowHeights[0]=0;
		for(int i=0;i<=n+1;i++)
		{
			StringGrid1->Rows[i]->Clear();
			StringGrid1->RowCount--;
			StringGrid1->ColCount--;
		}

		for(int i=0;i<=n;i++)
		{
			StringGrid2->Rows[i]->Clear();
			StringGrid2->RowCount--;
			StringGrid2->ColCount--;
		}

		StringGrid1->RowHeights[0]=StringGrid1->DefaultRowHeight;
		StringGrid2->RowHeights[0]=StringGrid2->DefaultRowHeight;
		n = StrToInt(Form2->Edit1->Text);

		Form1->StringGrid1->ColCount = n+2; // number of columns
		Form1->StringGrid1->RowCount = n+1; // number of rows

		for (int I = 1; I < StringGrid1->ColCount-1; I++)
			StringGrid1->Cells[I][0] = "A(" + IntToStr(I) + ")";

		for (int J = 1; J < n+1; J++)
			StringGrid1->Cells[0][J] = IntToStr(J) ;
			StringGrid1->Cells[n+1][0] = L"B";

	   //	for(int i = 1; i < n+1; i++)
			StringGrid1->FixedRows = 1;
			StringGrid1->FixedCols = 1;

		Form1->StringGrid2->RowCount = n;
		Form1->StringGrid2->ColCount = 2;
		StatusBar1-> Panels-> Items [0] -> Text = L" Successfully Created";
		//Button2->Enabled = true;
		Button3->Enabled = true;
		Calculate1->Enabled = true;
		Save1->Enabled = true;
		Saveas1->Enabled = true;

        if (StringGrid1->RowCount>2)
			Deleteequation1->Enabled = true;

		Button3->Enabled = true;
		if (n==0)
		{
		StringGrid1->RowHeights[0]=0;
		StringGrid2->RowHeights[0]=0;
		Calculate1->Enabled = false;
		Button3->Enabled = false;
		StatusBar1-> Panels-> Items [0] -> Text = L" No equations insert!";
		}


	 }
	catch(...)
	 {
		StringGrid1->RowHeights[0]=0;
		StringGrid2->RowHeights[0]=0;
		Calculate1->Enabled = false;
		Button3->Enabled = false;
		StatusBar1-> Panels-> Items [0] -> Text = L" No equations insert!";

		switch (Application->MessageBox(L"Invalid number of equations.",
										L"Gauss Method v1.0", MB_OK|MB_ICONERROR))

			case ID_OK:
		{
			TForm1::Button2Click(Sender);
			//StatusBar1-> Panels-> Items [0] -> Text = L" No equations insert!";
			//Form2->Edit1->SetFocus();
			Form2->Edit1->Clear();
			break;
		}

	 }

	}

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender)     //open Button
{
	 int i, j;                 //Save Changes
	 if ((StatusBar1-> Panels-> Items [0] -> Text == L" Successfully Created")  //Save Changes
		|| (save_as ==true) //(StringGrid1->EditorMode==true)
		&&!(StatusBar1-> Panels-> Items [0] -> Text == L" Edits successfully saved to: "+ SaveDialog1-> FileName))
	 {
		//|| (StatusBar1-> Panels-> Items [0] -> Text == L" Successfully calculated! "
		switch (Application->MessageBox(L"Do you want to save changes before Open?", L"Save changes", MB_YESNOCANCEL|MB_ICONQUESTION))
			{
			case ID_YES:
				{
						//SaveDialog1->DefaultExt="gmt";

					//if ( SaveDialog1->Execute(this->Handle))

						StringGrid1->Cols[0]->Clear();
						TStringList *tsl=new TStringList;

						for(int i=1;i<StringGrid1->RowCount;i++)
						{
							tsl->StrictDelimiter=true;
							tsl->Delimiter=' ';
							tsl->Append(StringGrid1->Rows[i]->DelimitedText);

						}
						tsl->SaveToFile(OpenDialog1->FileName);
						delete tsl;
						StatusBar1-> Panels-> Items [0] -> Text = L" Edits successfully saved to: "+ OpenDialog1-> FileName;
						for (int J = 1; J < n+1; J++)
							StringGrid1->Cells[0][J] = IntToStr(J) /*+ ")"*/;
						save_as = false;
						Button6->Enabled = false;
					break;

				}


				case ID_NO:
				{
					break;
				}
				case ID_CANCEL:
				{
					Abort();
				}

			}
	 }

		//OpenDialog1->DefaultExt="*.*";//это можно выставить в св-вах в disign time
		//OpenDialog1->Filter="Gauss Method (*.gmt)|*.gmt |Text Document (*.txt)|*.txt|All Files (*.*)|*.*";//это тоже,
	if ( OpenDialog1->Execute() )
		{
		for (int i = StringGrid1-> FixedCols; i <StringGrid1-> ColCount; i ++)
				StringGrid1-> Cols [i] -> Clear ();
		for (int i = StringGrid1-> FixedCols; i <StringGrid2-> ColCount; i ++)
				StringGrid2-> Cols [i] -> Clear ();

		TStringList *matrix = new TStringList;
		matrix->LoadFromFile(OpenDialog1->FileName);

		n = matrix->Count;

		Form1->StringGrid1->ColCount = n+2; // number of columns
		Form1->StringGrid1->RowCount = n+1; // number of rows
		//Form1->StringGrid2->RowCount = n; // right side
		//Form1->StringGrid2->ColCount = 1;

		for (int I = 1; I < StringGrid1->ColCount-1; I++)
			StringGrid1->Cells[I][0] = "A(" + IntToStr(I) + ")";

		for (int J = 1; J < n+1; J++)
			StringGrid1->Cells[0][J] = IntToStr(J) /*+ ")"*/;
			StringGrid1->Cells[n+1][0] = L"B";

		//for (i = 1; i <= n; i++)
		// Form1->StringGrid1->Cells[i][0] = "a[" + IntToStr(i) + "]";

		for(int i = 1; i < n+1; i++)
			{
			matrix->StrictDelimiter=true;
			matrix->Delimiter=' ';
			StringGrid1->Rows[i]->DelimitedText = StringGrid1->Cells[0][i]+ ' ' + matrix->Strings[i-1];
			}
		StatusBar1-> Panels-> Items [0] -> Text = L" Successfully opened the file: "+
													OpenDialog1-> FileName;
		StringGrid1->FixedRows = 1;
		StringGrid1->FixedCols = 1;

		open_err = false;
	  ////////////////////////////////////////////////////////////////
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n+1; j++)
		 // B[i][j] = StrToFloat(Form1->StringGrid1->Cells[j-1][i-1]);
				if (StringGrid1->Cells[j][i] == "")
					{
					open_err = true;
					}
				if (!open_err)
					{
					Form1->StringGrid2->RowCount = n;
					Form1->StringGrid2->ColCount = 2;

					//Button2->Enabled = true;
					Button3->Enabled = true;
					Calculate1->Enabled = true;
					Save1->Enabled = true;
					}
				else
					{
					switch (Application->MessageBox(L"Invalid matrix!",
										L"Gauss Method v1.0", MB_OK|MB_ICONERROR))

					case ID_OK:
						{
						break;
						}
					Button5->Enabled = false;
					Button3->Enabled = false;
					Calculate1->Enabled = false;
					Save1->Enabled = false;
					StatusBar1-> Panels-> Items [0] -> Text = L" An error occured! Try another file. " ;
				   //	TForm1::Button4Click(Sender) ;
					}

				if (StringGrid1->RowCount>2)
					Deleteequation1->Enabled = true;
                    StringGrid1->RowHeights[0]=StringGrid1->DefaultRowHeight;
					StringGrid2->RowHeights[0]=StringGrid2->DefaultRowHeight;

	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)    //Save Resulta As Button
{

	SaveDialog2->DefaultExt="txt";//это можно выставить в св-вах в disign time
	SaveDialog2->Filter="Text Document (*.txt)|*.txt|All files (*.*)|*.*";//это тоже,

		if ( SaveDialog2->Execute() )
		{
			TStringList *tsl=new TStringList;
			//tsl->Add(IntToStr(StringGrid2->RowCount));
			//tsl->Add(IntToStr(StringGrid2->ColCount));
		for(int i=0;i<StringGrid2->RowCount;i++)
			{
				//tsl->AddStrings(StringGrid1->Rows[i]);
				StringGrid2->Rows[i]->StrictDelimiter=true;
				StringGrid2->Rows[i]->Delimiter=' ';
				tsl->Append(StringGrid2->Rows[i]->DelimitedText);
			}
			tsl->SaveToFile(SaveDialog2->FileName,TEncoding::UTF8);
			delete tsl;
			StatusBar1-> Panels-> Items [0] -> Text = L" Results Successfully saved to: "
													+ SaveDialog2-> FileName;
			Button5->Enabled = false;
		}


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)  //Save as button
{
	SaveDialog1->DefaultExt="gmt";//это можно выставить в св-вах в disign time
	//SaveDialog1->Filter="Gauss Method (*.gmt)|*.gmt|Text Document (*.txt)|*.txt|Binary files (*.bin)|*.bin";//это тоже,

	if ( SaveDialog1->Execute())
		{
		StringGrid1->Cols[0]->Clear();
		TStringList *tsl=new TStringList;
		//	tsl->Add(IntToStr(StringGrid2->RowCount));
		//	tsl->Add(IntToStr(StringGrid2->ColCount));
		for(int i=1;i<StringGrid1->RowCount;i++)
		// for(int j=0;j<StringGrid1->ColCount;j++)
			{
			tsl->StrictDelimiter=true;
			tsl->Delimiter=' ';
			//StringGrid1->Rows[i]->DelimitedText = StringGrid1->Cells[i][j]+ ' ' + tsl->Strings[i];
			tsl->Append(StringGrid1->Rows[i]->DelimitedText);
			//tsl->matrix(StringGrid1->Cells[i][j]);

			}
		tsl->SaveToFile(SaveDialog1->FileName,TEncoding::UTF8);
		delete tsl;
		StatusBar1-> Panels-> Items [0] -> Text = L" Edits successfully saved to: "+ SaveDialog1-> FileName;
		for (int J = 1; J < n+1; J++)
			StringGrid1->Cells[0][J] = IntToStr(J) /*+ ")"*/;
		save_as = false;
		Button6->Enabled = false;
		}


}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
	if ((StatusBar1-> Panels-> Items [0] -> Text == L" Successfully Created")
		||save_as == true//(StringGrid1->EditorMode==true) //Save Changes
		&& !(StatusBar1-> Panels-> Items [0] -> Text == L" Edits successfully saved to: "+ SaveDialog1-> FileName))
	{
		//|| (StatusBar1-> Panels-> Items [0] -> Text == L" Successfully calculated! "
		switch (Application->MessageBox(L"Do you want to save changes before Exit?", L"Save changes", MB_YESNOCANCEL|MB_ICONQUESTION))
			{
			case ID_YES:
				{
				   //	SaveDialog1->DefaultExt="gmt";

				//if ( SaveDialog1->Execute())
				   //	{
						StringGrid1->Cols[0]->Clear();
						TStringList *tsl=new TStringList;

						for(int i=1;i<StringGrid1->RowCount;i++)
						{
							tsl->StrictDelimiter=true;
							tsl->Delimiter=' ';
							tsl->Append(StringGrid1->Rows[i]->DelimitedText);

						}
						tsl->SaveToFile(OpenDialog1->FileName);
						delete tsl;
						StatusBar1-> Panels-> Items [0] -> Text = L" Edits successfully saved to: "+ OpenDialog1-> FileName;
						for (int J = 1; J < n+1; J++)
							StringGrid1->Cells[0][J] = IntToStr(J) /*+ ")"*/;
						save_as = false;
						Button6->Enabled = false;
					break;
				//}
			}

				case ID_NO:
				{
					break;
				}
				case ID_CANCEL:
				{
					Abort();
				}
		}
	}

	 if ((StatusBar1-> Panels-> Items [0] -> Text == L" Successfully calculated! ")    //save Results
		&&!(StatusBar1-> Panels-> Items [0] -> Text == L" Results Successfully saved to: "+ SaveDialog2-> FileName))
	//|| (StringGrid1->EditorMode==true))
	{
		switch (Application->MessageBox(L"Do you want to save results before Exit?", L"Save changes", MB_YESNOCANCEL|MB_ICONQUESTION))
		{
			case ID_YES:
			{
				SaveDialog2->DefaultExt="txt";//это можно выставить в св-вах в disign time
				SaveDialog2->Filter="Text Document (*.txt)|*.txt|Binary files (*.bin)|*.bin";//это тоже,
				if ( SaveDialog2->Execute() )
				{
					TStringList *tsl=new TStringList;
					//	tsl->Add(IntToStr(StringGrid2->RowCount));
					//	tsl->Add(IntToStr(StringGrid2->ColCount));
					for(int i=0;i<StringGrid2->RowCount;i++)
						{
							//tsl->AddStrings(StringGrid1->Rows[i]);
							StringGrid2->Rows[i]->StrictDelimiter=true;
							StringGrid2->Rows[i]->Delimiter=' ';
							tsl->Append(StringGrid2->Rows[i]->DelimitedText);
						}
					tsl->SaveToFile(SaveDialog2->FileName);
					delete tsl;
					break;
				}
			case ID_NO:
				{
				break;
				}
			case ID_CANCEL:
				{
				Abort();
				}

			}
		}

	}


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1Change(TObject *Sender)
{
	//Button6->Enabled = true;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::New1Click(TObject *Sender)
{
	TForm1::Button2Click(Sender) ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Open1Click(TObject *Sender)
{
	TForm1::Button4Click(Sender) ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Save1Click(TObject *Sender)
{
	TForm1::Button5Click(Sender) ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Saveas1Click(TObject *Sender)
{
	TForm1::Button6Click(Sender) ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Exit1Click(TObject *Sender)
{
	TForm1::Button1Click(Sender) ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Calculate1Click(TObject *Sender)
{
	TForm1::Button3Click(Sender) ;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::StringGrid1GetEditText(TObject *Sender, int ACol, int ARow,
          UnicodeString &Value)
{
	Button6->Enabled = true;
	Saveas1->Enabled = true;
	save_as = true;
	Save2->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid1KeyPress(TObject *Sender, System::WideChar &Key)

{

	if( !((Key >= L'0') && (Key <= L'9') ||(Key == L'-')|| (Key == L'.')
		||(Key == 3)||(Key == 22)||(Key == 24)||(Key == 26)||(Key == VK_RETURN)
		||( Key == VK_BACK )||( Key == L'E')||( Key == L'e')))  //FormatSettings.DecimalSeparator
		{
		 StatusBar1-> Panels-> Items [0] -> Text = L" Please enter numerals only";
		//ShowMessage("Please enter numerals only");
		 Key = 0;
		}
	else if ((Key == L'.') && (Pos(Key, StringGrid1->Cells[StringGrid1->Col][StringGrid1->Row]) > 0)||
			(Key == L'-') && (Pos(Key, StringGrid1->Cells[StringGrid1->Col][StringGrid1->Row])>0 ))
		{
		//ShowMessage("Two dots!");
		StatusBar1-> Panels-> Items [0] -> Text = L" Two dots and two minuses not enable!";
		Key = 0;
		}
	Button3->Enabled = true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::CleanAll1Click(TObject *Sender)
{   	switch (Application->MessageBox(L"Do you want to reset all values?",
									L"Gauss Method", MB_YESNO|MB_ICONQUESTION))
	{
		case ID_YES:
		{
			break;
		}
		case ID_NO:
		{
			Abort();
		}
	}
	StringGrid1->RowHeights[0]=0;
	StringGrid2->RowHeights[0]=0;
	for(int i=0;i<=n+1;i++)
		{
		StringGrid1->Rows[i]->Clear();
		StringGrid1->RowCount--;
		StringGrid1->ColCount--;
		}

	for(int i=0;i<=n;i++)
		{
		StringGrid2->Rows[i]->Clear();
		StringGrid2->RowCount--;
		StringGrid2->ColCount--;
		}
	StatusBar1-> Panels-> Items [0] -> Text = L" All equations erased!";
	Deleteequation1->Enabled = false;
	Button3->Enabled = false;
	Button5->Enabled = false;
	Button6->Enabled = false;
	Saveas1->Enabled = false;
	Save1->Enabled = false;
	save_as = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AboutProgram1Click(TObject *Sender)
{
 ShowMessage(L"Solving a system of N linear algebraic equations with N unknowns.\nThe calculation of the roots of the equation should be done with a given accuracy (for example, up to 10 characters).\nSource data must be loaded from file.Provide the ability to save the results to a file. " ) ;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Addequation1Click(TObject *Sender)
{
		StringGrid1->RowHeights[0]=StringGrid1->DefaultRowHeight;
		StringGrid2->RowHeights[0]=StringGrid2->DefaultRowHeight;
	   // StringGrid1->Options=StringGrid1->Options<<goEditing;

		for (int i = StringGrid1-> FixedCols; i <StringGrid2-> ColCount; i ++)
				StringGrid2-> Cols [i] -> Clear ();

		StringGrid1->RowCount = StringGrid1->RowCount + 1  ;
		StringGrid1->ColCount = StringGrid1->RowCount + 1;

        StringGrid1->FixedRows = 1;
		StringGrid1->FixedCols = 1;

		n = StringGrid1->RowCount-1;
		for (int I = 1; I < StringGrid1->ColCount-1; I++)
			StringGrid1->Cells[I][0] = "A(" + IntToStr(I) + ")";

		for (int J = 1; J < StringGrid1->RowCount; J++)
			StringGrid1->Cells[0][J] = IntToStr(J) /*+ ")"*/;
			StringGrid1->Cells[StringGrid1->ColCount -1 ][0] = L"B";

		StringGrid2->ColCount = 2;
		StringGrid2->RowCount = StringGrid1->RowCount -1;
		StatusBar1-> Panels-> Items [0] -> Text = L" Equation aded!";

		if (StringGrid1->RowCount>2)
			Deleteequation1->Enabled = true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Deleteequation1Click(TObject *Sender)
{
		switch (Application->MessageBox(L"Do you want to delete a equation?",
									L"Gauss Method", MB_YESNO|MB_ICONQUESTION))
	{
		case ID_YES:
		{
			break;
		}
		case ID_NO:
		{
			Abort();
		}
	}
		for (int I = 1; I < StringGrid1->ColCount-1; I++)
				StringGrid1->Cells[I][0] = "A(" + IntToStr(I) + ")";
		for (int i = StringGrid1-> FixedCols; i <StringGrid2-> ColCount; i ++)
				StringGrid2-> Cols [i] -> Clear ();

		StringGrid1->RowCount = StringGrid1->RowCount - 1;
		StringGrid1->ColCount = StringGrid1->ColCount - 1;
		n = StringGrid1->RowCount-1;
		StringGrid1->Cells[StringGrid1->ColCount - 1][0] = L"B";

		StringGrid1->Rows[n+1]->Clear();
		StringGrid1->Cols[n+2]->Clear();

		StringGrid2->RowCount--;
		StatusBar1-> Panels-> Items [0] -> Text = L" Equation deleted!";

		if (StringGrid1->RowCount<3)
			Deleteequation1->Enabled = false;
        StringGrid1->SetFocus();
		//Button3->Enabled = false;
		//Button5->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
		StringGrid1->RowHeights[0]=0;
		StringGrid2->RowHeights[0]=0;
		StringGrid1->ColWidths[0]=30;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::StringGrid1SelectCell(TObject *Sender, int ACol, int ARow,
		  bool &CanSelect)
{

	StatusBar1-> Panels-> Items [0] -> Text = L"You have selected Value: " + UnicodeString(ACol) +
											  L" in  Equation No: " + UnicodeString(ARow);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Save2Click(TObject *Sender)
{
		//SaveDialog1->DefaultExt="gmt";//это можно выставить в св-вах в disign time
	//SaveDialog1->Filter="Gauss Method (*.gmt)|*.gmt|Text Document (*.txt)|*.txt|Binary files (*.bin)|*.bin";//это тоже,

	//if ( SaveDialog1->Execute())
		//{
		StringGrid1->Cols[0]->Clear();
		TStringList *tsl=new TStringList;

		for(int i=1;i<StringGrid1->RowCount;i++)
		// for(int j=0;j<StringGrid1->ColCount;j++)
			{
			tsl->StrictDelimiter=true;
			tsl->Delimiter=' ';
			tsl->Append(StringGrid1->Rows[i]->DelimitedText);
			}
		tsl->SaveToFile(OpenDialog1->FileName,TEncoding::UTF8);
		delete tsl;
		StatusBar1-> Panels-> Items [0] -> Text = L" Edits successfully saved to: "+ OpenDialog1-> FileName;
		for (int J = 1; J < n+1; J++)
			StringGrid1->Cells[0][J] = IntToStr(J) /*+ ")"*/;
		save_as = false;
		Button6->Enabled = false;
		Save2->Enabled = false;

}
//---------------------------------------------------------------------------
/*  USEFULL
    /* if(SaveDialog1->Execute())
  {
	if(ExtractFileExt(SaveDialog1->FileName).UpperCase()==".TXT")
	{//как текстовый
	  FILE *fop=fopen(SaveDialog1->FileName.c_str(),"wt");
	  if(fop)
	  {
		if(StringGrid2->RowCount>0)
		  fprintf(fop,StringGrid2->Rows[0]->CommaText.c_str());
		for(int i=1;i<StringGrid2->RowCount;i++)
		  fprintf(fop,"\n%s",StringGrid2->Rows[i]->CommaText.c_str());
		fclose(fop);
	  }
	}
	else
	{//сохраняем как бинарный
	}
  }   */

////////////////////////////////////////////


/*
if ( SaveDialog1->Execute() )
	{
	TStringList *tsl=new TStringList;
   //	tsl->Add(IntToStr(StringGrid2->RowCount));
   //	tsl->Add(IntToStr(StringGrid2->ColCount));
	for(int i=0;i<StringGrid2->RowCount;i++)

		{
		//tsl->AddStrings(StringGrid1->Rows[i]);
		tsl->AddStrings(StringGrid2->Rows[i]);
		}
	 tsl->SaveToFile(SaveDialog1->FileName);
	delete tsl;
	} */
/*
   if ( OpenDialog1->Execute() )
	{
	TStringList *matrix = new TStringList;
	matrix->LoadFromFile(OpenDialog1->FileName);
	n = matrix->Count;
	Form1->StringGrid2->RowCount = n; // right side
	Form1->StringGrid2->ColCount = 1;

	//StringGrid2->RowCount = matrix->Count;
	//StringGrid2->ColCount = matrix->count;
	for(int i = 0; i < matrix->Count; i++)
	{   matrix->StrictDelimiter=true;
		matrix->Delimiter=' ';
		StringGrid2->Rows[i]->DelimitedText = StringGrid2->Cells[0][i]+ ' ' + matrix->Strings[i];
	}
	  /*	// building the result form
	Form2->StringGrid1->RowCount = n;
	Form2->StringGrid1->ColCount = 1;
	Form2->StringGrid2->RowCount = n;
	Form2->StringGrid2->ColCount = 1;
	}
	 */
	 /*
	TRect Recto = StringGrid1->CellRect(StringGrid1->Col, StringGrid1->Row);
	//---------------------------------------------------------------------------
	int Left = StringGrid1-> Selection.Left;
		int Top = StringGrid1-> Selection.Top;
		ShowMessage ((String) Left + "" + (String) Top);

		StringGrid1->Rows [Top] ->Clear();
		StringGrid1->Rows [Top] ->Move(Top,StringGrid1->ColCount-1);
		*/
 ///////////////////////////////////////////////////////

	/*wchar_t szFileName[MAXFILE+4];
  int iFileHandle;
  int iLength;
  int count;
  if (SaveDialog1->Execute())
  {
	if (FileExists(SaveDialog1->FileName))
	{
	  _wfnsplit(SaveDialog1->FileName.w_str(), 0, 0, szFileName, 0);
	  wcscat(szFileName, L".BAK");

	  RenameFile(SaveDialog1->FileName, szFileName);
	}
	iFileHandle = FileCreate(SaveDialog1->FileName);
	// Write out the number of rows and columns in the grid.
	count = StringGrid1->ColCount;
	FileWrite(iFileHandle, &count, sizeof(count));
	count = StringGrid1->RowCount;
	FileWrite(iFileHandle, &count, sizeof(count));
	for (int x=0;x<StringGrid1->ColCount;x++)
	{
	  for (int y=0;y<StringGrid1->RowCount;y++)
	  {
		// Write out the length of each string, followed by the string itself.
		iLength = StringGrid1->Cells[x][y].Length()*sizeof(wchar_t);
		FileWrite(iFileHandle, (wchar_t *)&iLength, sizeof(iLength));
		FileWrite(iFileHandle, StringGrid1->Cells[x][y].w_str(), iLength);
	  }
	}
    FileClose(iFileHandle);
  }*/
  ////////////////////////////////////////////////////
   /*
   c = StrToInt(Form1->Edit1->Text);
	//ShowMessage (L"Succeeded");
	MessageDlg("The calculation roots of the equation has been set successfully!", mtInformation, TMsgDlgButtons() << mbOK, 0);
	StatusBar1-> Panels-> Items [0] -> Text = L" Accuracy set to "+Edit1->Text;   */

  //////////////////////////////////////////////////////
	   /*	for(int i = 0; i < n; i++)

		  // for (int j = 0; j < n; j++)
			 {
			   matrix->StrictDelimiter=true;
				matrix->Delimiter=' ';
				StringGrid2->Rows[i]->DelimitedText = StringGrid2->Cells[0][i]+ ' ' + matrix->Strings[i];
		   }
			  /* int a=StringGrid2->Selection.Left-StringGrid2->Selection.Right+(0);
	   //	if (StringGrid2->Selection.Left<StringGrid2->RowCount-1) {
		for (int i=StringGrid2->Selection.Left+1; i<StringGrid2->ColCount; i++)

			StringGrid2->Cols[a]=StringGrid2->Cols[i];
	   //	}


		for (int i = 0; i < n; i++) {
		  Form1->StringGrid2->ColCount--;
		}   */


	// building the result form
	//Form2->StringGrid1->RowCount = n;
   //	Form2->StringGrid1->ColCount = 1;

   ///////////////////////////////////////////////
   /*
	if(Button5->Enabled)
	switch (Application->MessageBox((L"Do you want to save?"),Application->Title.w_str(),
										MB_YESNO|MB_ICONQUESTION)) {

	case ID_NO:
	Button5Click(NULL);

	break;
	case ID_YES:
	return;
	} */
	////////////////////////////////////////////////
    /*
	   open_err = false;
	  ////////////////////////////////////////////////////////////////
	   for (i = 1; i <= n; i++)
		for (j = 1; j <= n+1; j++)
		 // B[i][j] = StrToFloat(Form1->StringGrid1->Cells[j-1][i-1]);
			if (StringGrid1->Cells[j][i] == "") {
				open_err = true;

				}
			  */


	  /*
	  else
	   {
		MessageDlg("Invalid matrix!", mtError, TMsgDlgButtons() << mbOK, 0);
		Button5->Enabled = false;
		//Button3->Enabled = false;
		Calculate1->Enabled = false;
		Save1->Enabled = false;
		StatusBar1-> Panels-> Items [0] -> Text = L" An error occured! Try another file. " ;
	  //	TForm1::Button4Click(Sender) ;
	   }
		 */
/////////////////////////////////////////////////////////


void __fastcall TForm1::PathmaArts1Click(TObject *Sender)
{
ShowMessage(L"This product is created by Pathma Kudagamana. All rights reserved. copyright © PathmaArts" ) ;

}
//---------------------------------------------------------------------------

