#ifndef Usuario_h //precisa colocar senão vai dar redefinição
#define Usuario_h

#include <iostream>

class Usuario
{
private:
  std::string nome;
  std::string email;
  std::string senha;
  unsigned int ID;
  
public:
  Usuario(std::string em, std::string sen, std::string nome, unsigned int id);
  std::string retorna_nome();
  std::string retorna_email();
  std::string retorna_senha();
  unsigned int retorna_ID();
};

//essa parte aqui fica em Usuario.cpp
Usuario::Usuario(std::string em, std::string sen, std::string nom, unsigned int id)
{
  this->email = em;
  this->senha = sen;
  this->nome = nom;
  this->ID = id;
}
std::string Usuario::retorna_nome(){return nome;
}

std::string Usuario::retorna_email(){
  return email;
}

std::string Usuario::retorna_senha(){
  return senha;
}

unsigned int Usuario::retorna_ID(){
  return ID;
}

#endif