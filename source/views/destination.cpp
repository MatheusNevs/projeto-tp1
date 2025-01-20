#include "../../include/views/destination.hpp"

void DestinationView::execute(Code &userCode)
{
  this->userCode = userCode;

  while (true)
  {
    try
    {
      cout << "\033[2J\033[1;1H";

      cout << "=======================" << endl;
      cout << "  Sistema de Destinos" << endl;
      cout << "=======================" << endl;
      cout << "1. Criar destino" << endl;
      cout << "2. Atualizar destino" << endl;
      cout << "3. Deletar destino" << endl;
      cout << "4. Listar destinos" << endl;
      cout << "5. Consultar destino" << endl;
      cout << "6. Retornar" << endl;
      cout << "Escolha uma opção: ";
      int option;
      cin >> option;

      cout << "\033[2J\033[1;1H";

      if (option == 1)
      {
        create();
      }
      else if (option == 2)
      {
        remove();
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

void DestinationView::create()
{
  Code code = Code();
  Rating rating = Rating("0");
  string name, startDate, endDate;

  cout << "=======================" << endl;
  cout << "    Criar destino" << endl;
  cout << "=======================" << endl;
  cout << "1. Digite o nome do destino: ";
  cin >> name;

  cout << "2. Digite a data de início (DD-MM-AA): ";
  cin >> startDate;

  cout << "1. Digite a data de fim: (DD-MM-AA)";
  cin >> endDate;

  Name nameDomain = Name(name);
  Date startDateDomain = Date(startDate);
  Date endDateDomain = Date(endDate);

  Destination destination = Destination(code, nameDomain, startDateDomain, endDateDomain, rating);
  destinationService->create(userCode, destination);
}

void DestinationView::read()
{
  cout << "=======================" << endl;
  cout << "    Listar destinos" << endl;
  cout << "=======================" << endl;

  vector<Destination> destinations = destinationService->read(userCode);

  if (destinations.size() == 0)
    cout << "Você não possui nenhum destino atrelado a esta conta" << endl;

  for (const auto &destination : destinations)
  {
    cout << "Código: " << destination.get("code").getValue() << endl;
    cout << "Nome: " << destination.get("name").getValue() << endl;
    cout << "Data de início: " << destination.get("startDate").getValue() << endl;
    cout << "Data de fim: " << destination.get("endDate").getValue() << endl;
    cout << "Avaliação: " << destination.get("rating").getValue() << endl;
    cout << "=======================" << endl;
  }
}

void DestinationView::update()
{
  string codeStr;
  cout << "=======================" << endl;
  cout << "    Atualizar destino" << endl;
  cout << "=======================" << endl;
  cout << "1. Digite o código do destino a ser atualizado: ";
  cin >> codeStr;

  string name, startDate, endDate, rating;
  cout << "2. Digite o novo nome do destino: ";
  cin >> name;

  cout << "3. Digite a nova data de início (DD-MM-AA): ";
  cin >> startDate;

  cout << "4. Digite a nova data de fim (DD-MM-AA): ";
  cin >> endDate;

  cout << "5. Digite a nova avaliação do destino: ";
  cin >> rating;

  Code codeDomain = Code(codeStr);

  Name nameDomain = Name(name);
  Date startDateDomain = Date(startDate);
  Date endDateDomain = Date(endDate);
  Rating ratingDomain = Rating(rating);

  Destination destination = Destination(codeDomain, nameDomain, startDateDomain, endDateDomain, ratingDomain);
  destinationService->update(userCode, codeDomain, destination);
}

void DestinationView::remove()
{
  string codeStr;

  cout << "=======================" << endl;
  cout << "    Deletar destino" << endl;
  cout << "=======================" << endl;
  cout << "1. Digite o código do destino: ";
  cin >> codeStr;
  Code code = Code(codeStr);

  destinationService->remove(userCode, code);
}
