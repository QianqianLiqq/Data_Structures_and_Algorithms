#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct SData{
	int nNumb;
	char sName[20];
	float fMath;
}DATA;

bool byNumb(DATA d1, DATA d2){
	return d1.nNumb < d2.nNumb;
}

bool byName(DATA d1, DATA d2){
	return strcmp(d1.sName, d2.sName) < 0;
}

bool byMath(DATA d1, DATA d2){
	return d1.fMath > d2.fMath;
}

int main(){
	DATA ds[] = {
		{ 1008, "dd", 98.5f },
		{ 1003, "fff", 94 },
		{ 1005, "aaa", 96 },
		{ 1004, "bbb", 97 },
	};
	sort(ds, ds + 4, byMath);

	return 0;
}
