#include "controller_registrar_presenca.h"
#include <ctime>

ControllerRegistrarPresenca::ControllerRegistrarPresenca(Session *session, DataPresenca *dataPresenca, DataModalidade *dataModalidade, DataUsuario *dataUsuario, DataPerfil *dataPerfil, DataTurma *dataTurma)
{
    _session = session;
    _dataPresenca = dataPresenca;
    _dataModalidade = dataModalidade;
    _dataUsuario = dataUsuario;
    _dataPerfil = dataPerfil;
}

std::vector<Turma*> ControllerRegistrarPresenca::ListarTurmasUsuario(int idUsuario)
{
    Usuario *usuario = _dataUsuario->buscaUsuarioByChave(idUsuario);
    std::vector<Modalidade *> modalidades = _dataModalidade->buscaListaModalidadesUsuario(usuario->getChaveUsu());
    std::vector<Turma *> turmas; 
    
    for(Modalidade *modalidade : modalidades)
    {
        std::vector<Turma *> turmasModalidade = _dataTurma->buscaTurmasModalidade(modalidade->getChaveMod());
        
        for(Turma *turma : turmasModalidade)
        {
            turmas.push_back(turma);
        }
    }

    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    int hoje = now->tm_wday + 1;

    // Remove as turmas que não tem aula hoje
    for(int i = 0; i < turmas.size(); i++)
    {
        if (turmas[i]->getDiasSemana().find(std::to_string(hoje)) == std::string::npos)
        {
            turmas.erase(turmas.begin() + i);
            i--;
        }
    }

    return turmas;
}

std::vector<Turma*> ControllerRegistrarPresenca::ListarTurmasUsuarioLogado()
{
    return ListarTurmasUsuario(_session->getSelectedUsuario()->getChaveUsu());     
}

RetornoController ControllerRegistrarPresenca::registrarPresencaUsuarioLogado()
{
    std::vector<Turma*> turmas = ListarTurmasUsuarioLogado();
    int opt = 1;

    if (turmas.size() == 0)
    {
        std::cout << "Você não possui aulas hoje!" << std::endl;
        return RetornoController::Completo;
    }
    
    std::cout << "Aulas disponíveis hoje:" << std::endl;
    for(Turma *turma : turmas)
    {
        // descobrir a hora atual
        std::time_t HoraAtual = std::time(nullptr); 

        // Se a hora atual estiver entre a hora de início e fim da aula + 1 hora, recomenda a aula
        if (HoraAtual >= turma->getHrInicioTime() && HoraAtual <= turma->getHrFimTime() + 3600)
        {
            std::cout << "Turma: " << opt << " - " << turma->getHrInicio() << " - " << turma->getHrFim() << " Recomendada." << std::endl;
        } else
            std::cout << "Turma: " << opt << " - " << turma->getHrInicio() << " - " << turma->getHrFim() << std::endl;
    
        opt++;
    }

    while (opt < 1 || opt > turmas.size())
    {
        std::cout << "Digite o número da turma que deseja registrar presença: ";
        std::cin >> opt;
    }

    _dataPresenca->RegistrarPresenca(_session->getSelectedUsuario()->getChaveUsu(), turmas[opt - 1]->getChaveTur());

    std::cout << "Presença registrada com sucesso!" << std::endl;
    return RetornoController::Completo;
}