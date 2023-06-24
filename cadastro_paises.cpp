/* Grupo: Estevao Augusto da Foseca Santos 
* Felipe Geraldo de Oliveira
* Tema: Sistema de Cadastro de Países
*/ 

#include <iostream>
#include <fstream>
 
using namespace std;
 
struct dados{
	int populacao;
	int extensao_territorial;
	float pib;
	float pib_per_capita;
	string cidade_populosa;
};
 
struct paises{
	int id;
	string nome;
	string continente;
	dados informacoes;
};

paises* aumenta(paises* pais, int &num)//aumenta o tamanho do vetor
{
	paises* novo = new paises[num+1];
	for(int i = 0; i < num; i++)
	{
		novo[i] = pais[i];
	}
	num+=1;
	delete []pais;
	return novo;
}
 
paises* inserir(int& num, paises* pais){
    paises inserido;
    int sinalizador = 0;
	int contador = 0;
	int execucao = 1;
	
	while(execucao == 1)
	{
		cout << "===============Subprograma Inserir==============="<< endl;
		
		for(int j = 0; j < num; j++) //verifica se existem linhas removidas
		{
			if(pais[j].id == -1)
			{
				contador++;
			}
		}

		cout << "Digite um numero de identificacao (ID) que seja positivo: ";
		cin >> inserido.id;
		cout << endl;
		while (inserido.id <= 0)
		{
			cout << "Numero invalido. Por favor, digite um numero de identificacao (ID) valido: ";
			cin >> inserido.id;
			cout << endl;
		}
		for(int j = 0; j < num; j++)
		{
			if(inserido.id==pais[j].id)//verifica se o id digitado ja esta sendo utilizado
			{
				sinalizador = 1;
			}

			if (sinalizador == 1)
			{
				cout << "Esse numero de identificacao (ID) ja esta em uso, por favor digite outro: ";
				cin >> inserido.id;
				j = 0;
				sinalizador = 0;
				cout << endl;
			}
		}
		if(sinalizador == 0)
		{
			cout << "Digite um nome de pais: ";
			cin.ignore();
			getline(cin, inserido.nome);
			cout << endl;
			cout << "Digite o continente ao qual esse pais pertence: ";
			getline(cin,inserido.continente);
			cout << endl;
			cout << "Digite a cidade mais populosa desse pais: ";
			getline(cin,inserido.informacoes.cidade_populosa);
			cout << endl;
			cout << "Digite o tamanho da populacao desse pais: ";
			cin >> inserido.informacoes.populacao;
			cout << endl;
			cout << "Digite a extensao territorial desse pais em quilometros quadrados: ";
			cin >> inserido.informacoes.extensao_territorial;
			cout << endl;
			cout << "Digite o PIB do pais em bilhoes de dolares: ";
			cin >> inserido.informacoes.pib;
			cout << endl;
			cout << "Digite o PIB per capita do pais em dolares: ";
			cin >> inserido.informacoes.pib_per_capita;
			cout << endl;
		}

		if(contador == 0) //caso não existam linhas removidas disponiveis
		{
			cout <<"O que deseja fazer?" << endl;
			cout <<"1) Inserir no final" << endl;
			cout<< "0) Voltar" << endl;
			cout << "=================================================" << endl;
			cout << "Sua resposta: ";
		}
		else //caso existam linhas removidas disponiveis
		{
		cout << "O que deseja fazer?" << endl;
		cout << "1) Inserir no final" << endl;
		cout << "2) Inserir em linhas disponiveis" << endl;
		cout << "0) Voltar" << endl;
		cout << "=================================================" << endl;
		cout << "Sua resposta: ";
		}
		int decisao;
		cin >> decisao;
	
		switch(decisao)
		{
			case 1:
			{
				pais = aumenta(pais, num);
				pais[num-1].id = inserido.id;
				pais[num-1].nome = inserido.nome;
				pais[num-1].continente = inserido.continente;
				pais[num-1].informacoes.cidade_populosa = inserido.informacoes.cidade_populosa;
				pais[num-1].informacoes.populacao = inserido.informacoes.populacao;
				pais[num-1].informacoes.extensao_territorial = inserido.informacoes.extensao_territorial;
				pais[num-1].informacoes.pib = inserido.informacoes.pib;
				pais[num-1].informacoes.pib_per_capita = inserido.informacoes.pib_per_capita;
				
				cout << endl;
				cout << "!==========================!" << endl;
				cout << "Dados inseridos com sucesso!" << endl;
				cout << "!==========================!" << endl << endl;
				
				break;
			}
			
			case 2: 
			{
				if(contador == 0) //caso não existam linhas removidas disponiveis e o usuario tenha digitado o numero 2, isso ocorre
				cout << "Opcao invalida" << endl << endl;
				else
				{
					cout << endl;
					cout << "=============Linhas disponiveis=============" << endl;
					for (int i = 0; i < num; i++)
					{
						if(pais[i].id == -1)
						{
							cout << i+1 << " ";
						}
					}
					cout << endl << endl;
					cout << "Escolha a linha que deseja inserir: ";
					cin >> decisao;
					if(pais[decisao-1].id != -1)
					{
						cout<< "Opcao invalida" << endl << endl;
					}
					else
					{
						pais[decisao-1].id = inserido.id;
						pais[decisao-1].nome = inserido.nome;
						pais[decisao-1].continente = inserido.continente;
						pais[decisao-1].informacoes.cidade_populosa = inserido.informacoes.cidade_populosa;	
						pais[decisao-1].informacoes.populacao = inserido.informacoes.populacao;
						pais[decisao-1].informacoes.extensao_territorial = inserido.informacoes.extensao_territorial;
						pais[decisao-1].informacoes.pib = inserido.informacoes.pib;
						pais[decisao-1].informacoes.pib_per_capita = inserido.informacoes.pib_per_capita;
						
						cout << endl;
						cout << "!==========================!" << endl;
						cout << "Dados inseridos com sucesso!" << endl;
						cout << "!==========================!" << endl << endl;
					}
				}
				break;
			}
			case 0:
			{
				execucao = 0;
				break;
			}
			
			default:
			{
				cout << "Opcao invalida" << endl << endl;
				break;
			}
		}
		
		if(execucao == 1)//nso entra nesse if caso o usuario digite 0 para voltar no menu inserir, pois 0 é atribuído à variavel "execucao" no case 0
		{
			cout << "=============================" << endl;
			cout << "Deseja continuar?" << endl;
			cout << "1) Sim" << endl;
			cout << "Outro valor) Nao" << endl;
			cout << "=============================" << endl << endl;
			cout << "Sua resposta: ";
			cin >> execucao; //o subprograma inserir começa novamente se o usuario digitar 1, pois esta dentro de um while que funciona caso execucao seja igual a 1
			cout << endl << endl;
		}			
	}
	return pais;
}			
			
