#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <sstream>
#include <ctime>
#include <iomanip>


using namespace std;
#define ASSENTOS 40;

struct Passageiro
{
    string nome;
    string cpf;
    string dt_nascimento;
    int num_Autorizacao;
};

struct  Roteiro
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
int Menu_Roteiros();
int Menu_Embarque();
bool valida_cpf(string& cpf);
bool valida_data_nascimento(string& data_nascimento);
bool valida_idade(const string& dataNascimento);
bool cpf_cadastrado(vector <Passageiro> &passageiro, string &cpf);
void incluir_passageiro(vector <Passageiro> &passageiro);

void limpaTela_palse();
void palse();
void limpaTela();

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
    int opcao,opcao2;
    vector<Embarca> embarca;
    vector<Roteiro> roteiro;
    vector<Passageiro> passageiros;

    do
    {
        limpaTela();
        opcao = Menu();
        switch (opcao)
        {
        case 1:
            do{
                limpaTela();
                opcao2 = Menu_Passageiros();

                switch (opcao2)
                {
                case 1:
                    incluir_passageiro(passageiros);
                    break;
                case 2:
                    // chamada da função remover passageiros
                    break;
                case 3:
                    // chamada da função alterar passageiros
                    break;
                case 4:
                    // chamada da função listar passageiros
                    break;
                case 5:
                    // chamada da função localizar passageiros
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
        case 2:
            do{
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
            do{
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
        case 4:
            // chamada da função 
            break;
        case 0:
            // chamada da função                     
            break;
        default:

            break;
        }
    } while (opcao != 0);
    
    return 0;
}

void palse(){
    cout << "\nPressione a tecla Enter para continuar...\n";
    cin.sync();
    cin.get();
}

void limpaTela(){
    system("echo ''") == 0 ? system("clear") : system("cls");
}

void limpaTela_palse(){
    palse();
    limpaTela();
}


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

int Menu_Passageiros(){
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

int Menu_Roteiros(){
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

int Menu_Embarque(){
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
};


bool valida_cpf(string& cpf){
        /**
         * valida_cpf: Esta função valida o cpf utilizando um regex.
         * Paramentro cpf do tipo string .
         * retorna true ou false.
         */
    regex datePattern(R"(\d{3}\.\d{3}\.\d{3}-\d{2}|\d{11})");

    return regex_match(cpf, datePattern);

};

bool valida_idade(const string& dataNascimento){
    time_t t = time(nullptr);
    tm tmAtual = *localtime(&t);

    tm tmNascimento = {};
    istringstream ss(dataNascimento);
    ss >> get_time(&tmNascimento, "%d/%m/%Y");


    int idade = tmAtual.tm_year - tmNascimento.tm_year;

    if (tmNascimento.tm_mon > tmAtual.tm_mon ||
        (tmNascimento.tm_mon == tmAtual.tm_mon && tmNascimento.tm_mday > tmAtual.tm_mday)) {
        idade--;
    }
    
    if (idade >= 16) {
        return  true;
    };
      
    return false;
}


bool valida_data_nascimento(string& data_nascimento) {
        /**
         * valida_data_nascimento: Esta função valida o data de nascimento utilizando um regex.
         * Paramentro data_nascimento do tipo string .
         * retorna true ou false.
         */
    regex datePattern(R"(\d{2}/\d{2}/\d{4})");

    return regex_match(data_nascimento, datePattern);
};


bool cpf_cadastrado(vector <Passageiro> &passageiro, string &cpf){
    int tamanho = passageiro.size();

    if (passageiro.size() == 0) return false;

    for( int i = 0; i < tamanho; i++){
        if(cpf == passageiro[i].cpf){
            return true;
        };
    };    
    return false;

};


void incluir_passageiro(vector <Passageiro> &passageiro){

    Passageiro passageiro_novo;
    string dt_nascimento , cpf, nome;
    int num_autorizacao;
    bool validacao_cpf, validacao_data;
    char resposta;

    do{
        do{
            cout << "CPF do passageiro" << endl;
            cin >> cpf;
            //chama funçaõ para validação
            validacao_cpf = valida_cpf(cpf);

            // verifica se o CPF já está cadastrado 
            if(cpf_cadastrado(passageiro, cpf)) {
                cout << "CPF já está cadastrado, mas você pode adicionar outro passageiro!!!"  <<endl;
                break;
            }
            
            cout << "Nome do passageiro" <<endl;
            cin >> nome;

            cout << "Data Nascimento do passageiro(dd/mm/yyyy)" <<endl;
            cin >>dt_nascimento;
            //chama funçaõ para validação
            validacao_data = valida_data_nascimento(dt_nascimento);

            if(!valida_idade(dt_nascimento)) {
                cout << "O passageiro "<< nome << "é menor de idade, então preciso que informa o numero de autorizacao:" <<endl;
                cin >> num_autorizacao;
            }



            if(validacao_cpf && validacao_data){
                passageiro_novo.cpf= cpf;
                passageiro_novo.dt_nascimento = dt_nascimento;
                passageiro_novo.nome =nome;
                passageiro_novo.num_Autorizacao = num_autorizacao > 0 ? num_autorizacao : 0;

                passageiro.push_back(passageiro_novo);
            }
            else{
                cout << "Erro ao informar seu dados, por favor verifique seu dados e ensira novamente!!!"  <<endl;
            }
        }while ( !(validacao_cpf && validacao_data));

        cout << "Deseja Adicionar outro passageiro (s/n)?" <<endl;
        cin >>resposta;

    }while(resposta =='s') ; 

    // for para teste.
    // for (int i = 0; i < passageiro.size(); i++)
    // {
    //     cout << passageiro[i].cpf << " ------------------- " << passageiro[i].nome << " ------------------ " << passageiro[i].dt_nascimento <<" ------------"<< passageiro[i].num_Autorizacao << endl;
    // }   

  
}