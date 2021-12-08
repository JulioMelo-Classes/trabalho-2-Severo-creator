#include <iostream>

#include "Canal_texto.h"
class Servidor
{
private:
  unsigned int ID;
  std::string codigo_convite = "";
  std::string nome;
  std::string descricao;
  vector<Usuario*> integrantes;
  vector<Canal_texto> canais;
  Usuario* dono;
  

public:
  Servidor(unsigned int id, std::string Nome, Usuario* DONO);
  
  unsigned int retorna_id();
  void set_desc(const std::string descricao);
  std::string retorna_nome();
  void set_ID(int inteiro);
  void modifica_convite(std::string novo);
};

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