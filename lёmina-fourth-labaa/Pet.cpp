#include "Pet.h"


Pet::Pet(std::ifstream& file)
{
	std::string temp;
	getline(file, temp, ':'); file >> std::ws; getline(file, owner);
	getline(file, temp, ':'); file >> std::ws; getline(file, nickname);
	getline(file, temp, ':'); file >> last_prixod; file.ignore();

	getline(file, temp, ':'); getline(file, temp, '\n');
	if (temp != " ")
	{
		size_t start = 0;
		size_t end = temp.find(',');
		while (end != std::string::npos)
		{
			vaccinations.push_back(temp.substr(start, end - start));
			start = end+2;
			end = temp.find(',', start);
		}
		vaccinations.push_back(temp.substr(start));
	}

	unsigned int age;
	getline(file, temp, ':'); file >> age; file.ignore(); birth = 2024 - age;

	std::string sex_str;
	getline(file, temp, ':'); file >> std::ws; getline(file, sex_str); 
	sex = sex_str == "�������" ? 1 : 0;
	getline(file, temp);
}

void Pet::fill_from_keyboard()
{

	std::cout << "������� ��� ���������: ";
	std::cin >> owner;

	std::cout << "������� ������ �������: ";
	std::cin >> nickname;

	std::cout << "������� ��� ���������� ���������: ";
	std::cin >> last_prixod;

	std::cout << "������� �������� (��� ���������� ������� 0): ";
	std::cin.ignore();
	std::string input;
	while (input != "0")
	{
		std::getline(std::cin, input);
		if (input != "0")
			add_vac(input);
	}

	std::cout << "������� ���� ��������: ";
	std::cin >> birth;

	std::cout << "������� ���: ";
	std::string sex_str;
	std::cin >> sex_str;
	sex = sex_str == "�������" ? 1 : 0;
	std::cout << "========================================================\n";

}

void Pet::print(std::ostream& stream)
{
	stream << "������: " << owner << '\n';
	stream << "��� �������: " << nickname << '\n';
	stream << "��������� ���������: " << last_prixod << '\n';
	stream << "������ ��������: ";
	if (vaccinations.size() == 0)
		stream << "���� ��� ��������";
	else
		for (int i{ 0 }; i < vaccinations.size(); ++i)
		{
			stream << vaccinations[i];
			if (i != vaccinations.size() - 1)
				stream << ", ";
		}
	stream << '\n';
	stream << "������� �������: " << age() << '\n';
	stream << "���: ";

	if (sex)
		stream << "�������";
	else stream << "�������";
	stream << '\n';
	stream << "========================================================\n";

}

bool Pet::check_vac(std::string vac)
{
	bool flag = 0;
	for (int i = 0; i < vaccinations.size(); ++i)
	{
		if (vaccinations[i] == vac) flag = true;
		std::cout << vaccinations[i] << " " << vac << '\n';
	}
	return flag;
}

void Pet::add_vac(std::string new_vac)
{
	vaccinations.push_back(new_vac);
}

int Pet::compare(const Pet& other)
{
	int result = 0;
	if (owner > other.owner)
		result = 1;
	else if (owner < other.owner)
		result = -1;

	if (result == 0)
	{
		if (nickname > other.nickname)
			result = 1;
		else if (nickname < other.nickname)
			result = -1;
	}

	if (result == 0)
	{
		if (sex > other.sex)
			result = 1;
		else if (sex< other.sex)
			result = -1;

	}

	return result;
}
