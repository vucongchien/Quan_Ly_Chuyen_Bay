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


//customer---------------------------------------------------------------
void cap_nhat_dshk_sau_khi_NHAPIN4_muaTIKCET(char CMND[], char ho[], char ten[], bool phai) {
    HanhKhach hk;
    string tmp1(ho), tmp2(ten);
    string tmp3;
    if (phai == 1) {
        tmp3 = "NU";
    }
    else if (phai == 0) {
        tmp3 = "NAM";
    }
    STRCPYY(hk.soCMND, CMND);
    hk.ho = tmp1;
    hk.ten = tmp2;
    hk.phai = tmp3;
    ds_hk.insert(hk);
    ds_hk.xoa_va_cap_nhat_file(ds_hk.getRoot());
}
void dem_so_luong_hk(Node* root) {
    if (root == NULL) {
        return;
    }
    so_luong_hanh_khach++;
    dem_so_luong_hk(root->left);
    dem_so_luong_hk(root->right);
}
void printf_dshk(Node* run, int trang_hien_tai, int& dem, int& y, int& b1, int& ynumber) {
    //static int dem = 0;
    int x = 350, xnumber = 160;
    int a1 = 100, a2 = 1198;
    if (run == NULL)
    {

        return;
    }

    printf_dshk(run->left, trang_hien_tai, dem, y, b1, ynumber);
    if (dem == (trang_hien_tai + 1) * 10)
    {

        return;
    }
    dem++;
    if (dem > trang_hien_tai * 10)
    {

        x -= textwidth(const_cast<char*>(run->data.soCMND)) / 2;
        outtextxy(x, y, const_cast<char*>(run->data.soCMND));
        x += textwidth(const_cast<char*>(run->data.soCMND)) / 2;
        x += 245;

        x -= textwidth(const_cast<char*>(run->data.ho.c_str())) / 2;
        outtextxy(x, y, const_cast<char*>(run->data.ho.c_str()));
        x += textwidth(const_cast<char*>(run->data.ho.c_str())) / 2;
        x += 245;

        x -= textwidth(const_cast<char*>(run->data.ten.c_str())) / 2;
        outtextxy(x, y, const_cast<char*>(run->data.ten.c_str()));
        x += textwidth(const_cast<char*>(run->data.ten.c_str())) / 2;
        x += 245;

        x -= textwidth(const_cast<char*>(run->data.phai.c_str())) / 2;
        outtextxy(x, y, const_cast<char*>(run->data.phai.c_str()));
        x += textwidth(const_cast<char*>(run->data.phai.c_str())) / 2;
        x += 245;
        y += 40;

        string m = to_string(dem);
        outtextxy(xnumber, ynumber, const_cast<char*>(m.c_str()));
        ynumber += 40;

        line(a1, b1, a2, b1);
        b1 = b1 + 40;
    }

    printf_dshk(run->right, trang_hien_tai, dem, y, b1, ynumber);

}
void Hien_thi_hanh_khach(int trang_hien_tai = 0) {
    //ifstream file("hanhkhach.txt");
    //string data;
    int x = 350, y = 300, xnumber = 160, ynumber = 300;
    int count = 0;
    so_luong_hanh_khach = 0;
    dem_so_luong_hk(ds_hk.getRoot());
    so_trang_hanh_khach = so_luong_hanh_khach / 10;
    if (so_luong_hanh_khach % 10 == 0) so_trang_hanh_khach -= 1;
    //for (int i = 0; i < trang_hien_tai; i++) {
    //    for (int j = 0; j < 10; j++) {
    //        getline(file, data);
    //        count++;
    //    }
    //}
    //count++;
    //int dem = 0;
    //while (getline(file, data)) {
    //    stringstream ss(data);
    //    while (getline(ss, data, ','))
    //    {
    //        x -= textwidth(const_cast<char*>(data.c_str())) / 2;
    //        outtextxy(x, y, const_cast<char*>(data.c_str()));
    //        x += textwidth(const_cast<char*>(data.c_str())) / 2;
    //        x += 245;
    //    }


    //    x = 350;
    //    y += 40;
    //    count++;
    //    dem++;
    //    if (dem == 10)
    //        break;

    //}
    int b1 = 290 + 40;
    //for (int i = trang_hien_tai * 10 + 1; i < count; i++) {
    //    string m = to_string(i);
    //    outtextxy(xnumber, ynumber, const_cast<char*>(m.c_str()));
    //    ynumber += 40;
    //    line(a1, b1, a2, b2);
    //    b1 = b2 = b1 + 40;
    //}

    //file.close();
    int dem = 0;
    printf_dshk(ds_hk.getRoot(), trang_hien_tai, dem, y, b1, ynumber);




}
//void xem_thong_tin_hanh_khach(int number_hk, int so_trang_hien_tai) {
//    Screen_Default(3);
//    setfillstyle(SOLID_FILL, COLOR(159, 197, 232));
//    bar(101, 220, 1439, 290);
//    //taoButton(520, 10, 730, 80, "CUSTOMER");
//    setlinestyle(0, 0, 2);
//    setcolor(0);
//    rectangle(100, 220, 1440, 690);
//    setbkcolor(COLOR(159, 197, 232));
//    line(250, 220, 250, 690); char a[20] = "ID"; outtextxy(170, 240, a);
//    line(450, 220, 450, 690); char a1[20] = "NAME"; outtextxy(330, 240, a1);
//    setlinestyle(0, 0, 2);
//    line(650, 220, 650, 690); char a2[20] = "ID PLANE"; outtextxy(520, 240, a2);
//    line(850, 220, 850, 690); char a3[11] = "ID FLIGHT"; outtextxy(716, 240, a3);
//    line(1026, 220, 1026, 690); char a4[20] = "NUMBER OF SEAT"; outtextxy(880, 240, a4);
//    line(1232, 220, 1232, 690); char a5[20] = "ARRIVE";   outtextxy(1100, 240, a5);
//    char a6[20] = "TIME"; outtextxy(1320, 240, a6);
//    //////////////////////
//    //TIM THANG LOL CO NUMBER DO
//    //KHO VAIIIIIIIIIIIIIIIIIIIILOLLLl
//    ifstream file("hanhkhach.txt");
//    string id, name, data;
//    int stt_hanh_khach = (so_trang_hien_tai) * 10 + number_hk;
//    int count = 0;
//    setbkcolor(COLOR(208, 224, 227));
//    while (getline(file, data)) {
//        stringstream ss(data);
//        getline(ss, data, ',');
//        id = data;
//        getline(ss, data, ',');
//        name = data;
//        getline(ss, data, ',');
//        name += " ";
//        name += data;
//
//        count++;
//
//        if (count == stt_hanh_khach) {
//            int x = 175;
//            int Width = textwidth(const_cast<char*>(id.c_str()));
//            x -= Width/2;
//            outtextxy(x, 300, const_cast<char*>(id.c_str()));
//            x += Width / 2;
//            x += 180;
//            Width = textwidth(const_cast<char*>(name.c_str()));
//            x -= Width / 2;
//            outtextxy(x, 300, const_cast<char*>(name.c_str())); 
//            x += Width / 2;
//
//            break;
//        }
//    }
//    line(100, 290, 1440, 290);
//    //int xnumber = 145, ynumber = 300;
//    //int tmp = 290 + 40;
//    //for (int i = 1; i <= count; i++) {
//    //    string m = to_string(i);
//    //    outtextxy(xnumber, ynumber, const_cast<char*>(m.c_str()));
//    //    ynumber += 40;
//    //    line(100,tmp,1440,tmp);
//    //    tmp += 40;
//    //}
//    file.close();
//}
void xoa_di_lam_lai() {
    setfillstyle(SOLID_FILL, COLOR(208, 224, 227));
    bar(101, 291, 1197, 689);
    setlinestyle(0, 0, 2);
    line(1026 + 70 + 34 + 34 + 34, 220, 1026 + 70 + 34 + 34 + 34, 690);
    line(820 + 70 + 34 + 34, 220, 820 + 70 + 34 + 34, 690);
    line(612 + 70 + 34, 220, 612 + 70 + 34, 690);
    line(406 + 70, 220, 406 + 70, 690);
    line(200 + 34, 220, 200 + 34, 690);

    //bar(201, 291, 405, 689);
    //bar(407, 291, 611, 689);
    //bar(613, 291, 819, 689);
    //bar(821, 291, 1025, 689);
    //bar(1027, 291, 1231, 689);
    //bar(1233, 291, 1439, 689);
}
void Search_hanh_khach(char id[], char lname[], char fname[], int*& danh_sach_HK_O_tren_man_hinh, int& so_luong_hanh_khach_tim_thay, int trang_curr, int& trang_max) {
    xoa_di_lam_lai();
    setbkcolor(COLOR(208, 224, 227));
    //--------------------------
    dem_so_luong_hk(ds_hk.getRoot());
    delete[]danh_sach_HK_O_tren_man_hinh;
    danh_sach_HK_O_tren_man_hinh = new int[so_luong_hanh_khach];
    string* xuat = new string[so_luong_hanh_khach * 4];
    //-------------------------danh_sach_hk_o_tren_man_hinh bao gom cac sothutu cua hanhkhach tim thay
    int tmp = 0;
    string cmnd, ho, ten, phai;
    string data;
    ifstream file("hanhkhach.txt");
    int dem2 = 0, dem1 = 0;
    so_luong_hanh_khach_tim_thay = 0;
    while (getline(file, data)) {
        stringstream ss(data);
        getline(ss, data, ',');
        cmnd = data;
        getline(ss, data, ',');
        ho = data;
        getline(ss, data, ',');
        ten = data;
        getline(ss, data, ',');
        phai = data;
        dem1++;

        if ((id[0] != '\0' && cmnd.compare(id) != 0) || (lname[0] != '\0' && ho.compare(lname) != 0) || (fname[0] != '\0' && ten.compare(fname) != 0)) {
            continue;
        }

        xuat[tmp] = cmnd;
        tmp++;
        xuat[tmp] = ho;
        tmp++;
        xuat[tmp] = ten;
        tmp++;
        xuat[tmp] = phai;
        tmp++;
        danh_sach_HK_O_tren_man_hinh[dem2] = dem1;
        dem2++;
        so_luong_hanh_khach_tim_thay++;

    }
    file.close();


    trang_max = so_luong_hanh_khach_tim_thay / 10;
    int so_luong_hk_duoc_in_ra = 0;
    if (trang_curr < trang_max) {
        so_luong_hk_duoc_in_ra = 10;
    }
    else if (trang_curr = trang_max) {
        so_luong_hk_duoc_in_ra = so_luong_hanh_khach_tim_thay % 10;
    }
    int x = 350, y = 300 - 40;
    int  ynum = 290 + 40;
    int xSTT = 160, ySTT = 300;
    int count = trang_curr * 10;
    int aduvippro = trang_curr * 10 * 4;
    for (int i = aduvippro; i < tmp; i++) {
        if (i % 4 == 0)
        {
            x = 350;
            y += 40;
            line(100, ynum, 1198, ynum);
            ynum += 40;
            string m = to_string(i / 4 + 1);
            outtextxy(xSTT, ySTT, const_cast<char*>(m.c_str()));
            count++;
            ySTT += 40;
        }
        x -= textwidth(const_cast<char*>(xuat[i].c_str())) / 2;
        outtextxy(x, y, const_cast<char*>(xuat[i].c_str()));
        x += textwidth(const_cast<char*>(xuat[i].c_str())) / 2;
        x += 245;
        if (ynum == 690) {
            break;
        }
    }
    delete[]xuat;
}
void Customer_design() {
    setfillstyle(SOLID_FILL, COLOR(159, 197, 232));
    bar(101, 220, 1197, 290);
    //taoButton(520, 10, 730, 80, "CUSTOMER");
    setlinestyle(0, 0, 2);
    setcolor(0);
    rectangle(100, 220, 1026 + 70 + 34 + 34 + 34, 690);
    setbkcolor(COLOR(159, 197, 232));
    line(200 + 34, 220, 200 + 34, 690); char a[8] = "NUMBERS"; outtextxy(116 + 14, 240, a);
    line(406 + 70, 220, 406 + 70, 690); char a1[20] = "ID"; outtextxy(295 + 34 + 15, 240, a1);
    setlinestyle(0, 0, 2);
    line(612 + 70 + 34, 220, 612 + 70 + 34, 690); char a2[20] = "LAST NAME"; outtextxy(489 + 34 + 34, 240, a2);
    line(820 + 70 + 34 + 34, 220, 820 + 70 + 34 + 34, 690); char a3[11] = "FIRST NAME"; outtextxy(688 + 34 + 34 + 34 + 15, 240, a3);
    line(1026 + 70 + 34 + 34 + 34, 220, 1026 + 70 + 34 + 34 + 34, 690); char a4[20] = "GENDER"; outtextxy(890 + 34 + 28 + 34 + 34 + 34, 240, a4);

    //next
    setfillstyle(SOLID_FILL, COLOR(217, 234, 211));
    bar(670, 720, 720, 750);
    rectangle(670, 720, 720, 750);
    bar(730, 720, 780, 750);
    rectangle(730, 720, 780, 750);
    line(710, 727, 680, 735);
    line(680, 735, 710, 744);
    line(745, 727, 771, 735);
    line(771, 735, 745, 745);
    setbkcolor(COLOR(208, 224, 227));
    char a7[20] = "SEARCH: ";
    char a8[20] = "ID";
    outtextxy(100, 140, a7);
    outtextxy(170, 140, a8);
    bar(200, 130, 400, 170);
    rectangle(200, 130, 400, 170);
    char a10[20] = "Last Name:";
    outtextxy(410, 140, a10);
    bar(500, 130, 700, 170);
    rectangle(500, 130, 700, 170);
    char a11[20] = "First Name:";
    outtextxy(710, 140, a11);
    bar(800, 130, 950, 170);
    rectangle(800, 130, 950, 170);
    //ke ngang
    line(100, 290, 1198, 290);
    //tuong tac
}
//----clean
