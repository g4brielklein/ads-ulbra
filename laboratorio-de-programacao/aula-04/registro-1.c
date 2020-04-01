#include <stdio.h>
#include <locale.h>

struct student {
	char name[50], course[50], genre, email[50], phone[20], cellphone[20], city[50], address[50];
	int age, CGU;
}student;

int main() {
	setlocale(LC_ALL, "portuguese");
	printf("Preencha as informações: \n");
	printf("Digite o nome: ");
	fflush(stdin);
	gets(student.name);
	printf("Digite o CGU: ");
	fflush(stdin);
	scanf("%d", &student.CGU);
	printf("Digite o curso: ");
	fflush(stdin);
	gets(student.course);
	printf("Digite a idade: ");
	fflush(stdin);
	scanf("%d", &student.age);
	printf("Digite o sexo (M/F): ");
	fflush(stdin);
	scanf("%c", &student.genre);
	printf("Digite o email: ");
	fflush(stdin);
	scanf("%s", &student.email);
	printf("Digite o telefone: ");
	fflush(stdin);
	gets(student.phone);
	printf("Digite o celular: ");
	fflush(stdin);
	gets(student.cellphone);
	printf("Digite a cidade: ");
	fflush(stdin);
	gets(student.city);
	printf("Digite o endereço: ");
	fflush(stdin);
	gets(student.address);
	
	printf("\nExibindo os dados:\nNome: %s\nCGU: %d\nCurso: %s\nIdade: %d anos\nSexo: %c\nEmail: %s\nTelefone: %s\nCelular: %s\nCidade: %s\nEndereço: %s\n", 
	student.name, student.CGU, student.course, student.age, student.genre, student.email, student.phone, student.cellphone, student.city, student.address);
	return 0;
}
