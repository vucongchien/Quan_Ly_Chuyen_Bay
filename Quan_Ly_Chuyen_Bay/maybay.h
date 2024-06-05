#pragma once
#include<cstring>
#include<fstream>
#include<iostream>
#include"hanhkhach.h"
#define MAX_MB 300 
#define yc 3 
//taoButton(920,370,1130,440,"THEM",11) ;
//	taoButton(920,445,1130,525,"XOA",12) ; 
//	taoButton(920,530,1130,600,"SUA",13) ; 
using namespace std;
struct maybay {
	char  sohieu[35]; char loai[40];
	int soday, sodong;
	int socho = sodong * soday;
};
struct listmb {
	int n = 0;
	maybay* nodes[MAX_MB];
};
bool Emptyds(listmb ds) {
	return ds.n == 0;
}
bool Full(listmb ds) {
	return ds.n = MAX_MB;
}
void addmb(listmb& ds, maybay& x) {
	ds.nodes[ds.n] = new maybay;
	*ds.nodes[ds.n] = x;
	ds.n++;
}
void deletemb(listmb& ds, int vitri) {
	delete ds.nodes[vitri];
	for (int i = vitri; i < ds.n - 1; i++) {
		ds.nodes[i] = ds.nodes[i + 1];
	}
	ds.n--;
}
void chinhsua(listmb& ds, int vitri, maybay& x) {
	*ds.nodes[vitri] = x;
}
int timkiem(listmb& ds, char* sohieumb) {
	for (int i = 0; i < ds.n; i++) {
		if (!strcmp(ds.nodes[i]->sohieu, sohieumb)) return i;
	}
	return -1;
}
maybay taomaybay(char* s, char* z, int x, int y) {
	maybay tmp;
	STRCPYY(tmp.sohieu, s);
	STRCPYY(tmp.loai, z);
	tmp.soday = x;
	tmp.sodong = y;
	return tmp;
}
void savefile(listmb& dsmb) {
	ofstream file("MAYBAY.txt", ios::out | ios::binary);
	for (int i = 0; i < dsmb.n; ++i) {
		file.write(reinterpret_cast<char*>(dsmb.nodes[i]), sizeof(maybay));
	}
	file.close();
}
void openfile(listmb& dsmb) {
	ifstream file("MAYBAY.txt", ios::in | ios::binary);
	maybay mb;
	while (file.read(reinterpret_cast<char*>(&mb), sizeof(maybay))) {
		dsmb.nodes[dsmb.n] = new maybay;
		*dsmb.nodes[dsmb.n] = mb;
		dsmb.n++;
	}
	file.close();
}
listmb ds_mb;
struct dsmbchay
{
	char sohieu[30];
	int lan;
};
struct dsdsmbchay
{
	dsmbchay db;
	dsdsmbchay* next;
};
typedef struct dsdsmbchay* dsmbc;
dsmbc newc(dsmbchay a) {
	dsmbc tmp = new dsdsmbchay;
	tmp->db = a;
	tmp->next = NULL;
	return tmp;
}
void pushmb(dsmbc& a, dsmbchay x) {
	dsmbc tmp = newc(x);
	if (a == NULL) {
		a = tmp;
	}
	else {
		dsmbc truoc = NULL, sau = NULL;
		sau = a;
		while (sau != NULL) {
			if (sau->db.lan <= x.lan) {
				if (truoc == NULL) {
					tmp->next = sau;
					a = tmp;
				}
				else {
					truoc->next = tmp;
					tmp->next = sau;
				}
				break;
			}
			truoc = sau;
			sau = sau->next;
		}
		if (sau == NULL) {
			truoc->next = tmp;
		}
	}
}