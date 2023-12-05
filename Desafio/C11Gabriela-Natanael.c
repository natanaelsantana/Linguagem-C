#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


char medico1[20];
char medico2[20];
char medico3[20];


char data_consulta1[11];
char data_consulta2[11];
char data_consulta3[11];

char medico[20];


int verificadorDeMedicoExistente (char medico[20]) {
    FILE *arquivo;

    arquivo = fopen("banco_de_dados.txt", "r+");

     if (medico[0] >= 'a' && medico[0] <= 'z'){
            medico[0] -=  32;
    }


    fread(&medico1, sizeof(medico1), 1, arquivo);
    fread(&medico2, sizeof(medico2), 1, arquivo);
    fread(&medico3, sizeof(medico3), 1, arquivo);

    fclose(arquivo);

    int correspondente1 = 1;
    int correspondente2 = 1;
    int correspondente3 = 1;

    int contador = 0;

    while (medico[contador] != '\0') {
        if (medico[contador] != medico1[contador]) {
            correspondente1 = 0;
            break;
        }
        contador++;
    }

    contador = 0;

    while (medico[contador] != '\0') {
        if (medico[contador] != medico2[contador]) {
            correspondente2 = 0;
            break;
        }
        contador++;
    }

    contador = 0;

    while (medico[contador] != '\0') {
        if (medico[contador] != medico3[contador]) {
            correspondente3 = 0;
            break;
        }
        contador++;
    }

    if (correspondente1 || correspondente2 || correspondente3) {
        printf("\nJá existe um médico com esse nome. Comece novamente\n");
        system("pause");
        system("cls");
        return 0;
    }

    return 1;
}

void entradaDeDados () {
    FILE *arquivo;

    arquivo = fopen("banco_de_dados.txt", "r+");


    int contador = 0;

    char medicoTemp[20];
    char dataTemp[11];

   while(contador < 3) {

    printf("Escreva o nome do médico: ");
    scanf("%s", medicoTemp);

    if (medicoTemp[0] >= 'a' && medicoTemp[0] <= 'z'){
            medicoTemp[0] -=  32;
    }
    printf("Escreva a data da consulta  no seguinte formato (dd/mm/ano): ");
    scanf("%s", dataTemp);



    int i = 0;
    int j = 0;

    switch(contador){
        case 0:
            while(1){
                medico1[i] = medicoTemp[i];
                if(medico1[i] == '\0' && medicoTemp[i]== '\0') {
                    break;
                }
                i++;
            }

            while(1) {
                data_consulta1[j] = dataTemp[j];
                if(data_consulta1[j] == '\0' && dataTemp[j]== '\0') {
                    break;
                }
                j++;
            }

            fwrite(&medico1, sizeof(medico1), 1, arquivo);
            fwrite(&data_consulta1, sizeof(data_consulta1), 1, arquivo);
        break;
        case 1:
            while(1){
                medico2[i] = medicoTemp[i];

                if(medico2[i] == '\0' && medicoTemp[i]== '\0') {
                    break;
                }
                i++;
            }

            while(1) {
                data_consulta2[j] = dataTemp[j];
                if(data_consulta2[j] == '\0' && dataTemp[j]== '\0') {
                    break;
                }
                j++;
            }

            fwrite(&medico2, sizeof(medico2), 1, arquivo);
            fwrite(&data_consulta2, sizeof(data_consulta2), 1, arquivo);
            break;
        case 2:
            while(1){
                medico3[i] = medicoTemp[i];

                if(medico3[i] == '\0' && medicoTemp[i]== '\0') {
                    break;
                }
                i++;
            }
            while(1) {
                data_consulta3[j] = dataTemp[j];
                if(data_consulta3[j] == '\0' && dataTemp[j]== '\0') {
                    break;
                }
                j++;
            }
            fwrite(&medico3, sizeof(medico3), 1, arquivo);
            fwrite(&data_consulta3, sizeof(data_consulta3), 1, arquivo);
        break;
    }

    contador++;
   }


    fclose(arquivo);

    system("cls");

}

