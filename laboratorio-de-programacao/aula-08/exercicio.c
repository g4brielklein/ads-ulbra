#include <stdio.h>

void subtrai ( ){
    int a, b, c;
	printf ("\n Digite um valor: ");
	scanf("%d",&a);
	printf ("\n Digite um valor: ");
	scanf("%d",&b);
	c = a - b;
	printf ("\n Resultado: %d \n\n",c);
	getch();
};

void soma ( ){	
    int a, b, c;
	printf ("\n Digite um valor: ");
	scanf("%d",&a);
	printf ("\n Digite um valor: ");
	scanf("%d",&b);
	c = a + b;
	printf ("\n Resultado: %d \n\n",c);
	getch();
};

main()
{
    char Menu;
    do
    {
        system("cls");
        fflush(stdin);
        printf("\n Menu Principal\n");
        printf("\n A - Adicao");
        printf("\n B - Subtracao");
        printf("\n E - Sair");
        printf("\n\nOpcao: ");
         Menu = getche();
        Menu = toupper(Menu);
        switch (Menu) {
        case 'A':
            system("cls");
            printf("\nAdicao");
             soma();
             getch(); 
            break;
        case 'B': system("cls");
            printf("\nSubtracao");
             subtrai();
             getch(); 
            break;
        case 'E': printf("\nSaindo..."); 
            sleep(3);
            break;
        default : printf("\n Opcao invalida"); 
             getch();
        } 
    }
    while (Menu!='E');
}
