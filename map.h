#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct point{
	int x;
	int y;
}Points;

int problemNumber;

char menu[];
char end[];
char map01[550];
char map02[550];
char map03[550];
char map04[550];

void gotoxy(int xpos, int ypos);
void showCursor(int visible);
void printMenu(int n);
void printMap();

int isRoad(int mx, int my);
int isAnything(int mx, int my);
int isAnythingHappened(char c, int mx, int my);
int isChangeMap(int mx, int my);

void changeAPoint(int* mx, int* my);