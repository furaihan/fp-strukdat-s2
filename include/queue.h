#pragma once
#include "iostream"
#include "node.h"

class Queue
{
    private:
    Node *head, *tail;
    int count;

    public:
    Queue()
    {
        head = tail = NULL;
        count = 0;
    }
    Node *Head()
    {
        return head;
    }
    Node *Tail()
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
    void Enqueue(Player item)
    {
        Node *newNode = new Node;
        newNode->data = item;
        if (Empty())
        {
            head = newNode;
        }
        else
        {
            tail->next = newNode;
        }
        tail = newNode;
        tail->next = NULL;
        count++;
    }
    void Dequeue()
    {
        if (Empty())
        {
            return;
        }
        Node *hapus = head;
        head = head->next;
        if (Empty())
        {
            tail = NULL;
        }
        count--;
        delete hapus;
    }
    void Clear()
    {
        Node *bantu, * hapus;
        bantu = head;
        while (bantu->next != tail)
        {
            hapus = bantu;
            bantu = bantu->next;
            delete hapus;
        }
        head = NULL;
        tail = NULL;
        count = 0;
    }
};