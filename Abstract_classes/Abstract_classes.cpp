#include <iostream>
using namespace std;

class Account {
public:
    int id;
    int cash = 100000;
    Account() : id(0), cash(100000){}
    Account(int id, int cash) {
        this->id = id;
        this->cash = cash;
    }
};

class Bank {
    int size;
    Account* accounts;
public:
    Bank(Account* accounts, int size) {
        this->accounts = accounts;
        this->size = size;
    }

    Account operation(Account account) {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            if (accounts[i].id == account.id) {
                cout << "How many do you want to take from this account?\n";
                cin >> sum;
            }

            if (sum < 0) {
                cout << "Error\n";
                throw sum;
            }

            if (account.cash < sum) {
                cout << "You dont have needed cash\n";
                throw account.cash;
            }
            else {
                account.cash -= sum;
                cout << "Now on your balance you got : " << account.cash << "\n";
            }
        }
    }
};

void generate_accounts(Account* accounts, int size){
    for (int i = 0; i < size; i++) {
        accounts[i] = Account(i, 100000);
    }
}


int main()
{
    int size = 2;
    Account* accounts = new Account[size]{};

    generate_accounts(accounts, size);

    Bank bank = Bank{ accounts, size };

    bank.operation(accounts[1]);
}