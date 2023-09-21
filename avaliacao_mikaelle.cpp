#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <limits>


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
    string data;
    string hora;
    string duracao;
    string origem;
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

int menu();
int menu_passageiros();
int menu_roteiros();
int menu_Embarque();
bool valida_cpf(string& cpf);
bool valida_data(string& data_nascimento);
bool valida_idade(const string& dataNascimento);
bool cpf_cadastrado(vector <Passageiro> &passageiro, string &cpf);
void incluir_passageiro(vector <Passageiro> &passageiro);
bool remove_cpf_index(vector <Passageiro> &passageiro, string elemento);
void excluir_passageiro(vector <Passageiro> &passageiro);
void dados_passageiro(vector<Passageiro> &vetorDePassageiros, const string &elemento);
void alterar_dados(vector<Passageiro> &passageiro);
void lista_passageiro(vector<Passageiro> &passageiro);
void localiza_passageiro(vector<Passageiro> &passageiro);


//funções para roteiro
void localiza_roteiro(vector <Roteiro> &roteiro);
void alterar_roteiro(vector <Roteiro> &roteiro);
void alterar_campos_roteiro(vector <Roteiro> &roteiro, Roteiro &roteiro_atualizado, int &codigo, bool &alter_data, bool &alter_codigo, bool &alter_hora, bool &alter_orig, bool &alter_dest, bool &alter_durat);
void excluir_roteiro(vector <Roteiro> &roteiro);
bool remove_roteiro(vector <Roteiro> &roteiro,  int codigo);
void lista_roteiros(vector <Roteiro> &roteiro);
void dados_roteiros(vector <Roteiro> &roteiro, int codigo);
void incluir_roteiro(vector <Roteiro> &roteiro);
bool codigo_roteiro_cadastrado(vector <Roteiro> &roteiro, int codigo);
bool valida_destino_origem(string destino, string origem);


