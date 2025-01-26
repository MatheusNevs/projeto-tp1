# Projeto TP1

O projeto utiliza **CMake** para automatizar o processo de compilação e execução, além de facilitar o gerenciamento de dependências e configurações de build.

---

## Estrutura de Diretórios

- **include/** -> Contém arquivos de cabeçalho (.hpp).

- **source/** -> Contém arquivos fonte (.cpp) principais.

- **lib/** -> Contém bibliotecas e funções auxiliares.

- **test/** -> Contém arquivos de teste.

---

## Configuração e Compilação

### Pré-requisitos

Certifique-se de ter as seguintes ferramentas instaladas:

- **CMake** (versão mínima 3.10).
- **Compilador C++** compatível com o padrão C++17.
- **SQLite3** (biblioteca necessária para o projeto).

### Passos para Compilar

1. Crie uma pasta para os arquivos de build:

   ```bash
   mkdir build && cd build
   ```

2. Configure o projeto com o CMake:

   - Para build de **Debug**:

     ```bash
     cmake -DCMAKE_BUILD_TYPE=Debug ..
     ```

   - Para build de **Release**:
     ```bash
     cmake -DCMAKE_BUILD_TYPE=Release ..
     ```

3. Compile o projeto:

   ```bash
   make
   ```

4. Execute o programa:

   ```bash
   ./ProjetoTP1
   ```

---

## Comandos Úteis

### Compilação Limpa

Para limpar os arquivos gerados pela compilação:

```bash
make clean
```

### Gerar Documentação com Doxygen

Se a ferramenta Doxygen estiver instalada, você pode gerar a documentação do projeto:

```bash
doxygen
```

Os arquivos gerados estarão disponíveis na pasta `docs/`.

---

## Dependências

O projeto depende da biblioteca SQLite3. Certifique-se de que ela esteja instalada no sistema antes de compilar. No Ubuntu, você pode instalá-la com:

```bash
sudo apt install libsqlite3-dev
```

Para gerar os gráficos do doxygen também será preciso de uma biblioteca a mais:

```bash
sudo apt install graphviz
```

---

## Sobre o Projeto

O Projeto TP1 é um trabalho acadêmico que explora conceitos de desenvolvimento modular em C++, utilizando boas práticas de organização de código e ferramentas modernas como CMake para gerenciar o processo de build.