void listar(int& num, paises* pais, int& opcao){
	bool listado; //checa se os dados foram listados ou o usuario quer parar de listar
	//O procedimento nao imprimira dados apagados, ou seja, que tenham -1 como valor
	
	do{
		cout << endl;
		listado = false;
		opcao = 0;
		
		cout << "===============Subprograma Listar==============="<< endl;
		cout << "Selecione o modo que deseja listar:" << endl << endl;
		cout << "1) Listar tudo" << endl;
		cout << "2) Listar por id" << endl;
		cout << "3) Listar por continente" << endl;
		cout << "4) Listar por nome" << endl;
		cout << "5) Listar por indice do pais" << endl;
		cout << "0) Voltar" << endl;
		cout << "========================================="<< endl;
		
		cout << "Sua resposta: ";
		cin >> opcao;
		
		switch(opcao){
			case 0: // Voltar a funcao principal atraves da declaracao de um valor bool como verdadeiro
				listado = true;
				break;
			case 1: // Listar todos os dados cadastrados
				for(int i = 0; i < num; i++){
					if(pais[i].id != -1){
						cout << "-----------------------------------" << endl;
						cout << i + 1 << "o pais" << endl;
						cout << "-----------------------------------" << endl;
						cout << "Id: " << pais[i].id << endl;
						cout << "Nome: " << pais[i].nome << endl;
						cout << "Continente: " << pais[i].continente << endl;
						cout << "Cidade mais populosa: " << pais[i].informacoes.cidade_populosa << endl;
						cout << "Populacao: " << pais[i].informacoes.populacao << " hab" << endl;
						cout << "Extensao territorial: " << pais[i].informacoes.extensao_territorial << " km2" << endl;
						cout << "Pib: " << pais[i].informacoes.pib << " bilhoes de dolares" << endl;
						cout << "Pib per capita: " << pais[i].informacoes.pib_per_capita << " dolares" << endl;
						cout << "-----------------------------------" << endl;
						}
					}
   				 listado = true;
   				 break;
   			case 2: //Listar um pais baseado no seu ID
   			{
				int id_procurado;
				cout << "Digite o id de um pais: ";
				cin >> id_procurado;
				
				for(int i = 0; i < num; i++){ 
					if(pais[i].id == id_procurado and pais[i].id != -1){
						listado = true;
						cout << "-----------------------------------" << endl;
						cout << i + 1 << "o pais" << endl;
						cout << "-----------------------------------" << endl;
						cout << "Id: " << pais[i].id << endl;
						cout << "Nome: " << pais[i].nome << endl;
						cout << "Continente: " << pais[i].continente << endl;
						cout << "Cidade mais populosa: " << pais[i].informacoes.cidade_populosa << endl;
						cout << "Populacao: " << pais[i].informacoes.populacao << " hab" << endl;
						cout << "Extensao territorial: " << pais[i].informacoes.extensao_territorial << " km2" << endl;
						cout << "Pib: " << pais[i].informacoes.pib << " bilhoes de dolares" <<endl;
						cout << "Pib per capita: " << pais[i].informacoes.pib_per_capita << " dolares" << endl;
						cout << "-----------------------------------" << endl;
						}
					}
					if(listado == false){
						cout << "!===================Falha====================!" << endl;
						cout << "        ID nao encontrado no sistema" << endl;
						cout << "!============================================!" << endl;
					}
				break;
			}
			case 3: //Listar paises baseado no  continente digitado
			{
				string continenteProcurado;
				cout << "Digite o nome do continente de maneira exata: ";
				cin.ignore();
				getline(cin, continenteProcurado);
				
				for(int i = 0; i < num; i++){
					if(pais[i].continente == continenteProcurado and pais[i].id != -1){
						listado = true;
						cout << "-----------------------------------" << endl;
						cout << i + 1 << "o pais" << endl;
						cout << "-----------------------------------" << endl;
						cout << "Id: " << pais[i].id << endl;
						cout << "Nome: " << pais[i].nome << endl;
						cout << "Continente: " << pais[i].continente << endl;
						cout << "Cidade mais populosa: " << pais[i].informacoes.cidade_populosa << endl;
						cout << "Populacao: " << pais[i].informacoes.populacao << " hab" << endl;
						cout << "Extensao territorial: " << pais[i].informacoes.extensao_territorial << " km2" << endl;
						cout << "Pib: " << pais[i].informacoes.pib << " bilhoes de dolares" << endl;
						cout << "Pib per capita: " << pais[i].informacoes.pib_per_capita << " dolares" << endl;
						cout << "-----------------------------------" << endl;
						}
					}
					if(listado == false){ //caso nenhum paises seja listado de acordo com o nome do continente 
						cout << "!===================Falha====================!" << endl;
						cout << " Nome de continente nao encontrado no sistema " << endl;
						cout << "!============================================!" << endl;
					}
				break;
			}
			case 4: //listar pais baseado no nome procurado
			{
				string nomeProcurado;
				cout << "Digite o nome do pais de maneira exata: ";
				cin.ignore();
				getline(cin, nomeProcurado);
				for(int i = 0; i < num; i++){
					if(pais[i].nome == nomeProcurado and pais[i].id != -1){ 
						listado = true;
						cout << "-----------------------------------" << endl;
						cout << i + 1 << "o pais" << endl;
						cout << "-----------------------------------" << endl;
						cout << "Id: " << pais[i].id << endl;
						cout << "Nome: " << pais[i].nome << endl;
						cout << "Continente: " << pais[i].continente << endl;
						cout << "Cidade mais populosa: " << pais[i].informacoes.cidade_populosa << endl;
						cout << "Populacao: " << pais[i].informacoes.populacao << " hab" << endl;
						cout << "Extensao territorial: " << pais[i].informacoes.extensao_territorial << " km2" << endl;
						cout << "Pib: " << pais[i].informacoes.pib << " bilhoes de dolares" << endl;
						cout << "Pib per capita: " << pais[i].informacoes.pib_per_capita << " dolares" << endl;
						cout << "-----------------------------------" << endl << endl;
						}
					}
					if(listado == false){ //caso nao achem pais com o nome procurado
						cout << endl;
						cout << "!===================Falha====================!" << endl;
						cout << "     Nome do pais nao encontrado no sistema " << endl;
						cout << "!============================================!" << endl;
					}
				break;
			}
			case 5:// listar baseado no indice do vetor
			{
				cout << "Digite um indice dentro do intervalo de 0 a " << num-1<< endl;
				int indiceInicial, indiceFinal;
				cout << "Digite o indice inicial: ";
				cin >> indiceInicial;
				while(indiceInicial < 0 or indiceInicial > num-1){
					cout << "Indice invalido!" << endl;
					cout << "Digite o indice inicial: ";
					cin >> indiceInicial;
				}
				cout << "Digite o indice final: ";
				cin >> indiceFinal;
				while(indiceFinal < indiceInicial or indiceFinal > num-1){
					cout << "Indice invalido!" << endl;
					cout << "Digite o indice final: ";
					cin >> indiceFinal;
				}
				for(int i = indiceInicial; i <= indiceFinal; i++){ 
					if(pais[i].id != -1){
							listado = true;
							cout << "-----------------------------------" << endl;
							cout << i + 1<< "o pais" << endl;
							cout << "-----------------------------------" << endl;
							cout << "Id: " << pais[i].id << endl;
							cout << "Nome: " << pais[i].nome << endl;
							cout << "Continente: " << pais[i].continente << endl;
							cout << "Cidade mais populosa: " << pais[i].informacoes.cidade_populosa << endl;
							cout << "Populacao: " << pais[i].informacoes.populacao << " hab" << endl;
							cout << "Extensao territorial: " << pais[i].informacoes.extensao_territorial << " km2" << endl;
							cout << "Pib: " << pais[i].informacoes.pib << " bilhoes de dolares" << endl;
							cout << "Pib per capita: " << pais[i].informacoes.pib_per_capita << " dolares" << endl;
							cout << "-----------------------------------" << endl << endl;
						} else {
							cout << "-----------------------------------" << endl << endl;
							cout << "Este pais foi removido do sistema" << endl;
							cout << "-----------------------------------" << endl << endl;
						}
					}
				listado = true;
				break;
			}
			default: //Caso o usuario digite uma opcao inexistente
			{
				cout << "Opcao inexistente ou invalida!";
			}
		}
	}while(listado != true);
}

