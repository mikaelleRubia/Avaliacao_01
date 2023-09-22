#include <iostream>
#include <cstring>
#include <vector>
#include <limits>
#include <ctime>
#include <regex>
#include <ctype.h>

using namespace std;

#define ASSENTOS 40
#define MAIOR_IDADE 16
#define ANOSMAXIMO 3 // Anos maximo para criação de Roteiros

struct Data
{
    int dia;
    int mes;
    int ano;
    string data = "";
};

struct Passageiro
{
    string nome;
    string cpf;
    Data dt_nascimento;
    int num_Autorizacao = 0;
    int idade();
};

struct Roteiro
{
    int codigo;
    Data data;
    string Hora;
    string duracao;
    string origem;
    string destino;
};

struct Ocorrencia
{
    string Descricao;
    string data;
    string hora;
    string numero_Apolice;
};

struct Embarque
{
    string cpf_passageiro;
    int codigo_roteiro;
    bool realizada;
    string data;
    string hora;
    int duracao;
    Ocorrencia ocorrencia;
};

int Menu();
int Menu_Passageiros();
int Menu_Alterar_Passageiro(Passageiro);
int Menu_Roteiros();
int Menu_Embarque();
int Menu_Ocorrencia();
int Menu_Alterar_Ocorrencia(Ocorrencia);

// Funções do sistema de Passageiros
Passageiro gerar_passageiro(vector<Passageiro> &);
bool remover_passageiro(vector<Passageiro> &);
void imprimir_passageiro(Passageiro);
void listar_passageiros(vector<Passageiro> &);
int localizar_passageiro(vector<Passageiro> &);
void alterar_passageiro(vector<Passageiro> &);

// Funções do sistema de Roteiros
void Valida_Destino(Roteiro &);
void Valida_Origem(Roteiro &);
Roteiro gerar_Roteiro(vector<Roteiro> &);
bool remover_Roteiro(vector<Roteiro> &);
void imprimir_Roteiro(Roteiro);
void listar_Roteiro(vector<Roteiro> &);
int localizar_Roteiro(vector<Roteiro> &);
void alterar_Roteiro(vector<Roteiro> &);
// Funções do sistema de Embarque
void gerar_Embarque(vector<Embarque> &, string, int);
bool remover_Embarque(vector<Embarque> &embarques, string cpf, int codigo);
void imprimir_Embarque(Embarque);
void listar_Embarques(vector<Embarque> &);
int localizar_Embarque(vector<Embarque> &);
void alterar_Embarque(int, vector<Embarque> &, vector<Passageiro> &);
Passageiro get_passageiro_por_cpf(string, vector<Passageiro> );

//Funções de Ocorrencia
void gerar_ocorrencia(vector<Embarque> &embarques,  Ocorrencia& ocorrencia);
bool remover_ocorrencia( vector<Embarque> &embarques);

// Funções de validação
bool verifica_CPF(string cpf, vector<Passageiro> &passageiros);
bool validarCPF(string cpf);
bool verifica_codigo(int codigo, vector<Roteiro> roteiros);
bool validarData(Data, bool);
Data gera_data(bool);
bool valida_data(string& data);
bool verifica_apolice_cadastro(vector<Embarque> &embarques, string& apolice);


// Funções de utilidades
void limpaTela_pause();
void pause();
void limpaTela();
void limparBuffers();

