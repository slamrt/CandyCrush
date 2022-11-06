/*
  MainGame.cpp
*/
//#include "Win10.h"
#include "Game.h"
#include "Menu.h"
//#include "Game.h"  // class Game

//void StartTitle()
//{
//	// TO DO
//}
//
//void EndTitle()
//{
//	// TO DO
//}
// перечень пунктов меню
Menu::ItemsCont mainMenu{
  "Start game",
  " Continue ",
  "  Setting ",
  "    Top   ",
  "   Save   ",
  "   Load   ",
  "   About  ",
  "   Exit   ",
};

// меню для настроек - вложенное меню
Menu::ItemsCont setMenu{
  "Level",
  "Speed",
  "Cloros",
  "Sound",
  "Main menu",
};
int main()
{
    // экземпляр класса Menu для главного меню
    Menu mMain(mainMenu, 3, 6);
    Menu mSettings(setMenu, 4, 8); // для настроек
    bool isDone = false;
    int select = 0;
    Game game;
    while (isDone == false)
    {
        CLS; // очистка экрана - system( "cls" )
        select = mMain.Show(select);
        switch (select)
        {
        case 0: // "Start game",
            SetPos(0, 0);
            cout << "Select: Start game" << endl;
            //StartTitle(); // Стартовая заставка
            game.Run();
            break;
        case 1: // "Continue",
            SetPos(0, 0);
            cout << "Select: Continue game" << endl;
            break;
        case 2: // "Setting",
        {
            CLS;
            int sel = mSettings.Show();
            SetPos(0, 0);
            switch (sel) {
            case 0: // "level"
                cout << "Level\n"; break;
            case 1: // "Speed"
                cout << "Speed\n"; break;
            case 4: case -1: // выход в предыдущее меню
                cout << "To main menu\n";
                break;
            } // switch (sel)
            PAUSE; // пауза на консоли
        }
        break;
        case 3: break; // "Top",
        case 4: break; // "Save",
        case 5: break; // "Load",
        case 6: break; // "About",

        case 7: // "Exit",
        case -1: // отказ от выбора
            isDone = true;
            break; // выход из цикла главного меню
        } // switch (select)
    } // while (isDone == false)
    cout << "Good bye...\n";
	//Menu menu;
	//menu.Show();
	////StartTitle(); // Стартовая заставка
	//Game game;
	//game.Run();
	/*grid.Create();
	grid.Draw();*/
	//EndTitle();   // Завершающпя заставка
}

