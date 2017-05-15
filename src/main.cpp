#include <fstream>
#include <iostream>
#include <sstream>
#include <math.h>
#include <vector>
#include <cmath>

#include "Company.h"
#include "Auxi.h"
#include "Matcher.h"

/**
 * @brief Test if input is correct number.
 * @param comp Company.
 * @param nif Nif.
 *
 * @return True if success, otherwise return false.
 */
bool testInputNif(Company &comp, string nif){
	if(nif.size()==0)
		return false;
	if(!isNOTNumber(nif))
		return false;
	return true;
}

/**
 * @brief Test if input is correct name.
 * @param comp Company.
 * @param name Name.
 *
 * @return True if success, otherwise return false.
 */
bool testInputName(Company &comp, string name){
	if(name.size()==0)
		return false;
	if(!isNumber(name))
		return false;
	return true;
}


/**
 * @brief Test if input is correct date format.
 * @param comp Company.
 * @param data Date
 *
 * @return True if success, otherwise return false.
 */
bool testDateFormat(Company comp, string data){
	if(data.size()!=10)
		return false;
	if (data[2] != '/' || data[5]!=  '/')
		return false;
	if(!isdigit(data[0])||!isdigit(data[1]) || !isdigit(data[3]) || !isdigit(data[4]) || !isdigit(data[6]) || !isdigit(data[7]) || !isdigit(data[8]) || !isdigit(data[9]))
		return false;
	return true;

}

/**
 * @brief Print all orders of the supermarket.
 *
 * @param orders Supermarket orders.
 */
void printOrders(vector<Order> orders){
	for(unsigned int i = 0; i < orders.size(); i++){
		cout << orders[i];
	}
}

/**
 * @brief Create a new delivery.
 *
 * @param comp Company.
 * @param user User.
 */
void newDelivery(Company &comp, User& user){
	string temp,date;
	int weight;

	do{
		cout << "Indique o peso da sua encomenda!" << endl;
		getline(cin,temp);
	}while(testInputNif(comp,temp));
	weight = stoi(temp);

	do{
		cout << "Indique a data de entrega da encomenda!" << endl;
		getline(cin,date);
	}while(!testDateFormat(comp, date));


	Order order= Order(user.getAddressId(), weight, date);

	comp.getSupermarket().addOrderToTruck(order);
comp.getSupermarket().printAllTrucks();

	for(unsigned int i = 0; i< comp.getSupermarket().getTrucks().size();i++){
	printOrders(comp.getSupermarket().getTrucks()[i].getOrders());
	}
}


/**
 * @brief Change User name.
 *
 * @param comp Company.
 * @param user User.
 */
void changeName(Company& comp,User & user){
	string name;
	do{
		cout << "Indique o novo Nome para a conta" << endl;
		getline(cin, name);
	}while(testInputName(comp, name));

	user.setName(name);
}

/**
 * @brief Change User address.
 *
 * @param comp Company.
 * @param user User.
 */
void changeAddress(Company& comp, User& user){
	string name;
	do{
		cout << "Indique a nova Morada(id) para a conta" << endl;
		getline(cin, name);
	}while(testInputNif(comp, name));

	user.setAddressId(stoi(name));
}

/**
 * @brief Change User account.
 *
 * @param comp Company.
 * @param user User.
 */
void changeAccount(Company& comp,User & user){
	int option = 0;
	string ss;
	while (option != 3) {
		do{
			cout << "Modificar conta de Cliente" << endl;

			cout << "1 - Modificar o Nome da conta" << endl
					<<"2 - Modificar a Morada" << endl
					<<"3 - Sair" << endl;

			getline(cin,ss);
		}while((ss.size()==0));
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
	}

}

/**
 * @brief Delete User account.
 *
 * @param comp Company.
 * @param user User.
 */
void eliminateAccount(Company comp, User u){
	vector<User>& users =comp.getSupermarket().getUsers();

	for (unsigned int i =0; i<users.size(); i++){
		if (users[i].getNif()==u.getNif()){
			users.erase(users.begin()+i);
		}
	}
}

/**
 * @brief Gets the User menu.
 *
 * @param comp Company.
 * @param user User.
 */
