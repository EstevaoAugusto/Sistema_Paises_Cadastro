/* Grupo: Estevao Augusto da Fonseca Santos 
* Felipe Geraldo de Oliveira
* Tema: Sistema de Cadastro de Países
*/ 

#include <iostream>
#include <fstream>
#include <cstring>
 
using namespace std;
 
struct dados{
	int populacao;
	int extensao_territorial;
	float pib;
	float pib_per_capita;
	char cidade_populosa[50];
};
 
struct paises{
	int id;
	char nome[50];
	char continente[10];
	dados informacoes;
};

paises* redimensiona(paises* pais, int& tamanho, int contador_excluidos)
{
	/* subprograma retorna vetor sem os registros removidos logicamente, ou seja, 
	 * os registros removidos logicamente são apagados definitivamente */
	 
	paises* novo = new paises[tamanho-contador_excluidos];
	int j = 0;
	for(int i = 0; i < tamanho; i++)
	{
		if(pais[i].id != -1)
		{
			novo[j].id = pais[i].id;
			memcpy(novo[j].nome, pais[i].nome, 50);
			memcpy(novo[j].continente, pais[i].continente, 10);
			memcpy(novo[j].informacoes.cidade_populosa, pais[i].informacoes.cidade_populosa, 50);
			novo[j].informacoes.populacao = pais[i].informacoes.populacao;
			novo[j].informacoes.extensao_territorial = pais[i].informacoes.extensao_territorial;
			novo[j].informacoes.pib = pais[i].informacoes.pib;
			novo[j].informacoes.pib_per_capita = pais[i].informacoes.pib_per_capita;
			j++;
		}
	}
	tamanho=tamanho-contador_excluidos;
	delete []pais;
	return novo;
}

