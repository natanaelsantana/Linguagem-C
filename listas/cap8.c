#include <stdio.h>
#include <locale.h>
#define ex6

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
/*Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faça uma
    funcao para compara-las usando ponteiros e retorne como resultado se
    sao IGUAIS 1 ou se sao DIFERENTES 0 para a funcao main().
    Imprima o resultado na funcao main(). Declare os vetores como variavel global*/

char string1[10];
char string2[10];

int compararString() {
    char *str1 = string1;
    char *str2 = string2;

    while (*str1 == *str2 && *str1 != '\0') {
        str1++;
        str2++;
    }

    if (*str1 != *str2) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    printf("Digite uma palavra de até 10 caracteres: ");
    scanf("%s", string1);
    printf("Digite outra palavra de até 10 caracteres: ");
    scanf("%s", string2);

    int resultado = compararString();

    printf("Resultado: %d\n", resultado);

    escolha();
}

#endif // ex1

#ifdef ex2
/*2 - Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva
    uma funcao que pesquise esta letra existe no vetor abaixo usando ponteiros.
    Imprima o resultado da pesquisa no video na funcao main(). Passe como informacao
    para a funcao a letra digitada usando ponteiros.(utilize o comando return).
    O vetor deve ser declarado como variavel global.

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y */

char letras[] = {'b','d','f','h','j','k','m','o','q','s','u','w','y'};

int verificaVetor (char *letra) {
    int i = 0;
   while(letras[i] != '\0'){
        if(letras[i] == *letra) {
            return 1;
        }
        i++;
    }

    return 0;
}

main(){
    setlocale(LC_ALL, "Portuguese");

    char c;
    char *pLetra = &c;
    printf("Digite uma letra para ser verificada: ");
    scanf(" %c", pLetra);

    char *pLetra2 = &c;
    if(verificaVetor(pLetra2)) {
        printf("A letra '%c' existe no vetor", *pLetra2);
    } else {
        printf("A letra '%c' não existe no vetor ", *pLetra2);
    }


    escolha();
}

#endif // ex2


#ifdef ex3

/* Escreva um programa que receba via teclado usando ponteiros um char,
    int, long, unsigned, float, double, unsigned long e unsigned char,
    e imprima-os no video utilizando ponteiros no seguinte formato:

            10        20        30        40        50        60
    123456789012345678901234567890123456789012345678901234567890
        int                 long                unsigned
                  float               double              char
             unsigned long       unsigned char*/


char *c;
int *numero;
long *longo;
float *f;
double *d;
unsigned char *cc;
unsigned int *numero2;
unsigned long *longo2;

void RecebeNum() {

    c = &c;
    numero = &numero;
    longo = &longo;
    f = &f;
    d = &d;
    cc = &cc;
    numero2 = &numero2;
    longo2 = &longo2;

    printf("Insira uma variável do tipo char:");
    scanf(" %c", c);
    printf("Insira uma variável do tipo inteiro:");
    scanf("%d", numero);
    printf("Insira uma variável do tipo long:");
    scanf("%ld", longo);
    printf("Insira uma variável do tipo float:");
    scanf("%f", f);
    printf("Insira uma variável do tipo double:");
    scanf("%lf", d);
    printf("Insira uma variável do tipo unsigned :");
    scanf("%u", numero2);
    printf("Insira uma variável do tipo unsigned long:");
    scanf("%lu", longo2);
    printf("Insira uma variável do tipo unsigned char:");
    scanf(" %c", cc);
}

void Imprime() {
    printf("\n\n    10        20        30        40        50        60\n");
    printf("123456789012345678901234567890123456789012345678901234567890\n");
    printf("    %d                  %ld                 %u               \n", numero, longo, numero2);
    printf("              %.2f                  %.2lf                  %c\n", f, d, c);
    printf("         %lu                 %u        ",longo2, cc);
}

int main() {
    RecebeNum();
    Imprime();

    escolha();
}
#endif // ex3

