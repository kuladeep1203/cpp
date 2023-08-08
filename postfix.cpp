#include <iostream>
#include <string.h>
using namespace std;
class queue
{
    char data;
    queue *head = NULL;
    queue *tail;
    queue *next;

public:
    queue *newnode(char data)
    {
        queue *newnode = new queue();
        newnode->data = data;
        newnode->next = NULL;
        return newnode;
    }
    void enqueue(char data)
    {
        queue *new_node = newnode(data);
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
    }
    char getdata()
    {
        if (head != NULL)
            return head->data;
        else
            return '0';
    }
    char dequeue()
    {
        queue *temp = head;
        char y;
        try
        {
            if (head == NULL)
            {
                throw head;
            }
            y = temp->data;
            head = head->next;
            delete[] temp;
        }
        catch (...)
        {
            cout << " Queue Is Empty " << endl;
        }
        return y;
    }
    int isEmpty()
    {
        if (head == NULL)
        {
            return 1;
        }

        return 0;
    }
};

class Stack
{
public:
    queue Q1, Q2;
    void push(char x)
{
    while (!Q1.isEmpty())
    {
        char temp = Q1.dequeue();
        Q2.enqueue(temp);
    }
    Q1.enqueue(x);
    while (!Q2.isEmpty())
    {
        int temp = Q2.dequeue();
        Q1.enqueue(temp);
    }
}
char pop()
{
    return Q1.dequeue();
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
    int n = strlen(a);

    char postfix[n];
    for (int i = 0; i < n; i++)
    {

        if (checkoperator(a[i]) == 1)
        {
            if (Q1.isEmpty() == 1)
            {
                push(a[i]);
            }
            else
            {
                if (precedence(a[i], Q1.getdata()))
                {
                    push(a[i]);
                }
                else
                {
                    while (precedence(a[i], Q1.getdata()) != 1 && Q1.getdata() != '0')
                    {
                        postfix[j] = Q1.getdata();

                        j++;
                        pop();
                    }
                    push(a[i]);
                }
            }
        }
        else
        {
            postfix[j] = a[i];
            j++;
        }
    }
    while (Q1.isEmpty() != 1)
    {
        postfix[j] = Q1.getdata();
        j++;
        pop();
    }

    cout << "postfix expression= " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << postfix[i];
    }
    cout << endl;
}
};
int main()
{
    char a[100];
    int choice;
   Stack s;
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
                if (s.check(a) == 0)
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
                if (s.check(a) == 0)
                {
                    throw a;
                }
                s.postfix(a);
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