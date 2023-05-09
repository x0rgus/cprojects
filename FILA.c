#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 10
//define tamanho maximo da fila

typedef struct T_FILA{
	int nomes[tam];
	int horas[tam];
	int fim;
}T_FILA;

//inicializar fila
void inicializaFila(T_FILA *f){
	int i;
	for(i=0;i<tam;i++){
		f->nomes[i] = 0;
		f->horas[i] = 0;
	}
	f->fim = 0;
} 

void enfileira(int hora, int nome, T_FILA *f){
	//verifica se fila esta cheia antes
	if(f->fim == tam){
		printf("A fila esta cheia.\n");
		sleep(1);
	return;
	}else{
		f->nomes[f->fim] = nome;
		f->horas[f->fim] = hora;
		//recebe HORA e NOME e armazena no final da fila em NOMES e HORAS
		f->fim++;
		//incrementa o valor de fim pois um valor foi inserido
	}
}
//a funcao desenfileirar não pode ser do tipo void pois ela retorna o valor que vai ser removido da lista
int desenfileira(T_FILA *f){
	int temphora;
	int tempnome;
	int i;
	//verifica se a lista não esta vazia
	if(f->fim == 0){
		printf("A fila esta vazia.\n");
		return;
	}else{
		temphora = f->horas[0];
		tempnome = f->nomes[0];
		for(i=0;i,f->fim;i++){
			f->horas[i] = f->horas[i+1];
			f->nomes[i] = f->nomes[i+1];
		}
		f->fim--;
		return temphora, tempnome;
	}
}

void imprimefila(T_FILA *f){
	int i;
	printf("imprimindo a fila:\n");
	for(i=0;i<f->fim;i++){
		printf("%d \n\n", f->horas[i]);
		printf("%d ", f->nomes[i]);
	}
}

int main(){
	T_FILA f1;
	//testando a fila
	inicializaFila(&f1);
	//inserindo um valor para representar o nome e outro a hora, inserindo um a mais para testar a verificação se a fila esta cheia ou não
	enfileira(10, 1, &f1);
	enfileira(15, 2, &f1);
	enfileira(20, 3, &f1);
	enfileira(25, 4, &f1);
	enfileira(30, 5, &f1);
	enfileira(35, 6, &f1);
	enfileira(40, 7, &f1);
	enfileira(50, 8, &f1);
	enfileira(60, 9, &f1);
	enfileira(70, 10, &f1);
	enfileira(75, 11, &f1);

	imprimefila(&f1);
	
	printf("desenfileirando fila... \n\n");
	sleep(5);
	desenfileira(&f1);
	//testando se fila realmente esta vazia depois de desenfileirar
	printf("Imprimindo fila... \n\n");
	imprimefila(&f1);
}
