#include <stdio.h>
#include <stdlib.h>

struct arraylist {
    int* vetor;
    int qtdade;
    int capacidade;
};

struct arraylist* inicializar(int capacidade) {
    struct arraylist* lista = (struct arraylist*)malloc(sizeof(struct arraylist));
    lista->vetor = (int*)calloc(capacidade, sizeof(int));
    lista->qtdade = 0;
    lista->capacidade = capacidade;
    return lista;
}

int obterElementoEmPosicao(struct arraylist* lista, int posicao) {
  return lista->vetor[posicao];
}

void duplicarCapacidade(struct arraylist* lista) {
    int* vetor_aux = (int*) calloc(2 * lista->capacidade, sizeof(int));
    for(int i=0; i<lista->capacidade; i++){
      vetor_aux[i] = lista->vetor[i];
    }
    free(lista->vetor);
    lista->vetor = vetor_aux;
}

void inserirElementoNoFim(struct arraylist* lista, int valor) {
  if(lista->qtdade == lista->capacidade){
    duplicarCapacidade(lista);
  }

  lista->vetor[lista->qtdade] = valor;
  lista->qtdade++;
}

void inserirElementoEmPosicao(struct arraylist* lista, int valor, int posicao) {
  lista->qtdade++;
  for(int i=lista->qtdade-1; i>posicao; i--){
    lista->vetor[i] = lista->vetor[i-1]; 
  }
  lista->vetor[posicao] = valor;
}

void atualizarElemento(struct arraylist* lista, int valor, int posicao) {
    lista->vetor[posicao] = valor;
}

void removerElementoNoFim(struct arraylist* lista) {
  lista->qtdade--;
}

void removerElementoEmPosicao(struct arraylist* lista, int posicao) {
  for(int i=posicao; i<lista->qtdade-1; i++){
    lista->vetor[i] = lista->vetor[i+1];
  }
  lista->qtdade--;
}

void exibirLista(struct arraylist* lista) {
    printf("[");
    for (int i = 0; i < lista->qtdade; i++) {
        printf("%d", lista->vetor[i]);
        if (i < lista->qtdade - 1) {
            printf(", ");
        }
    }
    printf("]");
}
