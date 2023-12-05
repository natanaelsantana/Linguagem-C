#define ex5
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
setlocale(LC_ALL,"Portuguese");

    int h1, m1, s1;

    printf("Insira o horario de inicio da sua ligaçao: ");
    scanf("%d:%d:%d", &h1,&m1,&s1);

    int horaInicio = (h1 * 3600) + (m1 * 60) + (s1);

    printf("Insira o horario de termino da sua ligaçao: ");
    scanf("%d:%d:%d", &h1,&m1,&s1);

    int horaTermino = (h1 * 3600) + (m1 * 60) + (s1);

    int diferenca = horaTermino - horaInicio;

    h1 = diferenca / 3600;
    m1 = diferenca % 3600 / 60;
    s1 = diferenca % 60;


    printf("O intervalo de tempo e: %dh %dmin %dseg", h1, m1, s1);


    escolha();

}


#endif // ex1


/* Escreva um programa para adivinhar um numero entre 1 e 99 que o usuario
    pensou. Digite via teclado os simbolos =, > ou < a cada pergunta. Utilize o
    comando if-else.
*/

#ifdef ex2
main () {
    setlocale(LC_ALL, "Portuguese");

int minimo=1, maximo=99;
int base;
char resposta;

printf("Pense num numero de 1 a 99\n");
while (resposta != '=')
{
    base = (minimo + maximo) / 2;
    fflush(stdin);
    printf("Esse numero é >, =, < que %d? ", base);
    scanf(" %c", &resposta);

        if (resposta == '>')
        {
            minimo = base + 1;
        }
        else if (resposta == '<')
        {
            maximo = base - 1;
        }
        else if (resposta == '=')
        {
            printf("Acertei! Hahaha\n");
            break;
        }
        else
        {
            printf("Por favor, responda com '>', '<' ou '='.\n");
        }
    }



    escolha();

}

#endif // ex2

#ifdef ex3
/*Reescreva o programa do exercicio anterior agora utilizando o comando switch.
    Conte o n. de tentativas e imprima o resultado no video.*/

main ()
{
    int minimo=1, maximo=99;
    int base;
    char resposta;

    printf("Pense num numero de 1 a 99\n");
    while (resposta != '=')
    {
        base = (minimo + maximo) / 2;
        fflush(stdin);
        printf("Esse numero é >, =, < que %d? ", base);
        scanf("%c", &resposta);

        switch (resposta)
        {

        case '>':
        minimo = base;
        break;
        case '<':
        maximo = base;
        break;
        case '=':
        printf("Acerteiiiii hahahaha");
        break;

        }
    }

    //Opção para continuar
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


#endif // ex3

#ifdef ex4


    main (){
    int distancia, litros, resultado;

    printf("Digite a distancia em km percorrida no percurso: ");
    scanf("%d", &distancia);
    printf("Digite a quantidade de litros utilizada no percurso: ");
    scanf("%d", &litros);
    resultado = distancia/litros;
    if (resultado < 8)
    {
        printf("Venda o carro!");
    }
    else if (resultado >= 8 && resultado <=14)
    {
        printf("Economico!");
    }
    else
    {
        printf("Super economico!");
    }
    //Opção para continuar
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

#endif // ex4

#ifdef ex5


    main()
    {
        int numero=0, cont=0, total=0;
        while (numero >= 0)
        {

            printf("Digite um numero: ");
            scanf("%d", &numero);
            if (numero > 0)
            {
               total += numero;
               cont ++;

            }

        }
        printf("A media dos numeros digitados é: %d", total/cont);

        escolha();
    }

#endif // ex5

