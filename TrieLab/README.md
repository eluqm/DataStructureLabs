# Laboratorio - Trie (Parte01)
Para esta tarea, explorarás cómo escribir un árbol Trie, junto con algunas
Funciones de utilidad para el árbol. También explorarás el concepto de
recursividad y cómo se puede utilizar para simplificar el código.

## Archivos proporcionados
En esta opotunidad no se le proporcionará los archivos, pero como parte de la tarea DEBE dividir el código de "implementación" para que
parezca más a un programa C estándar (PUEDE TOMAR COMO REFERENCIA EL LABORATORIO ANTERIOR), para presentar su tarea debe tener la siguiente estructura:

* [my_trie.h](my_trie.h) - Este es el archivo de encabezado de su Trie. Debe contener los prototipos de funciones para las funciones que implementará.
* [my_trie.c](my_trie.c) - Este es el archivo de implementación para su Trie. Contiene las definiciones de funciones para las funciones que implementará relacionadas con la **estructura** del TRIE.
* [trie_main.c](trie_main.c) - Este es el archivo principal de su Trie. Contiene la función principal y el código para probar su Trie. Debe agregar sus pruebas a este archivo y ejecutarlo para probar su bst.
 
👉🏽 **Tarea** 👈🏽 Tómate el tiempo para GENERAR los archivos. Deberían compilarse sin problemas en este punto. 

## Árbol Trie
Como recordatorio, un Trie, es un árbol N-ario, con el número de hijos para cada nodo relacionado a las letras del alfabeto 
En este laboratorio usamos la siguiente estructura proporcionada.


```c
// El número de hijos para cada nodo.
// Construiremos un árbol M-ario
// Como tenemos 26 letras en inglés, necesitamos
// 26 hijos por nodo
#define M 26

typedef struct TrieNode TrieNode;

struct TrieNode {
    // La estructura del nodo Trie
    // Cada nodo tiene M hijos, comenzando desde la raíz
    // y un flag para comprobar si es un nodo hoja palabra (word)
    char data; // almacena el caracter 
    TrieNode* children[M];
    int is_leaf;
};

```

👉🏽 **Tarea** 👈🏽 Implemente cada función a continuación, cada función tiene comentarios encima que documentan lo que hace, su tarea es implementar completamente todo lo proporcionado, mientras agrega funciones auxiliares adicionales según sea necesario.

### Implementaciones de funciones

Le sugerimos implementar las siguientes funciones en el siguiente orden:
* make_trienode():
```c
// Función que crea un nuevo nodo en el Trie
TrieNode* make_trienode(char data) {
    // OJO: acá usamos la función calloc, cual crees que es la diferencia con malloc ? 
    TrieNode* node = (TrieNode*) calloc (1, sizeof(TrieNode));
    // TODO: complete la inicialización del Trie
    return node;
}
```
* bst_free - Piensa en qué recorrido DFS usarías para liberar el árbol.
```c
// Inserta la palabra en el Trie
// SUPUESTO: La palabra solo tiene caracteres en minúscula
TrieNode* insert_trie(TrieNode* root, char* word) {
    // TODO: complete la inserción de una palabra en el Trie
    return root;
}
```
* print_trie
```c
// Imprime los nodos de un Trie
void print_trie(TrieNode* root) {
    if (!root)
        return;
    TrieNode* temp = root;
    printf("%c -> ", temp->data);
    for (int i=0; i<N; i++) {
        print_trie(temp->children[i]); 
    }
}
```
### Inserte e Imprima 
inserte e imprima las siguientes palabras :
[trie_main.c](trie_main.c)
```c
TrieNode* trie = make_trienode('\0');
    trie = insert_trie(trie, "hello");
    trie = insert_trie(trie, "hi");
    trie = insert_trie(trie, "teabag");
    trie = insert_trie(trie, "teacan");
print_trie(root);
```
