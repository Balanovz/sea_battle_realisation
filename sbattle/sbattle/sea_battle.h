#pragma once
#include <vector>
#include <iostream>


class sea_battle
{
	std::vector<std::vector<std::string>> field;		//���� ������
	std::vector<std::vector<std::string>> enemy_field;	//���� ��������� � ��������

	//���������� �����������, ������������, ������������ � ��������������� ��������
	int single = 4, two = 3, three = 2, four = 1;
	int ships = single + two + three + four;	//����� ���������� ��������

	bool check(int, int, int, int) const;		//�������� �� ��������� ������������ ��� �������
	const int deck(int, int, int, int);			//�������� �� ���������� �������
	void set_ship(int, int, int, int);			//��������� ������� �� ���� (�� ���� �������� ��� ���������� ������ � ��� ��������)
	bool remove_ship(int, int, int, int);		//������ ������� (�� ���� �������� ��� ���������� ������ � ��� ��������)
	bool shoot(sea_battle& player);				//���������� �������� � ������� �� ���� ��������� ��� �������
	bool auto_shoot(sea_battle& player);		//�������������� ����� ��� ���� ��� ����������
 
public:
	sea_battle();								//������� ��� ������ ���� (������ � ���� ��������� �� ����������) ����������� ������
	void print_field() const;					//����� ���� ������ � ���� ��������� �� �����
	void fight_system(sea_battle& player);		//�������� ���������� ���������, ������� �������������� ����� �������
	void menu_set();							//���� ��� ���������������� ������������ ��������
	void auto_set();							//�������������� ����������� �������� (���������)




};

