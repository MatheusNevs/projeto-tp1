# Projeto TP1

O projeto usa um **Makefile** para automatizar o processo de compilação e execução.

---

## Estrutura de Diretórios

- include/    -> Contém arquivos de cabeçalho (.hpp)

- source/     -> Contém arquivos fonte (.cpp) principais

- lib/utils/  -> Contém funções úteis para a implementação do projeto

- test/       -> Contém arquivos de teste

## Comandos do Makefile

### Compilar tudo

```bash
make
```

Este comando compila todos os arquivos .cpp em suas respectivas pastas e gera os executáveis principais (test_domain e test_entity).

### Executar o programa

```bash
make run
```

Este comando executa o programa após a compilação, mostrando o resultado de todos os testes.

### Gerar documentação externa

```bash
doxygen
```

Este comando cria a pasta docs, contendo a documentação em HTML gerada pelo doxygen.

### Limpar os arquivos gerados

```bash
make clean
```

Este comando remove os executáveis (test_domain e test_entity), todos os arquivos objeto (.o) e a pasta "docs" gerada pelo doxygen, garantindo que o projeto esteja "limpo" para uma nova compilação.
