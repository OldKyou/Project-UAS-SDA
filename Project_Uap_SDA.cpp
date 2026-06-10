#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

struct Ticket {
    int id;
    string film;
    int seats;
};

class BookingSystem {
private:
    queue<Ticket> bookingQueue;
    stack<Ticket> history;
    int nextId;

public:
    BookingSystem() : nextId(1) {}

    void showFilms() const {
        cout << "Pilihan film:\n";
        cout << "1. spiderman\n";
        cout << "2. ironman\n";
        cout << "3. mermaidman\n";
    }

    Ticket* createBooking(const string& film, int seats) {
        Ticket* ticket = new Ticket{nextId++, film, seats};
        bookingQueue.push(*ticket);
        history.push(*ticket);
        return ticket;
    }

int main() {
    
            int seats;
            cout << "Masukkan jumlah kursi: ";
            cin >> seats;
            if (seats <= 0) {
                cout << "Jumlah kursi harus lebih dari 0.\n";
                continue;
            }
            Ticket* ticket = system.createBooking(film, seats);
            cout << "Tiket berhasil dipesan: ID " << ticket->id << ", film " << ticket->film << ", kursi " << ticket->seats << ".\n";
            delete ticket;
        } else if (choice == 2) {
            system.processNextBooking();
        } else if (choice == 3) {
            system.showQueue();
        } else if (choice == 4) {
            system.showHistory();
        } else if (choice == 5) {
            cout << "Keluar dari program.\n";
        } else {
            cout << "Pilihan tidak dikenal. Silakan coba lagi.\n";
void showHistory() const {
        if (history.empty()) {
            cout << "Belum ada riwayat pemesanan.\n";
            return;
        }
        cout << "Riwayat pemesanan:\n";
        stack<Ticket> copy = history;
        while (!copy.empty()) {
            Ticket ticket = copy.top();
            copy.pop();
            cout << "ID " << ticket.id << " - " << ticket.film << " (" << ticket.seats << " kursi)\n";
        }
    }
};

    return 0;
}
int main() {
    BookingSystem system;
    int choice = 0;

    while (choice != 5) {
        cout << "\n=== Sistem Pemesanan Tiket Film Sederhana ===\n";
        cout << "1. Pesan tiket\n";
        cout << "2. Proses tiket berikutnya\n";
        cout << "3. Lihat antrian tiket\n";
        cout << "4. Lihat riwayat pemesanan\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> choice;

        if (choice == 1) {
            system.showFilms();
            int filmChoice = 0;
            cout << "Pilih nomor film: ";
            cin >> filmChoice;
            string film;
            switch (filmChoice) {
                case 1: film = "spiderman"; break;
                case 2: film = "ironman"; break;
                case 3: film = "mermaidman"; break;
                default:
                    cout << "Pilihan film tidak valid.\n";
                    continue;
            }
            int seats;
            cout << "Masukkan jumlah kursi: ";
            cin >> seats;
            if (seats <= 0) {
                cout << "Jumlah kursi harus lebih dari 0.\n";
                continue;
            }
            Ticket* ticket = system.createBooking(film, seats);
            cout << "Tiket berhasil dipesan: ID " << ticket->id << ", film " << ticket->film << ", kursi " << ticket->seats << ".\n";
            delete ticket;
        } else if (choice == 2) {
            system.processNextBooking();
        } else if (choice == 3) {
            system.showQueue();
        } else if (choice == 4) {
            system.showHistory();
        } else if (choice == 5) {
            cout << "Keluar dari program.\n";
        } else {
            cout << "Pilihan tidak dikenal. Silakan coba lagi.\n";
        }
    }

    return 0;