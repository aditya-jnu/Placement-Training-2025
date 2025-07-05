#include <iostream>
using namespace std;
class Stack
{
private:
    int top = -1;
    int arr[10];

public:
    int topIndex()
    {
        return arr[top];
    }
    void push(int x)
    {
        if (top >= 9)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "No element in stack" << endl;
            return;
        }
        top--;
    }
    int peep(int pos)
    {
        return arr[top - pos + 1];
    }
};

int main() {
    Stack s; // s is a variable of type Stack it stores the entire object directly.
    s.push(10);
    cout<<s.topIndex()<<endl; 
    s.push(20);
    cout<<s.topIndex()<<endl;
    s.push(30);
    cout<<s.topIndex()<<endl;      
    cout<<s.peep(1)<<" ";           
    cout<<s.peep(2)<<" ";       
    cout<<s.peep(3)<<" ";  
    return 0;
}