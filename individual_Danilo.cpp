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
    cout << "3 - Alterar CPF";
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

        cout << "Número de Autorização do Responsável: ";
        cin >> passageiro.num_Autorizacao;

        passageiros.push_back(passageiro);
        cout << "Passageiro incluído com sucesso!" << endl;

        cout << " Deseja Incluir outro passageiro (s/n)? " << endl;
        cin >> resposta;

    } while (resposta == 's');
};

