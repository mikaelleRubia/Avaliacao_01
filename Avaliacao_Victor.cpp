/*
    Avaliação 1
    Parte Individual - Víctor
*/

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <limits>
#include <sstream>
#include <regex>
using namespace std;

struct Data{
    int dia, mes, ano;
};

struct Passageiro
{
    string nome;
    string cpf;
    Data dt_nascimento;
    string num_Autorizacao;
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
void pause();

//MENUS
int Menu();
int Menu_Passageiros();
int Menu_Roteiros();

//FUNÇÕES CONTROLADORAS DA STRUCT PASSAGEIRO
void incluir_passageiro(vector<Passageiro> &passageiros);
void excluir_passageiro(vector<Passageiro> &passageiros, string cpf);
void alterar_passageiro(string cpf, vector<Passageiro> &passageiros);
void listar_passageiros(vector<Passageiro> &passageiros);
void localizar_passageiro(string cpf, vector<Passageiro> &passageiros);

//FUNÇÕES CONTROLADORAS DA STRUCT ROTEIRO
void incluir_roteiro(vector<Roteiro> &roteiros, int codigoGerado);
void excluir_roteiro(vector<Roteiro> &roteiros, int codigo);
void alterar_roteiro(vector<Roteiro> &roteiros, int codigo);
void listar_roteiros(vector<Roteiro> &roteiros);
void localizar_roteiro(int codigo, vector<Roteiro> &roteiros);

//VALIDAÇÕES E CALCULOS
int calcula_idade(Data data);
bool valida_data(Data data);
bool valida_hora(string horaString);
bool ja_existe_passageiro_com_cpf(vector<Passageiro> &passageiros, string cpf);
bool valida_numero_autorizacao(string numero);
void valida_origem_destino(Roteiro &roteiro, int campo);
bool valida_cpf(string &cpf);

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
    string cpf;
    int codigo, codigoGerado = 1;

    do
    {
        limpaTela();
        opcao = Menu();

        switch (opcao){
            case 1:
                do{
                    limpaTela();
                    opcaoPassageiro = Menu_Passageiros();
                    switch(opcaoPassageiro){
                        case 1:
                            limpaTela();
                            incluir_passageiro(passageiros);
                            cout<<"Passageiro cadastrado!"<<endl;
                            pause();
                            break;
                        case 2:
                            limpaTela();
                            cout<<"Digite o cpf do passageiro a ser removido (apenas numeros): ";
                            cin>>cpf;
                            excluir_passageiro(passageiros, cpf);
                            pause();
                            break;
                        case 3:
                            limpaTela();
                            cout<<"Digite o cpf do passageiro a ser alterado (apenas numeros): ";
                            cin>>cpf;
                            limpaTela();
                            alterar_passageiro(cpf, passageiros);
                            pause();
                            break;
                        case 4:
                            limpaTela();
                            listar_passageiros(passageiros);
                            pause();
                            break;
                        case 5:
                            limpaTela();
                            cout<<"Digite o cpf do passageiro a ser localizado (apenas numeros): ";
                            cin>>cpf;
                            localizar_passageiro(cpf, passageiros);
                            pause();
                            break;
                        case 0:
                            break;
                        default:
                            cout<<"Opção Inválida! Tente novamente"<<endl;
                            pause();
                            break;
                            
                    }
                } while(opcaoPassageiro != 0);
                break;
            case 2:
                do{
                    limpaTela();
                    opcaoRoteiro = Menu_Roteiros();
                    switch(opcaoRoteiro){
                        case 1:
                            limpaTela();
                            incluir_roteiro(roteiros, codigoGerado);
                            codigoGerado++;
                            cout<<"Roteiro cadastrado!"<<endl;
                            pause();
                            break;
                        case 2:
                            limpaTela();
                            cout<<"Digite o codigo do roteiro a ser removido: ";
                            cin>>codigo;
                            excluir_roteiro(roteiros, codigo);
                            pause();
                            break;
                        case 3:
                            limpaTela();
                            cout<<"Digite o codigo do roteiro a ser alterado: ";
                            cin>>codigo;
                            alterar_roteiro(roteiros, codigo);
                            pause();
                            break;
                        case 4:
                            limpaTela();
                            listar_roteiros(roteiros);
                            pause();
                            break;
                        case 5:
                            limpaTela();
                            cout<<"Digite o codigo do roteiro a ser localizado: ";
                            cin>>codigo;
                            localizar_roteiro(codigo, roteiros);
                            pause();
                            break;
                        case 0:
                            break;
                        default:
                            cout<<"Opção Inválida! Tente novamente"<<endl;
                            pause();
                            break;
                    }
                } while(opcaoRoteiro != 0);
                break;
            case 0: 
                break;
            default:
                cout<<"Opção Inválida! Tente novamente"<<endl;
                pause();
                break;
        }
    } while (opcao != 0);
    
}

