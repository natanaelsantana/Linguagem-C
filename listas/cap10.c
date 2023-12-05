#include <stdio.h>
#include <locale.h>
#define ex1


#ifdef ex1
/*1 - Escreva um programa para criar e abrir um arquivo texto de nome "arq.txt".
    Receba via teclado diversos caracteres (um por vezes) e escreva-os
    nesse arquivo. O caracter '0' finaliza a entrada de dados. Abra o arquivo
    "arq.txt", leia e imprima na tela todos os caracteres armazenados no
    arquivo (um por vezes).*/


main () {
    setlocale(LC_ALL, "Portuguese");

    FILE *arquivo;

    arquivo = fopen("arq.txt", "w");

    char c;

    while(c != '0') {
        printf("digite um caractere:");
        scanf(" %c", &c);

        putc(c, arquivo);

    }

    c = 'a';

    fclose(arquivo);

    fopen("arq.txt", "r");

    while(c != '0'){
        fscanf(arquivo,"%c ",&c);
        printf(" %c\n",c);
    }


    fclose(arquivo);

}

#endif // ex1



#ifdef ex2
 typedef struct Contato{
    char nome[20];
    char telefone[20];
    int diaAniv;
    int mesAniv;
    } Contato;

void inserirContato(struct Contato *contatos){
    int byte = sizeof(struct Contato);
    FILE *arquivo;

    arquivo = fopen("contatos.txt", "w");

    int i;

    for (i=0; i<4; i++){
        printf("Digite o nome: ");
        gets((contatos+i)->nome);

        printf("Digite o telefone (sem pontuações): ");
        gets((contatos+i)->telefone);

        printf("Digite apenas o dia do seu aniversário: ");
        scanf("%d", &(contatos+i)->diaAniv);
        getchar();

        printf("Digite o mês do seu aniversário: ");
        scanf("%d", &(contatos+i)->mesAniv);
        getchar();

        fwrite((contatos+i), byte, 1, arquivo);

    }

    fclose(arquivo);
}

void listarContatos(struct Contato *contatos){
    int byte = sizeof(struct Contato);

    FILE *arquivo;

    arquivo = fopen("contatos.txt", "r");

    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return;
    }

    while (fread(contatos, byte, 1, arquivo) == 1) {
        if(contatos->nome[0] != '*' ){
        printf("Nome: %s\n", contatos->nome);
        printf("Telefone: %s\n", contatos->telefone);
        printf("Data do Aniversário: %d / %d\n\n", contatos->diaAniv, contatos->mesAniv);

        }
    }
    fclose(arquivo);
}

void pesquisaContatoPeloNome(struct Contato *contatos) {

    int byte = sizeof(struct Contato);


    FILE *arquivo;

    arquivo = fopen("contatos.txt", "r");

    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return;
    }

    char nomeTemp[20];


    printf("Insira o nome: ");
    gets(nomeTemp);

    while (fread(contatos, byte, 1, arquivo)) {
        int contador = 0;
        int correspondente = 1;

            while (contatos->nome[contador] != '\0') {
                if (nomeTemp[contador] != contatos->nome[contador] || contatos->nome[0] == '*') {
                    correspondente = 0;
                    break;
                }
                contador++;
            }
         if(correspondente){
            printf("Nome: %s\n", contatos->nome);
            printf("Telefone: %s\n", contatos->telefone);
            printf("Data do Aniversário: %d / %d\n\n", contatos->diaAniv, contatos->mesAniv);
            fclose(arquivo);
            return 0;
         }

    }

    printf("Contato não encontrado.\n");
    fclose(arquivo);

}

void listarContatosPelaLetra (struct Contato *contatos){

    int byte = sizeof(struct Contato);

    FILE *arquivo;

    arquivo = fopen("contatos.txt", "r");

    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return;
    }

    char letra;
    int achados = 0;

    printf("Insira a letra: ");
    scanf(" %c", &letra);

    while (fread(contatos, byte, 1, arquivo)) {
        if(letra == contatos->nome[0] && contatos->nome[0] != '*') {
            printf("Nome: %s\n", contatos->nome);
            printf("Telefone: %s\n", contatos->telefone);
            printf("Data do Aniversário: %d / %d\n\n", contatos->diaAniv, contatos->mesAniv);
            achados++;
        }
    }

    if(achados){
        fclose(arquivo);
        return;
    }

    printf("Nenhum contato com esta letra.\n");
    fclose(arquivo);
}

