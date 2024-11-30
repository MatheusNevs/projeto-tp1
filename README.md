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

Este comando compila todos os arquivos .cpp em suas respectivas pastas e gera o executável principal (program).

### Executar o programa

```bash
make run
```

Este comando executa o programa após a compilação.

### Limpar os arquivos gerados

```bash
make clean
```

Este comando remove o executável (program) e todos os arquivos objeto (.o), garantindo que o projeto esteja "limpo" para uma nova compilação.
