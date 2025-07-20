#include <stdio.h> 
int main(void){ 
  int numero = 10;  
  int * ptr; 
  ptr = &numero;
  printf("Valor de numero:%d\n",numero);  
  printf("endereco de numero:%p\n",&numero);  
  printf("valor do ponteiro:%p\n",ptr);  
  printf("valor apontado pelo ponteiro:%d\n", *ptr);  
  *ptr = 20; 
  printf ("valor modificado de numero: %d\n", numero);
  /*int n1,n2,n3, retorno = 0;
  char var;
  do {
    printf("Informe 3 numeros inteiros: \n");
    retorno = scanf("%d%d%d", &n1,&n2,&n3);
    while((var = getchar()) != '\n');
  } while(retorno != 3);
  printf("%d, %d e %d\n", n1,n2,n3);*/
  return 0;  
} 