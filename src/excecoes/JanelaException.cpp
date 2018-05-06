/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#include "JanelaException.h"

namespace bolhas { namespace excecoes {
    JanelaException::JanelaException(const std::string mensagem) : 
    mensagem(mensagem) { 
    }

    JanelaException::~JanelaException() {}
}}


