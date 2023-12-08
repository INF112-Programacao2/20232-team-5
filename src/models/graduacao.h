#ifndef INF112_GRADUACAO_H
#define INF112_GRADUACAO_H

#include <string>

class Graduacao
{
private:
    int _chaveGrd;
    int _chaveMod;
    std::string _nome;
    int ordem;
    int minAulas;

public:
    Graduacao(int chaveGrd, int chaveMod, std::string nome, int ordem, int minAulas);

    // Getters
    int getChaveGrd();
    int getChaveMod();
    std::string getNome();
    int getOrdem();
    int getMinAulas();

    // Setters
    void setChaveGrd(int chaveGrd);
    void setChaveMod(int chaveMod);
    void setNome(std::string nome);
    void setOrdem(int ordem);
    void setMinAulas(int minAulas);
};

#endif
