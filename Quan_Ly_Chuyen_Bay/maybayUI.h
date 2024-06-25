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
#include"doimau.h"

#include"FUNTION.h"
using namespace std;
void Planes_design() {
    vekhungcongcu();
    vekhungdsmb();
    ve_hinh_vuong(540, 700, 590, 735, COLOR(217, 234, 211), 0, const_cast<char*>(">"), 1, 0);
    ve_hinh_vuong(410, 700, 460, 735, COLOR(217, 234, 211), 0, const_cast<char*>("<"), 1, 0);

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
            ve_hinh_vuong(833, 205 - 3, 898, 205 + 22, COLOR(205, 250, 219), COLOR(205, 250, 219), const_cast<char*>("ko the xoa"), 1, 0);
            delay(20);
            ve_hinh_vuong(833, 205 - 3, 898, 205 + 22, COLOR(250, 112, 112), COLOR(250, 112, 112), const_cast<char*>("ko the xoa"), 1, 0);
            delay(20);
            ve_hinh_vuong(833, 205 - 3, 898, 205 + 22, COLOR(205, 250, 219), COLOR(205, 250, 219), const_cast<char*>("ko the xoa"), 1, 0);
            delay(20);
            ve_hinh_vuong(833, 205 - 3, 898, 205 + 22, COLOR(250, 112, 112), COLOR(250, 112, 112), const_cast<char*>("ko the xoa"), 1, 0);

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
    if (stt >= dsmb.n)
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
