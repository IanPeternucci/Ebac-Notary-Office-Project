#include <stdio.h> //comunica��o 
#include <stdlib.h> // aloca��o de espa�o na mem�ria 
#include <locale.h> // aloca��o de texto por regi�o
#include <string.h> // respons�vel pela string  

int registro() // Registro de nomes
{
	setlocale(LC_ALL, "Portuguese");// C�digo para ler acentos
	
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
	setlocale(LC_ALL, "Portuguese");// C�digo para ler acentos
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF que deseja consultar: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O arquivo n�o foi localizado!.\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essa s�o as informa��es do Usu�rio: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause"); 

}

int deletar() // Deletar nomes
{
	setlocale(LC_ALL, "Portuguese");// C�digo para ler acentos
	
	char cpf[40];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
    if(file == NULL)
	{
		printf("O us�ario n�o consta no sistema!.\n");
		system("pause");
	}
	
			
}

int main()
 {
 	int opcao = 0;	// Vari�vel que defini as op��es
 	int laco = 1; // Vari�vel de repeti��o
 
 for(laco=1;laco = 1;) 
 {
        system("cls");
    	
		setlocale(LC_ALL, "Portuguese");// C�digo para ler acentos 

 		printf("### Cart�rio Ebac ### \n"); // In�cio do Menu
 		printf("\nEscolha op��o desejada do menu: \n");
 		printf("\n\t1- Registro de nomes\n");
 		printf("\n\t2- Consulta de nomes\n");
 		printf("\n\t3- Deletar nomes\n\n");
 		printf("Op��o: "); // Fim do Menu
 
 		scanf("%d", &opcao); // Armazenamento das variav�is do us�ario
 
 		system("cls"); // Clear depois da escolha do us�ario 
		 
		switch(opcao)
		{
			case 1:
			registro();
     	    break;
     	    
     	    case 2:
     	    consulta();
 	 	    break;
 	 	    
 	 	    case 3:
			deletar(); // Fim da Sele��o
 	 	    break;
			
			default:
			printf("Est� op��o n�o est� disponivel,selecione umas das tr�s op��es \n");
 	 	    system("pause");
 	 	    break;
			 
			
		 } 
     }
}
 









