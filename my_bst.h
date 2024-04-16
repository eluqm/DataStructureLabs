/**
 * Contiene información para una estructura de datos de árbol de búsqueda binaria (BST).
 *@autor TU NOMBRE
 * Semestre TU SEMESTRE
*/
#ifndef MYBST_H 
#define MYBST_H

#include <stdbool.h>
#include <stdlib.h>

// usar para print_type en bst_print
#define INORDER "inorder"
#define PREORDER "preorder"
#define POSTORDER "postorder"
#define BREADTHFIRST "breadthfirst"

// Crea una estructura de datos Node para almacenar datos dentro
// nuestro BST. En nuestro caso, almacenaremos 'enteros'

typedef struct Node
{
    int data;                    //data almacenado en el nodo
    struct Node *left;  // puntero al nodo izquierdo
    struct Node *right; // puntero al nodo derecho
} Node;

// Nuestra estructura de datos del árbol de búsqueda binaria
// Nuestro BST contiene un puntero al nodo raíz de nuestro BST.
// Esto ayuda a proteger el nodo raíz de perder hijos accidentalmente

typedef struct tree
{
    unsigned int size;  //  size realiza un seguimiento de cuántos elementos hay en el BST.
    Node *root;         //  puntero al nodo raíz del BST
    
} BST;

// lo siguiente debe implementarse en my_bst.c
int bst_add(BST *tree, int value);
BST * create_bst(); 
void bst_print(BST *tree, char* print_type);

#endif