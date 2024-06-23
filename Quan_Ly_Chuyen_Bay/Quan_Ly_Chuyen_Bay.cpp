#pragma once
#include "graphics.h"
#include<stdio.h>
#include<iostream>
#include<fstream>
#include"hanhkhach.h"
#include"maybay.h"
#include"CHUYENBAY.h"
#include<string>
#include<sstream>
#include"lickchuot.h"
#include <iomanip>
#include"hanhkhachUI.h"
#include"ticketUI.h"
using namespace std;
#pragma comment(lib, "graphics.lib")
//_________________________________ham tao lao bi dao_______________________________________________


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
void hienthiloi(char a[]) {

    std::wstring message = std::wstring(a, a + strlen(a));


    LPCWSTR messagePtr = message.c_str();


    MessageBox(NULL, messagePtr, L"loi", MB_OK);
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
void Planes_design() {
    vekhungcongcu();
    vekhungdsmb();
    setfillstyle(SOLID_FILL, COLOR(217, 234, 211));
    setbkcolor(COLOR(217, 234, 211));
    bar(410, 700, 460, 735);
    bar(540, 700, 590, 735);
    hien_o_giua(430, 710, const_cast<char*> ("<"));
    hien_o_giua(570, 710, const_cast<char*> (">"));
}

void hienthemmaybay() {
    cleardevice();
    Screen_Default(1);
    setfillstyle(SOLID_FILL, COLOR(159, 197, 232));
    setfillstyle(SOLID_FILL, COLOR(217, 234, 211));
    bar(55, 135, 125, 175);
    setbkcolor(COLOR(217, 234, 211));
    setcolor(0);
    char b[5] = "BACK";
    outtextxy(70, 145, b);
    setbkcolor(COLOR(208, 224, 227));
    char b1[30] = "ADD PLANE";
    outtextxy(644, 182, b1);
    char b2[30] = "ID PLANE: "; char b3[30] = "TYPE PLANES: ";
    outtextxy(354, 235, b2);
    bar(374 + 65, 220, 374 + 70 + 600, 265);
    outtextxy(324, 335, b3);
    bar(374 + 65, 320, 374 + 70 + 600, 365);
    char b4[30] = "DAY: ";
    outtextxy(380, 435, b4);
    bar(374 + 65, 420, 374 + 70 + 600, 465);
    char b5[30] = "DONG: ";
    outtextxy(374, 535, b5);
    bar(374 + 65, 520, 374 + 70 + 600, 565);
    setfillstyle(SOLID_FILL, COLOR(159, 197, 232));
    setbkcolor(COLOR(159, 197, 232));
    bar(1323, 660, 1416, 710);
    char b10[30] = "SAVE";
    outtextxy(1349, 677, b10);

}
bool check_mb(int stt, listmb dsmb, ds dscb) {
    while (dscb != NULL) {
        if (strcmp(dsmb.nodes[stt]->sohieu, dscb->cb.sohieu) == 0) {
            return 0;
        }
        dscb = dscb->next;
    }
    return 1;
}
void hien_ds_mb(int trangcurr, listmb ds_mb, ds dscb) {
    setfillstyle(SOLID_FILL, COLOR(208, 224, 227));
    bar(132, 193, 899, 679);
    if (Emptyds(ds_mb)) {
        return;
    }
    int sl_mb = 0;
    int trang_max = ds_mb.n / 10;
    if (trang_max == trangcurr) {
        sl_mb = ds_mb.n;
    }
    else {
        sl_mb = 10;
    }
    setbkcolor(COLOR(208, 224, 227));
    int x1 = 130, x2 = 900, y1 = 190 + 49, y2 = 680;
    setcolor(0);
    for (int i = trangcurr * 10; i < sl_mb; ++i) {
        line(x1, y1, x2, y1);
        y1 += 49;
        if (i == 9)
            break;
    }
    x1 = 160, y1 = 205;
    for (int i = trangcurr * 10; i < sl_mb; ++i) {
        string m = to_string(i);
        hien_o_giua(x1, y1, const_cast<char*>(m.c_str()));
        x1 += 130;
        hien_o_giua(x1, y1, const_cast<char*>(ds_mb.nodes[i]->sohieu));
        x1 += 160;
        hien_o_giua(x1, y1, const_cast<char*>(ds_mb.nodes[i]->loai));
        x1 += 150;
        m = to_string(ds_mb.nodes[i]->sodong);
        hien_o_giua(x1, y1, const_cast<char*>(m.c_str()));
        x1 += 150;
        m = to_string(ds_mb.nodes[i]->soday);
        hien_o_giua(x1, y1, const_cast<char*>(m.c_str()));

        if (check_mb(i, ds_mb, dscb) == 0) {
            ve_hinh_vuong(833, y1 - 3, 898, y1 + 22, COLOR(250, 112, 112), COLOR(250, 112, 112), const_cast<char*>("ko the xoa"), 1, 0);
        }
        x1 = 160;
        y1 += 49;
        if (i == 9)
            break;
    }

}
void xoa_mb_theo_stt(int stt, listmb& dsmb, int trangcurr, ds dscb) {
    if (stt > dsmb.n)
        return;

    if (check_mb(stt, dsmb, dscb) == 0)
        return;
    string m(dsmb.nodes[stt]->sohieu);
    string n = "ban co chac muon xoa mb ";
    n += m;
    n += "khong";
    are_you_sure(n);
    while (1) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int xx, yy;
            getmouseclick(WM_LBUTTONDOWN, xx, yy);
            if (isMouse_Yes_huy_ve(xx, yy)) {
                deletemb(dsmb, stt);
                savefile(dsmb);
                break;
            }
            else if (isMouse_No_huy_ve(xx, yy)) {
                break;
            }
        }
    }
    cleardevice();
    Screen_Default(1);
    Planes_design();
    hien_ds_mb(trangcurr, dsmb, dscb);

}
void man_hinh_sua_tt_mb(int stt, listmb& dsmb) {

    cleardevice();
    Screen_Default(1);
    setfillstyle(SOLID_FILL, COLOR(159, 197, 232));
    setfillstyle(SOLID_FILL, COLOR(217, 234, 211));
    bar(55, 135, 125, 175);
    setbkcolor(COLOR(217, 234, 211));
    setcolor(0);
    char b[5] = "BACK";
    outtextxy(70, 145, b);
    setbkcolor(COLOR(208, 224, 227));
    char b1[30] = "";
    outtextxy(644, 182, const_cast<char*>(dsmb.nodes[stt]->sohieu));
    char b2[30] = "ID PLANE: "; char b3[30] = "TYPE PLANES: ";
    //outtextxy(354, 235, b2);
    //bar(374 + 65, 220, 374 + 70 + 600, 265);
    outtextxy(324, 335, b3);
    ve_hinh_vuong(374 + 65, 320, 374 + 70 + 600, 365, COLOR(217, 234, 211), 0, const_cast<char*>(dsmb.nodes[stt]->loai), 0, 0);
    setbkcolor(COLOR(208, 224, 227));
    char b4[30] = "DAY: ";
    outtextxy(380, 435, b4);
    string m = to_string(dsmb.nodes[stt]->soday);
    ve_hinh_vuong(374 + 65, 420, 374 + 70 + 600, 465, COLOR(217, 234, 211), 0, const_cast<char*>(m.c_str()), 0, 0);
    setbkcolor(COLOR(208, 224, 227));
    char b5[30] = "DONG: ";
    outtextxy(374, 535, b5);
    m = to_string(dsmb.nodes[stt]->sodong);
    ve_hinh_vuong(374 + 65, 520, 374 + 70 + 600, 565, COLOR(217, 234, 211), 0, const_cast<char*>(m.c_str()), 0, 0);
    setbkcolor(COLOR(208, 224, 227));
    setfillstyle(SOLID_FILL, COLOR(159, 197, 232));
    setbkcolor(COLOR(159, 197, 232));
    bar(1323, 660, 1416, 710);
    char b10[30] = "SAVE";
    outtextxy(1349, 677, b10);
}
void sua_thong_tin_mb(int stt, listmb& dsmb, int& trangcurr, ds dscb) {
    if (stt > dsmb.n)
        return;
    man_hinh_sua_tt_mb(stt, dsmb);
    char dl_mb[4][30];
    STRCPYY(dl_mb[1], dsmb.nodes[stt]->loai);
    chuyenintschar(dl_mb[2], dsmb.nodes[stt]->soday);
    chuyenintschar(dl_mb[3], dsmb.nodes[stt]->sodong);
    //cout << dl_mb[1] << " " << dl_mb[2]<<" " << dl_mb[3] << endl;
    while (1) {

        if (ismouseclick(WM_LBUTTONDOWN)) {
            int xx, yy;
            getmouseclick(WM_LBUTTONDOWN, xx, yy);
            char dl1[30], dl2[30], dl3[30], dl4[30];
            dl1[0] = '\0'; dl2[0] = '\0'; dl3[0] = '\0'; dl4[0] = '\0';
            if (isMouseback(xx, yy)) {
                cleardevice();
                Screen_Default(1);
                Planes_design();
                trangcurr = 0;
                hien_ds_mb(trangcurr, dsmb, dscb);
                return;
            }
            else if (isMouseaddmamaybay(xx, yy) == 1) {
                nhapdulieu(445, 335, 440, 1046, 320, 363, dl2, 30, 2);
                STRCPYY(dl_mb[1], dl2);
            }
            else if (isMouseaddnoiden(xx, yy) == 1) {
                nhapdulieu(445, 435, 440, 1043, 421, 464, dl3, 30, 3);
                int a = atoi(dl_mb[2]);
                int b = atoi(dl3);
                if (a <= b)
                {
                    STRCPYY(dl_mb[2], dl3);
                }
                else {
                    hienthiloi(const_cast<char*>("khong the giam so ghe"));

                    string m = to_string(dsmb.nodes[stt]->soday);
                    ve_hinh_vuong(374 + 65, 420, 374 + 70 + 600, 465, COLOR(217, 234, 211), 0, const_cast<char*>(m.c_str()), 0, 0);
                }
            }
            else if (isMouseNhapDONG_them_mb(xx, yy)) {
                nhapdulieu(445, 529, 440, 1043, 521, 564, dl4, 30, 3);
                int a = atoi(dl_mb[3]);
                int b = atoi(dl4);
                if (a <= b)
                {
                    STRCPYY(dl_mb[3], dl4);
                }
                else {
                    hienthiloi(const_cast<char*>("khong the giam so ghe"));
                    string m = to_string(dsmb.nodes[stt]->sodong);
                    ve_hinh_vuong(374 + 65, 520, 374 + 70 + 600, 565, COLOR(217, 234, 211), 0, const_cast<char*>(m.c_str()), 0, 0);
                }

            }
            else if (isMousesave(xx, yy) == 1) {
                maybay tmp;
                STRCPYY(tmp.sohieu, dsmb.nodes[stt]->sohieu);
                STRCPYY(tmp.loai, dl_mb[1]);
                tmp.soday = stoi(dl_mb[2]);
                tmp.sodong = stoi(dl_mb[3]);
                chinhsua(dsmb, stt, tmp);
                hienthiloi(const_cast<char*>("luu thanh cong"));
                savefile(dsmb);                ds duyet = NULL; duyet = dscb;
                for (; duyet != NULL; duyet = duyet->next) {
                    chuyenbay tmp;
                    cout << strcmp(duyet->cb.sohieu, dsmb.nodes[stt]->sohieu) << endl;
                    if (strcmp(duyet->cb.sohieu, dsmb.nodes[stt]->sohieu) == 0) {
                        int ghemoi = dsmb.nodes[stt]->sodong * dsmb.nodes[stt]->soday;
                        char** new_danhsachve = new char* [ghemoi];
                        for (int i = 0; i < ghemoi; ++i) {
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
                        duyet->cb.sove = ghemoi;
                        tmp = duyet->cb;
                        sua_thong_tin_cb(s, tmp);
                        capnhatdulieu(s);
                    }
                }
            
                cleardevice();
                Screen_Default(1);
                Planes_design();
                trangcurr = 0;
                hien_ds_mb(trangcurr, dsmb, dscb);
                return;
            }
        }
    }
}

//flight-----------------------------------------------------------------


//void chuyencharstring(char a[], string b[]);
void hienthemchuyebay() {
    Screen_Default(2);
    setfillstyle(SOLID_FILL, COLOR(159, 197, 232));
    setfillstyle(SOLID_FILL, COLOR(217, 234, 211));
    bar(55, 135, 125, 175);
    setbkcolor(COLOR(217, 234, 211));
    setcolor(0);
    char b[5] = "BACK";
    outtextxy(70, 145, b);
    setbkcolor(COLOR(208, 224, 227));
    char b1[30] = "ADD FLIGHT";
    outtextxy(644, 182, b1);
    char b2[30] = "ID Flight: "; char b3[30] = "ID Planes: ";
    outtextxy(374, 235, b2);
    bar(374 + textwidth(b3), 220, 374 + textwidth(b3) + 600, 265);
    //hien th? planes
    outtextxy(374, 335, b3);
    bar(374 + textwidth(b3), 320, 374 + textwidth(b3) + 600, 365);
    char b4[30] = "ARIVE: ";
    outtextxy(374, 435, b4);
    bar(374 + textwidth(b3), 420, 374 + textwidth(b3) + 600, 465);
    char b5[30] = "TIME: ";
    outtextxy(374, 535, b5);
    bar(374 + textwidth(b3), 520, 374 + textwidth(b3) + 70, 565);
    char b6[30] = " / ";
    int x = 374 + textwidth(b3) + 70;
    outtextxy(x, 535, b6);
    bar(x + textwidth(b6), 520, x + textwidth(b6) + 70, 565); x = x + textwidth(b6) + 70;
    outtextxy(x, 535, b6);
    bar(x + textwidth(b6), 520, x + textwidth(b6) + 70, 565); x = x + textwidth(b6) + 70;
    char b7[30] = " AT ";
    outtextxy(x, 535, b7);
    bar(x + textwidth(b7), 520, x + textwidth(b7) + 70, 565); x = x + textwidth(b7) + 70;
    char b8[30] = " : ";
    outtextxy(x, 535, b8);
    bar(x + textwidth(b8), 520, x + textwidth(b8) + 70, 565);
    setfillstyle(SOLID_FILL, COLOR(159, 197, 232));
    setbkcolor(COLOR(159, 197, 232));
    bar(1070, 320, 1140, 360);
    char b9[30] = "FIND";
    outtextxy(1081, 335, b9);
    bar(1323, 660, 1416, 710);
    char b10[30] = "SAVE";
    outtextxy(1349, 677, b10);
}

//hien thi danh sach ve cua 1 chuyen bay 
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
void hienthidanhsachve(chuyenbay a, char** dsvtmp, int trangthai, int& phantuhien, int sophanthuco, int* vitrighe) {
    cleardevice();
    Screen_Default();
    int y = 289;
    setfillstyle(SOLID_FILL, COLOR(159, 197, 232));
    setfillstyle(SOLID_FILL, COLOR(217, 234, 211));
    bar(55, 135, 125, 175);
    setbkcolor(COLOR(217, 234, 211));
    setcolor(0);
    setlinestyle(0, 0, 2);
    rectangle(100, 220, 1440, 689);
    char b[5] = "BACK";
    outtextxy(70, 145, b);
    setbkcolor(COLOR(208, 224, 227));
    char tmp[1000] = "DANH SACH HANH KHACH THUOC CHUYEN BAY:  ";
    char chinh[500];
    mergeArrays(tmp, strlen(tmp), a.macb, strlen(a.macb), chinh);
    //thoi gian den
    char tmpcc[7][30];
    for (int i = 0; i < 7; i++) {
        tmpcc[i][0] = '\0';
    }
    chuyenintschar(tmpcc[1], a.tg.phut);
    chuyenintschar(tmpcc[2], a.tg.gio);
    chuyenintschar(tmpcc[3], a.tg.ngay);
    chuyenintschar(tmpcc[4], a.tg.thang);
    chuyenintschar(tmpcc[5], a.tg.nam);
    char tg[50]; tg[0] = '\0';
    ostringstream oss;
    oss << setw(2) << setfill('0') << tmpcc[2] << ":" << setw(2) << setfill('0') << tmpcc[1] << " - "
        << setw(2) << setfill('0') << tmpcc[3] << "/" << setw(2) << setfill('0') << tmpcc[4] << "/" << tmpcc[5];
    string tgtmp = oss.str();
    chuyenstringschar(tg, tgtmp);
    char thu[50] = "Ngay gio khoi hanh: ";
    char thu1[50] = "  Noi den: ";
    char chinh2p[100], chinh2pp[500], chinh2[500];
    mergeArrays(thu, strlen(thu), tg, strlen(tg), chinh2p);
    mergeArrays(chinh2p, strlen(chinh2p), thu1, strlen(thu1), chinh2pp);
    mergeArrays(chinh2pp, strlen(chinh2pp), a.sohieu, strlen(a.sohieu), chinh2);
    hienchinhgiua(42, 160, 1500, 190, chinh2);
    hienchinhgiua(42, 130, 1500, 160, chinh);
    /*if(trangthai==1){
     setfillstyle(SOLID_FILL, COLOR(159, 197, 232));
     bar(99, 220, 1440, 688);
     setfillstyle(SOLID_FILL, COLOR(208, 224, 227));
     bar(99, 289, 1440, 688);
     setlinestyle(0, 0, 2);
     setbkcolor(COLOR(159, 197, 232));
     line(190, 220, 190, 698); char a0[10] = "NUMBERS"; outtextxy(110, 240, a0);
     line(326, 220, 326, 689); char a1[20] = "SO GHE"; outtextxy(230, 240, a1);
     setlinestyle(0, 0, 2);
     line(570, 220, 570, 689); char a2[30] = "HO"; outtextxy(455, 240, a2);
     line(710, 220, 710, 689); char a3[30] = "TEN"; outtextxy(620, 240, a3);
     line(1056, 220, 1056, 689); char a4[20] = "SO CCCD"; outtextxy(843, 240, a4);
     line(1232, 220, 1232, 689); char a5[20] = "PHAI";   outtextxy(1105, 240, a5);
     char a6[20] = "DANH SACH VE"; outtextxy(1295, 240, a6);
     line(99, 220, 99, 689);
     line(1440, 220, 1440, 689);
     setfillstyle(SOLID_FILL, COLOR(159, 197, 232));
     bar(688, 719, 748, 765);
     bar(820, 719, 880, 765);
     line(727, 726, 698, 742);
     line(698, 742, 727, 760);
     line(836, 726, 866, 742);
     line(866, 742, 836, 760);
     int dem = 0; int vitri=65;
     for (int i = 0; i < 10; i++) {
             phantuhien++;
             dem++; int sodong, soday;
             soday = ds_mb.nodes[timkiem(ds_mb, a.sohieu)]->soday;
             sodong = ds_mb.nodes[timkiem(ds_mb, a.sohieu)]->sodong;
             chuyenintschar(tmpcc[0], dem);
             hienchinhgiua(100, y, 190, y + 40, tmpcc[0]);
             while (vitrighe[i] > sodong) { vitrighe[i] -= sodong;  vitri++; }
             string m;
             m += static_cast<char>(vitri);
             m += to_string(vitrighe[i]);
             hienchinhgiua(190, y, 326, y + 40, const_cast<char*>(m.c_str()));
             HanhKhach tmp;
             tmp = ds_hk.search(dsvtmp[i]);
             char ho1[50]; ho1[0] = '\0';
             chuyenstringschar(ho1, tmp.ho);
             hienchinhgiua(326, y, 570, y + 40, ho1);
             ho1[0] = '\0';
             chuyenstringschar(ho1, tmp.ten);
             hienchinhgiua(570, y, 710, y + 40, ho1);
             hienchinhgiua(710, y, 1055, y + 40, tmp.soCMND);
             ho1[0] = '\0';
             chuyenstringschar(ho1, tmp.phai);
             hienchinhgiua(1056, y, 1232, y + 40, ho1);
             y = y + 40;
             line(100, y, 1440, y);

     }
    }else*/ if (trangthai == 2) {
        setfillstyle(SOLID_FILL, COLOR(159, 197, 232));
        bar(99, 220, 1440, 688);
        setfillstyle(SOLID_FILL, COLOR(208, 224, 227));
        bar(99, 289, 1440, 688);
        setlinestyle(0, 0, 2);
        setbkcolor(COLOR(159, 197, 232));
        line(190, 220, 190, 698); char a0[10] = "NUMBERS"; outtextxy(110, 240, a0);
        line(326, 220, 326, 689); char a1[20] = "SO GHE"; outtextxy(230, 240, a1);
        setlinestyle(0, 0, 2);
        line(570, 220, 570, 689); char a2[30] = "HO"; outtextxy(455, 240, a2);
        line(710, 220, 710, 689); char a3[30] = "TEN"; outtextxy(620, 240, a3);
        line(1056, 220, 1056, 689); char a4[20] = "SO CCCD"; outtextxy(843, 240, a4);
        line(1232, 220, 1232, 689); char a5[20] = "PHAI";   outtextxy(1105, 240, a5);
        char a6[20] = "DANH SACH VE"; outtextxy(1295, 240, a6);
        line(99, 220, 99, 689);
        line(1440, 220, 1440, 689);
        setfillstyle(SOLID_FILL, COLOR(159, 197, 232));
        bar(688, 719, 748, 765);
        bar(820, 719, 880, 765);
        line(727, 726, 698, 742);
        line(698, 742, 727, 760);
        line(836, 726, 866, 742);
        line(866, 742, 836, 760);
        int dem = phantuhien;
        /*cout << dem << "cocaidaubui" << endl;*/
        for (int i = dem; i < dem + 10; i++) {
            phantuhien++;
            int sodong, soday;
            soday = ds_mb.nodes[timkiem(ds_mb, a.sohieu)]->soday;
            sodong = ds_mb.nodes[timkiem(ds_mb, a.sohieu)]->sodong;
            chuyenintschar(tmpcc[0], phantuhien);
            hienchinhgiua(100, y, 190, y + 40, tmpcc[0]);
            int vitri = 65;
            while (vitrighe[i] > sodong) { vitrighe[i] -= sodong;  vitri++; }
            string m;
            m += static_cast<char>(vitri);
            m += to_string(vitrighe[i]);
            hienchinhgiua(190, y, 326, y + 40, const_cast<char*>(m.c_str()));
            HanhKhach tmp;
            tmp = ds_hk.search(dsvtmp[i]);
            char ho1[50]; ho1[0] = '\0';
            chuyenstringschar(ho1, tmp.ho);
            hienchinhgiua(326, y, 570, y + 40, ho1);
            ho1[0] = '\0';
            chuyenstringschar(ho1, tmp.ten);
            hienchinhgiua(570, y, 710, y + 40, ho1);
            hienchinhgiua(710, y, 1055, y + 40, tmp.soCMND);
            ho1[0] = '\0';
            chuyenstringschar(ho1, tmp.phai);
            hienchinhgiua(1056, y, 1232, y + 40, ho1);
            y = y + 40;
            line(100, y, 1440, y);
        }
    }
    else if (trangthai == 3) {
        setfillstyle(SOLID_FILL, COLOR(159, 197, 232));
        bar(99, 220, 1440, 688);
        setfillstyle(SOLID_FILL, COLOR(208, 224, 227));
        bar(99, 289, 1440, 688);
        setlinestyle(0, 0, 2);
        setbkcolor(COLOR(159, 197, 232));
        line(190, 220, 190, 698); char a0[10] = "NUMBERS"; outtextxy(110, 240, a0);
        line(326, 220, 326, 689); char a1[20] = "SO GHE"; outtextxy(230, 240, a1);
        setlinestyle(0, 0, 2);
        line(570, 220, 570, 689); char a2[30] = "HO"; outtextxy(455, 240, a2);
        line(710, 220, 710, 689); char a3[30] = "TEN"; outtextxy(620, 240, a3);
        line(1056, 220, 1056, 689); char a4[20] = "SO CCCD"; outtextxy(843, 240, a4);
        line(1232, 220, 1232, 689); char a5[20] = "PHAI";   outtextxy(1105, 240, a5);
        char a6[20] = "DANH SACH VE"; outtextxy(1295, 240, a6);
        line(99, 220, 99, 689);
        line(1440, 220, 1440, 689);
        setfillstyle(SOLID_FILL, COLOR(159, 197, 232));
        bar(688, 719, 748, 765);
        bar(820, 719, 880, 765);
        line(727, 726, 698, 742);
        line(698, 742, 727, 760);
        line(836, 726, 866, 742);
        line(866, 742, 836, 760);
        int dem = phantuhien;
        for (int i = dem; i < sophanthuco; i++) {
            phantuhien++;
            int sodong, soday;
            soday = ds_mb.nodes[timkiem(ds_mb, a.sohieu)]->soday;
            sodong = ds_mb.nodes[timkiem(ds_mb, a.sohieu)]->sodong;
            chuyenintschar(tmpcc[0], phantuhien);
            hienchinhgiua(100, y, 190, y + 40, tmpcc[0]);
            int vitri = 65;
            while (vitrighe[i] > sodong) { vitrighe[i] -= sodong;  vitri++; }
            string m;
            m += static_cast<char>(vitri);
            m += to_string(vitrighe[i]);
            hienchinhgiua(190, y, 326, y + 40, const_cast<char*>(m.c_str()));
            HanhKhach tmp;
            tmp = ds_hk.search(dsvtmp[i]);
            char ho1[50]; ho1[0] = '\0';
            chuyenstringschar(ho1, tmp.ho);
            hienchinhgiua(326, y, 570, y + 40, ho1);
            ho1[0] = '\0';
            chuyenstringschar(ho1, tmp.ten);
            hienchinhgiua(570, y, 710, y + 40, ho1);
            hienchinhgiua(710, y, 1055, y + 40, tmp.soCMND);
            ho1[0] = '\0';
            chuyenstringschar(ho1, tmp.phai);
            hienchinhgiua(1056, y, 1232, y + 40, ho1);
            y = y + 40;
            line(100, y, 1440, y);
        }
    }
}




//mang hinh hien th? loi

void hienthidschuyenbay(ds& s, int& dem, int trangthai) {
    //1 hien tu dau den vi tri nho hon 10
    //2 hien 10 phan tu
    //3 hien cacphantu cuoi cung
    int y = 289; int tmpdem = dem;
    char tmp[6][30];
    for (int i = 0; i < 6; i++) {
        tmp[i][0] = '\0';
    }
    ds dscb = s;
    if (trangthai == 1) {
        xoavungchidinh(99, 289, 1440, 688);
        setfillstyle(SOLID_FILL, COLOR(159, 197, 232));
        bar(99, 220, 1440, 688);
        setfillstyle(SOLID_FILL, COLOR(208, 224, 227));
        bar(99, 289, 1440, 688);
        setlinestyle(0, 0, 2);
        setbkcolor(COLOR(159, 197, 232));
        line(190, 220, 190, 698); char a[8] = "NUMBERS"; outtextxy(110, 240, a);
        line(326, 220, 326, 689); char a1[20] = "ID FLIGHT"; outtextxy(230, 240, a1);
        setlinestyle(0, 0, 2);
        line(462, 220, 462, 689); char a2[30] = "SO HIEU MB"; outtextxy(355, 240, a2);
        line(760, 220, 760, 689); char a3[30] = "SAN BAY DEN"; outtextxy(560, 240, a3);
        line(1026, 220, 1026, 689); char a4[20] = "TIME"; outtextxy(873, 240, a4);
        line(1232, 220, 1232, 689); char a5[20] = "TRANG THAI";   outtextxy(1085, 240, a5);
        char a6[20] = "DANH SACH VE"; outtextxy(1295, 240, a6);
        line(99, 220, 99, 689);
        line(1440, 220, 1440, 689);
        for (; dscb != NULL; dscb = dscb->next) {
            dem++;
            chuyenintschar(tmp[0], dem);
            hienchinhgiua(100, y, 190, y + 40, tmp[0]);
            hienchinhgiua(190, y, 325, y + 40, dscb->cb.macb);
            hienchinhgiua(325, y, 462, y + 40, dscb->cb.sohieu);
            hienchinhgiua(462, y, 760, y + 40, dscb->cb.sanbay);
            chuyenintschar(tmp[1], dscb->cb.tg.phut);
            chuyenintschar(tmp[2], dscb->cb.tg.gio);
            chuyenintschar(tmp[3], dscb->cb.tg.ngay);
            chuyenintschar(tmp[4], dscb->cb.tg.thang);
            chuyenintschar(tmp[5], dscb->cb.tg.nam);
            char tg[50]; tg[0] = '\0';
            ostringstream oss;
            oss << setw(2) << setfill('0') << tmp[2] << ":" << setw(2) << setfill('0') << tmp[1] << " - "
                << setw(2) << setfill('0') << tmp[3] << "/" << setw(2) << setfill('0') << tmp[4] << "/" << tmp[5];
            string tgtmp = oss.str();
            chuyenstringschar(tg, tgtmp);
            hienchinhgiua(760, y, 1025, y + 40, tg);
            if (dscb->cb.trangthai == 1) {
                char th[30] = "dahuy";
                hienchinhgiua(1025, y, 1232, y + 40, th);
            }if (dscb->cb.trangthai == 2) {
                char th1[30] = "conve";
                hienchinhgiua(1025, y, 1232, y + 40, th1);
            }if (dscb->cb.trangthai == 3) {
                char th2[30] = "hetve";
                hienchinhgiua(1025, y, 1232, y + 40, th2);
            }if (dscb->cb.trangthai == 4) {
                char th3[30] = "hoantat";
                hienchinhgiua(1025, y, 1232, y + 40, th3);
            }
            int soveco1 = 0;
            for (int i = 0; i < dscb->cb.sove; i++) {
                if (dscb->cb.danhsachve[i][0] != 0) {
                    soveco1++;
                }
            }
            char dsv[30], dsvc[30], hiendsv[30]; dsv[0] = '\0'; dsvc[0] = '\0'; hiendsv[0] = '\0';
            chuyenintschar(dsv, soveco1); chuyenintschar(dsvc, dscb->cb.sove);
            ostringstream osss;
            osss << setw(2) << setfill('0') << dsv << "/" << setw(2) << setfill('0') << dsvc;
            string tgtmps = osss.str();
            chuyenstringschar(hiendsv, tgtmps);
            hienchinhgiua(760, y, 1025, y + 40, tg);
            hienchinhgiua(1234, y, 1439, y + 40, hiendsv);
            y = y + 40;
            line(100, y, 1440, y);

        }
    }if (trangthai == 2) {
        xoavungchidinh(99, 289, 1440, 688);
        setfillstyle(SOLID_FILL, COLOR(159, 197, 232));
        bar(99, 220, 1440, 688);
        setfillstyle(SOLID_FILL, COLOR(208, 224, 227));
        bar(99, 289, 1440, 688);
        setlinestyle(0, 0, 2);
        setbkcolor(COLOR(159, 197, 232));
        line(190, 220, 190, 698); char a[8] = "NUMBERS"; outtextxy(110, 240, a);
        line(326, 220, 326, 689); char a1[20] = "ID FLIGHT"; outtextxy(230, 240, a1);
        setlinestyle(0, 0, 2);
        line(462, 220, 462, 689); char a2[30] = "SO HIEU MB"; outtextxy(355, 240, a2);
        line(760, 220, 760, 689); char a3[30] = "SAN BAY DEN"; outtextxy(560, 240, a3);
        line(1026, 220, 1026, 689); char a4[20] = "TIME"; outtextxy(873, 240, a4);
        line(1232, 220, 1232, 689); char a5[20] = "TRANG THAI";   outtextxy(1085, 240, a5);
        char a6[20] = "DANH SACH VE"; outtextxy(1295, 240, a6);
        line(99, 220, 99, 689);
        line(1440, 220, 1440, 689);
        for (int i = 0; i < dem; i++) {
            dscb = dscb->next;
        }
        for (; dem < tmpdem + 10; dscb = dscb->next) {
            dem++;
            chuyenintschar(tmp[0], dem);
            hienchinhgiua(100, y, 190, y + 40, tmp[0]);
            hienchinhgiua(190, y, 325, y + 40, dscb->cb.macb);
            hienchinhgiua(325, y, 462, y + 40, dscb->cb.sohieu);
            hienchinhgiua(462, y, 760, y + 40, dscb->cb.sanbay);
            chuyenintschar(tmp[1], dscb->cb.tg.phut);
            chuyenintschar(tmp[2], dscb->cb.tg.gio);
            chuyenintschar(tmp[3], dscb->cb.tg.ngay);
            chuyenintschar(tmp[4], dscb->cb.tg.thang);
            chuyenintschar(tmp[5], dscb->cb.tg.nam);
            char tg[50]; tg[0] = '\0';
            ostringstream oss;
            oss << setw(2) << setfill('0') << tmp[2] << ":" << setw(2) << setfill('0') << tmp[1] << " - "
                << setw(2) << setfill('0') << tmp[3] << "/" << setw(2) << setfill('0') << tmp[4] << "/" << tmp[5];
            string tgtmp = oss.str();
            chuyenstringschar(tg, tgtmp);
            hienchinhgiua(760, y, 1025, y + 40, tg);
            if (dscb->cb.trangthai == 1) {
                char th[30] = "dahuy";
                hienchinhgiua(1025, y, 1232, y + 40, th);
            }if (dscb->cb.trangthai == 2) {
                char th1[30] = "conve";
                hienchinhgiua(1025, y, 1232, y + 40, th1);
            }if (dscb->cb.trangthai == 3) {
                char th2[30] = "hetve";
                hienchinhgiua(1025, y, 1232, y + 40, th2);
            }if (dscb->cb.trangthai == 4) {
                char th3[30] = "hoantat";
                hienchinhgiua(1025, y, 1232, y + 40, th3);
            }int soveco1 = 0;
            for (int i = 0; i < dscb->cb.sove; i++) {
                if (dscb->cb.danhsachve[i][0] != 0) {
                    soveco1++;
                }
            }
            char dsv[30], dsvc[30], hiendsv[30]; dsv[0] = '\0'; dsvc[0] = '\0'; hiendsv[0] = '\0';
            chuyenintschar(dsv, soveco1); chuyenintschar(dsvc, dscb->cb.sove);
            ostringstream osss;
            osss << setw(2) << setfill('0') << dsv << "/" << setw(2) << setfill('0') << dsvc;
            string tgtmps = osss.str();
            chuyenstringschar(hiendsv, tgtmps);
            hienchinhgiua(760, y, 1025, y + 40, tg);
            hienchinhgiua(1234, y, 1439, y + 40, hiendsv);
            y = y + 40;
            line(100, y, 1440, y);

        }
    }
    if (trangthai == 3) {
        xoavungchidinh(99, 289, 1440, 688);
        setfillstyle(SOLID_FILL, COLOR(159, 197, 232));
        bar(99, 220, 1440, 688);
        setfillstyle(SOLID_FILL, COLOR(208, 224, 227));
        bar(99, 289, 1440, 688);
        setlinestyle(0, 0, 2);
        setbkcolor(COLOR(159, 197, 232));
        line(190, 220, 190, 698); char a[8] = "NUMBERS"; outtextxy(110, 240, a);
        line(326, 220, 326, 689); char a1[20] = "ID FLIGHT"; outtextxy(230, 240, a1);
        setlinestyle(0, 0, 2);
        line(462, 220, 462, 689); char a2[30] = "SO HIEU MB"; outtextxy(355, 240, a2);
        line(760, 220, 760, 689); char a3[30] = "SAN BAY DEN"; outtextxy(560, 240, a3);
        line(1026, 220, 1026, 689); char a4[20] = "TIME"; outtextxy(873, 240, a4);
        line(1232, 220, 1232, 689); char a5[20] = "TRANG THAI";   outtextxy(1085, 240, a5);
        char a6[20] = "DANH SACH VE"; outtextxy(1295, 240, a6);
        line(99, 220, 99, 689);
        line(1440, 220, 1440, 689);
        for (int i = 0; i < dem; i++) {
            dscb = dscb->next;
        }
        for (; dscb != NULL; dscb = dscb->next) {
            dem++;
            chuyenintschar(tmp[0], dem);
            hienchinhgiua(100, y, 190, y + 40, tmp[0]);
            hienchinhgiua(190, y, 325, y + 40, dscb->cb.macb);
            hienchinhgiua(325, y, 462, y + 40, dscb->cb.sohieu);
            hienchinhgiua(462, y, 760, y + 40, dscb->cb.sanbay);
            chuyenintschar(tmp[1], dscb->cb.tg.phut);
            chuyenintschar(tmp[2], dscb->cb.tg.gio);
            chuyenintschar(tmp[3], dscb->cb.tg.ngay);
            chuyenintschar(tmp[4], dscb->cb.tg.thang);
            chuyenintschar(tmp[5], dscb->cb.tg.nam);
            char tg[50]; tg[0] = '\0';
            ostringstream oss;
            oss << setw(2) << setfill('0') << tmp[2] << ":" << setw(2) << setfill('0') << tmp[1] << " - "
                << setw(2) << setfill('0') << tmp[3] << "/" << setw(2) << setfill('0') << tmp[4] << "/" << tmp[5];
            string tgtmp = oss.str();
            chuyenstringschar(tg, tgtmp);
            hienchinhgiua(760, y, 1025, y + 40, tg);
            if (dscb->cb.trangthai == 1) {
                char th[30] = "dahuy";
                hienchinhgiua(1025, y, 1232, y + 40, th);
            }if (dscb->cb.trangthai == 2) {
                char th1[30] = "conve";
                hienchinhgiua(1025, y, 1232, y + 40, th1);
            }if (dscb->cb.trangthai == 3) {
                char th2[30] = "hetve";
                hienchinhgiua(1025, y, 1232, y + 40, th2);
            }if (dscb->cb.trangthai == 4) {
                char th3[30] = "hoantat";
                hienchinhgiua(1025, y, 1232, y + 40, th3);
            } int soveco1 = 0;
            for (int i = 0; i < dscb->cb.sove; i++) {
                if (dscb->cb.danhsachve[i][0] != 0) {
                    soveco1++;
                }
            }
            char dsv[30], dsvc[30], hiendsv[30]; dsv[0] = '\0'; dsvc[0] = '\0'; hiendsv[0] = '\0';
            chuyenintschar(dsv, soveco1); chuyenintschar(dsvc, dscb->cb.sove);
            ostringstream osss;
            osss << setw(2) << setfill('0') << dsv << "/" << setw(2) << setfill('0') << dsvc;
            string tgtmps = osss.str();
            chuyenstringschar(hiendsv, tgtmps);
            hienchinhgiua(760, y, 1025, y + 40, tg);
            hienchinhgiua(1234, y, 1439, y + 40, hiendsv);

            y = y + 40;
            line(100, y, 1440, y);
        }
    }
}
void hientrangdau(ds& s, int& sochuyenbayhien, int sochuyenbayco, int& sotrangcb) {
    tmp = (float)sochuyenbayco / 10;
    if (tmp > sotrangcb) {
        sotrangcb = tmp + 1;
    }
    if (sotrangcb == 1) {
        hienthidschuyenbay(s, sochuyenbayhien, 1);
    }
    if (sotrangcb > 1) {
        hienthidschuyenbay(s, sochuyenbayhien, 2);
    }
}
void timkiemchuyenbay(ds& vao, ds& ra, char b[], int trangthai, int& socbco, int& sochuyenbaysaukhitimco) {
    //1 idmay bay
    //2 ngay
    //3 thang
    //4 nam
    //5 sanbay den
    sochuyenbaysaukhitimco = 0;
    int sochuyebayxoa = 0;
    if (b[0] == '\0') {
        return;
    }

    int dem = 0;
    ds current = vao;
    while (current != NULL) {
        if (trangthai == 1) {
            if (strcmp(current->cb.macb, b) == 0) {
                push(ra, current->cb);

                current = current->next;
                sochuyenbaysaukhitimco++;
            }
            else {
                current = current->next;
            }
        }
        else if (trangthai == 2) {
            char tmp[30];
            chuyenintschar(tmp, current->cb.tg.ngay);
            if (strcmp(tmp, b) == 0) {
                push(ra, current->cb);
                current = current->next; sochuyenbaysaukhitimco++;
            }
            else {
                current = current->next;

            }
        }
        else if (trangthai == 3) {
            char tmp[30];
            chuyenintschar(tmp, current->cb.tg.thang);
            if (strcmp(tmp, b) == 0) {
                push(ra, current->cb);
                current = current->next; sochuyenbaysaukhitimco++;
            }
            else {
                current = current->next;

            }
        }
        else if (trangthai == 4) {
            char tmp[30];
            chuyenintschar(tmp, current->cb.tg.nam);
            if (strcmp(tmp, b) == 0) {

                push(ra, current->cb);
                current = current->next; sochuyenbaysaukhitimco++;
            }
            else {
                current = current->next;

            }
        }
        else if (trangthai == 5) {
            if (strcmp(current->cb.sanbay, b) == 0) {

                push(ra, current->cb); sochuyebayxoa++;
                current = current->next; sochuyenbaysaukhitimco++;
            }
            else {
                current = current->next;

            }
        }

    }
}
void timkiemchuyenbay1ds(ds& vao, char b[], int trangthai, int& socbco, int& sochuyenbaysaukhitimco) {
    //1 idmay bay
    //2 ngay
    //3 thang
    //4 nam
    //5 sanbay den
    int sochuyebayxoa = 0;
    if (b[0] == '\0') {
        return;
    }

    int dem = 0;
    ds current = vao;
    while (current != NULL) {
        if (trangthai == 1) {
            if (strcmp(current->cb.macb, b) != 0) {
                current = current->next;
                deletecb(vao, dem);
                sochuyebayxoa++;

            }
            else {
                current = current->next;
                dem++;
            }
        }
        else if (trangthai == 2) {
            char tmp[30];
            chuyenintschar(tmp, current->cb.tg.ngay);
            if (strcmp(tmp, b) != 0) {

                current = current->next;
                deletecb(vao, dem);
                sochuyebayxoa++;
            }
            else {
                current = current->next;
                dem++;
            }
        }
        else if (trangthai == 3) {
            char tmp[30];
            chuyenintschar(tmp, current->cb.tg.thang);
            if (strcmp(tmp, b) != 0) {

                current = current->next;
                deletecb(vao, dem);
                sochuyebayxoa++;
            }
            else {
                current = current->next;
                dem++;
            }
        }
        else if (trangthai == 4) {
            char tmp[30];
            chuyenintschar(tmp, current->cb.tg.nam);
            if (strcmp(tmp, b) != 0) {

                current = current->next;
                deletecb(vao, dem);
                sochuyebayxoa++;
            }
            else {
                current = current->next;
                dem++;
            }
        }
        else if (trangthai == 5) {
            if (strcmp(current->cb.sanbay, b) != 0) {

                current = current->next;
                deletecb(vao, dem);
                sochuyebayxoa++;
            }
            else {
                current = current->next;
                dem++;
            }
        }

    }
    sochuyenbaysaukhitimco = socbco - sochuyebayxoa;
}
void Flight_design() {
    setfillstyle(SOLID_FILL, COLOR(159, 197, 232));
    bar(101, 220, 1439, 290);
    setlinestyle(0, 0, 2);
    setcolor(0);
    rectangle(100, 220, 1440, 689);
    setbkcolor(COLOR(208, 224, 227));
    setfillstyle(SOLID_FILL, COLOR(217, 234, 211));
    int x = 110;
    char a7[30] = "ID FLIGHT: "; outtextxy(x, 150, a7); x = x + textwidth(a7);
    bar(x, 140, x + 200, 180); rectangle(x, 140, x + 200, 180); x = x + 230;
    char a8[30] = "TIME: "; outtextxy(x, 150, a8); x = x + textwidth(a8) + 10;
    bar(x, 140, x + 50, 180); rectangle(x, 140, x + 50, 180); x = x + 70;
    char a10[2] = "/"; outtextxy(x, 150, a10); x = x + textwidth(a10) + 10;
    bar(x, 140, x + 50, 180); rectangle(x, 140, x + 50, 180); x = x + 70;
    outtextxy(x, 150, a10); x = x + textwidth(a10) + 10;
    bar(x, 140, x + 100, 180); rectangle(x, 140, x + 100, 180); x = x + 150;
    char a9[30] = "SAN BAY DEN: "; outtextxy(x, 150, a9); x = x + textwidth(a9);
    bar(x, 140, x + 200, 180); rectangle(x, 140, x + 200, 180); x = x + 200;
    setbkcolor(COLOR(217, 234, 211)); char a11[30] = "ADD";
    bar(1290, 140, 1390, 180); outtextxy(1300 + 30, 150, a11);
    //nhap
    setfillstyle(SOLID_FILL, COLOR(159, 197, 232));
    bar(688, 719, 748, 765);
    bar(820, 719, 880, 765);
    line(727, 726, 698, 742);
    line(698, 742, 727, 760);
    line(836, 726, 866, 742);
    line(866, 742, 836, 760);
    setbkcolor(COLOR(208, 224, 227));
    setcolor(COLOR(255, 0, 77));
    outtextxy(70, 705, const_cast<char*>("chuot trai vao o danh sach ve de xem thong tin danh sach ve"));
    outtextxy(70, 730, const_cast<char*>("chuot phai de sua thong tin chuyen bay"));
    outtextxy(70, 755, const_cast<char*>("chuot trai de huy thong tin chuyen bay"));
    setcolor(0);
}



//static---------------------------------------------------------------
void Static_design() {
    setfillstyle(SOLID_FILL, COLOR(159, 197, 232));
    bar(100, 180, 1440, 289);
    setlinestyle(0, 0, 3);
    setcolor(0);
    rectangle(100, 180, 1440, 689);
    setbkcolor(COLOR(159, 197, 232));
    setfillstyle(SOLID_FILL, COLOR(217, 234, 211));
    char a[30] = "STT";
    outtextxy(140, 235, a);
    line(210, 180, 210, 689);
    char a1[30] = "MA MAY BAY";
    outtextxy(476, 235, a1);
    line(831, 180, 831, 689);
    char a2[30] = "SO LAN HOAN THANH CB";
    outtextxy(1053, 235, a2);
    line(100, 289, 1440, 289);
    setfillstyle(SOLID_FILL, COLOR(159, 197, 232));
    bar(688, 719, 748, 765);
    bar(820, 719, 880, 765);
    line(727, 726, 698, 742);
    line(698, 742, 727, 760);
    line(836, 726, 866, 742);
    line(866, 742, 836, 760);
}
void hiendsmbchay(dsmbc& chay, int& phantuhien, int trangthai) {
    cleardevice();
    Screen_Default();
    Static_design();
    int y = 289; dsmbc duyet = NULL; duyet = chay;
    if (trangthai == 1)
    {
        int dem = phantuhien;
        for (; dem < 10; duyet = duyet->next) {
            phantuhien++; dem++;
            char a[30];
            chuyenintschar(a, phantuhien);
            hienchinhgiua(100, y, 210, y + 40, a);
            hienchinhgiua(210, y, 831, y + 40, duyet->db.sohieu);
            char a3[30]; a3[0] = '\0';
            chuyenintschar(a3, duyet->db.lan);
            hienchinhgiua(831, y, 1440, y + 40, a3);
            y = y + 40;
            line(100, y, 1440, y);
        }
    }
    else if (trangthai == 2) {
        int dem = phantuhien;
        for (int i = 0; i < dem; i++) {
            duyet = duyet->next;
        }
        for (; duyet != NULL; duyet = duyet->next) {
            phantuhien++;
            char a[30];
            chuyenintschar(a, phantuhien);
            hienchinhgiua(100, y, 210, y + 40, a);
            hienchinhgiua(210, y, 831, y + 40, duyet->db.sohieu);
            char a3[30]; a3[0] = '\0';
            chuyenintschar(a3, duyet->db.lan);
            hienchinhgiua(831, y, 1440, y + 40, a3);
            y = y + 40;
            line(100, y, 1440, y);
        }
    }
}

//--------------------------------------dieu khien -----------------------------------
void AO_THAT_DAY() {
    int TRANG_THAI_TAB = 1;
    //1=PLANEs| 2=FLIGHT| 3=CUSTOMER... 3.1=XEM_THONG_TIN |4=TICKET| 5=STATIC
    // khai bao cho plane
    openfile(ds_mb);
    int xem_thong_ke_mb = 0;
    bool themmb = 0;
    bool da_search_mb = 0;
    int trang_mb_hientai = 0;

    char dl_mb[5][30]; for (int i = 0; i < 5; i++) dl_mb[i][0] = '\0';
    //khai bao cho flight''''''''''''''''''''''''''''''''''''''''''
    ds tmpcb; tmpcb = nullptr; chuyenbay tmpsua; bool chuyen_trang_xem_ds = false;
    int cbtmp = 0, cbcotmp, sotrangtmp = 1, tranghientmp = 1; int capnhapchuyenbaycotmp; int vitrisua = 0;
    bool addchuyenbay = false; bool suathongtin = false; bool suachuyenbay = false; bool isEnteringText = false; int chuyen_trang_tim_kiem = 0;
    int sotrangxemdsv = 1, tranghientaixemdsv = 1, sophantudsv = 0, sophantuhiendsv = 0; chuyenbay xemds; char** dsvtmp = nullptr; int* vitrighe = nullptr;
    char dlcb[13][30]; char mbsua[30]; mbsua[0] = '\0';
    for (int i = 0; i < 13; i++) {
        dlcb[i][0] = '\0';
    }
    bool muaticket = false; bool chon_may_bay = false; bool sua_cb = 0;
    docdulieu(s, sochuyenbayco);

    //khai bao cho customer........................................
    int trang_hien_tai = 0; ds_hk.lay_du_lieu_tu_file(); dem_so_luong_hk(ds_hk.getRoot());
    char Search[3][30]; for (int i = 0; i < 3; i++) Search[i][0] = '\0';
    int* danh_sach_HK_O_tren_man_hinh = new int[so_luong_hanh_khach];
    bool da_search_hk = 0;
    int so_luong_hanh_khach_tim_thay = 0;
    int trang_curr = 0, trang_max = 0;

    string* xuat_search= new string[ds_hk.getSo_luong_hk() * 4];
    int cout_for_search=0;

    //khai bao cho tiket...........................................
    bool dangmuab1 = 0, dangmuab2 = 0, dang_chon_chuyen_bay = 0, da_chon_phai = 0, da_nhap_du_in4 = 0, da_nhap_CMND = 0, trung_cmnd = 0, chon_ghe = 0;
    char ho[60], ten[30], CMND[30], idFlight_mua_ve[30]; bool phai; ho[0] = '\0'; ten[0] = '\0'; CMND[0] = '\0', idFlight_mua_ve[0] = '\0';
    //khai bao cho InStatic 
    dsmbc chay; int trangmaxmb = 1, somaybaymax = 0, tranghientaimb = 0, somayhienmb = 0;
    //'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    clearmouseclick(WM_LBUTTONDOWN);
    while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int x = mousex();
            int y = mousey();
            clearmouseclick(WM_LBUTTONDOWN);
            if (isMouseInPlanes(x, y) == 1) {
                TRANG_THAI_TAB = 1;
                cleardevice();
                Screen_Default(TRANG_THAI_TAB);
                Planes_design();
                trang_mb_hientai = 0;
                xem_thong_ke_mb = 1;
                themmb = 0;
                hien_ds_mb(trang_mb_hientai, ds_mb, s);
            }
            else if (isMouseInFlight(x, y) == 1) {
                for (int i = 0; i < 13; i++) {
                    dlcb[i][0] = '\0';
                }
                sochuyenbayco = 0;
                s = NULL;
                tmpcb = NULL;
                docdulieu(s, sochuyenbayco);
                tmpcb = NULL; addchuyenbay = false; suathongtin = false; chuyen_trang_xem_ds = false;
                chuyen_trang_tim_kiem = 0;
                TRANG_THAI_TAB = 2;
                tranghientaicb = 1;
                sochuyenbayhien = 0;
                sotrangcb = 1;
                capnhapchuyenbaycotmp = sochuyenbayco;
                cleardevice();
                Screen_Default(TRANG_THAI_TAB);
                Flight_design();
                muaticket = false; chon_may_bay = false;
                cap_nhat_trang_thai_cb(s);

                hientrangdau(s, sochuyenbayhien, sochuyenbayco, sotrangcb);
                sotrangxemdsv = 1, tranghientaixemdsv = 1, sophantudsv = 0, sophantuhiendsv = 0;
                trang_mb_hientai = 0;
                sua_cb = 0;
            }
            else if (isMouseInCustomer(x, y) == 1) {
                TRANG_THAI_TAB = 3;
                cleardevice();
                Screen_Default(TRANG_THAI_TAB);
                Customer_design();
                da_search_hk = 0;
                trang_hien_tai = 0;
                Hien_thi_hanh_khach(trang_hien_tai);
                for (int i = 0; i < 3; i++) Search[i][0] = '\0';
            }
            else if (isMouseInTicket(x, y) == 1) {
                tranghientaicb = 1;
                TRANG_THAI_TAB = 4;
                cleardevice();
                Screen_Default(TRANG_THAI_TAB);
                Ticket_design();
                for (int i = 0; i < 13; i++) {
                    dlcb[i][0] = '\0';
                }
                sochuyenbayco = 0;
                s = NULL;
                docdulieu(s, sochuyenbayco);
                tmpcb = NULL; addchuyenbay = false; suathongtin = false; chuyen_trang_xem_ds = false;
                chuyen_trang_tim_kiem = 0;
                sochuyenbayhien = 0;
                sotrangcb = 1;
                muaticket = false;
                capnhapchuyenbaycotmp = sochuyenbayco;
                dangmuab1 = 0;
                dangmuab2 = 0;
                dang_chon_chuyen_bay = 0;
                da_nhap_CMND = 0;
                chon_ghe = 0;
                cap_nhat_trang_thai_cb(s);
                hientrangdau(s, sochuyenbayhien, sochuyenbayco, sotrangcb);
            }
            else if (isMouseInStatic(x, y) == 1) {
                cap_nhat_trang_thai_cb(s);
                TRANG_THAI_TAB = 5;
                cleardevice();
                Screen_Default(TRANG_THAI_TAB);
                Static_design();
                chay = NULL; trangmaxmb = 1; somaybaymax = 0; tranghientaimb = 1; somayhienmb = 0;
                dsmbchay phantu; int qq;
                for (int i = 0; i < ds_mb.n; i++) {
                    qq = 0;
                    STRCPYY(phantu.sohieu, ds_mb.nodes[i]->sohieu);
                    ds duyet = NULL; duyet = s;
                    while (duyet != NULL) {
                        if (strcmp(ds_mb.nodes[i]->sohieu, duyet->cb.sohieu) == 0 && duyet->cb.trangthai == 4) {
                            qq++;
                        }
                        duyet = duyet->next;
                    }
                    phantu.lan = qq;
                    if (phantu.lan != 0) {
                        pushmb(chay, phantu);
                        somaybaymax++;
                        phantu.lan = 0;
                        phantu.sohieu[0] = '\0';
                    }
                }


                if (chay != NULL) {
                    float dd = somaybaymax / 10.0;
                    if (trangmaxmb * 1.0 < dd) {
                        trangmaxmb = dd + 1;
                        hiendsmbchay(chay, somayhienmb, 1);
                    }
                    else {
                        hiendsmbchay(chay, somayhienmb, 2);
                    }
                }
                //??????????????????????????????????????????????????????????                 
            }
            //chuyen trang Static
            else if (TRANG_THAI_TAB == 5 && (isMousexemtrangsau(x, y) == 1 || isMousexemtrangtruoc(x, y) == 1)) {
                if (isMousexemtrangsau(x, y) == 1) {
                    if (tranghientaimb < trangmaxmb) {
                        tranghientaimb++;
                        somayhienmb = (tranghientaimb - 1) * 10;
                        cout << somaybaymax << endl;
                        if (tranghientaimb == trangmaxmb) {
                            hiendsmbchay(chay, somayhienmb, 2);
                        }
                        else {
                            hiendsmbchay(chay, somayhienmb, 1);

                        }
                    }
                }
                else if (isMousexemtrangtruoc(x, y) == 1) {
                    //tranghientaicb,sotrangcb,sochuyenbayco
                    if (tranghientaimb > 1) {
                        tranghientaimb--;
                        somayhienmb = (tranghientaimb - 1) * 10;
                        hiendsmbchay(chay, somayhienmb, 1);
                    }
                }
            }




            //plane
            else if (TRANG_THAI_TAB == 1 && xem_thong_ke_mb == 1 && themmb == 0) {
                if (isMouseThemMayBay(x, y)) {
                    themmb = 1;
                    xem_thong_ke_mb = 0;
                    hienthemmaybay();
                }
                if (x >= 130 && x <= 900 && y >= 190 && y <= 680) {
                    int stt = (y - 190) / 49 + trang_mb_hientai * 10;
                    xoa_mb_theo_stt(stt, ds_mb, trang_mb_hientai, s);
                }
                int trang_mb_max = ds_mb.n / 10;
                if (isMouseNEXT_PAGE_MB(x, y)) {
                    if (trang_mb_hientai < trang_mb_max) {
                        trang_mb_hientai++;
                        hien_ds_mb(trang_mb_hientai, ds_mb, s);
                    }

                }
                if (isMouseBACK_PAGE_MB(x, y)) {
                    if (trang_mb_hientai > 0) {
                        trang_mb_hientai--;
                        hien_ds_mb(trang_mb_hientai, ds_mb, s);
                    }
                }
            }
            //themmb
            else if (TRANG_THAI_TAB == 1 && themmb == 1) {
                char dl1[30], dl2[30], dl3[30], dl4[30];
                dl1[0] = '\0'; dl2[0] = '\0'; dl3[0] = '\0'; dl4[0] = '\0';
                if (isMouseaddidflight(x, y) == 1) {
                    nhapdulieu(445, 235, 440, 1046, 221, 265, dl1, 30, 2);
                    STRCPYY(dl_mb[0], dl1);
                }
                else if (isMouseaddmamaybay(x, y) == 1) {
                    nhapdulieu(445, 335, 440, 1046, 320, 363, dl2, 30, 2);
                    STRCPYY(dl_mb[1], dl2);

                }
                else if (isMouseaddnoiden(x, y) == 1) {
                    nhapdulieu(445, 435, 440, 1046, 420, 466, dl3, 30, 1);
                    STRCPYY(dl_mb[2], dl3);
                }
                else if (isMouseNhapDONG_them_mb(x, y)) {
                    nhapdulieu(445, 529, 440, 1046, 519, 563, dl4, 30, 1);
                    STRCPYY(dl_mb[3], dl4);
                }
                else if (isMousesave(x, y) == 1) {
                    if (timkiem(ds_mb, const_cast<char*>(dl_mb[0])) == -1) {
                        int soday = 0, sodong = 0;
                        chuyencharsint(dl_mb[2], soday);
                        chuyencharsint(dl_mb[3], sodong);
                        maybay tmp = taomaybay(const_cast<char*>(dl_mb[0]), const_cast<char*>(dl_mb[1]), soday, sodong);
                        addmb(ds_mb, tmp);
                        savefile(ds_mb);

                        hienthiloi(const_cast<char*>("them thanh cong"));
                    }
                    else {
                        hienthiloi(const_cast<char*>("trung ma may bay"));
                    }
                }
                if (isMouseback(x, y) == 1) {
                    themmb = 0;
                    xem_thong_ke_mb = 1;
                    cleardevice();
                    cleardevice();
                    Screen_Default(TRANG_THAI_TAB);
                    Planes_design();
                    trang_mb_hientai = 0;
                    hien_ds_mb(trang_mb_hientai, ds_mb, s);
                    xem_thong_ke_mb = 1;
                    themmb = 0;
                }

            }





            //timkiem
            else if ((TRANG_THAI_TAB == 2 && addchuyenbay == false && chuyen_trang_xem_ds == false || (TRANG_THAI_TAB == 4 && dangmuab1 == 0 && dangmuab2 == 0 && dang_chon_chuyen_bay == 0 && chon_ghe == 0) || (TRANG_THAI_TAB == 4 && dang_chon_chuyen_bay == 1 && chon_ghe == 0)) && (isMousenhapidFlight(x, y) == 1 || isMouseaddFlight(x, y) == 1 || isMousenhapDAY(x, y) == 1 || isMousenhapMONTH(x, y) == 1 || isMousenhapYEAR(x, y) == 1 || isMousenhapsomaybay(x, y) == 1)) {
                char dl1[30], dl2[30], dl3[30], dl4[30], dl5[30];
                dl1[0] = '\0'; dl2[0] = '\0'; dl3[0] = '\0'; dl4[0] = '\0'; dl5[0] = '\0';
                if (isMousenhapidFlight(x, y) == 1) {
                    cbtmp = 0, cbcotmp, sotrangtmp = 1;
                    nhapdulieu(185, 150, 184, 382, 141, 179, dl1, 12, 2);
                    STRCPYY(dlcb[0], dl1);
                    if (dlcb[0][0] == '\0') {
                        continue;
                    }
                    else {
                        if (dlcb[1][0] == '\0' && dlcb[2][0] == '\0' && dlcb[3][0] == '\0' && dlcb[4][0] == '\0') {
                            if (tmpcb != NULL) {
                                while (tmpcb) {
                                    ds qq;
                                    qq = tmpcb->next;
                                    delete tmpcb;
                                    tmpcb = qq;
                                }
                                tmpcb = NULL;
                                if (s == NULL) {
                                    char a[100] = "khong co chuyen bay nao de tim";
                                    hienthiloi(a);
                                }
                                else {
                                    timkiemchuyenbay(s, tmpcb, dlcb[0], 1, capnhapchuyenbaycotmp, cbcotmp);
                                    capnhapchuyenbaycotmp = cbcotmp;
                                    hientrangdau(tmpcb, cbtmp, cbcotmp, sotrangtmp);
                                    chuyen_trang_tim_kiem = 1;
                                }
                            }
                            else {
                                if (s == NULL) {
                                    char a[100] = "khong co chuyen bay nao de tim";
                                    hienthiloi(a);
                                }
                                else {
                                    timkiemchuyenbay(s, tmpcb, dlcb[0], 1, capnhapchuyenbaycotmp, cbcotmp);
                                    capnhapchuyenbaycotmp = cbcotmp;
                                    hientrangdau(tmpcb, cbtmp, cbcotmp, sotrangtmp);
                                    chuyen_trang_tim_kiem = 1;
                                }
                            }
                        }
                        else {
                            timkiemchuyenbay1ds(tmpcb, dlcb[0], 1, capnhapchuyenbaycotmp, cbcotmp);
                            capnhapchuyenbaycotmp = cbcotmp;
                            hientrangdau(tmpcb, cbtmp, cbcotmp, sotrangtmp);
                            chuyen_trang_tim_kiem = 1;
                        }
                    }
                }
                if (isMousenhapDAY(x, y) == 1 || isMousenhapMONTH(x, y) == 1 || isMousenhapYEAR(x, y) == 1) {
                    int b;
                    if (isMousenhapDAY(x, y) == 1) {

                        do {

                            b = 0;
                            char a[30] = "nhap >0 va <30";
                            nhapdulieu(469, 150, 468, 514, 141, 179, dl2, 2, 3);
                            chuyencharsint(dl2, b);
                            if (b > 31 || b <= 0) {
                                hienthiloi(a);
                            }
                        } while (b > 31 || b <= 0);
                        STRCPYY(dlcb[1], dl2);
                        if (dlcb[1][0] == '\0') {
                            continue;
                        }
                        else {
                            if (dlcb[0][0] == '\0' && dlcb[2][0] == '\0' && dlcb[3][0] == '\0' && dlcb[4][0] == '\0') {
                                if (tmpcb != NULL) {
                                    while (tmpcb) {
                                        ds qq;
                                        qq = tmpcb->next;
                                        delete tmpcb;
                                        tmpcb = qq;
                                    }
                                    tmpcb = NULL;
                                    if (s == NULL) {
                                        char a[100] = "khong co chuyen bay nao de tim";
                                        hienthiloi(a);
                                    }
                                    else {
                                        timkiemchuyenbay(s, tmpcb, dlcb[1], 2, capnhapchuyenbaycotmp, cbcotmp);
                                        capnhapchuyenbaycotmp = cbcotmp;
                                        hientrangdau(tmpcb, cbtmp, cbcotmp, sotrangtmp);
                                        chuyen_trang_tim_kiem = 1;
                                    }
                                }
                                else {
                                    if (s == NULL) {
                                        char a[100] = "khong co chuyen bay nao de tim";
                                        hienthiloi(a);
                                    }
                                    else {
                                        cbtmp = 0, cbcotmp, sotrangtmp = 1;
                                        timkiemchuyenbay(s, tmpcb, dlcb[1], 2, capnhapchuyenbaycotmp, cbcotmp);
                                        capnhapchuyenbaycotmp = cbcotmp;
                                        hientrangdau(tmpcb, cbtmp, cbcotmp, sotrangtmp);
                                        chuyen_trang_tim_kiem = 1;
                                    }
                                }
                            }
                            else {
                                if (tmpcb == NULL) {
                                    char a[100] = "khong co chuyen bay nao de tim";
                                    hienthiloi(a);
                                }
                                else {
                                    cbtmp = 0, cbcotmp, sotrangtmp = 1;
                                    timkiemchuyenbay1ds(tmpcb, dlcb[1], 2, capnhapchuyenbaycotmp, cbcotmp);
                                    capnhapchuyenbaycotmp = cbcotmp;
                                    hientrangdau(tmpcb, cbtmp, cbcotmp, sotrangtmp);
                                    chuyen_trang_tim_kiem = 1;
                                }
                            }

                        }
                    }
                    if (isMousenhapMONTH(x, y) == 1) {

                        do {

                            b = 0;
                            char a[30] = "nh?p >0 và =<12";
                            nhapdulieu(553, 150, 552, 597, 141, 179, dl3, 2, 3);
                            chuyencharsint(dl3, b);

                            if (b > 12 || b <= 0) {
                                hienthiloi(a);
                            }
                        } while (b > 12 || b <= 0);
                        STRCPYY(dlcb[2], dl3);
                        if (dlcb[2][0] == '\0') {
                            continue;
                        }
                        else {
                            if (dlcb[0][0] == '\0' && dlcb[1][0] == '\0' && dlcb[3][0] == '\0' && dlcb[4][0] == '\0') {
                                if (tmpcb != NULL) {
                                    while (tmpcb) {
                                        ds qq;
                                        qq = tmpcb->next;
                                        delete tmpcb;
                                        tmpcb = qq;
                                    }
                                    tmpcb = NULL;
                                    if (s == NULL) {
                                        char a[100] = "khong co chuyen bay nao de tim";
                                        hienthiloi(a);
                                    }
                                    else {
                                        timkiemchuyenbay(s, tmpcb, dlcb[2], 3, capnhapchuyenbaycotmp, cbcotmp);
                                        capnhapchuyenbaycotmp = cbcotmp;
                                        hientrangdau(tmpcb, cbtmp, cbcotmp, sotrangtmp);
                                        chuyen_trang_tim_kiem = 1;
                                    }
                                }
                                else {
                                    if (s == NULL) {
                                        char a[100] = "khong co chuyen bay nao de tim";
                                        hienthiloi(a);
                                    }
                                    else {
                                        cbtmp = 0, cbcotmp, sotrangtmp = 1;
                                        timkiemchuyenbay(s, tmpcb, dlcb[2], 3, capnhapchuyenbaycotmp, cbcotmp);
                                        capnhapchuyenbaycotmp = cbcotmp;
                                        hientrangdau(tmpcb, cbtmp, cbcotmp, sotrangtmp);
                                        chuyen_trang_tim_kiem = 1;
                                    }
                                }
                            }
                            else {
                                if (tmpcb == NULL) {
                                    char a[100] = "khong co chuyen bay nao de tim";
                                    hienthiloi(a);
                                }
                                else {
                                    cbtmp = 0, cbcotmp, sotrangtmp = 1;
                                    timkiemchuyenbay1ds(tmpcb, dlcb[2], 3, capnhapchuyenbaycotmp, cbcotmp);
                                    capnhapchuyenbaycotmp = cbcotmp;
                                    hientrangdau(tmpcb, cbtmp, cbcotmp, sotrangtmp);
                                    chuyen_trang_tim_kiem = 1;
                                }
                            }
                        }
                    }
                    if (isMousenhapYEAR(x, y) == 1) {

                        do {

                            b = 0;
                            nhapdulieu(637, 150, 636, 733, 141, 179, dl4, 4, 3);

                            chuyencharsint(dl4, b);

                            if (b < 2024) {
                                char a[30] = "nhap >=2024";
                                hienthiloi(a);
                            }
                        } while (b < 2024);
                        STRCPYY(dlcb[3], dl4);
                        if (dlcb[3][0] == '\0') {
                            continue;
                        }
                        else {
                        if (dlcb[0][0] == '\0' && dlcb[2][0] == '\0' && dlcb[1][0] == '\0' && dlcb[4][0] == '\0') {
                            if (tmpcb != NULL) {
                                while (tmpcb) {
                                    ds qq;
                                    qq = tmpcb->next;
                                    delete tmpcb;
                                    tmpcb = qq;
                                }
                                tmpcb = NULL;
                                if (s == NULL) {
                                    char a[100] = "khong co chuyen bay nao de tim";
                                    hienthiloi(a);
                                }
                                else {
                                    timkiemchuyenbay(s, tmpcb, dlcb[3], 4, capnhapchuyenbaycotmp, cbcotmp);
                                    capnhapchuyenbaycotmp = cbcotmp;
                                    hientrangdau(tmpcb, cbtmp, cbcotmp, sotrangtmp);
                                    chuyen_trang_tim_kiem = 1;
                                }
                            }
                            else {
                                if (s == NULL) {
                                    char a[100] = "khong co chuyen bay nao de tim";
                                    hienthiloi(a);
                                }
                                else {
                                    cbtmp = 0, cbcotmp, sotrangtmp = 1;
                                    timkiemchuyenbay(s, tmpcb, dlcb[3], 4, capnhapchuyenbaycotmp, cbcotmp);
                                    capnhapchuyenbaycotmp = cbcotmp;
                                    hientrangdau(tmpcb, cbtmp, cbcotmp, sotrangtmp);
                                    chuyen_trang_tim_kiem = 1;
                                }
                            }
                        }
                        else {
                            if (tmpcb == NULL) {
                                char a[100] = "khong co chuyen bay nao de tim";
                                hienthiloi(a);
                            }
                            else {
                                cbtmp = 0, cbcotmp, sotrangtmp = 1;
                                timkiemchuyenbay1ds(tmpcb, dlcb[3], 4, capnhapchuyenbaycotmp, cbcotmp);
                                capnhapchuyenbaycotmp = cbcotmp;
                                hientrangdau(tmpcb, cbtmp, cbcotmp, sotrangtmp);
                                chuyen_trang_tim_kiem = 1;
                            }
                        }
                    }
                }
            }
                else if (isMousenhapsomaybay(x, y) == 1) {

                    nhapdulieu(886, 150, 886, 1082, 141, 179, dl5, 12, 2);
                    STRCPYY(dlcb[4], dl5);
                    if (dlcb[4][0] == '\0') {
                        continue;
                    }
                    else {
                        if (dlcb[0][0] == '\0' && dlcb[2][0] == '\0' && dlcb[3][0] == '\0' && dlcb[1][0] == '\0') {
                            if (tmpcb != NULL) {
                                while (tmpcb) {
                                    ds qq;
                                    qq = tmpcb->next;
                                    delete tmpcb;
                                    tmpcb = qq;
                                }
                                tmpcb = NULL;
                                if (s == NULL) {
                                    char a[100] = "khong co chuyen bay nao de tim";
                                    hienthiloi(a);
                                }
                                else {
                                    timkiemchuyenbay(s, tmpcb, dlcb[4], 5, capnhapchuyenbaycotmp, cbcotmp);
                                    capnhapchuyenbaycotmp = cbcotmp;
                                    hientrangdau(tmpcb, cbtmp, cbcotmp, sotrangtmp);
                                    chuyen_trang_tim_kiem = 1;
                                }
                            }
                            else {
                                if (s == NULL) {
                                    char a[100] = "khong co chuyen bay nao de tim";
                                    hienthiloi(a);
                                }
                                else {
                                    cbtmp = 0, cbcotmp, sotrangtmp = 1;
                                    timkiemchuyenbay(s, tmpcb, dlcb[4], 5, capnhapchuyenbaycotmp, cbcotmp);

                                    capnhapchuyenbaycotmp = cbcotmp;
                                    hientrangdau(tmpcb, cbtmp, cbcotmp, sotrangtmp);
                                    chuyen_trang_tim_kiem = 1;
                                }
                            }
                        }
                        else {
                            if (tmpcb == NULL) {
                                char a[100] = "khong co chuyen bay nao de tim";
                                hienthiloi(a);
                            }
                            else {
                                cbtmp = 0, cbcotmp, sotrangtmp = 1;
                                timkiemchuyenbay1ds(tmpcb, dlcb[4], 5, capnhapchuyenbaycotmp, cbcotmp);
                                capnhapchuyenbaycotmp = cbcotmp;
                                hientrangdau(tmpcb, cbtmp, cbcotmp, sotrangtmp);
                                chuyen_trang_tim_kiem = 1;
                            }
                        }

                    }
                }
                else if (isMouseaddFlight(x, y) == 1) {
                    if (TRANG_THAI_TAB == 2)
                    {
                        cleardevice();
                        hienthemchuyebay();
                        addchuyenbay = true;
                    }
                    else if (TRANG_THAI_TAB == 4 && dang_chon_chuyen_bay == 0 && chon_ghe == 0) {
                        dangmuab1 = 1;
                        dangmuab2 = 0;
                        dang_chon_chuyen_bay = 0;
                        chon_ghe = 0;
                        cleardevice();
                        Screen_Default(TRANG_THAI_TAB);
                        Man_hinh_mua_ticket_b1();
                    }
                }

            }
            //them cb
            else if (TRANG_THAI_TAB == 2 && addchuyenbay && chon_may_bay == false && suathongtin == false && sua_cb == 0 && (isMouseaddidflight(x, y) == 1 || isMouseaddmamaybay(x, y) == 1 || isMouseback(x, y) == 1 || isMouseaddnoiden(x, y) == 1 || isMouseaddday(x, y) == 1 || isMouseaddthang(x, y) == 1 || isMouseaddyear(x, y) == 1 || isMouseaddgio(x, y) == 1 || isMouseaddphut(x, y) == 1 || isMousetimmaybay(x, y) == 1 || isMousesave(x, y) == 1 || isMousechonmaybay(x, y) == 1)) {
                if (isMouseback(x, y) == 1) {
                    for (int i = 0; i < 13; i++) {
                        dlcb[i][0] = '\0';
                    }
                    sochuyenbayco = 0;
                    s = NULL;
                    tmpcb = NULL;
                    docdulieu(s, sochuyenbayco);
                    tmpcb = NULL; addchuyenbay = false; suathongtin = false; chuyen_trang_xem_ds = false;
                    chuyen_trang_tim_kiem = 0;
                    TRANG_THAI_TAB = 2;
                    sochuyenbayhien = 0;
                    sotrangcb = 1;
                    capnhapchuyenbaycotmp = sochuyenbayco;
                    cleardevice();
                    Screen_Default(TRANG_THAI_TAB);
                    Flight_design();
                    hientrangdau(s, sochuyenbayhien, sochuyenbayco, sotrangcb);
                    muaticket = false;
                }
                else if (isMouseaddidflight(x, y) == 1 || isMouseaddmamaybay(x, y) == 1 || isMouseaddnoiden(x, y) == 1 || isMouseaddday(x, y) == 1 || isMouseaddthang(x, y) == 1 || isMouseaddyear(x, y) == 1 || isMouseaddgio(x, y) == 1 || isMouseaddphut(x, y) == 1 || isMousetimmaybay(x, y) == 1 || isMousesave(x, y) == 1 || isMousechonmaybay(x, y) == 1) {
                    char tmp[8][30];
                    for (int i = 0; i < 7; i++) {
                        tmp[i][0] = '\0';
                    }
                    int b = 0;
                    if (isMousechonmaybay(x, y) == 1) {
                        cleardevice();
                        Screen_Default(TRANG_THAI_TAB);
                        Planes_design();
                        chon_may_bay = true;
                        hien_ds_mb(trang_mb_hientai, ds_mb, s);

                    }
                    else if (isMouseaddidflight(x, y) == 1) {
                        nhapdulieu(445, 235, 440, 1046, 221, 265, tmp[0], 12, 2);
                        STRCPYY(dlcb[5], tmp[0]);
                        ds kt = s; int demtrung = 0;
                        for (; kt != NULL; kt = kt->next) {
                            if (strcmp(kt->cb.macb, dlcb[5]) == 0) {
                                demtrung++;
                            }
                        }
                        if (demtrung > 0) {
                            char a[30] = "ma chuyen bay da co";
                            hienthiloi(a);
                        }
                    }
                    else if (isMouseaddmamaybay(x, y) == 1) {
                        nhapdulieu(445, 335, 440, 1046, 320, 363, tmp[1], 12, 2);
                        STRCPYY(dlcb[6], tmp[1]);
                        if (timkiem(ds_mb, dlcb[6]) == -1) {
                            char a3[30] = "may bay ko ton tai";
                            hienthiloi(a3);
                        }

                    }
                    else if (isMouseaddnoiden(x, y) == 1) {
                        nhapdulieu(445, 435, 440, 1046, 420, 466, tmp[2], 30, 1);
                        STRCPYY(dlcb[7], tmp[2]);
                    }
                    else if (isMouseaddday(x, y) == 1) {
                        do {
                            b = 0;
                            char a[30] = "nhap >0 va <30";
                            nhapdulieu(445, 535, 440, 513, 519, 563, tmp[3], 2, 3);
                            chuyencharsint(tmp[3], b);
                            if (b > 31 || b <= 0) {
                                hienthiloi(a);
                            }
                        } while (b > 31 || b <= 0);
                        STRCPYY(dlcb[8], tmp[3]);

                    }
                    else if (isMouseaddthang(x, y) == 1) {
                        do {
                            b = 0;
                            char a[30] = "nh?p >0 và <12";
                            nhapdulieu(530, 535, 526, 596, 519, 563, tmp[4], 2, 3);
                            chuyencharsint(tmp[4], b);

                            if (b > 12 || b <= 0) {
                                hienthiloi(a);
                            }
                        } while (b > 12 || b <= 0);

                        STRCPYY(dlcb[9], tmp[4]);
                    }
                    else if (isMouseaddyear(x, y) == 1) {
                        do {
                            b = 0;
                            char a[30] = "nam >=2024";
                            nhapdulieu(613, 535, 610, 678, 519, 563, tmp[5], 4, 3);
                            chuyencharsint(tmp[5], b);
                            if (b < 2024) {
                                hienthiloi(a);
                            }
                        } while (b < 2024);
                        STRCPYY(dlcb[10], tmp[5]);
                    }
                    else if (isMouseaddgio(x, y) == 1) {
                        do {
                            b = 0;
                            char a[30] = "nhap >=0 va <24";
                            nhapdulieu(706, 535, 703, 771, 519, 563, tmp[6], 2, 3);
                            chuyencharsint(tmp[6], b);
                            if (b > 24 || b < 0) {
                                hienthiloi(a);
                            }
                        } while (b > 24 || b < 0);
                        STRCPYY(dlcb[11], tmp[6]);
                    }
                    else if (isMouseaddphut(x, y) == 1) {
                        do {
                            b = 0;
                            char a[30] = "nhap >0 va <60";
                            nhapdulieu(788, 535, 785, 854, 519, 563, tmp[7], 2, 3);
                            chuyencharsint(tmp[7], b);
                            if (b > 60 || b < 0) {
                                hienthiloi(a);
                            }
                        } while (b > 60 || b < 0);
                        STRCPYY(dlcb[12], tmp[7]);
                    }
                    else if (isMousesave(x, y) == 1) {
                        int demptr = 0, b;
                        chuyenbay a;
                        for (int i = 5; i < 13; i++) {
                            if (dlcb[i][0] == '\0') {
                                demptr++;
                            }
                        }
                        if (demptr == 0) {
                            ds duyet; duyet = s; int demloi = 0;
                            if (timkiem(ds_mb, dlcb[6]) == -1) {
                                char a3[30] = "may bay ko ton tai";
                                hienthiloi(a3);
                            }
                            else {
                                for (; duyet != NULL; duyet = duyet->next) {
                                    if (strcmp(duyet->cb.macb, dlcb[5]) == 0) {
                                        demloi++;
                                    }
                                }
                                if (demloi > 0) {
                                    char a[30] = "ma chuyen bay da co";
                                    hienthiloi(a);
                                }
                                else {
                                    int tmptg[7], tght[5];
                                    for (int i = 0; i < 7; i++) {
                                        tmptg[i] = 0;
                                        if (i < 5) {
                                            tght[i] = 0;
                                        }
                                    }
                                    STRCPYY(a.macb, dlcb[5]);
                                    STRCPYY(a.sohieu, dlcb[6]);
                                    STRCPYY(a.sanbay, dlcb[7]);
                                    b = 0;
                                    chuyencharsint(dlcb[8], b); a.tg.ngay = b; b = 0;
                                    chuyencharsint(dlcb[9], b); a.tg.thang = b; b = 0;
                                    chuyencharsint(dlcb[10], b); a.tg.nam = b; b = 0;
                                    chuyencharsint(dlcb[11], b); a.tg.gio = b; b = 0;
                                    chuyencharsint(dlcb[12], b); a.tg.phut = b; b = 0;
                                    lay_tg_hien_tai(tght[0], tght[1], tght[2], tght[3], tght[4]);
                                    chuyencharsint(dlcb[11], tmptg[6]);
                                    chuyencharsint(dlcb[8], tmptg[0]); chuyencharsint(dlcb[9], tmptg[1]); chuyencharsint(dlcb[10], tmptg[2]); chuyencharsint(dlcb[11], tmptg[3]);
                                    if (tght[2] > tmptg[2] || (tght[2] == tmptg[2] && tght[1] > tmptg[1]) || (tght[2] == tmptg[2] && tght[1] == tmptg[1] && tght[0] > tmptg[0]) || (tght[2] == tmptg[2] && tght[1] == tmptg[1] && tght[0] == tmptg[0] && tght[3] - tmptg[3] >= 0)) {
                                        char loi[100] = "thoi gian phai sau thoi gian hien tai";
                                        hienthiloi(loi);
                                    }
                                    else {
                                        ds duyet; duyet = s; int demloi = 0;
                                        for (; duyet != NULL; duyet = duyet->next) {
                                            if (strcmp(duyet->cb.sohieu, dlcb[6]) == 0) {
                                                if (tmptg[0] == duyet->cb.tg.ngay && tmptg[1] == duyet->cb.tg.thang && tmptg[2] == duyet->cb.tg.nam) {
                                                    if (abs(duyet->cb.tg.gio - tmptg[3]) <= 3) {
                                                        demloi++;
                                                    }
                                                }
                                            }
                                        }
                                        if (demloi > 0) {
                                            char a[100] = "may bay da co chuyen bay trong tg nay";
                                            hienthiloi(a);
                                        }
                                        else {
                                            a.trangthai = 2; int soday = 0, sodong = 0;
                                            soday = ds_mb.nodes[timkiem(ds_mb, a.sohieu)]->soday;
                                            sodong = ds_mb.nodes[timkiem(ds_mb, a.sohieu)]->sodong;
                                            a.sove = soday * sodong;
                                            a.danhsachve = new char* [a.sove];
                                            for (int i = 0; i < a.sove; i++) {
                                                a.danhsachve[i] = new char[30];
                                                a.danhsachve[i][0] = '\0';

                                            }
                                            push(s, a);
                                            capnhatdulieu(s);
                                            char tc[30] = "da them thanh cong";
                                            hienthiloi(tc);
                                        }



                                    }

                                }
                            }
                        }
                        else {
                            char l[30] = "ban can nhap du thong tin";
                            hienthiloi(l);
                        }
                    }
                }
            }
            else if (TRANG_THAI_TAB == 2 && addchuyenbay && suathongtin == false && chon_may_bay && sua_cb == 0) {
                int trang_mb_max = ds_mb.n / 10;
                if (isMouseNEXT_PAGE_MB(x, y)) {
                    if (trang_mb_hientai < trang_mb_max) {

                        trang_mb_hientai++;
                        hien_ds_mb(trang_mb_hientai, ds_mb, s);
                    }

                }
                if (isMouseBACK_PAGE_MB(x, y)) {
                    if (trang_mb_hientai > 0) {
                        trang_mb_hientai--;
                        hien_ds_mb(trang_mb_hientai, ds_mb, s);
                    }
                }
                if (x >= 130 && x <= 900 && y >= 190 && y <= 680) {
                    int stt = (y - 190) / 49 + trang_mb_hientai * 10;
                    if (stt < ds_mb.n)
                    {
                        STRCPYY(dlcb[6], ds_mb.nodes[stt]->sohieu);
                        cleardevice();
                        Screen_Default(TRANG_THAI_TAB);
                        hienthemchuyebay();
                        setbkcolor(COLOR(217, 234, 211));
                        outtextxy(448, 337, dlcb[6]);
                        setbkcolor(COLOR(217, 234, 211));
                        outtextxy(450, 235, dlcb[5]);
                        outtextxy(450, 335, dlcb[6]);
                        outtextxy(450, 435, dlcb[7]);
                        char tg[30];
                        outtextxy(450, 535, dlcb[8]);
                        outtextxy(527, 535, dlcb[9]);
                        outtextxy(610, 535, dlcb[10]);
                        outtextxy(703, 535, dlcb[11]);
                        outtextxy(785, 535, dlcb[12]);
                        suathongtin = false;
                        chon_may_bay = false; addchuyenbay = true; TRANG_THAI_TAB = 2;
                        trang_mb_hientai = 0;
                    }
                }

            }
            // xem danh sach ve         
            else if (TRANG_THAI_TAB == 2 && chuyen_trang_xem_ds==true ) {
                if (isMouseback(x, y) == 1) {
                    for (int i = 0; i < 13; i++) {
                        dlcb[i][0] = '\0';
                    }
                    sochuyenbayco = 0;
                    s = NULL;
                    tmpcb = NULL;
                    docdulieu(s, sochuyenbayco);
                    tmpcb = NULL; addchuyenbay = false; suathongtin = false; chuyen_trang_xem_ds = false;
                    chuyen_trang_tim_kiem = 0;
                    TRANG_THAI_TAB = 2;
                    sochuyenbayhien = 0;
                    sotrangcb = 1;
                    capnhapchuyenbaycotmp = sochuyenbayco;
                    cleardevice();
                    Screen_Default();
                    Flight_design();
                    hientrangdau(s, sochuyenbayhien, sochuyenbayco, sotrangcb);
                    muaticket = false;
                    delete dsvtmp; delete vitrighe;
                    sotrangxemdsv = 1, tranghientaixemdsv = 1, sophantudsv = 0, sophantuhiendsv = 0;
                }                
               
            }           
            //chuyentrang
            else if ((TRANG_THAI_TAB == 2 || (TRANG_THAI_TAB == 4 && dangmuab1 == 0 && dangmuab2 == 0 && dang_chon_chuyen_bay == 0 && chon_ghe == 0) || (TRANG_THAI_TAB == 4 && dang_chon_chuyen_bay == 1 && chon_ghe == 0)) && chuyen_trang_tim_kiem == 0 && chuyen_trang_xem_ds == false && (isMousexemtrangsau(x, y) == 1 || isMousexemtrangtruoc(x, y) == 1)) {
                if (isMousexemtrangsau(x, y) == 1) {
                    if (tranghientaicb < sotrangcb) {
                        tranghientaicb++;
                        sochuyenbayhien = (tranghientaicb - 1) * 10;
                        if (tranghientaicb == sotrangcb) {
                            hienthidschuyenbay(s, sochuyenbayhien, 3);
                        }
                        else {
                            hienthidschuyenbay(s, sochuyenbayhien, 2);
                        }
                    }
                }
                else if (isMousexemtrangtruoc(x, y) == 1) {
                    //tranghientaicb,sotrangcb,sochuyenbayco
                    if (tranghientaicb > 1) {
                        tranghientaicb--;
                        sochuyenbayhien = (tranghientaicb - 1) * 10;
                        hienthidschuyenbay(s, sochuyenbayhien, 2);
                    }
                }

            }
            else if ((TRANG_THAI_TAB == 2 || (TRANG_THAI_TAB == 4 && dangmuab1 == 0 && dangmuab2 == 0 && dang_chon_chuyen_bay == 0 && chon_ghe == 0) || (TRANG_THAI_TAB == 4 && dang_chon_chuyen_bay == 1 && chon_ghe == 0)) && chuyen_trang_tim_kiem == 1 && chuyen_trang_xem_ds == false && (isMousexemtrangsau(x, y) == 1 || isMousexemtrangtruoc(x, y) == 1)) {

                if (isMousexemtrangsau(x, y) == 1) {
                    if (tranghientmp < sotrangtmp) {
                        tranghientmp++;
                        cbtmp = (tranghientmp - 1) * 10;
                        if (tranghientmp == sotrangtmp) {
                            hienthidschuyenbay(tmpcb, cbtmp, 3);
                        }
                        else {
                            hienthidschuyenbay(tmpcb, cbtmp, 2);
                        }
                    }
                }
                else if (isMousexemtrangtruoc(x, y) == 1) {
                    //tranghientaicb,sotrangcb,sochuyenbayco
                    if (tranghientmp > 1) {
                        tranghientmp--;
                        cbtmp = (tranghientmp - 1) * 10;
                        hienthidschuyenbay(tmpcb, cbtmp, 2);
                    }
                }

                //"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
            }
            else if (TRANG_THAI_TAB == 2 && chuyen_trang_tim_kiem == 0 && chuyen_trang_xem_ds==true && (isMousexemtrangsau(x, y) == 1 || isMousexemtrangtruoc(x, y) == 1)) {
                if (isMousexemtrangsau(x, y) == 1) {
                    cout << "dell" << endl;
                    chuyen_trang_xem_ds = true;
                    if (tranghientaixemdsv < sotrangxemdsv) {
                        tranghientaixemdsv++;
                        sophantuhiendsv = (tranghientaixemdsv - 1) * 10;
                        /*cout << sophantuhiendsv << endl << tranghientaixemdsv << endl << sotrangxemdsv << endl;*/
                        if (tranghientaixemdsv == sotrangxemdsv) {
                            hienthidanhsachve(xemds, dsvtmp, 3, sophantuhiendsv, sophantudsv, vitrighe);
                        }
                        else {
                            hienthidanhsachve(xemds, dsvtmp, 2, sophantuhiendsv, sophantudsv, vitrighe);

                        }
                    }
                }
                else if (isMousexemtrangtruoc(x, y) == 1) {
                    //tranghientaicb,sotrangcb,sochuyenbayco
                    if (tranghientaixemdsv > 1) {
                        tranghientaixemdsv--;
                        sophantuhiendsv = (tranghientaixemdsv - 1) * 10;
                        hienthidanhsachve(xemds, dsvtmp, 2, sophantuhiendsv, sophantudsv, vitrighe);
                    }
                }
            }
            //tra trang thai bang 1
            else if (TRANG_THAI_TAB == 2 && chuyen_trang_xem_ds == false && chuyen_trang_tim_kiem == 0 && addchuyenbay == false && suathongtin == false ) {               
                 int sothutu;
                 if (x >= 100 && x <= 1232 && y <= 689 && y >= 289) {
                     sothutu = 0;
                     sothutu = (y - 289) / 40 + 10 * (tranghientaicb - 1);
                     if (sothutu >= sochuyenbayco) {
                         char a[30] = "khong co phan tu de huy";
                         hienthiloi(a);
                     }
                     else {
                         ds duyet = NULL; duyet = s; int dem = 0;
                         while (duyet != NULL) {
                             if (dem == sothutu) {
                                 if (duyet->cb.trangthai == 4) {
                                     char a[130] = "chuyen bay da hoan thanh ko the huy";
                                     hienthiloi(a);
                                     break;
                                 }
                                 else {
                                     duyet->cb.trangthai = 1;
                                     char a[30] = "chuyen bay da huy";
                                     hienthiloi(a);
                                     capnhatdulieu(s);
                                     break;
                                 }
                             }
                             else {
                                 dem++;
                             }
                             duyet = duyet->next;
                         }

                         cleardevice();
                         Screen_Default(TRANG_THAI_TAB);
                         Flight_design();
                         sochuyenbayhien = 0;
                         tranghientaicb = 1;
                         hientrangdau(s, sochuyenbayhien, sochuyenbayco, sotrangcb);

                     }
                 }
                 if (x >= 1232 && x <= 1439 && y <= 689 && y >= 289) {
                     sothutu = 0;
                     sothutu = (y - 289) / 40 + 10 * (tranghientaicb - 1);
                     if (sothutu >= sochuyenbayco) {
                         char a[30] = "khong co phan tu de xem ds";
                         hienthiloi(a);
                         chuyen_trang_xem_ds = false;
                     }
                     else {
                         xemds = laychuyenbay(s, sothutu);
                         int j = 0;
                         dsvtmp = new char* [xemds.sove];
                         vitrighe = new int[xemds.sove];
                         for (int i = 0; i < xemds.sove; i++) {
                             dsvtmp[i] = new char[30];
                             dsvtmp[i][0] = '\0';
                             vitrighe[i] = 0;
                         }
                         for (int i = 0; i < xemds.sove; i++) {
                             if (xemds.danhsachve[i][0] == '\0') {
                                 continue;
                             }
                             else {
                                 sophantudsv++;
                                 vitrighe[j] = i + 1;
                                 STRCPYY(dsvtmp[j], xemds.danhsachve[i]);
                                 j++;
                             }
                         }
                         float c = sophantudsv / 10.0;
                         if (sotrangxemdsv < c) {
                             sotrangxemdsv = (int)c + 1;
                             hienthidanhsachve(xemds, dsvtmp, 2, sophantuhiendsv, sophantudsv, vitrighe);
                             chuyen_trang_xem_ds = true;
                         }
                         else {
                             hienthidanhsachve(xemds, dsvtmp, 3, sophantuhiendsv, sophantudsv, vitrighe);
                             chuyen_trang_xem_ds = true;
                         }
                     }
                 }
            }
            else if (TRANG_THAI_TAB == 2 && chuyen_trang_xem_ds == false && chuyen_trang_tim_kiem == 1 && addchuyenbay == false && suathongtin == false ) {
                int sothutu;
                if (x >= 100 && x <= 1232 && y <= 689 && y >= 289) {
                    sothutu = 0;
                    sothutu = (y - 289) / 40 + 10 * (tranghientmp - 1);
                    if (sothutu >= cbcotmp) {
                        char a[30] = "khong co phan tu de huy";
                        hienthiloi(a);
                    }
                    else {
                        chuyenbay xoa;
                        xoa = laychuyenbay(tmpcb, sothutu);
                        ds duyet = NULL; duyet = s;
                        while (duyet != NULL) {
                            if (strcmp(duyet->cb.macb, xoa.macb) == 0) {
                                if (duyet->cb.trangthai == 4) {
                                    char a[130] = "chuyen bay da hoan thanh ko the huy";
                                    hienthiloi(a);
                                    break;
                                }
                                else {
                                    duyet->cb.trangthai = 1;
                                    char a[30] = "chuyen bay da huy";
                                    hienthiloi(a);
                                    capnhatdulieu(s);
                                    break;
                                }
                            }
                            duyet = duyet->next;
                        }
                        cleardevice();
                        Screen_Default(TRANG_THAI_TAB);
                        Flight_design();
                        sochuyenbayhien = 0;
                        tranghientaicb = 1;
                        hientrangdau(s, sochuyenbayhien, sochuyenbayco, sotrangcb);
                    }
                }
                if (x >= 1232 && x <= 1439 && y <= 689 && y >= 289) {
                    sothutu = 0;
                    sothutu = (y - 289) / 40 + 10 * (tranghientmp - 1);
                    if (sothutu >= cbcotmp) {
                        char a[30] = "khong co phan tu de xem ds";
                        hienthiloi(a);
                        chuyen_trang_xem_ds = false;
                    }
                    else {
                        xemds = laychuyenbay(tmpcb, sothutu);
                        int j = 0;
                        dsvtmp = new char* [xemds.sove];
                        vitrighe = new int[xemds.sove];
                        for (int i = 0; i < xemds.sove; i++) {
                            dsvtmp[i] = new char[30];
                            dsvtmp[i][0] = '\0';
                            vitrighe[i] = 0;
                        }
                        for (int i = 0; i < xemds.sove; i++) {
                            if (xemds.danhsachve[i][0] == '\0') {
                                continue;
                            }
                            else {
                                sophantudsv++;
                                vitrighe[j] = i + 1;
                                STRCPYY(dsvtmp[j], xemds.danhsachve[i]);
                                j++;
                            }
                        }
                        float c = sophantudsv / 10.0;
                        if (sotrangxemdsv < c) {
                            sotrangxemdsv = (int)c + 1;
                            hienthidanhsachve(xemds, dsvtmp, 2, sophantuhiendsv, sophantudsv, vitrighe);
                            chuyen_trang_xem_ds = true;
                        }
                        else {
                            hienthidanhsachve(xemds, dsvtmp, 3, sophantuhiendsv, sophantudsv, vitrighe);
                            chuyen_trang_xem_ds = true;
                        }
                    }
                }

            }
            //sua
            else if (TRANG_THAI_TAB == 2 && addchuyenbay == false && suathongtin && chon_may_bay && sua_cb == 1) {
                int trang_mb_max = ds_mb.n / 10;
                if (isMouseNEXT_PAGE_MB(x, y)) {
                    if (trang_mb_hientai < trang_mb_max) {
                        trang_mb_hientai++;
                        hien_ds_mb(trang_mb_hientai, ds_mb, s);
                    }

                }
                if (isMouseBACK_PAGE_MB(x, y)) {
                    if (trang_mb_hientai > 0) {
                        trang_mb_hientai--;
                        hien_ds_mb(trang_mb_hientai, ds_mb, s);
                    }
                }
                if (x >= 130 && x <= 900 && y >= 190 && y <= 680) {
                    int stt = (y - 190) / 49 + trang_mb_hientai * 10;
                    if (stt < ds_mb.n)
                    {
                        STRCPYY(dlcb[6], ds_mb.nodes[stt]->sohieu);
                        cleardevice();
                        Screen_Default(TRANG_THAI_TAB);
                        hienthemchuyebay();
                        setbkcolor(COLOR(217, 234, 211));
                        outtextxy(448, 337, dlcb[6]);
                        setbkcolor(COLOR(217, 234, 211));
                        outtextxy(450, 235, dlcb[5]);
                        outtextxy(450, 335, dlcb[6]);
                        outtextxy(450, 435, dlcb[7]);
                        char tg[30];
                        outtextxy(450, 535, dlcb[8]);
                        outtextxy(527, 535, dlcb[9]);
                        outtextxy(610, 535, dlcb[10]);
                        outtextxy(703, 535, dlcb[11]);
                        outtextxy(785, 535, dlcb[12]);
                        suathongtin = false;
                        chon_may_bay = false; addchuyenbay = true; TRANG_THAI_TAB = 2;
                        trang_mb_hientai = 0;
                    }
                }

            }
            else if (TRANG_THAI_TAB == 2 && sua_cb == 1 && (isMouseaddidflight(x, y) == 1 || isMouseaddmamaybay(x, y) == 1 || isMouseback(x, y) == 1 || isMouseaddnoiden(x, y) == 1 || isMouseaddday(x, y) == 1 || isMouseaddthang(x, y) == 1 || isMouseaddyear(x, y) == 1 || isMouseaddgio(x, y) == 1 || isMouseaddphut(x, y) == 1 || isMousetimmaybay(x, y) == 1 || isMousesave(x, y) == 1 || isMousechonmaybay(x, y) == 1)) {

                if (isMouseback(x, y) == 1) {
                    for (int i = 0; i < 13; i++) {
                        dlcb[i][0] = '\0';
                    }
                    sochuyenbayco = 0;
                    s = NULL;
                    tmpcb = NULL;
                    docdulieu(s, sochuyenbayco);
                    tmpcb = NULL; addchuyenbay = false; suathongtin = false; chuyen_trang_xem_ds = false;
                    chuyen_trang_tim_kiem = 0;
                    TRANG_THAI_TAB = 2;
                    sochuyenbayhien = 0;
                    sotrangcb = 1;
                    capnhapchuyenbaycotmp = sochuyenbayco;
                    cleardevice();
                    Screen_Default(TRANG_THAI_TAB);
                    Flight_design();
                    hientrangdau(s, sochuyenbayhien, sochuyenbayco, sotrangcb);
                    muaticket = false; sua_cb = 0;
                }
                else if (isMouseaddidflight(x, y) == 1 || isMouseaddmamaybay(x, y) == 1 || isMouseaddnoiden(x, y) == 1 || isMouseaddday(x, y) == 1 || isMouseaddthang(x, y) == 1 || isMouseaddyear(x, y) == 1 || isMouseaddgio(x, y) == 1 || isMouseaddphut(x, y) == 1 || isMousetimmaybay(x, y) == 1 || isMousesave(x, y) == 1 || isMousechonmaybay(x, y) == 1) {
                    char tmp[8][30];
                    for (int i = 0; i < 7; i++) {
                        tmp[i][0] = '\0';
                    }
                    int b = 0;
                    if (isMousechonmaybay(x, y) == 1) {
                        cleardevice();
                        Screen_Default(TRANG_THAI_TAB);
                        Planes_design();
                        chon_may_bay = true;
                        hien_ds_mb(trang_mb_hientai, ds_mb, s);
                    }
                    else if (isMouseaddidflight(x, y) == 1) {

                        char a[30] = "ma chuyen bay khong the sua";
                        hienthiloi(a);

                    }
                    else if (isMouseaddmamaybay(x, y) == 1) {
                        nhapdulieu(445, 335, 440, 1046, 320, 363, tmp[1], 12, 2);
                        STRCPYY(dlcb[6], tmp[1]);

                    }
                    else if (isMouseaddnoiden(x, y) == 1) {
                        nhapdulieu(445, 435, 440, 1046, 420, 466, tmp[2], 30, 1);
                        STRCPYY(dlcb[7], tmp[2]);
                    }
                    else if (isMouseaddday(x, y) == 1) {
                        do {
                            b = 0;
                            char a[30] = "nhap >0 va <30";
                            nhapdulieu(445, 535, 440, 513, 519, 563, tmp[3], 2, 3);
                            chuyencharsint(tmp[3], b);
                            if (b > 31 || b <= 0) {
                                hienthiloi(a);
                            }
                        } while (b > 31 || b <= 0);
                        STRCPYY(dlcb[8], tmp[3]);

                    }
                    else if (isMouseaddthang(x, y) == 1) {
                        do {
                            b = 0;
                            char a[30] = "nh?p >0 và <12";
                            nhapdulieu(530, 535, 526, 596, 519, 563, tmp[4], 2, 3);
                            chuyencharsint(tmp[4], b);

                            if (b > 12 || b <= 0) {
                                hienthiloi(a);
                            }
                        } while (b > 12 || b <= 0);

                        STRCPYY(dlcb[9], tmp[4]);
                    }
                    else if (isMouseaddyear(x, y) == 1) {
                        do {
                            b = 0;
                            char a[30] = "nam >=2024";
                            nhapdulieu(613, 535, 610, 678, 519, 563, tmp[5], 4, 3);
                            chuyencharsint(tmp[5], b);
                            if (b < 2024) {
                                hienthiloi(a);
                            }
                        } while (b < 2024);
                        STRCPYY(dlcb[10], tmp[5]);
                    }
                    else if (isMouseaddgio(x, y) == 1) {
                        do {
                            b = 0;
                            char a[30] = "nhap >=0 va <24";
                            nhapdulieu(706, 535, 703, 771, 519, 563, tmp[6], 2, 3);
                            chuyencharsint(tmp[6], b);
                            if (b > 24 || b < 0) {
                                hienthiloi(a);
                            }
                        } while (b > 24 || b < 0);
                        STRCPYY(dlcb[11], tmp[6]);
                    }
                    else if (isMouseaddphut(x, y) == 1) {
                        do {
                            b = 0;
                            char a[30] = "nhap >0 va <60";
                            nhapdulieu(788, 535, 785, 854, 519, 563, tmp[7], 2, 3);
                            chuyencharsint(tmp[7], b);
                            if (b > 60 || b < 0) {
                                hienthiloi(a);
                            }
                        } while (b > 60 || b < 0);
                        STRCPYY(dlcb[12], tmp[7]);
                    }
                    else if (isMousesave(x, y) == 1) {
                        int demptr = 0, b;
                        for (int i = 5; i < 13; i++) {
                            if (dlcb[i][0] == '\0') {
                                demptr++;
                            }
                        }
                        if (demptr == 0) {
                            ds duyet; duyet = s; int demloi = -1;
                            int tmptg[7], tght[5];
                            for (int i = 0; i < 7; i++) {
                                tmptg[i] = 0;
                                if (i < 5) {
                                    tght[i] = 0;
                                }
                            }
                            STRCPYY(tmpsua.sohieu, dlcb[6]);
                            STRCPYY(tmpsua.sanbay, dlcb[7]);
                            b = 0;
                            chuyencharsint(dlcb[8], b); tmpsua.tg.ngay = b; b = 0;
                            chuyencharsint(dlcb[9], b); tmpsua.tg.thang = b; b = 0;
                            chuyencharsint(dlcb[10], b); tmpsua.tg.nam = b; b = 0;
                            chuyencharsint(dlcb[11], b); tmpsua.tg.gio = b; b = 0;
                            chuyencharsint(dlcb[12], b); tmpsua.tg.phut = b; b = 0;
                            lay_tg_hien_tai(tght[0], tght[1], tght[2], tght[3], tght[4]);
                            chuyencharsint(dlcb[11], tmptg[6]);
                            chuyencharsint(dlcb[8], tmptg[0]); chuyencharsint(dlcb[9], tmptg[1]); chuyencharsint(dlcb[10], tmptg[2]); chuyencharsint(dlcb[11], tmptg[3]);
                            if (tght[2] > tmptg[2] || (tght[2] == tmptg[2] && tght[1] > tmptg[1]) || (tght[2] == tmptg[2] && tght[1] == tmptg[1] && tght[0] > tmptg[0]) || (tght[2] == tmptg[2] && tght[1] == tmptg[1] && tght[0] == tmptg[0] && tght[3] - tmptg[3] >= 0)) {
                                char loi[100] = "thoi gian phai sau thoi gian hien tai";
                                hienthiloi(loi);
                            }
                            else {
                                ds duyet; duyet = s; int demloii = 0;
                                for (; duyet != NULL; duyet = duyet->next) {
                                    if (strcmp(duyet->cb.sohieu, dlcb[6]) == 0) {
                                        if (tmptg[0] == duyet->cb.tg.ngay && tmptg[1] == duyet->cb.tg.thang && tmptg[2] == duyet->cb.tg.nam) {
                                            if (abs(duyet->cb.tg.gio - tmptg[3]) <= 3) {
                                                demloi++;
                                            }
                                        }
                                    }
                                }
                                if (demloii > 1) {
                                    char a[100] = "may bay da co chuyen bay trong tg nay";
                                    hienthiloi(a);

                                }
                                else {
                                    tmpsua.trangthai = 2; int soday = 0, sodong = 0;
                                    soday = ds_mb.nodes[timkiem(ds_mb, tmpsua.sohieu)]->soday;
                                    sodong = ds_mb.nodes[timkiem(ds_mb, tmpsua.sohieu)]->sodong;
                                    tmpsua.sove = soday * sodong;
                                    tmpsua.danhsachve = new char* [tmpsua.sove];
                                    for (int i = 0; i < tmpsua.sove; i++) {
                                        tmpsua.danhsachve[i] = new char[30];
                                        tmpsua.danhsachve[i][0] = '\0';

                                    }
                                    sua_thong_tin_cb(s, tmpsua);
                                    capnhatdulieu(s);
                                    char tc[30] = "da sua thanh cong";
                                    hienthiloi(tc);
                                }
                            }







                        }
                    }
                    else {
                        char l[30] = "ban can nhap du thong tin";
                        hienthiloi(l);
                    }

                }

            }




            else if (TRANG_THAI_TAB == 3) {//hanhkhach
                char dl1[30], dl2[30], dl3[30];
                dl1[0] = '\0'; dl2[0] = '\0'; dl3[0] = '\0';
                if (isMouseSearchIdcustomer(x, y)) {
                    nhapdulieu(205, 140, 201, 399, 131, 169, dl1, 12, 3);

                    STRCPYY(Search[0], dl1);
                    Search_hanh_khach(Search[0], Search[1], Search[2], danh_sach_HK_O_tren_man_hinh, so_luong_hanh_khach_tim_thay, trang_curr, trang_max,xuat_search,cout_for_search);
                    PRINTF_SEARCH_CUSTOMER(so_luong_hanh_khach_tim_thay, trang_curr, trang_max, xuat_search, cout_for_search);
                    da_search_hk = 1;
                    trang_hien_tai = 0;
                }
                else if (isMouseSearchLastNamecustomer(x, y)) {
                    nhapdulieu(502, 140, 501, 699, 131, 169, dl2, 30, 4);
                    STRCPYY(Search[1], dl2);
                    Search_hanh_khach(Search[0], Search[1], Search[2], danh_sach_HK_O_tren_man_hinh, so_luong_hanh_khach_tim_thay, trang_curr, trang_max, xuat_search, cout_for_search);
                    PRINTF_SEARCH_CUSTOMER(so_luong_hanh_khach_tim_thay, trang_curr, trang_max, xuat_search, cout_for_search);                    da_search_hk = 1;
                    trang_hien_tai = 0;
                }
                else if (isMouseSearchFirstNameCustomer(x, y)) {
                    nhapdulieu(802, 140, 801, 949, 131, 169, dl3, 30, 5);
                    STRCPYY(Search[2], dl3);
                    Search_hanh_khach(Search[0], Search[1], Search[2], danh_sach_HK_O_tren_man_hinh, so_luong_hanh_khach_tim_thay, trang_curr, trang_max, xuat_search, cout_for_search);
                    PRINTF_SEARCH_CUSTOMER(so_luong_hanh_khach_tim_thay, trang_curr, trang_max, xuat_search, cout_for_search);                    da_search_hk = 1;
                    trang_hien_tai = 0;
                }
                else if (da_search_hk == 0 && isMouseCHUYEN_TRANG_SANG_PHAI(x, y) && trang_hien_tai < so_trang_hanh_khach) {
                    trang_hien_tai++;
                    cleardevice();
                    Screen_Default(TRANG_THAI_TAB);
                    Customer_design();
                    Hien_thi_hanh_khach(trang_hien_tai);
                }
                else if (da_search_hk == 0 && isMouseCHUYEN_TRANG_SANG_TRAI(x, y) && trang_hien_tai > 0) {
                    trang_hien_tai--;
                    cleardevice();
                    Screen_Default(TRANG_THAI_TAB);
                    Customer_design();
                    Hien_thi_hanh_khach(trang_hien_tai);
                }
                else if (da_search_hk == 1 && isMouseCHUYEN_TRANG_SANG_PHAI(x, y) && trang_curr < trang_max) {
                    trang_curr++;
                    PRINTF_SEARCH_CUSTOMER(so_luong_hanh_khach_tim_thay, trang_curr, trang_max, xuat_search, cout_for_search);
                }
                else if (da_search_hk == 1 && isMouseCHUYEN_TRANG_SANG_TRAI(x, y) && trang_curr > 0) {
                    trang_curr--;
                    PRINTF_SEARCH_CUSTOMER(so_luong_hanh_khach_tim_thay, trang_curr, trang_max, xuat_search, cout_for_search);
                }
                
            }
            //chuyen qua buoc 1:
            else if (TRANG_THAI_TAB == 4 && dangmuab1 == 0 && dangmuab2 == 0 && dang_chon_chuyen_bay == 0 && chon_ghe == 0) {
                if (isMouseaddFlight(x, y)) {

                    cleardevice();
                    Screen_Default(TRANG_THAI_TAB);
                    Man_hinh_mua_ticket_b1();
                    dangmuab1 = 1;
                    dangmuab2 = 0;
                    dang_chon_chuyen_bay = 0;
                    chon_ghe = 0;
                    chon_ghe = 0;
                }
            }
            //chuc nang buoc 1 va chuyen qua buoc 2
            else if (dangmuab1 == 1 && TRANG_THAI_TAB == 4) {
                char dl1[30]; dl1[0] = '\0'; trung_cmnd = 0;
                if (isMouseNhapCMND_MUA_VE(x, y)) {
                    setcolor(0);
                    nhapdulieu(405, 305, 400, 1000, 290, 340, dl1, 12, 3);
                    if (dl1[11] == '\0') {
                        hienthiloi(const_cast<char*>("vui long nhap du 12 so"));
                    }
                    else
                    {
                        STRCPYY(CMND, dl1);
                        da_nhap_CMND = 1;
                    }
                }
                if (isMouseNEXT(x, y))
                {
                    if (da_nhap_CMND == 1)
                    {
                        dangmuab2 = 1;
                        dangmuab1 = 0;
                        dang_chon_chuyen_bay = 0;
                        chon_ghe = 0;
                    }
                    else if (da_nhap_CMND == 0) {
                        hienthiloi(const_cast<char*>("VUI LONG NHAP SO CCCD"));
                    }
                    HanhKhach old = ds_hk.search(CMND);

                    if (old.soCMND[0] != '\0' && da_nhap_CMND == 1) {
                        //hien thi hk bi trung
                        trung_cmnd = 1;
                        Man_hinh_in4_hk_old(old);
                        da_nhap_CMND = 0;
                    }
                    else if (old.soCMND[0] == '\0' && da_nhap_CMND == 1)
                    {
                        trung_cmnd = 0;
                        Man_hinh_mua_ticket_b2();
                        da_nhap_CMND = 0;
                    }

                }

            }
            else if (dangmuab2 == 1 && TRANG_THAI_TAB == 4 && trung_cmnd == 0 && dangmuab1 == 0) {
                //new hk
                //Man_hinh_mua_ticket_b2();
                char dl1[60], dl2[30]; dl1[0] = '\0'; dl2[0] = '\0';
                bool dl3;//dl3 =0 nam =1 nu
                if (isMouseNhapHo_mua_ve(x, y) && dangmuab2) {
                    nhapdulieu(414, 235, 409, 1009, 220, 265, dl1, 60, 4);
                    STRCPYY(ho, dl1);
                }
                if (isMouseNhapTen_mua_ve(x, y) && dangmuab2) {
                    nhapdulieu(414, 335, 409, 1009, 320, 365, dl2, 30, 5);
                    STRCPYY(ten, dl2);
                }
                if (isMouseLaNam(x, y) && dangmuab2) {
                    dl3 = 0;
                    phai = dl3;
                    da_chon_phai = 1;
                    ve_hinh_vuong(374 + 35, 420, 374 + 35 + 200, 465, COLOR(168, 205, 159), 0, const_cast<char*>("nam"), 1, 0);
                    ve_hinh_vuong(600 + 35, 420, 374 + 35 + 430, 465, COLOR(217, 234, 211), 0, const_cast<char*>("nu"), 1, COLOR(179, 164, 146));
                }
                if (isMouseLaNu(x, y) && dangmuab2) {
                    dl3 = 1;
                    phai = dl3;
                    da_chon_phai = 1;
                    ve_hinh_vuong(600 + 35, 420, 374 + 35 + 430, 465, COLOR(168, 205, 159), 0, const_cast<char*>("nu"), 1, 0);
                    ve_hinh_vuong(374 + 35, 420, 374 + 35 + 200, 465, COLOR(217, 234, 211), 0, const_cast<char*>("nam"), 1, COLOR(179, 164, 146));
                }
                if (isMouseSearchChuyenBay_mua_ve(x, y) && dangmuab2) {
                    if (ho[0] == '\0' || ten[0] == '\0' || da_chon_phai == 0) {
                        da_nhap_du_in4 = 0;
                        hienthiloi(const_cast<char*>("cccc"));
                    }
                    else {
                        da_nhap_du_in4 = 1;
                    }
                    //chuyen qua buoc 3
                    if (da_nhap_du_in4 == 1)
                    {
                        cap_nhat_dshk_sau_khi_NHAPIN4_muaTIKCET(CMND, ho, ten, phai);
                        ho[0] = '\0'; ten[0] = '\0';
                        da_chon_phai = 0;
                        da_nhap_CMND = 0;
                        dang_chon_chuyen_bay = 1;
                        dangmuab2 = 0;
                        dangmuab1 = 0;
                        chon_ghe = 0;
                        cleardevice();
                        Screen_Default(TRANG_THAI_TAB);
                        Man_hinh_mua_ticket_b3();
                        Ticket_design();
                        sochuyenbayco = 0;
                        s = nullptr;
                        docdulieu(s, sochuyenbayco);
                        tmpcb = s; addchuyenbay = false; suachuyenbay = false;
                        chuyen_trang_tim_kiem = 0;
                        sochuyenbayhien = 0;
                        sotrangcb = 1;
                        capnhapchuyenbaycotmp = sochuyenbayco;
                        hientrangdau(s, sochuyenbayhien, sochuyenbayco, sotrangcb);
                    }
                }
                if (isMouse_dang_mua_ve_back_ve_chon_cb(x, y)) {
                    dangmuab1 = 1;
                    dangmuab2 = 0;
                    dang_chon_chuyen_bay = 0;
                    chon_ghe = 0;
                    trung_cmnd == 0;
                    cleardevice();
                    Screen_Default(TRANG_THAI_TAB);
                    Man_hinh_mua_ticket_b1();

                }
            }
            else if (trung_cmnd == 1 && TRANG_THAI_TAB == 4 && dangmuab2 == 1) {
                if (isMouseSearchChuyenBay_mua_ve(x, y) && dangmuab2) {
                    ho[0] = '\0'; ten[0] = '\0';
                    da_chon_phai = 0;
                    da_nhap_CMND = 0;
                    dang_chon_chuyen_bay = 1;
                    dangmuab2 = 0;
                    dangmuab1 = 0;
                    chon_ghe = 0;
                    cleardevice();
                    Screen_Default(TRANG_THAI_TAB);
                    Man_hinh_mua_ticket_b3();
                    for (int i = 0; i < 13; i++) {
                        dlcb[i][0] = '\0';
                    }
                    tranghientaicb = 1;
                    sochuyenbayco = 0;
                    s = NULL;
                    docdulieu(s, sochuyenbayco);
                    tmpcb = NULL; addchuyenbay = false; suathongtin = false; chuyen_trang_xem_ds = false;
                    chuyen_trang_tim_kiem = 0;
                    sochuyenbayhien = 0;
                    sotrangcb = 1;
                    muaticket = false;
                    capnhapchuyenbaycotmp = sochuyenbayco;
                    hientrangdau(s, sochuyenbayhien, sochuyenbayco, sotrangcb);
                }
                else if (isMouse_dang_mua_ve_back_ve_chon_cb(x, y)) {
                    dangmuab1 = 1;
                    dangmuab2 = 0;
                    dang_chon_chuyen_bay = 0;
                    chon_ghe = 0;
                    cleardevice();
                    Screen_Default(TRANG_THAI_TAB);
                    trung_cmnd == 0;
                    Man_hinh_mua_ticket_b1();

                }
            }
            //buoc 3
            else if (TRANG_THAI_TAB == 4 && chon_ghe == 1 && dang_chon_chuyen_bay == 0) {
                char so_ghe[30];
                so_ghe[0] = '\0';

                if (isMouseChonGhe(x, y) == 1) {
                    nhapdulieu(501, 140, 500, 600, 131, 169, so_ghe, 4, 2);
                    if (check_so_ghe(ds_mb.nodes[timkiem(ds_mb, tmpsua.sohieu)]->soday, ds_mb.nodes[timkiem(ds_mb, tmpsua.sohieu)]->sodong, so_ghe) == 1) {
                        int ghe = 0;
                        ghe = (so_ghe[0] - 'A') * ds_mb.nodes[timkiem(ds_mb, tmpsua.sohieu)]->sodong;
                        ghe += atoi(&so_ghe[1]) - 1;
                        them_hanh_khach(s, tmpsua.macb, CMND, ghe);
                        capnhatdulieu(s);
                        Man_hinh_mua_ticket_b4(tmpsua, ds_mb.nodes[timkiem(ds_mb, tmpsua.sohieu)]->soday, ds_mb.nodes[timkiem(ds_mb, tmpsua.sohieu)]->sodong);
                    }
                    else {
                        hienthiloi(const_cast<char*>("So ghe khong hop le"));
                        ve_hinh_vuong(500, 130, 600, 170, COLOR(217, 234, 211), 0, const_cast<char*>("nhap so ghe"), 1, COLOR(179, 164, 146));
                    }
                }
                else if (isMouse_dang_mua_ve_back_ve_chon_cb(x, y)) {
                    ho[0] = '\0'; ten[0] = '\0';
                    da_chon_phai = 0;
                    da_nhap_CMND = 0;
                    dang_chon_chuyen_bay = 1;
                    dangmuab2 = 0;
                    dangmuab1 = 0;
                    chon_ghe = 0;
                    cleardevice();
                    Screen_Default(TRANG_THAI_TAB);
                    Man_hinh_mua_ticket_b3();
                    for (int i = 0; i < 13; i++) {
                        dlcb[i][0] = '\0';
                    }
                    sochuyenbayco = 0;
                    s = NULL;
                    docdulieu(s, sochuyenbayco);
                    tmpcb = NULL; addchuyenbay = false; suathongtin = false; chuyen_trang_xem_ds = false;
                    chuyen_trang_tim_kiem = 0;
                    sochuyenbayhien = 0;
                    sotrangcb = 1;
                    muaticket = false;
                    capnhapchuyenbaycotmp = sochuyenbayco;
                    hientrangdau(s, sochuyenbayhien, sochuyenbayco, sotrangcb);
                }
            }
            //"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
        }
        //chuot phai
        else if (ismouseclick(WM_RBUTTONDOWN)) {
            /* if (TRANG_THAI_TAB == 3)
{
    if (xxem > 100 && xxem < 1440 && yxem > 290 && yxem < 690) {
        if (da_search_hk == 1)
        {
            int so_trang_hk_timthay = so_luong_hanh_khach_tim_thay / 10;
            if (trang_hien_tai < so_trang_hk_timthay && TRANG_THAI_TAB != 3.1) {

                int number_hanh_khach_can_xem = (yxem - 290) / 40 + 1;

                TRANG_THAI_TAB = 3.1;
                int cc = danh_sach_HK_O_tren_man_hinh[number_hanh_khach_can_xem] / 10;
                xem_thong_tin_hanh_khach(danh_sach_HK_O_tren_man_hinh[number_hanh_khach_can_xem] % 10, cc);
            }
            else if (trang_hien_tai == so_trang_hk_timthay && TRANG_THAI_TAB != 3.1) {
                cout << so_luong_hanh_khach_tim_thay;
                int tmp = so_luong_hanh_khach_tim_thay % 10;
                int number_hanh_khach_can_xem = (yxem - 290) / 40;
                int cc = danh_sach_HK_O_tren_man_hinh[number_hanh_khach_can_xem] / 10;
                if (tmp > number_hanh_khach_can_xem) {
                    TRANG_THAI_TAB = 3.1;
                    xem_thong_tin_hanh_khach(danh_sach_HK_O_tren_man_hinh[number_hanh_khach_can_xem] % 10, cc);
                }

            }
        }
        else if (da_search_hk == 0) {
            cout << "adu";
            if (trang_hien_tai < so_trang_hanh_khach && TRANG_THAI_TAB != 3.1) {
                int number_hanh_khach_can_xem = (yxem - 290) / 40 + 1;
                TRANG_THAI_TAB = 3.1;
                xem_thong_tin_hanh_khach(number_hanh_khach_can_xem, trang_hien_tai);
            }
            else if (trang_hien_tai == so_trang_hanh_khach && TRANG_THAI_TAB != 3.1) {
                int tmp = so_luong_hanh_khach % 10;
                int number_hanh_khach_can_xem = (yxem - 290) / 40 + 1;
                if (tmp >= number_hanh_khach_can_xem) {
                    TRANG_THAI_TAB = 3.1;
                    xem_thong_tin_hanh_khach(number_hanh_khach_can_xem, trang_hien_tai);
                }

            }
        }
    }

}*/
            int x = mousex();
            int y = mousey();
            clearmouseclick(WM_RBUTTONDOWN);
            if (TRANG_THAI_TAB == 1 && xem_thong_ke_mb == 1 && da_search_mb == 0) {
                if (x >= 130 && x <= 900 && y >= 190 && y <= 680) {
                    int stt = (y - 190) / 49 + trang_mb_hientai * 10;
                    ds duyet = NULL; duyet = s;
                    sua_thong_tin_mb(stt, ds_mb, trang_mb_hientai, s);
                }
            }
            if (TRANG_THAI_TAB == 2 && chuyen_trang_tim_kiem == 0 && addchuyenbay == false && suathongtin == false ) {
                if (x >= 100 && x <= 1232 && y <= 689 && y >= 289) {
                    vitrisua = 0;
                    vitrisua = (y - 289) / 40 + 10 * (tranghientaicb - 1);
                    if (vitrisua >= sochuyenbayco) {
                        char a[30] = "khong co phan tu de sua";
                        hienthiloi(a);
                        suathongtin = false;

                    }
                    else {
                        int demvedadat = 0;
                        tmpsua = laychuyenbay(s, vitrisua);
                        for (int i = 0; i < tmpsua.sove; i++) {
                            if (tmpsua.danhsachve[i][0] != '\0') {
                                demvedadat++;
                            }
                        }
                        if (demvedadat != 0) {
                            char a[50] = "chuyen bay da co nguoi dat ko the sua";
                            hienthiloi(a);
                            suathongtin = false;
                        }
                        else {
                            if (tmpsua.trangthai == 1) {
                                char a[30] = "chuyen bay da huy ko the sua";
                                hienthiloi(a);
                            }
                            else if (tmpsua.trangthai == 4) {
                                char a[50] = "chuyen bay da hoan thanh ko the sua";
                                hienthiloi(a);
                            }
                            else {
                                cleardevice();
                                hienthemchuyebay();
                                setbkcolor(COLOR(217, 234, 211));
                                outtextxy(450, 235, tmpsua.macb); STRCPYY(dlcb[5], tmpsua.macb);
                                outtextxy(450, 335, tmpsua.sohieu); STRCPYY(dlcb[6], tmpsua.sohieu);
                                outtextxy(450, 435, tmpsua.sanbay); STRCPYY(dlcb[7], tmpsua.sanbay);
                                char tg[30];
                                chuyenintschar(tg, tmpsua.tg.ngay); outtextxy(450, 535, tg); STRCPYY(dlcb[8], tg);
                                chuyenintschar(tg, tmpsua.tg.thang); outtextxy(527, 535, tg); STRCPYY(dlcb[9], tg);
                                chuyenintschar(tg, tmpsua.tg.nam); outtextxy(610, 535, tg); STRCPYY(dlcb[10], tg);
                                chuyenintschar(tg, tmpsua.tg.gio); outtextxy(703, 535, tg); STRCPYY(dlcb[11], tg);
                                chuyenintschar(tg, tmpsua.tg.phut); outtextxy(785, 535, tg); STRCPYY(dlcb[12], tg);
                                suathongtin = true;
                                sua_cb = 1;
                            }
                        }
                    }
                }
               

            }
            else if (TRANG_THAI_TAB == 2 && chuyen_trang_tim_kiem == 1 && addchuyenbay == false && suathongtin == false ) {
                if (x >= 100 && x <= 1232 && y <= 689 && y >= 289) {
                    vitrisua = 0;
                    vitrisua = (y - 289) / 40 + 10 * (tranghientmp - 1);
                    if (vitrisua >= cbcotmp) {
                        char a[30] = "khong co phan tu de sua";
                        hienthiloi(a);
                        suathongtin = false;
                    }
                    else {
                        int demvedadat = 0;
                        tmpsua = laychuyenbay(tmpcb, vitrisua);
                        for (int i = 0; i < tmpsua.sove; i++) {
                            if (tmpsua.danhsachve[i][0] != '\0') {
                                demvedadat++;
                            }
                        }
                        if (demvedadat != 0) {
                            char a[50] = "chuyen bay da co nguoi dat ko the sua";
                            hienthiloi(a);
                            suathongtin = false;
                        }
                        else {
                            if (tmpsua.trangthai == 1) {
                                char a[30] = "chuyen bay da huy ko the sua";
                                hienthiloi(a);
                            }
                            else if (tmpsua.trangthai == 4) {
                                char a[50] = "chuyen bay da hoan thanh ko the sua";
                                hienthiloi(a);
                            }
                            else {
                                cleardevice();
                                hienthemchuyebay();
                                setbkcolor(COLOR(217, 234, 211));
                                outtextxy(450, 235, tmpsua.macb); STRCPYY(dlcb[5], tmpsua.macb);
                                outtextxy(450, 335, tmpsua.sohieu); STRCPYY(dlcb[6], tmpsua.sohieu);
                                outtextxy(450, 435, tmpsua.sanbay); STRCPYY(dlcb[7], tmpsua.sanbay);
                                char tg[30];
                                chuyenintschar(tg, tmpsua.tg.ngay); outtextxy(450, 535, tg); STRCPYY(dlcb[8], tg);
                                chuyenintschar(tg, tmpsua.tg.thang); outtextxy(527, 535, tg); STRCPYY(dlcb[9], tg);
                                chuyenintschar(tg, tmpsua.tg.nam); outtextxy(610, 535, tg); STRCPYY(dlcb[10], tg);
                                chuyenintschar(tg, tmpsua.tg.gio); outtextxy(703, 535, tg); STRCPYY(dlcb[11], tg);
                                chuyenintschar(tg, tmpsua.tg.phut); outtextxy(785, 535, tg); STRCPYY(dlcb[12], tg);
                                suathongtin = true;
                                sua_cb = 1;
                            }
                        }
                    }
                }
                

            }
            //chuot phai de tim ghe    
            else if (((TRANG_THAI_TAB == 4 && dang_chon_chuyen_bay == 1 && chon_ghe == 0)) && chuyen_trang_tim_kiem == 0 && addchuyenbay == false && suathongtin == false && (isMousechuyenbay1(x, y) == 1 || isMousechuyenbay2(x, y) == 1 || isMousechuyenbay3(x, y) == 1 || isMousechuyenbay4(x, y) == 1 || isMousechuyenbay5(x, y) == 1 || isMousechuyenbay6(x, y) == 1 || isMousechuyenbay7(x, y) == 1 || isMousechuyenbay8(x, y) == 1 || isMousechuyenbay9(x, y) == 1 || isMousechuyenbay10(x, y) == 1)) {
                if (isMousechuyenbay1(x, y) == 1) {
                    vitrisua = 0;
                    vitrisua = 0 + 10 * (tranghientaicb - 1);
                    click_r_de_chon_ghe_chua_search(vitrisua, suathongtin, chon_ghe, dang_chon_chuyen_bay, tmpsua, sochuyenbayco);
                }
                else if (isMousechuyenbay2(x, y) == 1) {
                    vitrisua = 0;
                    vitrisua = 1 + 10 * (tranghientaicb - 1);
                    click_r_de_chon_ghe_chua_search(vitrisua, suathongtin, chon_ghe, dang_chon_chuyen_bay, tmpsua, sochuyenbayco);
                }
                else if (isMousechuyenbay3(x, y) == 1) {
                    vitrisua = 0;
                    vitrisua = 2 + 10 * (tranghientaicb - 1);
                    click_r_de_chon_ghe_chua_search(vitrisua, suathongtin, chon_ghe, dang_chon_chuyen_bay, tmpsua, sochuyenbayco);
                }
                else if (isMousechuyenbay4(x, y) == 1) {
                    vitrisua = 0;
                    vitrisua = 3 + 10 * (tranghientaicb - 1);
                    click_r_de_chon_ghe_chua_search(vitrisua, suathongtin, chon_ghe, dang_chon_chuyen_bay, tmpsua, sochuyenbayco);
                }
                else if (isMousechuyenbay5(x, y) == 1) {
                    vitrisua = 0;
                    vitrisua = 4 + 10 * (tranghientaicb - 1);
                    click_r_de_chon_ghe_chua_search(vitrisua, suathongtin, chon_ghe, dang_chon_chuyen_bay, tmpsua, sochuyenbayco);
                }
                else if (isMousechuyenbay6(x, y) == 1) {
                    vitrisua = 0;
                    vitrisua = 5 + 10 * (tranghientaicb - 1);
                    click_r_de_chon_ghe_chua_search(vitrisua, suathongtin, chon_ghe, dang_chon_chuyen_bay, tmpsua, sochuyenbayco);
                }
                else if (isMousechuyenbay7(x, y) == 1) {
                    vitrisua = 0;
                    vitrisua = 6 + 10 * (tranghientaicb - 1);
                    click_r_de_chon_ghe_chua_search(vitrisua, suathongtin, chon_ghe, dang_chon_chuyen_bay, tmpsua, sochuyenbayco);
                }
                else if (isMousechuyenbay8(x, y) == 1) {
                    vitrisua = 0;
                    vitrisua = 7 + 10 * (tranghientaicb - 1);
                    click_r_de_chon_ghe_chua_search(vitrisua, suathongtin, chon_ghe, dang_chon_chuyen_bay, tmpsua, sochuyenbayco);
                }
                else if (isMousechuyenbay9(x, y) == 1) {
                    vitrisua = 0;
                    vitrisua = 8 + 10 * (tranghientaicb - 1);
                    click_r_de_chon_ghe_chua_search(vitrisua, suathongtin, chon_ghe, dang_chon_chuyen_bay, tmpsua, sochuyenbayco);
                }
                else if (isMousechuyenbay10(x, y) == 1) {
                    vitrisua = 0;
                    vitrisua = 9 + 10 * (tranghientaicb - 1);
                    click_r_de_chon_ghe_chua_search(vitrisua, suathongtin, chon_ghe, dang_chon_chuyen_bay, tmpsua, sochuyenbayco);
                }

            }
            else if (((TRANG_THAI_TAB == 4 && dang_chon_chuyen_bay == 1 && chon_ghe == 0)) && chuyen_trang_tim_kiem == 1 && addchuyenbay == false && suathongtin == false && (isMousechuyenbay1(x, y) == 1 || isMousechuyenbay2(x, y) == 1 || isMousechuyenbay3(x, y) == 1 || isMousechuyenbay4(x, y) == 1 || isMousechuyenbay5(x, y) == 1 || isMousechuyenbay6(x, y) == 1 || isMousechuyenbay7(x, y) == 1 || isMousechuyenbay8(x, y) == 1 || isMousechuyenbay9(x, y) == 1 || isMousechuyenbay10(x, y) == 1)) {
                if (isMousechuyenbay1(x, y) == 1) {
                    vitrisua = 0;
                    vitrisua = 0 + 10 * (tranghientmp - 1);
                    click_r_de_chon_ghe_da_search(vitrisua, suathongtin, chon_ghe, dang_chon_chuyen_bay, cbcotmp, tmpsua, tmpcb);
                }
                else if (isMousechuyenbay2(x, y) == 1) {
                    vitrisua = 0;
                    vitrisua = 1 + 10 * (tranghientmp - 1);
                    click_r_de_chon_ghe_da_search(vitrisua, suathongtin, chon_ghe, dang_chon_chuyen_bay, cbcotmp, tmpsua, tmpcb);

                }
                else if (isMousechuyenbay3(x, y) == 1) {
                    vitrisua = 0;
                    vitrisua = 2 + 10 * (tranghientmp - 1);
                    click_r_de_chon_ghe_da_search(vitrisua, suathongtin, chon_ghe, dang_chon_chuyen_bay, cbcotmp, tmpsua, tmpcb);


                }
                else if (isMousechuyenbay4(x, y) == 1) {
                    vitrisua = 0;
                    vitrisua = 3 + 10 * (tranghientmp - 1);
                    click_r_de_chon_ghe_da_search(vitrisua, suathongtin, chon_ghe, dang_chon_chuyen_bay, cbcotmp, tmpsua, tmpcb);

                }
                else if (isMousechuyenbay5(x, y) == 1) {
                    vitrisua = 0;
                    vitrisua = 4 + 10 * (tranghientmp - 1);
                    click_r_de_chon_ghe_da_search(vitrisua, suathongtin, chon_ghe, dang_chon_chuyen_bay, cbcotmp, tmpsua, tmpcb);

                }
                else if (isMousechuyenbay6(x, y) == 1) {
                    vitrisua = 0;
                    vitrisua = 5 + 10 * (tranghientmp - 1);
                    click_r_de_chon_ghe_da_search(vitrisua, suathongtin, chon_ghe, dang_chon_chuyen_bay, cbcotmp, tmpsua, tmpcb);

                }
                else if (isMousechuyenbay7(x, y) == 1) {
                    vitrisua = 0;
                    vitrisua = 6 + 10 * (tranghientmp - 1);
                    click_r_de_chon_ghe_da_search(vitrisua, suathongtin, chon_ghe, dang_chon_chuyen_bay, cbcotmp, tmpsua, tmpcb);

                }
                else if (isMousechuyenbay8(x, y) == 1) {
                    vitrisua = 0;
                    vitrisua = 7 + 10 * (tranghientmp - 1);
                    click_r_de_chon_ghe_da_search(vitrisua, suathongtin, chon_ghe, dang_chon_chuyen_bay, cbcotmp, tmpsua, tmpcb);

                }
                else if (isMousechuyenbay9(x, y) == 1) {
                    vitrisua = 0;
                    vitrisua = 8 + 10 * (tranghientmp - 1);
                    click_r_de_chon_ghe_da_search(vitrisua, suathongtin, chon_ghe, dang_chon_chuyen_bay, cbcotmp, tmpsua, tmpcb);

                }
                else if (isMousechuyenbay10(x, y) == 1) {
                    vitrisua = 0;
                    vitrisua = 9 + 10 * (tranghientmp - 1);
                    click_r_de_chon_ghe_da_search(vitrisua, suathongtin, chon_ghe, dang_chon_chuyen_bay, cbcotmp, tmpsua, tmpcb);

                }
            }

        }
        //chuot move 
        if (ismouseclick(WM_MOUSEMOVE)) {

        }
        if (kbhit()) {
            char endct;
            endct = getch();
            if (endct == 27) {
                break;
            }
        }
    }
}

