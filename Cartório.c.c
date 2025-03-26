#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string
		
int registro()// Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: ");// Coletando informa��o dos usu�rios
	scanf("%s", cpf);// %s refere-se as string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");// Abrindo a pasta 
	fprintf(file,","); // Adicionando a v�rgula entre as palavras
	fclose(file);// Fechando a pasta
	
	printf("Digite o nome a ser cadastrado: ");// Coletando informa��o do usu�rio
	scanf("%s",nome);// %s refere-se as string
	
	file = fopen(arquivo, "a"); // Abrindo a pasta 
	fprintf(file,nome);// salvo o valor da variavel
	fclose(file);// Fechando a pasta
	
	file = fopen(arquivo, "a");// Abrindo a pasta 
	fprintf(file,",");// Adicionando a v�rgula entre as palavras
	fclose(file);// Fechando a pasta
	
	printf("Digite o sobrenome a ser cadastrado: ");// Coletando informa��o do usu�rio
	scanf("%s",sobrenome);// %s refere-se as string
	
	file = fopen(arquivo, "a");// Abrindo a pasta 
	fprintf(file,sobrenome);// salvo o valor da variavel
	fclose(file);// Fechando a pasta
	
	file = fopen(arquivo, "a");// Abrindo a pasta 
	fprintf(file,",");// Adicionando a v�rgula entre as palavras
	fclose(file);// Fechando a pasta
	
	printf("Digite o cargo a ser cadastrado: ");// Coletando informa��o do usu�rio
	scanf("%s",cargo);// %s refere-se as string
	
	file = fopen(arquivo, "a");// Abrindo a pasta 
	fprintf(file,cargo);// salvo o valor da variavel
	fclose(file);// Fechando a pasta	
	
    system("pause");// Pausando a tela 

}

int consulta()// Fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//inicio da cria��o de vari�veis/string
    char cpf[40];
    char conteudo [200];
    //final da cria��o de vari�veis/string
    
    printf("Digite o CPF a ser consultado: ");// Coletando informa��o do usu�rio
    scanf("%s",cpf);// %s refere-se as string
    
    FILE *file;// cria o arquivo
    file = fopen(cpf, "r");// Abrindo e lendo a pasta 
    
    
    if(file == NULL)//condicional para ver se encontra o CPF do usu�rio
    {
    	printf("\nN�o foi possivel abrir o arquivo, n�o localizado!\n\n"); //Informando o usu�rio que o CPF n�o foi localizado
	}
	
	while(fgets(conteudo,200,file) != NULL)//Fun��o para encontrar CPF do �suario
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");// Mensagem ao usu�rio informando que o CPF foi localizado
		printf("%s",conteudo);// %s refere-se as string
		printf("\n\n");//pulando linhas
	}
	system("pause");//Pausando sistema
	fclose(file);// Fechando a pasta
}

int deletar()
{
	//inicio da cria��o de vari�veis/string
	char cpf[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF do usu�rio a ser deletado: ");// Coletando informa��o do usu�rio
	scanf("%s",cpf);// %s refere-se as string
	
	FILE *file;// cria o arquivo
	file = fopen(cpf,"r");// Abrindo o arquivo
	fclose(file);// Fechando o arquivo

	if(file == NULL)//Condicional para encontrar CPF
	{
		printf("O usu�rio n�o se encontra no sistema!\n");// Mensagem que aparece ao usu�rio caso n�o encontre o CPF
		system("pause");// Pausando o sistema
	}
	else
	{
		printf("O usu�rio encontrado foi excluido do sistema!\n");// Mensagem que aparece ao usu�rio caso encontre o CPF
		system("pause");// Pausando o sistema
	}
	
	remove(cpf);// Removendo usu�rio do sistema
}


	
int main()
	{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls");// Respons�vel por limpar a tela

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: ");//fim do menu
				
		scanf("%d", & opcao); //armazenando a escolha do usuário
		
		system("cls");// Respons�vel por limpar a tela
	
		switch(opcao) //inicio da sele��o
		{
			case 1:// Selecionando a op��o 1
			registro(); // Chamada de fun��es
			break;// Finalizando a fun��o
			
			case 2:// Selecionando a op��o 2
			consulta();// Chamada de fun��es
			break;// Finalizando a fun��o
		
			case 3:// Selecionando a op��o 3
			deletar();// Chamada de fun��es
			break;// Finalizando a fun��o
		
			default:// Fun��o para informar o usu�rio que a op��o n�o est� dispon�vel no sistema
			printf("Essa op��o n�o est� disponivel!\n");// Mensagem que aparece ao usu�rio caso o sistema n�o reconhe�a a op��o escolhida
			system("pause");// Pausando o sistema
			break;// Finalizando a fun��o
		} //fim da sele��o
			
	}	
}
