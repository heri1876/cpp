/*
    Created by Heri Hermawan, Sabda Darmawan and Fathurrizqi on 2019-12-22
    Last edit by Heri Hermawan on 2020-01-16
*/

#include <conio.h>
#include <iostream>
#include <windows.h>

//Fungsi GOTOXY
void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

using namespace std;

//Inisialisasi variabel informasi mobil yang di sewa
string mobilSewa[99] , tipeMobilSewa[99], pemilikSewa[99], kontakSewa[99];
int jumlahKursi[99], hargaSewa[99];
//Varibel untuk menghitung panjang data yang ada di array
int lengthSewa = 0;

//Inisialisasi variabel informasi tagihan sewa mobil
string namaPenyewa[99], kontakPenyewa[99];
int kodePenyewa[99], lamaPenyewa[99];
//Varibel untuk menghitung panjang data yang ada di array
int lengthTagihan = 0;

//Inisialisasi Fungsi/function
void sewa(int y);
void out();
void historiPesanan();
void tampilSemuaData();
void menyewakan();

//Fungsi Main
int main() { 
    
    //Memberikan nilai awal variabel
	mobilSewa[0] = "Daihatsu Xenia";
	tipeMobilSewa[0] = "Mini MPV";
	hargaSewa[0] = 259000;
	jumlahKursi[0] = 6;
	pemilikSewa[0] = "Heri Hermawan";
    kontakSewa[0] = "085889088105";
	//
    mobilSewa[1] = "Suzuki Ertiga";
	tipeMobilSewa[1] = "Mini MPV";
	hargaSewa[1] = 288000;
	jumlahKursi[1] = 6;
	pemilikSewa[1] = "Fathurrizqi";
    kontakSewa[1] = "081384887859";
	//
    mobilSewa[2] = "Toyota Hiace";
	tipeMobilSewa[2] = "Mini Bus";
	hargaSewa[2] = 960000;
	jumlahKursi[2] = 13;
	pemilikSewa[2] = "Sabda Darmawan";
    kontakSewa[2] = "081383377262";
    lengthSewa = 3;

    menu:
    cout << "\t===================================================\n";
	cout << "\t|| Selamat Datang di Tempat Sewa & Rental Mobil  ||\n";
    cout << "\t===================================================\n";
    cout << "\n Silahkan pilih menu :";
    cout << "\n 1. Sewa Mobil (Menyewa mobil yang ada)";
    cout << "\n 2. Menyewakan Mobil (Menyewakan mobil yang anda miliki)";
    cout << "\n 3. Cek histori transaksi";
    cout << "\n 4. Keluar";
    cout << "\n Masukan angka menu yang di inginkan : ";
    int pilih;
    cin >>  pilih;

    //Menggunakan Switch, untuk melakukan pemilihan menu
    switch(pilih) {
        case 1:
            system ("cls");
            //Memanggil Fungsi tampilSemuaData()
            tampilSemuaData();
            system ("cls");
            goto menu;
            break;
        case 2:
            system ("cls");
            //Memanggil Fungsi Menyewakan()
            menyewakan();
            system ("cls");
            goto menu;
            break;
        case 3:
            system ("cls");
            //Memanggil Fungsi tampilSemuaTagihan()
            historiPesanan();
            system ("cls");
            goto menu;
            break;
        case 4:
            system ("cls");
            //Memanggil Fungsi out()
        	out();
            break;
        default :
            string pilih;
            cout << "\nAngka yang di masukan salah";
            cout << "\nKembali ke menu ? (Ya/Tidak)\n";
            cin >> pilih;
			// Menggunakan IF
            // "||" adalah Logical OR, apa bila salah satu kondisi benar(true) makan akan menghasilakan benar(true)
            if (pilih == "ya" || pilih == "Ya" || pilih == "y" || pilih == "Y") {	
                system ("cls");
                goto menu;
            } else if (pilih == "tidak" || pilih == "Tidak" || pilih == "t" || pilih == "T") {
            	system ("cls");
                //Memanggil Fungsi out()
            	out();
                break;                
            } else {
                cout << "Input salah";
                goto menu;
            }
    }
    getch();
    return 0;
}

