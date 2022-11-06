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

// ����� ��� ������� ����: ��������, ����������,
//   ���� ������� �� ���������
#define COLOR_ACTIVE  \
    CREATE_COLOR(COLOR::blue, COLOR::light_yellow)
#define COLOR_NONACTIVE \
    CREATE_COLOR(COLOR::green, COLOR::black)
// ���� ������� �� ���������: 0x07
#define COLOR_DEFAULT \
    CREATE_COLOR(COLOR::black, COLOR::white)

// ����� �������� ����, ������ 1.0
class Menu
{
public:
    // ������� ���� ��� ������ Menu
    using ItemType = typename string; // ��� ������ ������ ����
    //using ItemsCont = typename vector<ItemType>; 
    using ItemsCont = typename list<ItemType>;  // ��������� ��� ������� ����
    using Iter = typename ItemsCont::iterator;
    using CIter = typename ItemsCont::const_iterator;
private:
    ItemsCont Items; // ������ ������� ����
    int Row, Col;    // �������� ���������� ����
    int cActive;     // ���� ��������� ������ ����: ���� ���� � ��������
    int cNonActive;  // ���� ����������� ������ ����: ���� ���� � ��������
    int cDefault;    // ���� ������� �� ���������
    int Select;      // ������ ��������� ������ ���� ������ ���� ����
public:
    Menu() : Row(3), Col(5),
        cActive(COLOR_ACTIVE),
        cNonActive(COLOR_NONACTIVE),
        cDefault(COLOR_DEFAULT),
        Select()
    {}
    Menu(const ItemsCont& items) : Menu() {
        Items = items; // ����������� ������� ����
    }
    Menu(const ItemsCont& items, int row, int col)
        : Menu(items)
    {
        Row = row, Col = col;
    }
    // get/set-������

    // ����� ���� �� ����� � �������� ������
    int Show(int select = 0)
    {
        CursorHide(false); // ������ �������� ������

        if (select >= 0 && select < Items.size()) {
            Select = select;
        }
        else { Select = 0; }
        // ���� ��������� ����
        while (true) {
            // 1) ���������� ������ ���� �� �����
            int i = 0;
            for (auto& item : Items) {
                SetPos(Row + i, Col); // ������� ��� i-�� ������
                // ����� ����� ��� ��������� � ����������� �������
                /*if (Select == i++) { SetColor(cActive); }
                else               { SetColor(cNonActive); }*/
                SetColor((Select == i++) ? cActive : cNonActive);
                cout << item; // ����� ������ ����
                //i++;
            }
            // ������� ���� �� ��������� ��� �������
            SetColor(cDefault);
            // �������� ������� �������
            //if (_kbhit())
            {
                int key = _getch();
                if (key == CURSOR1 || key == CURSOR2) {
                    // ��� ����������� ����� ������
                    key = _getch();
                }
                // �������, ����� ������ ����������
                while (_kbhit()) { _getch(); }
                // ��������� ������� ������
                switch (key)
                {
                case _KEY::UP:   case _KEY::LEFT: // �����
                    if (Select > 0) { Select--; }
                    break;
                case _KEY::DOWN: case _KEY::RIGHT: // ����
                    if (Select < Items.size() - 1) { Select++; }
                    break;
                case _KEY::ENTER: // ����� ������ ����
                    return Select; // ���������� ��������� ������
                case _KEY::ESC:   // ����� �� ������
                    return -1; // ���������� �������������� ������
                } // switch (key)
            } // if(_kbhit())
        } // while(true);
    } // int Show(select);

    int Show(int row, int col, int select = 0) {
        Row = row, Col = col;
        return Show(select);
    }

}; // class Menu;
