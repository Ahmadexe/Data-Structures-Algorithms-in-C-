#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Queue
{
    int f = -1;
    int r = -1;
    int size;
    int *arr;
};

int isEmpty(Queue* q)
{
    return (q->f == -1 && q->r == -1);
}

int isFull(Queue * q)
{
    return ((q->r + 1) % q->size == q->f);
}

void takeOrder(Queue* q, int oid)
{
    if (isFull(q))
    {
        cout<<"Sorry! Can't accept more orders."<<endl;
    }
    else if (isEmpty(q))
    {
        q->f = 0;
        q->r = 0;
        q->arr[q->f] = oid;
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = oid;
    }
}

int deliver(Queue* q)
{
    if (isEmpty(q))
    {
        cout<<"No pending orders"<<endl;
        return -1;
    }
    else
    {
        if (q->f != q->r)
        {
            int id = q->arr[q->f];
            q->f = (q->f + 1) % q->size;
            return id;
        }
        else
        {
            int id = q->arr[q->f];
            q->f = (q->f + 1) % q->size;
            q->f = -1;
            q->r = -1;
            return id;
        }
    }
}

int main(int argc, char const *argv[])
{
    Queue* q = new Queue;
    q->f = -1;
    q->r = -1;
    q->size = 5;
    q->arr = (int *)malloc(sizeof(int) * q->size);

    takeOrder(q,10);
    takeOrder(q,20);
    takeOrder(q,30);
    cout<<deliver(q)<<endl;
    cout<<deliver(q)<<endl;
    takeOrder(q,40);
    takeOrder(q,50);
    takeOrder(q,60);
    takeOrder(q,70);

    cout<<deliver(q)<<endl;
    cout<<deliver(q)<<endl;
    cout<<deliver(q)<<endl;
    cout<<deliver(q)<<endl;
    cout<<deliver(q)<<endl;
    cout<<deliver(q)<<endl;




    return 0;
}