//Fungsi sewa, untuk melakukan sewa mobil
void sewa(int y){
    refill:
    cout << "\n==================================================================================================\n";
    cout << "| No Mobil |      Mobil       | Lama menyewa |  Total Harga  |   Nama Penyewa   |  Kontak Penyewa  |\n";
    cout << "====================================================================================================\n";
    int kode, hari;
    string nama, kontakPenyewa;
    gotoxy(5, y+11); cin >> kode;
    gotoxy(13, y+11); cout << mobilSewa[kode-1];
    gotoxy(13, y+12); cout << tipeMobilSewa[kode-1];
    gotoxy(35, y+11); cin >> hari;
    gotoxy(37, y+11); cout << "hari";
    gotoxy(47, y+11); cout << "Rp " << (hargaSewa[kode-1]*hari)/1000 << ".000";
    gotoxy(63, y+11); cin.ignore(); getline(cin, nama);
    gotoxy(82, y+11); cin >> kontakPenyewa;
    
    cout << "\nData yang di masukan sudah benar ?  (Ya/Tidak)\n";
    confirm:
    string jawab;
    cin >> jawab;
	// Menggunakan IF
    // "||" adalah Logical OR, apa bila salah satu kondisi benar(true) makan akan menghasilakan benar(true)
    if (jawab == "ya" || jawab == "Ya" || jawab == "y" || jawab == "Y"){
        namaPenyewa[lengthTagihan] = nama;
        lamaPenyewa[lengthTagihan] = hari;
        kodePenyewa[lengthTagihan] = kode-1;
        lengthTagihan++;
    } else if (jawab == "tidak" || jawab == "Tidak" || jawab == "t" || jawab == "T") {
        system ("cls");
        goto refill;
    } else {
        cout << "Input salah, masukan ulang";
        goto confirm;
    }

    system ("cls");
    cout << "\t========================" << endl;
	cout << "\t|  Informasi Tagihan   |" << endl;
    cout << "\t========================\n" << endl;
    cout << "Mobil yang akan di sewa   : " << mobilSewa[kode-1] << " " << tipeMobilSewa[kode-1] << endl;
    cout << "Nama pemilik mobil        : " << pemilikSewa[kode-1] << endl;
    cout << "Nama penyewa              : " << nama << endl;
    cout << "Kontak pemilik mobil      : " << kontakSewa[kode-1] << endl;
    cout << "Kontak penyewa mobil      : " << kontakPenyewa << endl;
    cout << "Harga sewa per hari       : " << "Rp." << hargaSewa[kode-1]<< endl;
	cout << "Lama hari menyewa         : " << hari << " Hari" << endl;
    cout << "Total yang harus di bayar : " << "Rp." <<hargaSewa[kode-1] * hari << endl;
    getch();
}

//Fungsi untuk menampilkan pesan ketika keluar dari program
void out(){
    cout << "\t===================================" << endl;
	cout << "\t|| Terimakasih sudah berkunjung  ||" << endl;
    cout << "\t===================================" << endl;
}

//Fungsi tampilSemuaData, untuk menampilkan data mobil yang dapat di sewa ke tabel
void tampilSemuaData(){
    cout << "=============================================================================================================\n";
    cout << "| No |      Mobil       |   Tipe Mobil   |    Harga/hari    | Jumlah Kursi |    Kontak    |     Pemilik     |\n";
    cout << "=============================================================================================================\n";

    // Menggunakan FOR, untuk melakukan perulangan dalam menampilkan data ke tabel
    int i;
    for (i = 0; i < lengthSewa; i++ ){
        gotoxy(0, 3+i); cout << "| " << i+1;
		gotoxy(5, 3+i); cout << "| " << mobilSewa[i];
        gotoxy(24, 3+i); cout << "|  " << tipeMobilSewa[i];
        gotoxy(41, 3+i); cout << "|   Rp " << hargaSewa[i];
        gotoxy(60, 3+i); cout << "|      " << jumlahKursi[i];
        gotoxy(75, 3+i); cout << "| " << kontakSewa[i];
        gotoxy(90, 3+i); cout << "| " << pemilikSewa[i];
        gotoxy(108, 3+i); cout << "|\n";
    }
    cout << "===========================================================================================================\n";

    cout << "\nIngin menyewa mobil ? (Ya/Tidak)\n";
    string jawab;
    cin >> jawab;
	//Menggunakan IF
    // "||" adalah Logical OR, apa bila salah satu kondisi benar(true) makan akan menghasilakan benar(true)
    if (jawab == "ya" || jawab == "Ya" || jawab == "y" || jawab == "Y"){
        //Memanggil Fungsi sewa()
        sewa(i);
    }
}

