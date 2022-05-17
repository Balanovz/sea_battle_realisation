#include "sea_battle.h"

sea_battle::sea_battle()
{
	std::vector<std::string> temp(10, "0");
	for (int i = 0; i < 10; ++i) {
		field.push_back(temp);
		enemy_field.push_back(temp);
	}
}


void sea_battle::print_field() const
{
	std::cout << "Your field:\n";
	for (auto i : field) {
		for (auto j : i)
			std::cout << j << " ";
		std::cout << std::endl;
	}

	std::cout << "\n\n";

	std::cout << "Enemy field:\n";
	for (auto i : enemy_field) {
		for (auto j : i)
			std::cout << j << " ";
		std::cout << std::endl;
	}

}

void sea_battle::menu_set()
{
	//пока не закончатся все корабли будет заполнение
	while (single + two + three + four) {
		system("cls");
		std::cout << "Select number how many deck ship to set:\n"
			<< "1. single deck (" << single << ")\n"
			<< "2. two deck (" << two << ")\n"
			<< "3. three deck (" << three << ")\n"
			<< "4. four deck (" << four << ")\n"
			<< "5. remove ship\n";
			

		int choose; std::cin >> choose;
		int begin1, begin2, end1, end2;

		std::cout << "\n\n";
		print_field();
		std::cout << "\n\n";

		switch (choose) {
		case 1:
			if (single) {
				std::cout << "Enter coordinate for single-deck ship:\n"
					<< "x = "; std::cin >> begin1;
				std::cout << "y = "; std::cin >> begin2;


				if (check(begin1, begin2, begin1, begin2) && (deck(begin1, begin2, begin1, begin2) == 0)) {
					set_ship(begin1, begin2, begin1, begin2);
					--single;
				}

				else { 
					std::cout << "invalid coordinates";
					std::cin.get(); std::cin.get();
				}

			}
			else {
				std::cout << "You haven't single-deck ship";
				std::cin.get(); std::cin.get();
			}
			break;
		case 2:
			if (two) {
				std::cout << "Enter the begin and end coordinates for the two-deck ship:\n"
					<< "x(begin) = "; std::cin >> begin1;
				std::cout << "y(begin) = "; std::cin >> begin2;
				std::cout << "x(end) = "; std::cin >> end1;
				std::cout << "y(end) = "; std::cin >> end2;
				
				if (check(begin1, begin2, end1, end2) && (deck(begin1, begin2, end1, end2) == 1)) {
					set_ship(begin1, begin2, end1, end2);
					--two;
				}

				else {
					std::cout << "invalid coordinates";
					std::cin.get(); std::cin.get();
				}
			}
			else {
				std::cout << "You haven't two-deck ship\n";
				std::cin.get(); std::cin.get();
			}
			break;
		case 3:
			if (three) {
				std::cout << "Enter the begin and end coordinates for the three-deck ship:\n"
					<< "x(begin) = "; std::cin >> begin1;
				std::cout << "y(begin) = "; std::cin >> begin2;
				std::cout << "x(end) = "; std::cin >> end1;
				std::cout << "y(end) = "; std::cin >> end2;

				if (check(begin1, begin2, end1, end2) && (deck(begin1, begin2, end1, end2) == 2)) {
					set_ship(begin1, begin2, end1, end2);
					--three;
				}

				else {
					std::cout << "invalid coordinates";
					std::cin.get(); std::cin.get();
				}

			}
			else {
				std::cout << "You haven't three-deck ship\n";
				std::cin.get(); std::cin.get();
			}
			break;
		case 4:
			if (four) {
				std::cout << "Enter the begin and end coordinates for the four-deck ship:\n"
					<< "x(begin) = "; std::cin >> begin1;
				std::cout << "y(begin) = "; std::cin >> begin2;
				std::cout << "x(end) = "; std::cin >> end1;
				std::cout << "y(end) = "; std::cin >> end2;

				if (check(begin1, begin2, end1, end2) && (deck(begin1, begin2, end1, end2) == 3)) {
					set_ship(begin1, begin2, end1, end2);
					--four;
				}

				else {
					std::cout << "invalid coordinates";
					std::cin.get(); std::cin.get();
				}

			}
			else {
				std::cout << "You haven't four-deck ship\n";
				std::cin.get(); std::cin.get();
			}
			break;
		case 5:
			int numb;
			std::cout << "how many deck ship to remove (1, 2, 3, 4)?\n";
			std::cin >> numb;
			if (numb != 1 && numb != 2 && numb != 3 && numb != 4) {
				std::cout << "invalid count of deck";
				std::cin.get(); std::cin.get();
				break;
			}

			std::cout << "if you are going to remove a single-deck ship, enter it's coordinates twice.\n";
			std::cout << "Enter the begin and end coordinates for the ship to be removed:\n"
				<< "x(begin) = "; std::cin >> begin1;
			std::cout << "y(begin) = "; std::cin >> begin2;
			std::cout << "x(end) = "; std::cin >> end1;
			std::cout << "y(end) = "; std::cin >> end2;

			if (remove_ship(begin1, begin2, end1, end2)) 
				switch (numb) {
				case 1:
					++single;
					break;
				case 2:
					++two;
					break;
				case 3:
					++three;
					break;
				case 4:
					++four;
					break;
				}

			break;
		default:
			std::cout << "invalid command";
			std::cin.get(); std::cin.get();
		}
	}
}

