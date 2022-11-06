#include "Game.h"
void Game::Logic() {
	CLS;
	grid.Create();
	grid.Draw();
	while (true) {
		//bool isClick = true;
		if (isLButtonDown()) {
				grid.Move();
				SetPos(grid.getRow() + 10, grid.getCol() + 10);
				cout << grid.getSelCnt()/* << "\t" << isLButtonDown()*/;
				grid.ReDraw();
				//cout.flush();
			//if (grid.isMove()) {
			//}
				//return;
			//isClick = false;
		}
		
		
		/*if (isLButtonDown) {
			int tRow, tCol;

			GetMouseCoord(tRow, tCol);
			tRow -= grid.getRow();
			tCol -= grid.getCol();
			if(tRow >= 0 && tRow <= grid.getHeight() && tCol >= 0 && tCol <= grid.getWidth()) {
				if (SelCnt == 0) {
					SelRow1 = tRow;
					SelCol1 = tCol;
					SelCnt++;
				}
				else if (SelCnt == 1) {
					SelRow2 = tRow;
					SelCol2 = tCol;
					SelCnt++;
					Move(grid);
				}
				else {
					SelCnt = 0;
				}
				grid.ReDraw();
			}
		}*/
	}
}

//void Game::Move(Grid& Field) {
//	if (SelCnt == 2) {
//		swap(Field[SelRow1][SelCol1], Field[SelRow2][SelCol2]);
//	}
//}
