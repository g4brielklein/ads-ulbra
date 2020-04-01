#include <stdio.h>
#include <locale.h>
#define size 10

struct student {
	char name[50], course[50], genre, email[50], phone[20], cellphone[20], city[50], address[50];
	int age, CGU;
}class[size];

int main() {
	int i;
	setlocale(LC_ALL, "portuguese");
	printf("Preencha as informa��es: \n");
	for (i=0; i < size; i++) {
		printf("\nDigite o nome: ");
		fflush(stdin);
		gets(class[i].name);
		printf("Digite o CGU: ");
		fflush(stdin);
		scanf("%d", &class[i].CGU);
		printf("Digite o curso: ");
		fflush(stdin);
		gets(class[i].course);
		printf("Digite a idade: ");
		fflush(stdin);
		scanf("%d", &class[i].age);
		printf("Digite o sexo (M/F): ");
		fflush(stdin);
		scanf("%c", &class[i].genre);
		printf("Digite o email: ");
		fflush(stdin);
		scanf("%s", &class[i].email);
		printf("Digite o telefone: ");
		fflush(stdin);
		gets(class[i].phone);
		printf("Digite o celular: ");
		fflush(stdin);
		gets(class[i].cellphone);
		printf("Digite a cidade: ");
		fflush(stdin);
		gets(class[i].city);
		printf("Digite o endere�o: ");
		fflush(stdin);
		gets(class[i].address);
	}
	
	printf("\nExibindo os dados:\n");
	
	for(i=0;i < size; i++) {
		printf("\nNome: %s\nCGU: %d\nCurso: %s\nIdade: %d anos\nSexo: %c\nEmail: %s\nTelefone: %s\nCelular: %s\nCidade: %s\nEndere�o: %s\n", 
		class[i].name, class[i].CGU, class[i].course, class[i].age, class[i].genre, class[i].email, class[i].phone, class[i].cellphone, class[i].city, class[i].address);
	}
	
	return 0;
}