void sea_battle::auto_set()
{
	srand(time(nullptr));
	int rand_begin1, rand_begin2,
		rand_end1, rand_end2;

	while (single) {
		rand_begin1 = rand() % 10;
		rand_begin2 = rand() % 10;

		if (check(rand_begin1, rand_begin2, rand_begin1, rand_begin2)) {
			set_ship(rand_begin1, rand_begin2, rand_begin1, rand_begin2);
			--single;
		}
	}

	while (two) {
		rand_begin1 = rand() % 10;
		rand_begin2 = rand() % 10;
		rand_end1 = rand_begin1 + (-1 + rand() % 3);
		rand_end2 = rand_begin2 + (-1 + rand() % 3);

		if ((deck(rand_begin1, rand_begin2, rand_end1, rand_end2) == 1) && check(rand_begin1, rand_begin2, rand_end1, rand_end2)) {
			set_ship(rand_begin1, rand_begin2, rand_end1, rand_end2);
			--two;
		}
	}

	while (three) {
		rand_begin1 = rand() % 10;
		rand_begin2 = rand() % 10;
		rand_end1 = rand_begin1 + (-2 + rand() % 5);
		rand_end2 = rand_begin2 + (-2 + rand() % 5);

		if ((deck(rand_begin1, rand_begin2, rand_end1, rand_end2) == 2) && check(rand_begin1, rand_begin2, rand_end1, rand_end2)) {
			set_ship(rand_begin1, rand_begin2, rand_end1, rand_end2);
			--three;
		}
	}

	while (four) {
		rand_begin1 = rand() % 10;
		rand_begin2 = rand() % 10;
		rand_end1 = rand_begin1 + (-3 + rand() % 7);
		rand_end2 = rand_begin2 + (-3 + rand() % 7);

		if ((deck(rand_begin1, rand_begin2, rand_end1, rand_end2) == 3) && check(rand_begin1, rand_begin2, rand_end1, rand_end2)) {
			set_ship(rand_begin1, rand_begin2, rand_end1, rand_end2);
			--four;
		}
	}

	/*
	нерабочая альтернатива решения, но я думаю, что при объединении всех четырех 
	условий вероятность прокрутки нужного корабля немного повысится, поэтому нужно
	переписать с соблюдением всех условий соблюденных выше (хотя алгоритм выше мне нравится
	больше, он более структурированный)
	*/

	/*while (single + two + three + four) {
		int rand_begin1 = rand() % 10,
			rand_begin2 = rand() % 10,
			rand_end1, rand_end2;

		if (single && check(rand_begin1, rand_begin2, rand_begin1, rand_begin2)) {
			set_ship(rand_begin1, rand_begin2, rand_begin1, rand_begin2);
			--single;
		}
		if (two) {
			rand_end1 = (rand_begin1 - 1) + rand() % (rand_begin1 + 1);
			rand_end2 = (rand_begin2 - 1) + rand() % (rand_begin2 + 1);

			if (check(rand_begin1, rand_begin2, rand_end1, rand_end2) && (deck(rand_begin1, rand_begin2, rand_end1, rand_end2) == 2)) {
				set_ship(rand_begin1, rand_begin2, rand_end1, rand_end2);
				--two;
			}
		}
		if (three) {
			rand_end1 = (rand_begin1 - 2) + rand() % (rand_begin1 + 2);
			rand_end2 = (rand_begin2 - 2) + rand() % (rand_begin2 + 2);

			if (check(rand_begin1, rand_begin2, rand_end1, rand_end2) && (deck(rand_begin1, rand_begin2, rand_end1, rand_end2) == 3)) {
				set_ship(rand_begin1, rand_begin2, rand_end1, rand_end2);
				--three;
			}
		}
		if (four) {
			rand_end1 = (rand_begin1 - 3) + rand() % (rand_begin1 + 3);
			rand_end2 = (rand_begin2 - 3) + rand() % (rand_begin2 + 3);

			if (check(rand_begin1, rand_begin2, rand_end1, rand_end2) && (deck(rand_begin1, rand_begin2, rand_end1, rand_end2) == 4)) {
				set_ship(rand_begin1, rand_begin2, rand_end1, rand_end2);
				--four;
			}
		}

		std::cout << "\n\n";
		print_field();
	}*/
}