void imprimirAniversariantesMes(struct Contato *contatos) {
    FILE *arquivo;

    int byte = sizeof(struct Contato);

    arquivo = fopen("contatos.txt", "r");

    int mes;
    int achados = 0;


    printf("Qual mes voce deseja consultar? (insira um numero) ");
    scanf("%d", &mes);

    while (fread(contatos, byte, 1, arquivo)) {
        if(mes == contatos->mesAniv && contatos->nome[0] != '*') {
            printf("Nome: %s\n", contatos->nome);
            printf("Telefone: %s\n", contatos->telefone);
            printf("Data do Aniversário: %d / %d\n\n", contatos->diaAniv, contatos->mesAniv);
            achados++;
        }
    }

    if(achados){
        fclose(arquivo);
        return;
    }

    printf("Nenhum contato com esse mes.\n");
    fclose(arquivo);
}

void alteraContato(struct Contato *contatos) {
    int byte = sizeof(struct Contato);

    FILE *arquivo;

    arquivo = fopen("contatos.txt", "r+");

    char nomeTemp[20];

    printf("Qual contato voce deseja alterar?");
    gets(nomeTemp);
    while (fread(contatos, byte, 1, arquivo)) {
        int contador = 0;
        int correspondente = 1;
        while (contatos->nome[contador] != '\0') {
                if (nomeTemp[contador] != contatos->nome[contador] || contatos->nome[0] == '*') {
                    correspondente = 0;
                    break;
                }
                contador++;
            }
        if(correspondente){
        printf("Digite o nome: ");
        gets(contatos->nome);

        printf("Digite o telefone (sem pontuações): ");
        gets(contatos->telefone);

        printf("Digite apenas o dia do seu aniversário: ");
        scanf("%d", &contatos->diaAniv);
        getchar();

        printf("Digite o mês do seu aniversário: ");
        scanf("%d", &contatos->mesAniv);
        getchar();

        fseek(arquivo, -byte, 1);
        fwrite(contatos, byte, 1, arquivo);
        fclose(arquivo);
        return;
        }
    }

    printf("Nenhum contato com este nome.\n");
    fclose(arquivo);

}

void excluiContato (struct Contato *contatos) {
    int byte = sizeof(struct Contato);

    FILE *arquivo;

    arquivo = fopen("contatos.txt", "r+");

    char nomeTemp[20];

    printf("Qual contato voce deseja excluir?");
    gets(nomeTemp);
    while (fread(contatos, byte, 1, arquivo)) {
        int contador = 0;
        int correspondente = 1;
        while (contatos->nome[contador] != '\0') {
                if (nomeTemp[contador] != contatos->nome[contador]) {
                    correspondente = 0;
                    break;
                }
                contador++;
            }
        if(correspondente){
        contatos->nome[0] = '*';


        fseek(arquivo, -byte, 1);
        fwrite(contatos, byte, 1, arquivo);
        fclose(arquivo);
        return;
        }

    }

    printf("Nenhum contato com esta letra.\n");
    fclose(arquivo);

}

