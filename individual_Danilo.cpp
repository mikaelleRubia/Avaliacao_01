#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct Passageiro
{
    string nome;
    string cpf;
    string dt_nascimento;
    int num_Autorizacao;
};


int Menu();
void incluirPassageiros(vector<Passageiro>& passageiros);
void listarPassageiros(vector<Passageiro>& passageiros);
void excluirPassageiros(vector<Passageiro>& passageiros);

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
            // chamada da função alterar passageiros
            break;
        case 4:
            listarPassageiros(passageiros);
            palse();
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
    cout << "3 - Alterar CPF\n";
    cout << "4 - Listar\n";
    cout << "5 - Localizar\n";
    cout << "0 - Sair\n";

    int opcao;
    wcout << L"\nEscolha uma opção: ";
    cin >> opcao;

    return opcao;
}

void incluirPassageiros(vector<Passageiro>& passageiros)
{

    Passageiro passageiro;

    char resposta;
    int cont = 0;

    do
    {
        cont++;
        cout << " Digite o nome do Passageiro: " << endl;
        cin.ignore();
        getline(cin, passageiro.nome);

        cout << " Digite o CPF do Passageiro: " << endl;
        cin >> passageiro.cpf;

        cout << " Digite a Data de Nascimento do Passageiro: " << endl;
        cin >> passageiro.dt_nascimento;

        cout << "Numero de Autorizacao do Responsavel: ";
        cin >> passageiro.num_Autorizacao;

        passageiros.push_back(passageiro);
        cout << "Passageiro incluido com sucesso!" << endl;

        cout << " Deseja Incluir outro passageiro (s/n)? " << endl;
        cin >> resposta;

    } while (resposta == 's');
};

void listarPassageiros(vector<Passageiro>& passageiros) {
    if (passageiros.empty()) {
        cout << "Nenhum passageiro cadastrado." << endl;
    } else {
       
    cout << "====================================================================" << endl;
    cout << "========================Lista de Passageiros===========================" << endl;
    cout << "====================================================================" << endl;
        for (const auto &passageiro : passageiros) {          
            cout << "Nome: " << passageiro.nome << endl;
            cout << "CPF: " << passageiro.cpf << endl;
            cout << "Data de Nascimento: " << passageiro.dt_nascimento << endl;
            cout << "Número de Autorização do Responsavel: " << passageiro.num_Autorizacao << endl;
            cout << "-----------------------------" << endl;
        }
    }
}

void excluirPassageiros(vector<Passageiro>& passageiros) {
    string cpf;
    char res;

    cout << "Digite o CPF do passageiro a ser excluído: ";
    cin >> cpf;

    for (auto it = passageiros.begin(); it != passageiros.end();it++) {
        if (it->cpf == cpf) {
            cout << "Realmente deseja exclui o Passageiro '" << it->nome << "' (s/n)?" << endl;
            cin >> res;
            if(res=='s'){
                 passageiros.erase(it);
                cout << "Passageiro excluído com sucesso!" << endl;
                return;
            }
           
        }
    }

    cout << "Passageiro com CPF " << cpf << " não encontrado." << endl;
}