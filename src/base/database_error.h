#ifndef INF112_DATABASE_ERROR_H
#define INF112_DATABASE_ERROR_H
#include <exception>
#include <string>

class DatabaseError : public std::exception
{
private:
  std::string _PGErrorMsg;

public:
  DatabaseError(std::string PGErrorMsg);
  virtual const char *what() const throw() override;
};

#endif