void listaTodosOsDados () {
    FILE *arquivo;

    arquivo = fopen("banco_de_dados.txt", "r");


    fread(&medico1, sizeof(medico1), 1, arquivo);
    fread(&data_consulta1, sizeof(data_consulta1), 1, arquivo);

    fread(&medico2, sizeof(medico2), 1, arquivo);
    fread(&data_consulta2, sizeof(data_consulta2), 1, arquivo);

    fread(&medico3, sizeof(medico3), 1, arquivo);
    fread(&data_consulta3, sizeof(data_consulta3), 1, arquivo);

    if(medico1[0] != '@'){
    printf("\n Medico: %s                 Data: %s\n", medico1, data_consulta1);
    }

    if(medico2[0] != '@') {
    printf(" Medico: %s                 Data: %s\n", medico2, data_consulta2);
    }

    if(medico3[0] != '@'){
    printf(" Medico: %s                 Data: %s\n\n", medico3, data_consulta3);
    }

    system("pause");

    fclose(arquivo);
    system("cls");


}

void pesquisaPorNomeCompleto() {
     FILE *arquivo;

     arquivo = fopen("banco_de_dados.txt", "r");

    fread(&medico1, sizeof(medico1), 1, arquivo);
    fread(&data_consulta1, sizeof(data_consulta1), 1, arquivo);

    fread(&medico2, sizeof(medico2), 1, arquivo);
    fread(&data_consulta2, sizeof(data_consulta2), 1, arquivo);

    fread(&medico3, sizeof(medico3), 1, arquivo);
    fread(&data_consulta3, sizeof(data_consulta3), 1, arquivo);

     char medicoTemp[20];

     printf("Escreva o nome do médico: ");
     scanf("%s", medicoTemp);



    int encontrado = 0;

    int correspondente1 = 1;
    int contador1 = 0;
    while (medicoTemp[contador1] != '\0') {
        if (medicoTemp[contador1] != medico1[contador1]) {
            correspondente1 = 0;
            break;
        }
        contador1++;
    }
    if (correspondente1) {
        printf("Médico: %s  Data: %s\n\n", medico1, data_consulta1);
        encontrado++;
    }

    int correspondente2 = 1;
    int contador2 = 0;
    while (medicoTemp[contador2] != '\0') {
        if (medicoTemp[contador2] != medico2[contador2]) {
            correspondente2 = 0;
            break;
        }
        contador2++;
    }
    if (correspondente2) {
        printf("Médico: %s  Data: %s\n\n", medico2, data_consulta2);
        encontrado++;
    }

    int correspondente3 = 1;
    int contador3 = 0;
    while (medicoTemp[contador3] != '\0') {
        if (medicoTemp[contador3] != medico3[contador3]) {
            correspondente3 = 0;
            break;
        }
        contador3++;
    }
    if (correspondente3) {
        printf("Médico: %s  Data: %s\n\n", medico3, data_consulta3);
        encontrado++;
    }

    if (!encontrado) {
        printf("Nenhum médico encontrado com o nome especificado.\n");
    }

    system("pause");
    fclose(arquivo);
    system("cls");

}

