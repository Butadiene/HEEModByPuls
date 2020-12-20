#include <string>
#include <iostream>
#include "../include/Account.hpp"

using namespace std;

void print_Account(string title, Account* p)
{
    cout << title
         << p->name() << "\" ("<< p->no() <<") "<< p->balance()<< "円\n" ;
}

int main(){
    Account suzuki("suzuki_ryuiti", "12345678", 1000);
    Account takeda("takeda_hirohumi","87654321", 200);

    suzuki.withdraw(200);
    takeda.deposit(100);

    print_Account("suzuki's_koza", &suzuki);
    print_Account("takeda's_koza", &takeda);
}