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
// Função
 int calcularFatorial (int num){
    int resultado = 1;
    int contadorDigitos = 0;
    int posicao = 0;
    int absoluto = 0;
    int digito = 0;

    // Calcula o fatorial
    for(int i = num; i >= 1; i--) {
        resultado *= i;

    }

    //verificar quantos digitos
    int temp = resultado;
    while(temp != 0){
        temp /= 10;
        contadorDigitos++;
    }


    //Extrai e soma os digitos

    for(int i = 0; i <= contadorDigitos; i++){
        posicao += contadorDigitos ;
        contadorDigitos--;

        for(int j = 0; j <= posicao; j++ ) {
            digito = resultado % 10;
            resultado /= 10;
            absoluto += digito;
        }
    }

    return absoluto;
}


main () {
    setlocale(LC_ALL, "Portuguese");
    int n;

    printf("digite um número menor ou igual a 10: ");
    scanf("%d", &n);
    int resultado = calcularFatorial(n);

    printf("A soma do resultado de %d! é: %d", n, resultado);

    escolha();
}
#endif // ex1


#ifdef ex2
int verificaPositivoNegativo (int n) {
    if(n > 0) return 1;
    else if (n < 0) return 0;
    else return -1;
}

int soma (int n, int m) {
    int maior;
    int menor;
    int soma = 0;

    if(n > m){
        maior = n; menor = m;
    } else{
        maior = m;
        menor = n;
    }

    while(maior >= menor){
        soma += menor;
        menor ++;
    }

    return soma;

}

int multiplicacao (int n, int m) {
    int maior;
    int menor;
    int multiplicacao = 1;

    if(n > m){
        maior = n; menor = m;
    } else{
        maior = m;
        menor = n;
    }

    while(maior >= menor){
        multiplicacao *= menor;
        menor ++;
    }
    return multiplicacao;

}

int divisao (int n, int m) {
    return n / m;

}

main () {
    int n, m;
    int resultado;

    printf ("Digite dois valores: ");
    scanf("%d%d", &n, &m);

    int verificacao1 = verificaPositivoNegativo(n);
    int verificacao2 = verificaPositivoNegativo(m);

    if (verificacao1 == 1 && verificacao2 == 1){
        resultado = soma(n, m);

    } else if (verificacao1 == 0 && verificacao2 == 0){
        resultado = multiplicacao(n,m);

    } else if (verificacao1 == 1 && verificacao2 == 0 || verificacao1 == 0 && verificacao2 == 1){
        resultado = divisao(n, m);
    } else {
        printf("valores precisam ser diferentes de 0");
        return 1;
    }

    printf("Resultado: %d", resultado);

    escolha();

}
#endif // ex2


#ifdef ex3

int soma(int n, int m) {
    return n + m;
}

int subtracao(int n, int m) {
    return n - m;
}

int divisao (int n, int m) {
    return n / m;
}

int multiplicacao(int n, int m) {
    return n * m;
}
main () {
    setlocale(LC_ALL, "Portuguese");
    int n = 0, m = 0, resultadoSoma, resultadoDivisao, resultadoMultiplicacao, resultadoSubtracao;
    printf("Digite os valores para a realização do cálculo: ");
    scanf("%d%d", &n, &m);

    resultadoSoma = soma(n,m);
    resultadoSubtracao = subtracao(n,m);
    resultadoDivisao = divisao(n,m);
    resultadoMultiplicacao = multiplicacao(n,m);


    printf("\nResultado da soma: %d", resultadoSoma);
    printf("\nResultado da subtração: %d", resultadoSubtracao);
    printf("\nResultado da divisão: %d", resultadoDivisao);
    printf("\nResultado da multiplicação: %d", resultadoMultiplicacao);
    escolha();
}
#endif // ex3

#ifdef ex4

int soma(int n, int m) {
    return n + m;
}

int subtracao(int n, int m) {
    return n - m;
}

int divisao (int n, int m) {
    return n / m;
}

int multiplicacao(int n, int m) {
    return n * m;
}
main () {
    setlocale(LC_ALL, "Portuguese");
    int n = 0, m = 0, resultadoSoma =0, resultadoDivisao = 0, resultadoMultiplicacao = 0, resultadoSubtracao = 0, valores = 0;
    printf("Quantos números você deseja para realizar o cálculo? ");
    scanf("%d", &valores);
    valores = valores - 1;

    printf("Digite os valores para a realização do cálculo: ");
    scanf("%d", &m);
    resultadoSoma = m;
    resultadoSubtracao = m;
    resultadoDivisao = m;
    resultadoMultiplicacao = m;


    while(valores > 0) {
    scanf("%d", &m);
    resultadoSoma = soma(resultadoSoma, m);
    resultadoSubtracao = subtracao(resultadoSubtracao,m);
    resultadoDivisao = divisao(resultadoDivisao,m);
    resultadoMultiplicacao = multiplicacao(resultadoMultiplicacao,m);
    valores --;
    }


    printf("\nResultado da soma: %d", resultadoSoma);
    printf("\nResultado da subtração: %d", resultadoSubtracao);
    printf("\nResultado da divisão: %d", resultadoDivisao);
    printf("\nResultado da multiplicação: %d", resultadoMultiplicacao);
    escolha();
}
#endif // ex4

#ifdef ex5
int soma(int n, int m) {
    return n + m;
}

int subtracao(int n, int m) {
    return n - m;
}

int divisao (int n, int m) {
    return n / m;
}

int multiplicacao(int n, int m) {
    return n * m;
}

main () {
    setlocale(LC_ALL, "Portuguese");
    int valores, resultado, total = 0;
    char operador;


    printf("Quantos números você deseja para realizar o cálculo? ");
    scanf("%d", &valores);

    int valoresRestantes = valores;

    while(valoresRestantes > 0){
        if(valores - valoresRestantes == 0){
            printf("Insira o primeiro valor: ");
            scanf("%d", &resultado);
            total = resultado;
            valoresRestantes--;
            continue;
        }

        printf("Qual operação você deseja?: +(soma) -(subtração) /(divisão) *(multiplicação) \n");
        scanf(" %c", &operador);
        printf("Insira o valor: ");
        scanf("%d", &resultado);

        switch (operador) {
        case '+':
            total = soma(total, resultado);
            break;
        case '-':
            total = subtracao(total, resultado);
            break;
        case '/':
            total = divisao(total, resultado);

            break;
        case '*':
            total = multiplicacao(total, resultado);
            break;
         default:
            printf("Opção inválida\n");
            break;
        }

        printf("\n\nTotal até o momento: %d\n\n", total);


        valoresRestantes--;

    }
    printf("Total: %d", total);
    escolha();
}

#endif // ex5
