#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "map.h"
#include "gameInfo.h"

int main(int argc, char* argv){
	Points start, move;
	int keyinFirst, keyinSecond, i;

	showCursor(0);
	printMenu(1);
	printMap();
	start.x = move.x = 2;
	start.y = move.y = 1;
	gotoxy(move.x, move.y), printf("A");
	while(1){
		if( kbhit() ){
			gotoxy(move.x, move.y), printf(" ");
			gotoxy(10, 17), printf("                                   ");
			gotoxy(10, 18), printf("                                   ");
			keyinFirst = getch();
			if(keyinFirst == 224) {
				keyinSecond = getch();
				switch(keyinSecond){
				case 72: /* up */
					if(isRoad(move.x, move.y-1)) move.y--;
					break;
				case 80: /* down */
					if(isRoad(move.x, move.y+1)) move.y++;
					break;
				case 75: /* left */
					if(isRoad(move.x-2, move.y)) move.x-=2;
					break;
				case 77: /* right */
					if(isRoad(move.x+2, move.y)) move.x+=2;
					break;
				}
			}
			else if(keyinFirst == 'z' || keyinFirst == 'Z'){
				if( isAnything(move.x, move.y) ) gotoxy(10, 17), printf("There is something.                ");
				else gotoxy(10, 17), printf("Nothing happened.                  ");
				gotoxy(10, 18), printf("                                   ");
			}
			
			if(isChangeMap(move.x, move.y)){
				changeAPoint(&move.x, &move.y);
				printMap();
			}
			gotoxy(move.x, move.y), printf("A");
		}
		if(kw >= 9){
			for(i=0; i<3; i++){
				printMap();
				Sleep(500);
			}
			break;
		}
	}
	printMenu(2);
	keyinFirst = getch();
	Sleep(1000);
	return 0;
}