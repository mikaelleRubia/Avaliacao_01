#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <iomanip>

using namespace std;


struct Roteiro
{
    string codigo;
    string Data;
    string Hora;
    string duracao;
    string origin;
    string destino;
};


int Menu();
void incluirRoteiros(vector<Roteiro>& roteiros);
void listarRoteiros(vector<Roteiro>&  roteiros);
void excluirRoteiros(vector<Roteiro>&  roteiros);
void localizarRoteiros(vector<Roteiro>&  roteiros);
void alterarRoteiro(vector<Roteiro>& roteiros);
bool existeCodigoRoteiro(const vector<Roteiro>& roteiros, const string& codigo);
bool validaRepeticaoSiadaDestino(string destino, string origem);
bool validaHorario(string& horario) ;

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

    vector< Roteiro>  roteiros;
    
    int opcao;

    do
    {
        limpaTela();
        opcao = Menu();
        switch (opcao)
        {
        case 1:
            incluirRoteiros(roteiros);
            break;
        case 2:
            excluirRoteiros(roteiros);
            break;
        case 3: 
            alterarRoteiro(roteiros);
            break;
        case 4:
            listarRoteiros(roteiros);
            palse();
            break;
        case 5:
            localizarRoteiros(roteiros);
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
    cout << "3 - Alterar CPF\n";
    cout << "4 - Listar\n";
    cout << "5 - Localizar\n";
    cout << "0 - Sair\n";

    int opcao;
    wcout << L"\nEscolha uma opcao: ";
    cin >> opcao;

    return opcao;
}

void incluirRoteiros(vector<Roteiro>& roteiros)
{

    Roteiro roteiro;

    char resposta;
    int cont = 0;

    do
    {
        cont++;
        cout << "Digite o Codigo do Roteiro: ";
        cin.ignore();
        getline(cin, roteiro.codigo);

        if (existeCodigoRoteiro(roteiros, roteiro.codigo))
        {
            cout << "Este código já existe. Tente novamente." << endl;
            continue;
        }

        cout << " Digite o Destino do Roteiro: " << endl;
        cin >> roteiro.destino;

        cout << " Digite a Origem do Roteiro: " << endl;
        cin >> roteiro.origin;

        if (validaRepeticaoSiadaDestino(roteiro.destino, roteiro.origin))
        {
            cout << "O destino não pode ser o mesmo que a origem. Tente novamente." << endl;
            continue;
        }


        cout << " Digite a Data do Roteiro: " << endl;
        cin >> roteiro.Data;

        cout << " Digite a Hora do Roteiro: " << endl;
        cin >> roteiro.Hora;

        if (!validaHorario(roteiro.Hora))
        {
            cout << "A hora de ser no formato hh:mm." << endl;
            continue;
        }

        cout << " Digite a Dracao do Roteiro: " << endl;
        cin >> roteiro.duracao;

        

        roteiros.push_back(roteiro);
        cout << "Roteiro incluido com sucesso!" << endl;

        cout << " Deseja Incluir outro Roteiro (s/n)? " << endl;
        cin >> resposta;

    } while (resposta == 's');
};

void listarRoteiros(vector<Roteiro>& roteiros) {
    if (roteiros.empty()) {
        cout << "Nenhum Roteiro cadastrado." << endl;
    } else {
       
    cout << "====================================================================" << endl;
    cout << "========================Lista de Roteiros========================" << endl;
    cout << "====================================================================" << endl;
        for (const auto &roteiro : roteiros) {          
            cout << "Codigo: " << roteiro.codigo << endl;
            cout << "Destino: " << roteiro.destino << endl;
            cout << "Saida: " << roteiro.origin << endl;
            cout << "Data: " << roteiro.Data << endl;
            cout << "Horario: " << roteiro.Hora << endl;
            cout << "Duracao: " << roteiro.duracao << endl;
            cout << "-----------------------------" << endl;
        }
    }
}

void excluirRoteiros(vector<Roteiro>& Roteiros) {
    string codigo;
    char res;

    cout << "Digite o Codigo do Roteiro a ser excluido: ";
    cin >> codigo;

    for (auto it = Roteiros.begin(); it != Roteiros.end();it++) {
        if (it->codigo == codigo) {
            cout << "Realmente deseja exclui o Roteiro '" << it->codigo << "' (s/n)?" << endl;
            cin >> res;
            if(res=='s'){
                 Roteiros.erase(it);
                cout << "Roteiro excluido com sucesso!" << endl;
                return;
            }
           
        }
    }

    cout << "Roteiro com CPF " << codigo << " não encontrado." << endl;
}

void localizarRoteiros(vector<Roteiro>& Roteiros) {
    string codigo;
    cout << "Digite o Codigo do Roteiro para localizalo: ";
    cin >> codigo;

    for (auto it = Roteiros.begin(); it != Roteiros.end();it++) {
        if (it->codigo == codigo) {
            cout << "====================================================================" << endl;
            cout << "==============================Roteiro============================" << endl;
            cout << "====================================================================" << endl;
            cout << "Codigo: " << it->codigo << endl;      
            cout << "Destino: " << it->destino << endl;
            cout << "Saida " << it->origin << endl;
            cout << "Data: " << it->Data << endl;       
            cout << "Hora: " << it->Hora << endl;       
            cout << "Duracao: " << it->duracao << endl;       
            cout << "-----------------------------" << endl;
            return;
        }
    }

    cout << "Roteiro com Codigo " << codigo << " nao encontrado." << endl;
}
bool existeCodigoRoteiro(const vector<Roteiro>& roteiros, const string& codigo)
{
    for (const Roteiro& roteiro : roteiros)
    {
        if (roteiro.codigo == codigo)
        {
            return true;
        }
    }
    return false;
}

void alterarRoteiro(vector<Roteiro>& roteiros)
{
    string codigo;
    string data;
    cout << "Digite o codigo do roteiro a ser alterado: ";
    cin >> codigo;

    for (auto& roteiro : roteiros)
    {
        if (roteiro.codigo == codigo)
        {
            cout << "==============================Dados do Roteiro============================" << endl;
            cout << "Codigo: " << roteiro.codigo << endl;
            cout << "Data: " << roteiro.Data << endl;
            cout << "Hora: " << roteiro.Hora << endl;
            cout << "Duracao: " << roteiro.duracao << endl;
            cout << "Origem: " << roteiro.origin << endl;
            cout << "Destino: " << roteiro.destino << endl;
            cout << "====================================================================" << endl;

            char resposta;
            cout << "Deseja alterar a Data (s/n)? ";
            cin >> resposta;
            if (resposta == 's')
            {
                cout << "Digite a nova Data (dd/mm/aaaa): ";
                cin >> data;
                roteiro.Data = data;
            }

            cout << "Deseja alterar a Hora (s/n)? ";
            cin >> resposta;
            if (resposta == 's')
            {
                cout << "Digite a nova Hora: ";
                cin >> roteiro.Hora;
            }

            cout << "Deseja alterar a Duração (s/n)? ";
            cin >> resposta;
            if (resposta == 's')
            {
                cout << "Digite a nova Duração: ";
                cin >> roteiro.duracao;
            }

            cout << "Deseja alterar a Origem (s/n)? ";
            cin >> resposta;
            if (resposta == 's')
            {
                cout << "Digite a nova Origem: ";
                cin >> roteiro.origin;
            }

            cout << "Deseja alterar o Destino (s/n)? ";
            cin >> resposta;
            if (resposta == 's')
            {
                cout << "Digite o novo Destino: ";
                cin >> roteiro.destino;
            }

            cout << "Roteiro alterado com sucesso!" << endl;
            return;
        }
    }

    cout << "Roteiro com código " << codigo << " não encontrado." << endl;
}

bool validaRepeticaoSiadaDestino(string destino, string origem)
{  

    if(destino == origem){
        return true;
    };
    return false;
};

bool validaHorario(string& horario) 
{ // faz fica no formato hh:mm
    regex datePattern(R"(\d{2}:\d{2})");

    return regex_match(horario, datePattern);
};