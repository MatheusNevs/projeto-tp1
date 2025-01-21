#include "../../include/views/activity.hpp"

void ActivityView::execute(Code &userCode)
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
      cout << "  Sistema de Atividades" << endl;
      cout << "=======================" << endl;
      cout << "1. Criar atividade" << endl;
      cout << "2. Listar atividades" << endl;
      cout << "3. Atualizar atividade" << endl;
      cout << "4. Deletar atividade" << endl;
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

void ActivityView::create()
{
  Code code = Code();
  Rating rating = Rating("0");
  string name, date, time, duration, price, activityDestinationCode;

  cout << "=======================" << endl;
  cout << "    Criar atividade" << endl;
  cout << "=======================" << endl;
  cout << "1. Digite o nome da atividade: ";
  cin >> name;
  Name nameDomain = Name(name);

  cout << "2. Digite a data da atividade (DD-MM-AA): ";
  cin >> date;
  Date dateDomain = Date(date);

  cout << "3. Digite o horário da atividade (HH:MM): ";
  cin >> time;
  Time timeDomain = Time(time);

  cout << "4. Digite a duração da atividade (HH:MM): ";
  cin >> duration;
  Duration durationDomain = Duration(duration);

  cout << "5. Digite o preço da atividade: ";
  cin >> price;
  Money priceDomain = Money(price);

  cout << "6. Digite o código do destino atrelado: ";
  cin >> activityDestinationCode;
  Code activityDestinationCodeDomain = Code(activityDestinationCode);

  Activity activity = Activity(code, nameDomain, dateDomain, timeDomain, durationDomain, priceDomain, rating);
  activityService->create(userCode, activityDestinationCodeDomain, activity);
}

void ActivityView::update()
{
  string codeStr, name, date, time, duration, price, rating;
  cout << "=======================" << endl;
  cout << "    Atualizar atividade" << endl;
  cout << "=======================" << endl;
  cout << "1. Digite o código da atividade a ser atualizada: ";
  cin >> codeStr;
  Code codeDomain = Code(codeStr);

  cout << "2. Digite o novo nome da atividade: ";
  cin >> name;
  Name nameDomain = Name(name);

  cout << "3. Digite a nova data da atividade (DD-MM-AA): ";
  cin >> date;
  Date dateDomain = Date(date);

  cout << "4. Digite o novo horário da atividade (HH:MM): ";
  cin >> time;
  Time timeDomain = Time(time);

  cout << "5. Digite a nova duração da atividade (HH:MM): ";
  cin >> duration;
  Duration durationDomain = Duration(duration);

  cout << "6. Digite o novo preço da atividade: ";
  cin >> price;
  Money priceDomain = Money(price);

  cout << "7. Digite a nova avaliação da atividade: ";
  cin >> rating;
  Rating ratingDomain = Rating(rating);

  Activity activity = Activity(codeDomain, nameDomain, dateDomain, timeDomain, durationDomain, priceDomain, ratingDomain);
  activityService->update(userCode, codeDomain, activity);
}

void ActivityView::remove()
{
  string codeStr;

  cout << "=======================" << endl;
  cout << "    Deletar atividade" << endl;
  cout << "=======================" << endl;
  cout << "1. Digite o código da atividade: ";
  cin >> codeStr;
  Code code = Code(codeStr);

  activityService->remove(userCode, code);
}

void ActivityView::read()
{
  cout << "=======================" << endl;
  cout << "    Listar atividades" << endl;
  cout << "=======================" << endl;

  vector<Activity> activities = activityService->read(userCode);

  if (activities.size() == 0)
    cout << "Você não possui nenhuma atividade atrelada a esta conta" << endl;

  for (const auto &activity : activities)
  {
    cout << "Código: " << activity.get("code").getValue() << endl;
    cout << "Nome: " << activity.get("name").getValue() << endl;
    cout << "Data: " << activity.get("date").getValue() << endl;
    cout << "Horário: " << activity.get("time").getValue() << endl;
    cout << "Duração: " << activity.get("duration").getValue() << endl;
    cout << "Preço: " << activity.get("price").getValue() << endl;
    cout << "Avaliação: " << activity.get("rating").getValue() << endl;
    cout << "=======================" << endl;
  }
}