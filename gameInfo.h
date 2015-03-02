#include <stdio.h>

int wrong;
int mapNumber;
int key, kw;
char keyword[10];

void setMapNumber(int n);
int getMapNumber();

void setKeyNumber(int n);
void addKeyNumber();
void subKeyNumber();
int getKeyNumber();

void setKeyword(int n);
void addKeyword();
int getKeyword();

void setWrongNumber(int n);
void addWrongNumber();
int getWrongNumber();

char* getMap();
void setMapObject(char c, int mx, int my);
char getMapObject(int mx, int my);