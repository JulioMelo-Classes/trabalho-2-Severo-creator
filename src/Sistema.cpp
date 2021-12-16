#include "Sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;


#include <iostream>
#include <sstream>
#include <algorithm>

int gera_id_usuario(std::vector<Usuario*> vtr, int base){
	int check = 0;
 for(auto i : vtr){
	 if(i->retorna_ID() == base){
		 check = 1;
	 }
 }
 if(check == 1){
	 return gera_id_usuario(vtr, base + 1);
 }else{
	 return base;
 }
}

int gera_id_server(std::vector<Servidor> vtr, int base){
	int check = 0;
 for(auto i : vtr){
	 if(i.retorna_id() == base){
		 check = 1;
	 }
 }
 if(check == 1){
	 return gera_id_server(vtr, base + 1);
 }else{
	 return base;
 }
}

/* COMANDOS */
string Sistema::quit() {
  return "Saindo...";
}

string Sistema::create_user (const string email, const string senha, const string nome) {
	int id_user = gera_id_usuario(Usuarios, 1);
	Usuario *new_usuario = new Usuario(email, senha, nome, id_user);
	this->Usuarios.push_back(new_usuario);
	string str;
	str = "user_created";
	str += email;
	str += " ";
	str += senha;
	str += " ";
	str += nome;
	return str;
	
}

std::string Sistema::delete_user (const std::string email, const std::string senha){
	for(int i = 0; i < Usuarios.size(); i ++){
		if(Usuarios[i]->retorna_email() == email && Usuarios[i]->retorna_senha() == senha){
		 // erase(Usuarios, *Usuarios[i]);

			/*Logados[Usuarios[i]->retorna_ID()].first = 0;
			Logados[Usuarios[i]->retorna_ID()].second = 0;
			Logados.erase(Usuarios[i]->retorna_ID());*/
			if (Logados.find(Usuarios[i]->retorna_ID()) != Logados.end()){
				
				return "Erro... Usuario logado!";
			}
			vector<Usuario*>::iterator usr;
			usr = Usuarios.begin() + i;
			Usuarios.erase(usr);
			string str = "deleted_user " + email;
			return str;
		}
	}


	return "delete_user NÃO IMPLEMENTADO";
}

string Sistema::login(const string email, const string senha) {
	for(int i = 0; i < Usuarios.size(); i ++){
	if(Usuarios[i]->retorna_email() == email && Usuarios[i]->retorna_senha() == senha){
		if (Logados.find(Usuarios[i]->retorna_ID()) != Logados.end()){
			return "Já logado.";
		}
		Logados[Usuarios[i]->retorna_ID()].first = 0;
		Logados[Usuarios[i]->retorna_ID()].second = 0;
		string str;
		str = "login de " + email;
		return str;
	}
	}
	return "login NÃO IMPLEMENTADO";
}

string Sistema::disconnect(int id) {
	if (Logados.find(id) != Logados.end()){
		Logados.erase(id);
		return "disconnect(1)...";
	}
	return "disconnect NÃO IMPLEMENTADO";
}

string Sistema::create_server(int id, const string nome) {
	//checa se id em questão existe//
	if (Logados.find(id) == Logados.end()){
		return"Usuario não logado";
	}
	//faz um ponteiro para o usuario que esta criando o servidor//
	Usuario* DON;
	for(auto check : Usuarios){
		if(check->retorna_ID() == id){
			DON = check;
			break;
		}
	}
	//vê se o nome do servidor já não existe//
	vector<Servidor>::iterator It;
	for(It = servers.begin(); It != servers.end(); It ++){
		if(It->retorna_nome() == nome){
			return "Já existe server " + nome;
		}
		
	}
	//chama a função para procurar um id válido para o servidor//
	int id_server = gera_id_server(servers , 1);
	
 //salva o servidor no vetor//;
	Servidor server =  Servidor(id_server, nome, DON);
	servers.push_back(server);

	//Dono entra no servidor//
		Logados[id].first = id_server;
		Logados[id].second = 0;
		enter_server(id, nome, "");

	string str;
	str = "create_server " + nome;
	return str;
	return "create_server NÃO IMPLEMENTADO";
}

string Sistema::set_server_desc(int id, const string nome, const string descricao) {
	vector<Servidor>::iterator It;
		if (Logados.find(id) == Logados.end()){
		return"Usuario não logado";
	}

	
	for(It = servers.begin(); It != servers.end(); It ++){
		if(It->retorna_nome() == nome){
			int  a = 0;
			for(auto check : Usuarios){
				if(check->retorna_ID() == It->retorna_dono().retorna_ID()){
					a = 1;
				}
			}
			if(a != 1){
				return "Usuario não é o dono";
			}

			It->set_desc(descricao);
			return "set_server_desc " + nome;
		}
	}
	
	return "set_server_desc NÃO Encontrado";
}

