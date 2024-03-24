#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>
#define PI 3.1415926536
#define coordenadas 3

typedef float coordenada;
typedef struct {
    coordenada x, y, z;
}ponto;

typedef struct{
    coordenada x, y, z;
    double modulo;
}vetor;


void _centralizada_(const char *message);

void documentacao();

void menu();

void operacoes();

double modulo(vetor *v);

void distancia_entre_pontos(vetor *v, ponto *a, ponto *b);

void ler_vetor(char c, vetor *v);

void modulo_vetores(vetor *u, vetor *v);

void multiplica_por_escalar(char c, vetor *v, float esc, bool exibir);

void somar_vetores(vetor *soma, vetor *u, vetor *v, bool exibir);

void subtrair_vetores(vetor *subtracao, vetor *u, vetor *v, bool exibir);

void cosseno_angulo(double cosuv);

double produto_escalar(vetor *u, vetor *v, bool exibir);

int projecao_vetor(vetor *projuv, vetor *u, vetor *v, bool exibir);

void produto_vetorial(vetor *prod_vet, vetor *u, vetor *v, bool exibir);

void produto_misto(vetor *u, vetor *v, vetor *w);

void imprime_vetores(vetor *u, vetor *v);

double __radiano_para_grau(double ang);
