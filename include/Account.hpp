#include <string>

class Account {
    std::string full_name;
    std::string number;
    long crnt_balance;

public:
    Account(std::string, std::string num, long amnt);

    std::string name() {return full_name;}
    std::string no() {return number; }
    long balance() {return crnt_balance;}

    void deposit(long amnt);
    void withdraw(long amnt);
};
