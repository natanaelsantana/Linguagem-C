#define ex5
#include "stdio.h"
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
main()
{
    int seg = 0;
    printf("Digite os segundos : ");
    scanf("%d", &seg);

    int horas = seg / 3600;
    int segundos = seg % 3600;
    int minutos = segundos / 60;
    segundos = segundos % 60;


    printf("Os segundos convertidos em horas equivale a: %dh %dmin %ds\n", horas, minutos, segundos);

    escolha();

}
#endif // ex1

#ifdef ex2
int main() {
        short varShort = 0;
        long varLong = 0;
        int varInt = 0;
        float varFloat = 0;
        double varDouble = 0;
        char varChar;
        setlocale(LC_ALL, "Portuguese");


        printf("Insira uma variável do tipo short: ");
        scanf("%hd", &varShort);
        printf("Insira uma variável do tipo long: ");
        scanf("%ld", &varLong);
        printf("Insira uma variável do tipo inteiro: ");
        scanf("%d", &varInt);
        printf("Insira uma variável do tipo float: ");
        scanf("%f", &varFloat);
        printf("Insira uma variável do tipo double: ");
        scanf("%lf", &varDouble);
        printf("Insira uma variável do tipo char: ");
        scanf(" %c", &varChar);


        printf("        10        20        30        40        50        60\n");
        printf("12345678901234567890123456789012345678901234567890123456789012345\n");
        printf("    %hd                 %ld                 %d \n", varShort, varLong, varInt);
        printf("              %.2f                %.2lf               %c  \n", varFloat, varDouble ,varChar);

        escolha();
}

#endif // ex2

#ifdef ex3
main () {
    int var1, var2;
    setlocale(LC_ALL, "Portuguese");

    printf("Coloque o valor de duas variaveis para que seus valores sejam trocados: \n ");
    printf("valor da primeira variavel: ");
    scanf("%d", &var1);
    printf("valor da segunda variavel: ");
    scanf("%d", &var2);

    var1 = var1 + var2;
    var2 = var1 - var2;
    var1 = var1 - var2;

    printf("\nOs valores invertidos sao: \n");
    printf("Valor da primeira variavel: %d", var1);
    printf("\nO valor da segunda variavel: %d", var2);

    escolha();
}
#endif // ex3

#ifdef ex4
main () {
    int num;
    setlocale(LC_ALL, "Portuguese");

    printf("Digite o seu numerode três digitos: ");
    scanf("%d", &num);

    int ultimo = num % 10;;
    int segundo = num / 10 % 10 ;
    int primeiro = num / 100;



    printf("O numero invertido e: %d%d%d\n", ultimo, segundo, primeiro);
    escolha();
}
#endif // ex4

#ifdef ex5
main () {
    int inteiro, limite, multiplo = 0;
    setlocale(LC_ALL, "Portuguese");

    printf("Digite o seu numero: ");
    scanf("%d", &inteiro);
    printf("Digite seu limite: ");
    scanf("%d", &limite);

    int i = 1;

    while(multiplo <= limite){
        multiplo = inteiro * i;
        i++;
    }

    printf("\nMenor multiplo de %d maior que %d. Resultado: %d.", inteiro, limite, multiplo);

    escolha();
}
#endif // ex5
