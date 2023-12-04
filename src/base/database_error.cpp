#include "database_error.h"

DatabaseError::DatabaseError(std::string PGErrorMsg) : _PGErrorMsg(PGErrorMsg) {}

const char *DatabaseError::what() const noexcept
{
  return (_PGErrorMsg).c_str();
}