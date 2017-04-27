#include "UI.h"
#include<string>
#include "Tutorial.h"

using namespace std;


void UI::printMenu()
{
	cout << endl;
	cout << "1 - Administrator Mode" << endl;
	cout << "2 - User Mode" << endl;
	cout << "0 - Exit." << endl;
}

void UI::printRepositoryMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Add tutorial." << endl;
	cout << "\t 2 - Display all." << endl;
	cout << "\t 3 - Remove turorial." << endl;
	cout << "\t 4 - Update tutorial." << endl;
	cout << "\t 0 - Back." << endl;
}

void UI::addTutorialToRepo()
{
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	cout << "Enter the presenter: ";
	std::string presenter;
	getline(cin, presenter);
	int minutes = 0, seconds = 0;
	cout << "Enter the duration: " << endl;
	cout << "\tMinutes: ";
	cin >> minutes;
	cin.ignore();
	cout << "\tSeconds: ";
	cin >> seconds;
	cin.ignore();
	cout << "Enter number of likes: " << endl;
	int noLikes = 0;
	cin >> noLikes;
	cin.ignore();
	cout << "Youtube link: ";
	std::string link;
	getline(cin, link);
	
	Tutorial tut = Tutorial{ title, presenter, Duration{minutes, seconds}, noLikes, link };

	DynamicVector v = this->ctrl.getRepo().getTutorials();
	Tutorial* t = v.getAllElems();
	int k = 0;
	//for (int i = 0; i < v.getSize(); i++)
	//{
	//	Tutorial tu = Tutorial{ t[i].getTitle(), t[i].getPresenter(), t[i].getDuration(), t[i].getLikes(), t[i].getLink() };
	//	if (tu == tut) {
	//		cout << "nu poti introduce acelasi tutorial de 2 ori";
	//		break;
	//	}
	//}
		this->ctrl.addTutorialAdmin(title, presenter, minutes, seconds, noLikes, link);
	
}

void UI::displayAllTutorialsRepo()
{
	DynamicVector v = this->ctrl.getRepo().getTutorials();
	Tutorial* t = v.getAllElems();
	if (t == NULL)
		return;
	if (v.getSize() == 0)
	{
		cout << "There are no songs in the repository." << endl;
		return;
	}

	for (int i = 0; i < v.getSize(); i++)
	{
		Tutorial tu = t[i];
		cout<<tu.toString();
	}
}

void UI::removeTutorialFromRepo()
{
	cout << "Enter the id: ";
	double id;
	cin >> id;
	cin.ignore();
	ctrl.removeTutorialAdmin(id);
}

void UI::updateTutorialFromRepo()
{
	cout << "Enter the id of the country to be modified ";
	double id;
	cin >> id;
	cin.ignore();
	cout << "Enter the title ";
	std::string title;
	getline(cin, title);
	cout << "Enter a new presenter: ";
	std::string presenter;
	getline(cin, presenter);
	int minutes = 0, seconds = 0;
	cout << "Enter a duration: " << endl;
	cout << "\tMinutes: ";
	cin >> minutes;
	cin.ignore();
	cout << "\tSeconds: ";
	cin >> seconds;
	cin.ignore();
	cout << "Enter a new number of likes: " << endl;
	int noLikes = 0;
	cin >> noLikes;
	cin.ignore();
	cout << "Youtube link: ";
	std::string link;
	getline(cin, link);

	ctrl.updateTutorialAdmin(id, title, presenter, minutes, seconds, noLikes, link);
}

void UI::run()
{
	while (true)
	{
		UI::printMenu();
		int command{ 0 };
		cout << "Input the command: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;

		// repository management
		if (command == 1)
		{
			while (true)
			{
				UI::printRepositoryMenu();
				int commandRepo{ 0 };
				cout << "Input the command: ";
				cin >> commandRepo;
				cin.ignore();
				if (commandRepo == 0)
					break;
				switch (commandRepo)
				{
				case 1:
					this->addTutorialToRepo();
					break;
				case 2:
					this->displayAllTutorialsRepo();
					break;
				case 3:
					this->removeTutorialFromRepo();
					break;
				case 4:
					this->updateTutorialFromRepo();
					break;
				}
			}
		}
	}
}