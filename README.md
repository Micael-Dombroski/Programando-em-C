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
# Alocação Dinâmica de Memória
## Por que dinâmico?
Porque a memória é alocada em tempo de execução, não de compilação.
## Funções
- ```malloc(quantidade de bytes)```: para alocar uma quantia de bytes de forma dinâmica na memória, a função retorna um endereço para a memória alocada. Retorna um ponteiro ````NULL``` se não conseguir alocar a memória.
- ```calloc(quantidade de elementos, bytes de 1 elemento)```: funciona da mesma forma que malloc mas não é necessário fazer a conta de bytes necessários com base na quantidade de elementos que quer alocar com o ponteiro. Também retorna um ponteiro ````NULL``` se não conseguir alocar a memória.
- ```realloc(pointeiro, numero de elementos)```: realoca a memória, usado quando se quer aumentar ou diminuir o espaço reservado na memória para um ponteiro.
- ```free()```:
Em C os arrays são estáticos: seus tamanhos são fixos durante a compilação, o que pode acarretar em espaço insuficiente ou desperdício de memória.