main() {
     setlocale(LC_ALL, "Portuguese");


     Contato contatos[4];

    char decisao;

    while(1) {
    printf("\n1 – Inserir contatos.");
    printf("\n2 – Lista todos os contatos.");
    printf("\n3– Pesquisar um contato pelo nome");
    printf("\n4 – listar os contatos cujo nome inicia com uma letra digitada.");
    printf("\n5 – imprimir os aniversariantes do mês.");
    printf("\n6 – altera contato.");
    printf("\n7 – exclui contato");
    printf("\n8 - saida");

    printf("\nO que você deseja fazer?");
    scanf(" %c", &decisao);
    getchar();
    switch (decisao) {

        case '1':
            system("cls");
            inserirContato(contatos);
            break;
        case '2':
            listarContatos(contatos);
            break;
         case '3':
            system("cls");
            pesquisaContatoPeloNome(contatos);
            break;
         case '4':
            system("cls");
            listarContatosPelaLetra(contatos);
            break;
        case '5':
            system("cls");
            imprimirAniversariantesMes(contatos);
            break;
         case '6':
            system("cls");
            alteraContato(contatos);
            break;
        case '7':
            excluiContato(contatos);
            break;
         case '8':
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
 typedef struct Mercadoria{
    char codigo[20];
    char nome[20];
    int quantidade;
    } Mercadoria;

void inserirMercadoria(struct Mercadoria *Mercadorias){
    int byte = sizeof(struct Mercadoria);
    FILE *arquivo;

    arquivo = fopen("Mercadorias.txt", "a");

    printf("Digite o codigo: ");
    gets(Mercadorias->codigo);

    printf("Digite o nome: ");
    gets(Mercadorias->nome);

    printf("Digite a quantidade: ");
    scanf("%d", &Mercadorias->quantidade);
    getchar();

    fwrite(Mercadorias, byte, 1, arquivo);

    fclose(arquivo);
}

void listarMercadorias(struct Mercadoria *Mercadorias){
    int byte = sizeof(struct Mercadoria);

    FILE *arquivo;

    arquivo = fopen("Mercadorias.txt", "r");

    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return;
    }

    while (fread(Mercadorias, byte, 1, arquivo) == 1) {
        if(Mercadorias->nome[0] != '*' ){
        printf("Codigo: %s\n", Mercadorias->codigo);
        printf("Nome: %s\n", Mercadorias->nome);
        printf("Quantidade: %d\n\n", Mercadorias->quantidade);

        }
    }
    fclose(arquivo);
}

void pesquisaMercadoriaPeloNome(struct Mercadoria *Mercadorias) {
    int byte = sizeof(struct Mercadoria);
    FILE *arquivo;

    arquivo = fopen("Mercadorias.txt", "r");

    char nomeTemp[20];
    printf("Insira o nome: ");
    gets(nomeTemp);

    while (fread(Mercadorias, byte, 1, arquivo)) {
        int contador = 0;
        int correspondente = 1;
            while (Mercadorias->nome[contador] != '\0' && nomeTemp[contador] != '\0') {
                if (nomeTemp[contador] != Mercadorias->nome[contador] || Mercadorias->nome[0] == '*') {
                    correspondente = 0;
                    break;
                }
                contador++;
            }
         if(correspondente){
            printf("Codigo: %s\n", Mercadorias->codigo);
            printf("Nome: %s\n", Mercadorias->nome);
            printf("quantidade: %d\n\n", Mercadorias->quantidade);
            fclose(arquivo);
            return 0;
         }

    }

    printf("Mercadoria não encontrado.\n");
    fclose(arquivo);

}

void listarProdutosNaoDisponiveis (struct Mercadoria *Mercadorias){

    int byte = sizeof(struct Mercadoria);

    FILE *arquivo;

    arquivo = fopen("Mercadorias.txt", "r");


    char letra;
    int achados = 0;

    printf("produtos nao disponíveis\n\n");

    while (fread(Mercadorias, byte, 1, arquivo)) {
        if(Mercadorias->quantidade == 0) {
            printf("Codigo: %s\n", Mercadorias->codigo);
            printf("Telefone: %s\n", Mercadorias->nome);
            printf("Quantidade: %d\n\n", Mercadorias->quantidade);
            achados++;
        }
    }

    if(achados){
        fclose(arquivo);
        return;
    }

    printf("Nenhuma mercadoria em falta.\n");
    fclose(arquivo);
}

void alteraQuantidade(struct Mercadoria *Mercadorias) {
    FILE *arquivo;

    int byte = sizeof(struct Mercadoria);

    arquivo = fopen("Mercadorias.txt", "r+");

    int achados = 0;


    char nomeTemp[20];

    printf("Insira o nome da mercadoria que voce deseja alterar a quantidade: ");
    gets(nomeTemp);
    while (fread(Mercadorias, byte, 1, arquivo)) {
        int contador = 0;
        int correspondente = 1;
            while (Mercadorias->nome[contador] != '\0' && nomeTemp[contador] != '\0') {
                if (nomeTemp[contador] != Mercadorias->nome[contador] || Mercadorias->nome[0] == '*') {
                    correspondente = 0;
                    break;
                }
                contador++;
            }
        if(correspondente){
        printf("Qual quantidade voce deseja? ");
        scanf("%d", &Mercadorias->quantidade);
        getchar();

        fseek(arquivo, -byte, 1);
        fwrite(Mercadorias, byte, 1, arquivo);
        fclose(arquivo);
        return;
        }
    }
    printf("Nenhum Mercadoria com esse nome.\n");
    fclose(arquivo);
}

void alteraProdutos(struct Mercadoria *Mercadorias) {
    int byte = sizeof(struct Mercadoria);

    FILE *arquivo;

    arquivo = fopen("Mercadorias.txt", "r+");

    char nomeTemp[20];

    printf("Qual Mercadoria voce deseja alterar?");
    gets(nomeTemp);
    while (fread(Mercadorias, byte, 1, arquivo)) {
        int contador = 0;
        int correspondente = 1;
            while (Mercadorias->nome[contador] != '\0' && nomeTemp[contador] != '\0') {
                if (nomeTemp[contador] != Mercadorias->nome[contador] || Mercadorias->nome[0] == '*') {
                    correspondente = 0;
                    break;
                }
                contador++;
            }
        if(correspondente){
        printf("Digite o codigo: ");
        gets(Mercadorias->codigo);

        printf("Digite o nome do produto: ");
        gets(Mercadorias->nome);

        printf("Qual quantidade voce deseja: ");
        scanf("%d", &Mercadorias->quantidade);
        getchar();

        fseek(arquivo, -byte, 1);
        fwrite(Mercadorias, byte, 1, arquivo);
        fclose(arquivo);
        return;
        }
    }

    printf("Nenhum Mercadoria com este nome.\n");
    fclose(arquivo);

}

void excluiMercadoria (struct Mercadoria *Mercadorias) {
    int byte = sizeof(struct Mercadoria);

    FILE *arquivo;

    arquivo = fopen("Mercadorias.txt", "r+");

    char nomeTemp[20];

    printf("Qual Mercadoria voce deseja excluir?");
    gets(nomeTemp);
    while (fread(Mercadorias, byte, 1, arquivo)) {
        int contador = 0;
        int correspondente = 1;
        while (Mercadorias->nome[contador] != '\0' && nomeTemp[contador] != '\0') {
                if (nomeTemp[contador] != Mercadorias->nome[contador]) {
                    correspondente = 0;
                    break;
                }
                contador++;
            }
        if(correspondente){
        Mercadorias->nome[0] = '*';


        fseek(arquivo, -byte, 1);
        fwrite(Mercadorias, byte, 1, arquivo);
        fclose(arquivo);
        return;
        }

    }

    printf("Nenhum Mercadoria com esta letra.\n");
    fclose(arquivo);

}

main() {
     setlocale(LC_ALL, "Portuguese");

    FILE *arquivo;

     arquivo =  fopen("Mercadorias.txt", "r+");

     if(!arquivo) {
        printf("Arquivo novo criado\n\n");
        arquivo = fopen("Mercadorias.txt", "w+");
        fclose(arquivo);
     } else {
        printf("arquivo aberto com sucesso!\n\n");
        fclose(arquivo);
     }


     Mercadoria Mercadorias;

    char decisao;

    while(1) {
    printf("\n1 – Inserir Mercadorias.");
    printf("\n2 – Lista todas os Mercadorias.");
    printf("\n3– Pesquisar um Mercadoria pelo nome");
    printf("\n4 – listar produtos não disponiveis.");
    printf("\n5 – Altera quantide atual.");
    printf("\n6 – altera Mercadoria.");
    printf("\n7 – exclui Mercadoria");
    printf("\n8 - saida");

    printf("\nO que você deseja fazer?");
    scanf(" %c", &decisao);
    getchar();
    switch (decisao) {

        case '1':
            system("cls");
            inserirMercadoria(&Mercadorias);
            break;
        case '2':
            listarMercadorias(&Mercadorias);
            break;
         case '3':
            system("cls");
            pesquisaMercadoriaPeloNome(&Mercadorias);
            break;
         case '4':
            system("cls");
            listarProdutosNaoDisponiveis(&Mercadorias);
            break;
        case '5':
            system("cls");
            alteraQuantidade(&Mercadorias);
            break;
         case '6':
            system("cls");
            alteraProdutos(&Mercadorias);
            break;
        case '7':
            excluiMercadoria(&Mercadorias);
            break;
         case '8':
            exit(0);
            break;
        default:
            printf("Opção inválida\n");
            system("cls");
            break;
    }

}
}
#endif // ex3

#ifdef ex4

/*Escreva um programa para controle de um cadastro de clientes. Para cada
    registro sera' armazenado nome, email e celular numa estrutura de dados.
    A unica estrutura de dados e' uma variavel LOCAL na funcao main().
    Escreva os registros direto no arquivo. (utilize a funcao fseek quando
    necessario). NAO pode usar vetor de estruturas. Utilize ponteiros para
    passar parametros para as funcoes.
    O programa deve ter as seguintes opcoes: (cada opcao do menu e' um funcao)

    1 - inclui registros
    2 - listar todos os registros
    3 - pesquisar registro pelo nome
    4 - altera registro
    5 - exclui registro
    6 - saida


    */
 typedef struct Cliente{
    char nome[20];
    char telefone[20];
    char email[40];
    } Cliente;


void inserirRegistro(struct Cliente *clientes){
    int byte = sizeof(struct Cliente);
    FILE *arquivo;

    arquivo = fopen("clientes.txt", "a");

    printf("Digite o nome: ");
    gets(clientes->nome);

    printf("Digite o telefone (sem pontuações): ");
    gets(clientes->telefone);

    printf("Digite o email: ");
    gets(clientes->email);

    fwrite(clientes, byte, 1, arquivo);

    fclose(arquivo);
}

void listarRegistros(struct Cliente *clientes){
    int byte = sizeof(struct Cliente);

    FILE *arquivo;

    arquivo = fopen("clientes.txt", "r");

    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return;
    }

    while (fread(clientes, byte, 1, arquivo) == 1) {
        if(clientes->nome[0] != '*' ){
        printf("Nome: %s\n", clientes->nome);
        printf("Telefone: %s\n", clientes->telefone);
        printf("Data do Aniversário: %s\n\n", clientes->email);
        }
    }
    fclose(arquivo);
}

void pesquisaRegistroPeloNome(struct Cliente *clientes) {

    int byte = sizeof(struct Cliente);

    FILE *arquivo;

    arquivo = fopen("clientes.txt", "r");

    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return;
    }

    char nomeTemp[20];

    printf("Insira o nome: ");
    gets(nomeTemp);

    while (fread(clientes, byte, 1, arquivo)) {
        int contador = 0;
        int correspondente = 1;

            while (clientes->nome[contador] != '\0') {
                if (nomeTemp[contador] != clientes->nome[contador] || clientes->nome[0] == '*') {
                    correspondente = 0;
                    break;
                }
                contador++;
            }
         if(correspondente){
            printf("Nome: %s\n", clientes->nome);
            printf("Telefone: %s\n", clientes->telefone);
            printf("Email: %s\n\n", clientes->email);
            system("pause");
            fclose(arquivo);
            return ;
         }

    }
    printf("Cliente não encontrado.\n");
    system("pause");
    fclose(arquivo);

}

