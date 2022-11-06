/*
  Menu.h
*/
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include "Win10.h"  // SetPos(), SetColor()
using namespace std;

// цвета для пунктов меню: активный, неактивный,
//   цвет консоли по умолчанию
#define COLOR_ACTIVE  \
    CREATE_COLOR(COLOR::blue, COLOR::light_yellow)
#define COLOR_NONACTIVE \
    CREATE_COLOR(COLOR::green, COLOR::black)
// цвет консоли по умолчанию: 0x07
#define COLOR_DEFAULT \
    CREATE_COLOR(COLOR::black, COLOR::white)

// класс оконного меню, версия 1.0
class Menu
{
public:
    // рабочие типы для класса Menu
    using ItemType = typename string; // тип одного пункта меню
    //using ItemsCont = typename vector<ItemType>; 
    using ItemsCont = typename list<ItemType>;  // контейнер для пунктов меню
    using Iter = typename ItemsCont::iterator;
    using CIter = typename ItemsCont::const_iterator;
private:
    ItemsCont Items; // массив пунктов меню
    int Row, Col;    // экранные координаты меню
    int cActive;     // цвет активного пункта меню: цвет фона и символов
    int cNonActive;  // цвет неактивного пункта меню: цвет фона и символов
    int cDefault;    // цвет консоли по умолчанию
    int Select;      // индекс активного пункта меню внутри окна меню
public:
    Menu() : Row(3), Col(5),
        cActive(COLOR_ACTIVE),
        cNonActive(COLOR_NONACTIVE),
        cDefault(COLOR_DEFAULT),
        Select()
    {}
    Menu(const ItemsCont& items) : Menu() {
        Items = items; // копирование пунктов меню
    }
    Menu(const ItemsCont& items, int row, int col)
        : Menu(items)
    {
        Row = row, Col = col;
    }
    // get/set-методы

    // вывод меню на экран и ожидание выбора
    int Show(int select = 0)
    {
        CursorHide(false); // скрыть экранный курсор

        if (select >= 0 && select < Items.size()) {
            Select = select;
        }
        else { Select = 0; }
        // цикл обработки меню
        while (true) {
            // 1) отобразить пункты меню на экран
            int i = 0;
            for (auto& item : Items) {
                SetPos(Row + i, Col); // позиция для i-ой строки
                // выбор цвета для активного и неактивного пунктов
                /*if (Select == i++) { SetColor(cActive); }
                else               { SetColor(cNonActive); }*/
                SetColor((Select == i++) ? cActive : cNonActive);
                cout << item; // вывод пункта меню
                //i++;
            }
            // вернуть цвет по умолчанию для консоли
            SetColor(cDefault);
            // проверка нажатия клавиши
            //if (_kbhit())
            {
                int key = _getch();
                if (key == CURSOR1 || key == CURSOR2) {
                    // для двухбайтных кодов клавиш
                    key = _getch();
                }
                // очистка, сброс буфера клавиатуры
                while (_kbhit()) { _getch(); }
                // обработка нажатий клавиш
                switch (key)
                {
                case _KEY::UP:   case _KEY::LEFT: // вверх
                    if (Select > 0) { Select--; }
                    break;
                case _KEY::DOWN: case _KEY::RIGHT: // вниз
                    if (Select < Items.size() - 1) { Select++; }
                    break;
                case _KEY::ENTER: // выбор пункта меню
                    return Select; // возвращаем выбранный индекс
                case _KEY::ESC:   // отказ от выбора
                    return -1; // возвращаем несуществующий индекс
                } // switch (key)
            } // if(_kbhit())
        } // while(true);
    } // int Show(select);

    int Show(int row, int col, int select = 0) {
        Row = row, Col = col;
        return Show(select);
    }

}; // class Menu;
