
#include <Windows.h>
#include "Container.h"
#include "FLIST.h"
#include "Pet.h"
#include <iostream>
const std::string privivki("anti-tyler anti-pudge anti-viper anti-hype anti-antimage anti-katya anti-danya anti-lopa");

void print_menu();

void main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);


    Container list;

    int choice{};
    
    do
    {
        print_menu();
        std::cin >> choice;

        switch (choice)
        {
        case 1: // Заполнить из файла
        {
            std::ifstream file("test.txt");
            list.read_from_file(file);
            file.close();
            break;
        }

        case 2: // Печать списка
        {

            list.print();
            break;
        }

        case 3: // Добавить в начало
        {
            Pet* tmp = new Pet();
            tmp->fill_from_keyboard();
            list.add_to_head(tmp);
            break;
        }

        case 4: // Добавить в конец
        {
            Pet* tmp = new Pet();
            tmp->fill_from_keyboard();
            list.add_to_tail(tmp);
            break;
        }

        case 5: // Добавить за заданным номером
        {
            int pos{};
            std::cout << "Введите позицию за которой вставить элемент: ";
            std::cin >> pos;
            Pet* tmp = new Pet();
            tmp->fill_from_keyboard();
            list.add_after_position(tmp, pos);
            break;
        }

        case 6: // Удалить из начала
        {
            list.del_from_head();
            break;
        }

        case 7: // Удалить из конца
        {
            list.del_from_tail();
            break;
        }

        case 8: // Удалить элемент по номеру
        {
            int pos{};
            std::cout << "Введите позицию: ";
            std::cin >> pos;
            list.del_at_position(pos);
            break;
        }

        case 9: // Найти элемент по номеру
        {
            int pos{};
            std::cout << "Введите позицию элемента: ";
            std::cin >> pos;
            Pet* tmp = list.find_at_position(pos);
            if (tmp)
                tmp->print(std::cout);
            else
                std::cout << "Элемент с таким индексом не найден!\n";
            break;
        }

        case 10: // Удалить все элементы
        {
            list.clear();
            break;
        }

        case 11:  /*Получить список всех пациентов, посетивших клинику в заданном году,
            имеющих менее трех прививок.*/
        {
            std::cout << "Введите год для поиска: ";
            int year{};
            std::cin >> year;
            Container reslist = list.get_special_list_y(year);
            reslist.print();
            break;
        }

        case 12:  /*Получить список всех пациентов, возраст которых не превышает
            заданный, имеющих прививку заданного наименования.При этом
            удалить выбранные элементы из Контейнера.*/
        {
            int age{};
            std::string vac{};
            std::cout << "Введите возраст для поиска:"; std::cin >> age;
            std::cout << "Введите название прививки:"; std::cin >> vac;

            Container reslist = list.get_special_list_a(age, vac);
            reslist.print();
            break;
        }


        case 13: //Упорядочить пациентов по ФИО хозяина, кличке и полу.
        {
            list.sorting();
            list.print();
            break;
        }

        case 14: 
        {
            std::cout << "Работа завершена!\n";
            break;
        }
        }


    } while (choice != 14);
        

}

void print_menu()
{
    std::cout << "Меню работы со списком:\n";
    std::cout << "\t1.Заполнить из файла\n";
    std::cout << "\t2.Печать списка\n";
    std::cout << "\t3.Добавить в начало\n";
    std::cout << "\t4.Добавить в конец\n";
    std::cout << "\t5.Добавить за заданным номером\n";
    std::cout << "\t6.Удалить из начала\n";
    std::cout << "\t7.Удалить из конца\n";
    std::cout << "\t8.Удалить элемент по номеру\n";
    std::cout << "\t9.Найти элемент по номеру\n";
    std::cout << "\t10.Удалить все элементы\n";
    std::cout << "Меню решения задачи:\n";
    std::cout << "\t11.Получить список всех пациентов,посетивших клинику в заданном году, имеющих менее трех прививок.\n";
    std::cout << "\t2.Получить список всех пациентов, возраст которых не превышает заданный,имеющих прививку заданного наименования.\n";
    std::cout << "\t13.Упорядочить пациентов по ФИО хозяина, кличке и полу.\n";
    std::cout << "\t14.Завершить работу\n";
    std::cout << ">";
}