void pesquisaDataDeConsulta() {
    FILE *arquivo;

     arquivo = fopen("banco_de_dados.txt", "r");

    fread(&medico1, sizeof(medico1), 1, arquivo);
    fread(&data_consulta1, sizeof(data_consulta1), 1, arquivo);

    fread(&medico2, sizeof(medico2), 1, arquivo);
    fread(&data_consulta2, sizeof(data_consulta2), 1, arquivo);

    fread(&medico3, sizeof(medico3), 1, arquivo);
    fread(&data_consulta3, sizeof(data_consulta3), 1, arquivo);

     char dataTemp[11];

     printf("Escreva a data: ");
     scanf("%s", &dataTemp);


    int encontrado = 0;
    int correspondente1 = 1;
    int contador1 = 0;
    int verificadorDeMedico1 = 0;
    int verificadorDeMedico2 = 0;
    while (dataTemp[contador1] != '\0') {



        if (dataTemp[contador1] != data_consulta1[contador1]) {
            correspondente1 = 0;
            break;
        }

        //Verificar se a mesma data está com outros médicos
        if (dataTemp[contador1] == data_consulta2[contador1]) {
            verificadorDeMedico1++;
        }

         if (dataTemp[contador1] == data_consulta3[contador1]) {
            verificadorDeMedico2++;
        }



        contador1++;
    }
    if (correspondente1) {
        printf("Médico: %s  Data: %s\n\n", medico1, data_consulta1);
        encontrado++;
    } else if(correspondente1 && verificadorDeMedico1 == 10) {
        printf("Médico: %s  Data: %s\n\n", medico1, data_consulta1);
        printf("Médico: %s  Data: %s\n\n", medico2, data_consulta2);
        encontrado++;

    } else if(correspondente1 && verificadorDeMedico2 == 10) {
        printf("Médico: %s  Data: %s\n\n", medico1, data_consulta1);
        printf("Médico: %s  Data: %s\n\n", medico3, data_consulta3);
        encontrado++;

    } else if(correspondente1 && verificadorDeMedico1 == 10 && verificadorDeMedico2 == 10) {
        printf("Médico: %s  Data: %s\n\n", medico1, data_consulta1);
        printf("Médico: %s  Data: %s\n\n", medico2, data_consulta2);
        printf("Médico: %s  Data: %s\n\n", medico3, data_consulta3);
        encontrado++;
    }




    int correspondente2 = 1;
    int contador2 = 0;
    verificadorDeMedico1 = 0;
    verificadorDeMedico2 = 0;
    while (dataTemp[contador2] != '\0') {
        if (dataTemp[contador2] != data_consulta2[contador2]) {
            correspondente2 = 0;
            break;
        }

        //Verificar se a mesma data está com outros médicos
        if (dataTemp[contador2] == data_consulta1[contador2]) {
            verificadorDeMedico1++;
        }

         if (dataTemp[contador2] == data_consulta3[contador2]) {
            verificadorDeMedico2++;
        }

        contador2++;
    }
    if (correspondente2) {
        printf("Médico: %s  Data: %s\n\n", medico2, data_consulta2);
        encontrado++;
    } else if(correspondente2 && verificadorDeMedico1 == 10) {
        printf("Médico: %s  Data: %s\n\n", medico2, data_consulta2);
        printf("Médico: %s  Data: %s\n\n", medico1, data_consulta1);
        encontrado++;

    } else if(correspondente2 && verificadorDeMedico2 == 10) {
        printf("Médico: %s  Data: %s\n\n", medico2, data_consulta2);
        printf("Médico: %s  Data: %s\n\n", medico3, data_consulta3);
        encontrado++;

    } else if(correspondente2 && verificadorDeMedico1 == 10 && verificadorDeMedico2 == 10) {
        printf("Médico: %s  Data: %s\n\n", medico1, data_consulta1);
        printf("Médico: %s  Data: %s\n\n", medico2, data_consulta2);
        printf("Médico: %s  Data: %s\n\n", medico3, data_consulta3);
        encontrado++;
    }



    int correspondente3 = 1;
    int contador3 = 0;
    verificadorDeMedico1 = 0;
    verificadorDeMedico2 = 0;
    while (dataTemp[contador3] != '\0') {
        if (dataTemp[contador3] != data_consulta3[contador3]) {
            correspondente3 = 0;
            break;
        }


         //Verificar se a mesma data está com outros médicos
        if (dataTemp[contador3] == data_consulta1[contador3]) {
            verificadorDeMedico1++;
        }

         if (dataTemp[contador3] == data_consulta2[contador3]) {
            verificadorDeMedico2++;
        }

        contador3++;
    }
    if (correspondente3) {
        printf("Médico: %s  Data: %s\n\n", medico3, data_consulta3);
        encontrado++;
    } else if(correspondente3 && verificadorDeMedico1 == 10) {
        printf("Médico: %s  Data: %s\n\n", medico3, data_consulta3);
        printf("Médico: %s  Data: %s\n\n", medico1, data_consulta1);
        encontrado++;

    } else if(correspondente3 && verificadorDeMedico2 == 10) {
        printf("Médico: %s  Data: %s\n\n", medico3, data_consulta3);
        printf("Médico: %s  Data: %s\n\n", medico2, data_consulta2);
        encontrado++;

    } else if(correspondente2 && verificadorDeMedico1 == 10 && verificadorDeMedico2 == 10) {
        printf("Médico: %s  Data: %s\n\n", medico1, data_consulta1);
        printf("Médico: %s  Data: %s\n\n", medico2, data_consulta2);
        printf("Médico: %s  Data: %s\n\n", medico3, data_consulta3);
        encontrado++;
    }


    if (!encontrado) {
        printf("Nenhum médico encontrado com a data especificado.\n\n");
    }

    system("pause");
    fclose(arquivo);
    system("cls");
}