void limpaTela(){
    system("echo ''") == 0 ? system("clear") : system("cls");
}

void pause(){
    cout << "\nPressione a tecla Enter para continuar...\n";
    cin.sync();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
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
    cout << "3 - Alterar\n";
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
    cout << "5 - Localizar\n";
    cout << "0 - Voltar ao Menu Principal\n";

    int opcao;
    cout << "\nEscolha uma opcao: ";
    cin >> opcao;

    return opcao;
}

void incluir_passageiro(vector<Passageiro> &passageiros){
    cout<<"########### INCLUIR PASSAGEIRO ###########\n\n";
    Passageiro passageiro;
    cout<<"Nome do passageiro: ";
    cin>>passageiro.nome;
    // getline(cin,passageiro.nome);
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"CPF do passageiro (apenas numeros): ";
    cin>>passageiro.cpf;
    if(ja_existe_passageiro_com_cpf(passageiros, passageiro.cpf) || !valida_cpf(passageiro.cpf)){
        do{
            //limpaTela();
            cout<<"Já existe um passageiro com este CPF ou este cpf esta invalido! Digite outro (apenas numeros): ";
            cin>>passageiro.cpf;
        } while(ja_existe_passageiro_com_cpf(passageiros, passageiro.cpf) || !valida_cpf(passageiro.cpf));
    }
    cout<<"Data de nascimento (dd/MM/yyyy):"<<endl;
    cout<<"Dia: ";
    cin>>passageiro.dt_nascimento.dia;
    cout<<"Mes: ";
    cin>>passageiro.dt_nascimento.mes;
    cout<<"Ano: ";
    cin>>passageiro.dt_nascimento.ano;
    if(!valida_data(passageiro.dt_nascimento)){
        do{
            cout<<"Data inválida! Digite outra: "<<endl;
            cout<<"Dia: ";
            cin>>passageiro.dt_nascimento.dia;
            cout<<"Mes: ";
            cin>>passageiro.dt_nascimento.mes;
            cout<<"Ano: ";
            cin>>passageiro.dt_nascimento.ano;
        } while(!valida_data(passageiro.dt_nascimento));
    }
    if(calcula_idade(passageiro.dt_nascimento) < 16){
        cout<<"Numero de autorizacao para passageiro menor de idade: ";
        cin>>passageiro.num_Autorizacao;
        if(!valida_numero_autorizacao(passageiro.num_Autorizacao)){
            do{
                cout<<"Numero de autorizacao inválido! Digite outro: ";
                cin>>passageiro.num_Autorizacao;
            } while(!valida_numero_autorizacao(passageiro.num_Autorizacao));
        }
    } else {
        passageiro.num_Autorizacao = "Passageiro maior de idade";
    }

    passageiros.push_back(passageiro);
}

