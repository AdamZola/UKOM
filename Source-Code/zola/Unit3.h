//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel11;
	TShape *Shape4;
	TShape *Shape2;
	TShape *Shape1;
	TShape *Shape3;
	TPanel *Panel4;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TComboBox *ComboBox1;
	TPanel *Panel12;
	TPanel *Panel13;
	TLabel *Label9;
	TLabel *Lwaktu;
	TLabel *Label11;
	TShape *Shape5;
	TShape *Shape6;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Lsoalke;
	TLabel *Label14;
	TLabel *Ljumlahsoal;
	TMemo *Msoal;
	TRadioGroup *RadioGroup1;
	TPanel *Panel14;
	TPanel *Panel15;
	TLabel *Label22;
	TfrxDBDataset *frxDBDataset1;
	TfrxReport *frxReport1;
	TTimer *Timer1;
	TTimer *Timer2;
	TEdit *Edit2;
	TDBGrid *DBGrid1;
	TPanel *Panel1;
	TLabel *Label1;
	TPanel *Panel3;
	TLabel *Label8;
	TLabel *Label10;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label17;
	TShape *Shape7;
	TShape *Shape8;
	TShape *Shape9;
	TShape *Shape10;
	TLabel *Label18;
	TPanel *Panel2;
	void __fastcall Panel14Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall Panel12Click(TObject *Sender);
	void __fastcall ComboBox1KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Shape1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Shape1MouseLeave(TObject *Sender);
	void __fastcall Shape1ContextPopup(TObject *Sender, TPoint &MousePos, bool &Handled);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Label17MouseLeave(TObject *Sender);
	void __fastcall Label17MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Label17Click(TObject *Sender);
	void __fastcall Panel3Click(TObject *Sender);
	void __fastcall Panel2Click(TObject *Sender);



private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