void alteraRegistro(struct Cliente *clientes) {
    int byte = sizeof(struct Cliente);

    FILE *arquivo;

    arquivo = fopen("clientes.txt", "r+");

    char nomeTemp[20];

    printf("Qual Cliente voce deseja alterar?");
    gets(nomeTemp);

    while (fread(clientes, byte, 1, arquivo)) {
        int contador = 0;
        int correspondente = 1;
        while (clientes->nome[contador] != '\0') {
                if (nomeTemp[contador] != clientes->nome[contador] || clientes->nome[0] == '*') {
                    correspondente = 0;
                    break;
                }
                contador++;
            }
        if(correspondente){
        printf("Digite o nome: ");
        gets(clientes->nome);

        printf("Digite o telefone (sem pontuações): ");
        gets(clientes->telefone);

        printf("Digite o email: ");
        gets(clientes->email);

        fseek(arquivo, -byte, 1);
        fwrite(clientes, byte, 1, arquivo);
        printf("alterações feitas com sucesso!")
        fclose(arquivo);
        return;
        }
    }

    printf("Nenhum Cliente com este nome.\n");
    fclose(arquivo);

}

void excluiRegistro (struct Cliente *clientes) {
    int byte = sizeof(struct Cliente);

    FILE *arquivo;

    arquivo = fopen("clientes.txt", "r+");

    char nomeTemp[20];

    printf("Qual Cliente voce deseja excluir?");
    gets(nomeTemp);

    while (fread(clientes, byte, 1, arquivo)) {
        int contador = 0;
        int correspondente = 1;
        while (clientes->nome[contador] != '\0') {
                if (nomeTemp[contador] != clientes->nome[contador]) {
                    correspondente = 0;
                    break;
                }
                contador++;
            }
        if(correspondente){
        clientes->nome[0] = '*';


        fseek(arquivo, -byte, 1);
        fwrite(clientes, byte, 1, arquivo);
        fclose(arquivo);
        return;
        }

    }

    printf("Nenhum Cliente com esta letra.\n");
    fclose(arquivo);

}

main() {
     setlocale(LC_ALL, "Portuguese");


    Cliente clientes;

    char decisao;

    while(1) {
    printf("\n1 – Inclui registros");
    printf("\n2 – Lista todos os registros.");
    printf("\n3–  Pesquisar registros pelo nome");
    printf("\n4 – altera registro.");
    printf("\n5 – exclui registro");
    printf("\n6 - saida");

    printf("\nO que você deseja fazer?");
    scanf(" %c", &decisao);
    getchar();
    switch (decisao) {

        case '1':
            system("cls");
            inserirRegistro(&clientes);
            break;
        case '2':
            listarRegistros(&clientes);
            break;
         case '3':
            system("cls");
            pesquisaRegistroPeloNome(&clientes);
            break;
         case '4':
            system("cls");
            alteraRegistro(&clientes);
            break;
        case '5':
            excluiRegistro(&clientes);
            break;
         case '6':
            exit(0);
            break;
        default:
            printf("Opção inválida\n");
            system("cls");
            break;
    }

}
}




#endif // ex4
