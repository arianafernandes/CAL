#include <fstream>
#include <iostream>
#include <sstream>
#include <math.h>
#include <vector>
#include <cmath>

#include "Company.h"

void newDelivery(Company &comp){
	string temp,data;
	double weight;

	cout << "Indique o peso da sua encomenda!" << endl;
	getline(cin,temp);
	weight = stoi(temp);

	cout << "Indique a data de entrega da encomenda!" << endl;
	getline(cin,data);

	/*
	 * Adicionar a Order a um truck e ao File das delivery
	 */
}

void changeName(Company& comp){
	string name;
	cout << "Indique o novo Nome para a conta" << endl;
	getline(cin, name);
	/**
	 * Modificar o nome do cliente no User e no FIle
	 */
}
void changeAddress(Company& comp){
	string name;
	cout << "Indique a nova Morada(id) para a conta" << endl;
	getline(cin, name);
	/**
	 * Modificar a morado do cliente e no File E VERIFICAR SE E VALIDA
	 */
}

void changeAccount(Company& comp){
	int option = 0;
		string ss;
		while (option != 3) {
			cout << "Modificar conta de Cliente" << endl;

			cout << "1 - Modificar o Nome da conta" << endl
					<<"2 - Modificar a Morada" << endl
					<<"3 - Sair" << endl;

			getline(cin,ss);
			option = stoi(ss);

			switch (option) {
				case 1:
					changeName(comp);
					break;
				case 2:
					changeAddress(comp);
					break;
				default:
					break;
				}
				system("cls");
			}

}

void eliminateAccount(Company comp){
/*
 * Eliminar User from User and File
 */
}

void areaCliente(Company& comp){
	int option = 0;
	string ss;
	while (option != 4) {
		cout << "Bem-vindo a tab dos Clientes!" << endl;

		cout << "1 - Realizar uma encomenda" << endl
				<< "2 - Modificar Conta" << endl
				<< "3- Eliminar Conta" << endl
				<< "4- Sair" << endl;

		getline(cin,ss);
		option = stoi(ss);


		switch (option) {
		case 1:
			newDelivery(comp);
			break;
		case 2:
			changeAccount(comp);
			break;
		case 3:
			eliminateAccount(comp);
			break;
		default:
			break;
		}
		system("cls");
	}

}

void Login(Company &comp){
	int option = 0;
	int nif;
	string ss;
	cout << "Bem-vindo a tab do Login!" << endl;

	cout << "Introduza o seu nif" << endl;
	getline(cin,ss);
	nif = stoi(ss);

	/*
	 * PROCURAR CLIENTE NO FILE DE CLIENTES
	 */
	system("cls");

	areaCliente(comp);
}
void newCliente(Company &comp) {
	string name, date,temp;
	int nif, id, weight;
	cout << "Indique por favor:" << endl;
	cout << "O seu nome" << endl;
	getline(cin,name);
	cout << "O seu nif:" << endl;
	getline(cin,temp);
	nif = stoi(temp);
	cout << "O id da sua morada:" << endl;
	getline(cin,temp);
	id = stoi(temp);
	//VERIFICAR SE EXISTE

	/**
	 * ADICIONAR O CLIENTE AO FILE
	 */

	cout << "Obrigado! A sua encomenda está a ser processada." << endl;
	cout << "name " << name << " nif "  << nif << " id " << id << endl;
	//Adicionar a order a company.
}
void Clientes(Company& comp){
	int option = 0;
	string ss;
	while (option != 3) {
		cout << "Bem-vindo a tab dos Clientes!" << endl;

		cout << "1 - Registar-se" << endl
				<< "2 - Login" << endl
				<< "3 - Sair." << endl;

		cout << "Insira o número da sua escolha. Obrigado." << endl;

		getline(cin,ss);
		option = stoi(ss);

		switch (option) {
		case 1:
			newCliente(comp);
			//Registar-se
			break;
		case 2:
			Login(comp);
			//Fazer login
			break;
		default:
			break;
		}
		system("cls");
	}
}



void watchDistribuition(Company &comp){

	int id;
	string data;

	/**
	 * Mostrar todos os camioes
	 * Selecionar um camiao
	 * E depois mostrar as datas e escolher uma data
	 */


}

void changeNameSuper(Company &comp){
	string name;
	cout << "Indique o novo nome do Supermercado" << endl;
	getline(cin, name);

	/**
	 * Modificar o nome do supermercado
	 */
}
void changeAddressSuper(Company &comp){
	string name;
		cout << "Indique a nova morada(id) do Supermercado" << endl;
		getline(cin, name);
		/**
		 * Modificar o id do Supermercado
		 */
}

void changeTrucks(Company &comp){
/**
 * Visualizar todos os trucks e dele escolher um para depois modificar as dist e cap
 */


	int option = 0;
			string ss;
			while (option != 3) {
				cout << "1 - Modificar a capacidade maxima do camiao " << endl
						<< "2 - Modificar a distancia maxima percorrida pelo camiao"
						<< endl << "3 - Sair."
						<< endl;
				cout << "Insira o número da sua escolha. Obrigado." << endl;
				getline(cin, ss);
				option = stoi(ss);
				switch (option) {
				case 1:
					//Mudar capacidade
					break;
				case 2:
				//Mudar distancia maxima
					break;
				default:
					break;
				}
				system("cls");
			}


}

void adminSuper(Company& comp){

	int option = 0;
		string ss;
		while (option != 4) {
			cout << "Bem-vindo ao tab de administracao do Super Preços Baixos!!" << endl;
			cout << "1 - Mudar o Nome do Supermercado " << endl << "2 - Modificar o local do Supermercado"
					<< endl << "3 - Modificar Camioes" << endl << "4 - Sair."
					<< endl;
			cout << "Insira o número da sua escolha. Obrigado." << endl;
			getline(cin, ss);
			option = stoi(ss);
			switch (option) {
			case 1:
				//Mudar nome do super
				changeNameSuper(comp);
				break;
			case 2:
			changeAddressSuper(comp);
				break;
			case 3:
			changeTrucks(comp);
				break;
			default:
				break;
			}
			system("cls");
		}
}

void interfUser(Company& comp) {
	//cout << "Read users done" << endl;
	//comp.distribution();
	//cout << "Distribuition of orders done" << endl;
	int option = 0;
	string ss;
	while (option != 4) {
		cout << "Bem-vindo ao Super Preços Baixos!!" << endl;
		cout << "1 - Clientes " << endl << "2 - Distribuição de entregas"
				<< endl << "3 - Administrar Supermercado" << endl << "4 - Sair."
				<< endl;
		cout << "Insira o número da sua escolha. Obrigado." << endl;
		getline(cin, ss);
		option = stoi(ss);
		switch (option) {
		case 1:
			Clientes(comp);
			break;
		case 2:
			watchDistribuition(comp);
			break;
		case 3:
			//Administrar Supermercado
			adminSuper(comp);
			break;
		default:
			break;
		}
		system("cls");
	}
}

int main() {
	Company comp = Company(137309415);
	comp.readMaps();
	//cout << "Read maps done" << endl;
	//comp.createGraphViewer();
	//cout << "Create graphviewer done" << endl;
	comp.readDeliveries();
	comp.readUsers();
	//cout << "Read users done" << endl;
	//comp.distribution();
	//cout << "Distribuition of orders done" << endl;
	//interfUser(comp);
	getchar();
	return 0;
}
