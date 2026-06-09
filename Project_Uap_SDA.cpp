#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;



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
        }
    }

    return 0;
}
