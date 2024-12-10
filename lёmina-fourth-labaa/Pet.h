#include <string>
#include <iostream>
#include <vector>
#include <fstream>

#pragma once
class Pet
{
private:
	std::string owner, nickname;
	std::vector<std::string> vaccinations;
	unsigned int birth, last_prixod;
	bool sex;
public:
	//обязательные
	Pet() {};
	Pet(std::ifstream &file);
	~Pet() {};

	//геттеры
	std::string get_owner() { return owner; };
	std::string get_nickname() { return nickname; };
	unsigned int get_birth() { return birth; };
	unsigned int get_prixod() { return last_prixod; };
	std::vector<std::string> get_vaccinations() { return vaccinations; };
	bool get_sex() { return sex; };

	//вспомогательные
	int age() { return (2024 - birth); }
	void add_vac(std::string new_vac);
	void fill_from_keyboard();
	void print(std::ostream & stream);
	bool check_vac(std::string vac);
	int compare(const Pet& other);
	
};