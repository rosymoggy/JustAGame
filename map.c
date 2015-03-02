#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "map.h"
#include "gameInfo.h"

char menu[] = { "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n"
				"*                                                                     *\n"
				"*                                                                     *\n"
				"*                                                                     *\n"
				"*    JJJJJ U   U  SSSS TTTTT      A       GGGG    A   M     M EEEEE   *\n"
				"*      J   U   U S       T       A A     G       A A  MM   MM E       *\n"
				"*      J   U   U  SSS    T      A   A    G  GGG A   A M M M M EEEE    *\n"
				"*   J  J   U   U     S   T      AAAAA    G    G AAAAA M  M  M E       *\n"
				"*    JJ     UUU  SSSS    T      A   A     GGG G A   A M     M EEEEE   *\n"
				"*                                                                     *\n"
				"*                           Any key to play.                          *\n"
				"*                                                                     *\n"
				"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n"};
//CONGRATULATION
char end[] = {  "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n"
				"*                                                                           *\n"
				"*                                                                           *\n"
				"*                                                                           *\n"
				"*  CC   OO  N   N  GG  RRRR    A  TTTTT U  U L      A  TTTTT III  OO  N   N *\n"
				"* C  C O  O NN  N G  G R   R  A A   T   U  U L     A A   T    I  O  O NN  N *\n"
				"* C    O  O N N N G    RRRR  A   A  T   U  U L    A   A  T    I  O  O N N N *\n"
				"* C  C O  O N  NN G GG R  R  AAAAA  T   U  U L    AAAAA  T    I  O  O N  NN *\n"
				"*  CC   OO  N   N  G G R   R A   A  T    UU  LLLL A   A  T   III  OO  N   N *\n"
				"*                                                                           *\n"
				"*                           Thanks for play.                                *\n"
				"*                                                                           *\n"
				"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n"};

// 49 x 11 (0~48 x 0~10)
char map01[550] = { "* * * * * * * * * * * * * * * * * * * * * * * * *"
					"*   *             *     *   *     *       *[K]  *"
					"*   *   * * *     *     |         *   *   *     *"
					"*   *   *[?]* *   * *   * * *     * * *   * *[Q]*"
					"*       *     *     *       *         *         *"
					"* * * * *   * * *   *   * * * * *   * * *   *   *"
					"*                   *       *[?]*   *       *   2"
					"*   * * *   * * * * * * *   *   *   * *   * * * *"
					"*   *[K]*   |       *       *   *   * *   *[K]  *"
					"*       *   *           *   *   |         *     *"
					"* * * * * * * * * * * * * 3 * * * * * * * * * 3 *"};

char map02[550] = { "* * * * * * * * * * * * * * * * * * * * * * * * *"
					"*   *       *        [?]*       *       *   |   *"
					"*       *       *       *   *       *   *   *   *"
					"*   * * * *   * * * * * *   * * * * *       *   *"
					"*       *             *     *       *   * * *   *"
					"* * *   * * * * *   * *   * *[Q]*   *   *       *"
					"1   *           *     |     *   *   *   *   *[Q]*"
					"*   * * *   * * *   * * * * *[K]*       *   *[K]*"
					"*       *   *         *[K]  * * *       *   * * *"
					"*   *       *[?]*     *                 *       *"
					"* * * * * * * * * * * * * * * * * * * * * * * 4 *"};

char map03[550] = { "* * * * * * * * * * * * * 1 * * * * * * * * * 1 *"
					"*[K]*   *[K]*       *       *   *   *       *   *"
					"*           *   *       * * *   *       *   *   *"
					"* * *[Q]* * *   * * * * *[K]*   *   *   *   *   *"
					"*         *     *       *       *   *       *   *"
					"*                   *   *   *   *   * * *       *"
					"*   * * * * * * * * *   *   *   *       * * * * *"
					"*     *           *     |   *   * * *     *     *"
					"*     *   *   *   * * * * * *       * *   |     4"
					"*  [?]*[?]*                     *         *     *"
					"* * * * * * * * * * * * * * * * * * * * * * * * *"};

char map04[550] = { "* * * * * * * * * * * * * * * * * * * * * * * 2 *"
					"*     |     *   |   *[?]*       *   *       *   *"
					"*   * * *   *   *   *   *   *   |   *   *       *"
					"*     *     *   *   *   *   * * *   *   * * * * *"
					"* *   *   * *   *   |   *       *               *"
					"*     *         *   * * * *   * * * * * * *[C]* *"
					"*[?]  * * * *   * * *           *   |   *       *"
					"* * * *         *[K]*   *   * * *   *   *[A]*[B]*"
					"3     *   * *   *   *       *       *   *   *   *"
					"*     |   *             *       *   *[?]*[K]*[K]*"
					"* * * * * * * * * * * * * * * * * * * * * * * * *"};

char keyword[10] = "JUSTAGAME";

void gotoxy(int xpos, int ypos)
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos; scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput,scrn);
}

void showCursor(int visible)
{
    CONSOLE_CURSOR_INFO ConCurInf;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hStdOut, &ConCurInf);
    ConCurInf.bVisible = visible;
    SetConsoleCursorInfo(hStdOut, &ConCurInf);
}

void printMenu(int n){
	int i, j;
	system("CLS");
	if(n == 1) printf("%s", menu);
	else printf("%s", end);
	for(i=2, j=68; ; i+=2, j-=2){
		gotoxy(i, 0), printf(" ");
		gotoxy(j, 12), printf(" ");
		Sleep(100);
		gotoxy(i, 0), printf("*");
		gotoxy(j, 12), printf("*"); 
		if(kbhit()) break;
		if(i > 68) i=2, j=68;
	}
	setMapNumber(1);
	setKeyNumber(0);
	setKeyword(0);
	setWrongNumber(0);
	problemNumber = 1;
}

