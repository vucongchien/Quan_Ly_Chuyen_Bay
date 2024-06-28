#pragma once
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include <iomanip>
#include<thread>
#include<chrono>

#include"maybay.h"
#include"CHUYENBAY.h"
#include"hanhkhach.h"
#include"lickchuot.h"

#include"hanhkhachUI.h"
#include"ticketUI.h"
#include"graphics.h"
#include"chuyenbayUI.h"
#include"maybayUI.h"
#include"doimau.h"



using namespace std;
#define maunen COLOR(208, 224, 227)
#define mauvien COLOR(140, 194, 243)
int mapid[1540][800] = { 0 };
void hienthidulieu(char a[][50], int b[], int c, int d) {

    for (int i = 0; i < d; i++) {
        outtextxy(b[i], c, a[i]);
        /*  cout << a[i] << endl;*/
    }
}
void xoavungchidinh(int x1, int y1, int x2, int y2) {
    setviewport(x1, y1, x2, y2, 1);
    clearviewport();
    setviewport(0, 0, getmaxx(), getmaxy(), 1);
}
void vede(int x, int y, int x1, int y1) {
    setfillstyle(SOLID_FILL, COLOR(217, 234, 211));
    bar(x, y, x1, y1);
}

void nhapdulieu(int x, int y, int xdau, int xcuoi, int yd, int yt, char a[], int sokitu, int dang) {
    setcolor(0);
    //(dang: 1 nh?p ch?a d?u cách ;2 là nh?p ko ch?a d?u cách;4 nhap ten voi chu dau viet hoa;) 3 nhap so;
    char tmptext[2];
    int xPos = x, yPos = y, x1 = x, x2 = x, xnhay, ynhay;
    int key;
    int i = 0;
    /*char daunhay[2]; daunhay[0] = '_'; daunhay[1] = '\0';*/

    setfillstyle(SOLID_FILL, COLOR(159, 197, 232));
    setbkcolor(COLOR(159, 197, 232));
    xoavungchidinh(xdau, yt, xcuoi, yd);
    do {
        if (i > sokitu) {
            char a[30] = "qua ki tu";
            hienthiloi(a);
            break;
        }
        key = getch();
        if (key == 8 && i > 0) {
            i--;
            a[i] = '\0';
            tmptext[0] = a[i - 1];
            tmptext[1] = '\0';
            xoavungchidinh(x2, yt, x1, yd);
            /*outtextxy(x2, yPos, daunhay);*/
            x1 = x2;
            x2 = x2 - textwidth(tmptext);
            outtextxy(xPos, yPos, a);

        }
        if (dang == 3) {
            if (key >= 48 && key <= 57 || key == 13 || key == 8) {
                if (key >= 48 && key <= 57) {
                    tmptext[0] = (char)key;
                    tmptext[1] = '\0';
                    a[i++] = tmptext[0];
                    a[i] = '\0';
                    x1 = x1 + textwidth(tmptext);
                    x2 = x1 - textwidth(tmptext);
                    outtextxy(xPos, yPos, a);
                }
            }
            else {
                char d[30] = "ki tu tu 0 den 9";
                hienthiloi(d);
                break;
            }

        }
        if ((key >= 32 && key <= 122 && (dang == 1 || dang == 2 || dang == 4 || dang == 5))) {
            if (key >= 33 && key <= 47 || key >= 58 && key <= 64 || key >= 91 && key <= 96) {
                continue;
            }
            else if (dang == 1) {
                if (key == 32) {
                    if (i == 0) {
                        continue;
                    }
                    else {
                        if (a[i - 1] == (char)32) {
                            i--;
                            a[i] = '\0';
                        }
                    }
                }
                else {
                    if (key >= 97 && key <= 122) {
                        tmptext[0] = (char)key - 32;
                        tmptext[1] = '\0';
                        a[i++] = tmptext[0];
                        a[i] = '\0';
                        outtextxy(xPos, yPos, a);
                        x1 = x1 + textwidth(tmptext);
                        x2 = x1 - textwidth(tmptext);

                    }
                    else {
                        tmptext[0] = (char)key;
                        tmptext[1] = '\0';
                        a[i++] = tmptext[0];
                        a[i] = '\0';
                        x1 = x1 + textwidth(tmptext);
                        x2 = x1 - textwidth(tmptext);
                        outtextxy(xPos, yPos, a);
                    }
                }
            }
            else if (dang == 2) {
                if (key == 32) {
                    continue;
                }
                else if (key >= 97 && key <= 122) {
                    tmptext[0] = (char)key - 32;
                    tmptext[1] = '\0';
                    a[i++] = tmptext[0];
                    a[i] = '\0';

                    outtextxy(xPos, yPos, a);
                    x1 = x1 + textwidth(tmptext);
                    x2 = x1 - textwidth(tmptext);

                }
                else {
                    tmptext[0] = (char)key;

                    tmptext[1] = '\0';
                    a[i++] = tmptext[0];
                    a[i] = '\0';
                    x1 = x1 + textwidth(tmptext);
                    x2 = x1 - textwidth(tmptext);
                    outtextxy(xPos, yPos, a);

                }
            }
            else if (dang == 4) {
                if (i == 0 || a[i - 1] == 32) {
                    if (key >= 97 && key <= 122) {
                        tmptext[0] = (char)key - 32;
                        tmptext[1] = '\0';
                        a[i++] = tmptext[0];
                        a[i] = '\0';

                        outtextxy(xPos, yPos, a);
                        x1 = x1 + textwidth(tmptext);
                        x2 = x1 - textwidth(tmptext);
                    }
                }
                else {
                    tmptext[0] = (char)key;

                    tmptext[1] = '\0';
                    a[i++] = tmptext[0];
                    a[i] = '\0';
                    x1 = x1 + textwidth(tmptext);
                    x2 = x1 - textwidth(tmptext);
                    outtextxy(xPos, yPos, a);
                }
            }
            else if (dang == 5) {
                if (key == 32) {
                    continue;
                }
                else if (i == 0) {
                    if (key >= 97 && key <= 122) {
                        tmptext[0] = (char)key - 32;
                        tmptext[1] = '\0';
                        a[i++] = tmptext[0];
                        a[i] = '\0';

                        outtextxy(xPos, yPos, a);
                        x1 = x1 + textwidth(tmptext);
                        x2 = x1 - textwidth(tmptext);
                    }
                }
                else {
                    tmptext[0] = (char)key;

                    tmptext[1] = '\0';
                    a[i++] = tmptext[0];
                    a[i] = '\0';
                    x1 = x1 + textwidth(tmptext);
                    x2 = x1 - textwidth(tmptext);
                    outtextxy(xPos, yPos, a);
                }
            }
        }
    } while (key != 13);
    xoavungchidinh(xdau, yt, xcuoi, yd);
    vede(xdau, yt, xcuoi, yd);
    setbkcolor(COLOR(217, 234, 211));
    outtextxy(x, y, a);
}
void setid(int x1, int y1, int x2, int y2, int id) {
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            mapid[i][j] = id;
        }
    }
}
void taoButton_new(int x1, int y1, int x2, int y2, char const* s, int id) {
    setfillstyle(SOLID_FILL, COLOR(248, 203, 244));
    bar(x1, y1, x2, y2);
    setcolor(COLOR(237, 142, 236));
    setlinestyle(0, 0, 3);
    rectangle(x1, y1, x2, y2);
    setcolor(0);
    setbkcolor(COLOR(248, 203, 244));
    outtextxy(x1 + 105 - textwidth(const_cast <char*>(s)) / 2, y1 + 35 - textheight(const_cast <char*>(s)) / 2, const_cast <char*>(s));
    setid(x1, y1, x2, y2, id);
}
void taoButton(int x1, int y1, int x2, int y2, char const* s) {
    setfillstyle(SOLID_FILL, COLOR(248, 203, 244));
    bar(x1, y1, x2, y2);
    setcolor(COLOR(237, 142, 236));
    setlinestyle(0, 0, 3);
    rectangle(x1, y1, x2, y2);

    setcolor(0);

    setbkcolor(COLOR(248, 203, 244));


    outtextxy(x1 + 75, y1 + 25, const_cast<char*>(s));
}
void taoLable(int x1, int y1, int x2, int y2, int mauVien, int mauText, int mauBG, char* text) {

    setcolor(mauVien);
    setfillstyle(1, mauBG);
    bar(x1, y1, x2, y2);
    rectangle(x1, y1, x2, y2);

    setcolor(mauText);
    setbkcolor(mauBG);
    outtextxy(x1 + (x2 - x1 - textwidth(text)) / 2, y1 + (y2 - y1 - textheight(text)) / 2, text);
}
void taoEditText(int x1, int y1, int x2, int y2, int mauVien, int mauBG, int id) {
    setcolor(mauVien);
    setfillstyle(1, mauBG);
    bar(x1, y1, x2, y2);
    rectangle(x1, y1, x2, y2);
    setid(x1, y1, x2, y2, id);

}
void vekhungcongcu() {
    //taoLable(920, 190, 1020, 230, 0, 0, 3,const_cast <char*>("ID"));
    //taoEditText(1025, 190, 1300, 230, 15, mauvien, 111);
    //taoLable(920, 235, 1020, 275, 0, 0, 3, const_cast <char*>( "TYPE"));
    //taoEditText(1025, 235, 1300, 275, 15, mauvien, 112);
    //taoLable(920, 280, 1020, 320, 0, 0, 3, const_cast <char*>("DAY"));
    //taoEditText(1025, 280, 1300, 320, 15, mauvien, 113);
    //taoLable(920, 325, 1020, 365, 0, 0, 3, const_cast <char*>("Dong"));
    //taoEditText(1025, 325, 1300, 365, 15, mauvien, 114);
    taoButton_new(920, 370, 1130, 440, "THEM", 11);
    setbkcolor(COLOR(208, 224, 227));
    setcolor(COLOR(255, 0, 77));
    outtextxy(70, 732, const_cast<char*>("-Click Chuot Trai De Xoa May Bay"));
    outtextxy(70, 757, const_cast<char*>("-Click Chuot Phai De Sua May Bay"));
}
void vekhungdsmb() {
    setbkcolor(maunen);
    setcolor(0);
    outtextxy(450, 120, const_cast <char*>("MAY BAY MANAGER"));
    setfillstyle(1, mauvien);
    bar(130, 145, 900, 190);
    setbkcolor(mauvien);
    setcolor(0);
    setlinestyle(0, 0, 3);
    line(130, 145, 900, 145);
    line(130, 190, 900, 190);
    line(130, 145, 130, 680);
    line(900, 145, 900, 680);
    line(130, 680, 900, 680);
    outtextxy(145, 170 - textheight(const_cast <char*>("STT")) / 2, const_cast <char*>("STT"));
    outtextxy(135 + 30 * 5, 170 - textheight(const_cast <char*>("ID")) / 2, const_cast <char*>("ID"));
    outtextxy(135 + 30 * 10, 170 - textheight(const_cast <char*>("TYPE")) / 2, const_cast <char*>("TYPE"));
    outtextxy(135 + 30 * 15, 170 - textheight(const_cast <char*>("DONG")) / 2, const_cast <char*>("DONG"));
    outtextxy(135 + 30 * 20, 170 - textheight(const_cast <char*>("DAY")) / 2, const_cast <char*>("DAY"));


}
void taodong(int stt) {
    setbkcolor(3);
    setfillstyle(1, 3);
    bar(130, 180 + 48 * stt - 40, 900, 180 + 48 * stt + 5);
    line(130, 190, 900, 190);
    line(130, 180 + 48 * stt + 5, 900, 180 + 48 * stt + 5);
    line(130, 145, 130, 680);
    line(900, 145, 900, 680);
    setcolor(0);
    //	string s =to_string(stt) ; 
    outtextxy(135, 180 + 48 * stt - 20, const_cast <char*>("stt"));
    outtextxy(135 + 30 * 5, 180 + 48 * stt - 20, const_cast <char*>("VIETNAMAIRLINE"));
    outtextxy(135 + 30 * 10, 180 + 48 * stt - 20, const_cast <char*>("HO"));
    outtextxy(135 + 30 * 15, 180 + 48 * stt - 20, const_cast <char*>("OK"));
    outtextxy(135 + 30 * 20, 180 + 48 * stt - 20, const_cast <char*>("OK"));
}
void input(char* s, int max, int px, int py, int id) {
    setbkcolor(COLOR(248, 203, 244));
    setcolor(0);
    int mx = -1, my = -1;
    unsigned int l = strlen(s);
    s[l] = '|';
    while (1) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, mx, my);
            clearmouseclick(WM_LBUTTONDOWN);
        }
        delay(1);
        if (kbhit()) {
            char c = getch();
            if (l < max) {
                if (l == 0 || s[l - 1] == ' ') {
                    if (c >= 'a' && c <= 'z') {
                        c = c + 'A' - 'a';
                    }
                    else {
                        c = c;
                    }
                }
                else if (c >= 'A' && c <= 'Z') {
                    c = c - 'A' + 'a';
                }
                if (c >= 'a' && c <= 'z') {
                    s[l] = c;
                    l++;
                }
                if (c >= 'A' && c <= 'Z') {
                    s[l] = c;
                    l++;
                }
                if (c >= '0' && c <= '9') {
                    s[l] = c;
                    l++;
                }
                if (l > 0) {
                    if (s[l - 1] != ' ' && c == ' ') {
                        s[l] = c;
                        l++;
                    }
                    outtextxy(px, py, s);
                }
                if (c == 13) {
                    s[l] = ' ';
                    outtextxy(px, py, s);
                    s[l] = '\0';
                    break;
                }
                if (c == 8 && l > 0) {
                    s[l] = ' ';
                    outtextxy(px, py, s);
                    s[l - 1] = ' ';
                    l--;
                }
                s[l] = '|';
                outtextxy(px, py, s);
            }
        }
    }
}
//ham nay de lay toa do diem cho nhanh ok ----------
void Lay_chi_so() {
    int x, y;
    while (true) {

        if (ismouseclick(WM_LBUTTONDOWN)) {

            getmouseclick(WM_LBUTTONDOWN, x, y);
            cout << "Nhan chuot tai toa do: (" << x << ", " << y << ")" << endl;
        }
        if (ismouseclick(WM_RBUTTONDOWN)) {
            cout << "aduu" << endl;
        }
        clearmouseclick(WM_RBUTTONDOWN);
        delay(50);
    }
}
//__________________________________________man hinh ________________________________________________
//plane
void hien_o_giua(int x, int y, char* a) {
    setcolor(0);
    setbkcolor(COLOR(208, 224, 227));
    x -= textwidth(const_cast<char*>(a)) / 2;
    outtextxy(x, y, const_cast<char*>(a));
}
void mergeArrays(char arr1[], int size1, char arr2[], int size2, char mergedArr[]) {
    for (int i = 0; i < size1; ++i) {
        mergedArr[i] = arr1[i];
    }
    for (int i = 0; i < size2; ++i) {
        mergedArr[size1 + i] = arr2[i];
    }
    mergedArr[size1 + size2] = '\0';
}
void hienchinhgiua(int x, int y, int x1, int y1, char a[]) {
    int dodai, xtmp, ytmp;
    dodai = textwidth(a);
    ytmp = y + ((y1 - y) / 2);
    xtmp = x + ((x1 - (x + dodai)) / 2);
    setbkcolor(COLOR(208, 224, 227));
    outtextxy(xtmp, ytmp, a);
}
bool TRC_30p(chuyenbay cb) {
    time_t thoigianhientai = time(nullptr);
    tm ltm;
    localtime_s(&ltm, &thoigianhientai);
    int namcurr, thangcurr, ngaycurr, giocurr, phutcurr;
    namcurr = 1900 + ltm.tm_year;
    thangcurr = 1 + ltm.tm_mon;
    ngaycurr = ltm.tm_mday;
    giocurr = ltm.tm_hour;
    phutcurr = ltm.tm_min;

    if (cb.tg.nam > namcurr) {
        return 1;
    }
    else if (cb.tg.thang > thangcurr) {
        return 1;
    }
    else if (cb.tg.ngay > ngaycurr) {
        return 1;
    }
    else if (cb.tg.gio > giocurr) {
        return 1;
    }
    else if (cb.tg.phut > phutcurr - 30) {
        return 1;
    }
    return 0;
}
void ve_hinh_vuong(int xright, int ytop, int xleft, int ybot, int colorbar, int colorrectangle, char text[], int mode = 0, int colortext = 0) {
    setfillstyle(SOLID_FILL, colorbar);
    bar(xright, ytop, xleft, ybot);
    setlinestyle(0, 0, 1);
    setcolor(colorrectangle);
    rectangle(xright, ytop, xleft, ybot);
    setbkcolor(colorbar);
    setcolor(colortext);
    if (mode == 1) {
        outtextxy((xright + xleft) / 2 - (textwidth(const_cast<char*>(text)) / 2), (ytop + ybot) / 2 - 10, const_cast<char*>(text));
        return;
    }
    outtextxy(xright + 5, (ytop + ybot) / 2 - 10, const_cast<char*>(text));
}
void Screen_Default(int TRANGTHAITAB = 0) {
    setfillstyle(SOLID_FILL, 15);
    bar(0, 0, 1540, 800);
    ve_hinh_vuong(40, 10, 250, 80, COLOR(255, 229, 229), 0, const_cast<char*>("PLANES"), 1, 0);
    ve_hinh_vuong(280, 10, 490, 80, COLOR(255, 229, 229), 0, const_cast<char*>("FLIGHTS"), 1, 0);
    ve_hinh_vuong(520, 10, 730, 80, COLOR(255, 229, 229), 0, const_cast<char*>("CUSTOMER"), 1, 0);
    ve_hinh_vuong(760, 10, 970, 80, COLOR(255, 229, 229), 0, const_cast<char*>("TIKCET"), 1, 0);
    ve_hinh_vuong(1000, 10, 1210, 80, COLOR(255, 229, 229), 0, const_cast<char*>("STATISIC"), 1, 0);
    if (TRANGTHAITAB == 1) {
        ve_hinh_vuong(40, 10, 250, 80, COLOR(255, 191, 191), 0, const_cast<char*>("PLANES"), 1, 0);
    }
    else if (TRANGTHAITAB == 2) {
        ve_hinh_vuong(280, 10, 490, 80, COLOR(255, 191, 191), 0, const_cast<char*>("FLIGHTS"), 1, 0);
    }
    else if (TRANGTHAITAB == 3) {
        ve_hinh_vuong(520, 10, 730, 80, COLOR(255, 191, 191), 0, const_cast<char*>("CUSTOMER"), 1, 0);
    }
    else if (TRANGTHAITAB == 4) {
        ve_hinh_vuong(760, 10, 970, 80, COLOR(255, 191, 191), 0, const_cast<char*>("TIKCET"), 1, 0);
    }
    else if (TRANGTHAITAB == 5) {
        ve_hinh_vuong(1000, 10, 1210, 80, COLOR(255, 191, 191), 0, const_cast<char*>("STATISIC"), 1, 0);
    }
    //setcolor(0);
    setfillstyle(SOLID_FILL, COLOR(208, 224, 227));
    bar(40, 100, 1500, 780);
    setlinestyle(0, 0, 3);
    setcolor(COLOR(140, 194, 243));
    rectangle(40, 100, 1500, 780);

}
void are_you_sure(string m) {
    ve_hinh_vuong(480, 250, 1000, 520, COLOR(218, 221, 177), COLOR(179, 164, 146), const_cast<char*>(m.c_str()), 1, 0);
    ve_hinh_vuong(510, 440, 590, 480, COLOR(217, 234, 211), 0, const_cast<char*>("YES"), 1, 0);
    ve_hinh_vuong(850, 440, 920, 480, COLOR(217, 234, 211), 0, const_cast<char*>("NO"), 1, 0);
}
