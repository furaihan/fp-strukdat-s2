#pragma once
#include "iostream"
#include "node.h"
#include "queue.h"
template <class T> class MyLinkedList
{
    Node<T> *head, *tail;
    public:
    MyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    MyLinkedList(Queue<T> q)
    {
        head = q.Head();
        tail = q.Tail();
    }
    //encapsulation for head element
    Node<T> *First()
    {
        return head;
    }
    //encapsulation for tail element
    Node<T> *Last()
    {
        return tail;
    }
    bool Empty()
    {
        return head == NULL;
    }
    int Count()
    {
        Node<T> *bantu = head;
        int counter = 0;
        while (bantu != NULL)
        {
            counter++;
            bantu = bantu->next;
        }
        return counter;
    }
    bool Contains(T item)
    {
        Node<T> *bantu = head;
        int counter = 1;
        while (bantu != NULL)
        {
            if (bantu->data == item) return true;
            bantu = bantu->next;
        }
        return false;
    }
    void AddLast(T item)
    {
        Node<T> *newNode = new Node<T>;
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
    }
    void AddFirst(T item)
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
    }
    //insert a new node to nth position
    void Insert(T item, int n)
    {
        Node<T> *newNode = new Node<T>;
        newNode->data = item;
        newNode->next = NULL;
        if (n == 1)
        {
            newNode->next = head;
            head = newNode;
            return;
        } 
        Node<T> *temp2 = head;
        for (int i = 0; i < n - 2; i++)
        {
            temp2 = temp2->next;
        }
        bool isLastElement = temp2 == tail;
        newNode->next = temp2->next;
        temp2->next = newNode;
        if (isLastElement) 
        {
            tail = newNode;
            tail->next = NULL;
        }
    }
    void RemoveFirst()
    {
        if (Empty())
        {
            return;
        }
        Node<T> *firstElem = head;
        head = head->next;
        delete firstElem;
    }
    void RemoveLast()
    {
        if (head == tail)
        {
            head = NULL;
            tail = NULL;
            return;
        }
        Node<T> *temp = head;
        Node<T> *del = tail;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        tail = temp;
        tail->next = NULL;
        delete del;
    }
    void RemoveAt(int index)
    {
        //TODO
    }
    void Clear()
    {
        Node<T> *bantu, * hapus;
        bantu = head;
        while (bantu->next != tail)
        {
            hapus = bantu;
            bantu = bantu->next;
            delete hapus;
        }
        head = NULL;
        tail = NULL;
    }
    void PrintList()
    {
        Node<T> *bantu = head;
        int counter = 1;
        while (bantu != NULL)
        {
            std::cout << "Data pada node #" << counter++ << " = " << bantu->data << std::endl;
            bantu = bantu->next;
        }
        std::cout << std::endl;
    }
};