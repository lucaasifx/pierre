#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <cmath>
#define coordenadas 3
typedef float coordenada;
//implementar vetor como distancia entre dois pontos
typedef struct {
    coordenada x, y, z;
}ponto;

typedef struct{
    coordenada x, y, z;
    double modulo;
}vetor;


void _centralizada_(const char *message){
    int tamanho = strlen(message);
    int tamanho_total = tamanho + 8;

    // Imprime a primeira linha
    for (int i = 0; i < tamanho_total; i++)
        printf("-");
    puts("");

    // Imprime a mensagem centralizada
    for (int i = 0; i < 4; i++)
        printf(" ");
    printf("%s\n", message);

    // Imprime a última linha
    for (int i = 0; i < tamanho_total; i++)
        printf("-");
    puts("\n");
}


void documentacao(){
    printf("Documentação:\n\n");
    printf("\t// Formato ideal de entrada: 3 coordenadas seguidas de espaços em branco\n");
    printf("\n\t\t\t\t \"u\" = x y z\n");
    printf("\t\t\t\t \"v\" = x y z\n\n");
    
    printf("Métodos:\n\n");
    printf("ler_vetor:\n\tRecebe o rótulo e endereço do vetor a ser lido. A leitura trata o caso \n\tem que o usuário digita números reais com vírgula.\n\n");
    printf("modulo:\n\tRecebe o endereço de um vetor e retorna um double que corresponde\n\tao módulo desse vetor.\n\n");
    printf("modulo_vetores:\n\tRecebe o endereço de 2 vetores. Exibe na tela o módulo com uma representação \n\tvisual.\n\n");
    printf("multiplica_por_escalar:\n\tRecebe o rótulo e o endereço de um vetor, o valor \n\tque será multiplicado e um booleano que indica se deve ou não exibir as operações realizadas.\n\n");
    printf("somar_vetores:\n\tRecebe o endereço de três vetores (soma, u e v) e um booleano que indica se deve ou não \n\texibir as operações realizadas. A função soma as coordenadas de u e v e armazena no vetor soma\n\n");
    printf("subtrair_vetores:\n\tRecebe o endereço de três vetores (subtracao, u e v) e um booleano que indica se deve \n\tou não exibir as operações realizadas. A função subtrai as coordenadas de u e v e armazena no vetor subtração\n\n");
    printf("cosseno_angulo:\n\tRecebe o cosseno do ângulo entre u e v. Exibe o ângulo correspondente.\n\n");
    printf("produto_escalar:\n\tRecebe o endereço de dois vetores e um booleano que indica se deve ou não retornar \n\to resultado. Calcula o ângulo entre vetores\n\n");
    printf("projecao_vetor:\n\tRecebe o endereço de três vetores (projuv, u e v) e um booleano que indica se deve ou não exibir as \n\toperações realizadas. A função encontra o vetor que corresponde à projeção de u em v\n\n");
    printf("produto_vetorial:\n\tRecebe o endereço de três vetores (prod_vet, u e v) e um booleano que indica se deve ou não exibir \n\tas operações realizadas. A função armazena o resultado dos determinantes\n\n");
    printf("produto_misto:\n\tRecebe o endereço de três vetores (u, v e w). A função calcula o produto vetorial \n\tentre v e w e realiza o produto escalar entre o vetor resultante e o vetor u.\n\n");
    printf("imprime_vetores:\n\tExibe os vetores atuais na saída padrão.\n\n");
    printf("--------------------------------------------------------------------------------\n");
}

void menu(){
    printf("Opções disponíveis:\n");
    printf("\t\t[ 1 ] Operações entre vetores\n");
    printf("\t\t[ 2 ] Mudar as coordenadas dos vetores\n");
    printf("\t\t[ 3 ] Imprimir os vetores atuais\n");
    printf("\t\t[ 4 ] Exibir documentação\n");
    printf("\t\t[ 5 ] Sair do programa\n");
}

void operacoes(){
    printf("Operações disponíveis:\n");
    printf("\t\t[ 1 ] Módulo dos vetores\n");
    printf("\t\t[ 2 ] Multiplicação por escalar\n");
    printf("\t\t[ 3 ] Soma\n");
    printf("\t\t[ 4 ] Subtração\n");
    printf("\t\t[ 5 ] Projeção de u em v\n");
    printf("\t\t[ 6 ] Produto Interno\n");
    printf("\t\t[ 7 ] Produto Vetorial\n");
    printf("\t\t[ 8 ] Produto Misto\n");
    printf("\t\t[ 9 ] Voltar\n");
}


double modulo(vetor *v){
    v->modulo = sqrt(pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2));
    return v->modulo;
}

// será implementado via interface
void distancia_entre_pontos(vetor *v, ponto *a, ponto *b){
    v->x = b->x - a->x;
    v->y = b->y - a->y;
    v->z = b->z - a->z;
    v->modulo = modulo(v);
}


