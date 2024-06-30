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
#include"graphics.h"
#include"chuyenbayUI.h"
#include"maybayUI.h"
#include"doimau.h"

#include"FUNTION.h"
using namespace std;

void cap_nhat_trang_thai_cb(ds capnhat) {
    for (; capnhat != NULL; capnhat = capnhat->next) {
        update_trang_thai(capnhat->cb);
    }
    capnhatdulieu(s);
}
bool check_so_ghe(int soday, int sodong, char so_ghe[30]) {
    if (so_ghe[0] >= 'A' && so_ghe[0] <= 'Z') {
        int ghe = 0;
        ghe = (so_ghe[0] - 'A');
        if (ghe < soday) {
            ghe = atoi(&so_ghe[1]);
            if (ghe <= sodong) {
                return 1;
            }
            return 0;
        }
        else return 0;
    }
    return 0;
}
void them_hanh_khach(dschuyenbay* ds, const char* macb, char* cmnd, int seat_number) {
    dschuyenbay* temp = ds;

    while (temp != nullptr) {
        if (strcmp(temp->cb.macb, macb) == 0) {
            if (temp->cb.trangthai != 2) { // Chỉ thêm hành khách vào chuyến bay còn vé
                hienthiloi(const_cast<char*>("Chuyen bay khong con ve hoac da hoan tat."));
                return;
            }
            if (seat_number < 0 || seat_number >= temp->cb.sove) {
                hienthiloi(const_cast<char*>("So ghe khong hop le."));

                return;
            }
            for (int j = 0; j < temp->cb.sove; ++j) {
                if (strcmp(temp->cb.danhsachve[j], cmnd) == 0) {
                    if (TRC_30p(temp->cb) == 0) {
                        hienthiloi(const_cast<char*>("Quy khach da dat ve tren chuyen bay nay."));
                        return;
                    }
                    string m = "Quy khach da dat ve tren chuyen bay nay.\nQuy khach co muon huy ve khong";
                    ve_hinh_vuong(480, 250, 1000, 520, COLOR(218, 221, 177), COLOR(179, 164, 146), const_cast<char*>(m.c_str()), 1, 0);
                    ve_hinh_vuong(510, 440, 590, 480, COLOR(217, 234, 211), 0, const_cast<char*>("YES"), 1, 0);
                    ve_hinh_vuong(850, 440, 920, 480, COLOR(217, 234, 211), 0, const_cast<char*>("NO"), 1, 0);
                    while (1) {
                        int xx, yy;
                        if (ismouseclick(WM_LBUTTONDOWN)) {
                            
                            getmouseclick(WM_LBUTTONDOWN, xx, yy);
                            if (isMouse_Yes_huy_ve(xx, yy)) {
                                temp->cb.danhsachve[j][0] = '\0';
                                cout << "huy thanh cong";
                                return;
                            }
                            else if (isMouse_No_huy_ve(xx, yy)) {
                                return;
                            }
                        }
                        static bool doi_mau = 0;
                        if (ismouseclick(WM_MOUSEMOVE))
                        {
                            getmouseclick(WM_MOUSEMOVE, xx, yy);
                            if (isMouse_Yes_huy_ve(xx, yy) && doi_mau == 0) {
                                doi_mau = 1;
                                ve_hinh_vuong(510, 440, 590, 480, COLOR(160, 196, 157), 0, const_cast<char*>("YES"), 1, 0);

                            }
                            else if (isMouse_No_huy_ve(xx, yy) && doi_mau == 0) {
                                doi_mau = 1;
                                ve_hinh_vuong(850, 440, 920, 480, COLOR(160, 196, 157), 0, const_cast<char*>("NO"), 1, 0);
                            }
                            else if (isMouse_Yes_huy_ve(xx, yy) == 0 && isMouse_No_huy_ve(xx, yy) == 0 && doi_mau == 1) {

                                ve_hinh_vuong(510, 440, 590, 480, COLOR(217, 234, 211), 0, const_cast<char*>("YES"), 1, 0);
                                ve_hinh_vuong(850, 440, 920, 480, COLOR(217, 234, 211), 0, const_cast<char*>("NO"), 1, 0);
                                doi_mau = 0;
                            }
                        }
                    }
                    return;
                }
            }
            if (strlen(temp->cb.danhsachve[seat_number]) != 0) {
                hienthiloi(const_cast<char*>("Ghe da duoc dat boi hanh khach khac."));

                return;
            }
            STRCPYY(temp->cb.danhsachve[seat_number], cmnd);
            hienthiloi(const_cast<char*>("Them hanh khach vao chuyen bay thanh cong."));

            return;
        }
        temp = temp->next;
    }
    hienthiloi(const_cast<char*>("Khong tim thay chuyen bay co ma "));
}
//ticket-------------------------------------------------------------------
void ve_may_bay(int x1, int y1, int x2, int y2, int radius) {
    // Vẽ hình vuông
    setfillstyle(SOLID_FILL, WHITE);
    setcolor(15);
    bar(x1 + radius, y1, x2 - radius + 15, y2);
    bar(x1, y1 + radius - 10, x2, y2 - radius + 15);

    // Vẽ các góc bo
    fillellipse(x1 + radius, y1 + radius, radius, radius);
    fillellipse(x2 - radius, y1 + radius, radius, radius);
    fillellipse(x1 + radius, y2 - radius, radius, radius);
    fillellipse(x2 - radius, y2 - radius, radius, radius);
    setcolor(15);
    fillellipse(x1 + 10, (y1 + y2) / 2, y2 - (y1 + y2) / 2 - 50, y2 - (y1 + y2) / 2);
    setfillstyle(SOLID_FILL, COLOR(164, 206, 149));
    sector(x1 + 10, (y1 + y2) / 2, 90, 270, y2 - (y1 + y2) / 2 - 50 - 10, y2 - (y1 + y2) / 2 - 10);
    setcolor(0);
    arc(x2 - radius, y1 + radius, 0, 90, radius);
    line(x2, y1 + radius, x2, y2 - radius);
    arc(x2 - radius, y2 - radius, 270, 0, radius);
    ellipse(x1 + 10, (y1 + y2) / 2, 90, 270, y2 - (y1 + y2) / 2 - 50, y2 - (y1 + y2) / 2);
    setlinestyle(0, 0, 2);
    line(x1 + 10, y1, x2 - 30, y1); line(x1 + 10, y2, x2 - 30, y2);

}
void to_mau_ghe(int x, int y, string m) {

    ve_hinh_vuong(x, y, x + 30, y + 20, COLOR(211, 118, 118), 0, const_cast<char*>(m.c_str()), 1, 0);
}
void Man_hinh_mua_ticket_b1() {

    char a1[30] = "Nhap thong tin hanh khach";
    ve_hinh_vuong(570, 130, 900, 180, COLOR(218, 221, 177), COLOR(179, 164, 146), a1, 1);
    char a2[30] = "Nhap CCCD:"; char a3[30] = "gom 12 chu so";
    setbkcolor(COLOR(208, 224, 227));
    outtextxy(300, 305, a2);
    ve_hinh_vuong(400, 290, 1000, 340, COLOR(217, 234, 211), 0, a3, 0, COLOR(179, 164, 146));
    char a5[20] = "NEXT";
    ve_hinh_vuong(1282, 420, 1370, 460, COLOR(217, 234, 211), 0, a5, 1);
    setbkcolor(COLOR(208, 224, 227));
    setcolor(COLOR(255, 0, 77));
    outtextxy(70, 730, const_cast<char*>("enter de hoan tat"));
}
void Man_hinh_mua_ticket_b2() {
    cleardevice();
    Screen_Default(4);
    setcolor(0);
    setbkcolor(COLOR(208, 224, 227));
    char b1[30] = "NHAP THONG TIN HANH KHACH";
    outtextxy(644, 182, b1);
    char b2[30] = "HO: "; char b3[30] = "TEN: ", b4[30] = "PHAI: ";
    char a2[30] = "gom 30 chu va giau cach", a3[30] = "gom 30 ki tu", a4[30] = "TIM CHUYEN BAY";
    outtextxy(377, 235, b2);
    outtextxy(370, 335, b3);
    outtextxy(370, 435, b4);
    ve_hinh_vuong(100, 130, 200, 170, COLOR(217, 234, 211), 0, const_cast<char*>("BACK"), 1, 0);
    //ho
    ve_hinh_vuong(374 + textwidth(b3), 220, 374 + textwidth(b3) + 600, 265, COLOR(217, 234, 211), 0, a2, 0, COLOR(179, 164, 146));
    ve_hinh_vuong(374 + textwidth(b3), 320, 374 + textwidth(b3) + 600, 365, COLOR(217, 234, 211), 0, a2, 0, COLOR(179, 164, 146));
    ve_hinh_vuong(374 + textwidth(b3), 420, 374 + textwidth(b3) + 200, 465, COLOR(217, 234, 211), 0, const_cast<char*>("nam"), 1, COLOR(179, 164, 146));
    ve_hinh_vuong(600 + textwidth(b3), 420, 374 + textwidth(b3) + 430, 465, COLOR(217, 234, 211), 0, const_cast<char*>("nu"), 1, COLOR(179, 164, 146));

    ve_hinh_vuong(374 + textwidth(b3), 520, 374 + textwidth(b3) + 600, 565, COLOR(245, 232, 221), 0, a4, 1, 0);
    setbkcolor(COLOR(208, 224, 227));
    setcolor(COLOR(255, 0, 77));
    outtextxy(70, 730, const_cast<char*>("enter de hoan tat"));
    outtextxy(70, 755, const_cast<char*>("chon tim chuyen bay de tim chuyen bay"));
    setcolor(0);
}
void Man_hinh_mua_ticket_b3() {
    cap_nhat_trang_thai_cb(s);
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
    setbkcolor(COLOR(217, 234, 211));
    //nhap
    setfillstyle(SOLID_FILL, COLOR(159, 197, 232));
    bar(688, 719, 748, 765);
    bar(820, 719, 880, 765);
    line(727, 726, 698, 742);
    line(698, 742, 727, 760);
    line(836, 726, 866, 742);
    line(866, 742, 836, 760);
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
    setcolor(COLOR(255, 0, 77));
    setbkcolor(COLOR(208, 224, 227));
    outtextxy(70, 730, const_cast<char*>("click chuot phai de chon chuyen bay"));
    setcolor(0);
}
void Man_hinh_mua_ticket_b4(chuyenbay clgt, int soday, int sodong) {

    cleardevice();
    Screen_Default(4);
    int x = 200;
    int y = soday * 50 + 200;
    ve_may_bay(x, 200, 1400, y, 30);
    ve_hinh_vuong(100, 130, 200, 170, COLOR(217, 234, 211), 0, const_cast<char*>("BACK"), 1, 0);
    int tmp1 = 300, tmp2 = 220;
    for (int i = 65; i < soday + 65; i++) {
        for (int j = 0; j < sodong; j++) {
            string m;
            m += static_cast<char>(i); // Chuyển số sang ký tự, VD: 0 -> 'A', 1 -> 'B', ...
            m += to_string(j + 1); // Ghế bắt đầu từ số 1
            ve_hinh_vuong(tmp1, tmp2, tmp1 + 30, tmp2 + 20, COLOR(217, 234, 211), 0, const_cast<char*>(m.c_str()), 1, 0);
            int tmp3 = (i - 65) * sodong + (j);

            if (clgt.danhsachve[tmp3][0] != '\0') {
                to_mau_ghe(tmp1, tmp2, m);
            }

            tmp1 += 35;
        }
        tmp1 = 300;
        tmp2 += 35;
    }
    ve_hinh_vuong(500, 130, 600, 170, COLOR(217, 234, 211), 0, const_cast<char*>("nhap so ghe"), 1, COLOR(179, 164, 146));
    string m;
    m = "chuyen bay: ";
    m += clgt.sohieu;
    hien_o_giua(800, 150, const_cast<char*>(m.c_str()));
}
void click_r_de_chon_ghe_da_search(int vitrisua, bool& suathongtin, bool& chon_ghe, bool& dang_chon_chuyen_bay, int cbcotmp, chuyenbay& tmpsua, ds& tmpcb) {
    if (vitrisua >= cbcotmp) {
        char a[30] = "khong co phan tu de sua";
        hienthiloi(a);
        suathongtin = false;
    }
    else {
        tmpsua = laychuyenbay(tmpcb, vitrisua);
        if (tmpsua.trangthai == 1) {
            char a[30] = "chuyen bay da huy";
            hienthiloi(a);
        }
        else if (tmpsua.trangthai == 4) {
            char a[30] = "chuyen bay da hoan thanh";
            hienthiloi(a);
        }
        else {
            cleardevice();
            //tim so dong so day
            Screen_Default(4);
            int soday, sodong;
            soday = ds_mb.nodes[timkiem(ds_mb, tmpsua.sohieu)]->soday;
            sodong = ds_mb.nodes[timkiem(ds_mb, tmpsua.sohieu)]->sodong;
            Man_hinh_mua_ticket_b4(tmpsua, soday, sodong);
            dang_chon_chuyen_bay = 0;
            chon_ghe = 1;
            suathongtin = true;
        }
    }
}
void click_r_de_chon_ghe_chua_search(int vitrisua, bool& suathongtin, bool& chon_ghe, bool& dang_chon_chuyen_bay, chuyenbay& tmpsua, int sochuyenbayco) {

    if (vitrisua >= sochuyenbayco) {
        char a[30] = "khong co phan tu de sua";
        hienthiloi(a);
        suathongtin = false;
    }
    else {
        tmpsua = laychuyenbay(s, vitrisua);
        TRC_30p(tmpsua);
        if (tmpsua.trangthai == 1) {    
            char a[30] = "chuyen bay da huy";
            hienthiloi(a);
        }
        else if (tmpsua.trangthai == 4) {
            char a[30] = "chuyen bay da hoan thanh";
            hienthiloi(a);
        }
        else {
            cleardevice();

            Screen_Default(4);
            int soday = 10, sodong = 5;
            soday = ds_mb.nodes[timkiem(ds_mb, tmpsua.sohieu)]->soday;
            sodong = ds_mb.nodes[timkiem(ds_mb, tmpsua.sohieu)]->sodong;
            Man_hinh_mua_ticket_b4(tmpsua, soday, sodong);
            dang_chon_chuyen_bay = 0;
            chon_ghe = 1;
            suathongtin = true;
        }
    }
}
void Man_hinh_in4_hk_old(HanhKhach old) {
    Man_hinh_mua_ticket_b2();
    char b3[30] = "TEN: ";
    bool oldphai = 0;
    //ve_hinh_vuong(100, 130, 200, 170, COLOR(217, 234, 211), 0, const_cast<char*>("BACK"), 1, 0);
    ve_hinh_vuong(374 + textwidth(b3), 220, 374 + textwidth(b3) + 600, 265, COLOR(217, 234, 211), 0, const_cast<char*>(old.ho.c_str()), 0);
    ve_hinh_vuong(374 + textwidth(b3), 320, 374 + textwidth(b3) + 600, 365, COLOR(217, 234, 211), 0, const_cast<char*>(old.ten.c_str()), 0);
    if (strcmp(const_cast<char*>(old.phai.c_str()), const_cast<char*>("NAM")) == 0) {
        oldphai = 0;
    }
    else {
        oldphai = 1;
    }
    if (oldphai == 0)
    {
        ve_hinh_vuong(374 + 35, 420, 374 + 35 + 200, 465, COLOR(168, 205, 159), 0, const_cast<char*>("nam"), 1, 0);
    }
    else
    {
        ve_hinh_vuong(600 + 35, 420, 374 + 35 + 430, 465, COLOR(168, 205, 159), 0, const_cast<char*>("nu"), 1, 0);
    }
    setbkcolor(COLOR(208, 224, 227));
    string m = "THONG TIN CUA HACH KHACH CO CCCD LA: ";
    string n(old.soCMND);
    m += n;
    outtextxy(584, 182, const_cast<char*>(m.c_str()));
    setcolor(0);
}
//void chuan_hoa_time(string &data) {
//    if (data[1] =='\0') {
//        data[1] = data[0];
//        data[0] = '0';
//    }
//}
//void hien_o_giua(int x, int y, string data) {
//    x -= textwidth(const_cast<char*>(data.c_str())) / 2;
//    outtextxy(x, y, const_cast<char*>(data.c_str()));
//    x += textwidth(const_cast<char*>(data.c_str())) / 2;
//}
//int dem_CB() {
//    int dem = 0;
//    ifstream file("Text.txt");
//    string data;
//    while (getline(file, data)) {
//        dem++;
//    }
//    return dem;
//    file.close();
//}
//void hien_thi_chuyen_bay(int TRANG_CB_CURR = 0) {
//    setbkcolor(COLOR(208, 224, 227));
//    sochuyenbayco = dem_CB();
//    sotrangcb = sochuyenbayco / 10;
//
//    ifstream file("Text.txt");
//    string data;
//    int x = 260, y = 299;
//    int count = 0;
//    string time, idfl, sanbay, sohieumb, trangthai;
//    for (int i = 0; i < TRANG_CB_CURR; i++) {
//        for (int j = 0; j < 10; j++) {
//            getline(file, data);
//            count++;
//        }
//    }
//    int dem = 0;
//    while (getline(file, data)) {
//        stringstream ss(data);
//        getline(ss, data, ' ');
//        chuan_hoa_time(data);
//        time = data;
//        time += ":";
//        getline(ss, data, ' ');
//        chuan_hoa_time(data);
//        time += data;
//        time += " - ";
//        getline(ss, data, ' ');
//        chuan_hoa_time(data);
//        time += data;
//        time += "/";
//        getline(ss, data, ' ');
//        chuan_hoa_time(data);
//        time += data;
//        time += "/";
//        getline(ss, data, ' ');
//        chuan_hoa_time(data);
//        time += data;
//        //bo qua so ghe
//        getline(ss, data, ' ');
//        getline(ss, data, ' ');
//        trangthai = data;
//        getline(ss, data, ' ');
//        sanbay = data;
//        getline(ss, data, ' ');
//        idfl = data;
//        getline(ss, data, ' ');
//        sohieumb = data;
//        dem++;
//        count++;
//        hien_o_giua(x, y, idfl);
//        x += 130;
//        hien_o_giua(x, y, sohieumb);
//        x += 220;
//        hien_o_giua(x, y, sanbay);
//        x += 280;
//        hien_o_giua(x, y, time);
//        x += 240;
//        if (trangthai == "1") {
//            trangthai = "da huy";
//        }if (trangthai == "2") {
//            trangthai = "conve";
//
//        }if (trangthai == "3") {
//            trangthai = "hetve";
//
//        }if (trangthai == "4") {
//            trangthai = "hoantat";
//            
//        }
//        hien_o_giua(x, y, trangthai);
//        x = 260;
//        y += 40;
//        if (dem == 10)
//        {
//            break;
//        }
//    }
//    int ynum = 299, yline = 289 + 40;
//    for (int i = TRANG_CB_CURR*10+1; i <=count; i++) {
//        string m = to_string(i);
//        hien_o_giua(140, ynum, m);
//        ynum += 40;
//        line(100, yline, 1440, yline);
//        yline += 40;
//    }
//    file.close();
//}
//void xoa_de_search() {
//    setfillstyle(SOLID_FILL, COLOR(208, 224, 227));
//    bar(101, 290, 189, 688);
//    bar(191, 290, 325, 688);
//    bar(327, 290, 461, 688);
//    bar(463, 290, 759, 688);
//    bar(761, 290, 1025, 688);
//    bar(1027, 290, 1231, 688);
//    bar(1233, 290, 1439, 688);
//}
//void search_CB(char idfl[], char ngay[], char thang[], char nam[], char sanbay[],int trang_curr) {
//    xoa_de_search();
//    setbkcolor(COLOR(208, 224, 227));
//    sochuyenbayco = dem_CB();
//    string* xuat = new string[sochuyenbayco * 10];
//    int so_luong_CB_tim_thay = 0;
//    int* STT = new int[sochuyenbayco];
//    int tmp = 0;//bien run mang xuat
//    int dem1 = 0, dem2 = 0;
//    
//    ifstream file("Text.txt");
//    string data;
//    string time, id, arrive, sohieumb, trangthai,day,month,year;
//    while (getline(file, data)) {
//        stringstream ss(data);
//        getline(ss, data, ' ');
//        chuan_hoa_time(data);
//        time = data;
//        time += ":";
//        getline(ss, data, ' ');
//        chuan_hoa_time(data);
//        time += data;
//        time += " - ";
//        getline(ss, data, ' ');
//        day = data;
//        chuan_hoa_time(data);
//        time += data;
//        time += "/";
//        getline(ss, data, ' ');
//        month = data;
//        chuan_hoa_time(data);
//        time += data;
//        time += "/";
//        getline(ss, data, ' ');
//        year = data;
//        time += data;
//        //bo qua so ghe
//        getline(ss, data, ' ');
//        getline(ss, data, ' ');
//        trangthai = data;
//        getline(ss, data, ' ');
//        arrive = data;
//        getline(ss, data, ' ');
//        id = data;
//        getline(ss, data, ' ');
//        sohieumb = data;
//        dem1++;
//        if ((idfl[0] != '\0' && id.compare(idfl) != 0) || (ngay[0] != '\0' && day.compare(ngay) != 0) || (thang[0] != '\0' && month.compare(thang) != 0) || (nam[0] != '\0' && year.compare(nam) != 0) || (sanbay[0] != '\0' && arrive.compare(sanbay) != 0)) {
//            continue;
//        }
//        xuat[tmp] = id;
//        tmp++;
//        xuat[tmp] = sohieumb;
//        tmp++;
//        xuat[tmp] = time; tmp++;
//        xuat[tmp] = arrive;
//        tmp++;
//
//        if (trangthai == "1") {
//            trangthai = "da huy";
//        }if (trangthai == "2") {
//            trangthai = "conve";
//
//        }if (trangthai == "3") {
//            trangthai = "hetve";
//
//        }if (trangthai == "4") {
//            trangthai = "hoantat";
//
//        }
//        xuat[tmp] = trangthai;
//        tmp++;
//        so_luong_CB_tim_thay++;
//        STT[dem2] = dem1;
//        dem2++;
//    }
//    file.close();
//    if (so_luong_CB_tim_thay == 0) {
//        delete[]xuat;
//        return;
//    }
//    int trang_max_tim_kiem = so_luong_CB_tim_thay / 10;
//    int so_luong_CB_duoc_in_ra = 0;
//    if (trang_curr < trang_max_tim_kiem) {
//        so_luong_CB_duoc_in_ra = 10;
//    }
//    else if (trang_curr = trang_max_tim_kiem) {
//        so_luong_CB_duoc_in_ra = so_luong_CB_tim_thay % 10;
//    }
//  
//    int x = 260, y = 299;
//   
//    int aduvippro = trang_curr * 10 * 5;
//    for (int i = aduvippro; i <= tmp; i++) {
//        hien_o_giua(x, y, xuat[aduvippro]);
//        x += 130;
//        aduvippro++;
//        hien_o_giua(x, y, xuat[aduvippro]);
//        x += 220; aduvippro++;
//        hien_o_giua(x, y, xuat[aduvippro]);
//        x += 280; aduvippro++;
//        hien_o_giua(x, y, xuat[aduvippro]);
//        x += 240; aduvippro++;
//        hien_o_giua(x, y, xuat[aduvippro]);
//        x = 260; aduvippro++;
//        y += 40;
//        if (y == 699)
//            break;
//    }
//    int xSTT = 140, ySTT = 299;
//    int yline = 289 + 40;
//    int count = trang_curr * 10;
//    for (int i = count; i < so_luong_CB_duoc_in_ra + count; i++) {
//        string m = to_string(STT[i]);
//        hien_o_giua(xSTT, ySTT, m);
//        ySTT += 40;
//        line(100, yline, 1440, yline);
//        yline += 40;
//    }
//    delete[]xuat;
//}
void Ticket_design() {
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
    setbkcolor(COLOR(217, 234, 211)); char a11[30] = "MUA VE";
    bar(1290, 140, 1390, 180); outtextxy(1300 + 30, 150, a11);
    //nhap
    setfillstyle(SOLID_FILL, COLOR(159, 197, 232));
    bar(688, 719, 748, 765);
    bar(820, 719, 880, 765);
    line(727, 726, 698, 742);
    line(698, 742, 727, 760);
    line(836, 726, 866, 742);
    line(866, 742, 836, 760);
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

}