void editar(int& num, paises* pais, int& opcao){
    int indice_pais = -1; //Indice do pais utilizado
    bool para_tudo = false; //<-- Serve para quando o usuario querer sair da edicao
    
    // Editar faz uso do indice do vetor de registro para identificar o pais
    cout << endl;
	cout << "====================================================" << endl;
	cout << "Selecione um pais dos indices  0 a " << num-1 << endl;
	cout << "Qual deles voce deseja editar?" << endl << endl;
	
	while(indice_pais < 0 or indice_pais > num-1){ //indice deve existir no intervalo dito
		cout << "Sua resposta: ";
		cin >> indice_pais;
		if(indice_pais < 0 or indice_pais > num-1){
			cout << "Indice invalido!" << endl;
		}
	}
    do{
		cout << "================Subprograma Editar================" << endl;
		cout << "Selecione a opcao que desejar:" << endl << endl;
		cout << "1) Editar tudo" << endl;
		cout << "2) Editar ID" << endl;
		cout << "3) Editar Nome" << endl;
		cout << "4) Editar Continente" << endl;
		cout << "5) Editar Populacao" << endl;
		cout << "6) Editar Cidade mais populosa" << endl;
		cout << "7) Editar Extensao territorial" << endl;
		cout << "8) Editar Pib" << endl;
		cout << "9) Editar Pib per capita" << endl;
		cout << "0) Voltar" << endl;
		cout << "===================================================" << endl;
		cout << "Sua resposta: ";
		cin >> opcao;
		switch(opcao){
			case 0: //Voltar para a funcao principal ao declarar um valor bool como verdadeiro
				para_tudo = true;
				break;
			case 1: //Editar Tudo
			{
				int idChecador;// servira para checar copias de ID nos vetores de registro
				int contador = -1; //Contara se outros paises possuem mesmo ID
				cout << "=======================================" << endl;
				cout << "Pais numero " << indice_pais << endl;
				while(contador < num){//Checa se o ID aparece em outras structs, senao o usuario eh obrigado a mandar valores até que a condicao do WHILE termine
					contador++;
					if(contador == 0){
						cout << "ID: "; //ID eh a unica variavel que deve ser distinta
						cin >> idChecador; //Inseri id em outra variavel
					}
					if(pais[contador].id == idChecador or idChecador < 0){
						cout << "Este ID ja existe, ou eh negativo!" << endl;
						contador = -1;
					}
				}
				pais[indice_pais].id = idChecador;
				cout << "Nome: ";
				cin.ignore();
				getline(cin, pais[indice_pais].nome);	
				cout << "Continente: ";
				cin >> pais[indice_pais].continente;	
				cout << "Cidade mais populosa: ";
				cin.ignore();
				getline(cin, pais[indice_pais].informacoes.cidade_populosa);	
				cout << "Populacao: ";
				cin >> pais[indice_pais].informacoes.populacao;	
				cout << "Extensao territorial: ";
				cin >> pais[indice_pais].informacoes.extensao_territorial;		
				cout << "Pib: ";
				cin >> pais[indice_pais].informacoes.pib;			
				cout << "Pib per capita: ";
				cin >> pais[indice_pais].informacoes.pib_per_capita;
				cout << "!==================================!" << endl;
				cout << "  O pais foi editado com sucesso" << endl;
				cout << "!==================================!" << endl;
				break;
			}
			case 2: //Editar ID
			{
				cout << "=======================================" << endl;
				int idChecador;// servira para checar copias de ID nos vetores de registro
				int contador = -1; //Contara se outros paises possuem mesmo ID
				while(contador < num){//Checa se o ID aparece em outras structs, senao o usuario eh obrigado a mandar valores até que a condicao do WHILE termine
					contador++;
					if(contador == 0){
						cout << "ID: "; //ID eh a unica variavel que deve ser distinta
						cin >> idChecador; //Inseri id em outra variavel
					}
					if(pais[contador].id == idChecador or idChecador < 0){
						cout << "Este ID ja existe, ou eh negativo!" << endl;
						contador = -1;
					}
				}
				pais[indice_pais].id = idChecador;
				cout << "O ID foi editado com sucesso!" << endl;
				break;
			}
			case 3: //Editar Nome
			{
				cout << "=======================================" << endl;
				cout << "Nome: ";
				cin.ignore();
				getline(cin, pais[indice_pais].nome);
				cout << "O Nome do pais foi editado com sucesso!";
				break;
			}
			case 4: //Editar Continente
			{
				cout << "=======================================" << endl;
				cout << "Continente: ";
				cin >> pais[indice_pais].continente;
				cout << "O Continente foi editado com sucesso!" << endl;
				break;
			}
			case 5: //Editar Cidade mais populosa
			{
				cout << "=======================================" << endl;
				cout << "Cidade mais populosa: ";
				cin.ignore();
				getline(cin, pais[indice_pais].informacoes.cidade_populosa);
				cout << "A Cidade mais populosa foi editada com sucesso!" << endl;
				break;
			}
			case 6: //Editar Populacao
			{
				cout << "=======================================" << endl;
				cout << "Populacao: ";
				cin >> pais[indice_pais].informacoes.populacao;
				cout << "A Populacao foi editada com sucesso!" << endl;
				break;
			}
			case 7: //Editar Extensao territorial
			{
				cout << "=======================================" << endl;
				cout << "Extensao territorial: ";
				cin >> pais[indice_pais].informacoes.extensao_territorial;
				cout << "A Extensao Territorial foi editada com sucesso!" << endl;
				break;
			}
			case 8: //Editar Pib
			{
				cout << "=======================================" << endl;
				cout << "Pib: ";
				cin >> pais[indice_pais].informacoes.pib;
				cout << "O Pib foi editado com sucesso!" << endl;
				break;
			}
			case 9: //Editar Pib per capita
			{
				cout << "=======================================" << endl;
				cout << "Pib per capita: ";
				cin >> pais[indice_pais].informacoes.pib_per_capita;
				cout << "O Pib per capita foi editado com sucesso!" << endl;
				break;
			}
			default: //Caso o usuario digite um valor fora da mensagem imprimida
			{
				cout << "!===================Falha====================!" << endl;
				cout << "              Opcao inexistente" << endl;
				cout << "!============================================!" << endl;
			}
		}
    }while(para_tudo != true);
}

