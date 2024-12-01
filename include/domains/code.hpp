#ifndef CODE_HPP 
#define CODE_HPP 

#include "./domain.hpp"

/** 
 * @class Code
 * @brief Representa um código alfanumérico validado.
 * 
 * A classe `Code` herda de `Domain` e implementa validação específica para 
 * códigos alfanuméricos de tamanho fixo.
 */
class Code : public Domain
{
private:
    static const int codeLength = 6; ///< Comprimento fixo do código.

    /**
     * @brief Valida o código fornecido.
     * 
     * Verifica se o código possui o tamanho especificado e atende aos requisitos 
     * de formato.
     * 
     * @param value Código a ser validado.
     * @throw invalid_argument Se o código for inválido.
     */
    void validate(string value) override;

public:
    /**
     * @brief Construtor da classe `Code`.
     * 
     * Inicializa a instância validando e definindo o valor do código.
     * 
     * @param value Código inicial.
     * @throw invalid_argument Se o código for inválido.
     */
    Code(string value);
};


inline Code::Code(string value)
{
  this->setValue(value);
}

#endif
