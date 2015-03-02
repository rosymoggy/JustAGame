#include <stdio.h>
#include "gameInfo.h"
#include "map.h"

void setMapNumber(int n){ mapNumber = n; }

int getMapNumber(){ return mapNumber; }

char* getMap(){
	if( getMapNumber() == 1 ) return &map01[0];
	else if( getMapNumber() == 2 ) return &map02[0];
	else if( getMapNumber() == 3 ) return &map03[0];
	else return &map04[0];
}

void setMapObject(char c, int mx, int my){
	char* m = getMap();
	m[my*49+mx] = c;
}

char getMapObject(int mx, int my){
	char* m = getMap();
	return m[my*49+mx];
}

void setKeyNumber(int n){ key = n; }
void addKeyNumber(){ key++; }
void subKeyNumber(){ if(key>0) key--;}
int getKeyNumber(){ return key; }

void setKeyword(int n){ kw = n; }
void addKeyword(){ kw++; }
int getKeyword(){ return kw; }

void setWrongNumber(int n){ wrong = n; }
void addWrongNumber(){ wrong++; }
int getWrongNumber(){ return wrong; }