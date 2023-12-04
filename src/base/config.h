#ifndef INF112_CONFIG_H
#define INF112_CONFIG_H
#include <string>

std::string dbname = "paiva";
std::string user = "postgres";
std::string password = "Joaogalo2020";
std::string host = "localhost";
std::string port = "5432";

std::string conninfo = "dbname=" + dbname + " user=" + user + " password=" + password + " host=" + host + " port=" + port;

#endif