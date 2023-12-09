cmake_minimum_required(VERSION 3.0.0)
project(tpfinal VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(sources
  main.cpp
  base/global.h
  base/global.cpp
  base/config.h
  base/database.h
  base/database.cpp
  base/database_error.h
  base/database_error.cpp
  base/menu.h
  base/menu.cpp
  base/opcao_menu.h
  base/opcao_menu.cpp
  base/session.h
  base/session.cpp
  models/usuario.h
  models/usuario.cpp
  models/aluno.h
  models/aluno.cpp
  models/modalidade.h
  models/modalidade.cpp
  models/cad_pendente.h
  models/cad_pendente.cpp
  models/graduacao.h
  models/graduacao.cpp
  models/turma.h
  models/turma.cpp
  models/enums.h
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
  menus/menu_cadastros.h
  menus/menu_cadastros.cpp
  features/autenticacao/controllers/controller_autenticacao.h
  features/autenticacao/controllers/controller_autenticacao.cpp
  features/autenticacao/data/data_autenticacao.h
  features/autenticacao/data/data_autenticacao.cpp
  features/usuario/menus/menu_opcoes_usuario.h
  features/usuario/menus/menu_opcoes_usuario.cpp
  features/usuario/controllers/controller_usuario.h
  features/usuario/controllers/controller_usuario.cpp
  features/usuario/data/data_usuario.h
  features/usuario/data/data_usuario.cpp
  features/cadastro_pendente/menus/menu_cadastro_pendente.h
  features/cadastro_pendente/menus/menu_cadastro_pendente.cpp
  features/cadastro_pendente/controllers/controller_cadastro_pendente.h
  features/cadastro_pendente/controllers/controller_cadastro_pendente.cpp
  features/cadastro_pendente/data/data_cadastro_pendente.h
  features/cadastro_pendente/data/data_cadastro_pendente.cpp
  features/modalidade/data/data_modalidade.h
  features/modalidade/data/data_modalidade.cpp
  features/modalidade/menus/menu_opcoes_modalidade.h
  features/modalidade/menus/menu_opcoes_modalidade.cpp
  features/modalidade/controllers/controller_modalidade.h
  features/modalidade/controllers/controller_modalidade.cpp
  features/graduacao/controllers/controller_graduacao.h
  features/graduacao/controllers/controller_graduacao.cpp
  features/graduacao/data/data_graduacao.h
  features/graduacao/data/data_graduacao.cpp
  features/turma/controllers/controller_turma.h
  features/turma/controllers/controller_turma.cpp
  features/turma/data/data_turma.h
  features/turma/data/data_turma.cpp
  features/graduacao/menus/menu_opcoes_graduacao.h
  features/graduacao/menus/menu_opcoes_graduacao.cpp
  features/turma/menus/menu_opcoes_turma.h
  features/turma/menus/menu_opcoes_turma.cpp
  features/aluno/data/data_aluno.h
  features/aluno/data/data_aluno.cpp
)

set (dirs
  base
  initializers
  menus
  usecases
  models
  features/autenticacao/controllers
  features/autenticacao/data
  features/usuario/menus
  features/usuario/controllers
  features/usuario/data
  features/cadastro_pendente/menus
  features/cadastro_pendente/controllers
  features/cadastro_pendente/data
  features/modalidade/data
  features/modalidade/menus
  features/modalidade/controllers
  features/graduacao/controllers
  features/graduacao/data
  features/graduacao/menus
  features/turma/controllers
  features/turma/data
  features/turma/menus
  features/aluno/data
)

find_package(PostgreSQL REQUIRED)

add_executable(tpfinal ${sources})

target_link_libraries (tpfinal ${PostgreSQL_LIBRARIES})
target_include_directories(tpfinal PRIVATE ${PostgreSQL_INCLUDE_DIRS} ${PostgreSQL_LIBRARY_DIRS})
target_include_directories(tpfinal PRIVATE ${dirs})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
