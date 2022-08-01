#include <stdio.h>
#include "interface.h"
#include <windows.h>

int main(){

    int Opcao;

    do{
        system("cls");
        
        Inicio();
        
        int x[] = {80,70,57,54};
        int y[] = {7,13,19,25};
        char Opcoes[][20] = {"Cadastrar", "Registrar", "Equipamentos", "Sair"};

        int x1[] = {92,92};
        int y1[] = {7,8};
        char Opcoes1[][20] = {"Cliente", "Equipamentos"};
        
        int x2[] = {82,82};
        int y2[] = {13,14};
        char Opcoes2[][20] = {"Aluguel", "Devolucao"};
        
        int x3[] = {72,72};
        int y3[] = {19,20};
        char Opcoes3[][20] = {"Disponiveis", "Alugados"};    
        

        Opcao = Menu(x, y, Opcoes, 4);
        if(Opcao == 0){
            Menu(x1, y1, Opcoes1, 2);
        }
        if(Opcao == 1){
            Menu(x2, y2, Opcoes2, 2);
        }
        if(Opcao == 2){
            Menu(x3, y3, Opcoes3, 2);
        }

    }while(Opcao != 3);
    Gotoxy(80, 25); printf(" Volte Sempre...");
    Gotoxy(68,27); system("pause");
    system("cls");

    return 0;
}