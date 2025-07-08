#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    string nome_utilizador;
    int comprimento;
    string senha;
    string caracteres = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+[]{}<>?/";

    // Pede o nome de utilizador
    cout << "Digite o seu nome de utilizador: ";
    cin >> nome_utilizador;

    // Pede o comprimento da senha
    cout << "Digite o comprimento da senha: ";
    cin >> comprimento;

    // Inicializa o gerador de números aleatórios
    srand(time(0));

    // Gera a senha
    for (int i = 0; i < comprimento; ++i) {
        int indice = rand() % caracteres.size();
        senha += caracteres[indice];
    }

    // Mostra o nome de utilizador e a senha gerada
    cout << "Utilizador: " << nome_utilizador << endl;
    cout << "Senha gerada: " << senha << endl;

    return 0;
}