void excluir_passageiro(vector<Passageiro> &passageiros, string cpf){
    bool localizou = false;
    
    for(int i = 0; i < passageiros.size(); i++){
        if(passageiros[i].cpf == cpf){
            passageiros.erase(passageiros.begin() + i);
            localizou = true;
            break;
        }
    }

    if(localizou) cout<<"Passageiro excluido!"<<endl;
    else cout<<"Passageiro nao encontrado!"<<endl;
}

void alterar_passageiro(string cpf, vector<Passageiro> &passageiros){
    bool localizou = false;

    for(Passageiro &passageiro : passageiros){
        if(passageiro.cpf == cpf){
            localizou = true;
            cout<<"########## ALTERAR PASSAGEIRO ##########\n\n";
            cout<<"Nome: "<<passageiro.nome<<endl;
            cout<<"CPF: "<<passageiro.cpf<<endl;
            cout<<"Data de nascimento: "<<passageiro.dt_nascimento.dia<<"//"<<passageiro.dt_nascimento.mes<<"//"<<passageiro.dt_nascimento.ano<<endl;
            cout<<"Numero de autorizacao: "<<passageiro.num_Autorizacao<<endl<<endl;

            char resposta;
            cout<<"Deseja alterar o nome do passageiro? (Digite 's' para sim ou qualquer caractere para não)";
            cin>>resposta;
            if(resposta == 's'){
                cout<<"Novo nome: ";
                cin>>passageiro.nome;
            }
            cout<<"Deseja alterar o CPF do passageiro? (Digite 's' para sim ou qualquer caractere para não)";
            cin>>resposta;
            if(resposta =='s'){
                cout<<"Novo CPF (apenas numeros): ";
                cin>>passageiro.cpf;
                if(ja_existe_passageiro_com_cpf(passageiros, passageiro.cpf) || !valida_cpf(passageiro.cpf)){
                    do{
                        cout<<"Já existe um passageiro com este CPF ou este cpf esta invalido! Digite outro (apenas numeros): ";
                        cin>>passageiro.cpf;
                    } while(ja_existe_passageiro_com_cpf(passageiros, passageiro.cpf) || !valida_cpf(passageiro.cpf));
                }
            }
            cout<<"Deseja alterar a data de nascimento do passageiro? (Digite 's' para sim ou qualquer caractere para não)";
            cin>>resposta;
            if(resposta == 's'){
                cout<<"Nova data de nascimento: "<<endl;
                cout<<"Dia: ";
                cin>>passageiro.dt_nascimento.dia;
                cout<<"Mes: ";
                cin>>passageiro.dt_nascimento.mes;
                cout<<"Ano: ";
                cin>>passageiro.dt_nascimento.ano;

                if(!valida_data(passageiro.dt_nascimento)){
                    do{
                        cout<<"Data inválida! Digite outra: "<<endl;
                        cout<<"Dia: ";
                        cin>>passageiro.dt_nascimento.dia;
                        cout<<"Mes: ";
                        cin>>passageiro.dt_nascimento.mes;
                        cout<<"Ano: ";
                        cin>>passageiro.dt_nascimento.ano;
                    } while(!valida_data(passageiro.dt_nascimento));
                }

                if(calcula_idade(passageiro.dt_nascimento) < 16 && passageiro.num_Autorizacao == "Passageiro maior de idade"){
                    cout<<"Numero de autorizacao para passageiro menor de idade: ";
                    cin>>passageiro.num_Autorizacao;
                    if(!valida_numero_autorizacao(passageiro.num_Autorizacao)){
                        do{
                            cout<<"Numero de autorizacao inválido! Digite outro: ";
                            cin>>passageiro.num_Autorizacao;
                        } while(!valida_numero_autorizacao(passageiro.num_Autorizacao));
                    }
                }
            }
            if(calcula_idade(passageiro.dt_nascimento) < 16){
                cout<<"Deseja alterar o numero de autorizacao do passageiro? (Digite 's' para sim ou qualquer caractere para não)";
                cin>>resposta;
                if(resposta == 's'){
                    cout<<"Novo numero de autorizacao: ";
                    cin>>passageiro.num_Autorizacao;
                    if(!valida_numero_autorizacao(passageiro.num_Autorizacao)){
                        do{
                            cout<<"Numero de autorizacao inválido! Digite outro: ";
                            cin>>passageiro.num_Autorizacao;
                        } while(!valida_numero_autorizacao(passageiro.num_Autorizacao));
                    }
                }
            }
            break;
        }
    }

    if(!localizou){
        cout<<"Passageiro nao encontrado!"<<endl;
    }
}

