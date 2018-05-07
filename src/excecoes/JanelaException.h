/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#ifndef JANELAEXCEPTION_H
#define JANELAEXCEPTION_H

#include <exception>
#include <string>

namespace bolhas { namespace excecoes {
    class JanelaException : std::exception {
        std::string mensagem;
        
    public:
        JanelaException(std::string mensagem);
        const char * what () const throw () {
            return mensagem.c_str();
        }
        ~JanelaException();

    };
}}

#endif /* JANELAEXCEPTION_H */

