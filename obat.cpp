#include <iostream>
#include <fstream>

using namespace std;

struct obat
{
    string kode;
    string nama;
    int stok;
    float harga;
    string expired;
};

string file_obat = "data_obat.txt";
int MAX_OBAT = 100;


int muatData(obat ob[]){
    ifstream file(file_obat);
    int jumlah = 0;
    
    while (file >> ob[jumlah].kode >> ob[jumlah].nama >> ob[jumlah].stok >> ob[jumlah].harga >> ob[jumlah].expired)
    {
        jumlah++;
        if (jumlah >= MAX_OBAT)
        {
            break;
        }   
    }
    file.close();
    return jumlah;
}

void tambahObat(obat dataObat[], int &totalObat){
    if (totalObat >= MAX_OBAT)
    {
        cout << "Kapasitas penyimpanan penuh!!\n";
        return;
    }

    cout << "\n-- Tambah Obat Baru --" << endl;
    int jumlah;
    cout << "Jumlah obat : "; cin >> jumlah; cin.ignore();
    
    for (int i = 0; i < jumlah; i++)
    {
        cout << "Data obat ke-" << (i+1) << endl;
        cout << "Kode obat\t: "; getline(cin, dataObat[i].kode);
        cout << "Nama obat\t: "; getline(cin, dataObat[i].nama);
        cout << "Stok obat\t: "; cin >> dataObat[i].stok;
        cout << "Harga obat\t: "; cin >> dataObat[i].harga;
        cout << "Expired\t: "; getline(cin, dataObat[i].expired);
    }
    cout << "Data berhasil ditambahkan\n";
}

void tampilkanObat(){

}

void cariObat(){

}

void urutkanObat(){

}

void simpanData(){

}

int main (){
    obat databaseObat[MAX_OBAT];
    muatData(databaseObat);
    int jumlah = muatData(databaseObat);

    int pilihan;
    do
    {
        cout << "\n=== SISTEM MANAJEMEN STOK APOTEK ===" << endl;
        cout << "1. Tambah Data Obat" << endl;
        cout << "2. Tampilkan Semua Obat" << endl;
        cout << "3. Cari Obat (Searching)" << endl;
        cout << "4. Urutkan Obat (Sorting)" << endl;
        cout << "5. Simpan Data & Keluar" << endl;
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan)
        {
        case 1: tambahObat(databaseObat, jumlah); break;
        case 2: tampilkanObat(); break;
        case 3: cariObat(); break;
        case 4: urutkanObat(); break;
        case 5: simpanData(); break;
        default:
            cout << "Pilihan tidak valid!!!";
            break;
        }
    } while (pilihan != 5);
    
    return 0;
}