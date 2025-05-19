/*
 * Initializer of templated structures with common data types.
 *
 * Made by David Xchel Morales Hurtado
 */
#ifndef INITS
#define INITS
void initializer(){
    /* Initialize linked lists for int, float, double and char data types */
    LinkedList<int> init_ll_int;
    LinkedList<float> init_ll_float;
    LinkedList<double> init_ll_double;
    LinkedList<char> init_ll_char;
    /* Initialize trees for int, float, double and char data types */
    Tree<int> init_t_int;
    Tree<float> init_t_float;
    Tree<double> init_t_double;
    Tree<char> init_t_char;
}
#endif