string Sistema::set_server_invite_code(int id, const string nome, const string codigo) {
	vector<Servidor>::iterator It;
		if (Logados.find(id) == Logados.end()){
		return"Usuario não logado";
	}


	for(It = servers.begin(); It != servers.end(); It ++){
		if(It->retorna_nome() == nome){
			int a = 0;
			for(auto check : Usuarios){
				if(check->retorna_ID() == It->retorna_dono().retorna_ID()){
					a = 1;
				}
			}
			if(a != 1){
				return "Usuario não é o dono";
			}
			
			It->modifica_convite(codigo);
				return "set_server_invite_code " + nome;
		}
	
	}

	return "set_server_invite_code NÃO IMPLEMENTADO";
}

string Sistema::list_servers(int id) {
	vector<Servidor>::iterator It;
	if (Logados.find(id) == Logados.end()){
		return"Usuario não logado";
	}else if(servers.size() == 0){
		return "Erro do comando";
	}
	for(It = servers.begin(); It < servers.end(); It ++){
		cout << "Server: " << It->retorna_nome() << " ID: " << It->retorna_id() <<" "<< It->retorna_descricao() << endl;
	}
  return "list of servers " ;
}

string Sistema::remove_server(int id, const string nome) {
	
	//checa se usuario esta logado//
	if (Logados.find(id) == Logados.end()){
		return"Usuario não logado";
	}else if(servers.size() == 0){
		return "Erro do comando";
	}
	
	//vê se existe o servidor, retira todos os usuarios logados nele e vê se o id é do dono//
	vector<Servidor>::iterator It;
	for(It = servers.begin(); It < servers.end(); It ++){
		if(It->retorna_nome() == nome){
			if (It->retorna_dono().retorna_ID() != id)
			{
				return "Usuario não é o dono";
			}
			
			for(auto ptr : Usuarios){
				if(Logados.find(ptr->retorna_ID()) != Logados.end()){
					if(Logados[ptr->retorna_ID()].first == It->retorna_id()){
						Logados[ptr->retorna_ID()].first = 0;
						Logados[ptr->retorna_ID()].second = 0;
					}
				}
			}
			servers.erase(It);
			return "removed_server " + nome;
			break;
		}
	}
	return "remove_server NÃO IMPLEMENTADO";
}

string Sistema::enter_server(int id, const string nome, const string codigo) {
	
	
	if (Logados.find(id) == Logados.end()){
		return"Usuario não logado";
	}else if(servers.size() == 0){
		return "Erro do comando";
	}
	//vê se o server existe , checa se o codigo foi preenchido esalva os valores no map//
	for(auto &check : servers){
		if(check.retorna_nome() == nome){
			if(check.esta_em(id) == true){
				Logados[id].first = check.retorna_id();
				Logados[id].second = 0;
			}else{
				if(check.retorna_codigo().size() > 0){
					
					if(codigo == check.retorna_codigo()){
						
						Logados[id].first = check.retorna_id();
						Logados[id].second = 0;
						for( auto i : Usuarios){
							if(id = i->retorna_ID()){
								check.add_user(i);
							}
						}
						return "id in " + nome;
					
					}else{
						
						return "Codigo invalido";
					}
					
				}else{
					Logados[id].first = check.retorna_id();
					Logados[id].second = 0;
					for( auto i : Usuarios){
						if(id = i->retorna_ID()){
							check.add_user(i);
						}
					}
					return "id in " + nome + " sem codigo";
				}
			}
		}
	}
	
	return "enter_server NÃO IMPLEMENTADO";
}

string Sistema::leave_server(int id, const string nome) {
	if (Logados.find(id) == Logados.end()){
		return"Usuario não logado";
	}else if(servers.size() == 0){
		return "Erro do comando";
	}
	/*for(auto check : servers){
		
		if(nome == check.retorna_nome()){
			if(check.retorna_id() == Logados[id].first){
				Logados[id].first = 0;
				Logados[id].second = 0;
				
				return "id saiu de " + nome;
			}
		}
	}*/
	vector<Servidor>::iterator It;
	for(It = servers.begin(); It < servers.end(); It ++){
		
		if(nome == It->retorna_nome()){
			
			Logados[id].first = 0;
			Logados[id].second = 0;
			It->remover_user(id);
			return "id saiu de" + nome;
			
		}
	}

	return "leave_server NÃO EXISTE";
}

