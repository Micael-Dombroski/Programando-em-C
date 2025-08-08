# Dicas
* Para garantir que o formato do input do usuário seja o requisitado:
```
int num; // variavel numerica
int retorno; // recebe o retorno de scanf (soma 1 para cada atribuição correta)
char c; //usado para limpar o buffer do teclado
do {
  retorno = scanf("%d", &num); // se o input for igual ao tipo esperado retorna 1
  while((c = getchar()) != '\n'); // limpando buffer do teclado
} while (retorno !=1);
// o scanf e usado apenas para atribuir valor a uma variável,
// por isso esperamos que o retorno seja 1, caso fossem N variáveis
// o retorno esperado deveria ser N, indicando que todas foram
// preenchidas corretamente
```
* Use a função ```fgets()``` da biblioteca ```string.h``` para ler strings ou então formate o ```scanf()``` para definir o tamanho máximo do input do usuário, por exemplo: ```scanf("%50[^\n]", string)```, desse forma a string terá no máximo 50 letras e a leitura se encerrará ao pressionar ```Enter```.
* Como criar um struct:
```
typedef struct {
  //Aqui você coloca as variáveis que compõem o struct mas sem inicializar elas.
} NomeDoStruct;
```
