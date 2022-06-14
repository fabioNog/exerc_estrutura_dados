#include <stdio.h>
#include <stdlib.h>

int main(){
    int num = 12;
    int num2 = 10;
    int resto = num % num2;
    int valorDadivisao = num/num2;

    int valorOriginal = valorDadivisao*10 + resto;
    

    printf(" %d %d %d",valorDadivisao,resto,valorOriginal);
}


