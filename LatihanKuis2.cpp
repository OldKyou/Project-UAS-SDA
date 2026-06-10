// Hospital System - SDA Teori
// Store patient data          struct / class       done
// Manage list of patients     Linked List          done
// Search patient by ID/name   Searching            done
// Sort patients by age/name   Sorting              done
// Emergency waiting line      Queue                done
// Undo latest action/history  Stack                done
// Recursive menu              Recursive            done
// Store temporary data        Array                done
// Dynamic memory allocation   Pointer              done
// Main program design         OOP                  done

#include <iostream>
#include <string>
using namespace std;

// STRUCT / CLASS
class Patient {
public:
    int    id;
    string name;
    int    age;
    string disease;

    void tampilkanInfo() {
        cout << "=====Data Pasien=====" << endl;
        cout << "ID     : " << id      << endl;
        cout << "Nama   : " << name    << endl;
        cout << "Umur   : " << age     << endl;
        cout << "Penyakit: " << disease << endl;
        cout << endl;
    }
};

// LINKED LIST
struct Node {
    Patient data;
    Node*   next;
    Node(Patient p) : data(p), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    int   size;
public:
    LinkedList() : head(nullptr), size(0) {}

    ~LinkedList() {
        Node* cur = head;
        while (cur) { Node* tmp = cur->next; delete cur; cur = tmp; }
    }

    void tambahPasien(Patient p) {
        Node* newNode = new Node(p);
        if (!head) { head = newNode; }
        else {
            Node* cur = head;
            while (cur->next) cur = cur->next;
            cur->next = newNode;
        }
        size++;
        cout << "Pasien \"" << p.name << "\" berhasil ditambahkan ke linked list." << endl;
    }

    bool hapusPasienById(int id) {
        if (!head) return false;
        if (head->data.id == id) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
            size--;
            return true;
        }
        Node* cur = head;
        while (cur->next && cur->next->data.id != id) cur = cur->next;
        if (!cur->next) return false;
        Node* tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
        size--;
        return true;
    }

    void tampilkanSemua() {
        if (!head) { cout << "Linked list kosong." << endl; return; }
        Node* cur = head;
        int   no  = 1;
        while (cur) {
            cout << "[Node " << no++ << "] Alamat: " << cur << endl;
            cur->data.tampilkanInfo();
            cur = cur->next;
        }
    }

    Patient* toArray(int& outSize) {
        outSize      = size;
        if (size == 0) return nullptr;
        Patient* arr = new Patient[size];
        Node*    cur = head;
        for (int i = 0; i < size; i++) { arr[i] = cur->data; cur = cur->next; }
        return arr;
    }

    int getSize() { return size; }
    Node* getHead() { return head; }
};

// QUEUE
struct QNode {
    Patient data;
    QNode*  next;
    QNode(Patient p) : data(p), next(nullptr) {}
};

class EmergencyQueue {
private:
    QNode* front;
    QNode* rear;
    int    count;
public:
    EmergencyQueue() : front(nullptr), rear(nullptr), count(0) {}

    ~EmergencyQueue() {
        while (front) {
            QNode* tmp = front->next;
            delete front;
            front = tmp;
        }
    }

    void enqueue(Patient p) {
        QNode* newNode = new QNode(p);
        if (!rear) { front = rear = newNode; }
        else       { rear->next = newNode; rear = newNode; }
        count++;
        cout << "Pasien \"" << p.name << "\" masuk antrian darurat (posisi ke-" << count << ")." << endl;
    }

    void dequeue() {
        if (!front) { cout << "Antrian darurat kosong." << endl; return; }
        cout << "Pasien berikutnya yang ditangani:" << endl;
        front->data.tampilkanInfo();
        QNode* tmp = front;
        front = front->next;
        if (!front) rear = nullptr;
        delete tmp;
        count--;
    }

    void tampilkanAntrian() {
        if (!front) { cout << "Antrian darurat kosong." << endl; return; }
        cout << "===== Antrian Darurat (FIFO) =====" << endl;
        QNode* cur = front;
        int    no  = 1;
        while (cur) {
            cout << "Posisi " << no++ << ": " << cur->data.name
                 << " (ID: " << cur->data.id << ")" << endl;
            cur = cur->next;
        }
        cout << endl;
    }

