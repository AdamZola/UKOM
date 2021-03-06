//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include "frxClass.hpp"
#include "frxDBSet.hpp"
//---------------------------------------------------------------------------
class TFsis : public TForm
{
__published:	// IDE-managed Components
	TADOConnection *koneksi;
	TADOQuery *Qadmin;
	TADOQuery *Qsoal;
	TDataSource *DSmasterdata;
	TADOQuery *Qregister;
	TADOQuery *Qmasterdata;
	TDataSource *DSsoal;
	TDataSource *DSregister;
	TfrxDBDataset *frxDBDataset1;
	TfrxReport *frxReport1;
	TfrxDBDataset *frxDBDataset2;
	TDataSource *DataSource1;
	TADOQuery *Qwaktu;
private:	// User declarations
public:		// User declarations
	__fastcall TFsis(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFsis *Fsis;
//---------------------------------------------------------------------------
#endif