void shell_sort(int& num, int opcao, int num_dado) {
	ifstream ler_dados("dados_paises_binario.dat", ios::binary);
	ler_dados.seekg(0, ler_dados.end);
	int tamanho = ler_dados.tellg()/sizeof(paises);
	num = tamanho;
	paises* pais = new paises[tamanho];
	ler_dados.seekg(0, ler_dados.beg);
	ler_dados.read((char*) pais, sizeof(paises)*tamanho);
	ler_dados.close();
	//Obs: A ordenacao foi feita utilizando o exemplo do slide
	/* Opcao = 1, quer dizer que é de Ordenação Crescente
	 * Opcao = 2, quer dizer que é de Ordenação Decrescente
	 * num_dado define quais valores serao usados para a ordenação
	 * Tais valores incluem:
	 * 1 -> ID
	 * 2 -> Nome
	 * 3 -> População
	 * 4 -> Extensao Territorial
	 * 5 -> Pib
	 * 6 -> Pib per Capta
	 * 7 -> Cidade mais populosa
	 * Vale ressaltar que os valores sao definidos pelo programado, ou seja, sao estaticos
	 * Tudo depende da situação que sao utilizados  e definidos*/ 
	
	int gaps[9] = {1, 4, 10, 23, 57, 132, 301, 701, 1750}; // É usado sequência de Ciura
	int pos_gap = 8;
	
	while (gaps[pos_gap] > tamanho) {
		pos_gap--;
	}
	
	paises value;
	int j;
	
	if(opcao == 1){ //Crescente
		switch(num_dado){
			case 1:{ //ID
				while ( pos_gap >= 0 ) {
					while ( pos_gap >= 0 ) {
					int gap = gaps[pos_gap];
					
					for (int i = gap; i < tamanho; i++) {
						value = pais[i];
						j = i;
						while ((j >= gap) and (value.id < pais[j - gap].id)) {
							pais[j] = pais[j - gap];
							j = j - gap;
						}
					pais[j] = value;
					}
					pos_gap--;
					}
				}
				break;
			}
			case 2: { //Nome
				while ( pos_gap >= 0 ) {
					while ( pos_gap >= 0 ) {
					int gap = gaps[pos_gap];
					
					for (int i = gap; i < tamanho; i++) {
						value = pais[i];
						j = i;
						while ((j >= gap) and (strcmp(value.nome, pais[j - gap].nome) <= 0)) {
							pais[j] = pais[j - gap];
							j = j - gap;
						}
					pais[j] = value;
					}
					pos_gap--;
					}
				}
				break;
			}
			case 3: { //Populacao
				while ( pos_gap >= 0 ) {
					while ( pos_gap >= 0 ) {
					int gap = gaps[pos_gap];
					
					for (int i = gap; i < tamanho; i++) {
						value = pais[i];
						j = i;
						while ((j >= gap) and (value.informacoes.populacao < pais[j - gap].informacoes.populacao)) {
							pais[j] = pais[j - gap];
							j = j - gap;
						}
					pais[j] = value;
					}
					pos_gap--;
					}
				}
				break;
			}
			case 4: { //Extensao Territorial
				while ( pos_gap >= 0 ) {
					while ( pos_gap >= 0 ) {
					int gap = gaps[pos_gap];
					
					for (int i = gap; i < tamanho; i++) {
						value = pais[i];
						j = i;
						while ((j >= gap) and (value.informacoes.extensao_territorial < pais[j - gap].informacoes.extensao_territorial)) {
							pais[j] = pais[j - gap];
							j = j - gap;
						}
					pais[j] = value;
					}
					pos_gap--;
					}
				}
				break;
			}
			case 5: { //Pib
				while ( pos_gap >= 0 ) {
					while ( pos_gap >= 0 ) {
					int gap = gaps[pos_gap];
					
					for (int i = gap; i < tamanho; i++) {
						value = pais[i];
						j = i;
						while ((j >= gap) and (value.informacoes.pib < pais[j - gap].informacoes.pib)) {
							pais[j] = pais[j - gap];
							j = j - gap;
						}
					pais[j] = value;
					}
					pos_gap--;
					}
				}
				break;
			}
			case 6: { //Pib per capta
				while ( pos_gap >= 0 ) {
					while ( pos_gap >= 0 ) {
					int gap = gaps[pos_gap];
					
					for (int i = gap; i < tamanho; i++) {
						value = pais[i];
						j = i;
						while ((j >= gap) and (value.informacoes.pib_per_capita < pais[j - gap].informacoes.pib_per_capita)) {
							pais[j] = pais[j - gap];
							j = j - gap;
						}
					pais[j] = value;
					}
					pos_gap--;
					}
				}
				break;
			}
			
			case 7: {//Cidade mais populosa
				while ( pos_gap >= 0 ) {
					while ( pos_gap >= 0 ) {
					int gap = gaps[pos_gap];
					
					for (int i = gap; i < tamanho; i++) {
						value = pais[i];
						j = i;
						while ((j >= gap) and (strcmp(value.informacoes.cidade_populosa, pais[j - gap].informacoes.cidade_populosa)) <= 0) {
							pais[j] = pais[j - gap];
							j = j - gap;
						}
					pais[j] = value;
					}
					pos_gap--;
					}
				}
				break;
			}
		}
	} else if(opcao == 2){ //Decrescente
		switch(num_dado){
			case 1: {//ID
				while ( pos_gap >= 0 ) {
					while ( pos_gap >= 0 ) {
					int gap = gaps[pos_gap];
					
					for (int i = gap; i < tamanho; i++) {
						value = pais[i];
						j = i;
						while ((j >= gap) and (value.id > pais[j - gap].id)) {
							pais[j] = pais[j - gap];
							j = j - gap;
						}
					pais[j] = value;
					}
					pos_gap--;
					}
				}
				break;
			}
			case 2: {//Nome
				while ( pos_gap >= 0 ) {
					while ( pos_gap >= 0 ) {
					int gap = gaps[pos_gap];
					
					for (int i = gap; i < tamanho; i++) {
						value = pais[i];
						j = i;
						
						while ((j >= gap) and (strcmp(value.nome, pais[j - gap].nome) >= 0)) {
							pais[j] = pais[j - gap];
							j = j - gap;
						}
					pais[j] = value;
					}
					pos_gap--;
					}
				}
				break;
			}
			case 3: {// Populacao
				while ( pos_gap >= 0 ) {
					while ( pos_gap >= 0 ) {
					int gap = gaps[pos_gap];
					
					for (int i = gap; i < tamanho; i++) {
						value = pais[i];
						j = i;
						while ((j >= gap) and (value.informacoes.populacao > pais[j - gap].informacoes.populacao)) {
							pais[j] = pais[j - gap];
							j = j - gap;
						}
					pais[j] = value;
					}
					pos_gap--;
					}
				}
				break;
			}
			case 4: { //Extensao territorial
				while ( pos_gap >= 0 ) {
					while ( pos_gap >= 0 ) {
					int gap = gaps[pos_gap];
					
					for (int i = gap; i < tamanho; i++) {
						value = pais[i];
						j = i;
						while ((j >= gap) and (value.informacoes.extensao_territorial > pais[j - gap].informacoes.extensao_territorial)) {
							pais[j] = pais[j - gap];
							j = j - gap;
						}
					pais[j] = value;
					}
					pos_gap--;
					}
				}
				break;
			}
			case 5: {//Pib
				while ( pos_gap >= 0 ) {
					while ( pos_gap >= 0 ) {
					int gap = gaps[pos_gap];
					
					for (int i = gap; i < tamanho; i++) {
						value = pais[i];
						j = i;
						while ((j >= gap) and (value.informacoes.pib > pais[j - gap].informacoes.pib)) {
							pais[j] = pais[j - gap];
							j = j - gap;
						}
					pais[j] = value;
					}
					pos_gap--;
					}
				}
				break;
			}
			case 6: {//Pib per capta
				while ( pos_gap >= 0 ) {
					while ( pos_gap >= 0 ) {
					int gap = gaps[pos_gap];
					
					for (int i = gap; i < tamanho; i++) {
						value = pais[i];
						j = i;
						while ((j >= gap) and (value.informacoes.pib_per_capita > pais[j - gap].informacoes.pib_per_capita)) {
							pais[j] = pais[j - gap];
							j = j - gap;
						}
					pais[j] = value;
					}
					pos_gap--;
					}
				}
				break;
			}
			case 7: {// Cidade mais populosa
				while ( pos_gap >= 0 ) {
					while ( pos_gap >= 0 ) {
					int gap = gaps[pos_gap];
					
					for (int i = gap; i < tamanho; i++) {
						value = pais[i];
						j = i;
						while ((j >= gap) and (strcmp(value.informacoes.cidade_populosa, pais[j - gap].informacoes.cidade_populosa)) >= 0) {
							pais[j] = pais[j - gap];
							j = j - gap;
						}
					pais[j] = value;
					}
					pos_gap--;
					}
				}
				break;
			}
		}
	}
	ofstream escrever_dados("dados_paises_binario.dat", ios::binary);
	int contador_excluidos = 0;
	for(int i = 0; i < tamanho; i++)
	{
		if(pais[i].id == -1)
		{
			contador_excluidos++;
		}
	}
	pais = redimensiona(pais, tamanho, contador_excluidos);
	num = tamanho;
	escrever_dados.write((const char*) pais, sizeof(paises)*tamanho);
	escrever_dados.close();
}
 
