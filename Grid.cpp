#include "Grid.h"
BananaCandy B;
AppleCandy A;
GrapeCandy G;
PlumCandy Pl;
PearCandy Pe; 
//vector<char> Candies = { B.getImage(), A.getImage(), G.getImage(), Pl.getImage(), Pe.getImage() };
vector<BaseCandy*> Candies = {&B, &A, &G, &Pl, &Pe};
//vector<int> Colors = { B.getColor(), A.getColor(), G.getColor(), Pl.getColor(), Pe.getColor() };

void Grid::Create() {
	CurGrid.clear();
	CurGrid.resize(Height);
	CurGridColor.clear();
	CurGridColor.resize(Height);
	for (int i = 0; i < Height; i++) {
		
		CurGrid[i].resize(Width);
		CurGridColor[i].resize(Width);
		for (int j = 0; j < Width; j++) {
			int k = RAND(0, 4);
			char c = Candies[k]->getImage();
			//SetColor(Colors[k]);
			CurGrid[i][j] = c;
			CurGridColor[i][j] = Candies[k]->getColor();
		}
	}
	PrevGridColor = CurGridColor;
	PrevGrid = CurGrid;
}//Create()


void Grid::Draw() {
	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < Width; j++) {
			SetPos(Row + i, Col + j);
			SetColor(CurGridColor[i][j]);
			cout << CurGrid[i][j];
		}
	}
}

void Grid::ReDraw() {
	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < Width; j++) {
			SetPos(Row + i, Col + j);
			SetColor(CurGridColor[i][j]);
			cout << CurGrid[i][j];
			
		}
	}
	//cout.flush(); //working
	// сохраняем обновление на OldCanvas
	PrevGrid = CurGrid;
}
void Grid::Move() {
	//if (isLButtonDown()) {
		//SelCnt++;
		//COORD coord = {tRow, tCol};
		//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		int tRow, tCol;
		GetMouseCoord(tRow, tCol);
		tRow -= Row;
		tCol -= Col;
		if (tRow >= 0 && tRow < Height && tCol >= 0 && tCol < Width) {
			if (SelCnt == 0) {

				SelRow1 = tRow;
				SelCol1 = tCol;
				/*tRow = 0;
				tCol = 0;*/
				SelCnt =1;
				//cout.flush();
			}
			else if (SelCnt == 1) {
				SelRow2 = tRow;
				SelCol2 = tCol;
				/*tRow = 0;
				tCol = 0;*/
				SelCnt =0;
				if (isMove(SelRow1, SelCol1, SelRow2, SelCol2)) {
					swap(CurGrid[SelRow1][SelCol1], CurGrid[SelRow2][SelCol2]);
					swap(CurGridColor[SelRow1][SelCol1], CurGridColor[SelRow2][SelCol2]);
					/*tRow = 0;
					tCol = 0;*/
					//cout.flush();
				}
				//Move();
				//cout.flush();
			}
			else {
				SelCnt = 0;
				
			}
			/*tRow = 0;
			tCol = 0;*/
			//ReDraw();
		//}
	}
}

bool Grid::isMove(int row1, int col1, int row2, int col2) {
	if (abs(row1-row2) == 1 && abs(col1 - col2) == 1) {
		return true;
	}
	return false;
}

