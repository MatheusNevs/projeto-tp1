#include "../include/controller.hpp"

Controller::~Controller()
{
  delete authView;
  delete travelView;
}

void Controller::setAuthView(AuthView *&authView)
{
  this->authView = authView;
}

void Controller::setTravelView(TravelView *&travelView)
{
  this->travelView = travelView;
}

void Controller::setDestinationView(DestinationView *&destinationView)
{
  this->destinationView = destinationView;
}

void Controller::setLodgingView(LodgingView *&lodgingView)
{
  this->lodgingView = lodgingView;
}

// void Controller::setActivityView(ActivityView *&lodgingView)
// {
//   this->activityView = activityView;
// }

void Controller::execute()
{
  while (true)
  {
    try
    {
      cout << "\033[2J\033[1;1H";

      cout << "=======================" << endl;
      cout << "  Sistema Central" << endl;
      cout << "=======================" << endl;
      cout << "1. Sistema de Autenticação" << endl;

      if (this->userCode.getValue() != "000000")
      {
        cout << "2. Sistema de Viagens" << endl;
        cout << "3. Sistema de Destinos" << endl;
        cout << "4. Sistema de Hospedagens" << endl;
        cout << "5. Sistema de Atividades" << endl;
        cout << "6. Sair" << endl;
        cout << "Escolha uma opção: ";
        int option;
        cin >> option;

        cout << "\033[2J\033[1;1H";

        if (option == 1)
          this->authView->execute(this->userCode);
        else if (option == 2)
          this->travelView->execute(this->userCode);
        else if (option == 3)
          this->destinationView->execute(this->userCode);
        // else if (option == 4)
        //   this->lodgingView->execute(this->userCode);
        // else if (option == 5)
        //   this->activityView->execute(this->userCode);
        else
          break;
      }
      else
      {
        cout << "2. Sair" << endl;
        cout << "Escolha uma opção: ";
        int option;
        cin >> option;

        cout << "\033[2J\033[1;1H";

        if (option == 1)
          this->authView->execute(this->userCode);
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
