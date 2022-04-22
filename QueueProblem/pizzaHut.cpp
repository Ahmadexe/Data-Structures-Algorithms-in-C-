#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Queue
{
    int f = -1;
    int r = -1;
    int size;
    string *arr;
};

int isEmpty(Queue* q)
{
    return (q->f == -1 && q->r == -1);
}

int isFull(Queue * q)
{
    return ((q->r + 1) % q->size == q->f);
}

void takeOrder(Queue* q, string oid)
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

string deliver(Queue* q)
{
    if (isEmpty(q))
    {
        return "No pending orders";
        
    }
    else
    {
        if (q->f != q->r)
        {
            string id = q->arr[q->f];
            q->f = (q->f + 1) % q->size;
            return id;
        }
        else
        {
            string id = q->arr[q->f];
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
    int M;
    cout<<"Enter total number of accepted orders"<<endl;
    q->size = M;
    q->arr = (string *)malloc(sizeof(int) * q->size);

    while (1)
    {
        int choiceMain;
        cout<<"1. Enter as customer\n"<<"2. Login as admin"<<endl<<"3. Exit"<<endl;
        cin>>choiceMain;
        if (choiceMain == 1)
        {
            int choiceC;
            cout<<"1. Place order"<<endl<<"2. Exit"<<endl;
            cin>>choiceC;
            if (choiceC == 1)
            {

            }
        }
    }
    




    return 0;
}