#ifdef ex4
/*4 - Escreva um programa que receba via teclado numeros inteiros positivos usando
    ponteiros. Quando o numero digitado for negativo o programa deve parar e calcula
    a media dos valores digitados e mostrar o resultado. Todos os calculos devem ser
    feitos usando ponteiro.*/


main() {
    int num;
    int pNum;
    int media = 0;
    int valores= 0;
    pNum = &num;
    while(1){
        printf("Digite um numero: ");
        scanf("%d", pNum);

        if(num < 0) {
            media = media /  valores;
            printf("A media dos valores e: %d", media);
            break;
        }

        media += num;
        valores++;

    }

    escolha();
}
#endif // ex4

#ifdef ex5

/*Com a estrutura abaixo, defina um vetor de estruturas de 4 elementos.
    Receba os dados via teclado numa funcao usando ponteiros. Imprima os dados
    recebidos no video numa usando ponteiros. Utilize um comando de loop.
    O vetor de estruturas de ser declarado como variavel global
       estrutura: nome, end, cidade, estado, cep*/


struct dados {
    char nome[20];
    char end[50];
    char cidade[20];
    char estado[3];
    int cep;
};

struct dados *completos[4];

struct dados pessoa[4];


void RecebeDados(int index) {
    printf("Digite seu nome: ");
    scanf("%s", completos[index]->nome);
    printf("Digite seu endereço: ");
    scanf("%s", completos[index]->end);
    printf("Digite seu cidade: ");
    scanf("%s", completos[index]->cidade);
    printf("Digite a sigla do seu estado: ");
    scanf("%s", completos[index]->estado);
    printf("Digite seu CEP sem pontuações: ");
    scanf("%d", &completos[index]->cep);
}

void Imprime(int index) {
    printf(" nome: %s\n end: %s\n cidade: %s\n estado: %s\n cep: %d\n\n", completos[index]->nome, completos[index]->end, completos[index]->cidade, completos[index]->estado, completos[index]->cep);
}

int main() {

     for (int i = 0; i < 4; i++) {
        completos[i] = &pessoa[i];
    }

    for (int i = 0; i < 4; i++) {
        printf("Informe os dados para o endereço %d:\n", i + 1);
        RecebeDados(i);
    }

    printf("Dados inseridos:\n");

    for (int i = 0; i < 4; i++) {
        printf("Endereço %d:\n", i + 1);
        Imprime(i);
    }

    escolha();
}


#endif // ex5

#ifdef ex6
/*6 - Escreva um programa com a estrutura abaixo. Receba 2 datas via teclado
    usando ponteiros. Calcule e exiba o numero de dias entre as duas datas
    usando ponteiros. Utilize um vetor de estruturas.
    	estrutura: dia, mes e ano
*/

struct data {
    int dia;
    int mes;
    int ano;
};

struct data data[2];
struct data *pData[2];



main() {
    int contagem = 0;
    while(contagem < 2) {
        pData[contagem] = &data[contagem];
        contagem++;
    }

    contagem = 0;
    while(contagem < 2) {
        printf("Essa e a data numero %d\n", contagem+1);
        printf("Insira a data no seguinte formato (dd/mm/ano): ");
        scanf("%d/%d/%d", &pData[contagem] -> dia, &pData[contagem] -> mes, &pData[contagem] -> ano);
        contagem++;
    }

    int totalDias;
    int diferenca;

    diferenca = (pData[0] -> dia + (pData[0] -> mes * 30) + (pData[0] -> ano * 365)) - (data[1].dia + (data[1].mes * 30) + (data[1].ano * 365));

    if(diferenca > 0) {
        totalDias = diferenca;
    } else if (diferenca < 0) {
        totalDias = -diferenca;
    } else {
        totalDias = 0;
    }

    printf("A diferença de dias entre cada data e: %d", totalDias);

}


#endif // ex6
