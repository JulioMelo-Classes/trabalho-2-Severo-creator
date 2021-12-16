#ifndef SERVER_H
#define SERVER_H
#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>

#include "Usuario.h"
#include "Canal.h"
class Servidor
{
private:
  unsigned int ID;
  std::string codigo_convite = "";
  std::string nome;
  std::string descricao;
  std::vector<Usuario*> integrantes;
  std::vector<int> ids_logados;
  std::vector<Canal> canais;
  Usuario* dono;
  

public:
  Servidor(unsigned int id, std::string Nome, Usuario* DONO);
  unsigned int retorna_id();
  std::string retorna_nome();
  void set_desc(const std::string descricao);
  Usuario retorna_dono();
  void modifica_convite(std::string novo);
  std::string retorna_codigo();
  void add_user(Usuario *usr);
  void remove_user(Usuario* user);
  unsigned int id_dono();
  std::vector<Usuario*> retornar_usuarios();
  std::string Lista_de_integrantes();
  std::string Lista_de_canais();
  std::string retorna_descricao();
  int numero_de_integrantes();
  void create_channel(std::string nome, Usuario* id);
  int channels_size();
  std::string  remove_channel(std::string nome, unsigned int id);
  bool retorna_channel(std::string nome);
  void add_user_Canal();
  unsigned int retorna_id_canal(std::string nome);
  void send_msg(unsigned int id_user, unsigned int id_canal, std::string msg);
  std::string historico(unsigned int id_canal);
  bool esta_em(unsigned int id);
  void remover_user(unsigned int id);
};

#endif