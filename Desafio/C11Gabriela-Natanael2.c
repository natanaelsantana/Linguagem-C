#include <stdio.h>
#include <locale.h>


 typedef struct Medico{
    char medico[20];
    char celular[14];
    char data_consulta[11];
    } Medico;

void convertePrimeiraLetraEmMaiuscula(char *str){
    int i = 0;
    //valores decimais correspondentes ao caracteres na tabela ascii
    while(str[i] != '\0'){
        if (str[0] >= 97 && str[0] <= 122){
            str[0] -=  32;
        }
        if(str[i] == 32 && str[i+1] >= 97 && str[i+1] <= 122 ){
            str[i+1] -=  32;
        }
        i++;
    }
}

int verificaMedicoExistente (char *nome, struct Medico *medicos){
    int byte = sizeof(struct Medico);
    FILE *arquivo;
    arquivo = fopen("medicos.txt", "r");
     while (fread(medicos, byte, 1, arquivo)) {
        int contador = 0;
        int correspondente = 1;
            while (medicos->medico[contador] != '\0' && nome[contador] != '\0') {
                if (nome[contador] != medicos->medico[contador] || medicos->medico[0] == '*') {
                    correspondente = 0;
                    break;
                }
                contador++;
            }
         if(correspondente){
            fclose(arquivo);
            printf("medico ja existente, tente novamente");
            return 1;
         }

    }
    return 0;
}

void inserirDados(struct Medico *medicos){
    int byte = sizeof(struct Medico);
    FILE *arquivo;
    arquivo = fopen("medicos.txt", "a");


    char medicoTemp[20];
    printf("Digite o nome do medico: ");
    gets(medicoTemp);

    convertePrimeiraLetraEmMaiuscula(medicoTemp);

    //a função retorna 1 caso existe um médico
    int medicoExiste = verificaMedicoExistente(medicoTemp, medicos);

    if(medicoExiste) return;

    int i = 0;
    while (medicoTemp[i] != '\0') {
    medicos->medico[i] = medicoTemp[i];
    i++;
    }

    medicos->medico[i] = '\0';

    printf("Digite o celular (sem pontuações): ");
    gets(medicos->celular);

    printf("Digite a data de consulta(dd/mm/aaaa): ");
    gets(medicos->data_consulta);

    fwrite(medicos, byte, 1, arquivo);

    printf("Medico salvo!");
    printf("\nPressione enter para retornar ao menu");
    getchar();
    fclose(arquivo);
}

void listarMedicos(struct Medico *medicos){
    int byte = sizeof(struct Medico);
    FILE *arquivo;
    arquivo = fopen("medicos.txt", "r");

    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return;
    }

    while (fread(medicos, byte, 1, arquivo) == 1) {
        if(medicos->medico[0] != '*' ){
            printf("medico: %s\n", medicos->medico);
            printf("celular: %s\n", medicos->celular);
            printf("Data da consulta: %s\n\n", medicos->data_consulta);
        }
    }

    printf("\nPressione enter para retornar ao menu");
    getchar();
    fclose(arquivo);
}

void pesquisaMedicoPeloNome(struct Medico *medicos) {
    int byte = sizeof(struct Medico);
    FILE *arquivo;
    arquivo = fopen("medicos.txt", "r");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return;
    }
    int resultado = 0;
    char medicoTemp[20];
    printf("Insira o nome medico: ");
    gets(medicoTemp);
    convertePrimeiraLetraEmMaiuscula(medicoTemp);

    while (fread(medicos, byte, 1, arquivo)) {
        int contador = 0;
        int correspondente = 1;
            while (medicos->medico[contador] != '\0' && medicoTemp[contador] != '\0') {
                if (medicoTemp[contador] != medicos->medico[contador] || medicos->medico[0] == '*') {
                    correspondente = 0;
                    break;
                }
                contador++;
            }
         if(correspondente){
            printf("medico: %s\n", medicos->medico);
            printf("celular: %s\n", medicos->celular);
            printf("data da consulta: %s\n", medicos->data_consulta);
            resultado++;
        }
    }
    if(!resultado){
        printf("Medico não encontrado.\n");
        printf("Pressione enter para retornar ao menu");
        getchar();
        fclose(arquivo);
        return;
    }
    return;

}

void pesquisaCelular(struct Medico *medicos){
    int byte = sizeof(struct Medico);
    FILE *arquivo;
    arquivo = fopen("medicos.txt", "r");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return;
    }
    char medicoTemp[20];
    printf("Insira o nome completo do medico: ");
    gets(medicoTemp);

    convertePrimeiraLetraEmMaiuscula(medicoTemp);

    while (fread(medicos, byte, 1, arquivo)) {
        int contador = 0;
        int correspondente = 1;

            while (medicos->medico[contador] != '\0') {
                if (medicoTemp[contador] != medicos->medico[contador] || medicos->medico[0] == '*') {
                    correspondente = 0;
                    break;
                }
                contador++;
            }
         if(correspondente){
            printf("Numero do medico: %s\n", medicos->celular);
            printf("Pressione enter para retornar ao menu");
            getchar();
            fclose(arquivo);
            return ;
         }

    }
    printf("Medico não encontrado.\n");
    printf("Pressione enter para retornar ao menu");
    getchar();
    fclose(arquivo);


}

