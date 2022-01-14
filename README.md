# Base para a atividade 02 de LP1

Use esse esqueleto de classes para iniciar a terceira atividade.

Existe um executor que faz a interpretação dos comandos e executa o método correto do sistema.

## Para compilar

Com makefiles:
```console
mkdir build
make
```

Com cmake:
```console
mkdir build
cd build
cmake ..
cmake --build .
```

Escolha uma das duas formas de build e ignore a outra.

## Para executar
Você pode rodar o sistema e em logo depois digitar os comandos seguidos de ENTER
```console
cd build
./concordo
```

Ou pode criar um arquivo de texto com uma lista de comandos (um por linha) e executar o sistema redirecionando esse arquivo como entrada padrão:
```console
cd build
./concordo < ../data/script_comandos.txt
```

# Avaliação
## Funcionalidades
- A1.2 ok
- A1.3 ok
- A1.4 ok
- A2.1 ok
- A2.2 ok
- A2.3 ok
- A2.4 ok
- A2.5 ok
- A2.6 ok
- A2.7 ok
- A2.8 ok
- A2.9 ok
- B1.1 ok
- B1.2 ok 
- B1.3 ok
- B1.4 ok
- B1.5 ok
- B2.1 ok
- B2.2 ok

## Classes
- Servidor ok
- Canal ok
- Mensagem ok

## Boas Práticas
- Documentação nok
- Testes 50%
Acho que a quantidade de testes poderia ser maior e melhor documentada
- Organização 50%
Mistura de implementações no .h com implementações no .cpp e alguns erros de indentação

## Observações