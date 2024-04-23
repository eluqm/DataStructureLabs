# Laboratorio - Trie (Parte01)
Para esta tarea, explorarás cómo escribir un árbol Trie, junto con algunas
Funciones de utilidad para el árbol. También explorarás el concepto de
recursividad y cómo se puede utilizar para simplificar el código.

## Archivos proporcionados
En esta opotunidad no se le proporcionará los archivos, pero como parte de la tarea DEBE dividir el código de "implementación" para que
parezca más a un programa C estándar (PUEDE TOMAR COMO REFERENCIA EL LABORATORIO ANTERIOR), para presentar su tarea debe tener la siguiente estructura:

* [my_bst.h](my_trie.h) - Este es el archivo de encabezado de su Trie. Debe contener los prototipos de funciones para las funciones que implementará.
* [my_bst.c](my_trie.c) - Este es el archivo de implementación para su Trie. Contiene las definiciones de funciones para las funciones que implementará relacionadas con la **estructura** del TRIE.
* [bst_main.c](bst_main.c) - Este es el archivo principal de su Trie. Contiene la función principal y el código para probar su Trie. Debe agregar sus pruebas a este archivo y ejecutarlo para probar su bst.
 
👉🏽 **Tarea** 👈🏽 Tómate el tiempo para GENERAR los archivos. Deberían compilarse sin problemas en este punto. 

## Árbol Trie
Como recordatorio, un Trie, es un árbol N-ario, con el número de hijos para cada nodo relacionado a las letras del alfabeto 
En este laboratorio usamos la siguiente estructura proporcionada.


```c
// The number of children for each node
// We will construct a N-ary tree and make it
// a Trie
// Since we have 26 english letters, we need
// 26 children per node
#define N 26

typedef struct TrieNode TrieNode;

struct TrieNode {
    // The Trie Node Structure
    // Each node has N children, starting from the root
    // and a flag to check if it's a leaf node
    char data; // Storing for printing purposes only
    TrieNode* children[N];
    int is_leaf;
};

```
