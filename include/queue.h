#pragma once
#include "iostream"
#include "node.h"

template <class T> class Queue
{
    private:
    Node<T> *head, *tail;
    int count;

    public:
    Queue()
    {
        head = tail = NULL;
        count = 0;
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
    int Count()
    {
        return count;
    }
    void Enqueue(T item)
    {
        Node<T> *newNode = new Node<T>;
        newNode->data = item;
        if (Empty())
        {
            newNode->next = NULL;
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
        count++;
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
        count--;
        delete hapus;
    }

};