void AlteraDados() {

    FILE *arquivo;


     char medicoTemp[20];
     char dataTemp[11];

     printf("Escreva o nome do médico: ");
     scanf("%s", medicoTemp);

    arquivo = fopen("banco_de_dados.txt", "r");

    fread(&medico1, sizeof(medico1), 1, arquivo);
    fread(&data_consulta1, sizeof(data_consulta1), 1, arquivo);
    fread(&medico2, sizeof(medico2), 1, arquivo);
    fread(&data_consulta2, sizeof(data_consulta2), 1, arquivo);
    fread(&medico3, sizeof(medico3), 1, arquivo);
    fread(&data_consulta3, sizeof(data_consulta3), 1, arquivo);


    fclose(arquivo);

    int encontrado = 0;

    int correspondente1 = 1;
    int contador1 = 0;
    while (medicoTemp[contador1] != '\0') {

        if (medicoTemp[contador1] != medico1[contador1]) {
            correspondente1 = 0;
            break;
        }
        contador1++;
    }
    if (correspondente1) {
        printf("Médico: %s  Data: %s\n\n", medico1, data_consulta1);
        encontrado++;

        printf("Alteração de dados\n\n");

        printf("Insira o novo nome: ");
        scanf("%s", medicoTemp);

        int verificador = verificadorDeMedicoExistente(medicoTemp);

        if(verificador == 0) {
            fclose(arquivo);
            return;
        }

        int i = 0;
        while(1){
            medico1[i] = medicoTemp[i];

            if(medico1[i] == '\0') {
                break;
            }
            i++;
        }

        i = 0;
        printf("Insira a nova data: ");
        scanf("%s", dataTemp);
        while(1){
            data_consulta1[i] = dataTemp[i];

            if(data_consulta1[i] == '\0') {
                break;
            }
            i++;
        }

        arquivo = fopen("banco_de_dados.txt", "r+");


        fwrite(medico1, sizeof(medico1), 1, arquivo);
        fwrite(data_consulta1, sizeof(data_consulta1), 1, arquivo);

        printf("Dados salvos com sucesso\n");

        system("pause");
        fclose(arquivo);
        system("cls");
        return;
    }


    int correspondente2 = 1;
    int contador2 = 0;
    while (medicoTemp[contador2] != '\0') {
        if (medicoTemp[contador2] != medico2[contador2]) {
            correspondente2 = 0;
            break;
        }
        contador2++;
    }
    if (correspondente2) {
        printf("Médico: %s  Data: %s\n", medico2, data_consulta2);
        encontrado++;

        printf("Alteração de dados\n\n");

        printf("Insira o novo nome: ");
        scanf("%s", medicoTemp);

        int i = 0;
        while(1){
            medico2[i] = medicoTemp[i];

            if(medico2[i] == '\0') {
                break;
            }
            i++;
        }

        int verificador = verificadorDeMedicoExistente(medico2);

        if(verificador == 0) {
            fclose(arquivo);
            return;
        }

        i = 0;
        printf("Insira a nova data: ");
        scanf("%s", dataTemp);
        while(1){
            data_consulta2[i] = dataTemp[i];

            if(data_consulta2[i] == '\0') {
                break;
            }
            i++;
        }


        arquivo = fopen("banco_de_dados.txt", "r+");

        //Posicionando o ponteiro para que ele atribua o valor na variável correta
        fwrite(&medico1, sizeof(medico1), 1, arquivo);
        fwrite(&data_consulta1, sizeof(data_consulta1), 1, arquivo);

        fwrite(medico2, sizeof(medico2), 1, arquivo);
        fwrite(data_consulta2, sizeof(data_consulta2), 1, arquivo);

        printf("Dados salvos com sucesso\n");


        system("pause");
        fclose(arquivo);
        system("cls");
        return;
    }

    int correspondente3 = 1;
    int contador3 = 0;
    while (medicoTemp[contador3] != '\0') {
        if (medicoTemp[contador3] != medico3[contador3]) {
            correspondente3 = 0;
            break;
        }
        contador3++;
    }
    if (correspondente3) {
        printf("Médico: %s  Data: %s\n", medico3, data_consulta3);
        encontrado++;

        printf("Alteração de dados\n\n");

        printf("Insira o novo nome: ");
        scanf("%s", medicoTemp);

        int verificador = verificadorDeMedicoExistente(medicoTemp);

        if(verificador == 0) {
            fclose(arquivo);
            return;
        }

        int i = 0;
        while(1){
            medico3[i] = medicoTemp[i];

            if(medico3[i] == '\0') {
                break;
            }
            i++;
        }
        i= 0;
        printf("Insira a nova data: ");
        scanf("%s", dataTemp);
        while(1){
            data_consulta3[i] = dataTemp[i];

            if(data_consulta3[i] == '\0') {
                break;
            }
            i++;
        }


        arquivo = fopen("banco_de_dados.txt", "r+");

        //Posicionando o ponteiro para que ele atribua o valor na variável correta
        fwrite(&medico1, sizeof(medico1), 1, arquivo);
        fwrite(&data_consulta1, sizeof(data_consulta1), 1, arquivo);
        fwrite(&medico2, sizeof(medico2), 1, arquivo);
        fwrite(&data_consulta2, sizeof(data_consulta2), 1, arquivo);

        //Escrita de variável corretamente
        fwrite(medico3, sizeof(medico3), 1, arquivo);
        fwrite(data_consulta3, sizeof(data_consulta3), 1, arquivo);

        printf("Dados salvos com sucesso\n");


        system("pause");
        fclose(arquivo);
        system("cls");
        return;
    }
    if (!encontrado) {
        printf("Nenhum médico encontrado com o nome especificado.\n");
        system("pause");
        system("cls");
        return;
    }


}

