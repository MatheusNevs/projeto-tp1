#include "../../include/views/auth.hpp"

void AuthView::execute(Code &userCode)
{
  this->userCode = &userCode;

  while (true)
  {
    try
    {
      // Limpa o terminal
      cout << "\033[2J\033[1;1H";

      if (this->userCode == nullptr)
      {

        // Aparece as opções
        cout << "=======================" << endl;
        cout << "  Sistema de Autenticação" << endl;
        cout << "=======================" << endl;
        cout << "1. Autenticar" << endl;
        cout << "2. Criar conta" << endl;
        cout << "3. Sair" << endl;
        cout << "Escolha uma opção: ";
        int option;
        cin >> option;

        // Limpa o terminal
        cout << "\033[2J\033[1;1H";

        // Executa a opção escolhida
        switch (option)
        {
        case 1:
          autenticate(&userCode);
        case 2:
          create(&userCode);
        default:
          return;
        }
      }
      else
      {
        // Aparece as opções
        cout << "=======================" << endl;
        cout << "  Sistema de Autenticação" << endl;
        cout << "=======================" << endl;
        cout << "1. Logout" << endl;
        cout << "2. Sair" << endl;
        cout << "Escolha uma opção: ";
        int option;
        cin >> option;

        // Limpa o terminal
        cout << "\033[2J\033[1;1H";

        // Executa a opção escolhida
        switch (option)
        {
        case 1:
          logout(&userCode);
        default:
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

void AuthView::create(Code *userCode)
{
  string password;

  cout << "=======================" << endl;
  cout << "      Criar conta" << endl;
  cout << "=======================" << endl;
  cout << "Digite uma senha para sua conta: ";
  cout << " - A senha deve possuir 5 digitos" << endl;
  cout << " - Não pode conter digitos duplicados" << endl;
  cout << " - Não pode estar em ordem crescente ou descrescente" << endl;
  cin >> password;
  Code userCodeDomain = Code();
  Password passwordDomain = Password(password);
  authService->create(userCodeDomain, passwordDomain);
  *userCode = userCodeDomain;
  cout << "Sua conta foi criada com o código " << userCodeDomain.getValue();
}

void AuthView::autenticate(Code *userCode)
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
    *userCode = codeDomain;
    return;
  }

  throw invalid_argument("Falha na autenticação, senha ou código inválidos");
}