void inserir(){
	paises inserido; //registro que será armazenado as informações do país que será inserido

	int sinalizador = 0; //verifica se o id digitado está disponível
	int contador = 0;  //verifica de existem linhas removidas logicamente pelo usuário
	int execucao = 1;  //enquanto estiver com valor 1, o subprograma continua rodando
	paises aux;
	fstream inserir("dados_paises_binario.dat", ios::binary|ios::in|ios::out);
	inserir.seekg(0, inserir.end);
	int num = inserir.tellg()/sizeof(paises);
	inserir.seekg(0, inserir.beg);
	
	while(execucao == 1)
	{
		cout << "===============Subprograma Inserir==============="<< endl;
		
		for(int j = 0; j < num; j++) //verifica se existem linhas removidas
		{
			inserir.seekg(sizeof(paises)*j, inserir.beg);
			inserir.read((char*) &aux, sizeof(paises));
			if(aux.id == -1)
			contador++;
		}
		inserir.seekg(0, inserir.beg);

		cout << "Digite um numero de identificacao (ID) que nao seja negativo: ";
		cin >> inserido.id;
		cout << endl;
		while (inserido.id < 0)
		{
			cout << "Numero invalido. Por favor, digite um numero de identificacao (ID) valido: ";
			cin >> inserido.id;
			cout << endl;
		}
		for(int j = 0; j < num; j++)
		{
			inserir.seekg(sizeof(paises)*j, inserir.beg);
			inserir.read((char*) &aux, sizeof(paises));
			if(inserido.id==aux.id)//verifica se o id digitado ja esta sendo utilizado
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
			cin.getline(inserido.nome, 50);
			cout << endl;
			cout << "Digite o continente ao qual esse pais pertence: ";
			cin.getline(inserido.continente, 10);
			cout << endl;
			cout << "Digite a cidade mais populosa desse pais: ";
			cin.getline(inserido.informacoes.cidade_populosa, 50);
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
				inserir.seekg(0, inserir.end);
				inserir.write((const char *) &inserido, sizeof(paises));
				num++;
				
				cout << endl;
				cout << "!==========================!" << endl;
				cout << "Dados inseridos com sucesso!" << endl;
				cout << "!==========================!" << endl << endl;
				
				break;
			}
			
			case 2: 
			{
				if(contador == 0) //caso não existam linhas removidas disponiveis e o usuario tenha digitado o numero 2, isso ocorre
				cout << endl << "Opcao invalida" << endl << endl;
				else
				{
					cout << endl;
					cout << "=============Linhas disponiveis=============" << endl;
					for (int i = 0; i < num; i++)
					{
						inserir.seekp(sizeof(paises)*i, inserir.beg);
						inserir.read((char*) &aux, sizeof(paises));
						if(aux.id == -1)
						{
							cout << i+1 << " ";
						}
					}
					inserir.seekg(0, inserir.beg);
					cout << endl << endl;
					cout << "Escolha a linha que deseja inserir: ";
					cin >> decisao;
					inserir.seekg(sizeof(paises)*(decisao-1), inserir.beg);
					inserir.read((char*) &aux, sizeof(paises));
					if(aux.id != -1)
					{
						
						cout << endl << "Opcao invalida" << endl << endl;
					}
					else
					{
						inserir.seekg(0, inserir.beg);
						inserir.seekp(sizeof(paises)*(decisao-1), inserir.beg);
						inserir.write((const char*) &inserido, sizeof(paises));
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
				cout << endl << "Opcao invalida" << endl << endl;
				break;
			}
		}
		
		if(execucao == 1)//nao entra nesse if caso o usuario digite 0 para voltar no menu inserir, pois 0 é atribuído à variavel "execucao" no case 0
		{
			cout << "=============================" << endl;
			cout << "Deseja continuar?" << endl;
			cout << "1) Sim" << endl;
			cout << "Outro valor) Nao" << endl;
			cout << "=============================" << endl << endl;
			cout << "Sua resposta: ";
			contador = 0;
			cin >> execucao; //o subprograma inserir começa novamente se o usuario digitar 1, pois esta dentro de um while que funciona caso execucao seja igual a 1
			cout << endl << endl;
		}			
	}
	inserir.close();
}				


	
void listar(int& opcao){
	bool listado; //checa se os dados foram listados ou o usuario quer parar de listar
	//O procedimento nao imprimira dados apagados, ou seja, que tenham -1 como valor
	//Algumas das opções impressas nao possuem a capacidade de serem listados de acordo com o valor digitado pelo usuario
	//Essas incluem: Extensao Territorial, Populacao, Pib per capta e cidade mais populosa
	ifstream tamanho("dados_paises_binario.dat", ios::binary);
	tamanho.seekg(0, tamanho.end);
	int num = tamanho.tellg()/sizeof(paises);
	tamanho.close();
	
	do{
		cout << endl;
		listado = false;
		opcao = 0;
		
		cout << "===============Subprograma Listar==============="<< endl;
		cout << "Selecione o modo que deseja listar:" << endl << endl;
		cout << "1) Listar tudo" << endl;
		cout << "2) Listar por id" << endl;
		cout << "3) Listar por continente" << endl; //Continente nao faz uso de ordenacao, ao possuir pouquissimas variaçoes
		cout << "4) Listar por nome" << endl;
		cout << "5) Listar por extensao territorial" << endl;
		cout << "6) Listar por populacao " << endl; 
		cout << "7) Listar por pib " << endl; 
		cout << "8) Listar por pib per capta " << endl; 
		cout << "9) Listar por cidade mais populosa" << endl;
		cout << "10) Listar por indice do pais" << endl;
		cout << "0) Voltar" << endl;
		cout << "========================================="<< endl;
		
		cout << "Sua resposta: ";
		cin >> opcao;
		
		switch(opcao){
			case 0: { // Voltar a funcao principal atraves da declaracao de um valor bool como verdadeiro
				listado = true;
				break; }
			case 1: { // Listar todos os dados cadastrados
				
				cout << "---------------------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "|   Id   |   Nome   |   Continente   |   Cidade mais populosa   |   Populacao   |   Extensao territorial   |   Pib  |   Pib per Capita  " << endl;
				cout << "---------------------------------------------------------------------------------------------------------------------------------------" << endl;
				ifstream arq("dados_paises_binario.dat", ios::binary);
				paises aux;
				int cont = 0;
				while(cont < num){
					if(arq){
						arq.seekg(sizeof(paises)*(cont),ios::beg);
						arq.read((char*) (&aux), sizeof(paises));
						if(aux.id != -1){
							cout << aux.id << "         " << aux.nome << "     " << aux.continente << "     " << aux.informacoes.cidade_populosa << "     " 
							<< aux.informacoes.populacao << "     " << aux.informacoes.extensao_territorial << "     " << aux.informacoes.pib << "     " << aux.informacoes.pib_per_capita << endl;
						}
						cont++;
					} else {
						arq.seekg(0, arq.beg);
					}
				}
				 arq.close();
				 break;
			}
   			case 2: //Listar um pais baseado no seu ID
   			{
				cout <<"===================================================" << endl;
				cout << "Como os IDs serao organizados?" << endl;
				cout << "1) Crescente" << endl;
				cout << "2) Decrescente" << endl;
				cout << "3) Buscar ID especifico" << endl;
				cout << "Qualquer numero) Voltar" << endl;
				cout << endl << "Sua resposta: ";
				
				cin >> opcao;
				
				if(opcao == 1 or opcao == 2){
					shell_sort(num, opcao, 1);
					cout << endl << endl;
				} 
				if(opcao == 3){
					ifstream arq("dados_paises_binario.dat", ios::binary);
					int id_procurado;
					cout << "Digite o id de um pais: ";
					cin >> id_procurado;
					cout << endl;
					
										
					cout << "---------------------------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "|   Id   |   Nome   |   Continente   |   Cidade mais populosa   |   Populacao   |   Extensao territorial   |   Pib  |   Pib per Capta  " << endl;
					cout << "---------------------------------------------------------------------------------------------------------------------------------------" << endl;
				
				
					paises aux;
					int cont = 0;
					for(cont = 0; cont < num; cont++){
						if(arq){
							arq.seekg(sizeof(paises)*(cont), arq.beg);
							arq.read((char*) (&aux), sizeof(paises));
							if(aux.id == id_procurado){
								cout << aux.id << "         " << aux.nome << "     " << aux.continente << "     " << aux.informacoes.cidade_populosa << "     " 
								<< aux.informacoes.populacao << "     " << aux.informacoes.extensao_territorial << "     " << aux.informacoes.pib << "     " << aux.informacoes.pib_per_capita << endl;
								listado = true;
							}
						} else {
							arq.seekg(0, arq.beg);
						}
					}
					arq.close();
					
					if(listado == false){
						cout << "!===================Falha====================!" << endl;
						cout << "        ID nao encontrado no sistema" << endl;
						cout << "!============================================!" << endl;
					}
					
				}
				break;
			}
			case 3: //Listar paises baseado no  continente digitado
			{
				ifstream arq("dados_paises_binario.dat", ios::binary);
				string continenteProcurado;
				cout << "Digite o nome do continente de maneira exata: ";
				cin.ignore();
				getline(cin, continenteProcurado);
				cout << endl;
				cout << "---------------------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "|   Id   |   Nome   |   Continente   |   Cidade mais populosa   |   Populacao   |   Extensao territorial   |   Pib  |   Pib per Capta  " << endl;
				cout << "---------------------------------------------------------------------------------------------------------------------------------------" << endl;
				
				
				paises aux;
				int cont = 0;
				while(cont < num){
					if(arq){
						arq.seekg(sizeof(paises)*(cont),ios::beg);
						arq.read((char*) (&aux), sizeof(paises));
						if(aux.continente == continenteProcurado and aux.id != -1){
							cout << aux.id << "         " << aux.nome << "     " << aux.continente << "     " << aux.informacoes.cidade_populosa << "     " 
							<< aux.informacoes.populacao << "     " << aux.informacoes.extensao_territorial << "     " << aux.informacoes.pib << "     " << aux.informacoes.pib_per_capita << endl;
							listado = true;
						}
						cont++;
					} else {
						arq.seekg(0, arq.beg);
					}
				}
				
				if(listado == false){ //caso nenhum paises seja listado de acordo com o nome do continente 
					cout << "!===================Falha====================!" << endl;
					cout << " Nome de continente nao encontrado no sistema " << endl;
					cout << "!============================================!" << endl;
				}
				arq.close();
				break;
			}
			case 4: //listar pais baseado no nome procurado
			{
				cout <<"===================================================" << endl;
				cout << "Como os Nomes dos paises serao organizados?" << endl;
				cout << "1) Crescente" << endl;
				cout << "2) Decrescente" << endl;
				cout << "3) Listar pais especifico" << endl;
				cout << "Qualquer numero) Voltar" << endl;
				cout << endl << "Sua resposta: ";
				
				cin >> opcao;
				
				if(opcao == 1 or opcao == 2){
					shell_sort(num, opcao, 2);
					cout << endl << endl;
				}
				if(opcao == 3){
					ifstream arq("dados_paises_binario.dat", ios::binary);
					string nomeProcurado;
					cout << "Digite o nome do pais de maneira exata: ";
					cin.ignore();
					getline(cin, nomeProcurado);
					cout << endl;
					cout << "---------------------------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "|   Id   |   Nome   |   Continente   |   Cidade mais populosa   |   Populacao   |   Extensao territorial   |   Pib  |   Pib per Capta  " << endl;
					cout << "---------------------------------------------------------------------------------------------------------------------------------------" << endl;
				
					paises aux;
					int cont = 0;
					while(cont < num){
						if(arq){
							arq.seekg(sizeof(paises)*(cont),ios::beg);
							arq.read((char*) (&aux), sizeof(paises));
							if(aux.nome == nomeProcurado and aux.id != -1){
								cout << aux.id << "         " << aux.nome << "     " << aux.continente << "     " << aux.informacoes.cidade_populosa << "     " 
								<< aux.informacoes.populacao << "     " << aux.informacoes.extensao_territorial << "     " << aux.informacoes.pib << "     " << aux.informacoes.pib_per_capita << endl;
								listado = true;
							}
							cont++;
						} else {
							arq.seekg(0, arq.beg);
						}
					}
					arq.close();
					if(listado == false){ //caso nao achem pais com o nome procurado
						cout << endl;
						cout << "!===================Falha====================!" << endl;
						cout << "     Nome do pais nao encontrado no sistema " << endl;
						cout << "!============================================!" << endl;
					}
				}
				break;
			}
			case 5:// Listar por extensao territorial
			{
				cout <<"===================================================" << endl;
				cout << "Como os valores das Extensoes Territoriais serao organizados?" << endl;
				cout << "1) Crescente" << endl;
				cout << "2) Decrescente" << endl;
				cout << "Qualquer numero) Voltar" << endl;
				cout << endl << "Sua resposta: ";
				
				cin >> opcao;
				
				if(opcao == 1 or opcao == 2){
					shell_sort(num, opcao, 4);
					cout << endl << endl;
				}
				
				break;
			}
			
			case 6: //Listar baseado na populacao
			{
				cout << "==============================================" << endl;
				cout << "Como o numero populacional devera ser organizado?" << endl;
				cout << "1) Crescente" << endl;
				cout << "2) Decrescente" << endl;
				cout << "Qualquer numero) Voltar" << endl << endl;
				
				cout << "Sua resposta: ";
				cin >> opcao;
				
				if(opcao == 1 or opcao == 2){
					shell_sort(num, opcao, 3);
					cout << endl << endl;
				}
				
				
				break;
			}
			case 7: //Listar baseado no pib
			{
				cout << "============================================" << endl;
				cout << "Como o pib devera ser organizado?" << endl;
				cout << "1) Crescente" << endl;
				cout << "2) Decrescente" << endl;
				cout << "Qualquer numero) Voltar" << endl << endl;
				
				cout << "Sua resposta: ";
				cin >> opcao;
				
				if(opcao == 1 or opcao == 2){
					shell_sort(num, opcao, 5);
					cout << endl << endl;
				}
				
				break;
			}
		
			case 8: //Listar baseado no pib per capta
			{
				cout << "============================================" << endl;
				cout << "Como o pib per capta devera ser organizado?" << endl;
				cout << "1) Crescente" << endl;
				cout << "2) Decrescente" << endl;
				cout << "Qualquer numero) Voltar" << endl << endl;
				cout << "Sua resposta: ";
				cin >> opcao;
				
				if(opcao == 1 or opcao == 2){
					shell_sort(num, opcao, 6);
					cout << endl << endl;
				}
			}
			
			case 9: //Listar baseado na cidade mais populosa
			{
				cout << "============================================" << endl;
				cout << "Como as cidades mais populosas deverao ser organizadas?" << endl;
				cout << "1) Crescente" << endl;
				cout << "2) Decrescente" << endl;
				cout << "Qualquer numero) Voltar" << endl << endl;
				cout << "Sua resposta: ";
				cin >> opcao;
				
				if(opcao == 1 or opcao == 2){
					shell_sort(num, opcao, 7);
					cout << endl << endl;
				}
				
				break;
			}
			
			case 10:// listar baseado no indice do vetor
			{
				ifstream arq("dados_paises_binario.dat", ios::binary);
				cout << "Digite um indice dentro do intervalo de 0 a " << num-1<< endl;
				int indiceInicial = -1, indiceFinal = -1;
				cout << "Digite o indice inicial: ";
				while(indiceInicial < 0 or indiceInicial > num-1){
					cin >> indiceInicial;
					if(indiceInicial < 0 or indiceInicial > num-1){
						cout << endl;
						cout << "Indice inicial invalido" << endl;
						cout << "Digite o indice inicial: ";
					}
				}
				
				cout << "Digite o indice final: ";
				while(indiceFinal < indiceInicial or indiceFinal > num-1){
					cin >> indiceFinal;
					if(indiceFinal < indiceInicial or indiceFinal > num-1){
						cout << endl;
						cout << "Indice final invalido" << endl;
						cout << "Digite o indice final: ";
					}
				}
				
				cout << endl;
				cout << "---------------------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "|   Id   |   Nome   |   Continente   |   Cidade mais populosa   |   Populacao   |   Extensao territorial   |   Pib  |   Pib per Capta  " << endl;
				cout << "---------------------------------------------------------------------------------------------------------------------------------------" << endl;
				
				paises aux;
				int cont = indiceInicial;
				while(cont <= indiceFinal){
					if(arq){
						arq.seekg(sizeof(paises)*(cont),ios::beg);
						arq.read((char*) (&aux), sizeof(paises));
						if(aux.id != -1){
							cout << aux.id << "         " << aux.nome << "     " << aux.continente << "     " << aux.informacoes.cidade_populosa << "     " 
							<< aux.informacoes.populacao << "     " << aux.informacoes.extensao_territorial << "     " << aux.informacoes.pib << "     " << aux.informacoes.pib_per_capita << endl;
						}
						
						cont++;
					} else {
						arq.seekg(0, arq.beg);
					}
				}
				listado = true;
				arq.close();
				break;
			}
			
			default: //Caso o usuario digite uma opcao inexistente
			{
				cout << "Opcao inexistente ou invalida!";
			}
		}
	}while(listado != true);
}

void editar(int& opcao){
	int id_digitado = -1; //ID do pais utilizado
	int indice_pais = -1; 
	bool para_tudo = false; //<-- Serve para quando o usuario querer sair da edicao
	// Editar faz uso do indice do vetor de registro para identificar o pais
	fstream edicao("dados_paises_binario.dat", ios::binary|ios::in|ios::out);
	edicao.seekg(0, edicao.end);
	int num = edicao.tellg()/sizeof(paises);
	paises aux;
	
	cout << endl;
	cout << "====================================================" << endl;
	cout << "Selecione o ID do pais disponivel. Qual deles voce deseja editar?" << endl;
	
	
	for(int i = 0; i < num; i++){ //Mostrar quais ids estao disponiveis no arquivo binarios
		edicao.seekg(sizeof(paises)*i, edicao.beg);
		edicao.read((char*)	 &aux, sizeof(paises));
		if(aux.id != -1)
		{
			cout << aux.id << " ";
		}
	}
	cout << endl;
	edicao.seekg(0, edicao.beg);
	while(indice_pais < 0){ //ID deve estar disponivel para saber  o indice do pais
		cout << "Sua resposta: ";
		cin >> id_digitado;
		cout << endl;
		for(int i = 0; i < num; i++){
			edicao.seekg(sizeof(paises)*i, edicao.beg);
			edicao.read((char*)	 &aux, sizeof(paises));
			if(aux.id == id_digitado and aux.id != -1){
				indice_pais = i;
			}
		}
		if(indice_pais == -1){
			cout << "Este id nao foi identificado no sistema. Digite novamente" << endl;
		}
	}
	edicao.seekg(0, edicao.beg);
	
	do{
		cout << "================Subprograma Editar================" << endl;
		cout << "Selecione a opcao que desejar:" << endl << endl;
		cout << "1) Editar tudo" << endl;
		cout << "2) Editar ID" << endl;
		cout << "3) Editar Nome" << endl;
		cout << "4) Editar Continente" << endl;
		cout << "5) Editar Cidade mais populosa" << endl;
		cout << "6) Editar Populacao" << endl;
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
				int contador; //Contara se outros paises possuem mesmo ID
				
				cout << "=======================================" << endl;
				cout << "Pais numero " << indice_pais << endl;
				for(contador = 0; contador < num; contador++){//Checa se o ID aparece em outras structs, senao o usuario eh obrigado a mandar valores até que a condicao do WHILE termine
					if(contador == 0){
						cout << "ID: "; //ID eh a unica variavel que deve ser distinta
						cin >> idChecador; //Inseri id em outra variavel
					}
					edicao.seekg(sizeof(paises)*contador, edicao.beg);
					edicao.read((char*)	 &aux, sizeof(paises));
					if(aux.id == idChecador or idChecador < 0){
						cout << "Este ID eh invalido ou ja existe!" << endl;
						contador = -1;
					}
				}
				edicao.seekg(0, edicao.beg);
				edicao.seekg(sizeof(paises)*indice_pais, edicao.beg);
				edicao.read((char*) &aux, sizeof(paises));
				aux.id = idChecador;
				edicao.seekg(0, edicao.beg);
				
				cout << "Nome: ";
				cin.ignore();
				cin.getline(aux.nome, 50);
				
				cout << "Continente: ";
				cin >> aux.continente;
				
				cout << "Cidade mais populosa: ";
				cin.ignore();
				cin.getline(aux.informacoes.cidade_populosa, 50);
					
				cout << "Populacao: ";
				cin >> aux.informacoes.populacao;
				
				cout << "Extensao territorial: ";
				cin >> aux.informacoes.extensao_territorial;
					
				cout << "Pib: ";
				cin >> aux.informacoes.pib;
				
				cout << "Pib per capita: ";
				cin >> aux.informacoes.pib_per_capita;
				
				cout << "!==================================!" << endl;
				cout << "  O pais foi editado com sucesso" << endl;
				cout << "!==================================!" << endl;
				edicao.seekp(sizeof(paises)*indice_pais, edicao.beg);
				edicao.write((const char*) &aux, sizeof(paises));
				edicao.seekg(0, edicao.beg);
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
					edicao.seekg(sizeof(paises)*contador, edicao.beg);
					edicao.read((char*)	 &aux, sizeof(paises));
					if(aux.id == idChecador or idChecador < 0){
						cout << "Este ID ja existe, ou eh invalido!" << endl;
						contador = -1;
					}
				}
				edicao.clear();
				edicao.seekg(0, edicao.beg);
				edicao.seekg(sizeof(paises)*indice_pais, edicao.beg);
				edicao.read((char*)	 &aux, sizeof(paises));
				aux.id = idChecador;
				edicao.seekp(sizeof(paises)*indice_pais, edicao.beg);
				edicao.write((const char*) &aux, sizeof(paises));
				edicao.seekg(0, edicao.beg);
				cout << "O ID foi editado com sucesso!" << endl;
				break;
			}
			case 3: //Editar Nome
			{
				cout << "=======================================" << endl;
				cout << "Nome: ";
				edicao.seekg(sizeof(paises)*indice_pais, edicao.beg);
				edicao.read((char*)	 &aux, sizeof(paises));
				cin.ignore();
				cin.getline(aux.nome, 50);
				edicao.seekp(sizeof(paises)*indice_pais, edicao.beg);
				edicao.write((const char*) &aux, sizeof(paises));
				edicao.seekg(0, edicao.beg);
				cout << "O Nome do pais foi editado com sucesso!" << endl;
				break;
			}
			case 4: //Editar Continente
			{
				cout << "=======================================" << endl;
				cout << "Continente: ";
				edicao.seekg(sizeof(paises)*indice_pais, edicao.beg);
				edicao.read((char*)	 &aux, sizeof(paises));
				cin >> aux.continente;
				edicao.seekp(sizeof(paises)*indice_pais, edicao.beg);
				edicao.write((const char*) &aux, sizeof(paises));
				edicao.seekg(0, edicao.beg);
				cout << "O Continente foi editado com sucesso!" << endl;
				break;
			}
			case 5: //Editar Cidade mais populosa
			{
				cout << "=======================================" << endl;
				cout << "Cidade mais populosa: ";
				edicao.seekg(sizeof(paises)*indice_pais, edicao.beg);
				edicao.read((char*)	 &aux, sizeof(paises));
				cin.ignore();
				cin.getline(aux.informacoes.cidade_populosa, 50);
				edicao.seekp(sizeof(paises)*indice_pais, edicao.beg);
				edicao.write((const char*) &aux, sizeof(paises));
				edicao.seekg(0, edicao.beg);
				cout << "A Cidade mais populosa foi editada com sucesso!" << endl;
				break;
			}
			case 6: //Editar Populacao
			{
				cout << "=======================================" << endl;
				cout << "Populacao: ";
				edicao.seekg(sizeof(paises)*indice_pais, edicao.beg);
				edicao.read((char*)	 &aux, sizeof(paises));
				cin >> aux.informacoes.populacao;
				edicao.seekp(sizeof(paises)*indice_pais, edicao.beg);
				edicao.write((const char*) &aux, sizeof(paises));
				edicao.seekg(0, edicao.beg);
				cout << "A Populacao foi editada com sucesso!" << endl;
				break;
			}
			case 7: //Editar Extensao territorial
			{
				cout << "=======================================" << endl;
				cout << "Extensao territorial: ";
				edicao.seekg(sizeof(paises)*indice_pais, edicao.beg);
				edicao.read((char*)	 &aux, sizeof(paises));
				cin >> aux.informacoes.extensao_territorial;
				edicao.seekp(sizeof(paises)*indice_pais, edicao.beg);
				edicao.write((const char*) &aux, sizeof(paises));
				edicao.seekg(0, edicao.beg);
				cout << "A Extensao Territorial foi editada com sucesso!" << endl;
				break;
			}
			case 8: //Editar Pib
			{
				cout << "=======================================" << endl;
				cout << "Pib: ";
				edicao.seekg(sizeof(paises)*indice_pais, edicao.beg);
				edicao.read((char*)	 &aux, sizeof(paises));
				cin >> aux.informacoes.pib;
				edicao.seekp(sizeof(paises)*indice_pais, edicao.beg);
				edicao.write((const char*) &aux, sizeof(paises));
				edicao.seekg(0, edicao.beg);
				cout << "O Pib foi editado com sucesso!" << endl;
				break;
			}
			case 9: //Editar Pib per capita
			{
				cout << "=======================================" << endl;
				cout << "Pib per capita: ";
				edicao.seekg(sizeof(paises)*indice_pais, edicao.beg);
				edicao.read((char*)	 &aux, sizeof(paises));
				cin >> aux.informacoes.pib_per_capita;
				edicao.seekp(sizeof(paises)*indice_pais, edicao.beg);
				edicao.write((const char*) &aux, sizeof(paises));
				edicao.seekg(0, edicao.beg);
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
	edicao.close();
}

void remover(){
	int escolha; 
	/* escolha conta número de linhas que o usuário quer remover. deve ser um número inteiro positivo e não pode ser maior
	 *  que o número de países disponíveis para remoção */
	int contador = 0;  //conta quantas linhas estão disponíveis para remoção
	int verificador = 0; //verifica se todos os ids digitados pelo usuário estão disponíveis para remoção
	paises aux;
	paises remocao; //será escrita em registros que o usuário quer remover, pois tem todos os campos com -1
	remocao.id = -1;
	memcpy(remocao.nome, "-1", 50);
	memcpy(remocao.continente, "-1", 10);
	memcpy(remocao.informacoes.cidade_populosa, "-1", 50);
	remocao.informacoes.populacao = -1;
	remocao.informacoes.extensao_territorial = -1;
	remocao.informacoes.pib = -1;
	remocao.informacoes.pib_per_capita = -1;
	fstream arquivo("dados_paises_binario.dat", ios::binary|ios::in|ios::out);
	arquivo.seekg(0, arquivo.end);
	int num = arquivo.tellg()/sizeof(paises);
	arquivo.seekg(0, arquivo.beg);
	
	cout << "===============Subprograma Remover==============="<< endl;
	for (int i = 0; i < num; i++)//verifica quantas linhas podem ser removidas
	{
		arquivo.seekg(sizeof(paises)*i, arquivo.beg);
		arquivo.read((char *) &aux, sizeof(paises));
		if(aux.id != -1)
		contador++;
	}
	arquivo.seekg(0, arquivo.beg);
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
			arquivo.seekg(sizeof(paises)*i, arquivo.beg);
			arquivo.read((char *) &aux, sizeof(paises));
			if(aux.id != -1)
			cout << aux.id << " ";
		}
		arquivo.seekg(0, arquivo.beg);
		cout << endl;
		int ids_remocao[escolha];
		
		cout << "Digite os ids (numeros de identificacao) que voce quer remover: ";
		for(int i = 0; i < escolha; i++)
		{
			cin >> ids_remocao[i];
		}
		for(int i = 0; i < num; i++) //verifica se todos os ids digitados estão disponiveis para remoção
		{
			arquivo.seekg(sizeof(paises)*i, arquivo.beg);
			arquivo.read((char *) &aux, sizeof(paises));
			for(int j = 0; j < escolha; j++)
			{
				if(aux.id == ids_remocao[j])
				{
					verificador++;
				}
			}
		}
		arquivo.seekg(0, arquivo.beg);
		if(verificador == escolha)//remocao so ocorre se todos os ids digitados estiverem disponiveis
		{		
			for(int i = 0; i < num; i++)
			{
				arquivo.seekg(sizeof(paises)*i, arquivo.beg);
				arquivo.read((char *) &aux, sizeof(paises));
				for(int j = 0; j < escolha; j++)
				{
					if(aux.id == ids_remocao[j])
					{
						arquivo.seekg(0, arquivo.beg);
						arquivo.seekp(sizeof(paises)*i, arquivo.beg);
						arquivo.write((const char *) &remocao, sizeof(paises));
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
	arquivo.seekg(0, arquivo.beg);
	arquivo.close();
	
}

void exportarCSV(){
	string nome_Arquivo;
	cout << "===========Subprograma Exportar====================" << endl;
	cout << "Digite o nome do arquivo a ser exportado: ";
	ifstream ler_dados("dados_paises_binario.dat", ios::binary);
	ler_dados.seekg(0, ler_dados.end);
	int num = ler_dados.tellg()/sizeof(paises);
	paises pais[num];
	ler_dados.seekg(0, ler_dados.beg);
	ler_dados.read((char*) pais, sizeof(paises)*num);
	ler_dados.close();
	cin >> nome_Arquivo;
	ofstream escrever(nome_Arquivo);
	escrever << "numero_de_identificacao,nome_do_pais,continente,cidade_mais_populosa,populacao_do_pais,extensao_territorial_do_pais,pib,pib_per_capita" << endl;
	escrever << num << endl;
	for(int i = 0; i < num; i++){
		escrever << pais[i].id << ",";
		escrever << pais[i].nome << ",";
		escrever << pais[i].continente << ",";
		escrever << pais[i].informacoes.cidade_populosa << ",";
		escrever << pais[i].informacoes.populacao << ",";
		escrever << pais[i].informacoes.extensao_territorial << ",";
		escrever << pais[i].informacoes.pib << ",";
		escrever << pais[i].informacoes.pib_per_capita;
		escrever << endl;
	}
	
	escrever.close();
	
	
	cout << "Exportado com sucesso!" << endl;
}

int main(){
	bool saida = false;
	int opcao;	
	int num;
	char lixo;
	string linha_lixo; 
	
	ifstream leitura_inicial("dados_paises.csv");
	getline(leitura_inicial, linha_lixo);
	leitura_inicial >> num;
	
	paises vetor_inicial[num];
	for(int i = 0; i < num; i++) //Ler dados no  arquivo csv
	{
		leitura_inicial >> vetor_inicial[i].id;
		leitura_inicial >> lixo;
		leitura_inicial.getline(vetor_inicial[i].nome, 50, ',');
		leitura_inicial.getline(vetor_inicial[i].continente, 10, ',');
		leitura_inicial.getline(vetor_inicial[i].informacoes.cidade_populosa, 50, ',');
		leitura_inicial >> vetor_inicial[i].informacoes.populacao;
		leitura_inicial >> lixo;
		leitura_inicial >> vetor_inicial[i].informacoes.extensao_territorial;
		leitura_inicial >> lixo;
		leitura_inicial >> vetor_inicial[i].informacoes.pib;
		leitura_inicial >> lixo;
		leitura_inicial >> vetor_inicial[i].informacoes.pib_per_capita;
	}
	leitura_inicial.close();
	ofstream arquivo_binario("dados_paises_binario.dat", ios::binary);
	arquivo_binario.write((const char*) vetor_inicial, sizeof(paises)*num);
	arquivo_binario.close();
	
	
	while(saida != true){
		cout << "------------Sistema de Cadastro de Paises------------" << endl;
		cout << "1) Inserir" << endl;
		cout << "2) Listar" << endl;
		cout << "3) Editar" << endl;
		cout << "4) Remover" << endl;
		cout << "5) Exportar CSVs" << endl;
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
				inserir();
				break;
			case 2:
				listar(opcao);
				break;
			case 3:
				editar(opcao);
				break;
			case 4:
				remover();
				break;
			case 5:
				exportarCSV();
				break;
			default:
				cout << "Opcao inexistente ou invalida" << endl; 
			}
	}
	
	cout << "Programa saindo...";
	return 0;
}

