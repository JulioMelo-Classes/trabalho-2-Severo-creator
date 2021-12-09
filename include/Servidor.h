#ifndef Servidor_h //essa proteção é necessária em C/C++ para evitar inclusão duplicada do arquivo
#define Servidor_h

#include <iostream>

//#include "Canal_texto.h" removi pois não precisa pro checkin 3
#include "Usuario.h" //precisei colocar

//vc precisa separar implementação de .hpp
class Servidor
{
private:
  unsigned int ID;
  std::string codigo_convite = "";
  std::string nome;
  std::string descricao;
  std::vector<Usuario*> integrantes;//precisa do std::
  //std::vector<Canal_texto> canais; //removi pq não precisa pro checkin 3
  Usuario* dono;
  

public:
  Servidor(unsigned int id, std::string Nome, Usuario* DONO);
  
  unsigned int retorna_id();
  void set_desc(const std::string descricao);
  std::string retorna_nome();
  void set_ID(int inteiro);
  void modifica_convite(std::string novo);
};

//essa parte aqui fica em Servidor.cpp, vc precisa atualizar o CMakeLists para incluir Servidor.cpp na compilação
Servidor::Servidor(unsigned int id, std::string Nome, Usuario* DONO)
{
  ID = id;
  nome = Nome;
  dono = DONO;
}


unsigned int Servidor::retorna_id(){
  return ID;
}

void Servidor::set_desc( const std::string descricao){
  
  this->descricao = descricao;
  
  }

void Servidor::set_ID(int inteiro){
  this->ID = inteiro ;
}

std::string Servidor::retorna_nome(){
return nome;
}

void  Servidor::modifica_convite(std::string novo){
  codigo_convite = novo;
}

#endif