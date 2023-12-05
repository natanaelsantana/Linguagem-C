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

    int V[10];

    main(){
        setlocale(LC_ALL, "Portuguese");

    int i;
    for (i=0; i<10; i++)
    {
    printf("Digite os componentes do seu vetor (até 10): ");
    scanf("%d", &V[i]);
    }
    int U[5] = {V[1], V[3], V[5], V[7], V[9]};
    int W[5] = {V[0], V[2], V[4], V[6], V[8]};
    for (int i=0; i<5; i++){
        printf("%d|", U[i]);
    }
    printf("\n");
    for (int i=0; i<5; i++){
        printf("%d|", W[i]);
    }

    escolha();
    }

#endif // ex1

#ifdef ex2
     int V[10];
     int U[10];
     int W[10];

    main(){
    setlocale(LC_ALL, "Portuguese");

    int i, j=0, k=0;
    for (i=0; i<10; i++)
    {
    printf("Digite os componentes do seu vetor: ");
    scanf("%d", &V[i]);
    if (V[i] % 2 != 0)
    {
    U[j]= V[i];
    j++;
    }
    if (V[i] % 2 == 0)
    {
    W[k]= V[i];
    k++;
    }
    }
    for (i=0; i<j; i++)
    {
    printf("%d|", U[i]);}
    printf("\n");
    for (i=0; i<k; i++)
    {
    printf("%d|", W[i]);}

    escolha();
    }

#endif // ex2

#ifdef ex3

    int A[2][3];
    int B[2][3];
    int C[6];
    main ()
    {
        int j;
        int k = 0;

        //Definindo primeiro vetor
        for (int i=0; i<2; i++){

           for(int j = 0; j < 3; j++){
            printf("Digite os componentes do vetor: ");
            scanf("%d", &A[i][j]);
           }

        }


        // Definindo segundo vetor
        for (int i=0; i<2; i++){

           for(int j = 0; j < 3; j++){
            printf("Digite os componentes do segundo vetor: ");
            scanf("%d", &B[i][j]);
           }

        }

        //Somando ambos
        for (int i=0; i<2; i++){

           for(int j = 0; j < 3; j++){
            C[k] = B[i][j] + A[i][j];
            k++;
           }

        }

       k = 0;
       for (int i=0; i<2; i++){
            for (int j=0; j<3; j++){
                printf("\n Indice %d | valores: %d + %d | resultado: %d ", k ,A[i][j], B[i][j], C[k] );
                k++;
            }
        }
        escolha();
    }
#endif // ex3


#ifdef ex4

main() {
    int vet[10];
    int j = 1;
    int k = 0;

    for(int i = 0; i < 10; i++){
        printf("\nDigite o valor: ");
        scanf("%d", &vet[i]);

        for (int x = 0; x <= i; x++){
            if(vet[i] < vet[x]) {
                k = vet[i];
                vet[i] = vet[x];
                vet[x] = k;
            }
        }
    }


    printf("\nOs valores ordenados são: \n");

    for(int i = 0; i < 10; i++) {
        printf("%d |", vet[i]);
    }
    escolha();
}

#endif // ex4


#ifdef ex5
int vetorInteiros[3];
long vetorLong[3];
unsigned vetorUnsign[3];
float vetorFloat[3];
double vetorDouble[3];

main() {
     // Leitura dos valores
    printf("Digite 3 valores inteiros:\n");
    for (int i = 0; i < 3; i++) {
        scanf("%d", &vetorInteiros[i]);
    }

    printf("Digite 3 valores longos:\n");
    for (int i = 0; i < 3; i++) {
        scanf("%ld", &vetorLong[i]);
    }

    printf("Digite 3 valores unsigned:\n");
    for (int i = 0; i < 3; i++) {
        scanf("%u", &vetorUnsign[i]);
    }

    printf("Digite 3 valores de ponto flutuante:\n");
    for (int i = 0; i < 3; i++) {
        scanf("%f", &vetorFloat[i]);
    }

    printf("Digite 3 valores double:\n");
    for (int i = 0; i < 3; i++) {
        scanf("%lf", &vetorDouble[i]);
    }

    // Impressão no formato especificado
     printf("\n%10d%10d%10d%10d%10d\n", 10, 20, 30, 40, 50);
    printf("12345678901234567890123456789012345678901234567890\n");
    printf("  %d                  %ld                %u      \n", vetorInteiros[0], vetorLong[0], vetorUnsign[0]);
    printf("            %2.l                %lf   \n", vetorFloat[0], vetorDouble[0]);
    printf("  %d                  %ld                %u      \n", vetorInteiros[1], vetorLong[1], vetorUnsign[1]);
    printf("            %2.l                %lf   \n", vetorFloat[1], vetorDouble[1]);
    printf("  %d                  %ld                %u      \n", vetorInteiros[2], vetorLong[2], vetorUnsign[2]);
    printf("            %2.l                %lf   \n", vetorFloat[2], vetorDouble[2]);


    escolha();
}

#endif // ex5
