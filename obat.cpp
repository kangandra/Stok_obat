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

    if (!file.is_open()) {
        cout << "File tidak ditemukan, memulai dengan data kosong.\n";
        return 0; 
    }
    
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

}

void tampilkanObat(){

}

void cariObat(obat dataObat[], int total){
    int pilih ;

    if (total == 0)
    {
        cout << "Data pemain masih kosong!\n";
    }

    cout << "\n=== CARI OBAT ===" << endl;
    cout << "1. Cari berdasarkan kode obat" << endl;
    cout << "2. Cari berdasarkan nama obat" << endl;
    cout << "3. Cari berdasarkan stok" << endl;
    cout << "4. Cari berdasarkan harga" << endl;
    cout << pilih; cin >> pilih;

    switch (pilih)
    {
    case 1:
        
        break;
    
    default:
        break;
    }

}

void urutkanObat(){

}

void simpanData(obat db[], int total){
    ofstream file(file_obat, ios::trunc);
    for (int i = 0; i < total; i++)
    {
        file << db[i].kode << " " << db[i].nama << " " << db[i].stok << " " << db[i].harga << " " << db[i].expired << "\n";
    }
    file.close();
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
        case 3: cariObat(databaseObat, jumlah); break;
        case 4: urutkanObat(); break;
        case 5: simpanData(databaseObat, jumlah); break;
        default:
            cout << "Pilihan tidak valid!!!";
            break;
        }
    } while (pilihan != 5);
    
    return 0;
}