//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <string>

#include "Unit2.h"
#include "Unit1.h"
#include "Unit3.h"
#include "Unit4.h"
String pelajaran, iduser;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cspin"
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
if (MessageBoxA(0,"Apakah anda yakin ingin keluar(log out)?","Keluar", MB_ICONQUESTION | MB_YESNO)==mrYes) {
Form1->Show();
Form2->Hide();
}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Label1Click(TObject *Sender)
{
Panel12->Visible = false;
Panel3->Visible = true;
Panel7->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ComboBox1Change(TObject *Sender)
{
if (ComboBox1->Text == "Bahasa Indonesia") {
	pelajaran = "bindo";

} else if (ComboBox1->Text == "Bahasa Inggris") {
	pelajaran = "bing";
}   else if (ComboBox1->Text == "Matematika") {
	pelajaran = "mtk";
}


	Fsis->Qsoal->Close();
	Fsis->Qsoal->SQL->Clear();
	Fsis->Qsoal->SQL->Add("select*from "+pelajaran+"");
	Fsis->Qsoal->Open();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Label2Click(TObject *Sender)
{
Panel12->Visible = false;
Panel7->Visible = true;
Panel3->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::DBGrid1CellClick(TColumn *Column)
{
Esoalke->Text = Fsis->Qsoal->FieldByName("id")->AsString;
Msoal->Text = Fsis->Qsoal->FieldByName("soal")->AsString;
A->Text = Fsis->Qsoal->FieldByName("a")->AsString;
B->Text = Fsis->Qsoal->FieldByName("b")->AsString;
C->Text = Fsis->Qsoal->FieldByName("c")->AsString;
D->Text = Fsis->Qsoal->FieldByName("d")->AsString;
E->Text = Fsis->Qsoal->FieldByName("e")->AsString;
ComboBox2->Text = Fsis->Qsoal->FieldByName("kunci_jawaban")->AsString;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Panel4Click(TObject *Sender)
{
if (Fsis->Qsoal->FieldByName("id")->AsString==Esoalke->Text) {
	MessageBoxA(0,"Kode soal yang dimasukan telah ada \n Klik perbarui soal jika ingin mengubah soal yang ada","Peringatan", MB_ICONWARNING | MB_OK);
}

else if (Esoalke->Text == "" && Msoal->Text == "" && A->Text == "" && B->Text == "" && C->Text == "" && D->Text == "" && E->Text == ""){
	MessageBoxA(0,"Isi kan semua kolom yang ada dengan lengkap","Peringatan", MB_ICONWARNING | MB_OK);

}

else {
Fsis->Qsoal->Close();
Fsis->Qsoal->SQL->Clear();
Fsis->Qsoal->SQL->Add("select*from "+pelajaran+"");
Fsis->Qsoal->Open();
Fsis->Qsoal->Append();
Fsis->Qsoal->FieldByName("id")->AsString = Esoalke->Text;
Fsis->Qsoal->FieldByName("soal")->AsString = Msoal->Text;
Fsis->Qsoal->FieldByName("a")->AsString = A->Text;
Fsis->Qsoal->FieldByName("b")->AsString = B->Text;
Fsis->Qsoal->FieldByName("c")->AsString = C->Text;
Fsis->Qsoal->FieldByName("d")->AsString = D->Text;
Fsis->Qsoal->FieldByName("e")->AsString = E->Text;
Fsis->Qsoal->FieldByName("kunci_jawaban")->AsString = ComboBox2->Text;
Fsis->Qsoal->Post();
MessageBoxA(0,"Anda berhasil menambahkan soal baru","Informasi", MB_ICONINFORMATION | MB_OK);
Fsis->Qsoal->Close();
Fsis->Qsoal->SQL->Clear();
Fsis->Qsoal->SQL->Add("select*from "+pelajaran+"");
Fsis->Qsoal->Open();
Esoalke->Clear();
Msoal->Clear();
A->Clear();
B->Clear();
C->Clear();
D->Clear();
E->Clear();
ComboBox2->Text = "";
}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Panel5Click(TObject *Sender)
{
if (Esoalke->Text == Fsis->Qsoal->FieldByName("id")->AsString &&
	Msoal->Text == Fsis->Qsoal->FieldByName("soal")->AsString &&
	A->Text == Fsis->Qsoal->FieldByName("a")->AsString &&
	B->Text == Fsis->Qsoal->FieldByName("b")->AsString &&
	C->Text == Fsis->Qsoal->FieldByName("c")->AsString &&
	D->Text == Fsis->Qsoal->FieldByName("d")->AsString &&
	E->Text == Fsis->Qsoal->FieldByName("e")->AsString &&
	ComboBox2->Text == Fsis->Qsoal->FieldByName("kunci_jawaban")->AsString)
	{
	MessageBoxA(0,"Anda belum mengubah soal","Informasi", MB_ICONWARNING | MB_OK);
}

else {

Fsis->Qsoal->Close();
Fsis->Qsoal->SQL->Clear();
Fsis->Qsoal->SQL->Add("select*from "+pelajaran+" where id='"+Esoalke->Text+"'");
Fsis->Qsoal->Open();
Fsis->Qsoal->Edit();
Fsis->Qsoal->FieldByName("id")->AsString = Esoalke->Text;
Fsis->Qsoal->FieldByName("soal")->AsString = Msoal->Text;
Fsis->Qsoal->FieldByName("a")->AsString = A->Text;
Fsis->Qsoal->FieldByName("b")->AsString = B->Text;
Fsis->Qsoal->FieldByName("c")->AsString = C->Text;
Fsis->Qsoal->FieldByName("d")->AsString = D->Text;
Fsis->Qsoal->FieldByName("e")->AsString = E->Text;
Fsis->Qsoal->FieldByName("kunci_jawaban")->AsString = ComboBox2->Text;
Fsis->Qsoal->Post();
MessageBoxA(0,"Anda berhasil mengubah soal","Informasi", MB_ICONINFORMATION | MB_OK);
Fsis->Qsoal->Close();
Fsis->Qsoal->SQL->Clear();
Fsis->Qsoal->SQL->Add("select*from "+pelajaran+"");
Fsis->Qsoal->Open();
Esoalke->Clear();
Msoal->Clear();
A->Clear();
B->Clear();
C->Clear();
D->Clear();
E->Clear();
ComboBox2->Text = "";
}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Panel6Click(TObject *Sender)
{
Fsis->Qsoal->Close();
Fsis->Qsoal->SQL->Clear();
Fsis->Qsoal->SQL->Add("delete from "+pelajaran+" where id='"+Esoalke->Text+"'");
Fsis->Qsoal->ExecSQL();
MessageBoxA(0,"Anda berhasil menghapus soal","Informasi", MB_ICONINFORMATION | MB_OK);
Fsis->Qsoal->Close();
Fsis->Qsoal->SQL->Clear();
Fsis->Qsoal->SQL->Add("select*from "+pelajaran+"");
Fsis->Qsoal->Open();
Esoalke->Clear();
Msoal->Clear();
A->Clear();
B->Clear();
C->Clear();
D->Clear();
E->Clear();
ComboBox2->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ComboBox2KeyPress(TObject *Sender, System::WideChar &Key)

{
std::string str = "";
	if ( str.find(Key) == std::string::npos && Key !=VK_BACK) {
		Key =0;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Panel10Click(TObject *Sender)
{
if (Euser->Text == "" && Epwd->Text == "" && Eemail->Text == "" && cbjk->Text == ""){
	MessageBoxA(0,"Isi kan semua kolom yang ada dengan lengkap","Peringatan", MB_ICONWARNING | MB_OK);

}

else {
Fsis->Qregister->Close();
Fsis->Qregister->SQL->Clear();
Fsis->Qregister->SQL->Add("select*from register");
Fsis->Qregister->Open();
Fsis->Qregister->Append();
Fsis->Qregister->FieldByName("username")->AsString = Euser->Text;
Fsis->Qregister->FieldByName("password")->AsString = Epwd->Text;
Fsis->Qregister->FieldByName("email")->AsString = Eemail->Text;
Fsis->Qregister->FieldByName("jenis_kelamin")->AsString = cbjk->Text;
Fsis->Qregister->Post();
MessageBoxA(0,"Anda berhasil menambah","Informasi", MB_ICONINFORMATION | MB_OK);
Fsis->Qregister->Close();
Fsis->Qregister->SQL->Clear();
Fsis->Qregister->SQL->Add("select*from register");
Fsis->Qregister->Open();
Euser->Clear();
Epwd->Clear();
Eemail->Clear();
cbjk->Text = "";
}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Panel9Click(TObject *Sender)
{
if (Euser->Text == Fsis->Qregister->FieldByName("username")->AsString &&
	Epwd->Text == Fsis->Qregister->FieldByName("password")->AsString &&
	Eemail->Text == Fsis->Qregister->FieldByName("email")->AsString &&
	cbjk->Text == Fsis->Qregister->FieldByName("jenis_kelamin")->AsString )
	{
	MessageBoxA(0,"Anda belum mengubah","Informasi", MB_ICONWARNING | MB_OK);
}

else {

Fsis->Qregister->Close();
Fsis->Qregister->SQL->Clear();
Fsis->Qregister->SQL->Add("select*from register where id = '"+iduser+"'");
Fsis->Qregister->Open();
Fsis->Qregister->Edit();
Fsis->Qregister->FieldByName("username")->AsString = Euser->Text;
Fsis->Qregister->FieldByName("password")->AsString = Epwd->Text;
Fsis->Qregister->FieldByName("email")->AsString = Eemail->Text;
Fsis->Qregister->FieldByName("jenis_kelamin")->AsString = cbjk->Text;
Fsis->Qregister->Post();
MessageBoxA(0,"Anda berhasil mengubah","Informasi", MB_ICONINFORMATION | MB_OK);
Fsis->Qregister->Close();
Fsis->Qregister->SQL->Clear();
Fsis->Qregister->SQL->Add("select*from register");
Fsis->Qregister->Open();
Euser->Clear();
Epwd->Clear();
Eemail->Clear();
cbjk->Text = "";
}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Panel11Click(TObject *Sender)
{
Fsis->Qsoal->Close();
Fsis->Qsoal->SQL->Clear();
Fsis->Qsoal->SQL->Add("delete from register where id='"+iduser+"'");
Fsis->Qsoal->ExecSQL();
MessageBoxA(0,"Anda berhasil menghapus data","Informasi", MB_ICONINFORMATION | MB_OK);
Fsis->Qregister->Close();
Fsis->Qregister->SQL->Clear();
Fsis->Qregister->SQL->Add("select*from register");
Fsis->Qregister->Open();
Euser->Clear();
Epwd->Clear();
Eemail->Clear();
cbjk->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm2::DBGrid2CellClick(TColumn *Column)
{
iduser = Fsis->Qregister->FieldByName("id")->AsString;
Euser->Text = Fsis->Qregister->FieldByName("username")->AsString;
Epwd->Text = Fsis->Qregister->FieldByName("password")->AsString;
cbjk->Text = Fsis->Qregister->FieldByName("jenis_kelamin")->AsString;
Eemail->Text = Fsis->Qregister->FieldByName("email")->AsString;
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Panel13Click(TObject *Sender)
{
Fsis->Qwaktu->Close();
Fsis->Qwaktu->SQL->Clear();
Fsis->Qwaktu->SQL->Add("select * from waktu");
Fsis->Qwaktu->Open();
if (Fsis->Qwaktu->FieldByName("waktu")->AsString == CSpinEdit1->Text + ":" + CSpinEdit2->Text) {

} else {
Fsis->Qwaktu->Edit();
Fsis->Qwaktu->FieldByName("waktu")->AsString = CSpinEdit1->Text + ":" + CSpinEdit2->Text;
Fsis->Qwaktu->Post();
MessageBoxA(0, "Anda berhasil mengubah waktu ujian!","Informasi", MB_ICONINFORMATION | MB_OK);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Label23Click(TObject *Sender)
{
Panel7->Visible = false;
Panel3->Visible = false;
Panel12->Visible = true;

Fsis->Qwaktu->Close();
Fsis->Qwaktu->SQL->Clear();
Fsis->Qwaktu->SQL->Add("select * from waktu");
Fsis->Qwaktu->Open();
Label22->Caption = Fsis->Qwaktu->FieldByName("waktu")->AsString;
CSpinEdit1->Text = Label22->Caption.SubString(0,2);
CSpinEdit2->Text = Label22->Caption.SubString(4,2);
}
//---------------------------------------------------------------------------