int main()
{
    // Verifica o sistema operacional para não dar erro
    if (system("echo ''") != 0)
    {
        locale::global(locale(""));
        system("clear");
    }
    else
    {
        setlocale(LC_ALL, "Portuguese");
        system("cls");
    }

    // Variaveis de suporte
    int opcao, opcao2, aux, aux2;
    Passageiro aux_passageiro;
    Roteiro aux_roteiro;
    // vetores
    vector<Embarque> embarques;
    vector<Roteiro> roteiros;
    vector<Passageiro> passageiros;
    Ocorrencia ocorrencias;

    do
    {
        limpaTela();
        opcao = Menu();
        switch (opcao)
        {
        case 1:
            do
            {
                limpaTela();
                opcao2 = Menu_Passageiros();
                limpaTela();
                switch (opcao2)
                {
                case 1:
                    // Criando um passageiro e adicionando no vetor
                    aux_passageiro = gerar_passageiro(passageiros);
                    passageiros.push_back(aux_passageiro);
                    cout << "Passageiro cadastrado com sucesso !" << endl;
                    limparBuffers();
                    pause();
                    break;
                case 2:
                    // chamada da função remover passageiros
                    if (passageiros.empty())
                    {
                        cout << "Nao ha passageiros cadastrados !" << endl;
                    }
                    else
                    {
                        if (remover_passageiro(passageiros))
                        {
                            cout << "Passageiro removido com sucesso !" << endl;
                        }
                        else
                        {
                            cout << "Erro ou Desistencia, ao/da remover/remocao o/do passageiro !" << endl;
                            cout << "CPF inexistente ou CPF digitado Errado !" << endl;
                        }
                    }
                    limparBuffers();
                    pause();
                    break;
                case 3:
                    // chamada da função alterar passageiro
                    if (passageiros.empty())
                    {
                        cout << "Nao ha passageiros cadastrados !" << endl;
                        limparBuffers();
                        pause();
                    }
                    else
                    {
                        alterar_passageiro(passageiros);
                    }
                    break;
                case 4:
                    // chamada da função listar passageiros
                    if (passageiros.empty())
                    {
                        cout << "Nao ha passageiros cadastrados !" << endl;
                    }
                    else
                    {
                        listar_passageiros(passageiros);
                    }
                    limparBuffers();
                    pause();
                    break;
                case 5:
                    // chamada da função localizar passageiro
                    if (passageiros.empty())
                    {
                        cout << "\nNao ha passageiros cadastrados !\n"
                             << endl;
                    }
                    else
                    {
                        aux = localizar_passageiro(passageiros);
                        if (aux != -1)
                        {
                            cout << "\nPassageiro localizado segue os dados: \n"
                                 << endl;
                            cout << "\n=======================================" << endl;
                            imprimir_passageiro(passageiros[aux]);
                            cout << "\n=======================================" << endl;
                        }else{
                            cout << "\nPassageiro nao localizado !" << endl;
                        }
                    }
                    limparBuffers();
                    pause();
                    break;
                case 0:
                    break;
                default:
                    cout << "Opção invalida !" << endl;
                    cout << "Por favor digite uma opcao valida !\n";
                    limparBuffers();
                    pause();
                    break;
                }

            } while (opcao2 != 0);
            break;
        case 2:
            do
            {
                limpaTela();
                opcao2 = Menu_Roteiros();
                limpaTela();
                switch (opcao2)
                {
                case 1:
                    // Criando um roteiro e adicionando no vetor
                    aux_roteiro = gerar_Roteiro(roteiros);
                    roteiros.push_back(aux_roteiro);
                    cout << "Roteiro cadastrado com sucesso !" << endl;
                    pause();
                    break;
                case 2:
                    // chamada da função remover Roteiro
                    if (roteiros.empty())
                    {
                        cout << "Nao ha roteiros cadastrados !" << endl;
                    }
                    else
                    {
                        if (remover_Roteiro(roteiros))
                        {
                            cout << "Roteiro removido com sucesso !" << endl;
                        }
                        else
                        {
                            cout << "Erro ou Desistencia, ao/da remover/remocao o/do roteiro !" << endl;
                            cout << "Codigo inexistente ou digitado Errado !" << endl;
                        }
                    }
                    limparBuffers();
                    pause();
                    break;
                case 3:
                    // chamada da função alterar passageiro
                    if (roteiros.empty())
                    {
                        cout << "Nao ha roteiros cadastrados !" << endl;
                        limparBuffers();
                        pause();
                    }
                    else
                    {
                        alterar_Roteiro(roteiros);
                    }
                    break;
                case 4:
                    // chamada da função listar passageiros
                    if (roteiros.empty())
                    {
                        cout << "Nao ha roteiros cadastrados !" << endl;
                    }
                    else
                    {
                        listar_Roteiro(roteiros);
                    }
                    limparBuffers();
                    pause();
                    break;
                case 5:
                    // chamada da função localizar passageiro
                    if (roteiros.empty())
                    {
                        cout << "Nao ha roteiros cadastrados !" << endl;
                    }
                    else
                    {

                        aux = localizar_Roteiro(roteiros);
                        if(aux != -1){
                        cout << "Roteiro localizado segue os dados: " << endl;
                        cout << "=======================================" << endl;

                        imprimir_Roteiro(roteiros[aux]);

                        cout << "=======================================" << endl;
                        }else{
                            cout << "Roteiro nao localizado !" << endl;
                        }
                    }
                    limparBuffers();
                    pause();
                    break;
                case 0:
                    break;
                default:
                    cout << "Opção invalida !" << endl;
                    cout << "Por favor digite uma opcao valida !\n";
                    break;
                }

            } while (opcao2 != 0);
            break;
        case 3:
            do
            {
                limpaTela();
                opcao2 = Menu_Embarque();

                switch (opcao2)
                {
                case 1:
                    // chamada da função inserir embarque
                    if (passageiros.empty() && roteiros.empty())
                    {
                        cout << "Nao ha passageiros ou roteiros cadastrados !" << endl;
                        limparBuffers();
                        pause();
                    }
                    else
                    {
                        aux = localizar_passageiro(passageiros);
                        aux2 = localizar_Roteiro(roteiros);
                        gerar_Embarque(embarques, passageiros[aux].cpf, roteiros[aux2].codigo);
                        cout << "Embarque cadastrado com sucesso!" << endl;
                        limparBuffers();
                        pause();
                    }
                    break;
                case 2:
                    // chamada da função remover embarque
                    if (embarques.empty())
                    {
                        cout << "Nao ha embarques cadastrados!" << endl;
                    }
                    else
                    {
                        aux = localizar_passageiro(passageiros);
                        aux2 = localizar_Roteiro(roteiros);

                        if (remover_Embarque(embarques, passageiros[aux].cpf, roteiros[aux2].codigo))
                        {
                            cout << "Embarque removido com sucesso!" << endl;
                        }
                        else
                        {
                            cout << "Erro ou Desistencia, ao/da remover/remocao o/do embarque!" << endl;
                            cout << "Codigo e cpf inexistente ou digitados Errados!" << endl;
                        }
                    }
                    limparBuffers();
                    pause();
                    break;
                case 3:
                    // chamada da função alterar embarque
                    cout<<"Digite o codigo do roteiro relacionado ao embarque: " ;
                    cin>>aux;
                    if(verifica_codigo(aux, roteiros))
                        cout<<"Nao existe um roteiro com esse codigo!"<<endl;
                    else{
                        alterar_Embarque(aux, embarques, passageiros);
                    }
                    limparBuffers();
                    pause();
                    break;
                case 4:
                    // chamada da função listar embarque
                    if(embarques.empty()){
                        cout<<"Nao ha embarques cadastrados!"<<endl;
                    } else {
                        listar_Embarques(embarques);
                    }
                    limparBuffers();
                    pause();
                    break;
                case 5:
                    // chamada do Menu de Ocorrencia
                    do
                    {
                        limpaTela();
                        opcao2 = Menu_Ocorrencia();

                        switch (opcao2)
                        {
                        case 1:
                            // chamada da função inserir embarque
                            if (passageiros.empty() && roteiros.empty())
                            {
                                cout << "Nao ha passageiros ou roteiros cadastrados !" << endl;
                                limparBuffers();
                                pause();
                            }
                            else
                            {
                                gerar_ocorrencia(embarques, ocorrencias);

                                limparBuffers();
                                pause();
                            }
                            break;
                        case 2:
                            // chamada da função remover embarque
                            if (embarques.empty())
                            {
                                cout << "Nao ha embarques cadastrados!" << endl;
                            }
                            else
                            {

                                if (remover_ocorrencia(embarques))
                                {
                                    cout << "Embarque removido com sucesso!" << endl;
                                }
                                else
                                {
                                    cout << "Erro ao remover Ocorrencia!" << endl;
                                    cout << "Codigo e cpf inexistente ou digitados Errados!" << endl;
                                }
                            }
                            limparBuffers();
                            pause();
                            break;
                        case 3:
                            // chamada da função alterar embarque
                            break;
                        case 4:
                            // chamada da função listar embarque
                            if(embarques.empty()){
                                cout<<"Nao ha embarques cadastrados!"<<endl;
                            } else {

                            }
                            limparBuffers();
                            pause();
                            break;
                        case 5:
                            // chamada do Menu de Ocorrencia
                            if (embarques.empty())
                            {
                                cout << "Nao ha Embarque cadastrado !" << endl;
                                limparBuffers();
                                pause();
                            }
                            else
                            {
                            }
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opção invalida !" << endl;
                            cout << "Por favor digite uma opcao valida !\n";
                            break;
                        }

                    } while (opcao2 != 0);
                    break;
                case 0:
                    break;
                default:
                    cout << "Opção invalida !" << endl;
                    cout << "Por favor digite uma opcao valida !\n";
                    break;
                }

            } while (opcao2 != 0);
            break;
        case 0:
            // chamada da função
            break;
        default:
            cout << "Opção invalida !" << endl;
            cout << "Por favor digite uma opcao valida !\n";
            limparBuffers();
            pause();
            break;
        }
    } while (opcao != 0);

    return 0;
}

