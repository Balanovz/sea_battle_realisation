/*
Каждый игрок имеет поле 10*10 с расставленными кораблями
(стандартные правила Морского боя). 
Реализовать классы «ИгровоеПоле», «Игра». Имитировать игру двух игроков.
*/

//расстановку кораблей для бота, атака бота, система ходов бота и игрока


#include "sea_battle.h"

void main() {
	sea_battle player;
	sea_battle bot;
	bool status = true;
	int action;

	
	while (status) {
		system("cls");
		std::cout << "1. start the game";
		std::cout << "\n2. exit the game\n";
		std::cin >> action;

		switch (action) {
		case 1:
			system("cls");
			char numb;
			bot.auto_set();
			std::cout << "1. arrange the ships yourself\n";
			std::cout << "2. arrange ships automatically\n";
			std::cin >> numb;

			if (numb == '1') {
				player.menu_set();
				player.fight_system(bot);
			}
			else if (numb == '2') {
				player.auto_set();
				player.fight_system(bot);
			}
			break;
		case 2:
			std::cout << "\nGoodbye!\n";
			status = false;
			break;
		default:
			std::cout << "invalid command\npress enter to continue";
			std::cin.get();
			std::cin.get();
		}

	}

}