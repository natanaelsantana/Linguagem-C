#define ex3
#include <stdio.h>
#include <locale.h>


//Função de escolha
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

/*1 - Escreva um programa que receba em uma funcao 2 strings de ate' 10 caracteres
    passando como parametro ponteiro.
    Os vetores devem ser declarados como variaveis LOCAIS na função main().
    Escreva uma funcao para comparar as 2 strings. Passe como parametros para
    a funcao as 2 strings usando ponteiros e retorne como resultado se IGUAIS 1
    ou se DIFERENTES 0. Mostre o resultado no video na funcao main().*/


int compararString(char *str1, char *str2) {
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

    char string1[10];
    char string2[10];

    printf("Digite uma palavra de até 10 caracteres: ");
    scanf("%s", string1);
    printf("Digite outra palavra de até 10 caracteres: ");
    scanf("%s", string2);

    int resultado = compararString(string1, string2);

    printf("Resultado: %d\n", resultado);

    escolha();
}


#endif // ex1


#ifdef ex2
/*2 - Escreva um programa que receba n valores via teclado e receba tambem a
    operação a ser executada. Quando for digitado "=" o programa deve mostrar
    o resultado acumulado dos n valores. As operações aritmeticas e a entrada
    de dados devem ser funcoes que recebe os valores usando ponteiros.
    As variaveis sao LOCAIS na funcao main().*/


#include <stdio.h>
#include <locale.h>

void primeiraEntrada(char *operador, int *valor1, int *valor2) {
    printf("Insira o primeiro valor: ");
    scanf("%d", valor1);
    printf("Qual operação você deseja? +(soma) -(subtração) /(divisão) *(multiplicação)  = (sair)\n");
    scanf(" %c", operador);
    printf("Insira um valor: ");
    scanf("%d", valor2);
}

void entradaDeDados (char *operador, int *valor1, int *valor2) {
    printf("Qual operação você deseja? +(soma) -(subtração) /(divisão) *(multiplicação)  = (sair)\n");
    scanf(" %c", operador);

    if (*operador == '=') {
            return;
    }

    printf("Insira um valor: ");
    scanf("%d", valor2);
}

int soma(int *n, int *m) {
    return (*n) + (*m);
}

int subtracao(int *n, int *m) {
    return (*n) - (*m);
}

int divisao(int *n, int *m) {
    return (*n) / (*m);
}

int multiplicacao(int *n, int *m) {
    return (*n) * (*m);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int valor2 = 0, total = 0;
    char operador = ' ';

    primeiraEntrada(&operador, &total, &valor2);

    while (operador != '=') {
        system("cls");

        printf("\nTotal até o momento: %d\n\n", total);

        entradaDeDados(&operador, &total, &valor2);

        switch (operador) {
            case '+':
                total = soma(&total, &valor2);
                break;
            case '-':
                total = subtracao(&total, &valor2);
                break;
            case '/':
                total = divisao(&total, &valor2);
                break;
            case '*':
                total = multiplicacao(&total, &valor2);
                break;
            case '=':
                printf("Total: %d\n", total);
                system("pause");
                system("cls");
                escolha();
                break;
            default:
                printf("Opção inválida\n");
                break;
        }


    }


}





#endif // ex2


#ifdef ex3

/*Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva
    uma funcao que pesquise se esta letra existe no vetor abaixo usando ponteiros.
    Imprima o resultado da pesquisa no video na funcao main(). Passe como informacao
    para a funcao a letra digitada e o vetor usando ponteiros e faca a pesquisa
    usando ponteiros.(utilize o comando return).
    O vetor deve ser declarado como variavel LOCAL na funcao main().

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y*/



int verificaVetor (char letra, char *letras) {
    int i = 0;
    while(letras[i] != '\0'){
        if(letras[i] == letra) {
            return 1;
        }
        i++;
    }

    return 0;
}


int main(){
    setlocale(LC_ALL, "Portuguese");
    char letras[] = {'b','d','f','h','j','k','m','o','q','s','u','w','y', '\0'};

    char c;
    printf("Digite uma letra para ser verificada: ");
    scanf(" %c", &c);

    if(verificaVetor(c, letras)) {
        printf("A letra '%c' existe no vetor", c);
    } else {
        printf("A letra '%c' não existe no vetor ", c);
    }

    return 0;
}

#endif // ex3

#ifdef ex4

