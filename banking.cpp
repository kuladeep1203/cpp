#include <iostream>
using namespace std;
class account
{
protected:
    int accountnumber;
    int amount;
    int temp;
    int customerid;
    char name[20];

public:
    account()
    {
        temp = 0;
        amount = 0;
        accountnumber=0;
    }
    
    
    int getaccount()
    {
    return accountnumber;
    }
    
};
class savings : public account
{
    int inter;
    float rate;

public:

    savings()
    {
        inter = 0;
    }
    int get(savings s[], int num, int n)
    {

        for (int i = 0; i < n; i++)
        {
            
                cout<<"id="<<s[i].customerid<<endl;
            
            
        }
    }
    int checknumber(savings s[], int num, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i].accountnumber == num)
            {
                return 1;
            }
           
        }
        return 0;
    }
    int checkid(savings s[], int num, int n)
    {

        for (int i = 0; i < n; i++)
        {
            if (s[i].customerid == num)
            {
                cout<<"id="<<s[i].customerid<<endl;
                return 1;
            }
                
        }
        return 1000;
    }
    int getindex(savings s[], int num, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i].accountnumber == num)
            {
                return i;
            }
            
                
        }
        return 1000;
    }
    void openaccount(int num, int id)
    {
        cout << "enter your name\n";
        cin >> name;
        accountnumber = num;
        cout<<"idd="<<id<<endl;
        customerid = id;
        cout<<"idd="<<customerid;
    }
    void credit(int money)
    {
        amount = amount + money;
        cout << money << "\thas been credited to\t" << accountnumber<<endl;
        cout << "balance=" << amount << endl;
    }
    void debit(int money)
    {
        if (money > amount)
        {
            cout << "no sufficent balance to withdraw\n";
        }
        else
        {
            amount = amount - money;
            cout << money << "\thas been debited from\t" << accountnumber << endl;
            cout << "balance=" << amount << endl;
        }
    }
    void changeinterest(int interest)
    {
        inter = interest;
    }
    void calculateinterest()
    {
        cout << "interest=" << inter << "amount=" << amount << endl;
        rate = (inter * amount) / 100;
        cout << "interest for your existing amount=" << rate << endl;
    }
    void calculateandupdate()
    {
        amount = amount + rate;
        cout << "amount after interest has added" << amount << endl;
    }
    void getdetails(savings s[], int num, int n)
    {
int i;
        for ( i = 0; i < n; i++)
        {
            if (s[i].customerid == num)
            {
                cout <<"Name="<< s[i].name << endl;
                cout << "Account type=savingsaccount\n";
                cout << "Accountnumber="<<s[i].accountnumber<<endl;
                cout <<"Balance=" <<s[i].amount<<endl;
                break;
            }
            
        }
        if(i>n)
        cout<<"enter valid"<<endl;
    }
};
class checking : public account
{
    int count;
    int rate;
    int checkingfee;

public:
    checking()
    {
        count = 0;
        checkingfee = 0;
    }
    int checknumber(checking s[], int num, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i].accountnumber == num)
            {
                return 1;
            }
            
        }
        return 0;
    }
    int checkid(checking s[], int num, int n)
    {

        for (int i = 0; i < n; i++)
        {
            if (s[i].customerid == num)
            {
                cout<<"id="<<s[i].customerid<<endl;
                return 1;
            }
           
        }
        return 1000;
    }
    int getindex(checking s[], int num, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i].accountnumber == num)
            {
                return i;
            }
            
        }
        return 1000;
    }
    void openaccount(int num, int id)
    {
        cout << "enter your name\n";
        cin >> name;
        accountnumber = num;
        customerid = id;
        temp++;
    }
    void credit(int money)
    {
        amount = amount + money;
        amount = amount - checkingfee;
        cout << money << "\thas been credited to\t" << accountnumber;
        count++;
    }
    void debit(int money)
    {
        if (money > amount)
        {
            cout << "no sufficent balance to withdraw\n";
        }
        else
        {
            amount = amount - money;
            cout<<"before="<<amount;
            amount = amount - checkingfee;
            cout << money << "\thas been debited from\t" << accountnumber<<endl;;
            cout<<"after fee="<<amount;
            count++;
        }
    }
    void changecheckingfee(int fee)
    {
        checkingfee = fee;
    }
    void printcheckingfee()
    {
        cout << "checking fee=" << checkingfee<<endl;
    }
    
    void getdetails(checking s[], int num, int n)
    {
        int i;

        for ( i = 0; i < n; i++)
        {
            if (s[i].customerid == num)
            {
                cout <<"Name=" <<s[i].name << endl;
                cout << "Account type=checkingaccount\n";
                cout << "Account number="<<s[i].accountnumber<<endl;
                cout <<"Balance=" <<s[i].amount<<endl;
                break;
            }
            
        }
        if(i>n)
        cout<<"enter valid\n";
    }

};
int main()
{
    int choice, accountnumber, choice1, checkacc, a=0, amount, interestrate, checkingfee;
    int customerid, k=0, l=0;
    savings s[5];
    checking c[5];
    int x;

    int i = 0,j=0;
    while (1)
    {
        cout << "1.open account\n2.credit\n3.debit\n4.change/update interest\n5.calculate interest\n6.calculate and update interest\n7.change/update fee amount\n8.print checking fee\n9.search customer details\n10.exit\n";
        cout << "enter your choice\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            x = 0;
            cout << "enter the customer id\n";
            cin >> customerid;
                cout << "enter 1 for savings account and 2 for checking account\n";
                cin >> choice1;
                if( i>0 && s[i].checkid(s,customerid,i+1)!=1000 )
                {
                a=s[i].checkid(s,customerid,i+1);
                k = s[a].getaccount();
                l = c[a].getaccount();
                }
                if (choice1 == 1 )
                {
                    cout<<"k="<<k<<endl;
                    if(k!=0 && s[i].checkid(s,customerid,i+1)!=1000)
                    {
                     if(k!=0)
                      cout<<"a user should have one account\n";
                      else
                      cout<<"oops!customer id already exist choose some other\n";

                    }
                    else
                    {
                    while (x != 1)
                    {
                        cout << "enter the account number in 3 digit number";
                        cin >> accountnumber;
                        if (s[i].checknumber(s, accountnumber, i + 1) || accountnumber / 100 != 1)
                        {
                            if (accountnumber / 100 != 1)
                                cout << "your number format should be 1xx\n";
                            else 
                                cout << "oops! number already exist choose some other\n";
                        }
                        else
                            x++;
                    }
                    cout<<"i="<<i<<endl;
                    s[i].openaccount(accountnumber, customerid);
                    cout<<"io="<<i<<endl;
                    i++;
                    }
                }
                else if (choice1 == 2 )
                {
                if(l!=0 &&s[i].checkid(s,customerid,i+1)!=1000)
                {
                     if(l!=0)
                      cout<<"a user should have one account\n";
                      else
                      cout<<"oops!customer id already exist choose some other\n";
                      break;
                }
                else
                {
                    x = 0;
                    while (x != 1)
                    {
                        cout << "enter the account number in 3 digit number";
                        cin >> accountnumber;
                        if (c[j].checknumber(c, accountnumber, i + 1) || accountnumber / 100 != 2)
                        {
                            if (accountnumber /100 != 2)
                                cout << "your number format should be 2xx\n";
                            else
                                cout << "oops! number already exist choose some other\n";
                        }
                        else
                            x++;
                    }
                    c[j].openaccount(accountnumber, customerid);
                    j++;
                }
                }
                else
                    cout << "enter only 1 or 2\n";
            
            break;
        case 2:
            cout << "enter your customerid\n";
            cin >> customerid;
            cout<<"i="<<i<<endl;
            if (s[i].checkid(s, customerid, i + 1)!=1000 || c[j].checkid(c,customerid,j+1)!=1000)
            {
                cout << "enter 1 to credit into savings account or 2 to credit into checking account\n";
                cin >> choice1;
                if (choice1 == 1)
                {
                    cout << "enter your account number\n";
                    cin >> checkacc;
                    a = s[i].getindex(s, checkacc, i + 1);
                    if (a != 1000)
                    {
                        cout << "enter amount to be credited\n";
                        cin >> amount;
                        if(amount<0)
                        cout<<"enter valid\n";
                        else
                        s[a].credit(amount);
                    }
                    else
                    {
                        cout << "enter valid number\n";
                    }
                }
                else if (choice1 == 2)
                {
                    cout << "enter your account number\n";
                    cin >> checkacc;
                    a = c[j].getindex(c, checkacc, j + 1);
                    if (a != 1000)
                    {
                        cout << "enter amount to be credited\n";
                        cin >> amount;
                        if(amount<0)
                        cout<<"entervalid\n";
                        else
                         c[a].credit(amount);
                    }
                    else
                    {
                        cout << "enter valid number\n";
                    }
                }
                else
                {
                    cout << "enter 1 or 2 only\n";
                }
            }
            else
            {
                cout << "id doesnot exist\n";
            }
            break;
        case 3:
            cout << "enter your customerid\n";
            cin >> customerid;
            if (s[i].checkid(s, customerid, i + 1)!=1000 || c[j].checkid(c,customerid,j+1)!=1000)
            {
                cout << "enter 1 to debit into savings account or 2 to debit into checking account\n";
                cin >> choice1;
                if (choice1 == 1)
                {
                    cout << "enter your account number\n";
                    cin >> checkacc;
                    a = s[i].getindex(s, checkacc, i + 1);
                    if (a != 1000)
                    {
                        cout << "enter amount to be debited\n";
                        cin >> amount;
                        if(amount<0)
                        cout<<"enter valid\n";
                        else
                        s[a].debit(amount);
                    }
                    else
                    {
                        cout << "enter valid number\n";
                    }
                }
                else if (choice1 == 2)
                {
                    cout << "enter your account number\n";
                    cin >> checkacc;
                    a = c[j].getindex(c, checkacc, j + 1);
                    if (a != 1000)
                    {
                        cout << "enter amount to be debited\n";
                        cin >> amount;
                        if(amount<0)
                        cout<<"enter valid\n";
                        else
                        c[a].debit(amount);
                    }
                    else
                    {
                        cout << "enter valid number\n";
                    }
                }
                else
                {
                    cout << "enter 1 or 2 only\n";
                }
            }
            else
            {
                cout << "id doesnot exist\n";
            }
            break;
        case 4:
            cout << "enter the interest rate\n";
            cin >> interestrate;
            if(interestrate>0){
            for (int z = 0; z < i; z++)
                s[z].changeinterest(interestrate);
            }
            else
            cout<<"enter valid\n";
            break;
        case 5:
            cout << "enter your customerid\n";
            cin >> customerid;
            if (s[i].checkid(s, customerid, i + 1)!=1000)
            {
                cout << "enter your account number\n";
                cin >> checkacc;
                a = s[i].getindex(s, checkacc, i + 1);
                if (a != 1000)
                {
                    s[a].calculateinterest();
                }
                else
                {
                    cout << "enter valid number\n";
                }
            }
            else
            {
                cout << "id doesnot exist\n";
            }
            break;
        case 6:
            cout << "enter your customerid\n";
            cin >> customerid;
            if (s[i].checkid(s, customerid, i + 1)!=1000)
            {
                cout << "enter your account number\n";
                cin >> checkacc;
                a = s[i].getindex(s, checkacc, i + 1);
                if (a != 1000)
                {
                    s[a].calculateandupdate();
                }
                else
                {
                    cout << "enter valid number\n";
                }
            }
            else
                cout << "id doesnot exist\n";
            break;
        case 7:
            cout << "enter checking fee\n";
            cin >> checkingfee;
            if(checkingfee>0){
            for (int z = 0; z < j; z++)
            c[z].changecheckingfee(checkingfee);
            }
            else
            cout<<"enter valid\n";
            break;
        case 8:
            c[j].printcheckingfee();
            break;
        case 9:
            cout << "enter your customerid\n";
            cin >> customerid;
            if (s[i].checkid(s, customerid, i + 1)!=1000)
            {
                s[i].getdetails(s, customerid, i + 1);
                c[i].getdetails(c, customerid, j + 1);
            }
            else
            {
                cout<<"id doesnot found\n";
            }

            break;
        case 10:
            s[i].get(s, customerid, i + 1);
            break;
        default:
            cout << "enter only from 1 to 10\n";
        }
    }
}