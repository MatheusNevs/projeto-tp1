#include "../../include/views/travel.hpp"

void TravelView::execute(Code userCode)
{
  this->userCode = userCode;

  while (true)
  {
    // Limpa o terminal
    cout << "\033[2J\033[1;1H";

    // Aparece as opções
    cout << "=======================" << endl;
    cout << "  Sistema de Viagens" << endl;
    cout << "=======================" << endl;
    cout << "1. Criar viagem" << endl;
    cout << "2. Atualizar viagem" << endl;
    cout << "3. Deletar viagem" << endl;
    cout << "4. Listar viagens" << endl;
    cout << "5. Consultar viagem" << endl;
    cout << "6. Sair" << endl;
    cout << "Escolha uma opção: ";
    int option;
    cin >> option;

    // Limpa o terminal
    cout << "\033[2J\033[1;1H";

    // Executa a opção escolhida
    if (option == 1)
      create();
    else if (option == 2)
      update();
    else if (option == 3)
      remove();
    else if (option == 4)
      listAll();
    // else if (option == 5)
    //   consultTravel();
    // Sai do sistema de viagem
    else
    {
      return;
    }
  }
}

void TravelView::create()
{
  try
  {
    Code code = Code();
    Rating rating = Rating("0");
    string name;
    cout << "=======================" << endl;
    cout << "    Criar viagens" << endl;
    cout << "=======================" << endl;
    cout << "1. Digite o nome da viagem: ";
    cin >> name;
    Name nameDomain = Name(name);

    Travel travel = Travel(code, nameDomain, rating);
    travelService->create(userCode, travel);

    cout << endl
         << "======= SUCESSO ======= " << endl
         << endl;
  }
  catch (const std::exception &e)
  {
    cout << "======== ERROR ========" << endl;
    cout << e.what() << endl;
    cout << "======== ERROR ========" << endl;
  }
  cout << "Pressione Enter para continuar...";
  cin.ignore();
  cin.get();
}
void TravelView::update()
{
  try
  {
    Code code;
    string codeStr;
    cout << "=======================" << endl;
    cout << "    Atualizar viagem" << endl;
    cout << "=======================" << endl;
    cout << "1. Digite o código da viagem a ser atualizada: ";
    cin >> codeStr;
    code = Code(codeStr);

    string name;
    cout << "2. Digite o novo nome da viagem: ";
    cin >> name;
    Name nameDomain = Name(name);

    string rating;
    cout << "3. Digite a nova avaliação da viagem: ";
    cin >> rating;
    Rating ratingDomain = Rating(rating);

    Travel travel = Travel(code, nameDomain, ratingDomain);
    travelService->update(userCode, code, travel);

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

void TravelView::remove()
{
  try
  {
    Code code;
    string codeStr;
    cout << "=======================" << endl;
    cout << "    Deletar viagem" << endl;
    cout << "=======================" << endl;
    cout << "1. Digite o código da viagem: ";
    cin >> codeStr;
    code = Code(codeStr);

    travelService->remove(userCode, code);

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

void TravelView::listAll()
{
  try
  {
    cout << "=======================" << endl;
    cout << "    Listar viagens" << endl;
    cout << "=======================" << endl;

    vector<Travel> travels = travelService->readAll(userCode);
    for (const auto &travel : travels)
    {
      cout << "Código: " << travel.get("code").getValue() << endl;
      cout << "Nome: " << travel.get("name").getValue() << endl;
      cout << "Avaliação: " << travel.get("rating").getValue() << endl;
      cout << "=======================" << endl;
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

// void TravelView::consultTravel()
// {
//   try
//   {
//     Code code;
//     string codeStr;
//     cout << "=======================" << endl;
//     cout << "    Consultar viagem" << endl;
//     cout << "=======================" << endl;
//     cout << "1. Digite o código da viagem: ";
//     cin >> codeStr;
//     code = Code(codeStr);

//     Travel travel = travelService->findByCode(userCode, code);

//     cout << "Código: " << travel.getCode().getValue() << endl;
//     cout << "Nome: " << travel.getName().getValue() << endl;
//     cout << "=======================" << endl;
//   }
//   catch (const std::exception &e)
//   {
//     cout << "ERROR!!!" << endl;
//     cout << e.what() << endl;
//     cout << "ERROR!!!" << endl;
//   }
// }