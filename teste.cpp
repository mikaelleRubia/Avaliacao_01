#include <iostream>
#include <string>
#include <vector>

struct Passageiro {
    std::string cpf;
};

bool cpf_cadastrado(const std::vector<Passageiro>& passageiros, const std::string& cpf) {
    int tamanho = passageiros.size();

    for (int i = 0; i < tamanho; i++) {
        if (cpf == passageiros[i].cpf) {
            return true; // O CPF já está cadastrado, então retornamos true
        }
    }

    return false; // Se chegarmos aqui, nenhum CPF correspondente foi encontrado, então retornamos false
}

int main() {
    std::vector<Passageiro> Passageiros;
    Passageiros.push_back({"05792803579"}); // Adiciona um passageiro com CPF

    std::string cpf = "05792803579";


    if (cpf_cadastrado(Passageiros, cpf)) {
        std::cout << "CPF já cadastrado." << std::endl;
    } else {
        std::cout << "CPF não cadastrado." << std::endl;
    }

    return 0;
}
