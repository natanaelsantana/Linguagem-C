#define ex1
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


char string1[10];
char string2[10];

int compararString (char str1[], char str2[]) {
    int contador = 0;
    while (str1[contador] == str2[contador] && str1[contador] != '\0') {
        contador ++;
    }
    if(str1[contador] != str2[contador]) {
        return 0;
    } else {
    return 1;}

}

main (){
    setlocale(LC_ALL, "Portuguese");

    printf("Digite uma palara de até 10 caractere: ");
    scanf("%s", string1);
    printf("Digite outra palavra de até 10 caracteres: ");
    scanf("%s", string2);


    int resultado = compararString(string1, string2);

    printf("resultado %d", resultado);

    escolha();

}

#endif // ex1

#ifdef ex2

char nome1[7];
char nome2[7];
char nome3[7];
char nome4[7];
char nome5[7];

main() {
    setlocale(LC_ALL, "Portuguese");


    for (int i = 0; i < 5; i++) {
        int contador = 0;
        printf("Escreva um nome com até 7 caracteres: ");
        scanf("%s", (i == 0) ? nome1 : (i == 1) ? nome2 : (i == 2) ? nome3 : (i == 3) ? nome4 : nome5);


        while (nome1[contador] != '\0') {
            contador++;
        }
        while (nome2[contador] != '\0') {
            contador++;
        }
        while (nome3[contador] != '\0') {
            contador++;
        }
        while (nome4[contador] != '\0') {
            contador++;
        }
        while (nome5[contador] != '\0') {
            contador++;
        }

        if(contador > 7){
            printf("A variável deve conter apenas 7 caracteres" );
            escolha();
        }
    }

    printf("        10        20        30        40        50\n");
    printf("12345678901234567890123456789012345678901234567890\n");

    printf("  %-7s                                    %-7s \n", nome1, nome5);
    printf("            %-7s             %-7s \n", nome2, nome4);
    printf("                      %-7s ", nome3);




    escolha();


}
#endif // ex2


#ifdef ex3
char string[100];


int tamanhoVetor(char string[]) {
    int contador = 0;

    while(string[contador] != '\0'){
        contador++;
    }

    return contador;
}

main() {
setlocale(LC_ALL, "Portuguese");

    printf("Digite aqui a string: ");
    scanf("%s", string);

    int comprimento = tamanhoVetor(string);

    printf("O comprimento da string %s é %d", string, comprimento);

    escolha();
}

#endif // ex3


#ifdef ex4

main() {

setlocale(LC_ALL, "Portuguese");

    char string[10];

    printf("Digite uma palavra de até 10 caracteres :");
    scanf("%s", string);
    int contador = 0;
     while (string[contador] != '\0') {
        if (string[contador] >= 'a' && string[contador] <= 'z'){
            string[contador] = string[contador] - 32;
        }
        contador++;

    }

    if(contador > 10){
            printf("A variável deve conter apenas 10 caracteres" );
            escolha();
    }

    printf("A variável convertida para maiúscula é:  %s", string);

    escolha();
}
#endif // ex4

#ifdef ex5
main() {

setlocale(LC_ALL, "Portuguese");

    char string[10];

    printf("Digite uma palavra de até 10 caracteres :");
    scanf("%s", string);
    int contador = 0;
     while (string[contador] != '\0') {
        if (string[contador] >= 'A' && string[contador] <= 'Z'){
            string[contador] = string[contador] + 32;
        }
        contador++;

    }

    if(contador > 10){
            printf("A variável deve conter apenas 10 caracteres" );
            escolha();
    }

    printf("A variável convertida para minúscula é:  %s", string);

    escolha();
}

#endif // ex5
