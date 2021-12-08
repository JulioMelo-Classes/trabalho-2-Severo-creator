#include "Sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

#include "Sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>

/* COMANDOS */
string Sistema::quit() {
  return "Saindo...";
}

string Sistema::create_user (const string email, const string senha, const string nome) {
	int id_user = Usuarios.size();
	for(int i = 0; i <Usuarios.size() ; i++){
		while(id_user < Usuarios[i].retorna_ID()){
			id_user ++;
		}
	}
	Usuario *new_usuario = new Usuario(email, senha, nome, id_user);
	this->Usuarios.push_back(*new_usuario);
	string str;
	str = "create_user ";
	str += email;
	str += " ";
	str += senha;
	str += " ";
	str += nome;
	return str;
}

std::string Sistema::delete_user (const std::string email, const std::string senha){
	for(int i = 0; i < Usuarios.size(); i ++){
		if(Usuarios[i].retorna_email() == email && Usuarios[i].retorna_senha() == senha){
			Usuarios.erase(Usuarios[i]);
			Logados[Usuarios[i].retorna_ID()].first = NULL;
			Logados[Usuarios[i].retorna_ID()].second = NULL;
			Logados.erase(Usuarios[i].retorna_ID());
			string str = "delete_user " + email;
			return str;
		}
	}
	return "não encontrado...";
}

string Sistema::login(const string email, const string senha) {
	for(int i = 0; i < Usuarios.size(); i ++){
		if(Usuarios[i].retorna_email() == email && Usuarios[i].retorna_senha() == senha){
			Logados[Usuarios[i].retorna_ID()].first = NULL;
			Logados[Usuarios[i].retorna_ID()].second = NULL;
			string str;
			str = "login " + email;
			return str;
		}
	}

	return "login NÃO EXISTE";
}

string Sistema::disconnect(int id) {
	/*for(int i = 0; i < Usuarios.size(); i ++){
		if(Logados[i].retorna_ID() == id ){
			Logados[Usuarios[i].retorna_ID()].first = NULL;
			Logados[Usuarios[i].retorna_ID()].second = NULL;
			Logados.erase(Usuarios[i].retorna_ID());
			string str;
			str = "disconnect " + id;
			return str;
		}
	}*/
	
	if (Logados.find(id) != Logados.end()){
		Logados.erase(id);
		return "disconnect.";
	}
	

	return "disconnect NÃO ENCONTRADO";
}

string Sistema::create_server(int id, const string nome) {
	if (Logados.find(id) != Logados.end()){
		return"Usuario não logado";
	}
	vector<Usuario>::iterator check;
	for(check = Usuarios.begin(); check < Usuarios.end(); check ++){
		if(check->retorna_ID() == id){
			break;
		}
	}
	int id_server = servers.size();
	for(int i = 0; i <servers.size() ; i++){
		while(id_server < servers[i].retorna_id()){
			id_server ++;
		}
	}

	Servidor* server = new Servidor(id_server, nome, &check);
	servers.push_back(*server);

	string str;
	str = "create_server " + nome;
	return str;
}

string Sistema::set_server_desc(int id, const string nome, const string descricao) {
	vector<Servidor>::iterator It;
		if (Logados.find(id) != Logados.end()){
		return"Usuario não logado";
	}
	for(It = servers.begin(); It < servers.end(); It ++){
		if(It->retorna_nome() == nome){
			It->set_desc(descricao);
		}
		return "set_server_desc " + nome;
	}
	
	return "set_server_desc NÃO Encontrado";
}

string Sistema::set_server_invite_code(int id, const string nome, const string codigo) {
	vector<Servidor>::iterator It;
		if (Logados.find(id) != Logados.end()){
		return"Usuario não logado";
	}
	for(It = servers.begin(); It < servers.end(); It ++){
		if(It->retorna_nome() == nome){
			It->modifica_convite(codigo);
		}
		return "set_server_invite_code " + nome;
	}

	return "set_server_invite_code NÃO IMPLEMENTADO";
}

string Sistema::list_servers(int id) {
	vector<Servidor>::iterator It;
		if (Logados.find(id) != Logados.end()){
		return"Usuario não logado";
	}else if(servers.size() == 0){
		return "Erro do comando";
	}
	for(It = servers.begin(); It < servers.end(); It ++){
		cout << "Server: " << It->retorna_nome() << " ID: " << It->retorna_id() << endl;

		
	}
  return "list of servers " ;
}

string Sistema::remove_server(int id, const string nome) {
	vector<Servidor>::iterator It;
	vector<Usuario>::iterator ptr;
		if (Logados.find(id) != Logados.end()){
		return"Usuario não logado";
	}else if(servers.size() == 0){
		return "Erro do comando";
	}

	for(It = servers.begin(); It < servers.end(); It ++){
		if(It->retorna_nome() == nome){
			servers.erase(It);
			return "remove_server " + nome;
			break;
		}
	}

	for(ptr = Usuarios.begin(); ptr < Usuarios.end(); ptr++ ){
		if(Logados.find(ptr->retorna_ID()) != Logados.end()){
			if(Logados[ptr->retorna_ID()].first == It->retorna_id()){
				Logados[ptr->retorna_ID()].first = NULL;
				Logados[ptr->retorna_ID()].second = NULL;
			}
		}
	}


	return "remove_server NÃO IMPLEMENTADO";
}

string Sistema::enter_server(int id, const string nome, const string codigo) {
if (Logados.find(id) != Logados.end()){
		return"Usuario não logado";
	}else if(servers.size() == 0){
		return "Erro do comando";
	}

	vector<Servidor>::iterator It;
		vector<Usuario>::iterator ptr;
	for(ptr = Usuarios.begin(); ptr < Usuarios.end(); ptr++ ){
		if(Logados.find(ptr->retorna_ID()) != Logados.end()){
		if(Logados[ptr->retorna_ID()].first == id){
				Logados[ptr->retorna_ID()].first = NULL;
				Logados[ptr->retorna_ID()].second = NULL;
			}
		}
	}

	return "enter_server NÃO IMPLEMENTADO";
}

string Sistema::leave_server(int id, const string nome) {
	return "leave_server NÃO IMPLEMENTADO";
}

string Sistema::list_participants(int id) {
	return "list_participants NÃO IMPLEMENTADO";
}

string Sistema::list_channels(int id) {
	return "list_channels NÃO IMPLEMENTADO";
}

string Sistema::create_channel(int id, const string nome) {
	return "create_channel NÃO IMPLEMENTADO";
}

string Sistema::remove_channel(int id, const string nome) {
	return "remove_channel NÃO IMPLEMENTADO";
}

string Sistema::enter_channel(int id, const string nome) {
	return "enter_channel NÃO IMPLEMENTADO";
}

string Sistema::leave_channel(int id) {
	return "leave_channel NÃO IMPLEMENTADO";
}

string Sistema::send_message(int id, const string mensagem) {
	return "send_message NÃO IMPLEMENTADO";
}

string Sistema::list_messages(int id) {
	return "list_messages NÃO IMPLEMENTADO";
}

