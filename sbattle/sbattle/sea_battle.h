#pragma once
#include <vector>
#include <iostream>


class sea_battle
{
	std::vector<std::vector<std::string>> field;		//поле игрока
	std::vector<std::vector<std::string>> enemy_field;	//поле попаданий и промахов

	//количество однопалбных, двухпалубных, трехпалубных и четырехпалубных кораблей
	int single = 4, two = 3, three = 2, four = 1;
	int ships = single + two + three + four;	//общее количество кораблей

	bool check(int, int, int, int) const;		//проверка на свободное пространство для корабля
	const int deck(int, int, int, int);			//проверка на палубность корабля
	void set_ship(int, int, int, int);			//установка корабля на поле (на вход получает две координаты начала и две конечные)
	bool remove_ship(int, int, int, int);		//убрать корабль (на вход получает две координаты начала и две конечные)
	bool shoot(sea_battle& player);				//постановка выстрела и отметка на поле попадания или промаха
	bool auto_shoot(sea_battle& player);		//автоматический метод для бота без интерфейса
 
public:
	sea_battle();								//создает два пустых поля (игрока и поле выстрелов по противнику) заполненное нулями
	void print_field() const;					//вывод поля игрока и поля выстрелов по врагу
	void fight_system(sea_battle& player);		//алгоритм выполнения попаданий, переход осуществляется после промаха
	void menu_set();							//меню для самостоятельного проставления кораблей
	void auto_set();							//автоматическое расстановка кораблей (рандомная)




};

