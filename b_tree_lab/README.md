
# Laboratorio - B-tree (Parte01)
Para esta tarea, entenderás como funciona un b-tree, junto con algunas
funciones de utilidad para el árbol. También explorarás el concepto de
recursividad y cómo se puede utilizar para simplificar el código.

## Archivos proporcionados
En esta oportunidad no se le proporcionará los archivos, pero como parte de la tarea DEBE dividir el código de "implementación" para que
parezca más a un programa C estándar (PUEDE TOMAR COMO REFERENCIA EL LABORATORIO ANTERIOR), para presentar su tarea debe tener la siguiente estructura:

* [b_tree.h](b_tree.h) - Este es el archivo de encabezado de su B-tree. Debe contener los prototipos de funciones para las funciones que implementará.
* [b_tree.c](b_tree.c) - Este es el archivo de implementación para su B-tree. Contiene las definiciones de funciones para las funciones que implementará relacionadas con la **estructura** del B-tree.
* [main.c](main.c) - Este es el archivo principal de su B-tree. Contiene la función principal y el código para probar su B-tree. Debe agregar sus pruebas a este archivo y ejecutarlo para probar su B-tree.

👉🏽 **Tarea** 👈🏽 Tómate el tiempo para GENERAR los archivos. Deberían compilarse sin problemas en este punto.

## Árbol B-tree
Propiedades del B-Tree:
* Todos las hojas están en el mismo nivel.
* El B-Tree está definido por el término grado mínimo ‘t‘.
* Cada nodo excepto el raíz debe contener al menos t-1 llaves. La raíz puede contener un mínimo de 1 llave.
* Todos los nodos (incluida la raíz) pueden contener como máximo (2*t – 1) llaves.
* El número de hijos de un nodo es igual al número de llaves en él más 1.
* Todas las llaves de un nodo están ordenadas en orden creciente. El hijo entre dos llaves k1 y k2 contiene todas las llaves en el rango de k1 y k2.
* El B-Tree crece y se reduce desde la raíz, a diferencia del Árbol de Búsqueda Binaria. Los Árboles de Búsqueda Binaria crecen hacia abajo y también se reducen hacia abajo.
* Al igual que otros Árboles de Búsqueda Binaria equilibrados, la complejidad temporal para buscar, insertar y eliminar es O(log n).
* La inserción de un nodo en un B-Tree ocurre solo en un nodo hoja.

A continuación se muestra un ejemplo de un B-Tree de orden mínimo 5.
Nota: que en B-Trees prácticos, el valor del orden mínimo es mucho más que 5.

<center>

![B-tree Add](output253.png)

</center>
👉🏽 En este laboratorio usamos la siguiente estructura proporcionada👈🏽

```c
#define MAX_KEYS 4

struct BTreeNode {
  int num_keys;
  int keys[MAX_KEYS];
  struct BTreeNode *children[MAX_KEYS + 1];
};

```
👉🏽 **Tarea** 👈🏽 ENTIENDA Y EXPLIQUE, su tarea es ENTENDER completamente todo lo proporcionado.
### Implementaciones de funciones

Le sugerimos ENTENDER las siguientes funciones en el siguiente orden:
* createNode():
```c
struct BTreeNode *createNode() {
  struct BTreeNode *newNode =
      (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
  if (newNode == NULL) {
    printf("La asignación de memoria falló.\n");
    exit(1);
  }
  newNode->num_keys = 0;
  for (int i = 0; i < MAX_KEYS + 1; i++) {
    newNode->children[i] = NULL;
  }
  return newNode;
}
```
* insert():
```c
void insert(struct BTreeNode **root, int key) {
  if (*root == NULL) {
    *root = createNode();
    (*root)->keys[0] = key;
    (*root)->num_keys = 1;
  } else {
    if ((*root)->num_keys == MAX_KEYS) {
      struct BTreeNode *newRoot = createNode();
      newRoot->children[0] = *root;
      splitChild(newRoot, 0);
      *root = newRoot;
    }
    insertNonFull(*root, key);
  }
}
```

* splitChild():
```c
void splitChild(struct BTreeNode *parent, int index) {
  struct BTreeNode *child = parent->children[index];
  struct BTreeNode *newChild = createNode();
  newChild->num_keys = MAX_KEYS / 2;
  for (int i = 0; i < MAX_KEYS / 2; i++) {
    newChild->keys[i] = child->keys[i + MAX_KEYS / 2 + 1];
  }
  if (child->children[0] != NULL) {
    for (int i = 0; i < MAX_KEYS / 2 + 1; i++) {
      newChild->children[i] = child->children[i + MAX_KEYS / 2 + 1];
    }
  }
  child->num_keys = MAX_KEYS / 2;
  for (int i = parent->num_keys; i >= index + 1; i--) {
    parent->children[i + 1] = parent->children[i];
  }
  parent->children[index + 1] = newChild;
  for (int i = parent->num_keys - 1; i >= index; i--) {
    parent->keys[i + 1] = parent->keys[i];
  }
  parent->keys[index] = child->keys[MAX_KEYS / 2];
  parent->num_keys++;
}
```

* insertNonFull():
```c
void insertNonFull(struct BTreeNode *node, int key) {
  int i = node->num_keys - 1;
  if (node->children[0] == NULL) {
    insertKey(node, key);
    return;
  }
  while (i >= 0 && node->keys[i] > key) {
    i--;
  }
  i++;
  if (node->children[i]->num_keys == MAX_KEYS) {
    splitChild(node, i);
    if (node->keys[i] < key) {
      i++;
    }
  }
  insertNonFull(node->children[i], key);
}
```

* insertKey():
```c
void insertKey(struct BTreeNode *node, int key) {
  int i = node->num_keys - 1;
  while (i >= 0 && node->keys[i] > key) {
    node->keys[i + 1] = node->keys[i];
    i--;
  }
  node->keys[i + 1] = key;
  node->num_keys++;
}
```

## 👉🏽 **Tarea** 👈🏽:
pruebe el funcionamiento del arbol insertando la siguiente secuencia de datos(IMPLEMENTE EL MAIN):
[ 30, 7, 17,10, 20, 5, 6, 12,0,678,234,567]



