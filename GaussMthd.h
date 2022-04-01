//---------------------------------------------------------------------------

#ifndef GaussMthdH
#define GaussMthdH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Dialogs.hpp>

#include "NumEqu.h"
#include <Vcl.ExtCtrls.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ActnCtrls.hpp>
#include <Vcl.ActnMan.hpp>
#include <Vcl.ActnMenus.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.Menus.hpp>

#define Max 20
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TPanel *Panel2;
	TPanel *Panel1;
	TLabel *Label4;
	TStringGrid *StringGrid2;
	TStringGrid *StringGrid1;
	TPanel *Panel4;
	TSplitter *Splitter1;
	TLabel *Label2;
	TLabel *Label5;
	TEdit *Edit1;
	TButton *Button4;
	TButton *Button5;
	TButton *Button3;
	TButton *Button1;
	TImage *Image1;
	TLabel *Label1;
	TStatusBar *StatusBar1;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *Edit2;
	TMenuItem *About1;
	TMenuItem *New1;
	TMenuItem *Open1;
	TMenuItem *Save1;
	TMenuItem *Saveas1;
	TMenuItem *Calculate1;
	TMenuItem *Exit1;
	TButton *Button6;
	TMenuItem *N2;
	TMenuItem *AboutProgram1;
	TMenuItem *PathmaArts1;
	TMenuItem *N3;
	TButton *Button2;
	TSaveDialog *SaveDialog2;
	TMenuItem *CleanAll1;
	TMenuItem *N4;
	TMenuItem *Edit3;
	TMenuItem *Addequation1;
	TMenuItem *Deleteequation1;
	TMenuItem *N5;
	TMenuItem *Save2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall New1Click(TObject *Sender);
	void __fastcall Open1Click(TObject *Sender);
	void __fastcall Save1Click(TObject *Sender);
	void __fastcall Saveas1Click(TObject *Sender);
	void __fastcall Exit1Click(TObject *Sender);
	void __fastcall Calculate1Click(TObject *Sender);
	void __fastcall StringGrid1GetEditText(TObject *Sender, int ACol, int ARow, UnicodeString &Value);
	void __fastcall StringGrid1KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall CleanAll1Click(TObject *Sender);
	void __fastcall AboutProgram1Click(TObject *Sender);
	void __fastcall Addequation1Click(TObject *Sender);
	void __fastcall Deleteequation1Click(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
	void __fastcall StringGrid1SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall Save2Click(TObject *Sender);
	void __fastcall PathmaArts1Click(TObject *Sender);



private:	// User declarations
	 int n;
     int c;
	 float A[Max][Max+1]; // matrix of coefficients
	 float X[Max]; // array of solutions
	 bool f_not; // true - system not determined
	 //float B[Max][Max+1];
	 bool open_err;  //true - open a file with emty cell
	 bool save_as;   //true - Save As not clicked

public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	int Calc(void);


};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
