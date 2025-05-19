/*
 * Header for the common structures used within the code.
 *
 * Made by David Xchel Morales Hurtado
 */
#ifndef STRUCTS
#define STRUCTS

#include <cstdlib>
#include <iostream>
#include <string>

template <typename T>
struct LLNode{
    /* LinkedList Node class with pointer to next node and a value. */
    T *value;
    LLNode<T> *next;
    LLNode(T *value, LLNode<T> *next = nullptr);
    ~LLNode();
};

template <typename T>
class LinkedList{
    /* LinkedList class with pointer to head node and functions for inserting, removing, reversing and readable representation. */
    int length;
    LLNode<T> *head;

public:
    LinkedList(T *value=nullptr);
    ~LinkedList();
    T *index(int index) const;
    void insert(T *value, int index=-1);
    T *remove(int index=-1);
    void reverse();
    LLNode<T> *iter() const;
    std::string str() const;
};
    

template <typename T>
struct TNode{
    /* LinkedList Node class with pointer to next node and a value. */
    T value;
    TNode<T> *left;
    TNode<T> *right;
    TNode(T value, TNode<T> *left = nullptr, TNode<T> *right = nullptr);
    ~TNode();
    std::string str() const;
};

template <typename T>
class Tree{
    /* Tree class with pointer to root node and functions for inserting, removing, reversing and readable representation. */
    int size;
    TNode<T> *root;

public:
    Tree();
    ~Tree();
    int get_size() const;
    TNode<T> *find(T value) const;
    void insert(T value);
    void remove(T value);
    std::string str() const;
};
#endif
