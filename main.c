#include <stdio.h>
#include <stdbool.h> //library booleana

// conta os caracteres
int calculaTamanho(char *textoEntrada) {
    int tamanhoAtual = 0;
    while (textoEntrada[tamanhoAtual] != '\0') {
        tamanhoAtual++;
    }
    return tamanhoAtual;
}

// limpa o enter
void removeQuebraLinha(char *textoEntrada) {
    int indiceAtual = 0;
    while (textoEntrada[indiceAtual] != '\0') {
        // acha o enter
        if (textoEntrada[indiceAtual] == '\n') {
            // troca por nulo
            textoEntrada[indiceAtual] = '\0'; 
            break;
        }
        indiceAtual++;
    }
}

// checa se minuscula
bool ehMinuscula(char letraAtual) {
    return (letraAtual >= 'a' && letraAtual <= 'z');
}

// checa se maiuscula
bool ehMaiuscula(char letraAtual) {
    return (letraAtual >= 'A' && letraAtual <= 'Z');
}

// checa se numero
bool ehNumero(char digitoAtual) {
    return (digitoAtual >= '0' && digitoAtual <= '9');
}

// valida o nome
bool validaNome(char *nomeCompleto) {
    int indiceAtual = 0;

    // exige primeira maiuscula
    if (!ehMaiuscula(nomeCompleto[indiceAtual])) return false;
    indiceAtual++;

    // le primeiro nome
    while (nomeCompleto[indiceAtual] != ' ' && nomeCompleto[indiceAtual] != '\0') {
        if (!ehMinuscula(nomeCompleto[indiceAtual])) return false;
        indiceAtual++;
    }

    // exige um espaco
    if (nomeCompleto[indiceAtual] != ' ') return false;
    indiceAtual++;

    // exige maiuscula sobrenome
    if (!ehMaiuscula(nomeCompleto[indiceAtual])) return false;
    indiceAtual++;

    // le resto sobrenome
    while (nomeCompleto[indiceAtual] != '\0') {
        if (!ehMinuscula(nomeCompleto[indiceAtual])) return false;
        indiceAtual++;
    }

    return true; 
}

// valida o email
bool validaEmail(char *enderecoEmail) {
    int indiceAtual = 0;
    int posicaoArroba = -1;
    int contadorArroba = 0;

    // procura o arroba
    while (enderecoEmail[indiceAtual] != '\0') {
        if (enderecoEmail[indiceAtual] == '@') {
            contadorArroba++;
            posicaoArroba = indiceAtual;
        }
        indiceAtual++;
    }

    // exige unico arroba
    if (contadorArroba != 1 || posicaoArroba == 0) return false; 

    // checa antes arroba
    for (int i = 0; i < posicaoArroba; i++) {
        if (!ehMinuscula(enderecoEmail[i])) return false;
    }

    int tamanhoTotal = calculaTamanho(enderecoEmail);

    // checa tamanho minimo
    if (tamanhoTotal < posicaoArroba + 5) return false;

    // checa depois arroba
    for (int i = posicaoArroba + 1; i < tamanhoTotal - 3; i++) {
        if (!ehMinuscula(enderecoEmail[i])) return false; 
    }

    // checa final br
    if (enderecoEmail[tamanhoTotal - 3] != '.' ||
        enderecoEmail[tamanhoTotal - 2] != 'b' ||
        enderecoEmail[tamanhoTotal - 1] != 'r') {
        return false;
    }

    return true;
}

// valida a senha
bool validaSenha(char *senhaEntrada) {
    // exige oito caracteres
    if (calculaTamanho(senhaEntrada) != 8) return false;

    int totalMaiusculas = 0;
    int totalNumeros = 0;

    // percorre a senha
    for (int i = 0; i < 8; i++) {
        char caractereAtual = senhaEntrada[i];

        if (ehMaiuscula(caractereAtual)) totalMaiusculas++;
        else if (ehNumero(caractereAtual)) totalNumeros++;
        else if (!ehMinuscula(caractereAtual)) return false;
    }

    // exige maiuscula numero
    if (totalMaiusculas < 1 || totalNumeros < 1) return false;

    return true;
}

// valida o cpf
bool validaCpf(char *numeroCpf) {
    // exige quatorze caracteres
    if (calculaTamanho(numeroCpf) != 14) return false;

    // checa o formato
    for (int i = 0; i < 14; i++) {
        if (i == 3 || i == 7) {
            // exige os pontos
            if (numeroCpf[i] != '.') return false;
        } 
        else if (i == 11) {
            // exige o traco
            if (numeroCpf[i] != '-') return false;
        } 
        else {
            // exige apenas numeros
            if (!ehNumero(numeroCpf[i])) return false;
        }
    }

    return true;
}

