#include "../../include/views/auth.hpp"

void AuthView::execute(Code &userCode)
{
  this->userCode = userCode;

  while (true)
  {
    try
    {
      cout << "\033[2J\033[1;1H";

      if (this->userCode.getValue() != "000000")
      {
        // Aparece as opções
        cout << "=======================" << endl;
        cout << "  Sistema de Autenticação" << endl;
        cout << "=======================" << endl;
        cout << "1. Logout" << endl;
        cout << "2. Retornar" << endl;
        cout << "Escolha uma opção: ";
        int option;
        cin >> option;

        // Limpa o terminal
        cout << "\033[2J\033[1;1H";

        // Executa a opção escolhida
        if (option == 1)
          logout();
        else
          return;
      }
      else
      {
        cout << "=======================" << endl;
        cout << "  Sistema de Autenticação" << endl;
        cout << "=======================" << endl;
        cout << "1. Autenticar" << endl;
        cout << "2. Criar conta" << endl;
        cout << "3. Sair" << endl;
        cout << "Escolha uma opção: ";
        string option;
        cin >> option;

        // Limpa o terminal
        cout << "\033[2J\033[1;1H";

        // Executa a opção escolhida
        if (option == "1")
        {
          autenticate();
        }
        else if (option == "2")
        {
          create();
        }
        else
        {
          return;
        }
      }

      cout << endl
           << "======= SUCESSO ======= " << endl
           << endl;
    }
    catch (const std::exception &e)
    {
      cout << endl
           << "======== ERROR ========" << endl;
      cout << e.what() << endl;
      cout << "======== ERROR ========" << endl
           << endl;
    }

    cout << "Pressione Enter para continuar...";
    cin.ignore();
    cin.get();
  }
}

void AuthView::create()
{
  string password;

  cout << "=======================" << endl;
  cout << "      Criar conta" << endl;
  cout << "=======================" << endl;
  cout << "Digite uma senha para sua conta: " << endl;
  cout << " - A senha deve possuir 5 digitos" << endl;
  cout << " - Não pode conter digitos duplicados" << endl;
  cout << " - Não pode estar em ordem crescente ou descrescente" << endl;
  cin >> password;
  Code userCodeDomain = Code();
  Password passwordDomain = Password(password);
  authService->create(userCodeDomain, passwordDomain);
  userCode.setValue(userCodeDomain.getValue());
  cout << "Sua conta foi criada com o código " << userCodeDomain.getValue() << endl;
  return;
}

void AuthView::autenticate()
{
  string password, code;
  cout << "=======================" << endl;
  cout << "      Autenticar" << endl;
  cout << "=======================" << endl;
  cout << "Digite o código da sua conta: ";
  cin >> code;
  Code codeDomain = Code(code);
  cout << "Digite a senha da sua conta: ";
  cin >> password;
  Password passwordDomain = Password(password);

  if (authService->autenticate(codeDomain, passwordDomain))
  {
    userCode.setValue(codeDomain.getValue());
    return;
  }

  throw invalid_argument("Falha na autenticação, senha ou código inválidos");
}

void AuthView::logout()
{
  userCode.setValue("000000");
  return;
}