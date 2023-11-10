cmake_minimum_required(VERSION 3.0.0)
project(tpfinal VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(sources
  main.cpp
  base/controller.h
  base/global.h
  base/global.cpp
  base/menu.h
  base/menu.cpp
  base/opcao_menu.h
  base/opcao_menu.cpp
  base/controller_sair.h
  base/controller_sair.cpp
  base/controller_voltar.h
  base/controller_voltar.cpp
  menus/menu_inicial.h
  menus/menu_inicial.cpp
  controllers/controller_login.h
  controllers/controller_login.cpp
)

set (dirs
  base
  controllers
  menus
  usecases
)

add_executable(tpfinal ${sources})

target_include_directories(tpfinal PRIVATE ${dirs})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)