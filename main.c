
/*
 *
 *  � 2022 Henrique Almeida
 *
 */

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main()
{
    // Contadores
    int qnt = 0, total = 0, ext = 0;
    // Recebe o nome do arquivo assembly a ser compilado
    char name[50] = {0};
    // Declaracao do ponteiro de tipo DIR
    DIR *dir;
    // Estrutura de leitura do diretorio
    struct dirent *dirnt;

    // Aponta para o diretorio atual
    if ((dir = opendir(".")) == 0)
    {
        printf("\n Erro ao abrir o diretorio\n\n ");
        system("pause");
        return -1;
    }

    // Enquanto o proximo item no diretorio existir
    while ((dirnt = readdir(dir)) != 0)
    {
        total++;
        // Caso o arquivo tenha extensao assembly
        if (strcasecmp(strrchr(dirnt->d_name, 46), ".asm") == 0)
            break;
        else if (strcasecmp(strrchr(dirnt->d_name, 46), ".s") == 0)
        {
            ext++;
            break;
        }
        else
            qnt++;
    }

    // Impede a execucao do codigo caso nao haja arquivo assembly
    if (total == qnt)
    {
        printf("\n Nao foi encontrado arquivo assembly\n\n ");
        system("pause");
        return -1;
    }

    // Armazena o nome do arquivo antes de fechar a estrutura
    strcpy(name, dirnt->d_name);

    // Fim do ponteiro e do diret�rio
    closedir(dir);

    // Busca pelo ultimo '.' e o substitui por '\0', assim eliminando a extensao do arquivo assembly
    strrchr(name, '.')[0] = 0;

    // Primeiro  input, usado para compilar o asm em objeto
    char input1[100] = "nasm -f win64 -o ";
    // Segundo input, usado para compilar o objeto em executavel
    char input2[80] = "gcc ";
    // Terceiro input, usado para deletar o objeto
    char input3[70] = "del /f ";

    /*
        Caso exista mais de um arquivo assembly no diretorio, e necessario
        usar input de usuario para especificar qual arquivo asm sera compilado.
        Basta remover os comentarios das linhas 59 e 60
    */
    // printf(" Digite o nome do arquivo: ");
    // scanf(" %s", &name);

    // Montando comandos de linha usados na compilacao
    strcat(strcat(strcat(input1, name), ".obj "), name);
    if (ext == 0)
        strcat(input1, ".asm");
    else if (ext == 1)
        strcat(input1, ".s");
    strcat(strcat(strcat(strcat(input2, name), ".obj -o "), name), ".exe");
    strcat(strcat(input3, name), ".obj");

    // Comandos finais sao enviados ao terminal
    system(input1); system(input2); system(input3);

    // Input final, execucao do exe gerado
    system(strcat(name, ".exe"));

    // Pausa para leitura do output gerado
    printf("\n\n  ");
    system("pause");
    return 0;
}
