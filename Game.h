/*
  Game.h
*/
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
//#include "Win10.h"    // SetPos(), SetColor()
#include "Grid.h"
using namespace std; 

class Game
{
private:
	Grid grid; // поле
	//vector <Candy> Candies; // массив конфет
	bool isPause, isGameOver, isWin;
    /*int SelRow1, SelCol1;
    int SelRow2, SelCol2;
    int SelCnt;*/
    
public:
	Game(): grid(3, 5, 7, 7), isPause(false), isGameOver(false), isWin(false)/*,
    SelRow1(), SelCol1(), SelRow2(), SelCol2(), SelCnt()*/ {}   
    void Run()
    {
        // должно быть главное меню игры
        StartNewGame();
        //ContinueGame();
        //Settings();
        //Save();
        //Load();
        //About();
        //Top();
    }
    
    void StartNewGame() {
        grid.Create();
        /*for (auto c : Candies) { delete c; }
        Candies.clear();*/
       /* for (int i = 0; i < grid.getWidth() * grid.getHeight(); i++) {
            Candies.push_back(new Candy);
        }*/
        //grid.Draw();
        //ContinueGame();
        isGameOver = false;
        isWin = false;
        ContinueGame();
    }
    
    void ContinueGame() {
        isPause = false;
        Logic();
    }
    void Logic();
    void Move(Grid& Field);
};

