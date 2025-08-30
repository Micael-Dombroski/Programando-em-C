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
Porque a memória é alocada em tempo de execução, não de compilação (alocação estática).
## Qual a utilidade?
É útil quando não sabemos previamente o tamanho do array ou estrutura que será usada, evitando tanto desperdício quanto falta de memória.
## Funções
- ```malloc(quantidade de bytes)```: para alocar uma quantia de bytes de forma dinâmica na memória, a função retorna um endereço para a memória alocada. Retorna um ponteiro ```NULL``` se não conseguir alocar a memória. A memória alocada não é inicializada, podendo conter lixo de memória.
```
int *v = malloc(10 * sizeof(int));
if (v == NULL) {
    printf("Erro de alocação!\n");
}
```
- ```calloc(quantidade de elementos, bytes de 1 elemento)```: funciona da mesma forma que malloc mas não é necessário fazer a conta de bytes necessários com base na quantidade de elementos que quer alocar com o ponteiro. Também retorna um ponteiro ```NULL``` se não conseguir alocar a memória.
```
int *v = calloc(10, sizeof(int));
if (v == NULL) {
    printf("Erro de alocação!\n");
}
```
- ```realloc(pointeiro, numero de elementos)```: realoca a memória, usado quando se quer aumentar ou diminuir o espaço reservado na memória para um ponteiro.
```
int *v = malloc(5 * sizeof(int));
v = realloc(v, 10 * sizeof(int)); // agora são 10 inteiros

```
- ```free()```: libera a memória alocada dinamicamente para ser reutilizada pois o sistema não libera automaticamente essa memória quando fora de uso (a menos que o programa termine). É uma boa prática atribuir ```NULL``` ao ponteiro para evitar acessos inválidos.
```
free(v);
v = NULL;
```