/*Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    A estrutura e' uma variavel LOCAL na funcao main(). Receba via teclado o
    conteudo de cada um dos membros numa funcao e imprima-os no video no
    seguinte formato(também numa função).

    estrutura: char, int, long, float, double, unsigned char, unsigned int,
    unsigned long

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long*/

 typedef struct dados {
    char c;
    int numero;
    long longo;
    float f;
    double d;
    unsigned char cc;
    unsigned int numero2;
    unsigned long longo2;
} dados;

void RecebeNum(struct dados *estrutura) {
    printf("Insira uma variável do tipo char:");
    scanf(" %c", &estrutura->c);
    printf("Insira uma variável do tipo inteiro:");
    scanf("%d", &estrutura->numero);
    printf("Insira uma variável do tipo long:");
    scanf("%ld", &estrutura->longo);
    printf("Insira uma variável do tipo float:");
    scanf("%f", &estrutura->f);
    printf("Insira uma variável do tipo double:");
    scanf("%lf", &estrutura->d);
    printf("Insira uma variável do tipo unsigned :");
    scanf("%u", &estrutura->numero2);
    printf("Insira uma variável do tipo unsigned long:");
    scanf("%lu", &estrutura->longo2);
    printf("Insira uma variável do tipo unsigned char:");
    scanf(" %c", &estrutura->cc);
}

void Imprime(struct dados *estrutura) {
    printf("\n\n    10        20        30        40        50        60\n");
    printf("123456789012345678901234567890123456789012345678901234567890\n");
    printf("    %d                  %ld                 %u               \n", estrutura->numero, estrutura->longo, estrutura->numero2);
    printf("              %.2f                  %.2lf                  %c\n", estrutura->f, estrutura->d, estrutura->c);
    printf("         %lu                 %u        ",estrutura->longo2, estrutura->cc);
}

int main() {
    dados estrutura;

    RecebeNum(&estrutura);
    Imprime(&estrutura);

    return 0;
}

#endif // ex4


#ifdef ex5
/*  Escreva um programa com a estrutura abaixo. Defina um vetor de estruturas
    de 4 elementos como variavel LOCAL na funcao main(). Receba os 4 registros
    sequencialmente pelo teclado numa função e imprima todos os registros no
    video em outra funcao. Faça um menu. Utilize ponteiros nas funcoes.
    Coloque no menu a opção de sair tambem. Utilize o comando switch.
    (vetor de estruturas)
     estutura: nome, end, cidade, estado, cep*/

typedef struct dados {
    char nome[20];
    char end[50];
    char cidade[20];
    char estado[3];
    int cep;
} dados;


void RecebeDados(struct dados *ptr) {
    printf("Digite seu nome: ");
    scanf("%s", ptr->nome);
    printf("Digite seu endereço: ");
    scanf("%s", ptr->end);
    printf("Digite seu cidade: ");
    scanf("%s", ptr->cidade);
    printf("Digite a sigla do seu estado: ");
    scanf("%s", ptr->estado);
    printf("Digite seu CEP sem pontuações: ");
    scanf("%d", &ptr->cep);
}

void Imprime(struct dados *ptr) {
    printf(" nome: %s\n end: %s\n cidade: %s\n estado: %s\n cep: %d\n", ptr->nome, ptr->end, ptr->cidade, ptr->estado, ptr->cep);
}

void Menu(struct dados *ptr){
int resposta;
printf("1 - receber todos os dados\n 2 - imprime todos os dados \n 3 - sair\n");
scanf("%d", &resposta);
do{
switch (resposta){
    case 1:
    RecebeDados(&ptr);
    break;
    case 2:
    Imprime(&ptr);
    break;
    case 3:
    exit(0);
    break;
}} while (resposta != 3);
}

int main() {

    dados completos[4];

    for (int i = 0; i < 4; i++) {
        printf("Informe os dados para o endereço %d:\n", i + 1);
        RecebeDados(&completos[i]);
    }

    printf("Dados inseridos:\n");

    for (int i = 0; i < 4; i++) {
        printf("Endereço %d:\n", i + 1);
        Imprime(&completos[i]);
    }
    Menu(&completos);

    return 0;
}



#endif // ex5

#ifdef ex6
/*Acrescente ao menu do exercicio anterior as funcoes de procura, altera e
    exclui um registro sempre usando ponteiros.*/

typedef struct dados {
    char nome[20];
    char end[50];
    char cidade[20];
    char estado[3];
    int cep;
} dados;


