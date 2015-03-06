//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <string>

#include "Unit3.h"
#include "Unit1.h"
#include "Unit2.h"
#include "Unit4.h"
String pelajaran;
int poin;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Panel14Click(TObject *Sender)
{
if(RadioGroup1->ItemIndex == -1){

	if (MessageBoxA(0,"Apakah anda yakin ingin melewati soal ini? \nJika iya, anda akan kehilangan kesempatan mendapatkan poin dari soal ini!","Melewati Soal", MB_ICONQUESTION | MB_YESNO)==mrYes){
        Fsis->Qmasterdata->Close();
		Fsis->Qmasterdata->SQL->Clear();
		Fsis->Qmasterdata->SQL->Add("select * from "+pelajaran+" where id="+Lsoalke->Caption+"");
		Fsis->Qmasterdata->Open();
		String soal = Fsis->Qmasterdata->FieldByName("soal")->AsString;

		Fsis->Qmasterdata->Close();
		Fsis->Qmasterdata->SQL->Clear();
		Fsis->Qmasterdata->SQL->Add("select * from masterdata");
		Fsis->Qmasterdata->Open();
		Fsis->Qmasterdata->Append();
		Fsis->Qmasterdata->FieldByName("id_user")->AsString = Fsis->Qregister->FieldByName("id")->AsString;
		Fsis->Qmasterdata->FieldByName("jawaban")->AsString = "-";
		Fsis->Qmasterdata->FieldByName("status")->AsString = "Tidak Dijawab";
		Fsis->Qmasterdata->FieldByName("kode_soal")->AsString = Lsoalke->Caption;
		Fsis->Qmasterdata->FieldByName("soal")->AsString = soal;
		Fsis->Qmasterdata->Post();

		int x=StrToInt(Lsoalke->Caption);
		int hasil=x+1;
		Lsoalke->Caption = IntToStr(hasil);

		Fsis->Qsoal->Close();
		Fsis->Qsoal->SQL->Clear();
		Fsis->Qsoal->SQL->Add("select*from "+pelajaran+" where id="+Lsoalke->Caption+"");
		Fsis->Qsoal->Open();

			if (Fsis->Qsoal->IsEmpty()) {
				Lsoalke->Caption = 0;
				MessageBoxA(0,"Kuis selesai, saatnya melihat hasil evaluasi anda","Selesai", MB_ICONINFORMATION | MB_OK);

				 Panel15->Visible = true;
				 Label22->Caption = poin;
				 Timer1->Enabled = false;
				 Panel13->Visible = true;
				 Panel11->Visible = false;
				}
	}

}

else {
String jawaban;

	Fsis->Qsoal->Close();
	Fsis->Qsoal->SQL->Clear();
	Fsis->Qsoal->SQL->Add("select * from "+pelajaran+" where id = '"+Lsoalke->Caption+"'");
	Fsis->Qsoal->Open();

if (RadioGroup1->ItemIndex == 0) {
	jawaban = 'a';
	}

if (RadioGroup1->ItemIndex == 1) {
	jawaban = 'b';
	}

if (RadioGroup1->ItemIndex == 2) {
	jawaban = 'c';
	}

if (RadioGroup1->ItemIndex == 3) {
	jawaban = 'd';
	}

if (RadioGroup1->ItemIndex == 4) {
	jawaban = 'e';
	}

if (Fsis->Qsoal->FieldByName("kunci_jawaban")->AsString == jawaban) {
		Fsis->Qmasterdata->Close();
		Fsis->Qmasterdata->SQL->Clear();
		Fsis->Qmasterdata->SQL->Add("select * from "+pelajaran+" where id="+Lsoalke->Caption+"");
		Fsis->Qmasterdata->Open();
		String soal = Fsis->Qmasterdata->FieldByName("soal")->AsString;


		Fsis->Qmasterdata->Close();
		Fsis->Qmasterdata->SQL->Clear();
		Fsis->Qmasterdata->SQL->Add("select * from masterdata");
		Fsis->Qmasterdata->Open();
		Fsis->Qmasterdata->Append();
		Fsis->Qmasterdata->FieldByName("id_user")->AsString = Fsis->Qregister->FieldByName("id")->AsString;
		Fsis->Qmasterdata->FieldByName("jawaban")->AsString = jawaban;
		Fsis->Qmasterdata->FieldByName("status")->AsString = "benar";
		Fsis->Qmasterdata->FieldByName("kode_soal")->AsString = Lsoalke->Caption;
		Fsis->Qmasterdata->FieldByName("soal")->AsString = soal;
		Fsis->Qmasterdata->Post();
		int benar;
		benar= 5;
		poin +=benar;

	}

	else {
		Fsis->Qmasterdata->Close();
		Fsis->Qmasterdata->SQL->Clear();
		Fsis->Qmasterdata->SQL->Add("select * from "+pelajaran+" where id="+Lsoalke->Caption+"");
		Fsis->Qmasterdata->Open();
		String soal = Fsis->Qmasterdata->FieldByName("soal")->AsString;

		Fsis->Qmasterdata->Close();
		Fsis->Qmasterdata->SQL->Clear();
		Fsis->Qmasterdata->SQL->Add("select * from masterdata");
		Fsis->Qmasterdata->Open();
		Fsis->Qmasterdata->Append();
		Fsis->Qmasterdata->FieldByName("id_user")->AsString = Fsis->Qregister->FieldByName("id")->AsString;
		Fsis->Qmasterdata->FieldByName("jawaban")->AsString = jawaban;
		Fsis->Qmasterdata->FieldByName("status")->AsString = "salah";
		Fsis->Qmasterdata->FieldByName("kode_soal")->AsString = Lsoalke->Caption;
		Fsis->Qmasterdata->FieldByName("soal")->AsString = soal;
		Fsis->Qmasterdata->Post();
		int salah;
		salah = -2;
		poin +=salah;
	}

	int x=StrToInt(Lsoalke->Caption);
	int hasil=x+1;
	Lsoalke->Caption = IntToStr(hasil);


	next:
		Fsis->Qsoal->Close();
		Fsis->Qsoal->SQL->Clear();
		Fsis->Qsoal->SQL->Add("select*from "+pelajaran+" where id="+Lsoalke->Caption+"");
		Fsis->Qsoal->Open();

		if (Fsis->Qsoal->IsEmpty()) {
			Timer1->Enabled = false;
			Lsoalke->Caption = 0;
			MessageBoxA(0,"Kuis selesai, saatnya melihat hasil evaluasi anda","Selesai", MB_ICONINFORMATION | MB_OK);

		   Panel15->Visible = true;
		   Label22->Caption = poin;
		   Timer1->Enabled = false;
		   Panel13->Visible = true;
		   Panel11->Visible = false;
		}

		else {
		Msoal->Text = Fsis->Qsoal->FieldByName("soal")->AsString;
		RadioGroup1->Items->Clear();
		RadioGroup1->Items->Add("A. "+Fsis->Qsoal->FieldByName("a")->AsString);
		RadioGroup1->Items->Add("B. "+Fsis->Qsoal->FieldByName("b")->AsString);
		RadioGroup1->Items->Add("C. "+Fsis->Qsoal->FieldByName("c")->AsString);
		RadioGroup1->Items->Add("D. "+Fsis->Qsoal->FieldByName("d")->AsString);
		RadioGroup1->Items->Add("E. "+Fsis->Qsoal->FieldByName("e")->AsString);
		}
		}

Edit2->Text = "move";
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Timer1Timer(TObject *Sender)
{
int a = StrToInt(Lwaktu->Caption.SubString(4,2));
int b = StrToInt(Lwaktu->Caption.SubString(0,2));
	if(a > 0){
		a-=1;
		if (b<10) {
		  Lwaktu->Caption = "0"+IntToStr(b)+":"+IntToStr(a);
		}

		else if (b>=10) {
		   Lwaktu->Caption = IntToStr(b)+":"+IntToStr(a);
			 }

	}
	else if(a == 0){
		if(b > 0){
			b= b-1;
			if (b<10) {
			Lwaktu->Caption = "0"+IntToStr(b)+":59";
			}

			else if (b>=10) {
			Lwaktu->Caption = IntToStr(b)+":59";
			 }
		}
	else if(b == 0){
	Timer1->Enabled = false;
	MessageBoxA (0, "Waktu pengerjaan kuis anda telah habis /n Kini saat nya melihat hasil evaluasinya","Informasi", MB_ICONINFORMATION | MB_OK);
	Panel15->Visible = true;
	Label22->Caption = poin;
	Timer1->Enabled = false;
	Panel13->Visible = true;
	Panel11->Visible = false;
   }
}

}
//---------------------------------------------------------------------------
void __fastcall TForm3::Timer2Timer(TObject *Sender)
{
if (Edit2->Text == "move") {
		 int a = (96-Msoal->Left)/15;
		 int b = (96-RadioGroup1->Left)/15;
		 int c = (Msoal->Left-0)/15;
		 int d = (RadioGroup1->Left-0)/15;

		 if (Msoal->Left<96) {
			 Msoal->Left++;
			 Msoal->Left+=a;
		 }

		 if (RadioGroup1->Left<96) {
			 RadioGroup1->Left++;
			 RadioGroup1->Left+=b;
		 }

			if (Msoal->Left == 96 && RadioGroup1->Left == 96) {

				 Msoal->Visible = false;
				 RadioGroup1->Visible = false;

			 }

				 if (Msoal->Visible == false && RadioGroup1->Visible == false) {

					Msoal->Left = 17;
					RadioGroup1->Left = 17;
				}

					 if (Msoal->Left == 17 && RadioGroup1->Left == 17) {

						 Msoal->Visible = true;
						 RadioGroup1->Visible = true;
						 Edit2->Text = "on";
					}


}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Panel12Click(TObject *Sender)
{
if (ComboBox1->Text == "") {
	MessageBoxA(0,"Anda harus memilih mata pelajaran terlebih dahulu", "Peringatan!", MB_ICONWARNING | MB_OK);
} else {
if (ComboBox1->Text == "Bahasa Indonesia") {
	pelajaran = "bindo";

} else if (ComboBox1->Text == "Bahasa Inggris") {
	pelajaran = "bing";
}   else if (ComboBox1->Text == "Matematika") {
	pelajaran = "mtk";
}

if (MessageBoxA(0,"Apakah anda yakin ingin memulai Ujian ini?","Question", MB_ICONQUESTION | MB_YESNO)==mrYes) {
Fsis->Qsoal->Close();
Fsis->Qsoal->SQL->Clear();
Fsis->Qsoal->SQL->Add("select * from "+pelajaran+" ORDER BY id");
Fsis->Qsoal->Open();

Ljumlahsoal->Caption = Fsis->Qsoal->RecordCount;



	int x=StrToInt(Lsoalke->Caption);
	int hasil=x+1;
	Lsoalke->Caption = IntToStr(hasil);

	next:
		Fsis->Qsoal->Close();
		Fsis->Qsoal->SQL->Clear();
		Fsis->Qsoal->SQL->Add("select*from "+pelajaran+" where id="+Lsoalke->Caption+"");
		Fsis->Qsoal->Open();

		Msoal->Text = Fsis->Qsoal->FieldByName("soal")->AsString;
		RadioGroup1->Items->Clear();
		RadioGroup1->Items->Add("A. "+Fsis->Qsoal->FieldByName("a")->AsString);
		RadioGroup1->Items->Add("B. "+Fsis->Qsoal->FieldByName("b")->AsString);
		RadioGroup1->Items->Add("C. "+Fsis->Qsoal->FieldByName("c")->AsString);
		RadioGroup1->Items->Add("D. "+Fsis->Qsoal->FieldByName("d")->AsString);
		RadioGroup1->Items->Add("E. "+Fsis->Qsoal->FieldByName("e")->AsString);

Lwaktu->Caption = Fsis->Qwaktu->FieldByName("waktu")->AsString;
Timer1->Enabled = true;
Panel13->Visible = true;
Panel11->Visible = false;
Panel15->Visible = false;
}
}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ComboBox1KeyPress(TObject *Sender, System::WideChar &Key)

{
std::string str = "";
	if ( str.find(Key) == std::string::npos && Key !=VK_BACK) {
		Key =0;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormShow(TObject *Sender)
{
Edit2->SetFocus();
Panel13->Visible = false;
Panel11->Visible = true;
Panel15->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Shape1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
Shape1->Brush->Color = 0x00FEAA19;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Shape1MouseLeave(TObject *Sender)
{
Shape1->Brush->Color = clWhite;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Shape1ContextPopup(TObject *Sender, TPoint &MousePos, bool &Handled)
{
if (MessageBoxA(0,"Apakah anda yakin ingin keluar(log out)?","Keluar", MB_ICONQUESTION | MB_YESNO)==mrYes) {
Form1->Show();
Form3->Hide();
}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormClose(TObject *Sender, TCloseAction &Action)
{
if (Timer1->Enabled == true) {
	MessageBoxA(0, "Anda tidak dapat keluar saat kuis sedang berjalan!", "Warning", MB_ICONWARNING | MB_OK);
	Application->Run();
} else {
if (MessageBoxA(0,"Apakah anda yakin ingin keluar(log out)?","Keluar", MB_ICONQUESTION | MB_YESNO)==mrYes) {
Fsis->Qmasterdata->Close();
Fsis->Qmasterdata->SQL->Clear();
Fsis->Qmasterdata->SQL->Add("delete from masterdata");
Fsis->Qmasterdata->ExecSQL();
Form1->Show();
Form3->Hide();
poin = 0;
}
}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Label17MouseLeave(TObject *Sender)
{
Shape1->Brush->Color = clWhite;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Label17MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
Shape1->Brush->Color = 0x00FEAA19;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Label17Click(TObject *Sender)
{
if (MessageBoxA(0,"Apakah anda yakin ingin keluar(log out)?","Keluar", MB_ICONQUESTION | MB_YESNO)==mrYes) {
Form1->Show();
Form3->Hide();
}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Panel3Click(TObject *Sender)
{
Fsis->frxReport1->PrepareReport();
Fsis->frxReport1->ShowReport();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Panel2Click(TObject *Sender)
{
Fsis->Qmasterdata->Close();
Fsis->Qmasterdata->SQL->Clear();
Fsis->Qmasterdata->SQL->Add("delete from masterdata");
Fsis->Qmasterdata->ExecSQL();
Edit2->SetFocus();
Panel13->Visible = false;
Panel11->Visible = true;
Panel15->Visible = false;
poin = 0;
}
//---------------------------------------------------------------------------

