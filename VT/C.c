#include <stdio.h>
// compila e inicia o programa
int main(){
    system("gcc main.c interface.c -o x");
    printf("DIGITE 's' PARA INICIAR O PROGRAMA: ");
    if(getch() == 's') system("x.exe");
    return 0;
}