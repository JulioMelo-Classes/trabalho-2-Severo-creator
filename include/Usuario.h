#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>

class Usuario
{
private:
  std::string nome;
  std::string email;
  std::string senha;
  unsigned int ID;
public:
  Usuario(const std::string em,const std::string sen,const std::string nome, unsigned int id);
  unsigned int retorna_ID();
  std::string retorna_email();
  std::string retorna_senha();
  std::string retorna_nome();
};




#endif