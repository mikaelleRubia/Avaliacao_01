#include <iostream>
#include <string>
#include <vector>

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
                    // chamada da função inserir passageiros
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
}