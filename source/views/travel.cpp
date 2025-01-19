#include "../../include/views/travel.hpp"

void TravelView::execute(Code &userCode)
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
      cout << "  Sistema de Viagens" << endl;
      cout << "=======================" << endl;
      cout << "1. Criar viagem" << endl;
      cout << "2. Atualizar viagem" << endl;
      cout << "3. Deletar viagem" << endl;
      cout << "4. Listar viagens" << endl;
      cout << "5. Consultar viagem" << endl;
      cout << "6. Retornar" << endl;
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
        update();
      }
      else if (option == 3)
      {
        remove();
      }
      else if (option == 4)
      {
        listAll();
      }
      else if (option == 5)
      {
        consultTravel();
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

void TravelView::create()
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
}

void TravelView::update()
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
}

void TravelView::remove()
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
}

void TravelView::listAll()
{
  cout << "=======================" << endl;
  cout << "    Listar viagens" << endl;
  cout << "=======================" << endl;

  vector<Travel> travels = travelService->readAll(userCode);

  if (travels.size() == 0)
    cout << "Você não possui nenhuma viagem atrelada a esta conta" << endl;

  for (const auto &travel : travels)
  {
    cout << "Código: " << travel.get("code").getValue() << endl;
    cout << "Nome: " << travel.get("name").getValue() << endl;
    cout << "Avaliação: " << travel.get("rating").getValue() << endl;
    cout << "=======================" << endl;
  }
}

void TravelView::consultCost(Code travelCode)
{
  cout << "=======================" << endl;
  cout << "Consultar custo da viagem" << endl;
  cout << "=======================" << endl;
  cout << "Custo da viagem: " << travelService->consultCost(userCode, travelCode) << endl;
  cout << "=======================" << endl;
}

void TravelView::listDestinations(Code travelCode)
{
  cout << "=======================" << endl;
  cout << "   Listar destinos" << endl;
  cout << "=======================" << endl;

  vector<Destination> destinations = travelService->listDestinations(userCode, travelCode);

  if (destinations.size() == 0)
    cout << "Você não possui nenhum destino atrelado a esta viagem" << endl;

  for (int i = 0; i < destinations.size(); i++)
  {
    cout << "Código: " << destinations[i].get("code").getValue() << endl;
    cout << "Nome: " << destinations[i].get("name").getValue() << endl;
    cout << "Data de Início: " << destinations[i].get("startDate").getValue() << endl;
    cout << "Data de Fim: " << destinations[i].get("endDate").getValue() << endl;
    cout << "Avaliação: " << destinations[i].get("rating").getValue() << endl;
    cout << "=======================" << endl;
  }
}

void TravelView::listActivities(Code destinationCode)
{
  cout << "=======================" << endl;
  cout << "   Listar atividades" << endl;
  cout << "=======================" << endl;

  vector<Activity> activities = travelService->listActivities(userCode, destinationCode);

  if (activities.size() == 0)
    cout << "Você não possui nenhuma atividade atrelada a este destino" << endl;

  for (int i = 0; i < activities.size(); i++)
  {
    cout << "Código: " << activities[i].get("codigo").getValue() << endl;
    cout << "Nome: " << activities[i].get("name").getValue() << endl;
    cout << "Data: " << activities[i].get("date").getValue() << endl;
    cout << "Horário: " << activities[i].get("time").getValue() << endl;
    cout << "Duração: " << activities[i].get("duration").getValue() << endl;
    cout << "Preço: " << activities[i].get("price").getValue() << endl;
    cout << "Avaliação: " << activities[i].get("rating").getValue() << endl;
  }
}

void TravelView::listLodgings(Code destinationCode)
{
  cout << "=======================" << endl;
  cout << "   Listar destinos" << endl;
  cout << "=======================" << endl;

  vector<Lodging> lodgings = travelService->listLodgings(userCode, destinationCode);

  if (lodgings.size() == 0)
    cout << "Você não possui nenhuma hospedagem atrelada a este destino" << endl;

  for (int i = 0; i < lodgings.size(); i++)
  {
    cout << "Código: " << lodgings[i].get("codigo").getValue() << endl;
    cout << "Nome: " << lodgings[i].get("name").getValue() << endl;
    cout << "Diário: " << lodgings[i].get("dailyRate").getValue() << endl;
    cout << "Avaliação: " << lodgings[i].get("rating").getValue() << endl;
  }
}

void TravelView::consultDestination()
{
  string destinationCode;
  Code destinationCodeDomain;
  while (true)
  {
    try
    {
      cout << "\033[2J\033[1;1H";

      cout << "=======================" << endl;
      cout << "   Consultar destino" << endl;
      cout << "=======================" << endl;

      cout << "Digite o código do destino: ";
      if (destinationCode == "")
      {
        cin >> destinationCode;
        destinationCodeDomain.setValue(destinationCode);
      }
      else
        cout << destinationCode << endl;
      cout << "=======================" << endl;
      cout << "1. Listar hospedagens" << endl;
      cout << "2. Listar atividades" << endl;
      cout << "3. Retornar" << endl;

      int option;
      cin >> option;

      cout << "\033[2J\033[1;1H";

      if (option == 1)
      {
        listLodgings(destinationCodeDomain);
      }
      else if (option == 2)
      {
        listActivities(destinationCodeDomain);
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

void TravelView::consultTravel()
{
  Code travelCodeDomain;
  string travelCode = "";
  while (true)
  {
    try
    {
      cout << "\033[2J\033[1;1H";
      cout << "=======================" << endl;
      cout << "   Consultar viagem" << endl;
      cout << "=======================" << endl;
      cout << "Digite o código da viagem: ";
      if (travelCode == "")
      {
        cin >> travelCode;
        travelCodeDomain.setValue(travelCode);
      }
      else
        cout << travelCode << endl;
      cout << "=======================" << endl;
      cout << "1. Consultar custo da viagem" << endl;
      cout << "2. Listar destinos associados" << endl;
      cout << "3. Consultar destino" << endl;
      cout << "4. Retornar" << endl;

      int option;
      cin >> option;

      cout << "\033[2J\033[1;1H";

      if (option == 1)
      {
        consultCost(travelCodeDomain);
      }
      else if (option == 2)
      {
        listDestinations(travelCodeDomain);
      }
      else if (option == 3)
      {
        consultDestination();
      }
      else
      {
        break;
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