void remover(int& num, paises* pais){
	int escolha;
	int contador = 0;
	int verificador = 0;
	
	cout << "===============Subprograma Remover==============="<< endl;
	for (int i = 0; i < num; i++)//verifica quantas linhas podem ser removidas
	{
		if(pais[i].id != -1)
		contador++;
	}
	cout << "Existem " << contador << " linhas passiveis de remocao" << endl << endl;
	cout << "Digite quantas linhas deseja remover: ";
	cin >> escolha;
	cout << endl;
	
	if(escolha <= 0 or escolha > contador)
	{
		cout << "Nao e possivel remover esse numero de linhas" << endl << endl;
		
	}
	else
	{
		cout << "===============ID disponiveis===============" << endl;
		for(int i = 0; i < num; i++)//apresenta quais linhas podem ser removidas
		{
			if(pais[i].id != -1)
			cout << pais[i].id << " ";
		}
		cout << endl;
		int ids_remocao[escolha];
		
		cout << "Digite os ids (numeros de identificacao) que voce quer remover: ";
		for(int i = 0; i < escolha; i++)
		{
			cin >> ids_remocao[i];
		}
		for(int i = 0; i < num; i++) //verifica se todos os ids digitados estão disponiveis para remoção
		{
			for(int j = 0; j < escolha; j++)
			{
				if(pais[i].id == ids_remocao[j])
				{
					verificador++;
				}
			}
		}
		if(verificador == escolha)//remocao so ocorre se todos os ids digitados estiverem disponiveis
		{		
			for(int i = 0; i < num; i++)
			{
				for(int j = 0; j < escolha; j++)
				{
					if(pais[i].id == ids_remocao[j])
					{
						pais[i].id = -1;
						pais[i].nome = "-1";
						pais[i].continente = "-1";
						pais[i].informacoes.cidade_populosa = "-1";
						pais[i].informacoes.populacao = -1;
						pais[i].informacoes.extensao_territorial = -1;
						pais[i].informacoes.populacao = -1;
						pais[i].informacoes.pib = -1;
						pais[i].informacoes.pib_per_capita = -1;
					}
				}
			}
			cout << endl;
			cout << "!======================================!" << endl;	
			cout << "Os dados foram removidos com sucesso!" << endl;
			cout <<	"!======================================!" << endl << endl;	
		}
		else //caso verificador seja diferente de escolha, significa que ao menos algum id digitado nao estava disponivel e, portanto, exibirá erro
		cout << endl << "ERRO! Ao menos algum id digitado nao estava disponivel para remocao" << endl << endl;
	}
	
}
int main(){
	bool saida = false;
	int num, opcao;
	string primeira_linha_lixo;
	char lixo; //armazena virgulas para a leitura de arquivos funcionar devidamente
	ifstream ler_dados("dados_paises.csv");
	getline(ler_dados, primeira_linha_lixo);
	ler_dados >> num; //le a quantidade de paises  inseridos
	
	paises* pais = new paises [num];
	
	for(int i = 0; i < num; i++){ //Leitor de dados no arquivo
		ler_dados >> pais[i].id;
		ler_dados >> lixo;
		getline(ler_dados, pais[i].nome,',');
		getline(ler_dados, pais[i].continente,',');
		getline(ler_dados, pais[i].informacoes.cidade_populosa,',');
		ler_dados >> pais[i].informacoes.populacao;
		ler_dados >> lixo;
		ler_dados >> pais[i].informacoes.extensao_territorial;
		ler_dados >> lixo;
		ler_dados >> pais[i].informacoes.pib;
		ler_dados >> lixo;
		ler_dados >> pais[i].informacoes.pib_per_capita;
	}
	
	do{
		cout << "------------Sistema de Cadastro de Paises------------" << endl;
		cout << "1) Inserir" << endl;
		cout << "2) Listar" << endl;
		cout << "3) Editar" << endl;
		cout << "4) Remover" << endl;
		cout << "0) Sair" << endl;
		cout << "----------------------------------------------------";
		cout << endl;
		cout << "Sua resposta: ";
		cin >> opcao;
		
		switch(opcao){
			case 0:
				saida = true;
				break;
			case 1:
				pais = inserir(num, pais);
				break;
			case 2:
				listar(num, pais, opcao);
				break;
			case 3:
				editar(num, pais, opcao);
				break;
			case 4:
				remover(num, pais);
				break;
			default:
				cout << "Opcao inexistente ou invalida" << endl; 
			}
	}while(saida != true);
	cout << "Programa saindo...";
	
	ler_dados.close();
	return 0;
}