void pesquisaDataConsulta(struct Medico *medicos){
 int byte = sizeof(struct Medico);
    FILE *arquivo;
    arquivo = fopen("medicos.txt", "r");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return;
    }
    char dataTemp[20];
    printf("Insira a data da consulta (dd/mm/aaaa): ");
    gets(dataTemp);

    int resultado = 0;
    while (fread(medicos, byte, 1, arquivo)) {
        int contador = 0;
        int correspondente = 1;

        while (medicos->data_consulta[contador] != '\0') {
                if (dataTemp[contador] != medicos->data_consulta[contador] || medicos->medico[0] == '*') {
                    correspondente = 0;
                    break;
                }
                contador++;
            }
        if(correspondente){
            printf("medico: %s\n", medicos->medico);
            printf("celular: %s\n", medicos->celular);
            printf("data da consulta: %s\n\n", medicos->data_consulta);
            resultado++;
        }
    }
    if(!resultado){
        printf("Medico não encontrado.\n");
        printf("Pressione enter para retornar ao menu");
        getchar();
        fclose(arquivo);
        return;
    }
    return;
}

void alteraDados(struct Medico *medicos) {
    int byte = sizeof(struct Medico);
    FILE *arquivo;
    arquivo = fopen("medicos.txt", "r+");
    char medicoTemp[20];

    printf("Digite o nome do médico para alteração: ");
    gets(medicoTemp);

    convertePrimeiraLetraEmMaiuscula(medicoTemp);


    while (fread(medicos, byte, 1, arquivo)) {
        int contador = 0;
        int correspondente = 1;
        while (medicos->medico[contador] != '\0') {
                if (medicoTemp[contador] != medicos->medico[contador] || medicos->medico[0] == '*') {
                    correspondente = 0;
                    break;
                }
                contador++;
            }
        if(correspondente){

            printf("Digite o nome do medico: ");
            gets(medicoTemp);

            convertePrimeiraLetraEmMaiuscula(medicoTemp);

            //a função retorna 1 caso existe um médico
            int medicoExiste = verificaMedicoExistente(medicoTemp, medicos);

            if(medicoExiste) return;

            int i = 0;
            while (medicoTemp[i] != '\0') {
            medicos->medico[i] = medicoTemp[i];
            i++;
            }

            medicos->medico[i] = '\0';

            printf("Digite o celular (sem pontuações): ");
            gets(medicos->celular);

            printf("Digite a data da consulta (dd/mm/aaaa): ");
            gets(medicos->data_consulta);

            fseek(arquivo, -byte, 1);
            fwrite(medicos, byte, 1, arquivo);
            printf("alterações feitas com sucesso!");
            printf("\nPressione enter para retornar ao menu");
            getchar();
            fclose(arquivo);
            return;
        }
    }

    printf("Nenhum Medico com este nome.\n");
    printf("\nPressione enter para retornar ao menu");
    getchar();
    fclose(arquivo);
}

void excluiMedico (struct Medico *medicos) {
    int byte = sizeof(struct Medico);
    FILE *arquivo;
    arquivo = fopen("medicos.txt", "r+");
    char medicoTemp[20];

    printf("Digite o nome do médico que você deseja excluir: ");
    gets(medicoTemp);
    convertePrimeiraLetraEmMaiuscula(medicoTemp);

    while (fread(medicos, byte, 1, arquivo)) {
        int contador = 0;
        int correspondente = 1;
        while (medicos->medico[contador] != '\0') {
                if (medicoTemp[contador] != medicos->medico[contador]) {
                    correspondente = 0;
                    break;
                }
                contador++;
            }
        if(correspondente){
        medicos->medico[0] = '*';


        fseek(arquivo, -byte, 1);
        fwrite(medicos, byte, 1, arquivo);
        printf("Excluido com sucesso!");
        printf("\nPressione enter para retornar ao menu");
        getchar();
        fclose(arquivo);
        return;
        }

    }
    printf("Nenhum Medico com este nome, insira o nome completo.\n");
    printf("\nPressione enter para retornar ao menu");
    getchar();
    fclose(arquivo);
}

int main() {
     setlocale(LC_ALL, "Portuguese");

     FILE *arquivo;

     arquivo =  fopen("medicos.txt", "r+");

     if(!arquivo) {
        printf("Arquivo novo criado\n\n");
        arquivo = fopen("medicos.txt", "w+");
        fclose(arquivo);
     } else {
        printf("arquivo aberto com sucesso!\n\n");
        fclose(arquivo);
     }


    Medico medicos;

    char decisao;

    while(1) {

    printf("\n1 – Entrada de dados");
    printf("\n2 – Lista todos os dados na tela.");
    printf("\n3–  Pesquisar medico pelo nome completo");
    printf("\n4 – Pesquisar celular pelo nome.");
    printf("\n5 – Pesquisa por data de consulta");
    printf("\n6 – altera dados.");
    printf("\n7 – exclui dados");
    printf("\n8 - saida");

    printf("\nO que você deseja fazer?");
    scanf(" %c", &decisao);
    getchar();
    switch (decisao) {

        case '1':
            system("cls");
            inserirDados(&medicos);
            break;
        case '2':
            system("cls");
            listarMedicos(&medicos);
            break;
         case '3':
            system("cls");
            pesquisaMedicoPeloNome(&medicos);
            break;
         case '4':
            system("cls");
            pesquisaCelular(&medicos);
            break;
         case '5':
            system("cls");
            pesquisaDataConsulta(&medicos);
            break;
         case '6':
            system("cls");
            alteraDados(&medicos);
            break;
         case '7':
            system("cls");
            excluiMedico(&medicos);
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

