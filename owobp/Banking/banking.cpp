#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


class Account {
private:
    string name;
    float balance;
    int id;
    int transactions;
public: //  Constructor
    Account(string _name, float _balance, int _id = (rand() & 99999) + 1, int _transactions = 0) {
        name = _name;
        balance = _balance;
        id = _id; //id is randomly generated - 1-99999
        transactions = _transactions;
    }

    string getName() { return name; }
    float getBalance() { return balance; }
    int getId() { return id; }
    int getTransactions() { return transactions; }

    void addBalance(float _balance) { balance += _balance; }
    void subBalance(float _balance) { balance -= _balance; }
};


class Bank {
public:
    vector<Account*> accounts;
    int customerCount = 0;

    void CreateAccount(string _name, float initDeposit) {
        accounts.push_back(new Account(_name, initDeposit));
        customerCount++;
    }

    void RemoveAccount(int posInDatabase) {
        accounts.erase(accounts.begin() + posInDatabase);
    }

    void SendMoney(int amount, Account *from, Account *to) {
        if (amount <= from->getBalance()) {
            cout << "Attempting to send $" << amount << ":\n";
            cout << "Sending $" << amount << " from " << from->getName() << " to " << to->getName() << endl;
            from->subBalance(amount);
            to->addBalance(amount);
        }

        

        else {
            cout << "Failed to send $" << amount << ":\n"; 
            cout << "Not enough money in account " << from->getName() << " to send $" << amount << " to: " << to->getName() << endl;
        }
    }

    void DisplayAllAccountNames() {
        for (int i = 0; i < accounts.size(); i++)
        {
            cout << "Account Name: " << accounts.at(i)->getName() << " ID: " <<
            accounts.at(i)->getId() << " Balance: $" << accounts.at(i)->getBalance() << endl;
        }
    }

};

int main() {
    srand((unsigned) time(0));
    Bank chase;
    chase.CreateAccount("Jayden Smith", 150.0f);
    chase.CreateAccount("John James", 500.0f);
    chase.DisplayAllAccountNames();

    cout << "" << endl;

    chase.SendMoney(100.0f, chase.accounts.at(0), chase.accounts.at(1));

    cout << "" << endl;
    chase.DisplayAllAccountNames();

    cout << "" << endl;
    chase.SendMoney(100.0f, chase.accounts.at(0), chase.accounts.at(1));

    cout << "" << endl;
    chase.DisplayAllAccountNames();

    cin.get();
}