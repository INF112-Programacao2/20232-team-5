#include "controller_registrar_presenca.h"
#include <ctime>

ControllerRegistrarPresenca::ControllerRegistrarPresenca(Session *session, DataPresenca *dataPresenca, DataModalidade *dataModalidade, DataTurma *dataTurma, DataAluno *dataAluno)
{
    _session = session;
    _dataPresenca = dataPresenca;
    _dataModalidade = dataModalidade;
    _dataTurma = dataTurma;
    _dataAluno = dataAluno;
}

std::vector<Turma *> ControllerRegistrarPresenca::ListarTurmasUsuario(int idUsuario)
{
    std::cout << "Listando turmas do usuário " << idUsuario << std::endl;
    std::vector<Modalidade *> modalidades = _dataModalidade->buscaListaModalidadesUsuario(idUsuario);
    std::vector<Turma *> turmas;

    for (int i = 0; i < modalidades.size(); i++)
        turmas = _dataTurma->buscaTurmasModalidade(modalidades[i]->getChaveMod());

    std::time_t t = std::time(nullptr);
    std::tm *now = std::localtime(&t);
    int hoje = now->tm_wday + 1;

    // Remove as turmas que não tem aula hoje
    for (int i = 0; i < turmas.size(); i++)
    {
        if (turmas[i]->getDiasSemana().find(std::to_string(hoje)) == std::string::npos)
        {
            delete turmas[i];
            turmas.erase(turmas.begin() + i);
            i--;
        }
    }

    for (int i = 0; i < modalidades.size(); i++)
        delete modalidades[i];

    return turmas;
}

std::vector<Turma *> ControllerRegistrarPresenca::ListarTurmasUsuarioLogado()
{
    return ListarTurmasUsuario(_session->getUsuario()->getChaveUsu());
}

RetornoController ControllerRegistrarPresenca::registrarPresencaUsuarioLogado()
{
    std::vector<Turma *> turmas = ListarTurmasUsuarioLogado();

    if (turmas.size() == 0)
    {
        std::cout << "Você não possui aulas hoje!" << std::endl;
        return RetornoController::Completo;
    }

    int opt = 1;
    std::cout << "Aulas disponíveis hoje:" << std::endl;
    for (int i = 0; i < turmas.size(); i++)
    {
        // descobrir a hora atual
        std::time_t HoraAtual = std::time(nullptr);

        // Se a hora atual estiver entre a hora de início e fim da aula + 1 hora, recomenda a aula
        if (HoraAtual >= turmas[i]->getHrInicioTime() && HoraAtual <= turmas[i]->getHrFimTime() + 3600)
        {
            std::cout << opt << ". " << turmas[i]->getHrInicio() << " - " << turmas[i]->getHrFim() << " (Recomendada)" << std::endl;
        }
        else
        {
            std::cout << opt << ". " << turmas[i]->getHrInicio() << " - " << turmas[i]->getHrFim() << std::endl;
        }

        opt++;
    }

    while (opt < 1 || opt > turmas.size())
    {
        std::cout << "Digite o número da turma que deseja registrar presença: ";
        std::cin >> opt;
    }

    Aluno *aluno = _dataAluno->buscaAlunoByUsuario(_session->getUsuario()->getChaveUsu(), turmas[opt - 1]->getChaveMod());
    _dataPresenca->RegistrarPresenca(turmas[opt - 1]->getChaveTur(), aluno->getChaveAlu());

    std::cout << "Presença registrada com sucesso!" << std::endl;
    delete aluno;
    return RetornoController::Completo;
}