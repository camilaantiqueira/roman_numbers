
/* Camila Antiqueira*/

#include<stdio.h>

char funcao_letra(char c)  /* Função utilizada para transformar letra minúscula em maiúscula caso necessário */

{
    c= c-32;
    return c;
}

int transforma_numero(char c)  /* Função aplicada para converter números romanos em algarismos arábicos */

{
    int numero;

    if (c == 'I')
        numero=1;

    else if (c=='V')
        numero=5;

    else if(c=='X')
        numero=10;

    else if (c=='L')
        numero=50;

    else if (c=='C')
        numero=100;

    else if (c=='D')
        numero=500;

    else if (c=='M')
        numero=1000;

    else
        numero=0;

    return numero;
}

main ()

{
    char romanos[10];     /* Vetor que recebe número romano digitado pelo usuário */

    int romanosnum[9],       /* Vetor que recebe algarismos romanos transformados em arábicos */
        num=0,
        c,
        i=0;

    printf("\nDigite o numero romano: ");

    while(romanos[i-1]!=10)  /* Foi utilizado [i-1] para sair do while na posição correta */
    {
        scanf("%c",&romanos[i]); /* Esse while lê separadamente cada algarismo romano e converte em letra maiúscula */

        c=romanos[i];           /* (caso seja digitado minúsculo) e  a seguir em algarismo arábico */

        if(c>=97 && c<=122)

        	romanos[i]=funcao_letra(romanos[i]);

        romanosnum[i]=transforma_numero(romanos[i]);

        i++;
    }
    romanos[i]=('\0');

    i=0;  /* A variável i é reinicializada, pois sai do while anterior com valor diferente de zero */

    while(romanosnum[i]!= 0)     /*Esse while foi utilizado para somar cada elemento do vetor romanosnum cujo
                                    conteudo era diferente de zero*/
    {
        if (romanosnum[i] >= romanosnum[i + 1])
        {
            num+= romanosnum[i];
        }

        else if (romanosnum[i] < romanosnum[i + 1])
        {
            num-= romanosnum[i];
        }

        i++;
    }
    printf("\n%d\n",num);
}
