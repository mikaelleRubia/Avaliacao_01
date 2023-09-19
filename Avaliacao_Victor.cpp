/*
    Avaliação 1
    Parte Individual - Víctor
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Data{
    int dia, mes, ano;
};

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
    Data data;
    string Hora;
    string duracao;
    string origin;
    string destino;
};

void limpaTela();
int Menu();
int Menu_Passsageiros();

int main(){

    vector<Passageiro> passageiros;
    vector<Roteiro> roteiros;

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

    int opcao, opcaoPassageiro, opcaoRoteiro;

    do
    {
        limpaTela();
        opcao = Menu();

        switch (opcao){
            case 1:
                opcaoPassageiro = Menu_Passageiros();
                do{
                    limpaTela();
                    switch(opcaoPassageiro){
                        case 1:
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        case 4:
                            break;
                        case 5:
                            break;
                        case 0:
                            break;
                        default:
                            cout<<"Opção Inválida! Tente novamente"<<endl;
                            break;
                            
                    }
                } while(opcaoPassageiro != 0);
                break;
            case 2:
                break;
            case 0: 
                break;
            default:
                cout<<"Opção Inválida! Tente novamente"<<endl;
                break;
        }
    } while (opcao != 0);
    
}

void limpaTela(){
    system("echo ''") == 0 ? system("clear") : system("cls");
}

int Menu()
{
    cout << "############## Menu ##############\n\n";
    cout << "1 - Gestao de Passageiros \n";
    cout << "2 - Gestao de Roteiros \n";
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

void incluir_passageiro(vector<Passageiro> passageiros){
    Passageiro passageiro;
    cout<<"Nome do passageiro: ";
    cin>>passageiro.nome;
    cout<<"CPF do passageiro: ";
    cin>>passageiro.cpf;
    cout<<"Data de nascimento (dd/MM/yyyy): ";
    cin>>passageiro.dt_nascimento;
    //verifica idade do passageiro...

    passageiros.push_back(passageiro);
}

void listar_passageiros(vector<Passageiro> passageiros){
    cout<<"PASSAGEIROS:"<<endl;

    for(Passageiro passageiro : passageiros){
        cout<<"----------------------------------------------------"<<endl;
        cout<<"Nome: "<<passageiro.nome<<endl;
        cout<<"CPF: "<<passageiro.cpf<<endl;
        cout<<"Data de nascimento: "<<passageiro.dt_nascimento<<endl;
        cout<<"Numero de autorizacao: "<<passageiro.num_Autorizacao<<endl;
    }
    cout<<"----------------------------------------------------"<<endl;
}

Passageiro localizar_passageiro(string cpf, vector<Passageiro> passageiros){
    for(Passageiro p : passageiros){
        if(p.cpf == cpf)
            return p;
    }
}
