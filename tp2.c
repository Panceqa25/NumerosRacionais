#include "racionais.h"
#include <stdio.h>
#include <stdlib.h>

int main () {
	int n, menor, max = 20;
	struct racional r3, aux, v[100];
	
	srand(20);
	printf("Informe o tamanho do vetor: ");
	scanf("%d", &n);

	//Preenche o vetor com racionais aleatorios
	for (int i = 0; i < n; i++)
		v[i] = sorteia_r(max);

	//Imprime o vetor gerado anteriormente
	for (int i = 0; i < n; i++)
		imprime_r(v[i]);
	printf("\n");

	//Busca um elemento invalido, se encontrar, move todos os numeros
	//para a esquerda e diminui o tamanho do vetor
	for (int i = 0; i < n; i++)
		if (v[i].valido == 0) {
			for (int j = i; j < n; j++)
				v[j] = v[j+1];
			n--;
			i--;
		}
	
	//Algoritmo de SelectionSort para ordenar o vetor
	for (int j = 0; j < n; j++) {
		menor = j;
		for (int i = j+1; i < n; i++)
			if (compara_r(v[i],v[menor]) == -1)
				menor = i;
		aux = v[j];
		v[j] = v[menor];
		v[menor] = aux;
	}
		
	//Imprime o vetor ordenado
	for (int i = 0; i < n; i++)
		imprime_r(v[i]);
	printf("\n");
	
	//Soma os elementos do vetor e imprime o resultado
	aux = v[0];
	for (int i = 1; i < n; i++) {
		soma_r(aux,v[i],&r3);
		aux = r3;
	}
	printf("A soma dos elementos vale: ");
	imprime_r(aux);
	printf("\n");

    return 0;
}
