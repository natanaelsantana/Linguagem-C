#define ex4
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
main () {
    int a, b;
setlocale(LC_ALL, "Portuguese");

    printf("Insira dois n�meros para serem calculados: ");
    scanf("%d %d", &a, &b);


    printf("Os valores inseridos foram %d e %d", a, b);
    printf("A soma é: %d \nA subtração é: %d", a + b, a - b);
    printf("\nA multiplicação é: %d \nA divisão: %d", a * b, a / b);


    escolha();
}
#endif // ex1

#ifdef ex2
main () {
    int a, b;
setlocale(LC_ALL, "Portuguese");

    printf("Insira dois números para serem calculados: ");
    scanf("%d %d", &a, &b);


    printf("Os valores inseridos foram %d e %d", a, b);
    printf("A soma é: %d \nA subtração é: %d", a += b, a -= b);
    printf("\nA multiplicação é: %d \nA divisão: %d", a *= b, a /= b);


    escolha();
}

#endif // ex2

#ifdef ex3

int main() {
    int diaNascimento, mesNascimento, anoNascimento;
    int diaAtual, mesAtual, anoAtual;
    int diaTotal, mesTotal, anoTotal;

    printf("Qual a data do seu nascimento? ");
    scanf("%d/%d/%d", &diaNascimento, &mesNascimento, &anoNascimento);
    printf("Qual a data atual? ");
    scanf("%d/%d/%d", &diaAtual, &mesAtual, &anoAtual);

    int diasNascimento = diaNascimento + mesNascimento * 30 + anoNascimento * 365;
    int diasAtual = diaAtual + mesAtual * 30 + anoAtual * 365;
    int idadeEmDias = diasAtual - diasNascimento;

    anoTotal = idadeEmDias / 365;
    int diasRestantes = idadeEmDias % 365;
    mesTotal = diasRestantes / 30;
    int diasQueTenho = diasRestantes % 30;

    printf("Você tem: %d anos, %d meses, %d dias\n", anoTotal, mesTotal, diasQueTenho);

    escolha();
}

#endif // ex3

#ifdef ex4

int main() {
    setlocale(LC_ALL, "Portuguese");

    int dia, mes, ano;


    printf("Digite uma data: ");
    scanf("%d/%d/%d", &dia, &mes, &ano);

    if(mes  <3) {
        mes += 12;
        ano--;
    }

    //Usando congruência de Zeller
    // neste algoritmo, janeiro e fevereiro são contados como os meses 13 e 14 do ano anterior. Por isso o loop a condição acima
    int k = ano % 100;
    int j = ano / 100;


    int diaDaSemana = (dia + (((mes +1)* 13)/5) + k + (k/4) + (j/4) - (2 * j)) % 7;

    switch (diaDaSemana) {
        case 0:
            printf("Sabado\n");
            break;
        case 1:
            printf("Domingo\n");
            break;
        case 2:
            printf("Segunda-feira\n");
            break;
        case 3:
            printf("Terca-feira\n");
            break;
        case 4:
            printf("Quarta-feira\n");
            break;
        case 5:
            printf("Quinta-feira\n");
            break;
        case 6:
            printf("Sexta-feira\n");
            break;
        default:
            printf("Data inválida.\n");
            break;
    }

    escolha();
}

#endif // ex4

#ifdef ex5

int main() {

    int numero1, numero2;
    setlocale(LC_ALL, "Portuguese");


    printf("Digite o primeiro numero: ");
    scanf("%d", &numero1);

    printf("Digite o segundo numero: ");
    scanf("%d", &numero2);

    int resultado_AND = numero1 & numero2;
    int resultado_OR = numero1 | numero2;
    int resultado_EXCLUSIVO = numero1 ^ numero2;

    printf("Operacao AND: %d\n", resultado_AND);
    printf("Operacao OR: %d\n", resultado_OR);
    printf("Operacao XOR: %d\n", resultado_EXCLUSIVO);

    printf("Operacao AND (Hexadecimal): 0x%X\n", resultado_AND);
    printf("Operacao OR (Hexadecimal): 0x%X\n", resultado_OR);
    printf("Operacao XOR (Hexadecimal): 0x%X\n", resultado_EXCLUSIVO);

    escolha();
}

#endif // ex5
