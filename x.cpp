#include <iostream>
#include <string.h>
#include<queue>
using namespace std;
queue<char> Q1;
queue<char> Q2;
class Stack
{
public:
    void push1(char);
    char pop1();
};
void Stack ::push1(char x)
{
    while (!Q1.empty())
    {
        char temp = Q1.front();
        Q1.pop();
        Q2.push(temp);
    }
    Q1.push(x);
    while (!Q2.empty())
    {
        int temp = Q2.front();
        Q2.pop();
        Q1.push(temp);
    }
}
char Stack ::pop1()
{
    char a=Q1.front();
    Q1.pop();
    return a;
}
int checkoperator(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
    {
        return 1;
    }
    return 0;
}
int checkoperand(char x)
{
    if (x >= 65 && x <= 90)
    {
        return 1;
    }
    if (x >= 97 && x <= 122)
    {
        return 1;
    }
    if (x >= 49 && x <= 57)
    {
        return 1;
    }
    return 0;
}
int check(char infix[])
{
    int count = 0;
    for (int i = 0; i < strlen(infix); i = i + 2)
    {
        if (checkoperand(infix[i]) == 1 && checkoperator(infix[i + 1]) == 1 && checkoperand(infix[i + 2]) == 1)
        {
            count = count + 1;
        }
    }

    if (count == strlen(infix) / 2)
        return 1;
    else
        return 0;
}
int precedence(char b, char a)
{
    if (a == '+' && b == '*')
        return 1;
    if (a == '+' && b == '/')
        return 1;
    if (a == '-' && b == '*')
        return 1;
    if (a == '-' && b == '/')
        return 1;
    else
        return 0;
}
void postfix(char a[])
{
    int j = 0;
    Stack s;
    int n = strlen(a);
    char postfix[n];
    for (int i = 0; i < n; i++)
    {
        if (checkoperator(a[i]) == 1)
        {
            if (Q1.empty() == 1)
            {
                s.push1(a[i]);
            }
            else
            {
                if (precedence(a[i], Q1.front()))
                {
                    s.push1(a[i]);
                }
                else
                {
                    while (precedence(a[i], Q1.front()) != 1 && !Q1.empty())
                    {
                        postfix[j] = Q1.front();
                        j++;
                        s.pop1();
                    }
                    s.push1(a[i]);
                }
            }
        }
        else
        {
            postfix[j] = a[i];
            j++;
        }
    }
    while (Q1.empty() != 1)
    {
        postfix[j] = Q1.front();
        j++;
        s.pop1();
    }

    cout << "postfix expression= " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << postfix[i];
    }
    cout << endl;
}
int main()
{
    char a[100];
    int choice;
    while (1)
    {
        cout << "enter your choice\n1.get infix expression\n2.print infix expression\n3.print postfix expression\n4.exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "enter the infix expression\n";
            cin >> a;
            try
            {
                if (check(a) == 0)
                {
                    throw a;
                }
            }
            catch (char a[])
            {
                cout << "invalid input\n";
            }
            break;
        case 2:
            cout << "infix expression=" << a << endl;
            break;
        case 3:
            try
            {
                if (check(a) == 0)
                {
                    throw a;
                }
                postfix(a);
            }
            catch (char a[])
            {
                cout << "invalid input\n";
            }
            break;
        case 4:
            exit(1);
        }
    }
    return 0;
}