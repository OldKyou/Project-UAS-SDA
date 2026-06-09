void processNextBooking() {
        if (bookingQueue.empty()) {
            cout << "Tidak ada tiket yang menunggu diproses.\n";
            return;
        }
        Ticket next = bookingQueue.front();
        bookingQueue.pop();
        cout << "Memproses tiket: ID " << next.id << ", film " << next.film << ", jumlah kursi " << next.seats << ".\n";
    }

    void showQueue() const {
        if (bookingQueue.empty()) {
            cout << "Antrian tiket kosong.\n";
            return;
        }
        cout << "Antrian tiket saat ini:\n";
        queue<Ticket> copy = bookingQueue;
        while (!copy.empty()) {
            Ticket ticket = copy.front();
            copy.pop();
            cout << "ID " << ticket.id << " - " << ticket.film << " (" << ticket.seats << " kursi)\n";
        }
    }
