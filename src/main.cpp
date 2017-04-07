#include <fstream>
#include <iostream>
#include <sstream>
#include <math.h>
#include <vector>
#include <cmath>

#include "Company.h"

void newOrder(Company comp) {
	string name, date;
	int nif, id, weight;
	cout << "Indique por favor:" << endl;
	cout << "O seu nome" << endl;
	cin >> name;
	cout << "O seu nif:" << endl;
	cin >> nif;
	cout << "O id da sua morada:" << endl;
	cin >> id;
	cout << "O peso da sua encomenda:" << endl;
	cin >> weight ;
	cout << "A data de entrega da sua encomenda: " << endl;
	cin >> date;

	cout << "Obrigado! A sua encomenda está a ser processada." << endl;

	//Adicionar a order a company.
}

void watchDistribuition(Company comp){

	int id;
	string data;

	cout << "Indique por favor:" << endl;
	cout << "O id da morada:" << endl;
	cin >> id ;
	cout << "A data da encomenda que pretende ver.";
	cin >> data;

	//Ver a encomenda

	cout << "Obrigado!" << endl;
}

void watchAllDistribuitions(Company comp){
	string data;
	cout << "Indique por favor:" << endl;

	cout << "A data em que pretende ver todas as encomendas do Super Preços Baixos.";
	cin >> data;

	//Ver todas as encomendas;
}

int main() {
	Company comp = Company(137309415);
	comp.readMaps();
	//cout << "Read maps done" << endl;
	comp.createGraphViewer();
	//cout << "Create graphviewer done" << endl;
	comp.readUsers();
	//cout << "Read users done" << endl;
	comp.distribution();
	//cout << "Distribuition of orders done" << endl;
	int option = 0;
	while (option != 4) {
		cout << "Bem-vindo ao Super Preços Baixos!!" << endl;

		cout << "Prefere: " << endl
				<< "1 - Fazer uma nova encomenda? " << endl
				<< "2 - Ver a distribuição de uma determinada encomenda?" << endl
				<< "3 - Ver todas as distribuições de encomendas do Super Preços Baixos para uma determinada data?" << endl
				<< "4 - Sair." << endl;

		cout << "Insira o número da sua escolha. Obrigado." << endl;

		cin >> option;

		switch (option) {
		case 1:
			newOrder(comp);
			break;
		case 2:
			watchDistribuition(comp);
			break;
		case 3:
			watchAllDistribuitions(comp);
			break;
		default:
			break;
		}


	system("cls");
	}

	getchar();
	return 0;
}
