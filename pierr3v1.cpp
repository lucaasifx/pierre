// idealizado por Lucas Emanoel
    //https://github.com/lucaasifx

// contribuições:
    // Sergio
    // Ana Emília Queiroz

// teste aqui

//teste 2.0
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <cmath>
#include "vetores.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

int main(){
    system("chcp 65001");
    system("cls");
    setlocale(LC_ALL, "pt_BR.UTF-8");

    //variaveis úteis
    vetor u, v;
    int opc, opc2;

    _centralizada_("pierr3 v1.1");

    while(1){
        printf("Forneça as coordenadas de u e v\n\n");

        //esse trecho recebe as coordenadas de u
        ler_vetor('u', &u);
        puts("");

        //esse trecho recebe as coordenadas de v
        ler_vetor('v', &v);
        puts("");

        while(1){
            //delay do menu
            #ifdef _WIN32
                Sleep(1000);
            #else
                usleep(1000000);
            #endif

            //listagem de opções
            menu();

            while(1){
                printf("\nSua opção: ");
                scanf("%d", &opc);
                getchar();
                if(opc && opc <= 5)
                    break;
                else
                    printf("Digite uma opção válida!");
            }
            puts("");

            switch(opc){
                case 1:{
                    while(1){
                        operacoes();
                        while(1){
                            printf("\nSua opção: ");
                            scanf("%d", &opc2);
                            getchar();
                            if(opc2 >= 1 && opc2 <= 9)
                                break;
                            else
                                printf("Digite uma opção válida!");
                        }
                        puts("");
                        switch(opc2){

                            case 1:{
                                modulo_vetores(&u, &v);
                                break;
                            }
                            case 2:{   
                                char mvet;
                                float multi;
                                while(1){

                                    printf("Qual dos vetores deseja multiplicar: ");
                                    scanf("%c", &mvet);
                                    getchar();

                                    if(mvet == 'u' || mvet == 'v')
                                        break;
                                    else
                                        printf("Digite um vetor válido!\n");
                                }


                                printf("Multiplicar por: ");
                                scanf("%f", &multi);
                                getchar();

                                
                                if(mvet == 'u')
                                    multiplica_por_escalar('u', &u, multi, true);
                                else
                                    multiplica_por_escalar('v', &v, multi, true);
                                break;
                            }

                            case 3:{
                                vetor soma;
                                somar_vetores(&soma, &u, &v, true);
                                break;
                            }
                            
                            case 4:{
                                vetor subtracao;
                                subtrair_vetores(&subtracao, &u, &v, true);
                                break;
                            }

                            case 5:{
                                vetor projuv;
                                projecao_vetor(&projuv, &u, &v, true);
                                break;
                            }

                            case 6:{
                                produto_escalar(&u, &v, true);
                                break;
                            }

                            case 7:{
                                vetor prod_vet;
                                produto_vetorial(&prod_vet, &u, &v, true);
                                break;
                            }
                            
                            case 8:{
                                vetor w;
                                _centralizada_("Forneça as coordenadas do vetor w");

                                //esse trecho recebe as coordenadas de w
                                ler_vetor('w', &w);
                                puts("");
                                produto_misto(&u, &v, &w);
                                break;
                            }

                            case 9:
                                break;

                            default:
                                printf("Opção inválida!\n");    
                        }
                        if(opc2 == 9)
                            break;
                        puts("");
                    }
                }
                case 2:
                    break;
                case 3:{
                    imprime_vetores(&u, &v);
                    break;
                }
                case 4:{
                    documentacao();
                    break;
                }
                case 5:
                    break;
                default:
                    printf("Digite uma opção válida!\n");
            }

            puts("");
            if(opc == 2 || opc == 5)
                break;
        }
        if(opc == 5)
            break;
    }

    return 0;
}