// Funções de utilidades
void pause()
{
    cout << "\nPressione a tecla Enter para continuar...\n";
    cin.clear(); // Limpa quaisquer flags de erro no cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // cin.get(); // Aguarda até que o usuário pressione Enter
}
void limparBuffers()
{
    // Limpa o buffer de entrada do cin
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // Limpa o buffer de saída do cout
    cout.flush();
}
void limpaTela()
{
    cin.clear();

    // Verifica se a variável de ambiente WINDIR está definida (ambiente Windows)
    const char *windir = getenv("WINDIR");

    if (windir != nullptr && strlen(windir) > 0)
    {
        // Se estiver definida, estamos no Windows, então use "cls"
        system("cls");
    }
    else
    {
        // Caso contrário, estamos em um ambiente Unix/Linux, use "clear"
        system("clear");
    }
}
void limpaTela_pause()
{
    pause();
    limpaTela();
}

// Verifica se o CPF é válido
bool validarCPF(string cpf)
{
    // Verifica se o CPF tem 11 dígitos
    if (cpf.size() != 11)
    {
        return false;
    }

    // Converte os dígitos do CPF para inteiros
    int digitos[11];
    for (int i = 0; i < 11; i++)
    {
        if (!isdigit(cpf[i]))
        {
            return false;
        }
        digitos[i] = cpf[i] - '0';
    }

    // Calcula o primeiro dígito verificador
    int soma = 0;
    for (int i = 0; i < 9; i++)
    {
        soma += digitos[i] * (10 - i);
    }
    int primeiroDigito = (soma * 10) % 11;
    if (primeiroDigito == 10)
    {
        primeiroDigito = 0;
    }

    // Verifica o primeiro dígito verificador
    if (primeiroDigito != digitos[9])
    {
        return false;
    }

    // Calcula o segundo dígito verificador
    soma = 0;
    for (int i = 0; i < 10; i++)
    {
        soma += digitos[i] * (11 - i);
    }
    int segundoDigito = (soma * 10) % 11;
    if (segundoDigito == 10)
    {
        segundoDigito = 0;
    }

    // Verifica o segundo dígito verificador
    if (segundoDigito != digitos[10])
    {
        return false;
    }

    // Se todas as verificações passaram, o CPF é válido
    return true;
}
// Verifica se o cpf já foi cadastrado anteriormente
bool verifica_CPF(string cpf, vector<Passageiro> &passageiros)
{
    if (validarCPF(cpf))
    {
        for (Passageiro passageiro : passageiros)
        {
            if (passageiro.cpf == cpf)
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
    return true;
}

// Verifica se a data é válida além de receber a data
// passamos um boolean que indica se é limitado o ano a atual ou não
bool validarData(Data data, bool atual)
{
    // Obter o tempo atual
    time_t tempoAtual = time(nullptr);

    // Converter o tempo atual para uma estrutura tm
    tm *infoTempo = localtime(&tempoAtual);

    // Obter o ano atual (adicione 1900 ao campo tm_year)
    int anoAtual = infoTempo->tm_year + 1900;

    // Verifica se o ano é válido (entre 1900 e o ano atual)
    if (atual)
    {
        if (data.ano < 1900 || data.ano > anoAtual)
        {
            return false;
        }
    }
    else
    {
        if (data.ano < 1900 || data.ano > anoAtual + ANOSMAXIMO)
        {
            return false;
        }
    }

    // Verifica se o mês está dentro do intervalo de 1 a 12
    if (data.mes < 1 || data.mes > 12)
    {
        return false;
    }

    // Verifica o número de dias com base no mês (considerando anos bissextos)
    int diasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // Verifica se é um ano bissexto
    if ((data.ano % 4 == 0 && data.ano % 100 != 0) || (data.ano % 400 == 0))
    {
        diasNoMes[2] = 29; // Fevereiro tem 29 dias em anos bissextos
    }

    // Verifica se o dia está dentro do intervalo válido para o mês
    if (data.dia < 1 || data.dia > diasNoMes[data.mes])
    {
        return false;
    }

    // Se passou por todas as verificações, a data é válida
    return true;
}

Data gera_data(bool atual)
{
    Data data;
    bool valido;
    do
    {
        cout << "Digite o dia: ";
        cin >> data.dia;
        cout << "Digite o mes: ";
        cin >> data.mes;
        cout << "Digite o ano: ";
        cin >> data.ano;
        valido = validarData(data, atual);
        if (!valido)
        {
            limpaTela();
            cout << "Data inválida !!" << endl;
            cout << "Por favor, digite uma data valida!" << endl;
            limparBuffers();
        }
    } while (!valido);
    data.data = to_string(data.dia) + "/" + to_string(data.mes) + "/" + to_string(data.ano);
    return data;
}

// ##########################################################################

// Funções de Menus
int Menu()
{
    cout << "############## Menu ##############\n\n";
    cout << "1 - Gestao de Passageiros \n";
    cout << "2 - Gestao de Roteiros \n";
    cout << "3 - Gestao de Embarquecoes \n";
    cout << "4 - Gestao de Ocorrencias \n";
    cout << "0 - Sair\n";

    int opcao;
    wcout << L"\nEscolha uma opcao: ";
    cin >> opcao;

    return opcao;
}

int Menu_Alterar_Passageiro(Passageiro p)
{
    int opcao;

    cout << "############## Alterar dados de Passageiro ##############\n\n";
    cout << "Passageiro: " << p.nome << "\n\n";
    cout << "CPF: " << p.cpf << "\n\n";
    cout << "Data de Nascimento: " << p.dt_nascimento.data << "\n\n";
    p.num_Autorizacao != 0 ? cout << "Numero de Autorizacao: " << p.num_Autorizacao << "\n\n" : cout << "Numero de Autorizacao: Maior de idade"
                                                                                                     << "\n\n";
    cout << "_____________________________________________________________\n\n";
    cout << "1 - Nome \n";
    cout << "2 - CPF \n";
    cout << "3 - Data de Nascimento \n";
    cout << "4 - Numero de Autorizacao \n";
    cout << "0 - Sair\n";

    cout << "\nEscolha uma opcao: ";
    cin >> opcao;

    return opcao;
}
int Menu_Passageiros()
{
    cout << "############## Menu de Passageiros ##############\n\n";
    cout << "1 - Incluir \n";
    cout << "2 - Excluir\n";
    cout << "3 - Alterar\n";
    cout << "4 - Listar\n";
    cout << "5 - Localizar passageiro via CPF\n";
    cout << "0 - Voltar ao Menu Principal\n";

    int opcao;
    cout << "\nEscolha uma opcao: ";
    cin >> opcao;

    return opcao;
}

int Menu_Roteiros()
{
    cout << "############## Menu de Roteiros ##############\n\n";
    cout << "1 - Incluir \n";
    cout << "2 - Excluir \n";
    cout << "3 - Alterar \n";
    cout << "4 - Listar  \n";
    cout << "5 - Localizar roteiro via codigo\n";
    cout << "0 - Voltar ao Menu Principal    \n";

    int opcao;
    cout << "\nEscolha uma opcao: ";
    cin >> opcao;

    return opcao;
}

int Menu_Embarque()
{
    cout << "############## Menu de Embarque ##############\n\n";
    cout << "1 - Incluir \n";
    cout << "2 - Excluir\n";
    cout << "3 - Alterar\n";
    cout << "4 - Listar\n";
    cout << "5 - Gerencia Ocorrencias\n";
    cout << "0 - Voltar ao Menu Principal\n";

    int opcao;
    cout << "\nEscolha uma opcao: ";
    cin >> opcao;

    return opcao;
}

int Menu_Alterar_Roteiro(Roteiro r)
{
    int opcao;

    cout << "############## Alterar dados de Roteiro ##############\n\n";
    cout << "Codigo: " << r.codigo << "\n\n";
    cout << "Data: " << r.data.data << "\n\n";
    cout << "Hora: " << r.Hora << "\n\n";
    cout << "Duracao: " << r.duracao << "\n\n";
    cout << "Origem: " << r.origem << "\n\n";
    cout << "Destino: " << r.destino << "\n\n";
    cout << "_____________________________________________________________\n\n";
    cout << "1 - Codigo \n";
    cout << "2 - Data \n";
    cout << "3 - Hora \n";
    cout << "4 - Duracao \n";
    cout << "5 - Origem \n";
    cout << "6 - Destino \n";
    cout << "0 - Sair\n";

    cout << "\nEscolha uma opcao: ";
    cin >> opcao;
    return opcao;
}

int Menu_Ocorrencia()
{
    cout << "############## Menu de Ocorrencia ##############\n\n";
    cout << "1 - Incluir \n";
    cout << "2 - Excluir\n";
    cout << "3 - Alterar\n";
    cout << "4 - Listar por Passageiro\n";
    cout << "5 - Listar por Roteiro\n";
    cout << "0 - Voltar ao Menu Principal\n";

    int opcao;
    cout << "\nEscolha uma opcao: ";
    cin >> opcao;

    return opcao;
}

int Menu_Alterar_Ocorrencia(Ocorrencia o)
{
    int opcao;
    cout << "############## Alterar dados de Ocorrencia ##############\n\n";
    cout << "Descricao: " << o.Descricao << "\n\n";
    cout << "Data: " << o.data << "\n\n";
    cout << "Hora: " << o.hora << "\n\n";
    cout << "Codigo: " << o.numero_Apolice << "\n\n";
    cout << "_____________________________________________________________\n\n";
    cout << "1 - Descricao \n";
    cout << "2 - Data \n";
    cout << "3 - Hora \n";
    cout << "4 - Numero de Apolice\n";
    cout << "0 - Voltar ao Menu Ocorrencia\n";

    cout << "\nEscolha uma opcao: ";
    cin >> opcao;

    return opcao;
}
// ###########################################################################

// Funções de gestão de passageiros

void imprimir_passageiro(Passageiro p)
{
    cout << "Nome: " << p.nome << endl;
    cout << "CPF: " << p.cpf << endl;
    cout << "Data de Nascimento: " << p.dt_nascimento.data << endl;
    cout << "Numero de Autorizacao: " << p.num_Autorizacao << endl;
}

int Passageiro::idade()
{
    // Obter o tempo atual
    time_t tempoAtual = time(nullptr);

    // Converter o tempo atual para uma estrutura tm
    tm *infoTempo = localtime(&tempoAtual);

    // Obter o ano atual (adicione 1900 ao campo tm_year)
    int anoAtual = infoTempo->tm_year + 1900;

    return anoAtual - dt_nascimento.ano;
}
Passageiro gerar_passageiro(vector<Passageiro> &passageiros)
{
    Passageiro p;
    bool verifica;
    cout << "==========Dados do Passageiro==========\n";
    do
    {
        cout << "\nDigite o CPF do passageiro: ";
        cin >> p.cpf;
        verifica = verifica_CPF(p.cpf, passageiros);
        if (!verifica)
        {
            cout << "CPF já cadastrado anteriormente ou inválido !!\n";
            cout << "Digite um CPF válido para o passageiro !!!\n";
            limparBuffers();
        }
    } while (!verifica);

    cout << "Digite o nome do passageiro: ";

    cin.ignore();
    getline(cin, p.nome);

    p.dt_nascimento = gera_data(true);

    if (p.idade() < MAIOR_IDADE)
    {
        cout << "Digite o numero de autorizacao do passageiro: ";
        cin >> p.num_Autorizacao;
    }
    cout << "======================================\n\n";

    return p;
}

int localizar_passageiro(vector<Passageiro> &passageiros)
{
    string cpf;
    int tamanho = passageiros.size();
    cout << "Digite o CPF do passageiro que deseja localizar: ";
    cin >> cpf;
    for (int i = 0; i < tamanho; i++)
    {
        if (passageiros[i].cpf == cpf)
        {
            return i;
        }
    }
    return -1;
}

bool remover_passageiro(vector<Passageiro> &passageiros)
{
    string cpf;
    int i,opcao;

    i = localizar_passageiro(passageiros);

    if (i != -1)
    {
        cout << "Dados do Passageiro a remover: !\n";
            cout << "======================================\n";
            imprimir_passageiro(passageiros[i]);
            cout << "======================================\n\n";
            cout << "Deseja realmente remover o passageiro?\n";
            cout << "1 - Sim\n";
            cout << "2 - Nao\n";
            cout << "OBS: Digite 1 ou 2, caso contrario sera considerado como Nao!\n";
            cin >> opcao;

            if(opcao == 1){
                passageiros.erase(passageiros.begin() + i);
                return true;
            }
    }

    return false;
}

void listar_passageiros(vector<Passageiro> &passageiros)
{
    int i = 1;
    cout << "==========Dados dos Passageiros==========\n\n";
    for (Passageiro passageiro : passageiros)
    {
        cout << "Passageiro: " << i << "ª\n\n";
        cout << "======================================\n";

        imprimir_passageiro(passageiro);

        cout << "======================================\n\n";
        i++;
    }
}

void alterar_passageiro(vector<Passageiro> &passageiros)
{

    int p;
    string cpf;
    p = localizar_passageiro(passageiros);
    int opcao;
    if (p != -1 && p >= 0)
    {
        do
        {
            opcao = Menu_Alterar_Passageiro(passageiros[p]);
            switch (opcao)
            {
            case 1:
                cout << "Digite o novo nome do passageiro: ";
                cin.ignore();
                getline(cin, passageiros[p].nome);
                cout << "Nome alterado com sucesso !\n";
                pause();
                break;
            case 2:
                cout << "Digite o novo CPF do passageiro: ";
                cin >> cpf;
                if (verifica_CPF(cpf, passageiros))
                {
                    passageiros[p].cpf = cpf;
                    cout << "CPF alterado com sucesso!\n";
                }
                else
                {
                    cout << "Não foi possivel alterar o CPF do passageiro\n";
                }
                limparBuffers();
                pause();
                break;
            case 3:
                cout << "Digite a nova data de nascimento do passageiro: \n";
                passageiros[p].dt_nascimento = gera_data(true);
                cout << "Data de nascimento alterada com sucesso!\n";
                limparBuffers();
                pause();
                break;
            case 4:
                if (passageiros[p].idade() < MAIOR_IDADE)
                {
                    cout << "Digite o novo numero de autorizacao do passageiro: ";
                    cin >> passageiros[p].num_Autorizacao;
                    cout << "Numero de autorizacao alterado com sucesso!\n";
                }
                else
                {
                    cout << "Não é possivel alterar o numero de autorizacao desse passageiro !!\n";
                    cout << "Pois ele já atingiu a maior idade !!\n";
                }
                limparBuffers();
                pause();
                break;
            case 0:
                break;
            default:
                cout << "Opcao invalida\n";
                cout << "Por favor digite uma opcao valida !\n";
                limparBuffers();
                pause();
                break;
            }
        } while (opcao != 0);
    }
    else
    {
        cout << "CPF Não encontrado!!\n";
        cout << "Serar redirecionado para o menu Passageiros !!\n";
        limparBuffers();
        pause();
    }
}

// ###########################################################################

// Funções de gestão de roteiros
// verifica se o codigo já está cadastrado retornando true

void Valida_Origem(Roteiro &roteiro)
{
    string origem;
    bool valida;
    cin.clear();
    do
    {
        cout << "Digite a origem do roteiro: ";
        getline(cin, origem);
        valida = origem == roteiro.destino;
        if (valida)
        {
            cout << "Origem invalida !\n";
            cout << "Não pode ser igual ao destino !!\n";
            cout << "Por favor digite uma origem valida!\n";
            pause();
        }
    } while (valida);
    roteiro.origem = origem;
}

void Valida_Destino(Roteiro &roteiro)
{
    string destino;
    bool valida;
    cin.clear();
    do
    {
        cout << "Digite o destino do roteiro: ";
        getline(cin, destino);
        valida = destino == roteiro.origem;
        if (valida)
        {
            cout << "Destino invalido !\n";
            cout << "Não pode ser igual ao origem !!\n";
            cout << "Por favor digite um destino valida!\n";
            pause();
        }
    } while (valida);
    roteiro.destino = destino;
}
bool valida_horario(string &horario)
{
    /**
     * valida_data: Esta função valida o horario utilizando um regex.
     * Paramentro horario do tipo string .
     * retorna true ou false.
     */
    regex datePattern(R"(\d{2}:\d{2})");

    return regex_match(horario, datePattern);
};
bool verifica_codigo(int codigo, vector<Roteiro> roteiros)
{
    for (Roteiro r : roteiros)
    {
        if (r.codigo == codigo)
        {
            return false;
        }
    }
    return true;
}
Roteiro gerar_Roteiro(vector<Roteiro> &roteiros)
{
    Roteiro r;
    bool verifica;
    cout << "==========Dados do Roteiro==========\n";
    do
    {
        cout << "\nDigite o codigo do roteiro: ";
        cin >> r.codigo;
        verifica = verifica_codigo(r.codigo, roteiros);
        if (!verifica)
        {
            cout << "Codigo já cadastrado anteriormente ou inválido\n";
            cout << "Digite um codigo válido para o roteiro !";
            limparBuffers();
            pause();
        }
    } while (!verifica);
    r.data = gera_data(false);
    do
    {
        cout << "Digite a hora do roteiro: ";
        cin >> r.Hora;
        if (!valida_horario(r.Hora))
        {
            cout << "Horario invalido, tente novamente." << endl;
            limparBuffers();
            pause();
        }
    } while (!valida_horario(r.Hora));

    cout << "Digite a duracao do roteiro: ";
    cin >> r.duracao;
    cout << "Digite a origem do roteiro: ";

    cin.ignore();
    getline(cin, r.origem);

    Valida_Destino(r);

    cout << "======================================\n\n";
    return r;
}
bool remover_Roteiro(vector<Roteiro> &roteiros)
{
    int codigo, opcao;
    int tamanho = roteiros.size();
    cout << "Digite o codigo do roteiro que deseja remover: ";
    cin >> codigo;
    for (int i = 0; i < tamanho; i++)
    {
        if (roteiros[i].codigo == codigo)
        {
            cout << "Dados do Roteiro a remover: !\n";
            cout << "======================================\n";
            imprimir_Roteiro(roteiros[i]);
            cout << "======================================\n\n";
            cout << "Deseja realmente remover o roteiro?\n";
            cout << "1 - Sim\n";
            cout << "2 - Nao\n";
            cout << "OBS: Digite 1 ou 2, caso contrario sera considerado como Nao!\n";
            cin >> opcao;

            if(opcao == 1){
                roteiros.erase(roteiros.begin() + i);
                return true;
            }
        }
    }
    return false;
}
void imprimir_Roteiro(Roteiro r)
{
    cout << "Codigo: " << r.codigo << endl;
    cout << "Data: " << r.data.data << endl;
    cout << "Hora: " << r.Hora << endl;
    cout << "Duracao: " << r.duracao << endl;
    cout << "origem: " << r.origem << endl;
    cout << "Destino: " << r.destino << endl;
}
void listar_Roteiro(vector<Roteiro> &roteiros)
{
    int i = 1;
    cout << "==========Dados dos Roteiros==========\n\n";
    for (Roteiro roteiro : roteiros)
    {
        cout << "Roteiro: " << i << "ª\n\n";
        cout << "======================================\n";

        imprimir_Roteiro(roteiro);

        cout << "======================================\n\n";
    }
}
int localizar_Roteiro(vector<Roteiro> &roteiros)
{
    int codigo;
    int tamanho = roteiros.size();
    cout << "Digite o codigo do roteiro que deseja localizar: ";
    cin >> codigo;
    for (int i = 0; i < tamanho; i++)
    {
        if (roteiros[i].codigo == codigo)
        {
            return i;
        }
    }
    return -1;
}
void alterar_Roteiro(vector<Roteiro> &roteiros)
{
    int r;
    int codigo;
    r = localizar_Roteiro(roteiros);
    int opcao;
    if (r != -1 && r >= 0)
    {
        do
        {
            opcao = Menu_Alterar_Roteiro(roteiros[r]);
            limpaTela();
            limparBuffers();
            switch (opcao)
            {
            case 1:
                cout << "Digite o novo codigo do roteiro: ";
                cin >> codigo;
                if (verifica_codigo(codigo, roteiros))
                {
                    roteiros[r].codigo = codigo;
                    cout << "Codigo alterado com sucesso !\n";
                }
                else
                {
                    cout << "Não foi possivel alterar o codigo do roteiro\n";
                }
                limparBuffers();
                pause();
                break;
            case 2:
                roteiros[r].data = gera_data(false);
                cout << "Data alterada com sucesso!\n";
                limparBuffers();
                pause();
                break;
            case 3:
                cout << "Digite a nova hora do roteiro: ";
                cin >> roteiros[r].Hora;
                cout << "Hora alterada com sucesso!\n";
                limparBuffers();
                pause();
                break;
            case 4:
                cout << "Digite a nova duracao do roteiro: ";
                cin >> roteiros[r].duracao;
                cout << "Duracao alterada com sucesso!\n";
                limparBuffers();
                pause();
                break;
            case 5:
                Valida_Origem(roteiros[r]);
                cout << "Origem alterada com sucesso!\n";
                pause();
                break;
            case 6:
                Valida_Destino(roteiros[r]);
                cout << "Destino alterado com sucesso!\n";
                pause();
                break;
            case 0:
                break;
            default:
                cout << "Opcao invalida\n";
                cout << "Por favor digite uma opcao valida !\n";
                pause();
            }
        } while (opcao != 0);
    }
    else
    {
        cout << "Codigo de roteiro nao encontrado !!\n";
        cout << "Serar redirecionado para o menu Roteiros !!\n";
        limparBuffers();
        pause();
    }
}

// Funções Gestão de Embarque
bool verifica_Embarque(vector<Embarque> embarques, string cpf, int codigo)
{
    for (Embarque e : embarques)
    {
        if (e.cpf_passageiro == cpf && e.codigo_roteiro == codigo)
        {
            return false;
        }
    }
    return true;
}
void gerar_Embarque(vector<Embarque> &embarques, string cpf, int codigo)
{
    Embarque e;
    int opcao;
    if (verifica_Embarque(embarques, cpf, codigo))
    {
        cout << "==========Dados do Roteiro==========\n";
        e.cpf_passageiro = cpf;
        e.codigo_roteiro = codigo;
        e.data = gera_data(false).data;
        cout << "Digite a hora do embarque: ";
        cin >> e.hora;
        cout << "Digite a duracao do embarque: ";
        cin >> e.duracao;
        cout << "Informe se o embarque foi realizado: \n";
        cout << "1 - Sim\n";
        cout << "2 - Nao\n";
        cout << "OBS: Digite 1 ou 2, caso contrario sera considerado como Nao !\n";
        cin >> opcao;
        if (opcao == 1)
        {
            e.realizada = true;
        }
        else
        {
            e.realizada = false;
        }
        cout << "======================================\n\n";
        embarques.push_back(e);
    }
}

void imprimir_Embarque(Embarque e)
{
    cout << "cpf_passageiro: " << e.cpf_passageiro << endl;
    cout << "codigo_roteiro: " << e.codigo_roteiro << endl;
    cout << "data: " << e.data << endl;
    cout << "hora: " << e.hora << endl;
    cout << "duracao: " << e.duracao << endl;
    cout << "realizada: ";
    if(e.realizada == 1) cout<<"Sim"<<endl;
    else cout<<"Nao"<<endl;
    // << e.realizada << endl;
}
bool remover_Embarque(vector<Embarque> &embarques, string cpf, int codigo)
{
    int tamanho = embarques.size();
    int opcao;
    for (int i = 0; i < tamanho; i++)
    {
        if (embarques[i].cpf_passageiro == cpf && embarques[i].codigo_roteiro == codigo)
        {

            cout << "Dados do embarque a remover: !\n";
            cout << "======================================\n";
            imprimir_Embarque(embarques[i]);
            cout << "======================================\n\n";
            cout << "Deseja realmente remover o embarque?\n";
            cout << "1 - Sim\n";
            cout << "2 - Nao\n";
            cout << "OBS: Digite 1 ou 2, caso contrario sera considerado como Nao!\n";
            cin >> opcao;

            if(opcao == 1){
                embarques.erase(embarques.begin() + i);
                return true;
            }
        }
    }
    return false;
}

void alterar_Embarque(int codigo, vector<Embarque> &embarques, vector<Passageiro> &passageiros){
    for(Embarque embarque : embarques){
        if(embarque.codigo_roteiro == codigo){
            Passageiro passageiro = get_passageiro_por_cpf(embarque.cpf_passageiro, passageiros);
            imprimir_passageiro(passageiro);
        }
    }

    cout<<"Digite o cpf do passageiro relacionado ao embarque: ";
    string cpf;
    cin>>cpf;
    if(validarCPF(cpf)){
        for(Embarque &embarque : embarques){
            if(embarque.cpf_passageiro == cpf && embarque.codigo_roteiro == codigo){
                string duracaoString;
                cout<<"Digite a duracao real do embarque: ";
                cin>>duracaoString;
                bool eNumero = true;
                // string duracaoString = to_string(duracao);
                for(char caractere : duracaoString){
                    if(!isdigit(caractere)){
                        cout<<"Digite um valor numerico para a duracao do embarque!"<<endl;
                        eNumero = false;
                        break;
                    }
                }
                if(eNumero){
                    int duracao = stoi(duracaoString);
                    embarque.duracao = duracao;
                    cout<<"Embarque alterado com sucesso!";
                }
                return;
            }
        }

        cout<<"Um passageiro com esse cpf nao existe ou na esta relacionado a esse embarque."<<endl;
    } else{
        cout<<"CPF invalido"<<endl;
    }
}

Passageiro get_passageiro_por_cpf(string cpf, vector<Passageiro> passageiros){
    for(Passageiro passageiro : passageiros){
        if(passageiro.cpf == cpf){
            return passageiro;
        }
    }
    return Passageiro();
}

void listar_Embarques(vector<Embarque> &embarques){
    int i = 1;
    cout << "==========Dados dos Embarques==========\n\n";
    for (Embarque embarque : embarques)
    {
        cout << "Embarque: " << i << "ª\n\n";
        cout << "======================================\n";

        imprimir_Embarque(embarque);

        cout << "======================================\n\n";
    }
}

bool valida_data(string& data) {
        /**
         * valida_data: Esta função valida o data utilizando um regex.
         * Paramentro data do tipo string .
         * retorna true ou false.
         */
    regex datePattern(R"(\d{2}/\d{2}/\d{4})");

    return regex_match(data, datePattern);
};

bool verifica_apolice_cadastro(vector<Embarque> &embarques, string& apolice) {
    for (Embarque embarque : embarques){
        if(embarque.ocorrencia.numero_Apolice == apolice){
            return true;
        }
    }
    return  false;
};

void gerar_ocorrencia(vector<Embarque> &embarques,  Ocorrencia& ocorrencia)
{
    Embarque e;

    int codigo;
    string cpf;
    bool verifica_embarques;

    do{
        cout << "========== Dados da ocorrencia ==========\n";
        cout << "Digite o codigo do roteiro: ";
        cin >> codigo;

        cout << "Digite o CPF do passageiro: ";
        cin >> cpf;

        if (verifica_Embarque(embarques, cpf, codigo)) {
                verifica_embarques = false;
                cout << "Não encontramos essa embarque!" << endl;
                limparBuffers();
                pause();
    // Saia da função se a ocorrência não foi encontrada.
            }else{
                verifica_embarques = true;

                cout << "========== Dados do Roteiro ==========\n";
                cout << "Digite a descrição da ocorrência: ";
                cin.ignore(); // Limpe o buffer do teclado antes de ler a descrição.
                getline(cin, ocorrencia.Descricao); 

                do{
                    cout << "Digite o numero da apólice: ";
                    cin >> ocorrencia.numero_Apolice;
                    if (verifica_apolice_cadastro(embarques, ocorrencia.numero_Apolice))
                    {
                        cout << "Apolice já cadastrada, tente outra." << endl;
                        limparBuffers();
                        pause();
                    }
                } while (verifica_apolice_cadastro(embarques, ocorrencia.numero_Apolice));

                do{
                    cout << "Digite a Data da ocorrência (formato: DD/MM/AAAA): ";
                    cin >> ocorrencia.data;
                    if(!valida_data(ocorrencia.data)){
                        cout << "Nascimento do passageiro invalida tente novamente." <<endl;
                        limparBuffers();
                        pause();
                    }
                } while (!valida_data(ocorrencia.data));

                do{
                    cout << "Digite a hora da ocorrência(00:00): ";
                    cin >> ocorrencia.hora;
                    if (!valida_horario(ocorrencia.hora))
                    {
                        cout << "Horario invalido, tente novamente." << endl;
                        limparBuffers();
                        pause();
                    }
                } while (!valida_horario(ocorrencia.hora));

                for (Embarque& e : embarques) {
                    if (e.cpf_passageiro == cpf && e.codigo_roteiro == codigo) {
                        e.ocorrencia = ocorrencia;
                        std::cout << "Ocorrência cadastrada com sucesso!" << std::endl;
                    }
                }
                cout << "======================================\n\n";
                cout << "Ocorrencia cadastrado com sucesso!" << endl;

            };
    }while(verifica_embarques != true);

};


bool remover_ocorrencia(vector<Embarque> &embarques)
{
    Embarque novo_embarque;
    int codigo, opcao, tamanho = embarques.size();
    string cpf;

    cout << "Digite o CPF: ";
    cin >> cpf;

    cout << "Digite o codigo do roteiro que deseja remover: ";
    cin >> codigo;
        for (int i = 0; i < tamanho; i++ ){
            if (embarques[i].cpf_passageiro == cpf && embarques[i].codigo_roteiro == codigo){

                cout << "Dados da Ocorrencia removidos: !\n";
                cout << "======================================\n";
                //chama a função aqui, imprimir
                cout << "======================================\n\n";
                cout << "Deseja realmente remover o embarque?\n";
                cout << "1 - Sim\n";
                cout << "2 - Nao\n";
                cout << "OBS: Digite 1 ou 2, caso contrario sera considerado como Nao!\n";
                cin >> opcao;

                if(opcao == 1){
                    embarques[i].ocorrencia.Descricao = " ";
                    embarques[i].ocorrencia.data = " ";
                    embarques[i].ocorrencia.hora = " ";
                    embarques[i].ocorrencia.numero_Apolice = " ";

                    return true;
                };
            };
        };
    return false;
}

// ###########################################################################

// CPFs Válidos para teste
/*
    56920258099
    16429869091
    62628795019
    78192873064
    7608843705
    71020146001
    38754362024
    12300887096
    16188894000
    46429599043
*/