//latihan soal live coding SDA Teori
//Hospital System
// Store patient data	struct / class done
// Manage list of patients dynamically	Linked List
// Search patient by ID/name	Searching done
// Sort patients by age/priority	Sorting done
// Emergency waiting line	Queue
// Undo latest action/history	Stack
// Recursive menu or recursive traversal	Recursive done
// Store temporary data	Array done
// Dynamic memory allocation	Pointer done
// Main program design	OOP done

#include <iostream>
#include <string>
using namespace std;

class Patient{
    public:
    int id;
    string name;
    int age;
    string disease;

    void tampilkanInfo(){
        cout << "=====Data Pasien=====" << endl;
        cout << "ID: " << id << endl;
        cout << "Nama: " << name << endl;
        cout << "Umur: " << age << endl;
        cout << "Penyakit: " << disease << endl;
        cout << endl;
    }
};

void insertionSort(Patient* DataPasien, int n, int sortBy){
    for(int i = 1; i < n; i++){
        Patient temp = DataPasien[i];
        int j = i - 1;

        if(sortBy == 1){ // sort by name
            while(j >= 0 && DataPasien[j].name > temp.name){ 
                DataPasien[j+1] = DataPasien[j];
                j--;
            }
        } else { // sort by age
            while(j >= 0 && DataPasien[j].age > temp.age){
                DataPasien[j+1] = DataPasien[j];
                j--;
            }
        }
        DataPasien[j+1] = temp;
    }
    cout << "Data berhasil diurutkan!" << endl;
}

void menu(Patient* DataPasien, int n){
    cout << "\n====MENU====" << endl;
    cout << "(1) Tampilkan semua pasien" << endl;
    cout << "(2) Cari pasien" << endl;
    cout << "(3) Urutkan data pasien" << endl;
    cout << "(0) Keluar" << endl;
    cout << "Pilihan: ";
    cout << "\n============" << endl;

    int pilihan;
    cin >> pilihan;

    if(pilihan == 0){
        cout << "Keluar..." << endl;
        return;
    } else if(pilihan == 1){
        for(int i = 0; i < n; i++){
            DataPasien[i].tampilkanInfo();
        }
    } else if(pilihan == 2){
        cout << "Cari berdasarkan (1) ID atau (2) Nama: ";
        int choice;
        cin >> choice;

        if(choice == 1){
            cout << "Masukkan ID: ";
            int cariid;
            cin >> cariid;

            bool found = false;
            for(int i = 0; i < n; i++){
                if(DataPasien[i].id == cariid){
                    cout << "Pasien ditemukan!" << endl;
                    DataPasien[i].tampilkanInfo();
                    found = true;
                    break;
                }
            }
            if(!found) cout << "Pasien tidak ditemukan." << endl; 

        } else if(choice == 2){
            cout << "Masukkan nama: ";
            cin.ignore();
            string carinama;
            getline(cin, carinama);

            bool found = false;
            for(int i = 0; i < n; i++){
                if(DataPasien[i].name == carinama){
                    cout << "Pasien ditemukan!" << endl;
                    DataPasien[i].tampilkanInfo();
                    found = true;
                    break;
                }
            }
            if(!found) cout << "Pasien tidak ditemukan." << endl;

        } else {
            cout << "Pilihan tidak valid!" << endl;
        }
    } else if(pilihan == 3){ 
        cout << "Urutkan berdasarkan (1) Nama atau (2) Umur: ";
        int sortBy;
        cin >> sortBy;

        if(sortBy == 1 || sortBy == 2){
            insertionSort(DataPasien, n, sortBy);
            for(int i = 0; i < n; i++){
                DataPasien[i].tampilkanInfo();
            }
        } else {
            cout << "Pilihan tidak valid!" << endl;
        }
    } else {
        cout << "Pilihan tidak valid!" << endl;
    }

    menu(DataPasien, n);
}

int main(){
    int n;
    cout << "Masukkan jumlah pasien: ";
    cin >> n;

    Patient* DataPasien = new Patient[n];
    Patient* ptr = DataPasien;

    for(int i = 0; i < n; i++){
        cout << "\nPasien ke-" << i+1 << endl;
        cout << "Alamat memori: " << ptr << endl;

        cout << "Masukkan ID: ";
        cin >> DataPasien[i].id;
        cin.ignore();

        cout << "Masukkan nama: ";
        getline(cin, DataPasien[i].name);

        cout << "Masukkan umur: ";
        cin >> DataPasien[i].age;
        cin.ignore();

        if(DataPasien[i].age < 0){
            cout << "Umur tidak valid!" << endl;
            i--;
            continue;
        }

        cout << "Masukkan penyakit: ";
        getline(cin, DataPasien[i].disease);

        ptr->tampilkanInfo();
        ptr++;

        cout << endl;
    }

    menu(DataPasien, n);

    delete[] DataPasien;
}
