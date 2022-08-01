#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "interface.h"


void Gotoxy(int linha, int coluna){
    COORD c;
    c.X = linha; c.Y = coluna;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void Caixa(int x, int y, int largura, int altura, int tipo){
    int i, j;
    unsigned char C[][6] = {{218, 196, 191, 179, 192, 217},
                            {201, 205, 187, 186, 200, 188}};
    Gotoxy(x, y); printf("%c", C[tipo][0]);
    for(i = 0; i < largura; i++) printf("%c", C[tipo][1]);
    printf("%c", C[tipo][2]);
    for(j = 0; j < altura; j++){
        Gotoxy(x, y + j + 1); printf("%c", C[tipo][3]);
        for(i = 0; i < largura; i++) printf(" ");
        printf("%c", C[tipo][3]);
    }
    Gotoxy(x, y + j + 1); printf("%c", C[tipo][4]);
    for(i = 0; i < largura; i++) printf("%c", C[tipo][1]);
    printf("%c", C[tipo][5]);
}

void Cores(int fundo, int letras){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), letras + (fundo << 4));
}


int Menu(int x[], int y[], char Opcoes[][20], int n){
    int i, Opcao = 0, tecla;
    TipoCursor(0);
    Cores(7, 0);
    for(i = 0; i < n; i++){
        Gotoxy(x[i], y[i]); printf("%s", Opcoes[i]);
    }
    do{
        Cores(0, 7);
        Gotoxy(x[Opcao], y[Opcao]); printf("%s", Opcoes[Opcao]);
        tecla = GetTecla();
        Cores(7, 0);
        Gotoxy(x[Opcao], y[Opcao]); printf("%s", Opcoes[Opcao]);
        if(tecla == TEC_ESQ) Opcao--;
        if(tecla == TEC_DIR) Opcao++;
        if(tecla == TEC_CIMA) Opcao--;
        if(tecla == TEC_BAIXO) Opcao++;
        
        if(tecla == TEC_ENTER){
                TipoCursor(1);
                return Opcao;
        }
        if(Opcao < 0) Opcao = n -1;
        if(Opcao >= n) Opcao = 0;
    }while(tecla != TEC_ESC);
    TipoCursor(1);
    return -1;
}

int GetTecla(){
    int ch;
    ch = getch();
    if(ch == 224){
        ch = getch() + 1000;
    }
    return ch;
}

void TipoCursor(int cursor){
    HANDLE myconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CURSOR;
    BOOL result;
    CURSOR.dwSize = 1;
    if(cursor == 0)
        CURSOR.bVisible = FALSE;
    else
        CURSOR.bVisible = TRUE;
    result = SetConsoleCursorInfo(myconsole, &CURSOR);
}




void Inicio(/*Tema t, int num*/){

    int cdf = 0;//t.letra;
    int fundo = 7;//t.fundo;

    Cores(fundo, cdf); Caixa(0, 0, 118, 28, 1);
    Cores(fundo, cdf); Caixa(2, 1, 114, 26, 1 );
    Caixa(90, 5, 26, 5, 1);
    Caixa(80, 10, 36, 5, 1);
    Caixa(70, 16, 46, 5, 1);
    Caixa(60, 22, 56, 5, 1);

    Gotoxy(12, 4);  printf("VVV             VVV   TTTTTTTTTTTTTTTT");
    Gotoxy(12, 5);  printf(" VVV           VVV    TTTTTTTTTTTTTTTT");
    Gotoxy(12, 6);  printf("  VVV         VVV            TTT      ");
    Gotoxy(12, 7);  printf("   VVV       VVV             TTT      ");
    Gotoxy(12, 8);  printf("    VVV     VVV              TTT      ");
    Gotoxy(12, 9);  printf("     VVV   VVV               TTT      ");
    Gotoxy(12, 10); printf("      VVV VVV                TTT      ");
    Gotoxy(12, 11); printf("       VVVVV                 TTT      ");
    Gotoxy(12, 12); printf("        VVV                  TTT      ");
    Gotoxy(12, 13); printf("         V                   TTT      ");

    Gotoxy(12, 16); printf("        Locadora de Equipamentos      ");



}












