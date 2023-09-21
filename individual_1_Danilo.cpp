#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <iomanip>

using namespace std;


struct Passageiro
{
    string nome;
    string cpf;
    string dt_nascimento;
    string num_Autorizacao;
};


int Menu();
void incluirPassageiros(vector<Passageiro>& passageiros);
void listarPassageiros(vector<Passageiro>& passageiros);
void excluirPassageiros(vector<Passageiro>& passageiros);
void localizarPassageiros(vector<Passageiro>& passageiros);
void alterarPassageiro(vector<Passageiro>& passageiros);
bool valida_idade(const string& dataNascimento);
bool validaCPF(string& cpf);
bool cpf_cadastrado(vector <Passageiro> &passageiro, string &cpf);

bool validaDataNascimento(string& data_nascimento);  

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

    vector<Passageiro> passageiros;
    
    int opcao;

    do
    {
        limpaTela();
        opcao = Menu();
        switch (opcao)
        {
        case 1:
            incluirPassageiros(passageiros);
            break;
        case 2:
            excluirPassageiros(passageiros);
            break;
        case 3: 
            alterarPassageiro(passageiros);
            break;
        case 4:
            listarPassageiros(passageiros);
            palse();
            break;
        case 5:
            localizarPassageiros(passageiros);
            palse();
            break;
        case 0:
            break;
        default:
            cout << "Opcao invalida !" << endl;
            cout << "Por favor digite uma opcao valida !\n";
            palse();
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
    system("echo ''") != 0 ? system("clear") : system("cls");
}

void limpaTela_palse(){
    palse();
    limpaTela();
}


int Menu()
{
    cout << "############## Menu ##############\n\n";
    cout << "1 - Incluir \n";
    cout << "2 - Excluir\n";
    cout << "3 - Alterar pelo CPF\n";
    cout << "4 - Listar\n";
    cout << "5 - Localizar\n";
    cout << "0 - Sair\n";

    int opcao;
    wcout << L"\nEscolha uma opcao: ";
    cin >> opcao;

    return opcao;
}

void incluirPassageiros(vector<Passageiro>& passageiros)
{

    Passageiro passageiro;

    char resposta;
    int cont = 0;
    string data;
    do
    {
        cont++;
        cout << "Digite o nome do Passageiro: " << endl;
        cin.ignore();
        getline(cin, passageiro.nome);

        cout << "Digite o CPF do Passageiro: " << endl;
        cin >> passageiro.cpf;

         passageiro.cpf.erase(remove_if(passageiro.cpf.begin(), passageiro.cpf.end(), [](char c) { return !isdigit(c); }), passageiro.cpf.end());

        if (!validaCPF(passageiro.cpf))
        {
            cout << "CPF inválido. Tente novamente." << endl;
            continue;
        }

        // Verificar se o CPF já está cadastrado
        if (cpf_cadastrado(passageiros, passageiro.cpf))
        {
            cout << "Este CPF já está cadastrado. Tente novamente." << endl;
            continue;
        }

        

        cout << "Digite a Data de Nascimento do Passageiro (dd/mm/aaaa): " << endl;
        cin >> data;

        if (!validaDataNascimento(data)) {
            cout << "Data de Nascimento invalida. Digite no formato dd/mm/aaaa." << endl;
            void palse();
            continue; 
        }

        if (!valida_idade(data)) {
            cout << "Idade do Passageiro e menor que 16 anos. Não e permitido." << endl;
            cout << "Numero de Autorizacao do Responsavel: " << endl;
            cin >> passageiro.num_Autorizacao;
        }

    
        if (!validaDataNascimento(data)) {
            cout << "Data de Nascimento invalida. Digite no formato dd/mm/aaaa." << endl;
            void palse();
            continue; 
        }
        passageiro.dt_nascimento = data;
        passageiro.num_Autorizacao = "Maior";
        passageiros.push_back(passageiro);
        cout << "Passageiro incluído com sucesso!" << endl;

        cout << "Deseja Incluir outro passageiro (s/n)? " << endl;
        cin >> resposta;

    } while (resposta == 's');
};

void listarPassageiros(vector<Passageiro>& passageiros) {
    if (passageiros.empty()) {
        cout << "Nenhum passageiro cadastrado." << endl;
    } else {
       
    cout << "====================================================================" << endl;
    cout << "========================Lista de Passageiros========================" << endl;
    cout << "====================================================================" << endl;
        for (const auto &passageiro : passageiros) {          
            cout << "Nome: " << passageiro.nome << endl;
            cout << "CPF: " << passageiro.cpf << endl;
            cout << "Data de Nascimento: " << passageiro.dt_nascimento << endl;
            cout << "Numero de Autorizacao do Responsavel: " << passageiro.num_Autorizacao << endl;
            cout << "-----------------------------" << endl;
        }
    }
}

void excluirPassageiros(vector<Passageiro>& passageiros) {
    string cpf;
    char res;

    cout << "Digite o CPF do passageiro a ser excluido: ";
    cin >> cpf;

    for (auto it = passageiros.begin(); it != passageiros.end();it++) {
        if (it->cpf == cpf) {
            cout << "Realmente deseja exclui o Passageiro '" << it->nome << "' (s/n)?" << endl;
            cin >> res;
            if(res=='s'){
                 passageiros.erase(it);
                cout << "Passageiro excluido com sucesso!" << endl;
                return;
            }
           
        }
    }

    cout << "Passageiro com CPF " << cpf << " não encontrado." << endl;
}

void localizarPassageiros(vector<Passageiro>& passageiros) {
    string cpf;
    cout << "Digite o CPF do passageiro para localizalo: ";
    cin >> cpf;

    for (auto it = passageiros.begin(); it != passageiros.end();it++) {
        if (it->cpf == cpf) {
            cout << "====================================================================" << endl;
            cout << "==============================Passageiro============================" << endl;
            cout << "====================================================================" << endl;
            cout << "Nome: " << it->nome << endl;      
            cout << "CPF: " << it->cpf << endl;
            cout << "Data de Nascimento: " << it->dt_nascimento << endl;
            cout << "Numero de Autorização do Responsavel: " << it->num_Autorizacao << endl;       
        }
    }

    cout << "Passageiro com CPF " << cpf << " nao encontrado." << endl;
}

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


bool validaDataNascimento(string& data_nascimento) {      
    regex datePattern(R"(\d{2}/\d{2}/\d{4})");

    return regex_match(data_nascimento, datePattern);
};

void alterarPassageiro(vector<Passageiro>& passageiros)
{
    string cpf;
    string data;
    cout << "Digite o CPF do passageiro a ser alterado: ";
    cin >> cpf;

    for (auto& passageiro : passageiros)
    {
        if (passageiro.cpf == cpf)
        {
            cout << "==============================Dados do Passageiro============================" << endl;
            cout << "Nome: " << passageiro.nome << endl;
            cout << "CPF: " << passageiro.cpf << endl;
            cout << "Data de Nascimento: " << passageiro.dt_nascimento << endl;
            cout << "Numero de Autorizacao do Responsavel: " << passageiro.num_Autorizacao << endl;
            cout << "====================================================================" << endl;

            char resposta;
            cout << "Deseja alterar o Nome (s/n)? ";
            cin >> resposta;
            if (resposta == 's')
            {
                cout << "Digite o novo Nome: ";
                cin.ignore();
                getline(cin, passageiro.nome);
            }

            cout << "Deseja alterar o CPF (s/n)? ";
            cin >> resposta;
            if (resposta == 's')
            {
                string novoCPF;
                cout << "Digite o novo CPF: ";
                cin >> novoCPF;

                if (!validaCPF(passageiro.cpf))
                {
                    cout << "CPF inválido. Tente novamente." << endl;
                    continue;
                }
                // Verificar se o novo CPF já está cadastrado
                if (cpf_cadastrado(passageiros, novoCPF))
                {
                    cout << "Este CPF já está cadastrado. Tente novamente." << endl;
                    continue;
                }

                passageiro.cpf = novoCPF;
            }

            cout << "Deseja alterar a Data de Nascimento (s/n)? ";
            cin >> resposta;
            if (resposta == 's')
            {
                do
                {
                    cout << "Digite a nova Data de Nascimento (dd/mm/aaaa): ";
                    cin >> data;

                    if (!validaDataNascimento(data)) {
                        cout << "Data de Nascimento invalida. Digite no formato dd/mm/aaaa." << endl;
                        void palse();
                        continue; 
                    }

                    if (!valida_idade(data)) {
                        cout << "Idade do Passageiro e menor que 16 anos. Não e permitido." << endl;
                        cout << "Numero de Autorizacao do Responsavel: " << endl;
                        cin >> passageiro.num_Autorizacao;
                    }

                    passageiro.dt_nascimento = data;
                } while (!validaDataNascimento(passageiro.dt_nascimento));
            }

            cout << "Deseja alterar o Numero de Autorizacao (s/n)? ";
            cin >> resposta;
            if (resposta == 's')
            {
                cout << "Digite o novo Numero de Autorizacao: ";
                cin >> passageiro.num_Autorizacao;
            }

            cout << "Passageiro alterado com sucesso!" << endl;
            return;
        }
    }

    cout << "Passageiro com CPF " << cpf << " não encontrado." << endl;
}

bool cpf_cadastrado(vector <Passageiro> &passageiro, string &cpf)
{
    if(passageiro.size()> 0){    
        for (const Passageiro& passageiro : passageiro) {
            if(passageiro.cpf == cpf){
                return true;
            };
        };
    };
    return false;

};
bool validaCPF(string& cpf) // cpf dev conter 11 numeros
{
    regex datePattern(R"(\d{3}\.\d{3}\.\d{3}-\d{2}|\d{11})");

    return regex_match(cpf, datePattern);

};