void excluiDados () {
     FILE *arquivo;

     arquivo = fopen("banco_de_dados.txt", "r");

    fread(&medico1, sizeof(medico1), 1, arquivo);
    fread(&data_consulta1, sizeof(data_consulta1), 1, arquivo);

    fread(&medico2, sizeof(medico2), 1, arquivo);
    fread(&data_consulta2, sizeof(data_consulta2), 1, arquivo);

    fread(&medico3, sizeof(medico3), 1, arquivo);
    fread(&data_consulta3, sizeof(data_consulta3), 1, arquivo);

    fclose(arquivo);

     char medicoTemp[20];

     printf("Escreva o nome do médico: ");
     scanf("%s", medicoTemp);



    int encontrado = 0;
    int escolha = 0;

    int correspondente1 = 1;
    int contador1 = 0;
    while (medicoTemp[contador1] != '\0') {
        if (medicoTemp[contador1] != medico1[contador1]) {
            correspondente1 = 0;
            break;
        }
        contador1++;
    }
    if (correspondente1) {
        printf("Médico: %s  Data: %s\n", medico1, data_consulta1);
        encontrado++;

        printf("Tem certeza que deseja excluir os dados?\n  [1] SIM  [2] NÂO\n");
        scanf("%d", &escolha);

        if(escolha == 1){
            medico1[0] = '@';
            data_consulta1[0] = '@';
            arquivo = fopen("banco_de_dados.txt", "r+");



            fwrite(medico1, sizeof(medico1), 1, arquivo);
            fwrite(data_consulta1, sizeof(data_consulta1), 1, arquivo);

            printf("Dados excluidos com sucesso\n\n");

            system("pause");
            fclose(arquivo);
            system("cls");
            return;

        } else {
            system("cls");
            return;
        }

    }

    int correspondente2 = 1;
    int contador2 = 0;
    while (medicoTemp[contador2] != '\0') {
        if (medicoTemp[contador2] != medico2[contador2]) {
            correspondente2 = 0;
            break;
        }
        contador2++;
    }
    if (correspondente2) {
        printf("Médico: %s  Data: %s\n", medico2, data_consulta2);
        encontrado++;

        printf("Tem certeza que deseja excluir os dados?\n  [1] SIM  [2] NÂO\n");
        scanf("%d", &escolha);

        if(escolha == 1){
            medico2[0] = '@';
            data_consulta2[0] = '@';

             arquivo = fopen("banco_de_dados.txt", "r+");

            //Posicionando o ponteiro para que ele atribua o valor na variável correta
            fwrite(&medico1, sizeof(medico1), 1, arquivo);
            fwrite(&data_consulta1, sizeof(data_consulta1), 1, arquivo);


            //Escrita de variável corretamente
            fwrite(medico2, sizeof(medico2), 1, arquivo);
            fwrite(data_consulta2, sizeof(data_consulta2), 1, arquivo);


            printf("Dados excluidos com sucesso\n\n");

            system("pause");
            fclose(arquivo);
            system("cls");
            return;
        } else {
            system("cls");
            return ;
        }
    }

    int correspondente3 = 1;
    int contador3 = 0;
    while (medicoTemp[contador3] != '\0') {
        if (medicoTemp[contador3] != medico3[contador3]) {
            correspondente3 = 0;
            break;
        }
        contador3++;
    }
    if (correspondente3) {
        printf("Médico: %s  Data: %s\n", medico3, data_consulta3);
        encontrado++;

        printf("Tem certeza que deseja excluir os dados?\n  [1] SIM  [2] NÂO\n");
        scanf("%d", &escolha);

        if(escolha == 1){
            medico3[0] = '@';
            data_consulta3[0] = '@';
            //Posicionando o ponteiro para que ele atribua o valor na variável correta
            fwrite(&medico1, sizeof(medico1), 1, arquivo);
            fwrite(&data_consulta1, sizeof(data_consulta1), 1, arquivo);
            fwrite(&medico2, sizeof(medico2), 1, arquivo);
            fwrite(&data_consulta2, sizeof(data_consulta2), 1, arquivo);

            //Escrita de variável corretamente
            fwrite(medico3, sizeof(medico3), 1, arquivo);
            fwrite(data_consulta3, sizeof(data_consulta3), 1, arquivo);

            printf("Dados excluidos com sucesso\n\n");

            system("pause");
            fclose(arquivo);
            system("cls");
            return;


        } else {
            system("cls");
            return;
        }
    }

    if (!encontrado) {
        printf("Nenhum médico encontrado com o nome especificado.\n\n");
    }



    system("pause");
    fclose(arquivo);
    system("cls");
}



