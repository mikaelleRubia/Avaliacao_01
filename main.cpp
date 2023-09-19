#include <iostream>
#include <string>

using namespace std;

int Menu();

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
    int opcao;

    do
    {
        limpaTela();
        opcao = Menu();
        switch (opcao)
        {
        case 1:
            // chamada da função 
            break;
        case 2:
            // chamada da função 
            break;
        case 3:
            // chamada da função 
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
        palse();                    
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