void printMap(){
	int i, j, k=getKeyword(), knum=getKeyNumber();
	char *m = getMap();
	system("CLS");
	gotoxy(10, 15), printf("Use ↑↓←→ Z.");
	gotoxy(10, 16), printf("Door key: %d, Keyword: ", knum);
	for(i=0; i<k; i++) printf("%c", keyword[i]);
	for(i=0; i<9-getKeyword(); i++) printf("*");
	for(i=0; i<11; i++){
		for(j=0; j<49; j++){
			gotoxy(j, i);
			if(m[i*49+j]!='E' && !(m[i*49+j]<='9' && m[i*49+j]>='0')) printf("%c", m[i*49+j]);
			else printf(" ");
		}
	}
}

int isRoad(int mx, int my){
	char c = getMapObject(mx, my);
	if( c == ' ' || ( c <= '9' && c>= '0')) return TRUE;
	return FALSE;
}

int isAnything(int mx, int my){
	if( isAnythingHappened(getMapObject(mx+2, my), mx+2, my) ) return TRUE;
	else if( isAnythingHappened(getMapObject(mx-2, my), mx-2, my) ) return TRUE;
	else if( isAnythingHappened(getMapObject(mx, my+1), mx, my+1) ) return TRUE;
	else if( isAnythingHappened(getMapObject(mx, my-1), mx, my-1) ) return TRUE;
	return FALSE;
}

int isAnythingHappened(char c, int mx, int my){
	int i;
	char cho;
	if(c=='K' || (c=='|' && getKeyNumber()>0) || c=='?'){
		if(c == 'K') addKeyNumber(); // key
		else if(c == '|') subKeyNumber();// door
		else if(c == '?') addKeyword(); // keyword
		setMapObject(' ', mx, my);
		gotoxy(mx, my), printf(" ");
		gotoxy(10, 16), printf("Door key: %d, Keyword: ", getKeyNumber());
		for(i=0; i<getKeyword(); i++) printf("%c", keyword[i]);
		for(i=0; i<9-getKeyword(); i++) printf("*");
		return TRUE;
	}
	else if(c=='|' && getKeyNumber()<=0) gotoxy(10, 18), printf("Door key haven't enough.");
	else if(c=='Q'){
		switch(problemNumber){
		case 1:
			gotoxy(10, 18), printf("西元2000年是閏年嗎? (y/n)");
			cho = getch();
			if(cho=='Y' || cho=='y') addWrongNumber();
			else if(cho=='N' || cho=='n') {
				setMapObject(' ', mx, my);
				problemNumber++;
				gotoxy(mx, my), printf(" ");
			}
			break;
		case 2:
			gotoxy(10, 18), printf("遊戲的名字是JUST AN GAME嗎? (y/n)");
			cho = getch();
			if(cho=='Y' || cho=='y') addWrongNumber();
			else if(cho=='N' || cho=='n') {
				setMapObject(' ', mx, my);
				problemNumber++;
				gotoxy(mx, my), printf(" ");
			}
			break;
		case 3:
			gotoxy(10, 18), printf("哆啦A夢有耳朵嗎? (y/n)");
			cho = getch();
			if(cho=='Y' || cho=='y') addWrongNumber();
			else if(cho=='N' || cho=='n') {
				setMapObject(' ', mx, my);
				problemNumber++;
				gotoxy(mx, my), printf(" ");
			}
			break;
		case 4:
			gotoxy(10, 17), printf("「我是獨子，我兒子的爸爸，是我爸的");
			gotoxy(10, 18), printf("  兒子。」這段話是對的。 (y/n)");
			cho = getch();  
			if(cho=='Y' || cho=='y') {
				setMapObject(' ', mx, my);
				problemNumber++;
				gotoxy(mx, my), printf(" ");
			}
			else if(cho=='N' || cho=='n') addWrongNumber();
			break;
		}
		return TRUE;
	}
	else if(c=='C'){
		gotoxy(10, 18), printf("You can only choose one of them.");
		cho = getch();
		if(cho=='A' || cho=='a' || cho=='B' || cho=='b'){
			setMapObject(' ', mx, my);
			gotoxy(mx, my), printf(" ");
			if(cho == 'A' || cho == 'a') {
				setMapObject(' ', 42, 7);
				gotoxy(42, 7), printf(" ");
			}
			else {
				setMapObject(' ', 46, 7);
				gotoxy(46, 7), printf(" ");
			}
		}
		else gotoxy(10, 18), printf("Please enter \"A\" or \"B\".");
		return TRUE;
	}
	return FALSE;
}

int isChangeMap(int mx, int my){
	char c = getMapObject(mx, my);
	if(c <= '9' && c >= '0') return TRUE;
	return FALSE;
}

void changeAPoint(int* mx, int* my){
	char c = getMapObject(*mx, *my);
	int n1 = getMapNumber(), n2 = c-'0';
	setMapNumber(n2);
	switch(n1){
	case 1:
		if(n2 == 2) *mx = 2;
		if(n2 == 3) *my = 1;
		break;
	case 2:
		if(n2 == 1) *mx = 46;
		if(n2 == 4) *my = 1;
		break;
	case 3:
		if(n2 == 1) *my = 9;
		if(n2 == 4) *mx = 2;
		break;
	case 4:
		if(n2 == 2) *my = 9;
		if(n2 == 3) *mx = 46;
		break;
	}
}
