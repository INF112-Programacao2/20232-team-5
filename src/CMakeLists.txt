cmake_minimum_required(VERSION 3.0.0)
project(tpfinal VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(sources
  main.cpp
  base/global.h
  base/global.cpp
  base/menu.h
  base/menu.cpp
  base/opcao_menu.h
  base/opcao_menu.cpp
  base/session.h
  base/session.cpp
  models/usuario.h
  models/usuario.cpp
  models/perfil.h
  models/perfil.cpp
  models/aluno.h
  models/aluno.cpp
  models/modalidade.h
  models/modalidade.cpp
  models/cad_pendente.h
  models/cad_pendente.cpp
  models/graduacao.h
  models/graduacao.cpp
  initializers/main_initializer.h
  initializers/main_initializer.cpp
  menus/menu_inicial.h
  menus/menu_inicial.cpp
  menus/menu_cliente.h
  menus/menu_cliente.cpp
  menus/menu_professor.h
  menus/menu_professor.cpp
  menus/menu_administrador.h
  menus/menu_administrador.cpp
  features/autenticacao/controllers/controller_autenticacao.h
  features/autenticacao/controllers/controller_autenticacao.cpp
  features/autenticacao/data/data_autenticacao.h
  features/autenticacao/data/data_autenticacao.cpp
  features/modalidade/data/data_modalidade.h
  features/modalidade/data/data_modalidade.cpp
  features/graduacao/controllers/controller_graduacao.h
  features/graduacao/controllers/controller_graduacao.cpp
  features/graduacao/data/data_graduacao.h
  features/graduacao/data/data_graduacao.cpp
)

set (dirs
  base
  initializers
  menus
  usecases
  models
  features/autenticacao/controllers
  features/autenticacao/data
  features/modalidade/data
  features/graduacao/controllers
  features/graduacao/data
)

add_executable(tpfinal ${sources})

target_include_directories(tpfinal PRIVATE ${dirs})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
