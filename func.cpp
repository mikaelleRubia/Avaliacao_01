void listar_ocorrencia(vector<Embarque> &embarques)
{
    string cpf;

    cout << "Digite o CPF do passageiro: ";
    cin >> cpf;

    cout << "==========Dados dos Ocorrencia========== \n\n" << endl;
    for (Embarque embarque : embarques)
    {
        if(embarque.cpf_passageiro == cpf){
            cout << "Descricao"<< embarque.cpf_passageiro << endl;
            cout << "Descricao"<< embarque.ocorrencia.Descricao << endl;
            cout << "Data" << embarque.ocorrencia.data<< endl;
            cout << "Hora" << embarque.ocorrencia.hora<< endl;
            cout << "num Apolice" << embarque.ocorrencia.numero_Apolice<< endl;
        }
    }
    cout << "=============================================\n\n";
}
/////////////////////////////////////

void alterar_OcorrenciaPorCPF(vector<Embarque> &embarques) 
{
    string cpf;
    int codigo;
    bool encontrou_embarque = false;

    cout << "========== Alterar Ocorrência ==========\n";
    cout << "Digite o CPF do passageiro: ";
    cin >> cpf;

    cout << "Digite o código do roteiro: ";
    cin >> codigo;

    // Procurar pelo embarque correspondente
    for (Embarque &e : embarques) {
        if (e.cpf_passageiro == cpf && e.codigo_roteiro == codigo) {
            encontrou_embarque = true;

            cout << "\n========== Dados da Ocorrência ==========\n";
            cout << "Descrição atual da ocorrência: " << e.ocorrencia.Descricao << endl;
            cout << "Deseja alterar a descrição? (S/N): ";
            char opcao;
            cin >> opcao;

            if (opcao == 'S' || opcao == 's') {
                cout << "Digite a nova descrição da ocorrência: ";
                cin.ignore();
                getline(cin, e.ocorrencia.Descricao);
            }

            cout << "Data atual da ocorrência: " << e.ocorrencia.data << endl;
            cout << "Deseja alterar a data? (S/N): ";
            cin >> opcao;

            if (opcao == 'S' || opcao == 's') {
                do {
                    cout << "Digite a nova data da ocorrência (formato: DD/MM/AAAA): ";
                    cin >> e.ocorrencia.data;
                } while (!valida_data(e.ocorrencia.data));
            }

            cout << "Número da apólice atual: " << e.ocorrencia.numero_Apolice << endl;
            cout << "Deseja alterar o número da apólice? (S/N): ";
            cin >> opcao;

            if (opcao == 'S' || opcao == 's') {
                do {
                    cout << "Digite o novo número da apólice: ";
                    cin >> e.ocorrencia.numero_Apolice;
                } while (verifica_apolice_cadastro(embarques, e.ocorrencia.numero_Apolice));
            }

            cout << "Ocorrência alterada com sucesso!" << endl;
            break;
        }
    }

    if (!encontrou_embarque) {
        cout << "Não encontramos esse embarque!" << endl;
    }
}


void listar_ocorrenciaPorRoteiro(vector<Embarque> &embarques)
{
    int codigo;

    cout << "Digite o codigo do Roteiro: ";
    cin >> codigo;

    cout << "==========Dados dos Ocorrencia========== \n\n" << endl;
    for (Embarque embarque : embarques)
    {
        if(embarque.codigo_roteiro == codigo){
            cout << "Descricao"<< embarque.cpf_passageiro << endl;
            cout << "Descricao"<< embarque.ocorrencia.Descricao << endl;
            cout << "Data" << embarque.ocorrencia.data<< endl;
            cout << "Hora" << embarque.ocorrencia.hora<< endl;
            cout << "num Apolice" << embarque.ocorrencia.numero_Apolice<< endl;
        }
    }
    cout << "=============================================\n\n";
}
