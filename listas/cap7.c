#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define ex4


void escolha () {

setlocale(LC_ALL, "Portuguese");

 printf("\n\nDeseja continuar(s/n)?  ");
    char continuar;
    scanf(" %c", &continuar);
     switch (continuar) {
        case 's':
            system("cls");
            main();
            break;
        case 'n':
            exit(0);
            break;
        default:
            printf("Opção inválida\n");
            break;
    }
}

#ifdef ex1
/*Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    Receba dados via teclado em uma funcao e imprima estes conteudos no video,
    em outra funcao, no seguinte formato.
     estrutura: char, int, long, float, double, unsigned char, unsigned int,
                unsigned long

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long*/

struct variaveis{
char c;
int numero;
long longo;
float f;
double d;
unsigned char cc;
unsigned int numero2;
unsigned long longo2;
};

struct variaveis exercicio;


void RecebeNum(){

printf("Digite uma caractere: ");
scanf("%c", &exercicio.c);

printf("Digite um inteiro: ");
scanf("%d", &exercicio.numero);

printf("Digite uma variável de tipo long: ");
scanf("%ld", &exercicio.longo);

printf("Digite uma variável de tipo float: ");
scanf("%f", &exercicio.f);

printf("Digite uma variável de tipo double: ");
scanf("%lf", &exercicio.d);

printf("Digite uma variável do tipo unsigned int: ");
scanf("%u", &exercicio.numero2);

printf("Digite uma variável do tipo unsigned long: ");
scanf("%lu", &exercicio.longo2);

printf("Digite uma variável de tipo unsigned char: ");
scanf(" %c", &exercicio.cc);


}

void Imprime(){
printf("\n        10        20        30        40        50        60        70\n");
printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");
printf("    %c     %d       %ld                %.2f               %.2lf\n", exercicio.c, exercicio.numero, exercicio.longo, exercicio.f, exercicio.d);
printf("          %u                 %u                  %lu", exercicio.cc, exercicio.numero2, exercicio.longo2);
}

main(){
RecebeNum();
Imprime();
}

#endif // ex1

#ifdef ex2
/*  Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
    estruturas de 4 elementos. Receba os dados pelo teclado em uma funcao
    e imprima-os no video em uma funcao. Utilize vetor de estruturas.
    Faça um menu com uma opcao para saida do programa.
		estrutura: nome, end, cidade, estado, cep*/

struct dados {
char nome[20];
char end[50];
char cidade[20];
char estado[3];
int cep;
};
struct dados completos[4];

void RecebeDados(){
    for (int i=0;i<4;i++){
        getchar();
        printf("\nDigite seu nome: ");
        fgets(completos[i].nome, 20, stdin);
        printf("Digite seu endereco: ");
        fgets(completos[i].end, 50, stdin);
        printf("Digite seu cidade: ");
        scanf("%s", &completos[i].cidade);
        printf("Digite a sigla do seu estado: ");
        scanf("%s", &completos[i].estado);
        printf("Digite seu CEP sem pontuacoes: ");
        scanf("%d", &completos[i].cep);
        system("cls");
    }

    system("pause");
    system("cls");

}

void Imprime(){
    for (int i=0;i<4;i++){
        printf("\n nome: %s end: %s cidade: %s\n estado: %s\n cep: %d\n", completos[i].nome, completos[i].end, completos[i].cidade, completos[i].estado, completos[i].cep);
    }

    system("pause");
    system("cls");

}

main(){
    setlocale(LC_ALL, "Portuguese");

    int resposta;

while(1) {
    printf("\n 1 - Receber todos os dados\n 2 - Imprime todos os dados\n 3 - sair\n");
    scanf("%d", &resposta);
    switch (resposta){
        case 1:
        RecebeDados();
        break;
        case 2:
        Imprime();
        break;
        case 3:
        exit(0);
        break;
        default:
            printf("Opção inválida\n");
            system("cls");
            break;
}
}
}
#endif // ex2

#ifdef ex3

/*Escreva um programa com a estrutura de dados abaixo. Receba 2 datas via
    teclado na funcao main(). Faca uma funcao que calcule o numero de dias
    entre elas e mostre o resultado no video na funcao main().
    Utilize vetor de estruturas.
                estrutura: dia, mes, ano*/


struct datas{
int dia;
int mes;
int ano;
};

struct datas primeiraData;
struct datas segundaData;



int Calcula(){
    int totalDias;
    int diferenca;

    diferenca = (primeiraData.dia + (primeiraData.mes * 30) + (primeiraData.ano * 365)) - (segundaData.dia + (segundaData.mes * 30) + (segundaData.ano * 365));

    if(diferenca > 0) {
        totalDias = diferenca;
    } else if (diferenca < 0) {
        totalDias = -diferenca;
    } else {
        totalDias = 0;
    }

    printf("O número de dias entre elas e: %d", totalDias);


}

main(){
    setlocale(LC_ALL, "Portuguese");
    printf("Digite uma data(dd/mm/aa): ");
    scanf("%d/%d/%d", &primeiraData.dia, &primeiraData.mes, &primeiraData.ano);
    printf("Digite uma data(dd/mm/aa): ");
    scanf("%d/%d/%d", &segundaData.dia, &segundaData.mes, &segundaData.ano);
    Calcula();
    escolha();
}

#endif // ex3

#ifdef ex4


struct dados {
char nome[20];
float peso;
float altura;
};

struct dados completos[4];

void RecebeDados(){
for (int i=0;i<4;i++){
printf("Digite seu nome: ");
scanf("%s", &completos[i].nome);
printf("Digite seu peso: ");
scanf("%f", &completos[i].peso);
printf("Digite sua altura em metros (ex: 1.60): ");
scanf("%f", &completos[i].altura);
}
}

void ImprimeDados(){
for (int i=0;i<4;i++){
    printf("\nNome: %s\nPeso: %.2f\nAltura: %.2f\n", completos[i].nome, completos[i].peso, completos[i].altura);
}
}

float CalculoIMC(){
float Imc;
for (int i=0;i<4;i++){
Imc = completos[i].peso/(completos[i].altura*completos[i].altura);
printf("nome: %s", completos[i].nome);
printf("IMC: %.2f\n", Imc);
}
}


main(){
int resposta;

while(1) {
    printf("\n 1 - Receber todos os dados\n 2 - Imprime todos os dados \n 3 - Calcula o IMC de todas as pessoas. \n 4 - sair\n");
    scanf("%d", &resposta);
    switch (resposta){
        case 1:
        RecebeDados();
        break;
        case 2:
        ImprimeDados();
        break;
        case 3:
        CalculoIMC();
        break;
        case 4:
        exit(0);
        break;
        default:
            printf("Opção inválida\n");
            system("cls");
            break;
}
}
}

#endif // ex 4
