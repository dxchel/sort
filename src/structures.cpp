/*
 * Main structures code.
 * Here lies the code for the basic structures taken into account.
 *
 * Made by David Xchel Morales Hurtado
 */
#include "headers/structures.hpp"

template <typename T>
LLNode<T>::LLNode(T *value, LLNode<T> *next)
    :value(value), next(next) {};
template <typename T>
LLNode<T>::~LLNode(){
    delete value;
};


template <typename T>
LinkedList<T>::LinkedList(T *value)
    :length(0), head(nullptr) {
    /* Initialize everything to an empty LinkedList, if a value is given use it to make a node. */
    if(!value) return;

    this->head = new LLNode<T>(value);
    this->length = 1;
};
template <typename T>
LinkedList<T>::~LinkedList(){
    /* Delete all LinkedList Nodes. */
    LLNode<T> *prev = this->head;
    LLNode<T> *next = prev;
    while(next){
        next = prev->next;
        delete prev;
        prev = next;
    }
};

template <typename T>
T *LinkedList<T>::index(int index) const{
    /*
     * Get the element value at specific Index.
     * If negative index is used it will start from the last element, being -1 the last element.
     * If the index is out of bounds, return nullptr.
     */
    if(index >= this->length || index <= -this->length) return nullptr;
    else index = index%this->length;
    LLNode<T> *element = this->head;
    for(int i=0; i < index; i++) element = element->next;
    return element->value;
};
template <typename T>
void LinkedList<T>::insert(T *value, int index){
    /*
     * Insert the value as the node at index, default is to insert at the end.
     * If negative index is used it will start from the last element, being -1 to insert after last element.
     * If the index is out of bounds, return and do nothing.
     */
    if(index >= this->length || index < -this->length) return;
    index = (index + this->length + 1)%(this->length + 1);
    // Keep track of previous node for linking.
    LLNode<T> *prev = nullptr;
    LLNode<T> *element = this->head;
    for(int i=0; i < index; i++){
        prev = element;
        element = element->next;
    }
    element = new LLNode<T>(value, element);
    // Linking.
    if(prev) prev->next = element;
    else this->head = element;
    this->length += 1;
    return;
};
template <typename T>
T *LinkedList<T>::remove(int index){
    /*
     * Remove the node at index, default is to remove the last one.
     * If negative index is used it will start from the last element, being -1 the last element.
     * If the index is out of bounds, return nullptr and do nothing.
     */
    if(!this->length || index < -this->length || index >= this->length) return nullptr;
    index = (index + this->length)%this->length;
    // Keep track of previous node for linking.
    LLNode<T> *prev = nullptr;
    LLNode<T> *next = this->head;
    for(int i=0; i < index; i++){
        prev = next;
        next = next->next;
    }
    // Linking and node deletion.
    if(prev) prev->next = next->next;
    else this->head = next->next;
    this->length -= 1;
    T *value = new T(*next->value);
    delete next;
    return value;
};
template <typename T>
void LinkedList<T>::reverse(){
    /* Reverse the whole LinkedList, using tail as head and linking from there. */
    LLNode<T> *prev = nullptr;
    LLNode<T> *last = nullptr;
    LLNode<T> *next = this->head;
    while(next){
        prev = next;
        next = next->next;
        prev->next = last;
        last = prev;
    }
    this->head = prev;
};
template <typename T>
LLNode<T> *LinkedList<T>::iter() const{
    /* Get iterator by getting first element. */
    return this->head;
};
template <typename T>
std::string LinkedList<T>::str() const{
    /* Print the LinkedList in a readable way. */
    std::string representation = "[ ";
    LLNode<T> *element = this->head;
    while(element){
        representation += std::to_string(*element->value) + " ";
        element = element->next;
    }
    representation += "]";
    return representation;
};

template <typename T>
TNode<T>::TNode(T value, TNode<T> *left, TNode<T> *right)
    :value(value), left(left), right(right) {};
template <typename T>
TNode<T>::~TNode(){
    delete left;
    delete right;
};
template <typename T>
std::string TNode<T>::str() const{
    /* Get the Tree Node string representation. */
    return std::to_string(this->value) + "{" +
        (this->left ? this->left->str() : "") + ":" +
        (this->right ? this->right->str() : "") + "}";
};


template <typename T>
Tree<T>::Tree(){
    this->size = 0;
    this->root = nullptr;
};
template <typename T>
Tree<T>::~Tree(){
    delete this->root;
};
template <typename T>
int Tree<T>::get_size() const{
    return this->size;
};
template <typename T>
TNode<T> *Tree<T>::find(T value) const{
    /* find the value in the tree and return the node. */
    TNode<T> *node = this->root;
    while(node){
        if(value == node->value) break;
        node = value > node->value ? node->right : node->left;
    }
    return node;
};
template <typename T>
void Tree<T>::insert(T value){
    /* Insert an element with the value given into the tree. */
    TNode<T> **node = &(this->root);
    while(*node){
        if(value == (*node)->value){
            this->size -= 1;
            break;
        }
        node = value > (*node)->value ? &(*node)->right : &(*node)->left;
    }
    if(!*node) *node = new TNode(value);
    this->size += 1;
    return;
};
template <typename T>
std::string Tree<T>::str() const{
    /* Get Tree string representation in a readable way. */
    return this->root ? this->root->str() : "{}";
};
