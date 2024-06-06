#pragma once
#include<iostream>
#include<ctime>
#include "maybay.h"
#include"hanhkhach.h"
#include<fstream>
#include<sstream>
#include<string>


using namespace std;
void hienthiloi(char a[]);
void chuyenstringschar(char a[], string b) {
	int d = b.length();
	for (int i = 0; i <= d; i++) {
		a[i] = b[i];
	}
	a[d] = '\0';
}
struct day_time
{
	int gio, phut, ngay, thang, nam;
};
struct chuyenbay
{
	char macb[30];
	char sanbay[30];
	day_time tg;
	char sohieu[30];
	int trangthai;//1.huy chuyen,2.conve,3.hetve,4.hoantat
	int sove;
	char** danhsachve;
};
struct dschuyenbay
{
	chuyenbay cb;
	dschuyenbay* next;
};
typedef struct dschuyenbay* ds;



ds newcb(chuyenbay a) {
	ds tmp = new dschuyenbay;
	tmp->cb = a;
	tmp->next = NULL;
	return tmp;
}
void push(ds& a, chuyenbay x) {
	ds tmp = newcb(x);
	if (a == NULL) {
		a = tmp;
	}
	else {
		ds truoc = NULL, sau = NULL;
		sau = a;
		while (sau != NULL) {
			if (strcmp(sau->cb.macb, x.macb) < 0) {
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
void deletecb(ds& a, int p) {
	if (a == NULL) {
		return; // Ki?m tra danh sách có r?ng không
	}
	if (p == 0) {
		ds temp = a;
		a = a->next;
		delete temp;
		return;
	}
	int tmp = 0;
	ds q = a;
	ds sau = NULL;
	while (q != NULL && tmp < p) {
		sau = q;
		q = q->next;
		tmp++;
	}
	if (q == NULL) {
		return; // Tr??ng h?p v? trí p không h?p l?
	}
	sau->next = q->next;
	delete q;
}
chuyenbay laychuyenbay(ds& s, int p) {
	if (s == NULL) {
		return chuyenbay(); // Ki?m tra danh sách có r?ng không
	}
	if (p == 0) {
		chuyenbay temp = s->cb;
		return temp;
	}
	int tmp = 0;
	chuyenbay tra;
	ds q = s;
	ds sau = NULL;
	while (q != NULL && tmp < p) {
		sau = q;
		q = q->next;
		tmp++;
	}
	if (q == NULL) {
		return chuyenbay();
	}
	tra = q->cb;
	return tra;
}
// l?y ???c chuy?n bay a
char** cap_phat(int size) {
	return new char* [size];
}

// Hàm gi?i phóng b? nh? c?a m?ng 2 chi?u (char **)
void giai_phong(char** arr, int size) {
	for (int i = 0; i < size; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
}

// Hàm thêm hành khách vào danh sách vé c?a m?t chuy?n bay


void sua_thong_tin_cb(ds& s, chuyenbay b) {
	if (s == NULL) {
		return;
	}
	for (ds duyet = s; duyet != NULL; duyet = duyet->next) {
		if (strcmp(duyet->cb.macb, b.macb) == 0) {
			STRCPYY(duyet->cb.sanbay, b.sanbay);
			STRCPYY(duyet->cb.sohieu, b.sohieu);
			duyet->cb.trangthai = b.trangthai;
			duyet->cb.tg.ngay = b.tg.ngay;
			duyet->cb.tg.thang = b.tg.thang;
			duyet->cb.tg.nam = b.tg.nam;
			duyet->cb.tg.gio = b.tg.gio;
			duyet->cb.tg.phut = b.tg.phut;
			if (b.sove != duyet->cb.sove) {
				char** new_danhsachve = new char* [b.sove];
				for (int i = 0; i < b.sove; ++i) {
					new_danhsachve[i] = new char[30];
					if (i < duyet->cb.sove) {
						for (int j = 0; j < 30; j++) {
							new_danhsachve[i][j] = duyet->cb.danhsachve[i][j];

						}
					}
					else {
							new_danhsachve[i][0] = '\0';
					}
						
				}
				for (int i = 0; i < duyet->cb.sove; ++i) {
					delete duyet->cb.danhsachve[i];
				}
				delete duyet->cb.danhsachve;
				duyet->cb.danhsachve = new_danhsachve;
				duyet->cb.sove = b.sove;
			}
			else {
				duyet->cb.sove = b.sove;
			}
		}
	}
}
int sovecon(chuyenbay cb) {
	int tmp = 0;
	for (int i = 0; i < cb.sove; i++) {
		if (cb.danhsachve[i] != 0) {
			tmp++;
		}
	}
	return cb.sove - tmp;

}
void update_trang_thai(chuyenbay& cb) {
	if (cb.trangthai == 1 || cb.trangthai == 4) {
		return;
	}
	time_t thoigianhientai = time(nullptr);
	tm time;
	localtime_s(&time, &thoigianhientai);
	if ((time.tm_year + 1900) > cb.tg.nam) {
		cb.trangthai = 4;
	}
	else {
		if ((time.tm_year + 1900) < cb.tg.nam) {
			int dem = 0;
			for (int i = 0; i < cb.sove; i++) {
				if (cb.danhsachve[i][0] != '\0') {
					dem++;
				}
			}
			if (dem == cb.sove) {
				cb.trangthai = 3;
			}
			else {
				cb.trangthai = 2;
			}
		}
		else {
			if ((time.tm_mon + 1) > cb.tg.thang) {
				cb.trangthai = 4;
			}
			else {
				if ((time.tm_mon + 1) < cb.tg.thang) {
					int dem = 0;
					for (int i = 0; i < cb.sove; i++) {
						if (cb.danhsachve[i][0] != '\0') {
							dem++;
						}
					}
					if (dem == cb.sove) {
						cb.trangthai = 3;
					}
					else {
						cb.trangthai = 2;
					}
				}
				else {
					if (time.tm_mday > cb.tg.ngay) {
						cb.trangthai = 4;
					}
					else {
						if (time.tm_mday < cb.tg.ngay) {
							int dem = 0;
							for (int i = 0; i < cb.sove; i++) {
								if (cb.danhsachve[i][0] != '\0') {
									dem++;
								}
							}
							if (dem == cb.sove) {
								cb.trangthai = 3;
							}
							else {
								cb.trangthai = 2;
							}

						}
						else {
							if (time.tm_hour > cb.tg.gio) {
								cb.trangthai = 4;
							}
							else {
								if (time.tm_hour < cb.tg.gio) {
									int dem = 0;
									for (int i = 0; i < cb.sove; i++) {
										if (cb.danhsachve[i][0] != '\0') {
											dem++;
										}
									}
									if (dem == cb.sove) {
										cb.trangthai = 3;
									}
									else {
										cb.trangthai = 2;
									}
								}
								else {
									if (time.tm_min >= cb.tg.phut) {
										cb.trangthai = 4;
									}
									else {
										int dem = 0;
										for (int i = 0; i < cb.sove; i++) {
											if (cb.danhsachve[i][0] != '\0') {
												dem++;
											}
										}
										if (dem == cb.sove) {
											cb.trangthai = 3;
										}
										else {
											cb.trangthai = 2;
										}
									}
								}
							}

						}
					}
				}
			}
		}
	}
}
//int sovecon(chuyenbay cb) {
//	int tmp = 0;
//	for (int i = 0; i < cb.sove; i++) {
//		if (cb.danhsachve[i] != 0) {
//			tmp++;
//		}
//	}
//	return cb.sove - tmp;
//
//}
//void update_trang_thai(chuyenbay& cb) {
//	if (cb.trangthai == 1) {
//		return;
//	}
//	time_t thoigianhientai = time(nullptr);
//	tm time;
//	localtime_s(&time, &thoigianhientai);
//	if ((time.tm_year + 1900) > cb.tg.nam) {
//		cb.trangthai = 4;
//	}
//	else {
//		if ((time.tm_year + 1900) < cb.tg.nam) {
//			if (sovecon(cb) != 0) { cb.trangthai = 2; }
//			else { cb.trangthai = 3; };
//		}
//		else {
//			if ((time.tm_mon + 1) > cb.tg.thang) {
//				cb.trangthai = 4;
//			}
//			else {
//				if ((time.tm_mon + 1) < cb.tg.thang) {
//					if (sovecon(cb) != 0) { cb.trangthai = 2; }
//					else { cb.trangthai = 3; };
//				}
//				else {
//					if (time.tm_wday > cb.tg.ngay) {
//						cb.trangthai = 4;
//					}
//					else {
//						if (time.tm_wday < cb.tg.ngay) {
//							if (sovecon(cb) != 0) { cb.trangthai = 2; }
//							else { cb.trangthai = 3; };
//
//
//						}
//						else {
//							if ((time.tm_hour + 2) > cb.tg.gio) {
//								cb.trangthai = 4;
//							}
//							else {
//								if (sovecon(cb) != 0) { cb.trangthai = 2; }
//								else { cb.trangthai = 3; };
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//}
//ds tim_kiem(ds& a, char b[]) {
//	if (a == NULL) {
//		return NULL;
//	}
//	ds tmp = a;
//	while (tmp != NULL) {
//		if (strcmp(tmp->cb.macb, b) == 0) {
//			return tmp;
//		}
//		tmp = tmp->next;
//	}
//	return NULL;
//}
//void sua_thong_tin(ds& ds1, char b[],int c) {
// //1.thay doi ngay h ;2.san bay den ;3.so hieu may bay;.4.huy chuyen.
//	ds tmp;
//	tmp = ds1;
//	while (tmp != NULL) {
//		if (strcmp(tmp->cb.macb, b) == 0) {
//			if (c == 4) {
//				tmp->cb.trangthai = 1;
//			}
//			if (c == 1) {
//				int ngay, gio;
//				cout << "nhap ngay"; cin >> ngay;
//				cout << "nhap gio"; cin >> gio;
//				tmp->cb.tg.ngay = ngay;
//				tmp->cb.tg.gio = gio;
//			}
//			if (c == 2) {
//				char sanbaymoi[30];
//				cout << "nhap san bay moi"; cin >> sanbaymoi;
//				for (int i = 0; i < 30; i++) {
//					tmp->cb.sanbay[i] = sanbaymoi[i];
//				}
//			}
//			if (c == 3) {
//				char sohieumbmoi[30];
//				cout << "nhap sp hieuj may bay moi"; cin >> sohieumbmoi;
//				for (int i = 0; i < 30; i++) {
//					tmp->cb.sohieu[i] = sohieumbmoi[i];
//				}
//			}
//		}
//		tmp = tmp->next;
//	}
//}
void chuanhoachu(char a[]) {
	for (int i = 0; a[i] != NULL; i++) {
		if ((int)a[i] >= 97 && (int)a[i] <= 122) {
			a[i] = a[i] - 32;
		}
	}
}
void docdulieu(ds& dscb, int& dem) {
	chuyenbay a;
	ifstream file;
	file.open("Text.txt");
	string line;
	while (getline(file, line)) {
		stringstream ss(line);
		ss >> a.tg.gio >> a.tg.phut >> a.tg.ngay >> a.tg.thang >> a.tg.nam >> a.sove >> a.trangthai;

		// Ð?c d? li?u cho các trý?ng thông tin
		ss.ignore(); // B? qua d?u cách sau trý?ng tr?ng thái
		ss.getline(a.sanbay, sizeof(a.sanbay), ' '); // Ð?c vào m?ng kí t? a.sanbay
		ss.getline(a.macb, sizeof(a.macb), ' '); // Ð?c vào m?ng kí t? a.macb
		ss.getline(a.sohieu, sizeof(a.sohieu), ' '); // Ð?c vào m?ng kí t? a.sohieu
		chuanhoachu(a.sanbay);
		chuanhoachu(a.macb);
		chuanhoachu(a.sohieu);

		// Ð?c d? li?u cho danh sách vé
		a.danhsachve = new char* [a.sove];
		for (int i = 0; i < a.sove; i++) {
			a.danhsachve[i] = new char[30];
			a.danhsachve[i][0] = '\0';
		}
		int vitri = 0;
		char tmp[30];
		for (int i = 0; i < a.sove; i++) {
			tmp[0] = '\0';
			vitri = 0;
			ss.ignore();
			ss.getline(tmp, sizeof(tmp), ' ');
			ss >> vitri;
			if (tmp[0] == 'a') {
				a.danhsachve[vitri - 1][0] = '\0';

			}
			else {
				for (int j = 0; j < 12; j++) {
					a.danhsachve[vitri - 1][j] = tmp[j];
				}
				a.danhsachve[vitri - 1][12] = '\0';

			}
		}
		push(dscb, a);
		dem++;
	}
	file.close();
}
void lay_tg_hien_tai(int& ngay, int& thang, int& nam, int& gio, int& phut) {
	time_t thoigianhientai = time(nullptr);
	tm ltm;
	localtime_s(&ltm, &thoigianhientai);
	nam = (1900 + ltm.tm_year);
	thang = (1 + ltm.tm_mon);
	ngay = (ltm.tm_mday);
	gio = ltm.tm_hour;
	phut = ltm.tm_min;
}
void capnhatdulieu(ds& dscb) {
	ofstream outputFile("Text.txt");
	ds s = dscb;
	for (; s != NULL; s = s->next) {
		outputFile << s->cb.tg.gio << " " << s->cb.tg.phut << " " << s->cb.tg.ngay << " " << s->cb.tg.thang << " " << s->cb.tg.nam << " " << s->cb.sove << " " << s->cb.trangthai << " " << s->cb.sanbay << " " << s->cb.macb << " " << s->cb.sohieu << "  ";

		// Ghi d? li?u danh sách vé vào t?p tin
		for (int i = 0; i < s->cb.sove; i++) {
			if (s->cb.danhsachve[i][0] == '\0') {
				outputFile << 'a';
			}
			else {
				outputFile << s->cb.danhsachve[i];
			}
			outputFile << " " << i + 1 << " ";
		}
		outputFile << endl;
	}
	outputFile.close();
}
int sotrangcb = 1;
int sochuyenbayhien = 0, sochuyenbayco = 0;
float tmp;
int tranghientaicb = 1;
ds s;