    bool isEmpty() { return front == nullptr; }
};

// STACK
struct SNode {
    string  action;
    Patient patient;
    SNode*  next;
    SNode(string a, Patient p) : action(a), patient(p), next(nullptr) {}
};

class UndoStack {
private:
    SNode* top;
    int    count;
public:
    UndoStack() : top(nullptr), count(0) {}

    ~UndoStack() {
        while (top) { SNode* tmp = top->next; delete top; top = tmp; }
    }

    void push(string action, Patient p) {
        SNode* newNode = new SNode(action, p);
        newNode->next  = top;
        top   = newNode;
        count++;
        cout << "Aksi \"" << action << "\" disimpan ke riwayat." << endl;
    }

    void undo(LinkedList& list) {
        if (!top) { cout << "Tidak ada aksi yang bisa di-undo." << endl; return; }
        cout << "Undo aksi: \"" << top->action << "\" untuk pasien \"" << top->patient.name << "\"" << endl;
        if (top->action == "Tambah") {
            if (list.hapusPasienById(top->patient.id))
                cout << "Pasien berhasil dihapus dari linked list." << endl;
        } else if (top->action == "Hapus") {
            list.tambahPasien(top->patient);
            cout << "Pasien berhasil dikembalikan ke linked list." << endl;
        }
        SNode* tmp = top;
        top = top->next;
        delete tmp;
        count--;
    }

    void tampilkanRiwayat() {
        if (!top) { cout << "Riwayat kosong." << endl; return; }
        cout << "===== Riwayat Aksi (LIFO) =====" << endl;
        SNode* cur = top;
        int    no  = 1;
        while (cur) {
            cout << no++ << ". [" << cur->action << "] " << cur->patient.name
                 << " (ID: " << cur->patient.id << ")" << endl;
            cur = cur->next;
        }
        cout << endl;
    }
};

// SORTING
void insertionSort(Patient* arr, int n, int sortBy) {
    for (int i = 1; i < n; i++) {
        Patient temp = arr[i];
        int     j    = i - 1;
        if (sortBy == 1) {
            while (j >= 0 && arr[j].name > temp.name) { arr[j+1] = arr[j]; j--; }
        } else {
            while (j >= 0 && arr[j].age  > temp.age)  { arr[j+1] = arr[j]; j--; }
        }
        arr[j+1] = temp;
    }
    cout << "Data berhasil diurutkan!" << endl;
}

