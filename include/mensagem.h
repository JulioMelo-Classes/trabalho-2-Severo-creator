#include <iostream>

#include "Usuario.h"

class mensagem
{
private:
  unsigned int ID;
  std::string Data_hora;
  Usuario* enviada_por;
  std::string conteudo;
public:
  mensagem(/* args */);
  ~mensagem();
};

mensagem::mensagem(/* args */)
{
}

mensagem::~mensagem()
{
}
