#include <stdio.h> //comunicação 
#include <stdlib.h> // alocação de espaço na memória 
#include <locale.h> // alocação de texto por região
#include <string.h> // responsável pela string  

int registro() // Registro de nomes
{
	setlocale(LC_ALL, "Portuguese");// Código para ler acentos
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo,cpf); // copiar valores das strings
	
	FILE *file; // cria arquivo no banco de dados
	file = fopen(arquivo, "w"); 
	fprintf(file,cpf); // salva valor da variavel 
	fclose(file);  // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:  ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	system("pause"); 

}

int consulta() // Consulta de nomes
{
	setlocale(LC_ALL, "Portuguese");// Código para ler acentos
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF que deseja consultar: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O arquivo não foi localizado!.\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essa são as informações do Usuário: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause"); 

}

int deletar() // Deletar nomes
{
	setlocale(LC_ALL, "Portuguese");// Código para ler acentos
	
	char cpf[40];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
    if(file == NULL)
	{
		printf("O usúario não consta no sistema!.\n");
		system("pause");
	}
	
			
}

int main()
 {
 	int opcao = 0;	// Variável que defini as opções
 	int laco = 1; // Variável de repetição
 
 for(laco=1;laco = 1;) 
 {
        system("cls");
    	
		setlocale(LC_ALL, "Portuguese");// Código para ler acentos 

 		printf("### Cartório Ebac ### \n"); // Início do Menu
 		printf("\nEscolha opção desejada do menu: \n");
 		printf("\n\t1- Registro de nomes\n");
 		printf("\n\t2- Consulta de nomes\n");
 		printf("\n\t3- Deletar nomes\n\n");
 		printf("Opção: "); // Fim do Menu
 
 		scanf("%d", &opcao); // Armazenamento das variavéis do usúario
 
 		system("cls"); // Clear depois da escolha do usúario 
		 
		switch(opcao)
		{
			case 1:
			registro();
     	    break;
     	    
     	    case 2:
     	    consulta();
 	 	    break;
 	 	    
 	 	    case 3:
			deletar(); // Fim da Seleção
 	 	    break;
			
			default:
			printf("Está opção não está disponivel,selecione umas das três opções \n");
 	 	    system("pause");
 	 	    break;
			 
			
		 } 
     }
}
 









