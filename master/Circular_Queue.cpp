// @author: Abhimanyu Maurya

#include <iostream>
#include <vector>
using namespace std;

//fast i/o
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);
bool ot = cout.tie(0);

class Circular_Queue
{
private:
    int size;
    int maxSize;
    int frontIndex;
    int rearIndex;
    int *data;

public:
    Circular_Queue(int);
    ~Circular_Queue();
    int front();
    int rear();
    string enQueue(int);
    string deQueue();
    string isEmpty();
    string isFull();
};

Circular_Queue::Circular_Queue(int n)
{
    size = 0;
    maxSize = n;
    frontIndex = 0;
    rearIndex = n - 1;
    data = new int[n];
}

Circular_Queue::~Circular_Queue()
{
}

int Circular_Queue::front()
{
    if (size > 0)
        return data[frontIndex];
    return -1;
}

int Circular_Queue::rear()
{
    if (size > 0)
        return data[rearIndex];
    return -1;
}

string Circular_Queue::enQueue(int n)
{
    if (size < maxSize)
    {
        rearIndex = (rearIndex + 1) % maxSize;
        data[rearIndex] = n;
        size++;
        return "true";
    }
    else
        return "false";
}

string Circular_Queue::deQueue()
{
    if (size == 0)
        return "false";
    frontIndex++;
    size--;
    return "true";
}

string Circular_Queue::isEmpty()
{
    if (size == 0)
        return "true";
    return "false";
}

string Circular_Queue::isFull()
{
    if (size == maxSize)
        return "true";
    return "false";
}

int main()
{
    int n, choice;
    cin >> n;
    Circular_Queue cq(n);
    while (1)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> n;
            cout << cq.enQueue(n) << '\n';
            break;
        case 2:
            cout << cq.deQueue() << '\n';
            break;
        case 3:
            cout << cq.front() << '\n';
            break;
        case 4:
            cout << cq.rear() << '\n';
            break;
        case 5:
            cout << cq.isEmpty() << '\n';
            break;
        case 6:
            cout << cq.isFull() << '\n';
            break;
        default:
            return 0;
        }
    }
    return 0;
}
