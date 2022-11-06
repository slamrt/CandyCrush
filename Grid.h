#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include "Win10.h"
#include "BaseCandy.h"
using namespace std;
#define RAND(min,max)  (rand()%((max)-(min)+1)+(min))

extern BananaCandy B;
extern AppleCandy A;
extern GrapeCandy G;
extern PlumCandy Pl;
extern PearCandy Pe;
class Grid
{
private:
	int Row, Col;
	int Height, Width;
	int SelRow1, SelCol1;
	int SelRow2, SelCol2;
	bool isSel;
	int SelCnt;
	vector <string> CurGrid;
	vector <string> PrevGrid;
	vector<vector<int>> CurGridColor;
	vector<vector<int>> PrevGridColor;
public:
	Grid(): Row(3), Col(5), Height(7), Width(7), SelRow1(), SelCol1(), SelRow2(),
		SelCol2(), isSel(), SelCnt() {}
	Grid(int row, int col, int height, int width): Row(row), Col(col),
		Height(height), Width(width), SelCnt(0) {
		this->Create();
	}
	int getRow() const{ return Row; }
	int getCol() const{ return Col; }
	int getHeight() const{ return Height; }
	int getWidth() const{ return Width; }
	int getSelCnt() const { return SelCnt; }
	vector<string> getCurGrid() const {
		return CurGrid;
	}
	vector<vector<int>> getCurGridColor() const {
		return CurGridColor;
	}
	void Create();
	
	void Draw();
	
	string& operator[](int index) {
		return CurGrid[index];
	}

	void ReDraw();
	void Move();
	bool isMove(int sel1, int row1, int sel2, int row2);


	const string& operator[](int index)const {
		return PrevGrid[index];
	}
};

