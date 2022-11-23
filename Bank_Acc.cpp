#include <iostream>

using namespace std;

class bankAccount
{
 public:
        int cust_id;
        double cust_balance;
        double cust_deposit, cust_withdraw;


        bankAccount(int idcust, double balance)
        {
            cust_id = idcust;
            cust_balance = balance;
        }

        double getBalance()
        {
            return cust_balance;
        }

        int getCustId()
        {
            return cust_id;
        }
        void setBalance(double balance)
        {
            cust_balance = balance;
        }
        void setCustId(int idcust)
        {
            cust_id = idcust;
        }
        void getAccInfo()
        {
            cout << " ---------------------------------" << endl;
            cout << " ||        Account Info           " << endl;
            cout << " ---------------------------------" << endl;
            cout << " || Account Number :" << cust_id << endl;
            cout << " || Account Balance: Rp " << cust_balance << endl;
            cout << " ---------------------------------" << endl;
            cout << endl;
        }
        double setDepo(double depo)
        {
            cust_deposit = depo;
            cust_balance += depo;
            return cust_balance;
        }
        double setWD(double wd) 
        {
            cust_withdraw = wd;
            if(cust_balance >= wd)
            {
                cust_balance -= wd;
            }
            else if(cust_balance < wd)
            {
                cout << "Insufficient balance" << endl;
            }
            cout << "Current Balance: ";    
            return cust_balance;
        }

};

class checkingAccount:bankAccount
{
    public:
        double minimum_balance = 10000;
        double service_charges = 1000;
        double interest_rate;

        checkingAccount(int idcust, double balance, double intrst):bankAccount(idcust, balance)
        {
            interest_rate = intrst;
        }

        void setIntRate(double rate)
        {
            interest_rate = rate;
        }
        double getIntRate()
        {
            return interest_rate;
        }
        void setMinimumBal(double bal)
        {
            minimum_balance = bal;
        }
        double getMinimumBal()
        {
            return minimum_balance;
        }

        double setDepo(double depo)
        {
            cust_balance += depo;
            return cust_balance;
        }
        double getBalance()
        {
            return cust_balance;
        }
        double setWD(double wd)
        {
            if(cust_balance >= wd)
            {
                cust_balance -= wd;
            }
            else if(cust_balance < wd)
            {
                cout << "Insufficient balance" << endl;
            }
            cout << "Current Balance: ";    
            return cust_balance;
        }
    
        
        int getCharge()
        {
                cout << " ----------------------------------------------" << endl;
                cout << "|| You will get charged due to minimum balance: Rp " << service_charges << endl; 
                cout << " ----------------------------------------------" << endl;

                return service_charges;
        }
        void getAccInfo()
        {
            cout << " ---------------------------------" << endl;
            cout << " ||        Account Info           " << endl;
            cout << " ---------------------------------" << endl;
            cout << " || Account Number :" << cust_id << endl;
            cout << " || Account Balance: Rp" << cust_balance << endl;
            cout << " ---------------------------------" << endl;
            cout << endl;
        }

};

class savingAccount:bankAccount
{
    double minimum_balance;
    public:
    savingAccount(int idcust, double balance):bankAccount(idcust,balance)
    {
        minimum_balance = 10000;
    }
    double setDepo(double depo)
    {
        cust_balance += depo;
        return cust_balance;
    }
    double setWD(double wd)
    {
        if(cust_balance >= wd)
        {
            cust_balance -= wd;
        }
        else if(cust_balance < wd)
        {
            cout << "Insufficient balance" << endl;
        }
        cout << "Current Balance: ";    
        return cust_balance;
    }
    void setMinimumBal(double bal)
    {
        minimum_balance = bal;
    }
    void getAccInfo()
    {
        cout << " ---------------------------------" << endl;
        cout << " ||        Account Info           " << endl;
        cout << " ---------------------------------" << endl;
        cout << " || Account Number :" << cust_id << endl;
        cout << " || Account Balance: Rp " << cust_balance << endl;
        cout << " ---------------------------------" << endl;
        cout << endl;
    }
    
};

int main(int argc, char const *argv[])
{
    double amount;
    int choice;


    do
    {
        cout << endl;
        cout << "       Create an Account      " << endl;
        cout << " *****************************" << endl;
        cout << " **  1 - Checking Account   **" << endl;
        cout << " **  2 - Saving Account     **" << endl;
        cout << " **  3 - Exit               **" << endl;
        cout << " *****************************" << endl;
        cin >> choice;
        cout << endl;

        if(choice==1)
        {
            int idcust1, choice1;
            double balance1, intrate1, minimum1;

            cout << "Enter account ID: "; cin >> idcust1;
            cout << "Enter open balance: "; cin >> balance1;
            cout << "Enter interest rate: "; cin >> intrate1;
            checkingAccount person1(idcust1, balance1, intrate1);
            cout << "Enter Minimum Balance: "; cin >> minimum1;
            person1.setMinimumBal(minimum1);

            do
            {
                cout << endl;
                cout << " *************************" << endl;
                cout << " **  1 - Deposit        **" << endl;
                cout << " **  2 - Withdraw       **" << endl;
                cout << " **  3 - Account Info   **" << endl;
                cout << " **  4 - Exit           **" << endl;
                cout << " *************************" << endl;
                cin >> choice1;
                cout << endl;
                switch (choice1)
                {
                case 1:
                    cout << "Enter amount: " << endl;
                    cin >> amount;
                    cout << "Current balance: " << person1.setDepo(amount);
                    if(person1.getBalance() < person1.getMinimumBal())
                    {
                        person1.getCharge();
                    }
                    break;
                case 2:
                    cout << "Enter amount: " << endl;
                    cin >> amount;
                    cout << person1.setWD(amount) << endl;
                    if(person1.getBalance() < person1.getMinimumBal())
                    {
                        person1.getCharge();
                    }
                    else
                    {}
                    break;
                case 3:
                    person1.getAccInfo();
                    break;
                default:
                    break;
                }
                
            }
            while(choice1!=4);
        }
        else if(choice==2)
        {
            int idcust2, choice2;
            double balance2;
            cout << "Enter account ID: "; cin >> idcust2;
            cout << "Enter open balance: "; cin >> balance2;
            savingAccount person2(idcust2, balance2);
            do
            {
                cout << endl;
                cout << " *************************" << endl;
                cout << " **  1 - Deposit        **" << endl;
                cout << " **  2 - Withdraw       **" << endl;
                cout << " **  3 - Account Info   **" << endl;
                cout << " **  4 - Exit           **" << endl;
                cout << " *************************" << endl;
                cin >> choice2;
                cout << endl;
                switch (choice2)
                {
                case 1:
                    cout << "Enter amount: " << endl;
                    cin >> amount;
                    cout << person2.setDepo(amount);
                    break;
                case 2:
                    cout << "Enter amount: " << endl;
                    cin >> amount;
                    cout << person2.setWD(amount) << endl;
                    break;
                case 3:
                    person2.getAccInfo();
                    break;
                default:
                    break;
                }
            }
            while(choice2!=4);
        }
    } 
    while (choice!=3);
    return 0;
}