int main() {



    initwindow(1540, 800, "install_graphics_h");
    Screen_Default(0);
    AO_THAT_DAY();
    Lay_chi_so();
    getch();
    closegraph();



    //ds_hk.lay_du_lieu_tu_file();
    //QLHK tmp = ds_hk;
    //ds_hk.printf_ds(ds_hk.getRoot());
    
    //dem = 0;
    //printf_dshk(tmp.getRoot(), 1, dem);
    //dem = 0;
    //printf_dshk(tmp.getRoot(), 0, dem);




    //cout << ds_hk.getRoot()->data.soCMND;
    //ds_hk.printf_ds(ds_hk.getRoot());
    //char a[30] = "4";
    //ds_hk.remove(ds_hk.getRoot(), a);
    //cout << "sau remove";
    //ds_hk.printf_ds(ds_hk.getRoot());



    //listmb ds;
    //maybay mb;
    //mb = taomaybay(const_cast<char*>("conmemay"), const_cast < char*>( "alo"), 20, 40);
    //addmb(ds,mb) ;
    //savefile(ds) ;
    //openfile(ds);
    //for (int i = 0; i < ds.n; i++) {
    //    cout << ds.nodes[i]->sohieu << "\n" << ds.nodes[i]->sodong << endl <<ds.nodes[i]->soday<<endl<< ds.nodes[i]->socho <<endl<< ds.nodes[i]->loai<<endl;

    //}


}
