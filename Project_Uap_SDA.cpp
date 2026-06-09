#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

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