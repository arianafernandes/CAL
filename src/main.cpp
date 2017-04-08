#include <fstream>
#include <iostream>
#include <sstream>
#include <math.h>
#include <vector>
#include <cmath>

#include "Company.h"

void newDelivery(Company &comp, User& user){
	string temp,date;
	int weight;

	cout << "Indique o peso da sua encomenda!" << endl;
	getline(cin,temp);
	weight = stoi(temp);

	cout << "Indique a data de entrega da encomenda!" << endl;
	getline(cin,date);

	Order order= Order(user.getAddressId(), weight, date);

	/*
	 * Adicionar a Order a um truck e ao File das delivery
	 *
	 */
	ofstream delfile;
	delfile.open("delivery.txt", ios::app);
	delfile << user.getAddressId() << ";" << weight << ";" << date << ";" << endl;
	delfile.close();

	comp.getSupermarket().addOrderToTruck(order);
	vector<Truck> trucks = comp.getSupermarket().getTrucks();
}

void changeName(Company& comp,User & user){
	string name;
	cout << "Indique o novo Nome para a conta" << endl;
	getline(cin, name);

	user.setName(name);
	/**
	 * Modificar o nome do cliente no User e no FIle
	 */
}
void changeAddress(Company& comp, User& user){
	string name;
	cout << "Indique a nova Morada(id) para a conta" << endl;
	getline(cin, name);

	user.setAddressId(stoi(name));

	/**
	 * Modificar a morado do cliente e no File E VERIFICAR SE E VALIDA
	 */

}

void changeAccount(Company& comp,User & user){
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
			changeName(comp,user);
			break;
		case 2:
			changeAddress(comp,user);
			break;
		default:
			break;
		}
		system("cls");
	}

}

void eliminateAccount(Company comp, User u){
	/*
	 * Eliminar User from User and File
	 */
	vector<User>& users =comp.getSupermarket().getUsers();
	for (unsigned int i =0; i<users.size(); i++){
		cout << "name " << users[i].getName() << " nif "  << users[i].getNif() << endl;
	}

	for (unsigned int i =0; i<users.size(); i++){
		if (users[i].getNif()==u.getNif()){
			users.erase(users.begin()+i);
		}
	}

	for (unsigned int i =0; i<users.size(); i++){
		cout << "name " << users[i].getName() << " nif "  << users[i].getNif() << endl;
	}
}

void areaCliente(Company& comp, User& user){
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
			newDelivery(comp,user);
			break;
		case 2:
			changeAccount(comp,user);
			break;
		case 3:
			eliminateAccount(comp,user);
			break;
		default:
			break;
		}
		system("cls");
	}

}

void Login(Company &comp){
	int option = 0;
	bool existe = false;
	int nif;
	string ss;
	cout << "Bem-vindo a tab do Login!" << endl;

	cout << "Introduza o seu nif" << endl;
	getline(cin,ss);
	nif = stoi(ss);

	User user = comp.getSupermarket().findUserFromNif(nif);

	if (user.getNif()==0){
		cout<<" Não se encontra registado! Por favor, efetue o registo!"<< endl;
	}
	else
	{
		areaCliente(comp,user);
	}



	/*
	 * PROCURAR CLIENTE NO FILE DE CLIENTES
	 */
	system("cls");


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

	bool exists =false;
	User user = comp.getSupermarket().findUserFromNif(nif);
	if(user.getNif() != 0)
		exists = true;


	if(!exists){
		ofstream usersFile;
		usersFile.open("users.txt", ios::app);
		usersFile << name << ";" << nif << ";" << id<< ";" << endl;
		usersFile.close();
		User user = User(name,nif,id);
		comp.getSupermarket().addUser(user);
	}else{
		cout << "This user already exists!" << endl;
	}
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

	comp.getSupermarket().displayAllTrucks();
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

	comp.getSupermarket().setName(name);
}
void changeAddressSuper(Company &comp){
	string name;
	cout << "Indique a nova morada(id) do Supermercado" << endl;
	getline(cin, name);
	comp.getSupermarket().setIdSuper(stoi(name));
	//Verificar se o id existe
	cout << "id super " << comp.getSupermarket().getIdSuper() << endl;
}

void changeCapacity(Company& comp){
	string id,cap;
	comp.getSupermarket().printAllTrucks();
	do{
		cout << "Indique, por favor, o id do camiao a modificar!"<< endl;
		getline(cin,id);
		cout << "Indique a capacidade maxima" << endl;
		getline(cin,cap);
	}while(!comp.getSupermarket().setCapacityToTruck(stoi(cap),stoi(id)));
}

void changeMaxDist(Company& comp){
	string id,cap;
	comp.getSupermarket().printAllTrucks();
	do{
	cout << "Indique, por favor, o id do camiao a modificar!"<< endl;
	getline(cin,id);
	cout << "Indique a distancia maxima" << endl;
	getline(cin,cap);
	}while(!comp.getSupermarket().setDistanceToTruck(stoi(cap),stoi(id)));
}

void changeTrucks(Company &comp){
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
			changeCapacity(comp);
			break;
		case 2:
			//Mudar distancia maxima
			changeMaxDist(comp);
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
		cout << "Bem-vindo ao tab de administracao do " <<comp.getSupermarket().getName() << endl;
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
	interfUser(comp);

	//Save To file
	getchar();
	return 0;
}
