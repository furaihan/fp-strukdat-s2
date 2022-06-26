#pragma once
#include "iostream"
#include "node.h"

template <class T> class Queue
{
    private:
    Node<T> *head, *tail;

    public:
    Queue()
    {
        *head = *tail = NULL;
    }
    Node<T> *Head()
    {
        return head;
    }
    Node<T> *Tail()
    {
        return tail;
    }
    bool Empty()
    {
        return head = NULL;
    }
    void Enqueue(T item)
    {
        Node<T> *temp = new Node<T>;

        temp->data = item;
        temp->next = NULL;
        if (Empty())
        {
            head = tail = temp;
            return;
        }
        tail->next = temp;
        tail = temp;
    }
    void Dequeue()
    {
        if (Empty())
        {
            return;
        }
        Node<T> hapus = head;
        head = head->next;
        if (Empty())
        {
            tail = NULL;
        }
        delete hapus;
    }

};