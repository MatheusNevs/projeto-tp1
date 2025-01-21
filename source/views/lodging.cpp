#include "../../include/views/lodging.hpp"

void LodgingView::execute(Code &userCode)
{
  this->userCode = userCode;

  while (true)
  {
    try
    {
      // Limpa o terminal
      cout << "\033[2J\033[1;1H";

      // Aparece as opções
      cout << "=======================" << endl;
      cout << "  Sistema de Hospedagem" << endl;
      cout << "=======================" << endl;
      cout << "1. Criar hospedagem" << endl;
      cout << "2. Listar hospedagens" << endl;
      cout << "3. Atualizar hospedagem" << endl;
      cout << "4. Deletar hospedagem" << endl;
      cout << "5. Retornar" << endl;
      cout << "Escolha uma opção: ";
      int option;
      cin >> option;

      // Limpa o terminal
      cout << "\033[2J\033[1;1H";

      // Executa a opção escolhida
      if (option == 1)
      {
        create();
      }
      else if (option == 2)
      {
        read();
      }
      else if (option == 3)
      {
        update();
      }
      else if (option == 4)
      {
        remove();
      }
      else
      {
        return;
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

void LodgingView::create()
{
  Code code = Code();
  Rating rating = Rating("0");
  string name, dailyRate, lodgingDestinationCode;

  cout << "=======================" << endl;
  cout << "    Criar hospedagem" << endl;
  cout << "=======================" << endl;
  cout << "1. Digite o nome da hospedagem: ";
  cin >> name;
  Name nameDomain = Name(name);

  cout << "2. Digite o valor da diária: ";
  cin >> dailyRate;
  Money dailyRateDomain = Money(dailyRate);

  cout << "3. Digite o código do destino atrelado: ";
  cin >> lodgingDestinationCode;
  Code lodgingDestinationCodeDomain = Code(lodgingDestinationCode);

  Lodging lodging = Lodging(code, nameDomain, dailyRateDomain, rating);
  lodgingService->create(userCode, lodgingDestinationCodeDomain, lodging);
}

void LodgingView::update()
{
  string codeStr, name, dailyRate, rating;
  cout << "=======================" << endl;
  cout << "    Atualizar hospedagem" << endl;
  cout << "=======================" << endl;
  cout << "1. Digite o código da hospedagem a ser atualizada: ";
  cin >> codeStr;
  Code codeDomain = Code(codeStr);

  cout << "2. Digite o novo nome da hospedagem: ";
  cin >> name;
  Name nameDomain = Name(name);

  cout << "3. Digite o novo valor da diária: ";
  cin >> dailyRate;
  Money dailyRateDomain = Money(dailyRate);

  cout << "4. Digite a nova avaliação da hospedagem: ";
  cin >> rating;
  Rating ratingDomain = Rating(rating);

  Lodging lodging = Lodging(codeDomain, nameDomain, dailyRateDomain, ratingDomain);
  lodgingService->update(userCode, codeDomain, lodging);
}

void LodgingView::remove()
{
  string codeStr;

  cout << "=======================" << endl;
  cout << "    Deletar hospedagem" << endl;
  cout << "=======================" << endl;
  cout << "1. Digite o código da hospedagem: ";
  cin >> codeStr;
  Code code = Code(codeStr);

  lodgingService->remove(userCode, code);
}

void LodgingView::read()
{
  cout << "=======================" << endl;
  cout << "    Listar hospedagens" << endl;
  cout << "=======================" << endl;

  vector<Lodging> lodgings = lodgingService->read(userCode);

  if (lodgings.size() == 0)
    cout << "Você não possui nenhuma hospedagem atrelada a esta conta" << endl;

  for (const auto &lodging : lodgings)
  {
    cout << "Código: " << lodging.get("code").getValue() << endl;
    cout << "Nome: " << lodging.get("name").getValue() << endl;
    cout << "Diária: " << lodging.get("dailyRate").getValue() << endl;
    cout << "Avaliação: " << lodging.get("rating").getValue() << endl;
    cout << "=======================" << endl;
  }
}