# 🛡️ Validador de Cadeias (Simulação de Expressões Regulares)

Este repositório contém o código fonte e a resolução da atividade prática da disciplina de **Teoria da Computação**, integrante do programa de **Mestrado em Ciência da Computação (PPGCC) da Universidade Federal do Pará (UFPA)**.

## 📖 Sobre o Projeto

O preenchimento e a validação de formulários são tarefas essenciais para garantir a integridade de dados em aplicações. O objetivo deste trabalho foi desenvolver um conjunto de máscaras de validação para verificar se determinadas cadeias de caracteres (strings digitadas pelo usuário) pertencem a uma linguagem específica, baseando-se em conceitos de expressões regulares e autômatos finitos.

Os campos que precisavam ser validados com base em regras estritas foram:
- **Nome** (Nome e sobrenome, iniciando com maiúsculas)
- **E-mail** (Formato padrão terminando em `.br`)
- **Senha** (Tamanho exato de 8 caracteres, mesclando letras e números)
- **CPF** (Formato `xxx.xxx.xxx-xx`)
- **Telefone** (Formatos variados como `(xx) 9xxxx-xxxx` ou `xx 9xxxxxxxx`)

## ⚙️ Implementação e Resolução do Problema

A resolução foi inteiramente implementada na **linguagem C**. A escolha do C se deu pelo alto nível de controle sobre a manipulação de memória e vetores de caracteres (*strings*). 

Em vez de importar bibliotecas prontas de expressões regulares (`regex.h`), o problema foi resolvido de forma estrutural, implementando funções algorítmicas que simulam a transição de estados de um autômato finito determinístico (AFD) de forma procedural. O código avança iterativamente pelas cadeias de caracteres, validando-as contra três alfabetos predefinidos:

*   $\Sigma = \{a, b, c, ..., z\}$ (Letras minúsculas)
*   $\Gamma = \{A, B, C, ..., Z\}$ (Letras maiúsculas)
*   $N = \{0, 1, 2, ..., 9\}$ (Números)

### 🛠️ Estrutura do Código

Para modularizar o sistema, o código foi dividido em pequenas funções de checagem:
1.  **Funções de Alfabeto:** `ehMinuscula()`, `ehMaiuscula()`, `ehNumero()` validam a pertinência do caractere atual aos alfabetos da regra.
2.  **Funções de Tratamento:** `calculaTamanho()` e `removeQuebraLinha()` garantem a higienização do *buffer* de entrada (removendo o `\n` inserido pelo `fgets`).
3.  **Máscaras de Validação:** 
    *   `validaNome()`: Percorre a string verificando os espaçamentos e a regra de letras iniciais maiúsculas.
    *   `validaEmail()`: Localiza o caractere `@`, garantindo ser único, e verifica as strings ao redor e o sufixo `.br`.
    *   `validaSenha()`: Checa o tamanho rígido (8) e atua como um contador garantindo as intersecções de alfabetos necessárias.
    *   `validaCpf()` e `validaTelefone()`: Validam os formatos estáticos utilizando posições indexadas do vetor de *char* para casar pontuações (como `.` e `-`) e números.

## 🚀 Como Executar

Para rodar este projeto na sua máquina, você precisará de um compilador C (como o GCC).



