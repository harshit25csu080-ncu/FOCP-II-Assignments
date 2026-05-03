#include <iostream>
#include <unordered_map>
#include <sstream>
using namespace std;

class Bank {
private:
    unordered_map<int, long long> accounts;

public:
    // CREATE X Y
    bool create(int userID, long long amount) {
        if (accounts.find(userID) == accounts.end()) {
            accounts[userID] = amount;
            return true;   // new account created
        } else {
            accounts[userID] += amount;
            return false;  // already existed
        }
    }

    // DEBIT X Y
    bool debit(int userID, long long amount) {
        if (accounts.find(userID) == accounts.end() || accounts[userID] < amount) {
            return false;
        }
        accounts[userID] -= amount;
        return true;
    }

    // CREDIT X Y
    bool credit(int userID, long long amount) {
        if (accounts.find(userID) == accounts.end()) {
            return false;
        }
        accounts[userID] += amount;
        return true;
    }

    // BALANCE X
    long long balance(int userID) {
        if (accounts.find(userID) == accounts.end()) {
            return -1;
        }
        return accounts[userID];
    }
};

int main() {
    int Q;
    cin >> Q;
    cin.ignore();

    Bank bank;

    while (Q--) {
        string line, query;
        getline(cin, line);

        stringstream ss(line);
        ss >> query;

        if (query == "CREATE") {
            int X;
            long long Y;
            ss >> X >> Y;
            cout << (bank.create(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "DEBIT") {
            int X;
            long long Y;
            ss >> X >> Y;
            cout << (bank.debit(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "CREDIT") {
            int X;
            long long Y;
            ss >> X >> Y;
            cout << (bank.credit(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "BALANCE") {
            int X;
            ss >> X;
            cout << bank.balance(X) << endl;
        }
    }

    return 0;
}