void areaCliente(Company& comp, User& user){
	int option = 0;
	string ss;
	while (option != 4) {
		do{
			cout << "Bem-vindo a tab dos Clientes, "<<user.getNif()<< "!" << endl;

			cout 	<< "1 - Modificar Conta" << endl
					<< "2- Eliminar Conta" << endl
					<< "3 - Ver perfil" << endl
					<< "4- Sair" << endl;

			getline(cin,ss);
		} while((ss.size()==0));
		option = stoi(ss);


		switch (option) {
		case 1:
			changeAccount(comp,user);
			break;
		case 2:
			eliminateAccount(comp,user);
			break;
		case 3:
			user.viewProfile();
			break;
		default:
			break;
		}
	}

}

/**
 * @brief Login User.
 *
 * @param comp Company.
 *
 */
void Login(Company comp){
	int nif;
	string ss;
	cout << "Bem-vindo a tab do Login!" << endl;

	do{
		cout << "Introduza o seu nif" << endl;
		getline(cin,ss);
	}while(testInputNif(comp,ss));

	nif = stoi(ss);

	User user = comp.getSupermarket().findUserFromNif(nif);

	if (user.getNif()==0){
		cout<<" Nao se encontra registado! Por favor, efetue o registo!"<< endl;
	}
	else
	{
		areaCliente(comp,user);
	}



	// PROCURAR CLIENTE NO FILE DE CLIENTES

}


/**
 * @brief Add a new cliet to the company.
 *
 * @param comp Company.
 * @return True if success, otherwise return false.
 */
bool newCliente(Company &comp) {
	string name,temp;
	int nif,id;
	cout << "Indique por favor:" << endl;

	do{
		cout << "O seu nome" << endl;
		getline(cin,name);
	}while(testInputName(comp, name));

	do{
		cout << "O seu nif:" << endl;
		getline(cin,temp);
	}while(testInputNif(comp,temp));
	nif = stoi(temp);
	do{
		cout << "O id da sua morada:" << endl;
		getline(cin,temp);
	}while(testInputNif(comp,temp));
	id = stoi(temp);
	if (!comp.checkIfNodeExist(id)){
		cout << "O id indicado nao se encontra no mapa!"<< endl;
		return false;
	}

	if(comp.getSupermarket().userExists(nif)){
		cout << "Ja se encontra registado!" << endl;
		return false;
	} else{
		User user = User(name,nif,id);
		comp.getSupermarket().addUser(user);
		return true;
	}
}

/**
 * @brief Clients Menu.
 *
 * @param comp Company.
 */
void Clientes(Company& comp){
	int option = 0;
	string ss;
	while (option != 3) {
		cout << "Bem-vindo a tab dos Clientes!" << endl;

		cout << "1 - Registar-se" << endl
				<< "2 - Login" << endl
				<< "3 - Sair." << endl;

		cout << "Insira o numero da sua escolha. Obrigado." << endl;

		getline(cin,ss);
		option = stoi(ss);

		switch (option) {
		case 1:
			newCliente(comp);
			//Registar-se
			break;
		case 2:
			Login(comp);
			break;
		default:
			break;
		}
	}
}

/**
 * @brief Check distribuition.
 *
 * @param comp Company.
 * @param id Id.
 * @return True if success, otherwise return false.
 */
bool checkDistribution(string id,Company comp){
	if(id.size()==0)
		return false;
	if((unsigned int) stoi(id) < comp.getSupermarket().getTrucks().size())
		if((unsigned int)stoi(id) >= 0)
			return true;

	return false;
}

/**
 * @brief Watch distribuition.
 *
 * @param comp Company.
 *
 */
void watchDistribuition(Company &comp){
	string id;
	comp.getSupermarket().printAllTrucks();
	do{
		cout << "Indique, por favor, o id do camiao!"<< endl;
		getline(cin,id);
	}while(!checkDistribution(id,comp));
	comp.getSupermarket().displayOrdersFromTruck(stoi(id));
	comp.createGraphViewer();
	comp.distribution(stoi(id));
	//ver quais as encomendas nao foram entregues
	Truck truck = comp.getSupermarket().getTrucks()[stoi(id)];
	vector<Order> orders = truck.getOrders();
	for(unsigned int i=0; i <orders.size(); i++){
		if(!orders[i].getDelivery())
			cout << orders[i];
	}
}

/**
 * @brief Change Sueprmarket name.
 *
 * @param comp Company.
 *
 */
