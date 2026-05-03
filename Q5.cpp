#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <vector>
using namespace std;

class MovieTicket {
private:
    // movieID -> set of booked customer IDs
    unordered_map<int, unordered_set<int>> bookings;

public:
    // BOOK X Y
    bool book(int customerID, int movieID) {
        if (bookings[movieID].count(customerID)) {
            return false; // already booked
        }
        if (bookings[movieID].size() >= 100) {
            return false; // sold out
        }
        bookings[movieID].insert(customerID);
        return true;
    }

    // CANCEL X Y
    bool cancel(int customerID, int movieID) {
        if (!bookings[movieID].count(customerID)) {
            return false; // not booked
        }
        bookings[movieID].erase(customerID);
        return true;
    }

    // IS_BOOKED X Y
    bool isBooked(int customerID, int movieID) {
        return bookings[movieID].count(customerID) > 0;
    }

    // AVAILABLE_TICKETS Y
    int availableTickets(int movieID) {
        return 100 - bookings[movieID].size();
    }
};

int main() {
    int Q;
    cin >> Q;
    cin.ignore();

    MovieTicket system;

    while (Q--) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string query;
        ss >> query;

        if (query == "BOOK") {
            int X, Y;
            ss >> X >> Y;
            cout << (system.book(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "CANCEL") {
            int X, Y;
            ss >> X >> Y;
            cout << (system.cancel(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "IS_BOOKED") {
            int X, Y;
            ss >> X >> Y;
            cout << (system.isBooked(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "AVAILABLE_TICKETS") {
            int Y;
            ss >> Y;
            cout << system.availableTickets(Y) << endl;
        }
    }

    return 0;
}
