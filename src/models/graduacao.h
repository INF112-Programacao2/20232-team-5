#ifndef INF112_GRADUACAO_H
#define INF112_GRADUACAO_H

#include <string>

class Graduacao
{
private:
    int _chaveGrad;
    std::string _nome;
    int ordem;
    int minAulas;

public:
    Graduacao(int chaveGrad, std::string nome, int ordem, int minAulas);

    // Getters
    int getChaveGrad();
    std::string getNome();
    int getOrdem();
    int getMinAulas();

    // Setters
    void setChaveGrad(int chaveGrad);
    void setNome(std::string nome);
    void setOrdem(int ordem);
    void setMinAulas(int minAulas);

};

#endif
