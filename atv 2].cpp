#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TFP 10
#define TFC 30
#define TFV 500

int main(void){

	char op, produto[TFP][30], cliente[TFC][30], auxproduto[30], auxcliente[30];
	int TLV=0, TLC=0, TLP=0, pos, matvendas[TFV][3], estoque[TFP],quantidade, auxestoque;
	float preco[TFP], valorpago[TFV],somaparcial,somatotal,auxpreco;
	do
	{
			system("cls");
			printf("\n### M E N U  VENDAS ###\n");
			printf("[A] Cadastrar Produtos\n");
			printf("[B] Exibir Produtos\n");
			printf("[C] Consultar Produtos\n");
			printf("[D] Excluir Produtos\n");
			printf("[E] Alterar Estoque de Produtos\n");
			printf("[F] Ordenar Produtos pela Qtde em Estoque (Decrescente)\n");
			printf("[G] Cadastrar Clientes\n");
			printf("[H] Exibir Clientes\n");
			printf("[I] Ordenar Clientes (Crescente)\n");
			printf("[J] Realizar Vendas\n");
			printf("[K] Exibir Vendas\n");
			printf("[ESC] Finalizar\n");
			printf("\n\nOpcao desejada: ");
			op = toupper(getch());
				
		switch(op)
		{
			case'A': 
			///Busca para validar a existemcia do produto
			system("cls");
			printf("[A]-Cadastrar produtos\n");
			printf("Descricao  do produto [%d]: \n", TLP);
			fflush(stdin);
			gets(auxproduto);
			/// Quatros formas de usar
			///	while(TLP < TFP && strlen(auxproduto) > 0)
			/// while(TLP < TFP && auxproduto[0] != '\0')
			/// while(TLP < TFP && strcmp(auxproduto, "\0")!=0)
			
			
			while(TLP < TFP && strcmp(auxproduto, "")!=0) {
				///Busca exaustiva para verificar se já existe o produto dentro da matriz
				pos=0;
				while(pos < TLP && strcmp(auxproduto, produto[pos])!=0)
					pos++;
					
				if(pos==TLP){
					
				
					if(TLP==TFP)
					{
						printf("\nVetor de produtos esta cheio!\n");
						
					}else
					{	
						strcpy(produto[TLP],auxproduto);
						printf("Preco [%d]:\n", TLP);
						scanf("%f", &preco[TLP]);
						printf("Quantidade de estoque [%d]:\n",TLP);
						scanf("%d", &estoque[TLP]);
						TLP++;
						///Caso haja mais espaço na matriz, ele vai permitir colocar mais produtos
						if(TLP < TFP){
							
							system("cls");
							printf("\nDescricao  do produto [%d]: \n", TLP);
							fflush(stdin);
							gets(auxproduto);
						}else
							{
								printf("\nVetor de produtos esta cheio!\n");
								getch();
							}
					}	
				}else
				{
					///Caso ixita um produto com o mesmo nome na matriz.
					printf("\nProduto ja cadastrado. Cadastre outro produto!!!\n");
					printf("\nDescricao  do produto [%d]: \n", TLP);
					fflush(stdin);
					gets(auxproduto);
				}	
			}
				break;
			case'B':
				///Relatório dos produtos cadastrados.
				system("cls");
				printf("[B]-exibir Produtos\n");
				printf("\nRelatorio de produtos:\n");
				if(TLP==0)
					printf("\n Nao ha produtos!\n");
				else
				{
					for(int i=0; i < TLP; i++)
					{
						printf("\n\nproduto[%d]: \n", i);
						printf("Descricao: %s\n",produto[i]);
						printf("Preco: R%.2f\n", preco[i]);
						printf("Estoque: %d\n",estoque[i]);
					}
				}
				getch();
				break;
				
			case'C':
				system("cls");
				printf("[C] Consultar Produtos\n");
				if(TLP==0){
					printf("\n Nao ha produtos!\n");
				}else
				{
					printf("Qual produto deseja consultar ?\n");
					fflush(stdin);
					gets(auxproduto);
					pos=0;
					while(pos < TLP && strcmp(auxproduto, produto[pos])!=0)
						pos++;
					if(pos < TLP){
						printf("\n\nproduto[%d]: \n");
						printf("Descricao: %s\n",produto[pos]);
						printf("Preco: R%.2f\n", preco[pos]);
						printf("Estoque: %d\n",estoque[pos]);
					}else
					{
						printf("produto não encontardo!!/n");
					}
					
				}
				getch();
				
				break;	
			case'D': 
					///Excluir produtos na matriz 
					if(TLP==0){
						printf("Nao tem produto no vetor!!!");
					}else
					{
						
						system("cls");
						printf("[D]excluir Produtos\n");
						printf("Digite o nome do produto que deseja excluir\n");
						fflush(stdin);
						gets(auxproduto);
						if(TLP > 0 && strcmp(auxproduto, "")!=0)
						{
							///Busca exaustica pela possição do produto na matriz. 
							pos = 0;
							while(pos < TLP && strcmp(auxproduto,produto[pos])!=0)
								pos++;
							///Caso o produto exista na matriz ele vai fazer a exclusao.
									
							if(pos < TLP){
								printf("\n### DEtalhes do produto ####\n");
								printf("\n\nproduto[%d]: \n",pos);
								printf("Descricao: %s\n",produto[pos]);
								printf("Preco: R%.2f\n", preco[pos]);
								printf("Estoque: %d\n",estoque[pos]);
								
								printf("\n Deseja realmente excluir produto ?\n");
								scanf("%c", &op);
								if(op == 83 || op == 115)
								{
									
									for(; pos < TLP-1; pos++ ){
										strcpy(produto[pos], produto[pos+1]);
										preco[pos]= preco[pos+1];
										estoque[pos]= estoque[pos+1];
										
									}
									printf("produto excluido\n");
									getch();
								}
		
							}else
							{
								///Caso o produto não exista na matriz.
								printf("Não foi possível encontrar o produto\n");
								printf("Digite o nome do produto que deseja excluir\n");
								fflush(stdin);
								gets(auxproduto);
								
							}
							
								
								
						}
						TLP--;
						
					}
					break;
			case'E':
				///Alteração de estoque 
				 system("cls");
				 printf("[E] Alterar Estoque de Produtos\n");
			 	if(TLP==0){
					printf("Nao tem produto no vetor!!!");
				}else
				{
					 printf("Qual é o nome do produto que deseja fazer alteracoes:\n");
					 fflush(stdin);
					 gets(auxproduto);
					 ///Busca exastiva.
					 pos=0;
					 while(pos < TLP && strcmp(auxproduto, produto[pos])!=0)
					 	pos++;
					///Caso ache o produto na matriz.
				 	 if(pos < TLP){
						printf("Quantidade no estoque ?\n");
						scanf("%d", &estoque[pos]);
						
					}else
					///Caso não ache o produto na matriz.
						printf("produto não encontrado!!!\n");
				}
				getch();
				break;	
			case'F':
				///Ordenar produtos já inseridos na matriz.
				system("cls");
					if(TLP==0){
						printf("Nao tem produto no vetor!!!");
					}else
					{
						printf("[F] Ordenar Produtos pela Qtde em Estoque (Decrescente)\n");
						for(int i =0; i < TLP-1; i++)
							for(int j=i+1; j < TLP; j++)
								if( estoque[i] < estoque[j]){
									///remanejar produto
									strcpy(auxproduto, produto[i]);
									strcpy(produto[i], produto[j]);
									strcpy(produto[j], auxproduto);
									///Remaneja estoque
									auxestoque = estoque[i];
									estoque[i]= estoque[j];
									estoque[j]= auxestoque;
									///Remanejar preco
									auxpreco= preco[i];
									preco[i]= preco[j];	
									preco[j]= auxpreco;	
								}
						printf("Ordenacao completa\n");	
						
					}
			
				getch();	
				break;
			case'G':
				////Cadastrar clientes 
				system("cls");
				printf("[C]-Cadastrar Clientes\n");
				printf("Nome do cliente [%d] \n", TLC);
				fflush(stdin);
				gets(auxcliente);
				while(TLC < TFC && strcmp(auxcliente, "")!=0) {
					///Busca exaustiva,  caso já exista uma pessoa com o mesmo nome na matriz.
					pos=0;
					while(pos < TLC && strcmp(auxcliente, cliente[pos])!=0)
						pos++;		
					if(pos==TLC)
					{
						strcpy(cliente[TLC],auxcliente);
						TLC++;	
						if(TLC < TFC)
						{
							system("cls");
							printf("Nome do cliente [%d]\n",TLC);
							fflush(stdin);
							gets(auxcliente);				
						}else
						{
							printf("cadastro cheio!!!\n");
						}		
					}else
					{
						///Caso já exita uma  pessoa com o mesmo nome na matriz.
						system("cls");
						printf("Nome ja esta na lista de cadstrado!!!\n");
						printf("Nome do cliente [%d]\n",TLC);
						fflush(stdin);
						gets(auxcliente);
					}
				}	
				getch();
				break;
			case'H':
				///Exibir clinetes já cadastrados. 
				system("cls");
				printf("[D]-Exibir clientes\n");
					if(TLC==0){
						printf("Nao tem Clientes registrados!!!");
					}else
					{		
						if(TLC==0)
								printf("\n Nao ha clientes cadastrados!\n");
						else
							for(int i=0; i < TLC; i++)
							{
								printf("\n\nCliente[%d]: \n", i);
								printf("%s\n",cliente[i]);
							}
					}
			
					getch();
				break;
			case'I':
				///Ordenarar clientes em ordem alfabetica 
				system("cls");
				printf("[I] Ordenar Clientes (Crescente)\n");
						
				if(TLC==0)
						printf("\n Nao ha clientes cadastrados!\n");
					else{	
						for(int i=0; i < TLC-1; i++)
							for(int j=i+1; j < TLC; j++ )
								if(strcmp(cliente[i], cliente[j])>0)
								{
									strcpy(auxcliente, cliente[i]);
									strcpy(cliente[i], cliente[j]);
									strcpy(cliente[j], auxcliente);
								}
						printf("Ordenacao completa\n");
					}
				
				getch();
				break;
			case'J':
				///Venda de produtos 
				system("cls");
				printf("[E]-Realizar vendas\n");		
				if(TLC==0)
					printf("\n Nao ha clientes cadastrados!\n");
				else
					{
											
						printf("Nome do cliente:\n");
						fflush(stdin);
						gets(auxcliente);
						while(TLV < TFV && strcmp(auxcliente, "")!=0) {
							
							pos=0;
							while(pos < TLC && strcmp(auxcliente, cliente[pos])!=0)
								pos++;
							if(pos < TLC){
									
								matvendas[TLV][0]= pos ; 
								printf("Qual produto desejado?\n");
								fflush(stdin);
								gets(auxproduto);
								pos=0;
								while(pos < TLP && strcmp(auxproduto, produto[pos])!=0)
									pos++;
								if(pos < TLP)
								{
									matvendas[TLV][1] = pos;
									printf("Qual é a quantidade desejada do produto [%s]?\n",produto[pos]);
									scanf("%d", &quantidade);
									if(quantidade <= estoque[pos])
									{
										matvendas[TLV][3]= quantidade;
										valorpago[TlV]= preco[pos]* quantidade;
										estoque[pos]-= quantidade;
										printf("compra afetuada com sucesso!!!!\n");
										printf("Quantidade do produto no estoque [%d]\n", estoque[pos]);
										TLV++;
										if(TLV < TLC){			
											printf("Nome do cliente:\n");
											fflush(stdin);
											gets(auxcliente);
										}
									}else
									{
										printf("Pedido ilimitado!!!! Estoque do produto %s é: [%d]\n",produto[pos],estoque[pos]);
									}
								}else
								{
									printf("Produto não encontrado!!\n");
								}
							}else
							{
								printf("Cliente não encontrado\n");
								printf("Nome do cliente:\n");
								fflush(stdin);
								gets(auxcliente);
							}
								
								
						}
					}
				getch();
				break;
			case'K':
				system("cls");
				printf("[F]-Exibir  Vendas\n");
					printf("\nRelatorio de Vendas:\n");
				if(TLV==0)
					printf("\n Nao ha Vendas!\n");
				else
					for(int i=0; i < TLV; i++){
					
						printf("Venda %d:\n", i + 1);
                        printf("Cliente: %s \n", cliente[matvendas[i][0]]);
                        printf("Produto: %s (Posicao: %d)\n", produto[matvendas[i][1]], matvendas[i][1]);
                        printf("Preco: R$%.2f\n", preco[matvendas[i][1]]);
                        printf("Quantidade: %d\n", matvendas[i][3]);
                        printf("Total: R$%.2f\n", valorpago[i]);
                        printf("\n");
                        
					}
					getch();
							
		}
		
		
	}while(op != 27);
		
return 0;

}

