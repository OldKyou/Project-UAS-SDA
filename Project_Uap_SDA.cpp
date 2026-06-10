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