// RECURSIVE
   void menu(LinkedList& list, EmergencyQueue& queue, UndoStack& undoStack) {
    cout << "\n============ MENU ============" << endl;
    cout << "(1)  Tampilkan semua pasien (Linked List)" << endl;
    cout << "(2)  Cari pasien"                          << endl;
    cout << "(3)  Urutkan data pasien"                  << endl;
    cout << "(4)  Tambah pasien baru"                   << endl;
    cout << "(5)  Hapus pasien by ID"                   << endl;
    cout << "(6)  Antrian Darurat - tambah pasien"      << endl;
    cout << "(7)  Antrian Darurat - panggil berikutnya" << endl;
    cout << "(8)  Tampilkan antrian darurat"             << endl;
    cout << "(9)  Undo aksi terakhir"                   << endl;
    cout << "(10) Tampilkan riwayat aksi"               << endl;
    cout << "(0)  Keluar"                               << endl;
    cout << "==============================" << endl;
    cout << "Pilihan: ";

    int pilihan;
    cin >> pilihan;

    if (pilihan == 0) {
        cout << "Keluar..." << endl;
        return;

    } else if (pilihan == 1) {
        list.tampilkanSemua();

    } else if (pilihan == 2) {
        cout << "Cari berdasarkan (1) ID atau (2) Nama: ";
        int choice; cin >> choice;

        int size;
        Patient* arr = list.toArray(size);
        bool found   = false;

        if (choice == 1) {
            cout << "Masukkan ID: ";
            int cariid; cin >> cariid;
            for (int i = 0; i < size; i++) {
                if (arr[i].id == cariid) {
                    cout << "Pasien ditemukan!" << endl;
                    arr[i].tampilkanInfo(); found = true; break;
                }
            }
        } else if (choice == 2) {
            cout << "Masukkan nama: "; cin.ignore();
            string carinama; getline(cin, carinama);
            for (int i = 0; i < size; i++) {
                if (arr[i].name == carinama) {
                    cout << "Pasien ditemukan!" << endl;
                    arr[i].tampilkanInfo(); found = true; break;
                }
            }
        } else { cout << "Pilihan tidak valid!" << endl; }

        if (!found && (choice == 1 || choice == 2))
            cout << "Pasien tidak ditemukan." << endl;
        delete[] arr;

    } else if (pilihan == 3) {
        cout << "Urutkan berdasarkan (1) Nama atau (2) Umur: ";
        int sortBy; cin >> sortBy;
        int size;
        Patient* arr = list.toArray(size);
        if (arr && (sortBy == 1 || sortBy == 2)) {
            insertionSort(arr, size, sortBy);
            for (int i = 0; i < size; i++) arr[i].tampilkanInfo();
        } else { cout << "Pilihan tidak valid atau list kosong." << endl; }
        delete[] arr;

    } else if (pilihan == 4) {
        Patient p;
        cout << "Masukkan ID     : "; cin >> p.id;
        cin.ignore();
        cout << "Masukkan Nama   : "; getline(cin, p.name);
        cout << "Masukkan Umur   : "; cin >> p.age;
        if (p.age < 0) { cout << "Umur tidak valid!" << endl; }
        else {
            cin.ignore();
            cout << "Masukkan Penyakit: "; getline(cin, p.disease);
            list.tambahPasien(p);
            undoStack.push("Tambah", p);
        }

    } else if (pilihan == 5) {
        cout << "Masukkan ID pasien yang ingin dihapus: ";
        int delId; cin >> delId;
        int size;
        Patient* arr = list.toArray(size);
        Patient  found_p; bool found = false;
        for (int i = 0; i < size; i++) {
            if (arr[i].id == delId) { found_p = arr[i]; found = true; break; }
        }
        delete[] arr;
        if (found) {
            list.hapusPasienById(delId);
            cout << "Pasien berhasil dihapus." << endl;
            undoStack.push("Hapus", found_p);
        } else { cout << "Pasien tidak ditemukan." << endl; }

    } else if (pilihan == 6) {
        cout << "Masukkan ID pasien yang akan masuk antrian darurat: ";
        int qId; cin >> qId;
        int size;
        Patient* arr = list.toArray(size);
        bool found   = false;
        for (int i = 0; i < size; i++) {
            if (arr[i].id == qId) { queue.enqueue(arr[i]); found = true; break; }
        }
        delete[] arr;
        if (!found) cout << "Pasien tidak ditemukan di linked list." << endl;

    } else if (pilihan == 7) {
        queue.dequeue();

    } else if (pilihan == 8) {
        queue.tampilkanAntrian();

    } else if (pilihan == 9) {
        undoStack.undo(list);

    } else if (pilihan == 10) {
        undoStack.tampilkanRiwayat();

    } else {
        cout << "Pilihan tidak valid!" << endl;
    }

    menu(list, queue, undoStack);
}

// ARRAY + POINTER
int main() {
    LinkedList     list;
    EmergencyQueue queue;
    UndoStack      undoStack;

    int n;
    cout << "Masukkan jumlah pasien awal: ";
    cin >> n;

    Patient* DataPasien = new Patient[n];
    Patient* ptr        = DataPasien;

    for (int i = 0; i < n; i++) {
        cout << "\nPasien ke-" << i+1 << endl;
        cout << "Alamat memori: " << ptr << endl;

        cout << "Masukkan ID      : "; cin >> DataPasien[i].id;
        cin.ignore();
        cout << "Masukkan Nama    : "; getline(cin, DataPasien[i].name);
        cout << "Masukkan Umur    : "; cin >> DataPasien[i].age;
        if (DataPasien[i].age < 0) {
            cout << "Umur tidak valid!" << endl;
            i--; continue;
        }
        cin.ignore();
        cout << "Masukkan Penyakit: "; getline(cin, DataPasien[i].disease);

        ptr->tampilkanInfo();
        ptr++;

        list.tambahPasien(DataPasien[i]);
    }

    delete[] DataPasien;

    menu(list, queue, undoStack);

    return 0;
}