void listar_passageiros(vector<Passageiro> &passageiros){
    cout<<"####### PASSAGEIROS #######\n\n";

    for(Passageiro passageiro : passageiros){
        cout<<"----------------------------------------------------"<<endl;
        cout<<"Nome: "<<passageiro.nome<<endl;
        cout<<"CPF: "<<passageiro.cpf<<endl;
        cout<<"Data de nascimento: "<<passageiro.dt_nascimento.dia<<"/"<<passageiro.dt_nascimento.mes<<"/"<<passageiro.dt_nascimento.ano<<endl;
        cout<<"Numero de autorizacao: "<<passageiro.num_Autorizacao<<endl;
    }
    cout<<"----------------------------------------------------"<<endl;
}

void localizar_passageiro(string cpf, vector<Passageiro> &passageiros){
    bool localizou = false;

    for(Passageiro &passageiro : passageiros){
        if(passageiro.cpf == cpf){
            cout<<"----------------------------------------------------"<<endl;
            cout<<"Nome: "<<passageiro.nome<<endl;
            cout<<"CPF: "<<passageiro.cpf<<endl;
            cout<<"Data de nascimento: "<<passageiro.dt_nascimento.dia<<"/"<<passageiro.dt_nascimento.mes<<"/"<<passageiro.dt_nascimento.ano<<endl;
            cout<<"Numero de autorizacao: "<<passageiro.num_Autorizacao<<endl;
            localizou = true;
            break;
        }
    }

    if(!localizou){
        cout<<"----------------------------------------------------"<<endl;
        cout<<"Passageiro nao encontrado!"<<endl;
    }
}

void incluir_roteiro(vector<Roteiro> &roteiros, int codigoGerado){
    cout<<"########### INCLUIR ROTEIRO ###########\n\n";
    Roteiro roteiro;
    roteiro.codigo = codigoGerado;
    cout<<"Data do roteiro:"<<endl;
    cout<<"Dia: ";
    cin>>roteiro.data.dia;
    cout<<"Mes: ";
    cin>>roteiro.data.mes;
    cout<<"Ano: ";
    cin>>roteiro.data.ano;
    if(!valida_data(roteiro.data)){
        do{
            cout<<"Data inválida! Digite outra: "<<endl;
            cout<<"Dia: ";
            cin>>roteiro.data.dia;
            cout<<"Mes: ";
            cin>>roteiro.data.mes;
            cout<<"Ano: ";
            cin>>roteiro.data.ano;
        } while(!valida_data(roteiro.data));
    }
    cout<<"Hora: ";
    cin>>roteiro.Hora;
    if(!valida_hora(roteiro.Hora)){
        do{
            cout<<"Hora inválida! Digite outra: "<<endl;
            cout<<"Hora: ";
            cin>>roteiro.Hora;
        } while(!valida_hora(roteiro.Hora));
    }
    cout<<"Duracao prevista: ";
    cin>>roteiro.duracao;
    if(!valida_hora(roteiro.duracao)){
        do{
            cout<<"Duracao inválida! Digite outra: "<<endl;
            cout<<"Duracao: ";
            cin>>roteiro.duracao;
        } while(!valida_hora(roteiro.duracao));
    }
    cout<<"Origem do roteiro: ";
    cin>>roteiro.origin;
    cout<<"Destino do roteiro: ";
    cin>>roteiro.destino;
    valida_origem_destino(roteiro, 2);

    roteiros.push_back(roteiro);
}

