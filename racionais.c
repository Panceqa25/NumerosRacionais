/* acrescente demais includes que voce queira ou precise */
#include "racionais.h"
#include <stdio.h>
#include <stdlib.h>

/* 
 * Implemente neste arquivo as funções definidas no racionais.h.
 * Caso queira, você pode definir neste arquivo funções adicionais
 * que serão internas a este arquivo.
 *
 * Por exemplo, as funções aleat, mdc e mmc devem ser
 * implementadas neste arquivo.
*/

/* retorna um numero aleatorio entre min e max, inclusive. */
int aleat (int min, int max){
	return (min + rand()) % (max + 1);
}

/* Maximo Divisor Comum entre a e b      */
/* calcula o mdc pelo metodo de Euclides */
int mdc (int a, int b){
	int aux;
	while (a != 0) {
		aux = a;
		a = b%a;
		b = aux;
	}
	return b;
}

/* Minimo Multiplo Comum entre a e b */
/* mmc = (a * b) / mdc (a, b)        */
int mmc (int a, int b){
	return a*b/mdc(a,b);
}

/*void troca_r(struct racional v[], int a, int b) {
	struct racional aux;
	aux = v[a];
	v[a] = v[b];
	v[b] = aux;
}*/

int valido_r(struct racional r) {
	if (r.den == 0)
		return 0;
	return 1;
}

int numerador_r (struct racional r) {
	return r.num;
}

int denominador_r (struct racional r) {
	return r.den;
}

int compara_r (struct racional r1, struct racional r2) {
	if ((r1.num * r2.den) < (r1.den * r2.num))
		return -1;
	if ((r1.num * r2.den) == (r1.den * r2.num))
		return 0;
	return 1;
}

int simplifica_r (struct racional *r) {
	int max = mdc(r->num,r->den);
	//Divide o num e den pelo mdc entre eles para simplificar
	r->num /= max;
	r->den /= max;
	if (r->den < 0) {
		r->num *= -1;
		r->den *= -1;
	}
	//Se o racional eh invalido retorna 0
	if (r->valido == 0)
		return 0;
	return 1;	
}

struct racional cria_r (int numerador, int denominador) {
	struct racional cria;
	cria.num = numerador;
	cria.den = denominador;
	cria.valido = valido_r(cria);
	return cria;
}
	
struct racional sorteia_r (int n) {
	struct racional sorteio;
	int num, den;
	num = aleat(-n,n);
	den = aleat(-n,n);
	sorteio = cria_r(num,den);
	//Confere o racional eh valido antes de simplificar
	if (sorteio.valido == 1)
		simplifica_r(&sorteio);
	return sorteio;
}

int soma_r (struct racional r1, struct racional r2, struct racional *r3) {
	int min = mmc(r1.den,r2.den);
	r3->num = (r1.num*min/r1.den) + (r2.num*min/r2.den);
	r3->den = min;
	r3->valido = valido_r(*r3);
	//Se qualquer um dos 3 racionais for invalido, retorna 0
	if ((r1.valido == 0) || (r2.valido == 0) || (r3->valido == 0))
		return 0;
	simplifica_r(r3);
	return 1;
}

int subtrai_r (struct racional r1, struct racional r2, struct racional *r3) {
	int min = mmc(r1.den,r2.den);
	r3->num = (r1.num*min/r1.den) - (r2.num*min/r2.den);
	r3->den = min;
	r3->valido = valido_r(*r3);
	if ((r1.valido == 0) || (r2.valido == 0) || (r3->valido == 0))
		return 0;
	simplifica_r(r3);
	return 1;
}


int multiplica_r (struct racional r1, struct racional r2, struct racional *r3) {
	r3->num = r1.num * r2.num;
	r3->den = r1.den * r2.den;
	r3->valido = valido_r(*r3);
	if ((r1.valido == 0) || (r2.valido == 0) || (r3->valido == 0))
		return 0;
	simplifica_r(r3);
	return 1;

}

int divide_r (struct racional r1, struct racional r2, struct racional *r3) {
	r3->num = r1.num * r2.den;
	r3->den = r1.den * r2.num;
	r3->valido = valido_r(*r3);
	if ((r1.valido == 0) || (r2.valido == 0) || (r3->valido == 0))
		return 0;
	simplifica_r(r3);
	return 1;
}


void imprime_r (struct racional r) {
	if (r.valido == 0)
		printf("INVALIDO ");
	else if (r.num == 0)
		printf("%d ", 0);
	else if (r.den == 1)
		printf("%d ", r.num);
	else if (r.num == r.den)
		printf("%d ", 1);
	else
		printf("%d/%d ", r.num, r.den);
}
/* implemente aqui as funções declaradas em racionais.h */

