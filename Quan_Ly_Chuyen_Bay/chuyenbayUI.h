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
#include"maybayUI.h"
#include"doimau.h"

#include"FUNTION.h"
using namespace std;
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
        
        for (int i = dem; i < dem + 10; i++) {
            phantuhien++;
            int sodong, soday;
            soday = ds_mb.nodes[timkiem(ds_mb, a.sohieu)]->soday;
            sodong = ds_mb.nodes[timkiem(ds_mb, a.sohieu)]->sodong;
            chuyenintschar(tmpcc[0], phantuhien);
            hienchinhgiua(100, y, 190, y + 40, tmpcc[0]);
            int vitri = 65;
            int demghe= vitrighe[i];
            while (demghe > sodong) { demghe -= sodong;  vitri++; }
            string m;
            m += static_cast<char>(vitri);
            
            m += to_string(demghe);
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
            int demghe = vitrighe[i];
            while (demghe > sodong) { demghe -= sodong;  vitri++; }
            string m;
            m += static_cast<char>(vitri);
            m += to_string(demghe);
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