void excluir_roteiro(vector<Roteiro> &roteiros, int codigo){
    bool localizou = false;
    
    for(int i = 0; i < roteiros.size(); i++){
        if(roteiros[i].codigo == codigo){
            roteiros.erase(roteiros.begin() + i);
            localizou = true;
            break;
        }
    }

    if(localizou) cout<<"Roteiro excluido!"<<endl;
    else cout<<"Roteiro nao encontrado!"<<endl;
}

void alterar_roteiro(vector<Roteiro> &roteiros, int codigo){
    bool localizou = false;

    for(Roteiro &roteiro : roteiros){
        if(roteiro.codigo == codigo){
            localizou = true;
            cout<<"########## ALTERAR ROTEIRO ##########\n\n";
            cout<<"Codigo: "<<roteiro.codigo<<endl;
            cout<<"Data e hora prevista: "<<endl;
            cout<<"Dia: "<<roteiro.data.dia<<"//"<<roteiro.data.mes<<"//"<<roteiro.data.ano<<endl;
            cout<<"Hora: "<<roteiro.Hora<<endl;
            cout<<"Origem: "<<roteiro.origin<<endl;
            cout<<"Destino: "<<roteiro.destino<<endl;

            char resposta;
            cout<<"Deseja alterar o codigo do roteiro? (Digite 's' para sim ou qualquer caractere para não): ";
            cin>>resposta;
            if(resposta == 's'){
                cout<<"Novo codigo: ";
                cin>>roteiro.codigo;
            }
            cout<<"Deseja alterar a data e a hora prevista? (Digite 's' para sim ou qualquer caractere para não): ";
            cin>>resposta;
            if(resposta =='s'){
                cout<<"Nova data e hora prevista: "<<endl;
                cout<<"Dia: ";
                cin>>roteiro.data.dia;
                cout<<"Mes: ";
                cin>>roteiro.data.mes;
                cout<<"Ano: ";
                cin>>roteiro.data.ano;
                 if(!valida_data(roteiro.data)){
                    do{
                        cout<<"Data inválida! Digite outra: "<<endl;
                        cout<<"Dia: ";
                        cin>>roteiro.data.dia;
                        cout<<"Mes: ";
                        cin>>roteiro.data.mes;
                        cout<<"Ano: ";
                        cin>>roteiro.data.ano;
                    } while(!valida_data(roteiro.data));
                }
                cout<<"Hora: ";
                cin>>roteiro.Hora;
            }
            cout<<"Deseja alterar a duracao prevista? (Digite's' para sim ou qualquer caractere para não): ";
            cin>>resposta;
            if(resposta =='s'){
                cout<<"Nova duracao prevista: ";
                cin>>roteiro.duracao;
            }
            cout<<"Deseja alterar a origem do roteiro? (Digite's' para sim ou qualquer caractere para não): ";
            cin>>resposta;
            if(resposta =='s'){
                cout<<"Nova origem do roteiro: ";
                cin>>roteiro.origin;
                valida_origem_destino(roteiro, 1);
            }
            cout<<"Deseja alterar a destino do roteiro? (Digite's' para sim ou qualquer caractere para não): ";
            cin>>resposta;
            if(resposta =='s'){
                cout<<"Nova destino do roteiro: ";
                cin>>roteiro.destino;
                valida_origem_destino(roteiro, 2);
            }
            break;
        }
    }

    if(!localizou){
        cout<<"Roteiro nao encontrado!"<<endl;
    }
}

