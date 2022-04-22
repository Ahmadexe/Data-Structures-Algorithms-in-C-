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
        q->f = (q->f + 1) % q->size;
        q->r = (q->r + 1) % q->size;
        q->arr[q->f] = oid;
    }
    else
    {
        q->r += (q->r + 1) % q->size;
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
        int id = q->arr[q->f];
            q->f = (q->f + 1) % q->size;
        if (q->f != q->r)
        {
            return id;
        }
        else
        {
            q->f = -1;
            q->r = -1;
            return id;
        }
    }
}

int main(int argc, char const *argv[])
{
    
    return 0;
}