//Fungsi menyewakan, untuk memasukan mobil yang dapat di sewakan ke tabel
void menyewakan(){

    string jawab;
    //Mengunakan DO WHILE, untuk melakukan perulangan dalam input data mobil
    do {
    cout << "                             Mohon isi data mobil dengan benar                                      \n";
    cout << "====================================================================================================\n";
    cout << "|  Nama Pemilik  |   Merk Mobil   |   Tipe Mobil   |   Harga Sewa  |  Jumlah Kursi  |    Kontak    |\n";
    cout << "====================================================================================================\n";

    //Karena input menggunakan spasi untuk menghindari error, maka menggunakan cin.ignore() dan getline()
    cin.ignore();
    gotoxy(2, 4); getline(cin, pemilikSewa[lengthSewa]);
    gotoxy(20, 4); getline(cin, mobilSewa[lengthSewa]);
    gotoxy(38, 4); getline(cin, tipeMobilSewa[lengthSewa]); 
    gotoxy(54, 4); cin >> hargaSewa[lengthSewa];
    gotoxy(75, 4); cin >> jumlahKursi[lengthSewa];
    gotoxy(86, 4); cin >> kontakSewa[lengthSewa];
	lengthSewa++;

    gotoxy(0, 7);
    cout << "Ingin menambahkan lagi data mobil yang ingin di sewakan ?  (Ya/Tidak)\n";
    cin >> jawab;
    system ("cls");

    // "||" adalah Logical OR, apa bila salah satu kondisi benar(true) makan akan menghasilakan benar(true)
    } while(jawab == "ya" || jawab == "Ya" || jawab == "y" || jawab == "Y");
    
    cout << "\t=============================" << endl;
	cout << "\t|| Data Berhasil di Input  ||" << endl;
    cout << "\t=============================" << endl;
    getch();
}

//Fungsi historiPesanan, untuk menampilkan daftar pesanan
void historiPesanan(){
    cout << "====================================================================================================\n";
	cout << "|                                                                                                  |\n";
	cout << "|                                         Histori Tagihan                                          |\n";
	cout << "|                                                                                                  |\n";
    cout << "| No |   Nama Penyewa    | Lama menyewa |    Nama Pemilik    |  Mobil yang disewa  |  Total Harga  |\n";
    cout << "====================================================================================================\n";
   
    int i = 0;
    // Menggunakan while, untuk melakukan perulangan dalam menampilkan data ke tabel
    while (i < lengthTagihan){
        gotoxy(2, 6+i); cout << i +1; 
        gotoxy(8, 6+i); cout << namaPenyewa[i];
        gotoxy(28, 6+i); cout << lamaPenyewa[i] << " Hari";
        gotoxy(44, 6+i); cout << pemilikSewa[kodePenyewa[i]];
        gotoxy(65, 6+i); cout << mobilSewa[kodePenyewa[i]];
        gotoxy(65, 7+i); cout << tipeMobilSewa[kodePenyewa[i]];
        gotoxy(86, 6+i); cout << lamaPenyewa[i] * hargaSewa[kodePenyewa[i]];
        i++;
    }

    // Menggunakan IF, untuk mengecek apakah sudah pernah melakukan pemesanan 
    if (lengthTagihan == 0) {
        cout << "\t \n Belum melakukan pesanan \n";
    } else {
        cout << "\n==============================================================================================\n";
    }
    gotoxy(1, 8+i);cout << "\nTekan tombol apa saja untuk kembali ke Menu awal";
    getch();
}