void changeNameSuper(Company &comp){
	string name;
	do{
		cout << "Indique o novo nome do Supermercado" << endl;
		getline(cin, name);
	}while(testInputName(comp, name));

	comp.getSupermarket().setName(name);
}

/**
 * @brief Change Sueprmarket address.
 *
 * @param comp Company.
 *
 */
/*
void changeAddressSuper(Company &comp){
	string name;
	do{
		cout << "Indique a nova morada(id) do Supermercado" << endl;
		getline(cin, name);
	}while(name.size()==0);

	if(comp.checkIfNodeExist(stoi(name))){
		comp.getSupermarket().setIdSuper(stoi(name));
	}else {
		cout << "A morada nao se encontra no mapa!" << endl;
		return;
	}
}*/

/**
 * @brief Check set capacity.
 *
 * @param comp Company.
 * @param id Id.
 * @param cap Capacity.
 *
 * @return True if success, otherwise return false.
 */
bool checkSetCapacity(Company &comp, string id, string cap){

	if(comp.getSupermarket().setCapacityToTruck(stoi(cap),stoi(id)))
		return false;
	if((unsigned int) stoi(id) < comp.getSupermarket().getTrucks().size())
		if((unsigned int) stoi(id) >= 0)
			return true;

	return false;
}

/**
 * @brief Change Truck capacity.
 *
 * @param comp Company.
 *
 */
void changeCapacity(Company& comp){
	string id,cap;
	comp.getSupermarket().printAllTrucks();
	do{
		do{
			cout << "Indique, por favor, o id do camiao a modificar!"<< endl;
			getline(cin,id);
		}while(!checkDistribution(id,comp));

		do{
			cout << "Indique a capacidade maxima" << endl;
			getline(cin,cap);
		}while(testInputNif(comp,cap));
	}while(checkSetCapacity(comp, id, cap));
}

/**
 * @brief Check maximum.
 *
 * @param comp Company.
 * @param id Id.
 * @param cap Capacity.
 *
 * @return True if success, otherwise return false.
 */
bool checkMax(Company & comp, string id, string cap){
	if(comp.getSupermarket().setCapacityToTruck(stoi(cap),stoi(id)))
		return true;
	if((unsigned int) stoi(id) < comp.getSupermarket().getTrucks().size())
		if((unsigned int) stoi(id) >= 0)
			return true;

	return false;
}


/**
 * @brief Change maximum distance.
 *
 * @param comp Company.
 *
 */
void changeMaxDist(Company& comp){
	string id,cap;
	comp.getSupermarket().printAllTrucks();
	do{
		do{
			cout << "Indique, por favor, o id do camiao a modificar!"<< endl;
			getline(cin,id);
		}while(id.size()==0);
		do{
			cout << "Indique a distancia maxima" << endl;
			getline(cin,cap);
		}while(cap.size()==0);
	}while(!checkMax(comp, id, cap));
}

/**
 * @brief Change trucks.
 *
 * @param comp Company.
 *
 */
void changeTrucks(Company &comp){
	int option = 0;
	string ss;
	while (option != 3) {
		do{

			cout << "1 - Modificar a capacidade maxima do camiao " << endl
					<< "2 - Modificar a distancia maxima percorrida pelo camiao"
					<< endl << "3 - Sair."
					<< endl;
			cout << "Insira o numero da sua escolha. Obrigado." << endl;
			getline(cin, ss);
		}while(!checkDistribution(ss, comp));
		option = stoi(ss);
		switch (option) {
		case 1:
			changeCapacity(comp);
			break;
		case 2:
			changeMaxDist(comp);
			break;
		default:
			break;
		}
	}
}

/**
 * @brief Admin Menu.
 *
 * @param comp Company.
 *
 */
void adminSuper(Company& comp){
	int option = 0;
	string ss;
	while (option != 4) {
		do{

			cout << "Bem-vindo ao tab de administracao do " <<comp.getSupermarket().getName() << endl;
			cout << "1 - Mudar o Nome do Supermercado " << endl << "2 - Modificar o local do Supermercado"
					<< endl << "3 - Modificar Camioes" << endl << "4 - Sair."
					<< endl;
			cout << "Insira o numero da sua escolha. Obrigado." << endl;
			getline(cin, ss);
		}while((ss.size()==0));
		option = stoi(ss);
		switch (option) {
		case 1:
			changeNameSuper(comp);
			break;
		case 2:
			//changeAddressSuper(comp);
			cout << "Nao e possivel alterar a morada do supermercado atualmente." << endl;
			break;
		case 3:
			changeTrucks(comp);
			break;
		default:
			break;
		}
	}
}

