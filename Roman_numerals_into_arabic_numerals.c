
/* Camila Antiqueira*/

#include<stdio.h>

char funcao_letra(char c)  /* Fun��o utilizada para transformar letra min�scula em mai�scula caso necess�rio */

{
    c= c-32;
    return c;
}

int transforma_numero(char c)  /* Fun��o aplicada para converter n�meros romanos em algarismos ar�bicos */

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
    char romanos[10];     /* Vetor que recebe n�mero romano digitado pelo usu�rio */

    int romanosnum[9],       /* Vetor que recebe algarismos romanos transformados em ar�bicos */
        num=0,
        c,
        i=0;

    printf("\nDigite o numero romano: ");

    while(romanos[i-1]!=10)  /* Foi utilizado [i-1] para sair do while na posi��o correta */
    {
        scanf("%c",&romanos[i]); /* Esse while l� separadamente cada algarismo romano e converte em letra mai�scula */

        c=romanos[i];           /* (caso seja digitado min�sculo) e  a seguir em algarismo ar�bico */

        if(c>=97 && c<=122)

        	romanos[i]=funcao_letra(romanos[i]);

        romanosnum[i]=transforma_numero(romanos[i]);

        i++;
    }
    romanos[i]=('\0');

    i=0;  /* A vari�vel i � reinicializada, pois sai do while anterior com valor diferente de zero */

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
