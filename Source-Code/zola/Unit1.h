//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel5;
	TLabel *Label32;
	TLabel *Label1;
	TLabel *Label2;
	TPanel *Panel6;
	TImage *Image2;
	TPanel *Panel2;
	TPanel *Panel7;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TPanel *Panel4;
	TLabel *Label5;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *Edit6;
	TEdit *Edit7;
	TEdit *Edit8;
	TComboBox *ComboBox1;
	TPanel *Panel8;
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label6;
	TLabel *Label7;
	void __fastcall Panel8Click(TObject *Sender);
	void __fastcall Label4Click(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall CheckBox2Click(TObject *Sender);
	void __fastcall CheckBox3Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Panel7Click(TObject *Sender);
	void __fastcall Label2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
