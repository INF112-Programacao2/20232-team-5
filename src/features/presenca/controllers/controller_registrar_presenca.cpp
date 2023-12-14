#include "controller_registrar_presenca.h"
#include <ctime>

// Construtor
ControllerRegistrarPresenca::ControllerRegistrarPresenca(Session *session, DataPresenca *dataPresenca, DataModalidade *dataModalidade, DataTurma *dataTurma, DataAluno *dataAluno)
{
    // Inicializa os atributos
    _session = session;
    _dataPresenca = dataPresenca;
    _dataModalidade = dataModalidade;
    _dataTurma = dataTurma;
    _dataAluno = dataAluno;
}

std::vector<Turma *> ControllerRegistrarPresenca::ListarTurmasUsuario(int idUsuario)
{
    std::cout << "Listando turmas do usuário " << idUsuario << std::endl;
    // Busca as modalidades do usuário
    std::vector<Modalidade *> modalidades = _dataModalidade->buscaListaModalidadesUsuario(idUsuario);
    std::vector<Turma *> turmas;

    // Busca as turmas de cada modalidade
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

    // Desaloca as modalidades
    for (int i = 0; i < modalidades.size(); i++)
        delete modalidades[i];

    return turmas;
}

std::vector<Turma *> ControllerRegistrarPresenca::ListarTurmasUsuarioLogado()
{    // Retorna a lista de turmas do usuário atualmente logado
    return ListarTurmasUsuario(_session->getUsuario()->getChaveUsu());
}

// Método para registrar a presença do usuário logado
RetornoController ControllerRegistrarPresenca::registrarPresencaUsuarioLogado()
{
    // Obtém a lista de turmas do usuário logado
    std::vector<Turma *> turmas = ListarTurmasUsuarioLogado();

    // Se o usuário não tem turmas (ou seja, aulas) hoje, informa o usuário e retorna
    if (turmas.size() == 0)
    {
        std::cout << "Você não possui aulas hoje!" << std::endl;
        return RetornoController::Completo;
    }

    // Variável para armazenar a opção do usuário
    int opt = 1;
    // Informa ao usuário as aulas disponíveis hoje
    std::cout << "Aulas disponíveis hoje:" << std::endl;
    // Itera sobre as turmas e imprime as opções para o usuário
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

    // Entra em um loop até que o usuário digite uma opção válida
    while (opt < 1 || opt > turmas.size())
    {
        std::cout << "Digite o número da turma que deseja registrar presença: ";
        // Lê a opção do usuário
        std::cin >> opt;
    }

    // Busca o aluno correspondente ao usuário logado e à turma selecionada
    Aluno *aluno = _dataAluno->buscaAlunoByUsuario(_session->getUsuario()->getChaveUsu(), turmas[opt - 1]->getChaveMod());

    // Registra a presença do aluno na turma selecionada
    _dataPresenca->RegistrarPresenca(turmas[opt - 1]->getChaveTur(), aluno->getChaveAlu());

    std::cout << "Presença registrada com sucesso!" << std::endl;

    // Libera a memória alocada para o aluno
    delete aluno;

    // Libera a memória alocada para cada turma
    for (int i = 0; i < turmas.size(); i++)
        delete turmas[i];
        
    return RetornoController::Completo;
}