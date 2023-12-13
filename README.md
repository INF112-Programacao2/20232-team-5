# 20232-team-5
Esse projeto é um sistema de gerenciamento para uma academia de Artes Marciais para controlar a frequência dos alunos.

## Diagrama UML
![Diagrama Paiva Team](./img/uml_tp_final.jpeg)

## Banco de Dados
Não é preciso realizar nenhuma instalação, pois disponibilizamos uma versão do banco de dados de forma online, através do serviço [ElephantSQL](https://www.elephantsql.com/), e o acesso já está configurado. Ainda assim, caso seja necessário, bastaria instalar o PostgreSQL e executar os arquivos na pasta bd para gerar as tabelas e os dados. Para integrar o app com o servidor local, bastaria alterar os parâmetros em **src/base/config.h**.

## Instalação
- Instalação do CMake
```
sudo apt-get -y install cmake
```
- Entrar na pasta **src**
```
cd src
```
- Criar pasta de build
```
mkdir build
```
## Execução
- Configurar
```
cd build
cmake ..
```
- Compilar
```
cd ../
cmake --build build --config Debug --target all
```
