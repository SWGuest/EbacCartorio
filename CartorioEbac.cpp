#include <stdio.h>//biblioteca de comunica��o with user
#include <stdlib.h>//resposanvel por aloca��o de espa�o de memoria
#include <locale.h>// biblioteca de aloca��es de texto por regi�o
#include <string.h>//responsavel por cuidar dos strings

int registro() //fun. resp. por cadastrar usuarios ao sistema
   //inicio cria��o de variaveis string
{
	char arquivo[50];
	char cpf[50];
	char nome[50];
	char sobrenome[50];
	char cargo[50];
	// fim da criacao
	
	
	printf("digite o cpf a ser cadastrado:\t");
	scanf("%s", cpf);//%s se refere a string
	
	strcpy(arquivo, cpf);//resp. por copiar os valores string
	
	FILE * file;
	file = fopen(arquivo, "w");//cria o arquivo
	fprintf(file,cpf); //salva valor da variavel
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);

	printf("digite o nome a ser cadastrado:\t ");
	scanf("%s", nome);
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	printf("digite o sobrenome cadastrado:\t");
	scanf("%s", sobrenome);
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
		
	printf("digite o cargo cadastrado:\t");
	scanf("%s", cargo);	
	file =fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
}

int consulta()
{
  setlocale (LC_ALL, "Portuguese");
  
  char cpf[50];
  char conteudo[200];
  
  printf("digite o cpf a ser consultado:\t");
  scanf("%s", cpf);
  
  FILE * file;
  file =fopen(cpf, "r");
  
  if(file==NULL)
  {
  	printf("n�o fo possivel abrir o arquivo, n�o localizado");
  }
  while(fgets(conteudo, 200, file)!=NULL)
  {
  	printf("essas s�o as informa��es do usuario:\n ");
  	printf("%s", conteudo);
    printf("\n\n");
  }
  system("pause");
}

int deletar()
{
	char cpf[50];
	
	printf("digite o cpf a ser deletado\n");
	scanf("%s, cpf");
	
	remove(cpf);
	
	FILE * file;
	file=fopen(cpf, "r");
	
	if(file== NULL)
	{
		printf("\tusuario n�o encontrado\n");
		system("pause");
	}
	
}


int main() //fun��o � adicionada parenteses
{
  system("cls");
  
   int opcao=0;//definindo variaveis
   int laco=1;
   for(laco=1;laco=1;)
   {
   
  setlocale (LC_ALL, "Portuguese");//incluindo linguagens

  system("cls");   
   
   printf("\t*Cart�rio da EBAC*\n\n");   //inicio do menu
   printf("escolha a op��o desejada do menu:\n\n");
  //\T � um comando que ajuda a dar espa�o
   printf("\t1-registrar nomes\n");
   printf("\t2-consultar nomes\n");
   printf("\t3-deletar nomes\n\n"); 
   printf("\t4-sair do sistema");
   printf("\top��o:\n\n"); 
  
 
 scanf("%d",&opcao);//armazenando e escolha do usuario
 
system("cls"); 

 switch(opcao)
{
	case 1:
	registro();
	break;
	case 2:
	consulta();
	break;
	case 3:
	deletar();
    break;
    case 4:
    printf("obrigado por utilizar o sistema");
	return 0;
	break;
    	
    	
    
    
    
    default:
    		printf("\top��o indisponivel");
	system("pause");
	break;
}
}
}