/**
 * @brief User interface menu.
 *
 * @param comp Company.
 *
 */
void interfUser(Company& comp) {
	int option = 0;
	string ss;
	while (option != 4) {
		do{
			cout << "Bem-vindo ao Super Precos Baixos!!" << endl;
			cout << "1 - Clientes " << endl << "2 - Distribuicao de entregas"
					<< endl << "3 - Administrar Supermercado" << endl << "4 - Sair."
					<< endl;
			cout << "Insira o numero da sua escolha. Obrigado." << endl;
			getline(cin, ss);
		}while(ss.size()==0);
		option = stoi(ss);
		switch (option) {
		case 1:
			Clientes(comp);
			break;
		case 2:
			watchDistribuition(comp);
			break;
		case 3:
			adminSuper(comp);
			break;
		default:
			break;
		}
	}
}

/**
 * @brief Save users informations.
 *
 * @param comp Company.
 *
 */
void saveUsers(Company comp){
	ofstream users;
	users.open ("users.txt");
	if (!users) {
		cerr << "Unable to open file users.txt";
		return;
	}

	vector<User> vecUsers = comp.getSupermarket().getUsers();
	for(unsigned int i = 0; i< vecUsers.size(); i++){
		users << vecUsers[i].getName() << ";" << vecUsers[i].getNif() << ";" << vecUsers[i].getAddressId() << ";"<< endl;
	}
	users.close();
}

/**
 * @brief Save delieveries informations.
 *
 * @param comp Company.
 *
 */
void saveDeliveries(Company comp){
	ofstream file;
	file.open ("delivery.txt");
	if (!file) {
		cerr << "Unable to open file delivery.txt";
		return;
	}

	vector<Truck> trucks = comp.getSupermarket().getTrucks();
	for(unsigned int i = 0; i< trucks.size(); i++){
		vector<Order> orders = trucks[i].getOrders();
		for(unsigned int j = 0; j< orders.size();j++){
			file << orders[j].getId() << ";" << orders[j].getWeight() << ";" << orders[j].getDate() << endl;
		}
	}
	file.close();
}

/**
 * @brief Save files.
 *
 * @param comp Company.
 *
 */
void saveFiles(Company& comp){
	saveUsers(comp);
	saveDeliveries(comp);
}

bool stringInterface(){
	string name;
	cout << "Insira o nome de uma rua " << endl;
	getline(cin,name);
	int n = numStringMatching("roads.txt",name);
	cout << "n " << n << endl;
	int pesqAprox;

	if(n == 0){//nao existe nenhuma rua com esse nome
		//separar os nomes das ruas de cada road e comparar com name
		//comp.pesquisaAproximada(name);
	}else{//existe pelo menos uma rua com esse nome

	}
return false;
}

void checkifSupermarket(Company &cmp){
	//pesquisar nos vertices cujas edges pertencem ao idRua da rua indicada
	//e ver se corresponde a um idSupermercado ou nao
	//vector<Vertex<Info>*> vertex =cmp.getGraph().getVertexSet();

	for(unsigned int i = 0; i< cmp.getRoads().size(); i++){
		cout << "Road name: "  << cmp.getRoads().at(i).getName() << " id Rua " <<cmp.getRoads().at(i).getId() << endl;
	}
	/*
	for(unsigned int i = 0; i < vertex.size();i++{
			vector<Edge<Info>> adj = vertex[i].getAdj();
			for(unsigned int j = 0; j < adj.size();j++){
				//adj[j].getIdRua();
			}

	}*/
}



int main() {
	Company comp = Company();
	comp.readMaps();
	comp.readDeliveries();
	comp.readUsers();
	stringInterface();
	//checkifSupermarket(comp);
     //ve se existe um supermercado no cruzamento da rua indicado
	//interfUser(comp);
	//saveFiles(comp);
	comp.createGraphViewer();

	getchar();
	return 0;
}