void RecebeDados(struct dados *ptr) {
    getchar();
    for(int i= 0; i < 4; i++){
    printf("\n\nDigite seu nome: ");
    gets(ptr[i].nome);
    printf("Digite seu endereço: ");
    gets(ptr[i].end);
    printf("Digite seu cidade: ");
    gets(ptr[i].cidade);
    printf("Digite a sigla do seu estado: ");
    gets(ptr[i].estado);
    printf("Digite seu CEP sem pontuações: ");
    scanf("%d", &ptr[i].cep);
    getchar();
    }
}

void Imprime(struct dados *ptr) {
    for(int i = 0; i < 4; i++){
        if(ptr[i].nome[0] != '*'){
        printf("\nnome: %s\nend: %s\ncidade: %s\nestado: %s\ncep: %d\n", ptr[i].nome, ptr[i].end, ptr[i].cidade, ptr[i].estado, ptr[i].cep);
        }
    }
    return;
}

void pesquisaDadosPeloNome(struct dados *ptr) {

    char nomeTemp[20];
    getchar();
    printf("Insira o nome: ");
    gets(nomeTemp);

    for (int i = 0; i < 4; i++) {
        int contador = 0;
        int correspondente = 1;
            while (ptr[i].nome[contador] != '\0') {
                if (nomeTemp[contador] != ptr[i].nome[contador] || ptr[i].nome[0] == '*') {
                    correspondente = 0;
                    break;
                }
                contador++;
            }
         if(correspondente){
            printf("Nome: %s\n", ptr[i].nome);
            printf("Endereço: %s\n", ptr[i].end);
            printf("Cidade: %s\n", ptr[i].cidade);
            printf("Estado: %s\n", ptr[i].estado);
            printf("CEP: %d\n", ptr[i].cep);
            return 0;
         }

    }
    printf("Contato não encontrado.\n");
}

void alteraDados(struct dados *ptr) {

    char nomeTemp[20];
    getchar();

    printf("Insira o nome dos dados que você deseja apagar?");
    gets(nomeTemp);
    int contador = 0;
    int correspondente = 1;
    for(int i = 0; i < 4; i++){
    while (ptr[i].nome[contador] != '\0' && nomeTemp[contador] != '\0') {
        if (nomeTemp[contador] != ptr[i].nome[contador] || ptr[i].nome[0] == '*') {
            correspondente = 0;
                break;
        }
        contador++;
    }

    if(correspondente){
        printf("\n\nDigite seu nome: ");
        gets(ptr[i].nome);
        printf("Digite seu endereço: ");
        gets(ptr[i].end);
        printf("Digite seu cidade: ");
        gets(ptr[i].cidade);
        printf("Digite a sigla do seu estado: ");
        gets(ptr[i].estado);
        printf("Digite seu CEP sem pontuações: ");
        scanf("%d", &ptr[i].cep);
        getchar();
        return;
        }
    }

    printf("Nenhum contato com este nome.\n");
}

void excluiDados (struct dados *ptr) {

    char nomeTemp[20];
    getchar();
    printf("Qual contato voce deseja excluir?");
    gets(nomeTemp);
    for (int i =0; i < 4; i++) {
        int contador = 0;
        int correspondente = 1;
        while (ptr[i].nome[contador] != '\0' && nomeTemp[contador] != '\0') {
                if (nomeTemp[contador] != ptr[i].nome[contador]) {
                    correspondente = 0;
                    break;
                }
                contador++;
            }
        if(correspondente){
        ptr[i].nome[0] = '*';
        return;
        }

    }
    printf("Nenhum contato com esta letra.\n");
}

int main() {

    dados completos[4];
    int resposta;

    for(int i = 0; i < 2; i++) {
        completos[i].nome[0] = '*' ;
    }

    while (1){
        printf("1 - receber todos os dados\n2 - imprime todos os dados \n3 - pesquisa pelo nome\n");
        printf("4 - altera dados\n5 - exclui Dados \n6 - sair\n");

        scanf("%d", &resposta);

        switch (resposta){
        case 1:
        RecebeDados(&completos);
        break;
        case 2:
        Imprime(&completos);
        break;
        case 3:
        pesquisaDadosPeloNome(&completos);
        break;
        case 4:
        alteraDados(&completos);
        break;
        case 5:
        excluiDados(&completos);
        break;
        case 6:
        exit(0);
        break;
        }

    }
    return 0;
}

#endif // ex6