// valida o telefone
bool validaTelefone(char *numeroTelefone) {
    int tamanhoTotal = calculaTamanho(numeroTelefone); 

    // formato quinze caracteres
    if (tamanhoTotal == 15) {
        if (numeroTelefone[0] == '(' && ehNumero(numeroTelefone[1]) && ehNumero(numeroTelefone[2]) &&
            numeroTelefone[3] == ')' && numeroTelefone[4] == ' ' && numeroTelefone[5] == '9' &&
            ehNumero(numeroTelefone[6]) && ehNumero(numeroTelefone[7]) && ehNumero(numeroTelefone[8]) &&
            ehNumero(numeroTelefone[9]) && numeroTelefone[10] == '-' && ehNumero(numeroTelefone[11]) &&
            ehNumero(numeroTelefone[12]) && ehNumero(numeroTelefone[13]) && ehNumero(numeroTelefone[14])) {
            return true; 
        }
    }

    // formato quatorze caracteres
    if (tamanhoTotal == 14) {
        if (numeroTelefone[0] == '(' && ehNumero(numeroTelefone[1]) && ehNumero(numeroTelefone[2]) &&
            numeroTelefone[3] == ')' && numeroTelefone[4] == ' ' && numeroTelefone[5] == '9' &&
            ehNumero(numeroTelefone[6]) && ehNumero(numeroTelefone[7]) && ehNumero(numeroTelefone[8]) &&
            ehNumero(numeroTelefone[9]) && ehNumero(numeroTelefone[10]) && ehNumero(numeroTelefone[11]) &&
            ehNumero(numeroTelefone[12]) && ehNumero(numeroTelefone[13])) {
            return true; 
        }
    }

    // formato doze caracteres
    if (tamanhoTotal == 12) {
        if (ehNumero(numeroTelefone[0]) && ehNumero(numeroTelefone[1]) && numeroTelefone[2] == ' ' &&
            numeroTelefone[3] == '9' && ehNumero(numeroTelefone[4]) && ehNumero(numeroTelefone[5]) &&
            ehNumero(numeroTelefone[6]) && ehNumero(numeroTelefone[7]) && ehNumero(numeroTelefone[8]) &&
            ehNumero(numeroTelefone[9]) && ehNumero(numeroTelefone[10]) && ehNumero(numeroTelefone[11])) {
            return true; 
        }
    }

    return false;
}

// executa bloco principal
int main() {
    // cria os vetores
    char entradaNome[100];
    char entradaEmail[100];
    char entradaSenha[100];
    char entradaCpf[20];
    char entradaTelefone[20];

    // coleta o nome
    printf("Digite o nome (Ex: Alan Turing): ");
    fgets(entradaNome, 100, stdin);
    removeQuebraLinha(entradaNome);

    // coleta o email
    printf("Digite o email (Ex: divulga@ufpa.br): ");
    fgets(entradaEmail, 100, stdin);
    removeQuebraLinha(entradaEmail);

    // coleta a senha
    printf("Digite a senha (Ex: 518R2r5e): ");
    fgets(entradaSenha, 100, stdin);
    removeQuebraLinha(entradaSenha);

    // coleta o cpf
    printf("Digite o CPF (Ex: 123.456.789-09): ");
    fgets(entradaCpf, 20, stdin);
    removeQuebraLinha(entradaCpf);

    // coleta o telefone
    printf("Digite o telefone (Ex: (91) 99999-9999): ");
    fgets(entradaTelefone, 20, stdin);
    removeQuebraLinha(entradaTelefone);

    // quebra de linha
    printf("\n--- RESULTADOS ---\n");

    // valida o nome
    if (validaNome(entradaNome)) printf("Nome: ACEITO\n");
    else printf("Nome: REJEITADO\n");

    // valida o email
    if (validaEmail(entradaEmail)) printf("Email: ACEITO\n");
    else printf("Email: REJEITADO\n");

    // valida a senha
    if (validaSenha(entradaSenha)) printf("Senha: ACEITO\n");
    else printf("Senha: REJEITADO\n");

    // valida o cpf
    if (validaCpf(entradaCpf)) printf("CPF: ACEITO\n");
    else printf("CPF: REJEITADO\n");

    // valida o telefone
    if (validaTelefone(entradaTelefone)) printf("Telefone: ACEITO\n");
    else printf("Telefone: REJEITADO\n");

    // finaliza o programa
    return 0;
}