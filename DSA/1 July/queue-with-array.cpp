#include <iostream>
using namespace std;

class Queue
{
private:
    int top = 0, end = 0;
    int arr[5];

public:
    // if queue do not have any element
    bool isEmpty()
    {
       return top == end;
    }
    // if queue is full
    bool isFull()
    {
        return (end + 1) % 5 == top;
    }
    // return the top element, the top is dequed first
    int front()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[top];
    }

    // insert at last(rear)
    void enqueue(int x)
    {
        if (!isFull())
        {
            arr[end] = x;
            end = (end + 1)%5;
        }
        else
            cout << "Out of Memory" << endl;
    }
    // pick out from start(front)
    void dequeue()
    {
        if (!isEmpty())
            top = (top+1)%5;
        else
            cout << "Queue is empty" << endl;
    }
};

int main()
{
    Queue q;
    cout<<"Empty "<<q.isEmpty()<<endl;
    cout<<"Full "<<q.isFull()<<endl;
    cout<<"Front "<<q.front()<<endl;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout<<"Front "<<q.front()<<endl;
    q.dequeue();
    cout<<"Front "<<q.front()<<endl;
    q.enqueue(10);
    q.dequeue();
    cout<<"Front "<<q.front()<<endl;
    q.dequeue();
    cout<<"Front "<<q.front()<<endl;
    q.dequeue();
    cout<<"Front "<<q.front()<<endl;
    q.dequeue();
    cout<<"Front "<<q.front()<<endl;
    cout<<"Empty "<<q.isEmpty()<<endl;
    return 0;
}