void limpa_tela_pause();
void pause();
void limpa_tela();

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
        limpa_tela();
        opcao = menu();
        switch (opcao)
        {
        case 1:
            do{
                limpa_tela();
                opcao2 = menu_passageiros();

                switch (opcao2)
                {
                case 1:
                    incluir_passageiro(passageiros);
                    break;
                case 2:
                    excluir_passageiro(passageiros);
                    break;
                case 3:
                    alterar_dados(passageiros);
                    break;
                case 4:
                    lista_passageiro(passageiros);
                    break;
                case 5:
                    localiza_passageiro(passageiros);
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
                limpa_tela();
                opcao2 = menu_roteiros();

                switch (opcao2)
                {
                case 1:
                    incluir_roteiro(roteiro);
                    break;
                case 2:
                    excluir_roteiro(roteiro);
                    break;
                case 3:
                    alterar_roteiro(roteiro);
                    break;
                case 4:
                    lista_roteiros(roteiro);
                    break;
                case 5:
                    localiza_roteiro(roteiro);
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
                limpa_tela();
                opcao2 = menu_Embarque();

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

void pause(){
    cout << "\nPressione a tecla Enter para continuar...\n";
    cin.clear(); // Limpa quaisquer flags de erro no cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // cin.get(); // Aguarda até que o usuário pressione Enter
}
void limparBuffers()
{
    // Limpa o buffer de entrada do cin
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // Limpa o buffer de saída do cout
    cout.flush();
}

void limpa_tela(){
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

void limpa_tela_pause(){
    pause();
    limpa_tela();
}

int menu()
{
    cout << "############## menu ##############\n\n";
    cout << "1 - Gestao de Passageiros \n";
    cout << "2 - Gestao de Roteiros \n";
    cout << "3 - Gestao de Embarcacoes \n";
    cout << "0 - Sair\n";

    int opcao;
    wcout << L"\nEscolha uma opcao: ";
    cin >> opcao;

    return opcao;
}

int menu_passageiros(){
    cout << "############## menu de Passageiros ##############\n\n";
    cout << "1 - Incluir \n";
    cout << "2 - Excluir\n";
    cout << "3 - Alterar CPF\n";
    cout << "4 - Listar\n";
    cout << "5 - Localizar\n";
    cout << "0 - Voltar ao menu Principal\n";

    int opcao;
    cout << "\nEscolha uma opcao: ";
    cin >> opcao;

    return opcao;
}

int menu_roteiros(){
    cout << "############## menu de Roteiros ##############\n\n";
    cout << "1 - Incluir \n";
    cout << "2 - Excluir\n";
    cout << "3 - Alterar\n";
    cout << "4 - Listar\n";
    cout << "5 - Localizar\n";
    cout << "0 - Voltar ao menu Principal\n";

    int opcao;
    cout << "\nEscolha uma opcao: ";
    cin >> opcao;

    return opcao;
}

int menu_Embarque(){
    cout << "############## menu de Embarque ##############\n\n";
    cout << "1 - Incluir \n";
    cout << "2 - Excluir\n";
    cout << "3 - Alterar\n";
    cout << "4 - Listar\n";
    cout << "0 - Voltar ao menu Principal\n";

    int opcao;
    cout << "\nEscolha uma opcao: ";
    cin >> opcao;

    return opcao;
};

void lista_passageiro(vector<Passageiro> &passageiro){
        cout <<"---------------------Lista de passageiro-------------------"<< endl;
        cout << "==========================================================" << endl;
    if(passageiro.size()> 0){    
        for (const Passageiro& passageiro : passageiro) {
            cout<<"Nome: " << passageiro.nome << 
            "\nCPF: " <<passageiro.cpf <<  
            "\nData Nascimento: " << passageiro.dt_nascimento <<
            "\nAutorizacao: " << passageiro.num_Autorizacao << endl;
            cout << "==========================================================" << endl;
            cout << "==========================================================" << endl;
        };

    }else{
        cout <<"Opa, a lista ainda esta vazia!!"<< endl;
    };  
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

bool valida_data(string& data) {
        /**
         * valida_data: Esta função valida o data utilizando um regex.
         * Paramentro data do tipo string .
         * retorna true ou false.
         */
    regex datePattern(R"(\d{2}/\d{2}/\d{4})");

    return regex_match(data, datePattern);
};

bool valida_horario(string& horario) {
        /**
         * valida_data: Esta função valida o horario utilizando um regex.
         * Paramentro horario do tipo string .
         * retorna true ou false.
         */
    regex datePattern(R"(\d{2}:\d{2})");

    return regex_match(horario, datePattern);
};

bool cpf_cadastrado(vector <Passageiro> &passageiro, string &cpf){
    if(passageiro.size()> 0){    
        for (const Passageiro& passageiro : passageiro) {
            if(passageiro.cpf == cpf){
                return true;
            };
        };
    };
    return false;

};

bool remove_cpf_index(vector <Passageiro> &passageiro, string cpf){
    int tamanho;
    tamanho = passageiro.size();
    passageiro.erase(std::remove_if(passageiro.begin(), passageiro.end(),
        [&cpf](const Passageiro& passageiro) {
            return passageiro.cpf == cpf;
        }), passageiro.end());

    if(tamanho > passageiro.size()){
        return true;
    }
    return false;
};

void altera_campo(vector<Passageiro> &vetorDePassageiros, Passageiro &passageiro_atualizado, const string &cpfParaAlterar, bool &altera_dt, bool &altera_cpf, bool &altera_nome, bool &altera_autoriza){

    for (Passageiro &passageiro : vetorDePassageiros) {
        if (passageiro.cpf == cpfParaAlterar) {
            if(altera_dt) {
                passageiro.dt_nascimento =  passageiro_atualizado.dt_nascimento;
            } 
            if(altera_cpf) {
                passageiro.cpf = passageiro_atualizado.cpf;
            } 
            if(altera_nome) {
                passageiro.nome = passageiro_atualizado.nome;
            }
            if(altera_autoriza) { 
                passageiro.num_Autorizacao = passageiro_atualizado.num_Autorizacao!= 0? passageiro_atualizado.num_Autorizacao : passageiro.num_Autorizacao;
            };
        };
    };
};

void dados_passageiro(vector<Passageiro> &passageiro, const string &elemento){
    cout <<"----------------Dados do passageiro-----------------"<< endl;
    cout << "======================================================" << endl;
    for (Passageiro &passageiro : passageiro) {
        if (passageiro.cpf == elemento) {
            passageiro.cpf = elemento;
        cout << "======================================================" << endl;
            cout<<"Nome: " << passageiro.nome << 
            "\nCPF: " <<passageiro.cpf <<  
            "\nData Nascimento: " << passageiro.dt_nascimento <<
            "\nAutorização: " << passageiro.num_Autorizacao << endl;
        }
    }
}

void incluir_passageiro(vector <Passageiro> &passageiro){

    Passageiro passageiro_novo;
    string dt_nascimento , cpf, nome;
    int num_autorizacao = 0;
    bool validacao_cpf;
    char resposta;

    do{
        cout << "CPF do passageiro" << endl;
        cin >> passageiro_novo.cpf;
        //chama funçaõ para validação
        if(valida_cpf(passageiro_novo.cpf)){

            if(cpf_cadastrado(passageiro, passageiro_novo.cpf)) {
                cout << "CPF ja cadastrado, mas voce pode adicionar outro passageiro!!!"  <<endl;

            
            }else{
                cout << "Nome do passageiro" <<endl;
                cin.ignore();
                getline(cin, passageiro_novo.nome);

                cout << "Data Nascimento do passageiro(dd/mm/yyyy)" <<endl;
                cin >>passageiro_novo.dt_nascimento;

                if(!valida_data(passageiro_novo.dt_nascimento)){
                    cout << "Nascimento do passageiro invalida tente novamente." <<endl;
                    break;
                };

                if(!valida_idade(passageiro_novo.dt_nascimento)) {
                    cout << "O passageiro "<< nome << "é menor de idade, então preciso que informa o numero de autorizacao:" <<endl;
                    cin >> num_autorizacao;
                }
                passageiro_novo.num_Autorizacao = num_autorizacao;
                passageiro.push_back(passageiro_novo);
            }
        }else{
            cout << "CPF invalido!" << endl;
        }; 
        // verifica se o CPF já está cadastrado 
        cout << "Deseja Adicionar outro passageiro (s/n)?" <<endl;
        cin >>resposta;
    }while(resposta =='s') ; 

};

void excluir_passageiro(vector <Passageiro> &passageiro){
    string cpf;
    char resposta;

    do{
        cout << "Para excluir um passageiro, preciso do CPF:" << endl;
        cin >> cpf;
        //chama função para validação
        // verifica se o CPF já está cadastrado
        if (valida_cpf(cpf)){
            if(passageiro.size() == 0){
                cout << "A lista de passageiros ainda está vazia" << endl;
                break;
            };
            if(cpf_cadastrado(passageiro, cpf)) {
                if(remove_cpf_index(passageiro, cpf)){
                    cout << "Roteiro excluido da lista" << endl;
                }else{
                    cout << "Poxa, não consegui remover o passageiro, tente mais tarde!!" << endl;
                    break;
                };
            } else {
                cout << "Passageiro não está na lista" << endl;
                };
        }else{
            cout << "CPF invalido!" << endl;
        };  
        cout << "Deseja remover outro passageiro (s/n)?" <<endl;
        cin >>resposta;

    }while(resposta =='s'); 
};

void alterar_dados(vector<Passageiro> &passageiro){

    bool altera_dt, altera_cpf, altera_nome, altera_autoriza;
    Passageiro passageiro_atualizado;
    string cpf;
    char resposta, resposta_altera;

        do{
            cout << "CPF do passageiro" << endl;
            cin >> cpf;
            // verifica se o CPF já está cadastrado 
            if(cpf_cadastrado(passageiro, cpf)){
                if(valida_cpf(cpf)){
                    dados_passageiro(passageiro, cpf);
                cout << "Deseja alterar o cpf do passageiro: (s/n)" <<endl;
                cin >> resposta_altera;

                if(resposta_altera =='s'){
                    resposta_altera ='\0';
                    altera_cpf = true;

                    cout << "Digite o CPF atualizado:" <<endl;
                    cin >> passageiro_atualizado.cpf;
                }
                cout << "Deseja alterar o nome do passageiro: (s/n)" <<endl;
                cin >> resposta_altera;

                if(resposta_altera =='s'){
                    resposta_altera ='\0';
                    altera_nome= true;

                    cout << "Digite o Nome  atualizado:" <<endl;
                    cin.ignore();
                    getline(cin, passageiro_atualizado.nome);

                }
                cout << "Deseja alterar a data de nascimento do passageiro: (s/n)" <<endl;
                cin >> resposta_altera;

                if(resposta_altera =='s'){
                    resposta_altera ='\0';
                    altera_dt = true;

                    cout << "Digite Data Nascimento atualizadaa(dd/mm/yyyy):" <<endl;
                    cin >>passageiro_atualizado.dt_nascimento;

                    if(!valida_idade(passageiro_atualizado.dt_nascimento)) {
                        cout << "Sua data de nascimento foi alterada, e você é menor de idade, então preciso que informa o numero de autorizacao:" <<endl;
                        cin >> passageiro_atualizado.num_Autorizacao;
                        altera_autoriza =true;
                    }
                }
                altera_campo(passageiro, passageiro_atualizado, cpf, altera_dt, altera_cpf, altera_nome, altera_autoriza);
                cout << "============================" << endl;

                }else{
                    cout << "CPF invalido!" << endl;
                };
            }else{
                cout << "Passageiro não está na lista" << endl;
                break;
            }; 
                

        cout << "Deseja alterar outro passageiro (s/n)?" <<endl;
        cin >>resposta;

    }while(resposta =='s') ;
}

void localiza_passageiro(vector<Passageiro> &passageiro){

    string cpf;
    char resposta;

    do{
        cout << "Digite o CPF do passageiro que deseja localizar:" <<endl;
        cin >> cpf;
        //chama função para validação
        // verifica se o CPF já está cadastrado
        if (valida_cpf(cpf)){
            if(passageiro.size() == 0){
                cout << "A lista de passageiros ainda está vazia" << endl;
                break;
            }else{
                if(cpf_cadastrado(passageiro, cpf)) {
                    dados_passageiro(passageiro, cpf);
                }else{
                    cout << "Passageiro não localizado" << endl;
                    
                }
            };
        }else{
            cout << "CPF invalido!" << endl;
        };  
        cout << "Deseja localizar outro passageiro (s/n)?" <<endl;
        cin >>resposta;

    }while(resposta =='s'); 
};

// funções para roteiro
bool codigo_roteiro_cadastrado(vector <Roteiro> &roteiro, int codigo){

    if(roteiro.size()> 0){    
        for (const Roteiro& roteiro : roteiro) {
            if(roteiro.codigo == codigo){
                return true;
            };
        };
    };
    return false;
};

bool valida_destino_origem(string destino, string origem){  

    if(destino == origem){
        return true;
    };
    return false;
};

void incluir_roteiro(vector <Roteiro> &roteiro){

    Roteiro roteiro_novo;
    char resposta;

    do{
        cout << "Digite o codigo do Roteiro" << endl;
        cin >> roteiro_novo.codigo;
       if(codigo_roteiro_cadastrado(roteiro, roteiro_novo.codigo)){
            cout << "O codigo do ja cadastrado, tente novamente." <<endl;
            
       }else{
            cout << "Agora digite a data do Roteiro(dd/mm/yy)" << endl;
            cin >> roteiro_novo.data;

            if(!valida_data(roteiro_novo.data)){
                cout << "Nascimento do roteiro invalida, tente novamente." <<endl;
                break;
            }else{
                cout << "digite hora prevista do Roteiro(00:00)" << endl;
                cin >> roteiro_novo.hora;

                if(!valida_horario(roteiro_novo.hora)){
                    cout << "Horario do roteiro invalido, tente novamente." <<endl;
                }else{
                    cout << "Digite a duração prevista do Roteiro:" << endl;
                    cin >> roteiro_novo.duracao;

                    cout << "Digite a origem:" << endl;
                    cin.ignore();
                    getline(cin, roteiro_novo.origem);

                    cout << "Digite o destino:" << endl;
                    cin.ignore();
                    getline(cin, roteiro_novo.destino);

                    if(valida_destino_origem(roteiro_novo.destino, roteiro_novo.origem)){
                        cout << "Origem e Destinos são iguais, tente outras destino ou origem." << endl;

                    }else{
                        roteiro.push_back(roteiro_novo);

                    };

                };
            };
       };
        // verifica se o CPF já está cadastrado 
        cout << "Deseja Adicionar outro roteiro (s/n)?" <<endl;
        cin >>resposta;
    }while(resposta =='s') ; 

};

void dados_roteiros(vector <Roteiro> &roteiro, int codigo){
        cout <<"---------------------Dados dos Roteiros-------------------"<< endl;
        cout << "==========================================================" << endl;
    if(roteiro.size()> 0){    
        for (const Roteiro& roteiro : roteiro) {
            if(roteiro.codigo == codigo){
                cout<<"Codigo: " << roteiro.codigo << 
                "\nData: " <<roteiro.data <<  
                "\nHorario: " << roteiro.hora<<
                "\nOrigem: " << roteiro.origem <<
                "\nDestino: " << roteiro.destino <<
                "\nDuração prevista: " << roteiro.duracao << endl;
                cout << "==========================================================" << endl;
            };
        };

    }else{
        cout <<"Opa, a lista de roteriros ainda esta vazia!!"<< endl;
    }   
};

void lista_roteiros(vector <Roteiro> &roteiro){
        cout <<"---------------------Lista de Roteiros-------------------"<< endl;
        cout << "==========================================================" << endl;
    if(roteiro.size()> 0){    
        for (const Roteiro& roteiro : roteiro) {
            cout<<"Codigo: " << roteiro.codigo << 
            "\nData: " <<roteiro.data <<  
            "\nHorario: " << roteiro.hora<<
            "\nOrigem: " << roteiro.origem <<
            "\nDestino: " << roteiro.destino <<
            "\nDuração prevista: " << roteiro.duracao << endl;
            cout << "==========================================================" << endl;
            cout << "==========================================================" << endl;
        };

    }else{
        cout <<"Opa, a lista de roteriros ainda esta vazia!!"<< endl;
    }   
};

bool remove_roteiro(vector <Roteiro> &roteiro,  int codigo){
    int tamanho;
    tamanho = roteiro.size();
    roteiro.erase(std::remove_if(roteiro.begin(), roteiro.end(),
        [&codigo](const Roteiro& roteiro) {
            return roteiro.codigo == codigo;
        }), roteiro.end());
    if(tamanho > roteiro.size()){
        return true;
    }
    return false;
};

void excluir_roteiro(vector <Roteiro> &roteiro){

    int codigo;
    char resposta;

    do{
        if(roteiro.size() > 0){
            cout << "Digite o codigo do Roteiro" << endl;
            cin >> codigo;

            if(remove_roteiro(roteiro, codigo)){
                cout << "Roteiro excluido da lista" << endl;
            }else{
                cout << "Poxa, não consegui remover o roteiro, tente mais tarde!" << endl;
                break;
            };

        }else{
            cout <<"Opa, a lista de roteriros ainda esta vazia!!"<< endl;
            break;
        };

        cout << "Deseja remover outro passageiro (s/n)?" <<endl;
        cin >>resposta;

    }while(resposta =='s'); 
};

void alterar_campos_roteiro(vector <Roteiro> &roteiro, Roteiro &roteiro_atualizado, int &codigo, bool &alter_data, bool &alter_codigo, bool &alter_hora, bool &alter_orig, bool &alter_dest, bool &alter_durat){

    for (Roteiro &roteiro : roteiro) {
        if (roteiro.codigo == codigo) {
            if(alter_data) {
                roteiro.data = roteiro_atualizado.data;
            }; 
            if(alter_codigo) {
                roteiro.codigo = roteiro_atualizado.codigo;
            }; 
            if(alter_durat) {
                roteiro.data = roteiro_atualizado.duracao;
            };
            if(alter_hora) { 
                roteiro.hora = roteiro_atualizado.hora;
            };
            if(alter_orig) { 
                roteiro.origem = roteiro_atualizado.origem;
            };
            if(alter_dest) { 
                roteiro.destino = roteiro_atualizado.destino;
            };
        };
    };

};

void alterar_roteiro(vector <Roteiro> &roteiro){

    bool alter_data, alter_codigo, alter_hora, alter_orig, alter_dest, alter_durat;
    int codigo;
    Roteiro roteiro_atualizado;
    char resposta, resposta_altera;

        do{
            if(roteiro.size() > 0){
                cout << "Digite o codigo do Roteiro" << endl;
                cin >> codigo;


                cout << "Deseja alterar o codigo do Roteiro: (s/n)" <<endl;
                cin >> resposta_altera;

                if(resposta_altera =='s'){
                    resposta_altera ='\0';
                    alter_codigo = true;

                    cout << "Digite o codigo do roteiro atualizado:" <<endl;
                    cin >> roteiro_atualizado.codigo;
                }
                // altera data
                cout << "Deseja alterar a data do roteiro atualizado: (s/n)" <<endl;
                cin >> resposta_altera;

                if(resposta_altera =='s'){
                    resposta_altera ='\0';
                    alter_data= true;

                    cout << "Digite a data atualizada:" <<endl;
                    cin >> roteiro_atualizado.data;
                }
                // altera horario
                cout << "Deseja alterar a horario do roteiro atualizado: (s/n)" <<endl;
                cin >> resposta_altera;

                if(resposta_altera =='s'){
                    resposta_altera ='\0';
                    alter_hora= true;

                    cout << "Digite o horario atualizado:" <<endl;
                    cin >> roteiro_atualizado.hora;
                }
                // altera origem
                cout << "Deseja alterar a origem do roteiro atualizado: (s/n)" <<endl;
                cin >> resposta_altera;

                if(resposta_altera =='s'){
                    resposta_altera ='\0';
                    alter_orig= true;

                    cout << "Digite o origem atualizado:" <<endl;
                    cin.ignore();
                    getline(cin, roteiro_atualizado.origem);

                }
                // altera destino
                cout << "Deseja alterar a destino do roteiro atualizado: (s/n)" <<endl;
                cin >> resposta_altera;

                if(resposta_altera =='s'){
                    resposta_altera ='\0';
                    alter_dest = true;

                    cout << "Digite o destino do roteiro atualizado:" <<endl;
                    cin.ignore();
                    getline(cin, roteiro_atualizado.destino);

                }
                // altera duração prevista
                cout << "Deseja alterar a duracao prevista do roteiro atualizado: (s/n)" <<endl;
                cin >> resposta_altera;

                if(resposta_altera =='s'){
                    resposta_altera ='\0';
                    alter_durat = true;

                    cout << "Digite o duracao prevista roteiro atualizado:" <<endl;
                    cin >>roteiro_atualizado.duracao;
                };
                alterar_campos_roteiro(roteiro, roteiro_atualizado, codigo, alter_data, alter_codigo, alter_hora, alter_orig, alter_dest, alter_durat);
                cout << "============================" << endl;      
            }else{
                cout <<"Opa, a lista de roteriros ainda esta vazia!!"<< endl;
            };    // verifica se o CPF já está cadastrado 


        cout << "Deseja alterar outro roteiro (s/n)?" <<endl;
        cin >>resposta;

    }while(resposta =='s');
}

void localiza_roteiro(vector <Roteiro> &roteiro){

    int codigo;
    char resposta;

    do{
        if(roteiro.size() > 0){
            cout << "Digite o codigo do Roteiro que deseja localizar" << endl;
            cin >> codigo;

            if(codigo_roteiro_cadastrado(roteiro, codigo)){
                dados_roteiros(roteiro, codigo);
            }else{
                cout << "Roteiro não localizado" << endl;   
                }
        }else{
            cout <<"Opa, a lista de roteriros ainda esta vazia!!"<< endl;
            break;
        }; 
        cout << "Deseja localizar outro passageiro (s/n)?" <<endl;
        cin >>resposta;

    }while(resposta =='s'); 
};