void ler_vetor(char c, vetor *v){
    char entrada[80];

    //leitura das coordenadas
    while(1){
        printf("%c = ", c);
        scanf("%79[^\n]", entrada);
        getchar();
        for(int i = 0; i < strlen(entrada); i++){
            if(entrada[i] == ',')
                entrada[i] = '.';
        }
        int coordenadas_lidas = sscanf(entrada, "%f %f %f", &v->x, &v->y, &v->z);
        if(coordenadas_lidas == 3)
            break;
        else
            printf("ERRO! Coordenadas inválidas\n");
    }

    //calculo do modulo
    v->modulo = modulo(v);
}

void modulo_vetores(vetor *u, vetor *v){   
    double modu, modv;
    double rmodu, rmodv;
    modu = pow(u->x, 2) + pow(u->y, 2) + pow(u->z, 2);
    modv = pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2);
    rmodu = u->modulo;
    rmodv = v->modulo;
    printf("|u| = √%.3lf = %.3lf\n", modu, rmodu);
    printf("|v| = √%.3lf = %.3lf\n", modv, rmodv);
}

void multiplica_por_escalar(char c, vetor *v, float esc, bool exibir){
    v->x *= esc;
    v->y *= esc;
    v->z *= esc;
    if(exibir)
        printf("%c = (%.3f, %.3f, %.3f)\n", c, v->x, v->y, v->z);
}

void somar_vetores(vetor *soma, vetor *u, vetor *v, bool exibir){
    soma->x = u->x + v->x;
    soma->y = u->y + v->y;
    soma->z = u->z + v->z;
    if(exibir)
        printf("u + v = (%.3f, %.3f, %.3f)\n", soma->x, soma->y, soma->z);
}

void subtrair_vetores(vetor *subtracao, vetor *u, vetor *v, bool exibir){
    subtracao->x = u->x - v->x;
    subtracao->y = u->y - v->y;
    subtracao->z = u->z - v->z;
    if(exibir)
        printf("u - v = (%.3f, %.3f, %.3f)\n", subtracao->x, subtracao->y, subtracao->z);
}

double __radiano_para_grau(double ang){
    ang *= 180/M_PI;
    return ang;
}

double produto_escalar(vetor *u, vetor *v, bool exibir){
    double prod = 0;
    prod += u->x * v->x;
    prod += u->y * v->y;
    prod += u->z * v->z;
    if(!exibir)
        return prod;
    printf("Produto Escalar = %.3lf\n", prod);
    if(!prod)
        printf("Os vetores u e v são ortogonais!\n");
    else{
        // cálculo do ângulo entre os vetores u e v
        double modu, modv, cosuv;
        modu = modulo(u);
        modv = modulo(v);
        if(modu && modv){
            cosuv = prod / (modu * modv);
            cosuv = acos(cosuv);
            cosuv = __radiano_para_grau(cosuv);
            printf("Ângulo entre u e v: %.3f°\n", cosuv);
        }
    }
}

int projecao_vetor(vetor *projuv, vetor *u, vetor *v, bool exibir){
    //projuv recebe uma copia de v
    projuv->x = v->x;
    projuv->y = v->y;
    projuv->z = v->z;

    float modv = modulo(v);
    float prod = produto_escalar(u, v, 0);
    float proj;
    if(modv){
        proj = prod / (pow(modv, 2));
        multiplica_por_escalar('v', projuv, proj, 0);
        if(exibir)
            printf("Projeção de u em v = (%.3f, %.3f, %.3f)\n", projuv->x, projuv->y, projuv->z);
    }
    else
        return 0;     
}

void produto_vetorial(vetor *prod_vet, vetor *u, vetor *v, bool exibir){

    // calculo do produto vetorial
        //primeira diagonal
    prod_vet->x = (u->y * v->z) - (u->z * v->y);
        //segunda diagonal
    prod_vet->y = (u->z * v->x) - (u->x * v->z);
        //terceira diagonal
    prod_vet->z = (u->x * v->y) - (u->y * v->x);

    prod_vet->modulo = modulo(prod_vet);

    if(exibir){
        printf("u X v = (%.3f, %.3f, %.3f)\n", prod_vet->x, prod_vet->y, prod_vet->z);

        if(!prod_vet->x && !prod_vet->y && !prod_vet->z)
            printf("Os vetores u e v são paralelos!\n");
        else{
            float modu;
            modu = pow(prod_vet->x, 2) + pow(prod_vet->y, 2) + pow(prod_vet->z, 2);
            printf("|u X v| = √%.3f = %.3f\n", modu, prod_vet->modulo);
        }
    }
}

void produto_misto(vetor *u, vetor *v, vetor *w){
    // produto misto é o número dado por u . (v X w)

    vetor produto_vet;
    produto_vetorial(&produto_vet, v, w, false);

    double produto_misto = produto_escalar(&produto_vet, u, 0);
    printf("Produto misto: \n");
    printf("[u, v, w] = %.3f\n", produto_misto);
    if(!produto_misto)
        printf("u, v e w coplanares e linearmente dependentes.\n");
    else
        printf("\nMódulo do produto misto:\n|[u, v, w]| = %.3f\n", fabs(produto_misto));
} 

void imprime_vetores(vetor *u, vetor *v){
    printf("u = (%.3f, %.3f, %.3f)\n", u->x, u->y, u->z);
    printf("v = (%.3f, %.3f, %.3f)\n", v->x, v->y, v->z);
}