main () {

    setlocale(LC_ALL, "Portuguese");

    FILE *arquivo;

    arquivo = fopen("banco_de_dados.txt", "r+");

    if (!arquivo) {
        arquivo = fopen("banco_de_dados.txt", "w+");
        fclose(arquivo);
        if (!arquivo) {
            printf("Erro ao criar o arquivo.\n");
            return 1;
        }
        printf("Novo arquivo criado\n");
    } else {
        printf("Trabalhando em arquivo existente\n\n");
        fclose(arquivo);

    }

    char decisao;

    while(1) {
    printf("\n1 – Entrada de dados.");
    printf("\n2 – Lista todos os dados na tela.");
    printf("\n3– Pesquisa um médico pelo nome completo e mostra todo os dados na tela");
    printf("\n4 – Pesquisa pela data de consulta e mostra todos na tela.");
    printf("\n5 – Altera dados. Pesquisa pelo nome completo do médico.");
    printf("\n6 – Exclui dados. Pesquisa pelo nome completo do médico.");
    printf("\n7 – Saída\n");

    printf("\nO que você deseja fazer?");
    scanf(" %c", &decisao);

    switch (decisao) {

        case '1':
            system("cls");
            entradaDeDados();
            break;
        case '2':
            listaTodosOsDados();
            break;
         case '3':
            system("cls");
            pesquisaPorNomeCompleto();
            break;
         case '4':
            system("cls");
            pesquisaDataDeConsulta();
            break;
         case '5':
            system("cls");
            AlteraDados();
            break;
         case '6':
            excluiDados();
            break;
         case '7':
            exit(0);
            break;
        default:
            printf("Opção inválida\n");
            system("cls");
            break;
    }
    }
}
