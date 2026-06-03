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


void simpanData(obat db[], int total){
    ofstream file(file_obat, ios::trunc);
    for (int i = 0; i < total; i++)
    {
        file << db[i].kode << " " << db[i].nama << " " << db[i].stok << " " << db[i].harga << " " << db[i].expired << "\n";
    }
    file.close();
}


void tambahObat(obat dataObat[], int &totalObat){
    if(totalObat >= MAX_OBAT){
        cout << "[ERROR] Database pemain penuh!\n";
        return;
    }

    cout << "\n=== TAMBAH DATA OBAT BARU ===" << endl;

    cout << "Masukkan kode obat : "; getline(cin, dataObat[totalObat].kode);
    cout << "Masukkan nama obat : "; getline(cin, dataObat[totalObat].nama);
    cout << "Masukkan stok obat : "; cin >> dataObat[totalObat].stok;
    cout << "Masukkan harga obat : "; cin >> dataObat[totalObat].harga;
    cout << "Masukkan tanggal expired : "; getline(cin, dataObat[totalObat].expired);

    totalObat++;
    simpanData(dataObat, totalObat);

    cout << "\n[SUKSES] Data pemain berhasil ditambahkan!" << endl;
}

void tampilkanObat(){

}

int cariKode(obat db[], int total, string kodeCari){
    int min = 0;
    int max = total - 1;

    while (min <= max)
    {
        int mid = (min + max) / 2;

        if (db [mid].kode == kodeCari)
        {
            return mid;
        } else if(kodeCari < db[mid].kode){
            max = mid - 1;
        }else{
            min = mid +1;
        }     
    }
    return -1;
}

void cariObat(obat dataObat[], int total){
    int pilih ;

    if (total == 0)
    {
        cout << "Data obat masih kosong!\n";
    }

    cout << "\n=== CARI OBAT ===" << endl;
    cout << "1. Cari berdasarkan kode obat" << endl;
    cout << "2. Cari berdasarkan nama obat" << endl;
    cout << pilih; cin >> pilih;

    switch (pilih)
    {
    case 1:{
        string kodeCari;
        // urutkanObat(dataObat, total);

        cout << "Masukkan kode obat : "; getline(cin, kodeCari);

        int hasil = cariKode(dataObat, total, kodeCari);
        if (hasil != -1)
        {
            tampilkanObat();
        }else{
            cout << "Data obat dengan kode tersebut tidak ditemukan!\n";
        }
        break;
    }
    case 2:{
        string namaCari;
        bool found = false;

        cout << "Masukkan nama obat : "; getline(cin, namaCari);

        for (int i = 0; i < total; i++)
        {
            if (dataObat[i].nama == namaCari)
            {
                //tampilkanObat(dataObat[i]);
                found = true;
            }         
        }
        if (!found)
        {
            cout << "Tidak ada obat yang sesuai dengan kriteria\n";
        }     
        break;}
    default:
        cout << "Pilihan tidak valid." << endl;
        break;
    }

}

void urutkanObat(){

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