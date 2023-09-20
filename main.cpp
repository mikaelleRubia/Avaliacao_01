#include <iostream>
#include <cstring>
#include <vector>
# include <limits>

using namespace std;
#define ASSENTOS 40;

struct Passageiro
{
    string nome;
    string cpf;
    string dt_nascimento;
    int num_Autorizacao;
    bool vazio = true;
};

struct Roteiro
{
    int codigo;
    string Data;
    string Hora;
    string duracao;
    string origin;
    string destino;
};

struct Embarca
{
    string cpf_passageiro;
    int codigo_roteiro;
    char realizada;
    string data;
    string hora;
    int duracao;
};

int Menu();
int Menu_Passageiros();
int Menu_Alterar_Passageiro();
int Menu_Roteiros();
int Menu_Embarque();

// Funções do sistema de Passageiros
Passageiro gerar_passageiro(vector<Passageiro> &);
bool remover_passageiro(vector<Passageiro> &);
void imprimir_passageiro(Passageiro);
void listar_passageiros(vector<Passageiro> &);
int localizar_passageiro(vector<Passageiro> &);
void alterar_passageiro(vector<Passageiro> &);

// Funções do sistema de Roteiros
// Funções do sistema de Embarque

// Funções de utilidades
bool verifica_CPF(string cpf, vector<Passageiro> &passageiros);
bool validarCPF(string cpf);
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
    int opcao, opcao2,aux;
    vector<Embarca> embarca;
    vector<Roteiro> roteiro;
    vector<Passageiro> passageiros;
    Passageiro aux_passageiro;

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
                            cout << "Erro ao remover passageiro !" << endl;
                            cout << "CPF inexistente ou CPF digitado Errado !" << endl;
                        }
                    }
                    limparBuffers();
                    pause();
                    break;
                case 3:
                    // chamada da função alterar passageiro
                    if(passageiros.empty()){
                        cout << "Nao ha passageiros cadastrados !" << endl;
                    }else{
                        alterar_passageiro(passageiros);
                    }
                    limparBuffers();
                    pause();
                    break;
                case 4:
                    // chamada da função listar passageiros
                    if(passageiros.empty()){
                        cout << "Nao ha passageiros cadastrados !" << endl;
                    }else{
                        listar_passageiros(passageiros);
                    }
                    limparBuffers();
                    pause();
                    break;
                case 5:
                    // chamada da função localizar passageiro
                    if(passageiros.empty()){
                        cout << "Nao ha passageiros cadastrados !" << endl;
                    }else{
                        
                        aux = localizar_passageiro(passageiros);

                        cout << "Passageiro localizado segue os dados: " << endl;
                        imprimir_passageiro(passageiros[aux]);
                        cout << "======================================="<< endl;
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

                switch (opcao2)
                {
                case 1:
                    // chamada da função inserir roteiros
                    break;
                case 2:
                    // chamada da função remover roteiros
                    break;
                case 3:
                    // chamada da função alterar roteiros
                    break;
                case 4:
                    // chamada da função listar roteiros
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
                    break;
                case 2:
                    // chamada da função remover embarque
                    break;
                case 3:
                    // chamada da função alterar embarque
                    break;
                case 4:
                    // chamada da função listar embarque
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
void pause() {
    cout << "\nPressione a tecla Enter para continuar...\n";
    cin.clear(); // Limpa quaisquer flags de erro no cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // cin.get(); // Aguarda até que o usuário pressione Enter
}
void limparBuffers() {
    // Limpa o buffer de entrada do cin
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Limpa o buffer de saída do cout
    std::cout.flush();
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
// ##########################################################################

// Funções de Menus
int Menu()
{
    cout << "############## Menu ##############\n\n";
    cout << "1 - Gestao de Passageiros \n";
    cout << "2 - Gestao de Roteiros \n";
    cout << "3 - Gestao de Embarcacoes \n";
    cout << "0 - Sair\n";

    int opcao;
    wcout << L"\nEscolha uma opcao: ";
    cin >> opcao;

    return opcao;
}

int Menu_Alterar_Passageiro(){
    int opcao;

    cout << "############## Alterar dados de Passageiro ##############\n\n";
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
    cout << "3 - Alterar CPF\n";
    cout << "4 - Listar\n";
    cout << "5 - Localizar\n";
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
    cout << "2 - Excluir\n";
    cout << "3 - Alterar\n";
    cout << "4 - Listar\n";
    cout << "0 - Voltar ao Menu Principal\n";

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
    cout << "0 - Voltar ao Menu Principal\n";

    int opcao;
    cout << "\nEscolha uma opcao: ";
    cin >> opcao;

    return opcao;
}
// ###########################################################################

// Funções de gestão de passageiros

void imprimir_passageiro(Passageiro p){
    cout << "Nome: " << p.nome << endl;
    cout << "CPF: " << p.cpf << endl;
    cout << "Data de Nascimento: " << p.dt_nascimento << endl;
    cout << "Numero de Autorizacao: " << p.num_Autorizacao << endl;
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
            cout << "CPF já cadastrado anteriormente ou inválido\n";
            cout << "Digite um CPF válido para o passageiro !";
        }
    } while (!verifica);

    cout << "Digite o nome do passageiro: ";
    cin >> p.nome;
    cout << "Digite a data de nascimento do passageiro: ";
    cin >> p.dt_nascimento;
    cout << "Digite o numero de autorizacao do passageiro: ";
    cin >> p.num_Autorizacao;
    p.vazio = false;
    cout << "======================================\n\n";

    return p;
}

bool remover_passageiro(vector<Passageiro> &passageiros)
{
    string cpf;
    int tamanho = passageiros.size();
    cout << "Digite o CPF do passageiro que deseja remover: ";
    cin >> cpf;
    for (int i = 0; i < tamanho; i++)
    {
        if (passageiros[i].cpf == cpf)
        {
            passageiros.erase(passageiros.begin() + i);
            return true;
        }
    }
    return false;
}

void listar_passageiros(vector<Passageiro> &passageiros){
    int i = 1;
    cout << "==========Dados dos Passageiros==========\n\n";
    for (Passageiro passageiro : passageiros)
    {
        cout << "Passageiro: " << i << "\n\n";

        imprimir_passageiro(passageiro);

        cout << "======================================\n";
        cout << "======================================\n\n";
        i++;
    }
}

int localizar_passageiro(vector<Passageiro> &passageiros){
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

void alterar_passageiro(vector<Passageiro> &passageiros){
    
    int p;
    string cpf;
    p = localizar_passageiro(passageiros);
    int opcao;
    if(p!=-1 && p>=0)
    {
        do{
            opcao = Menu_Alterar_Passageiro();
            switch(opcao){
                case 1:
                    cout << "Digite o novo nome do passageiro: ";
                    cin >> passageiros[p].nome;
                    cout << "Nome alterado com sucesso !\n";
                    limparBuffers();
                    pause();
                    break;
                case 2:
                    cout << "Digite o novo CPF do passageiro: ";
                    cin >> cpf;
                    if(verifica_CPF(cpf, passageiros)){
                        passageiros[p].cpf = cpf;
                    }else{
                        cout << "Não foi possivel alterar o CPF do passageiro\n";
                    }
                    limparBuffers();
                    pause();
                    break;
                case 3:
                    cout << "Digite a nova data de nascimento do passageiro: ";
                    cin >>passageiros[p].dt_nascimento;
                    cout << "Data de nascimento alterada com sucesso!\n";
                    limparBuffers();
                    pause();
                    break;
                case 4:
                    cout << "Digite o novo numero de autorizacao do passageiro: ";
                    cin >> passageiros[p].num_Autorizacao;
                    cout << "Numero de autorizacao alterado com sucesso!\n";
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
        }while(opcao!=0);
    }
}

// ###########################################################################