bool sea_battle::check(int begin1, int begin2, int end1, int end2) const {
	int size = field.size() - 1;

	if (begin1 < 0 || begin1 > size || begin2 < 0 || begin2 > size || end1 < 0 || end1 > size || end2 < 0 || end2 > size)
		return false;

	if (begin1 > end1) std::swap(begin1, end1);
	if (begin2 > end2) std::swap(begin2, end2);

	for (int i = begin1 - 1; i <= end1 + 1; ++i)
		for (int j = begin2 - 1; j <= end2 + 1; ++j)
			if (i >= 0 && j >= 0 && i <= size && j <= size)
				if (field[i][j] == "1")
					return false;

	return true;
}

const int sea_battle::deck(int begin1, int begin2, int end1, int end2) {
	if (begin1 > end1) std::swap(begin1, end1);
	if (begin2 > end2) std::swap(begin2, end2);

	if(begin1 == end1 || begin2 == end2)
	return (end1 - begin1 + end2 - begin2);

	return -1;
}

void sea_battle::set_ship(int begin1, int begin2, int end1, int end2) {
	if (begin1 > end1) std::swap(begin1, end1);
	if (begin2 > end2) std::swap(begin2, end2);

	for (int i = begin1; i <= end1; ++i)
		for (int j = begin2; j <= end2; ++j)
			field[i][j] = "1";
}

bool sea_battle::remove_ship(int begin1, int begin2, int end1, int end2) {
	int size = field.size() - 1;
	if (begin1 < 0 || begin1 > size || begin2 < 0 || begin2 > size || end1 < 0 || end1 > size || end2 < 0 || end2 > size) {
		std::cout << "invalid coordinate";
		std::cin.get(); std::cin.get();
		return false;
	}

	if (begin1 > end1) std::swap(begin1, end1);
	if (begin2 > end2) std::swap(begin2, end2);

	for (int i = begin1; i <= end1; ++i)
		for (int j = begin2; j <= end2; ++j)
			if (field[i][j] == "0") {
				std::cout << "invalid coordinate";
				std::cin.get(); std::cin.get();
				return false;
			}

	for (int i = begin1; i <= end1; ++i)
		for (int j = begin2; j <= end2; ++j)
			field[i][j] = "0";
	return true;

}

bool sea_battle::shoot(sea_battle& player) {
	int x, y;
	std::cout << "Enter attack coordinates\n";
	std::cout << "x = "; std::cin >> x;
	std::cout << "y = "; std::cin >> y;
	if (x >= 0 && x < field.size() && y >= 0 && y < field.size()) {
		if (player.field[x][y] == "1") {
			player.field[x][y] = "x";
			enemy_field[x][y] = "x";
			std::cout << "you hit the ship";
			std::cin.get(); std::cin.get();
			return true;
		}
		else if (player.field[x][y] == "0") {
			player.field[x][y] = ".";
			enemy_field[x][y] = ".";
			std::cout << "you missed";
			std::cin.get(); std::cin.get();
			return false;

		}
		else if (player.field[x][y] == "x" || player.field[x][y] == ".") {
			std::cout << "you already shot here try again";
			std::cin.get(); std::cin.get();
		}
			
	}
	else {
		std::cout << "Coordinates entered incorrectly, please try again";
		std::cin.get(); std::cin.get();
	}

}

bool sea_battle::auto_shoot(sea_battle& player) {
	srand(time(nullptr));
	int x = rand() % 10;
	int y = rand() % 10;

	if (player.field[x][y] == "1") {
		player.field[x][y] = "x";
		enemy_field[x][y] = "x";
		return true;
	}
	else if (player.field[x][y] == "0") {
		player.field[x][y] = ".";
		enemy_field[x][y] = ".";
		return false;
	}

}

void sea_battle::fight_system(sea_battle& bot) {
	while (ships && bot.ships) {
		system("cls");
		print_field();
		while(shoot(bot)){
			system("cls");
			print_field();

			--bot.ships;
		}

		while(bot.auto_shoot(*this)){
			--ships;
		}

	}
	if (ships > bot.ships) {
		std::cout << "You won!";
		std::cin.get(); std::cin.get();
	}
	else {
		std::cout << "Game over.";
		std::cin.get(); std::cin.get();
	}
}