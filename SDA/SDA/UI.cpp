#include "UI.h"

UI::UI()
{
	mm = MultiMap{ 15 };
}

void UI::printMenu()
{
	std::cout << "\n\t\t  ~MENU~ \n" << std::endl;
	std::cout << "\t 1. Add a guest to a table." << std::endl;
	std::cout << "\t 2. Remove a guest from a table." << std::endl;
	std::cout << "\t 3. Display the guests from a given table." << std::endl;
	std::cout << "\t 4. Search for a guest." << std::endl;
	std::cout << "\t 5. Show all tables." << std::endl;
	std::cout << "\t 0. Exit.\n" << std::endl;
}

void UI::init()
{
	mm.add(4, "Andreas Dragutin");
	mm.add(1, "Gleb Valerian");
	mm.add(2, "Jonatas Yesha'yahu");
	mm.add(4, "Eudocia Cassia");
	mm.add(8, "Freida Yakup");
	mm.add(3, "Laura Ina");
	mm.add(1, "Victoria Inna");
	mm.add(1, "Detlef Britt");
	mm.add(4, "Patrizio Wigheard");
	mm.add(9, "Fabiana Eva");
}

void UI::run()
{
	init();

	int command = -1;

	while (command != 0)
	{
		std::cout << std::endl;
		printMenu();
		std::cout << "\n\tYour commnad: ";
		std::cin >> command;

		if (command == 0) return;

		if (command == 1)
		{
			int table;
			std::cout << "\n\tTable ID: ";
			std::cin.ignore();
			std::cin >> table;

			std::cout << "\tGuest name: ";
			std::string name;
			getchar();
			getline(std::cin, name);

			if (mm.add(table, name) == 0)
				std::cout << "\n\t\t Guest has been added !" << std::endl;
			else std::cout << "\n\t\t Guest couldn't be added !" << std::endl;
		}

		else if (command == 2)
		{
			int table;
			std::cout << "\n\tTable ID: ";
			std::cin.ignore();
			std::cin >> table;

			std::string name;
			std::cout << "\tGuest name: ";
			getchar();
			getline(std::cin, name);

			if (mm.remove(table, name) == 0)
				std::cout << "\n\t\t Guest has been deleted !" << std::endl;
			else std::cout << "\n\t\t Guest was not found for deleting !" << std::endl;
		}

		else if (command == 3)
		{
			int table;
			std::cout << "\n \tTable ID: ";
			std::cin.ignore();
			std::cin >> table;

			int k = 0;

			MultiMap::Iterator aux{ mm };
			std::cout << std::endl;
			while (aux.valid())
			{
				if (aux.getCurrent().getKey() == table)
				{
					std::cout << "\tName: " << aux.getCurrent().getName() << "." << std::endl;
					k++;
				}
				aux.next();
			}
			if (k == 0) std::cout << "\tThe coresponding table does not exist !" << std::endl;
		}
		else if (command == 4)
		{
			bool sem = false;
			std::cout << "\n \tGuest name: ";
			std::string name;
			getchar();
			getline(std::cin, name);

			MultiMap::Iterator aux{ mm };
			std::cout << std::endl;
			while (aux.valid())
			{
				if (aux.getCurrent().getName() == name)
				{
					std::cout << "\t\tThe guest is at table " << aux.getCurrent().getKey() << "." << std::endl;
					sem = true;
				}
				aux.next();
			}
			if (sem == false)
				std::cout << "\t\tThe guest couldn't been found !" << std::endl;
		}
		else if (command == 5)
		{
			std::cout << std::endl;
			MultiMap::Iterator aux{ mm };
			std::cout << std::endl;
			while (aux.valid())
			{
				std::cout << "\tTable: " << aux.getCurrent().getKey() << "           Name: " << aux.getCurrent().getName() << std::endl;
				aux.next();
			}
		}
		else std::cout << "\n\tInvalid command !" << std::endl;
	}
}