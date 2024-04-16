#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_bst.h"
#include <stdio.h>

int main(void) {
  BST* bst= create_bst();
  if(bst==NULL){
    printf("Error al crear el BST\n");
  }
  return 0;
}