/*
 * Code for the test cases used to check the correct functionality of the structures.
 *
 * Made by David Xchel Morales Hurtado
 */
#include "headers/test_structures.hpp"
#include "headers/structures_examples.hpp"

int test_LinkedList(){
    /* 
     * Make a series of operations on LinkedList for functionality check.
     */
    printf("Creating list with 1 ");
    LinkedList<int> *list = new LinkedList<int>(new int(1));
    std::cout << list->str() << std::endl;
    printf("Adding 2 ");
    list->insert(new int(2));
    std::cout << list->str() << std::endl;
    printf("Adding 3 ");
    list->insert(new int(3));
    std::cout << list->str() << std::endl;
    printf("Adding 4 ");
    list->insert(new int(4));
    std::cout << list->str() << std::endl;
    printf("Adding 5 into 2 ");
    list->insert(new int(5), 2);
    std::cout << list->str() << std::endl;
    printf("Adding 0 into 0 ");
    list->insert(new int(0), 0);
    std::cout << list->str() << std::endl;
    printf("Adding 6 into 2 ");
    list->insert(new int(6), 2);
    std::cout << list->str() << std::endl;
    printf("Adding -1 into -1 ");
    list->insert(new int(-1), -1);
    std::cout << list->str() << std::endl;
    printf("Adding 100 into 100 ");
    list->insert(new int(100), 100);
    std::cout << list->str() << std::endl;
    list->reverse();
    std::cout << "And now reversed!" << list->str() << std::endl;
    std::cout << "Here's index 4! " << *(list->index(4)) << list->str() << std::endl;
    std::cout << "Using iterator in for loop" << std::endl;
    LLNode<int> *iter = list->iter();
    while(iter != nullptr){
        std::cout << "Element " << *(iter->value) << std::endl;
        iter = iter->next;
    }
    delete iter;
    std::cout << "Removing index 3: " << *list->remove(3) << list->str() << std::endl;
    std::cout << "Removing last index: " << *list->remove() << list->str() << std::endl;
    std::cout << "Removing index 20 (nullptr): " << list->remove(20) << list->str() << std::endl;
    std::cout << "Removing last index: " << *list->remove() << list->str() << std::endl;
    std::cout << "Removing last index: " << *list->remove() << list->str() << std::endl;
    std::cout << "Removing last index: " << *list->remove() << list->str() << std::endl;
    std::cout << "Removing last index: " << *list->remove() << list->str() << std::endl;
    std::cout << "Removing last index: " << *list->remove() << list->str() << std::endl;
    std::cout << "Removing last index: " << *list->remove() << list->str() << std::endl;
    std::cout << "Removing last index: " << list->remove() << list->str() << std::endl;
    delete list;
    return 0;
};

int test_Tree(){
    /* 
     * Make a series of operations on Tree for functionality check.
     */
    printf("Creating map \n");
    Tree<int> *tree = new Tree<int>();
    std::cout << tree->str() << " Size: " << tree->get_size() << std::endl;
    printf("Adding 2 \n");
    tree->insert(2);
    std::cout << tree->str() << " Size: " << tree->get_size() << std::endl;
    printf("Adding 5 \n");
    tree->insert(5);
    std::cout << tree->str() << " Size: " << tree->get_size() << std::endl;
    printf("Adding 3 \n");
    tree->insert(3);
    std::cout << tree->str() << " Size: " << tree->get_size() << std::endl;
    printf("Adding 1 \n");
    tree->insert(1);
    std::cout << tree->str() << " Size: " << tree->get_size() << std::endl;
    printf("Adding 2 \n");
    tree->insert(2);
    std::cout << tree->str() << " Size: " << tree->get_size() << std::endl;
    printf("Finding 7 \n");
    std::cout << (tree->find(7) ? tree->find(7)->value : 0) << std::endl;
    printf("Finding 3 \n");
    std::cout << (tree->find(3) ? tree->find(3)->value : 0) << std::endl;
    printf("Adding -1 \n");
    tree->insert(-1);
    std::cout << tree->str() << " Size: " << tree->get_size() << std::endl;
    printf("Adding 10 \n");
    tree->insert(10);
    std::cout << tree->str() << " Size: " << tree->get_size() << std::endl;
    printf("Adding 8 \n");
    tree->insert(8);
    std::cout << tree->str() << " Size: " << tree->get_size() << std::endl;
    delete tree;
    return 0;
};