void listar_roteiros(vector<Roteiro> &roteiros){
    cout<<"####### ROTEIROS #######\n\n";

    for(Roteiro roteiro : roteiros){
        cout<<"----------------------------------------------------"<<endl;
        cout<<"Codigo: "<<roteiro.codigo<<endl;
        cout<<"Data e hora prevista: "<<roteiro.data.dia<<"/"<<roteiro.data.mes<<"/"<<roteiro.data.ano<<endl;
        cout<<"Hora: "<<roteiro.Hora<<endl;
        cout<<"Duracao: "<<roteiro.duracao<<endl;
        cout<<"Origem: "<<roteiro.origin<<endl;
        cout<<"Destino: "<<roteiro.destino<<endl;
    }
    cout<<"----------------------------------------------------"<<endl;
}

void localizar_roteiro(int codigo, vector<Roteiro> &roteiros){
    bool localizou = false;

    for(Roteiro &roteiro : roteiros){
        if(roteiro.codigo == codigo){
            cout<<"----------------------------------------------------"<<endl;
            cout<<"Codigo: "<<roteiro.codigo<<endl;
            cout<<"Data prevista: "<<roteiro.data.dia<<"/"<<roteiro.data.mes<<"/"<<roteiro.data.ano<<endl;
            cout<<"Hora: "<<roteiro.Hora<<endl;
            cout<<"Origem: "<<roteiro.origin<<endl;
            cout<<"Destino: "<<roteiro.destino<<endl;
            localizou = true;
            break;
        }
    }

    if(!localizou){
        cout<<"----------------------------------------------------"<<endl;
        cout<<"Roteiro nao encontrado!"<<endl;
    }
}

bool ja_existe_passageiro_com_cpf(vector<Passageiro> &passageiros, string cpf){
    for(Passageiro passageiro : passageiros){
        if(passageiro.cpf == cpf){
            return true;
        }
    }
    return false;
}

bool valida_cpf(string &cpf){

    regex datePattern(R"(\d{11})");

    return regex_match(cpf, datePattern);
}

int calcula_idade(Data data){
    time_t now = time(0);
    tm* currentDate = localtime(&now);

    int idade = currentDate->tm_year + 1900 - data.ano;

    if (data.mes > currentDate->tm_mon + 1 || (data.mes == currentDate->tm_mon + 1 && data.dia > currentDate->tm_mday)) {
        idade--;
    }

    return idade;
}

bool valida_data(Data data){
    if(data.mes < 1 || data.mes > 12)
        return false;
    if(data.mes == 2){
        if(data.ano % 4 == 0 && (data.ano % 100 != 0 || data.ano % 400 == 0)){
            if(data.dia < 1 || data.dia > 29)
                return false;
        } else if(data.dia < 1 || data.dia > 28) {
            return false;
        }
    } else if (data.mes == 1 || data.mes == 3 || data.mes == 5 || 
                data.mes == 7 || data.mes == 8 || data.mes == 10 || data.mes == 12){
        if(data.dia < 1 || data.dia > 31)
            return false;
    } else {
        if(data.dia < 1 || data.dia > 30)
            return false;
    }

    return true;
}

bool valida_hora(string horaString){
    int hora, minuto;
    istringstream ss(horaString);
    char delimiter;
    ss>>hora>>delimiter>>minuto;

    if(ss.fail() || hora < 0 || hora > 23 || minuto < 0 || minuto > 59)
        return false;

    return true;
}

bool valida_numero_autorizacao(string numero){

    for(int i = 0; i < numero.length(); i++){
        if(!isdigit(numero[i]))
            return false;
    }

    return true;
}

void valida_origem_destino(Roteiro &roteiro, int campo){
    if(campo == 1){
        while(roteiro.origin == roteiro.destino){
            cout<<"Origem do roteiro nao pode ser igual a destino, digite outra origem: ";
            cin>>roteiro.origin;
        }
    } else{
        while(roteiro.origin == roteiro.destino){
            cout<<"Destino do roteiro nao pode ser igual a origem, digite outra destino: ";
            cin>>roteiro.destino;
        }
    }
}
