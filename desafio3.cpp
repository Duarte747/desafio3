#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

int main() {
    string nome_utilizador;
    int comprimento;
    string caracteres = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+[]{}<>?/";
    char opcao;

    srand(time(0)); // Inicializar gerador de números aleatórios apenas uma vez

    do {
        string senha = ""; // Limpar senha anterior

        // Obter dados do utilizador
        cout << "Digite o seu nome de utilizador: ";
        cin >> nome_utilizador;

        cout << "Digite o comprimento da senha: ";
        cin >> comprimento;

        // Gerar a senha aleatória
        for (int i = 0; i < comprimento; ++i) {
            int indice = rand() % caracteres.size();
            senha += caracteres[indice];
        }

        // Mostrar os resultados
        cout << "Utilizador: " << nome_utilizador << endl;
        cout << "Senha gerada: " << senha << endl;

        // Guardar a senha num ficheiro
        ofstream ficheiro("senhas.txt", ios::app);
        if (ficheiro.is_open()) {
            ficheiro << "Utilizador: " << nome_utilizador << endl;
            ficheiro << "Senha gerada: " << senha << endl;
            ficheiro << "--------------------------" << endl;
            ficheiro.close();
        } else {
            cout << "Erro ao abrir o ficheiro para escrita." << endl;
        }

        // Perguntar se quer continuar
        cout << "Deseja gerar outra senha? (s/n): ";
        cin >> opcao;

    } while (opcao == 's' || opcao == 'S');

    cout << "Programa encerrado." << endl;
    return 0;
}

