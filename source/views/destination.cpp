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
      cout << "2. Listar destinos" << endl;
      cout << "3. Atualizar destino" << endl;
      cout << "4. Deletar destino" << endl;
      cout << "5. Retornar" << endl;
      cout << "Escolha uma opção: ";
      string option;
      cin >> option;

      cout << "\033[2J\033[1;1H";

      if (option == "1")
      {
        create();
      }
      else if (option == "2")
      {
        read();
      }
      else if (option == "3")
      {
        update();
      }
      else if (option == "4")
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
  string name, arrival, departure, travelCode;

  cout << "=======================" << endl;
  cout << "    Criar destino" << endl;
  cout << "=======================" << endl;
  cout << "1. Digite o nome do destino: ";
  cin >> name;
  Name nameDomain = Name(name);

  cout << "2. Digite a data de início (DD-MM-AA): ";
  cin >> arrival;
  Date arrivalDomain = Date(arrival);

  cout << "3. Digite a data de fim (DD-MM-AA): ";
  cin >> departure;
  Date departureDomain = Date(departure);

  cout << "4. Digite o código da viagem a ser atrelada: ";
  cin >> travelCode;
  Code travelCodeDomain = Code(travelCode);

  Destination destination = Destination(code, nameDomain, arrivalDomain, departureDomain, rating);
  destinationService->create(userCode, travelCodeDomain, destination);
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
    cout << "Data de início: " << destination.get("arrival").getValue() << endl;
    cout << "Data de fim: " << destination.get("departure").getValue() << endl;
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
  Code codeDomain = Code(codeStr);

  string name, arrival, departure, rating;
  cout << "2. Digite o novo nome do destino: ";
  cin >> name;
  Name nameDomain = Name(name);

  cout << "3. Digite a nova data de início (DD-MM-AA): ";
  cin >> arrival;
  Date arrivalDomain = Date(arrival);

  cout << "4. Digite a nova data de fim (DD-MM-AA): ";
  cin >> departure;
  Date departureDomain = Date(departure);

  cout << "5. Digite a nova avaliação do destino: ";
  cin >> rating;
  Rating ratingDomain = Rating(rating);

  Destination destination = Destination(codeDomain, nameDomain, arrivalDomain, departureDomain, ratingDomain);
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
