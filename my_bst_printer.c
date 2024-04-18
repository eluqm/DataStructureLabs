/**
 * Funciones de impresión de árboles.
 * Puede utilizar el código de solución proporcionado con ese laboratorio.
 *
 *@autor TU NOMBRE
 * semestre: TU SEMESTRE
 */
#include "my_bst.h"
#include <stdio.h>
#include <string.h>

void print_single_node(Node *node) { printf("%d ", node->data); }

/** inOrder */
void printTreeInOrder(Node *root) {}

/** post order */
void printTreePostOrder(Node *root) {}

/** pre order*/
void printTreePreOrder(Node *root) {}

/**
 * Imprime el árbol según el tipo de impresión especificado.
 * Un nodo con un *espacio* entre cada nodo. (no tienes que preocuparte por el
 * espacio final) Por ejemplo, si el árbol es A->B, A->C, B->D, B->E, C->F,
 * C->G, la salida del pedido anticipado debe ser A B D E C F G
 *
 * Debe utilizar funciones independientes para cada tipo de impresión.
 * Los tipos de impresión aceptados son
 * - "inorder"
 * - "preorder"
 * - "postorder"
 * CONSEJO: SI USA CHATGTP ENTIENDA PORFAVOR EL CóDIGO
 * Si se proporciona un tipo de impresión no válido, imprima un mensaje de
 * error.
 */
void bst_print(BST *tree, char *print_type) {}