string Sistema::list_participants(int id) {
	if (Logados.find(id) == Logados.end()){
		return"Usuario não logado";
	}else if(servers.size() == 0){
		return "Erro do comando";
	}
	if(Logados[id].first > 0){
		for(auto &check : servers){
			if(check.retorna_id() == Logados[id].first){
				cout << "lista de todos os players:" << endl;
				cout << check.Lista_de_integrantes() << endl;
				return ".";
			}
		}
	}
	return "list_participants NÃO IMPLEMENTADO";
}

string Sistema::list_channels(int id) {
	if (Logados.find(id) == Logados.end()){
		return"Usuario não logado";
	}else if(servers.size() == 0){
		return "Erro do comando";
	}

	if(Logados[id].first > 0){
		for(auto &check : servers){
			if(check.retorna_id() == Logados[id].first){
				cout << check.Lista_de_canais() << endl;
				return "Lista";
			}
		}
	}
	return "NÃO LOGADO";
}

string Sistema::create_channel(int id, const string nome) {
	if (Logados.find(id) == Logados.end()){
		return"Usuario não logado";
	}else if(servers.size() == 0){
		return "Erro do comando";
	}

	if(Logados[id].first > 0){
		for(auto &check : servers){
			if(check.retorna_id() == Logados[id].first){
				if(check.retorna_channel(nome) == false){
					for(auto i : Usuarios){
						if(i->retorna_ID() == id){
							check.create_channel(nome, i);
							this->enter_channel(id, nome);
							return " canal " + nome +" criado";
						}
					}
				}else{
					return "JA EXISTE";
				}
			}
		}
	}
	return "ID SEM SERVER";
}

string Sistema::remove_channel(int id, const string nome) {
		if (Logados.find(id) == Logados.end()){
		return"Usuario não logado";
	}else if(servers.size() == 0){
		return "Erro do comando";
	}

	if(Logados[id].first > 0){
		for(auto &check : servers){
			if(check.retorna_id() == Logados[id].first){
				string str = check.remove_channel(nome, id);
				return str;
			}
		}
	}
	return "ID SEM SERVER";
}

string Sistema::enter_channel(int id, const string nome) {
	if (Logados.find(id) == Logados.end()){
		return"Usuario não logado";
	}else if(servers.size() == 0){
		return "Erro do comando";
	}

	if(Logados[id].first > 0){
		for(auto &check : servers){
			if(check.retorna_id() == Logados[id].first){
				if(check.retorna_id_canal(nome) == 0){
					return "CANAL NÃO EXISTE";
				}else{
					Logados[id].second =  check.retorna_id_canal(nome);
					return "entrou em" + nome;
				}
			}
		}
	}

	return "NAO ESTA NO SERVIDOR";
}

string Sistema::leave_channel(int id) {
	if (Logados.find(id) == Logados.end()){
		return"Usuario não logado";
	}else if(servers.size() == 0){
		return "Erro do comando";
	}

	if(Logados[id].first > 0){
		for(auto &check : servers){
			if(check.retorna_id() == Logados[id].first){
				if(Logados[id].second == 0){
					return "NAO ESTA EM NENHUM CANAL";
				}else{
					Logados[id].second =  0;
					return "id saiu do canal";
				}
			}
		}
	}

	return "NAO ESTA NO SERVIDOR";
}

string Sistema::send_message(int id, const string mensagem) {
	if (Logados.find(id) == Logados.end()){
		return"Usuario não logado";
	}else if(servers.size() == 0){
		return "Erro do comando";
	}

	if(Logados[id].first > 0){
		for(auto &check : servers){
			if(check.retorna_id() == Logados[id].first){
				if(Logados[id].second == 0){
					return "NAO ESTA EM NENHUM CANAL";
				}else{
					check.send_msg(id, Logados[id].second, mensagem);
					return "mensagem enviada";
				}
			}
		}
	}

	return "NAO ESTA NO SERVIDOR";
}

string Sistema::list_messages(int id) {
		if (Logados.find(id) == Logados.end()){
		return"Usuario não logado";
	}else if(servers.size() == 0){
		return "Erro do comando";
	}

	if(Logados[id].first > 0){
		for(auto &check : servers){
			if(check.retorna_id() == Logados[id].first){
				if(Logados[id].second == 0){
					return "NAO ESTA EM NENHUM CANAL";
				}else{
					cout << check.historico(Logados[id].second) << endl;
					return "^^Historico^^";
				}
			}
		}
	}
	return "NAO ESTA NO SERVIDOR";
}

