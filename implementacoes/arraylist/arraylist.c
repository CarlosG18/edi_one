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
    //TODO
}

void inserirElementoNoFim(struct arraylist* lista, int valor) {
     
    /*if(lista->qtdade == lista->capacidade){
       duplicarCapacidade(lista);
    }*/

    lista->vetor[lista->qtdade] = valor;
    lista->qtdade++;
}

void inserirElementoEmPosicao(struct arraylist* lista, int valor, int posicao) {
    


}

void atualizarElemento(struct arraylist* lista, int valor, int posicao) {
    lista->vetor[posicao] = valor;
}

void removerElementoNoFim(struct arraylist* lista) {
    lista->qtdade--;
}

void removerElementoEmPosicao(struct arraylist* lista, int posicao) {
    
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

int  main(){

    int capacidade = 10;

    struct arraylist* lista = inicializar(capacidade);

    inserirElementoNoFim(lista, 50);
    inserirElementoNoFim(lista, 40);
    inserirElementoNoFim(lista, 30);
    inserirElementoNoFim(lista, 20);
    inserirElementoNoFim(lista, 10);
    printf("o valor do index 2 = %d", obterElementoEmPosicao(lista,2));
    exibirLista(lista);




    return 0;
}
