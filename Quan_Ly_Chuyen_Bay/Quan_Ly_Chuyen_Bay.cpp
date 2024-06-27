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

#include"FUNTION.h"

using namespace std;
#pragma comment(lib, "graphics.lib")

void hien(char cb[], char ngay[], char thang[], char nam[], char noiden[], ds s, ds& tmpcb, int& chuyen_trang_tim_kiem, int TRANG_THAI_TAB, int& capnhapchuyenbaycotmp, int& cbcotmp, int& cbtmp, int& sotrangtmp,int TICKETT=0) {
    int trangthai = 0;

    if (cb[0] == '\0' && ngay[0] == '\0' && noiden[0] == '\0' && nam[0] == '\0' && thang[0] == '\0') {
        while (tmpcb) {
            ds qq;
            qq = tmpcb->next;
            delete tmpcb;
            tmpcb = qq;
        }
        tmpcb = NULL;
        tranghientaicb = 1;
        sochuyenbayhien = 0;
        sotrangcb = 1;
        cleardevice();
        Screen_Default(TRANG_THAI_TAB);
        if(TICKETT==0)
        Flight_design();
        else if (TICKETT == 1) {
            Ticket_design();
        }
        else {
            Man_hinh_mua_ticket_b3();
        }
        hientrangdau(s, sochuyenbayhien, sochuyenbayco, sotrangcb);
        chuyen_trang_tim_kiem = 0;

    }
    else {
        cout << cb << endl;
        if (cb[0] == '\0' || ngay[0] == '\0' || noiden[0] == '\0' || nam[0] == '\0' || thang[0] == '\0') {
            while (tmpcb) {
                ds qq;
                qq = tmpcb->next;
                delete tmpcb;
                tmpcb = qq;
            }
            tmpcb = NULL;
        }
        if (cb[0] != '\0' && tmpcb == NULL && trangthai == 0) {
            cbtmp = 0, cbcotmp, sotrangtmp = 1;
            timkiemchuyenbay(s, tmpcb, cb, 1, capnhapchuyenbaycotmp, cbcotmp);
            capnhapchuyenbaycotmp = cbcotmp;
            if (tmpcb == NULL) {
                trangthai = 1;
            }
        }
        if (cb[0] != '\0' && tmpcb != NULL) {
            cbtmp = 0, cbcotmp, sotrangtmp = 1;
            timkiemchuyenbay1ds(tmpcb, cb, 1, capnhapchuyenbaycotmp, cbcotmp);
            capnhapchuyenbaycotmp = cbcotmp;
            if (tmpcb == NULL) {
                trangthai = 1;
            }
        }
        if (ngay[0] != '\0' && tmpcb == NULL && trangthai == 0) {
            cbtmp = 0, cbcotmp, sotrangtmp = 1;
            timkiemchuyenbay(s, tmpcb, ngay, 2, capnhapchuyenbaycotmp, cbcotmp);
            capnhapchuyenbaycotmp = cbcotmp;
            if (tmpcb == NULL) {
                trangthai = 1;
            }
        }
        if (ngay[0] != '\0' && tmpcb != NULL) {
            cbtmp = 0, cbcotmp, sotrangtmp = 1;
            timkiemchuyenbay1ds(tmpcb, ngay, 2, capnhapchuyenbaycotmp, cbcotmp);
            capnhapchuyenbaycotmp = cbcotmp;
            if (tmpcb == NULL) {
                trangthai = 1;
            }
        }
        if (thang[0] != '\0' && tmpcb == NULL && trangthai == 0) {
            cbtmp = 0, cbcotmp, sotrangtmp = 1;
            timkiemchuyenbay(s, tmpcb, thang, 3, capnhapchuyenbaycotmp, cbcotmp);
            capnhapchuyenbaycotmp = cbcotmp;
            if (tmpcb == NULL) {
                trangthai = 1;
            }
        }
        if (thang[0] != '\0' && tmpcb != NULL) {
            cbtmp = 0, cbcotmp, sotrangtmp = 1;
            timkiemchuyenbay1ds(tmpcb, thang, 3, capnhapchuyenbaycotmp, cbcotmp);
            capnhapchuyenbaycotmp = cbcotmp;
            if (tmpcb == NULL) {
                trangthai = 1;
            }
        }
        if (nam[0] != '\0' && tmpcb == NULL && trangthai == 0) {
            cbtmp = 0, cbcotmp, sotrangtmp = 1;
            timkiemchuyenbay(s, tmpcb, nam, 4, capnhapchuyenbaycotmp, cbcotmp);
            capnhapchuyenbaycotmp = cbcotmp;
            if (tmpcb == NULL) {
                trangthai = 1;
            }
        }
        if (nam[0] != '\0' && tmpcb != NULL) {
            cbtmp = 0, cbcotmp, sotrangtmp = 1;
            timkiemchuyenbay1ds(tmpcb, nam, 4, capnhapchuyenbaycotmp, cbcotmp);
            capnhapchuyenbaycotmp = cbcotmp;
            if (tmpcb == NULL) {
                trangthai = 1;
            }
        }
        if (noiden[0] != '\0' && tmpcb == NULL && trangthai == 0) {
            cbtmp = 0, cbcotmp, sotrangtmp = 1;
            timkiemchuyenbay(s, tmpcb, noiden, 5, capnhapchuyenbaycotmp, cbcotmp);
            capnhapchuyenbaycotmp = cbcotmp;
            if (tmpcb == NULL) {
                trangthai = 1;
            }
        }
        if (noiden[0] != '\0' && tmpcb != NULL) {
            cbtmp = 0, cbcotmp, sotrangtmp = 1;
            timkiemchuyenbay1ds(tmpcb, noiden, 5, capnhapchuyenbaycotmp, cbcotmp);
            capnhapchuyenbaycotmp = cbcotmp;
            if (tmpcb == NULL) {
                trangthai = 1;
            }
            /* hientrangdau(tmpcb, cbtmp, cbcotmp, sotrangtmp);
             chuyen_trang_tim_kiem = 1;*/
        }



        hientrangdau(tmpcb, cbtmp, cbcotmp, sotrangtmp);
        chuyen_trang_tim_kiem = 1;
    }
}
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
void lay_chuyen_bay_co_the_dat_ve(ds vao, ds& ra, int& dem) {
    dem = 0;
    while (vao != NULL) {
        if (vao->cb.trangthai == 2) {
            push(ra, vao->cb);
            dem++;
            vao = vao->next;
        }
        else {
            vao = vao->next;
        }
    }
}


//--------------------------------------dieu khien -----------------------------------
void AO_THAT_DAY() {
    int TRANG_THAI_TAB = 1;
    bool keepRunning = true;

    dieukienpage dieukien = LISTPLANE;
    thread t(threadFunction, ref(TRANG_THAI_TAB), ref(keepRunning), ref(dieukien));
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
    int trang_hien_tai = 0; ds_hk.lay_du_lieu_tu_file();// dem_so_luong_hk(ds_hk.getRoot());
    char Search[3][30];  for (int i = 0; i < 3; i++) Search[i][0] = '\0';
    int* danh_sach_HK_O_tren_man_hinh = new int[ds_hk.getSo_luong_hk()];
    bool da_search_hk = 0;
    int so_luong_hanh_khach_tim_thay = 0;
    int trang_curr = 0, trang_max = 0;

    string* xuat_search = new string[ds_hk.getSo_luong_hk() * 4];
    int cout_for_search = 0;
    ds chuyenbaycothedat; chuyenbaycothedat = NULL; int sochuyenbayhien1, sochuyenbayco1, sotrangcb1, tranghientaicb1;
    //khai bao cho tiket...........................................
    bool dangmuab1 = 0, dangmuab2 = 0, dang_chon_chuyen_bay = 0, da_chon_phai = 0, da_nhap_du_in4 = 0, da_nhap_CMND = 0, trung_cmnd = 0, chon_ghe = 0;
    char ho[60], ten[30], CMND[30], idFlight_mua_ve[30]; bool phai; ho[0] = '\0'; ten[0] = '\0'; CMND[0] = '\0', idFlight_mua_ve[0] = '\0';
    //khai bao cho InStatic 
    dsmbc chay; int trangmaxmb = 1, somaybaymax = 0, tranghientaimb = 0, somayhienmb = 0;
    clearmouseclick(WM_LBUTTONDOWN);
    while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int x = mousex();
            int y = mousey();
            clearmouseclick(WM_LBUTTONDOWN);
            if (isMouseInPlanes(x, y) == 1) {
                dieukien = LISTPLANE;
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
                dieukien = LISTCUSTOMER;
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
                tranghientaicb1 = 1;
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
                if (chuyenbaycothedat != NULL) {
                    while (chuyenbaycothedat) {
                        ds qq;
                        qq = chuyenbaycothedat->next;
                        delete chuyenbaycothedat;
                        chuyenbaycothedat = qq;
                    }
                }
                lay_chuyen_bay_co_the_dat_ve(s, chuyenbaycothedat, sochuyenbayco1);
                tmpcb = NULL; addchuyenbay = false; suathongtin = false; chuyen_trang_xem_ds = false;
                chuyen_trang_tim_kiem = 0;
                sochuyenbayhien1 = 0;
                sotrangcb1 = 1;
                muaticket = false;
                capnhapchuyenbaycotmp = sochuyenbayco1;
                dangmuab1 = 0;
                dangmuab2 = 0;
                dang_chon_chuyen_bay = 0;
                da_nhap_CMND = 0;
                chon_ghe = 0;
                cap_nhat_trang_thai_cb(s);
                hientrangdau(chuyenbaycothedat, sochuyenbayhien1, sochuyenbayco1, sotrangcb1);
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




            //------------------------PLANE


            else if (TRANG_THAI_TAB == 1 && xem_thong_ke_mb == 1 && themmb == 0) {
                if (isMouseThemMayBay(x, y)) {
                    themmb = 1;
                    xem_thong_ke_mb = 0;
                    dieukien = ADDPLANE;
                    hienthemmaybay();

                }
                if (x >= 130 && x <= 900 && y >= 190 && y <= 680) {
                    int stt_may_bay = (y - 190) / 49 + trang_mb_hientai * 10;
                    xoa_mb_theo_stt(stt_may_bay, ds_mb, trang_mb_hientai, s);
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

            //------------------------FLIGHT

                        //timkiem
            else if ((TRANG_THAI_TAB == 2 && addchuyenbay == false && chuyen_trang_xem_ds == false || (TRANG_THAI_TAB == 4 && dangmuab1 == 0 && dangmuab2 == 0 && dang_chon_chuyen_bay == 0 && chon_ghe == 0) || (TRANG_THAI_TAB == 4 && dang_chon_chuyen_bay == 1 && chon_ghe == 0)) && (isMousenhapidFlight(x, y) == 1 || isMouseaddFlight(x, y) == 1 || isMousenhapDAY(x, y) == 1 || isMousenhapMONTH(x, y) == 1 || isMousenhapYEAR(x, y) == 1 || isMousenhapsomaybay(x, y) == 1)) {
                if (TRANG_THAI_TAB == 2) {
                    char dl1[30], dl2[30], dl3[30], dl4[30], dl5[30];
                    dl1[0] = '\0'; dl2[0] = '\0'; dl3[0] = '\0'; dl4[0] = '\0'; dl5[0] = '\0';
                    if (isMousenhapidFlight(x, y) == 1) {
                        cbtmp = 0, cbcotmp, sotrangtmp = 1;
                        nhapdulieu(185, 150, 184, 382, 141, 179, dl1, 12, 2);
                        STRCPYY(dlcb[0], dl1);
                        hien(dlcb[0], dlcb[1], dlcb[2], dlcb[3], dlcb[4], s, tmpcb, chuyen_trang_tim_kiem, TRANG_THAI_TAB, capnhapchuyenbaycotmp, cbcotmp, cbtmp, sotrangtmp);

                    }
                    if (isMousenhapDAY(x, y) == 1 || isMousenhapMONTH(x, y) == 1 || isMousenhapYEAR(x, y) == 1) {
                        int b;
                        if (isMousenhapDAY(x, y) == 1) {


                            b = 0;
                            char a[30] = "nhap >0 va <30";
                            nhapdulieu(469, 150, 468, 514, 141, 179, dl2, 2, 3);
                            if (b > 31) {
                                b = 31;
                            }
                            chuyencharsint(dl2, b);
                            if (b <= 0) {
                                dl2[0] = '\0';
                            }
                            STRCPYY(dlcb[1], dl2);
                            hien(dlcb[0], dlcb[1], dlcb[2], dlcb[3], dlcb[4], s, tmpcb, chuyen_trang_tim_kiem, TRANG_THAI_TAB, capnhapchuyenbaycotmp, cbcotmp, cbtmp, sotrangtmp);

                        }
                        if (isMousenhapMONTH(x, y) == 1) {


                            b = 0;
                            char a[30] = "nh?p >0 và =<12";
                            nhapdulieu(553, 150, 552, 597, 141, 179, dl3, 2, 3);
                            chuyencharsint(dl3, b);

                            if (b > 12) {
                                b = 12;
                            }
                            chuyencharsint(dl2, b);
                            if (b <= 0) {
                                dl2[0] = '\0';
                            }
                            STRCPYY(dlcb[2], dl3);
                            hien(dlcb[0], dlcb[1], dlcb[2], dlcb[3], dlcb[4], s, tmpcb, chuyen_trang_tim_kiem, TRANG_THAI_TAB, capnhapchuyenbaycotmp, cbcotmp, cbtmp, sotrangtmp);


                        }
                        if (isMousenhapYEAR(x, y) == 1) {


                            b = 0;
                            nhapdulieu(637, 150, 636, 733, 141, 179, dl4, 4, 3);
                            if (b < 2024) {
                                b = 2024;
                            }
                            chuyencharsint(dl4, b);


                            if (b <= 0) {
                                dl4[0] = '\0';
                            }
                            STRCPYY(dlcb[3], dl4);
                            hien(dlcb[0], dlcb[1], dlcb[2], dlcb[3], dlcb[4], s, tmpcb, chuyen_trang_tim_kiem, TRANG_THAI_TAB, capnhapchuyenbaycotmp, cbcotmp, cbtmp, sotrangtmp);

                        }

                    }
                    else if (isMousenhapsomaybay(x, y) == 1) {

                        nhapdulieu(886, 150, 886, 1082, 141, 179, dl5, 12, 2);
                        STRCPYY(dlcb[4], dl5);
                        hien(dlcb[0], dlcb[1], dlcb[2], dlcb[3], dlcb[4], s, tmpcb, chuyen_trang_tim_kiem, TRANG_THAI_TAB, capnhapchuyenbaycotmp, cbcotmp, cbtmp, sotrangtmp);

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
                else {
                    char dl1[30], dl2[30], dl3[30], dl4[30], dl5[30];
                    dl1[0] = '\0'; dl2[0] = '\0'; dl3[0] = '\0'; dl4[0] = '\0'; dl5[0] = '\0';
                    if (isMousenhapidFlight(x, y) == 1 && dangmuab1 == 0 && dangmuab2 == 0 && dang_chon_chuyen_bay == 1 && chon_ghe == 0) {
                        cbtmp = 0, cbcotmp, sotrangtmp = 1;
                        nhapdulieu(185, 150, 184, 382, 141, 179, dl1, 12, 2);
                        STRCPYY(dlcb[0], dl1);
                        hien(dlcb[0], dlcb[1], dlcb[2], dlcb[3], dlcb[4], chuyenbaycothedat, tmpcb, chuyen_trang_tim_kiem, TRANG_THAI_TAB, capnhapchuyenbaycotmp, cbcotmp, cbtmp, sotrangtmp,2);


                    }

                    if (isMousenhapidFlight(x, y) == 1 && dangmuab1 == 0 && dangmuab2 == 0 && dang_chon_chuyen_bay == 0 && chon_ghe == 0) {
                        cbtmp = 0, cbcotmp, sotrangtmp = 1;
                        nhapdulieu(185, 150, 184, 382, 141, 179, dl1, 12, 2);
                        STRCPYY(dlcb[0], dl1);
                        hien(dlcb[0], dlcb[1], dlcb[2], dlcb[3], dlcb[4], chuyenbaycothedat, tmpcb, chuyen_trang_tim_kiem, TRANG_THAI_TAB, capnhapchuyenbaycotmp, cbcotmp, cbtmp, sotrangtmp,1);
                       

                    }
                    if ((isMousenhapDAY(x, y) == 1 || isMousenhapMONTH(x, y) == 1 || isMousenhapYEAR(x, y) == 1) && dangmuab1 == 0 && dangmuab2 == 0 && dang_chon_chuyen_bay == 0 && chon_ghe == 0)  {
                        int b;
                        if (isMousenhapDAY(x, y) == 1) {

                            b = 0;
                            char a[30] = "nhap >0 va <30";
                            nhapdulieu(469, 150, 468, 514, 141, 179, dl2, 2, 3);
                            if (b > 31) {
                                b = 31;
                            }
                            chuyencharsint(dl2, b);
                            if (b <= 0) {
                                dl2[0] = '\0';
                            }
                            STRCPYY(dlcb[1], dl2);
                            hien(dlcb[0], dlcb[1], dlcb[2], dlcb[3], dlcb[4], chuyenbaycothedat, tmpcb, chuyen_trang_tim_kiem, TRANG_THAI_TAB, capnhapchuyenbaycotmp, cbcotmp, cbtmp, sotrangtmp,1);

                        }
                        if (isMousenhapMONTH(x, y) == 1) {

                            b = 0;
                            char a[30] = "nh?p >0 và =<12";
                            nhapdulieu(553, 150, 552, 597, 141, 179, dl3, 2, 3);
                            if (b > 12) {
                                b = 12;
                            }
                            chuyencharsint(dl3, b);
                            if (b <= 0) {
                                dl3[0] = '\0';
                            }

                            STRCPYY(dlcb[2], dl3);
                            hien(dlcb[0], dlcb[1], dlcb[2], dlcb[3], dlcb[4], chuyenbaycothedat, tmpcb, chuyen_trang_tim_kiem, TRANG_THAI_TAB, capnhapchuyenbaycotmp, cbcotmp, cbtmp, sotrangtmp,1);

                        }
                        if (isMousenhapYEAR(x, y) == 1) {


                            b = 0;
                            nhapdulieu(637, 150, 636, 733, 141, 179, dl4, 4, 3);
                            if (b < 2024) {
                                b = 2024;
                            }
                            chuyencharsint(dl4, b);

                            if (b <= 0) {
                                dl4[0] = '\0';
                            }
                            STRCPYY(dlcb[3], dl4);
                            hien(dlcb[0], dlcb[1], dlcb[2], dlcb[3], dlcb[4], chuyenbaycothedat, tmpcb, chuyen_trang_tim_kiem, TRANG_THAI_TAB, capnhapchuyenbaycotmp, cbcotmp, cbtmp, sotrangtmp,1);

                        }
                    }
                    if ((isMousenhapDAY(x, y) == 1 || isMousenhapMONTH(x, y) == 1 || isMousenhapYEAR(x, y) == 1) && dangmuab1 == 0 && dangmuab2 == 0 && dang_chon_chuyen_bay == 1 && chon_ghe == 0) {
                        int b;
                        if (isMousenhapDAY(x, y) == 1) {

                            b = 0;
                            char a[30] = "nhap >0 va <30";
                            nhapdulieu(469, 150, 468, 514, 141, 179, dl2, 2, 3);
                            if (b > 31) {
                                b = 31;
                            }
                            chuyencharsint(dl2, b);
                            if (b <= 0) {
                                dl2[0] = '\0';
                            }
                            STRCPYY(dlcb[1], dl2);
                            hien(dlcb[0], dlcb[1], dlcb[2], dlcb[3], dlcb[4], chuyenbaycothedat, tmpcb, chuyen_trang_tim_kiem, TRANG_THAI_TAB, capnhapchuyenbaycotmp, cbcotmp, cbtmp, sotrangtmp, 2);

                        }
                        if (isMousenhapMONTH(x, y) == 1) {

                            b = 0;
                            char a[30] = "nh?p >0 và =<12";
                            nhapdulieu(553, 150, 552, 597, 141, 179, dl3, 2, 3);
                            if (b > 12) {
                                b = 12;
                            }
                            chuyencharsint(dl3, b);
                            if (b <= 0) {
                                dl3[0] = '\0';
                            }

                            STRCPYY(dlcb[2], dl3);
                            hien(dlcb[0], dlcb[1], dlcb[2], dlcb[3], dlcb[4], chuyenbaycothedat, tmpcb, chuyen_trang_tim_kiem, TRANG_THAI_TAB, capnhapchuyenbaycotmp, cbcotmp, cbtmp, sotrangtmp,2);

                        }
                        if (isMousenhapYEAR(x, y) == 1) {


                            b = 0;
                            nhapdulieu(637, 150, 636, 733, 141, 179, dl4, 4, 3);
                            if (b < 2024) {
                                b = 2024;
                            }
                            chuyencharsint(dl4, b);

                            if (b <= 0) {
                                dl4[0] = '\0';
                            }
                            STRCPYY(dlcb[3], dl4);
                            hien(dlcb[0], dlcb[1], dlcb[2], dlcb[3], dlcb[4], chuyenbaycothedat, tmpcb, chuyen_trang_tim_kiem, TRANG_THAI_TAB, capnhapchuyenbaycotmp, cbcotmp, cbtmp, sotrangtmp, 2);

                        }
                    }
                    else if (isMousenhapsomaybay(x, y) == 1 && dangmuab1 == 0 && dangmuab2 == 0 && dang_chon_chuyen_bay == 1 && chon_ghe == 0) {

                        nhapdulieu(886, 150, 886, 1082, 141, 179, dl5, 12, 2);
                        STRCPYY(dlcb[4], dl5);
                        hien(dlcb[0], dlcb[1], dlcb[2], dlcb[3], dlcb[4], chuyenbaycothedat, tmpcb, chuyen_trang_tim_kiem, TRANG_THAI_TAB, capnhapchuyenbaycotmp, cbcotmp, cbtmp, sotrangtmp,2);

                    }

                    else if (isMousenhapsomaybay(x, y) == 1 && dangmuab1 == 0 && dangmuab2 == 0 && dang_chon_chuyen_bay == 0 && chon_ghe == 0) {

                        nhapdulieu(886, 150, 886, 1082, 141, 179, dl5, 12, 2);
                        STRCPYY(dlcb[4], dl5);
                        hien(dlcb[0], dlcb[1], dlcb[2], dlcb[3], dlcb[4], chuyenbaycothedat, tmpcb, chuyen_trang_tim_kiem, TRANG_THAI_TAB, capnhapchuyenbaycotmp, cbcotmp, cbtmp, sotrangtmp,1);

                    }
                    else if (isMouseaddFlight(x, y) == 1&&dangmuab1==0&&dangmuab2==0&&dang_chon_chuyen_bay==0&&chon_ghe==0) {
                        dangmuab1 = 1;
                        dangmuab2 = 0;
                        dang_chon_chuyen_bay = 0;
                        chon_ghe = 0;
                        cleardevice();
                        Screen_Default(TRANG_THAI_TAB);
                        Man_hinh_mua_ticket_b1();

                    }
                }
                }            //them cb
            //them
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
                                            if (a.tg.thang == 4 || a.tg.thang == 6 || a.tg.thang == 9 || a.tg.thang == 11) {
                                                if (a.tg.ngay > 30) {
                                                    char a[30] = "loi thoi gian";
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
                                             else if (a.tg.thang == 2) {                                                   
                                                        if (a.tg.ngay > 29) {
                                                            char a[30] = "loi thoi gian";
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
            else if (TRANG_THAI_TAB == 2 && chuyen_trang_xem_ds == true) {
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
                    tranghientaicb = 1;
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
                if (isMousexemtrangsau(x, y) == 1) {
                    chuyen_trang_xem_ds = true;
                    if (tranghientaixemdsv < sotrangxemdsv) {
                        tranghientaixemdsv++;
                        sophantuhiendsv = (tranghientaixemdsv - 1) * 10;
                        if (tranghientaixemdsv == sotrangxemdsv) {
                            hienthidanhsachve(xemds, dsvtmp, 3, sophantuhiendsv, sophantudsv, vitrighe);
                        }
                        else {
                            hienthidanhsachve(xemds, dsvtmp, 2, sophantuhiendsv, sophantudsv, vitrighe);

                        }
                    }
                }
                else if (isMousexemtrangtruoc(x, y) == 1) {
                    if (tranghientaixemdsv > 1) {
                        tranghientaixemdsv--;
                        sophantuhiendsv = (tranghientaixemdsv - 1) * 10;
                        hienthidanhsachve(xemds, dsvtmp, 2, sophantuhiendsv, sophantudsv, vitrighe);
                    }
                }
            }
            //chuyentrang
            else if ((TRANG_THAI_TAB == 2 || (TRANG_THAI_TAB == 4 && dangmuab1 == 0 && dangmuab2 == 0 && dang_chon_chuyen_bay == 0 && chon_ghe == 0) || (TRANG_THAI_TAB == 4 && dang_chon_chuyen_bay == 1 && chon_ghe == 0)) && chuyen_trang_tim_kiem == 0 && chuyen_trang_xem_ds == false && (isMousexemtrangsau(x, y) == 1 || isMousexemtrangtruoc(x, y) == 1)) {
                if (TRANG_THAI_TAB == 2) {

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
                else {
                    cout << "dell" << endl;

                    if (isMousexemtrangsau(x, y) == 1) {
                        if (tranghientaicb1 < sotrangcb1) {
                            tranghientaicb1++;
                            sochuyenbayhien1 = (tranghientaicb1 - 1) * 10;
                            if (tranghientaicb1 == sotrangcb1) {
                                hienthidschuyenbay(chuyenbaycothedat, sochuyenbayhien1, 3);
                            }
                            else {
                                hienthidschuyenbay(chuyenbaycothedat, sochuyenbayhien1, 2);
                            }
                        }
                    }
                    else if (isMousexemtrangtruoc(x, y) == 1) {
                        //tranghientaicb,sotrangcb,sochuyenbayco
                        if (tranghientaicb1 > 1) {
                            tranghientaicb1--;
                            sochuyenbayhien1 = (tranghientaicb1 - 1) * 10;
                            hienthidschuyenbay(chuyenbaycothedat, sochuyenbayhien1, 2);
                        }
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
            /*else if (TRANG_THAI_TAB == 2 && chuyen_trang_tim_kiem == 0 && chuyen_trang_xem_ds==true && (isMousexemtrangsau(x, y) == 1 || isMousexemtrangtruoc(x, y) == 1)) {
                if (isMousexemtrangsau(x, y) == 1) {
                    cout << "dell" << endl;
                    chuyen_trang_xem_ds = true;
                    if (tranghientaixemdsv < sotrangxemdsv) {
                        tranghientaixemdsv++;
                        sophantuhiendsv = (tranghientaixemdsv - 1) * 10;
                        if (tranghientaixemdsv == sotrangxemdsv) {
                            hienthidanhsachve(xemds, dsvtmp, 3, sophantuhiendsv, sophantudsv, vitrighe);
                        }
                        else {
                            hienthidanhsachve(xemds, dsvtmp, 2, sophantuhiendsv, sophantudsv, vitrighe);

                        }
                    }
                }
                else if (isMousexemtrangtruoc(x, y) == 1) {
                    if (tranghientaixemdsv > 1) {
                        tranghientaixemdsv--;
                        sophantuhiendsv = (tranghientaixemdsv - 1) * 10;
                        hienthidanhsachve(xemds, dsvtmp, 2, sophantuhiendsv, sophantudsv, vitrighe);
                    }
                }
            }*/
            //tra trang thai bang 1
            else if (TRANG_THAI_TAB == 2 && chuyen_trang_xem_ds == false && chuyen_trang_tim_kiem == 0 && addchuyenbay == false && suathongtin == false) {
                int sothutu;
                if (x >= 100 && x <= 1232 && y <= 689 && y >= 289) {
                    sothutu = 0;
                    sothutu = (y - 289) / 40 + 10 * (tranghientaicb - 1);
                    if (sothutu >= sochuyenbayco) {
                        continue;
                    }
                    else {
                        ds duyet = NULL; duyet = s; int dem = 0;
                        while (duyet != NULL) {
                            if (dem == sothutu) {
                                if (duyet->cb.trangthai == 4 || duyet->cb.trangthai == 1) {
                                    char a[200] = "chuyen bay ko the huy";
                                    hienthiloi(a);
                                    dem++;
                                    break;
                                }
                                else {
                                    dem++;
                                    string n = "ban co chac muon xoa cb ";
                                    string m = duyet->cb.macb;
                                    n += m;
                                    n += "khong";
                                    are_you_sure(n);
                                    while (1) {
                                        if (ismouseclick(WM_LBUTTONDOWN)) {
                                            int xx, yy;
                                            getmouseclick(WM_LBUTTONDOWN, xx, yy);
                                            if (isMouse_Yes_huy_ve(xx, yy)) {
                                                duyet->cb.trangthai = 1;
                                                /* char a[30] = "chuyen bay da huy";
                                                 hienthiloi(a);*/
                                                capnhatdulieu(s);
                                                break;
                                            }
                                            else if (isMouse_No_huy_ve(xx, yy)) {
                                                break;
                                            }
                                        }
                                    }
                                    /*                                    duyet->cb.trangthai = 1;
                                                                        char a[30] = "chuyen bay da huy";
                                                                        hienthiloi(a);
                                                                        capnhatdulieu(s);
                                                                        break;*/

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
                        chuyen_trang_xem_ds = false;
                        continue;
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
                            chuyen_trang_tim_kiem = false;
                        }
                        else {
                            hienthidanhsachve(xemds, dsvtmp, 3, sophantuhiendsv, sophantudsv, vitrighe);
                            chuyen_trang_xem_ds = true;
                            chuyen_trang_tim_kiem = false;
                        }
                    }
                }
            }
            else if (TRANG_THAI_TAB == 2 && chuyen_trang_xem_ds == false && chuyen_trang_tim_kiem == 1 && addchuyenbay == false && suathongtin == false) {
                int sothutu;
                if (x >= 100 && x <= 1232 && y <= 689 && y >= 289) {
                    sothutu = 0;
                    sothutu = (y - 289) / 40 + 10 * (tranghientmp - 1);
                    if (sothutu >= cbcotmp) {
                        continue;
                    }
                    else {
                        chuyenbay xoa;
                        xoa = laychuyenbay(tmpcb, sothutu);
                        ds duyet = NULL; duyet = s;
                        while (duyet != NULL) {
                            if (strcmp(duyet->cb.macb, xoa.macb) == 0) {
                                if (duyet->cb.trangthai == 4 || duyet->cb.trangthai == 1) {
                                    char a[130] = "chuyen bay ko the huy";
                                    hienthiloi(a);
                                    chuyen_trang_tim_kiem = 0;
                                    break;
                                }
                                else {
                                    string n = "ban co chac muon xoa cb ";
                                    string m = duyet->cb.macb;
                                    n += m;
                                    n += "khong";
                                    are_you_sure(n);
                                    while (1) {
                                        if (ismouseclick(WM_LBUTTONDOWN)) {
                                            int xx, yy;
                                            getmouseclick(WM_LBUTTONDOWN, xx, yy);
                                            if (isMouse_Yes_huy_ve(xx, yy)) {
                                                duyet->cb.trangthai = 1;
                                                /* char a[30] = "chuyen bay da huy";
                                                 hienthiloi(a);*/
                                                capnhatdulieu(s);
                                                chuyen_trang_tim_kiem = 0;
                                                break;
                                            }
                                            else if (isMouse_No_huy_ve(xx, yy)) {
                                                chuyen_trang_tim_kiem = 0;
                                                break;
                                            }
                                        }
                                    }
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
                        chuyen_trang_xem_ds = false;
                        continue;
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
                    tranghientaicb=1;
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
                                    if (tmpsua.tg.thang == 4 || tmpsua.tg.thang == 6 || tmpsua.tg.thang == 9 || tmpsua.tg.thang == 11) {
                                        if (tmpsua.tg.ngay > 30) {
                                            char a[30] = "loi thoi gian";
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
                                    else if (tmpsua.tg.thang == 2) {
                                        if (tmpsua.tg.ngay > 29) {
                                            char a[30] = "loi thoi gian";
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
                    }
                    else {
                        char l[30] = "ban can nhap du thong tin";
                        hienthiloi(l);
                    }

                }

            }


            //------------------CUSTOMER

            else if (TRANG_THAI_TAB == 3) {//hanhkhach
                char SearchID[30], SearchLastName[30], SearchFirstName[30];
                SearchID[0] = '\0'; SearchLastName[0] = '\0'; SearchFirstName[0] = '\0';
                if (isMouseSearchIdcustomer(x, y)) {
                    nhapdulieu(205, 140, 201, 399, 131, 169, SearchID, 12, 3);

                    STRCPYY(Search[0], SearchID);
                    Search_hanh_khach(Search[0], Search[1], Search[2], danh_sach_HK_O_tren_man_hinh, so_luong_hanh_khach_tim_thay, trang_curr, trang_max, xuat_search, cout_for_search);
                    PRINTF_SEARCH_CUSTOMER(so_luong_hanh_khach_tim_thay, trang_curr, trang_max, xuat_search, cout_for_search);
                    da_search_hk = 1;
                    trang_hien_tai = 0;
                }
                else if (isMouseSearchLastNamecustomer(x, y)) {
                    nhapdulieu(502, 140, 501, 699, 131, 169, SearchLastName, 30, 4);
                    STRCPYY(Search[1], SearchLastName);
                    Search_hanh_khach(Search[0], Search[1], Search[2], danh_sach_HK_O_tren_man_hinh, so_luong_hanh_khach_tim_thay, trang_curr, trang_max, xuat_search, cout_for_search);
                    PRINTF_SEARCH_CUSTOMER(so_luong_hanh_khach_tim_thay, trang_curr, trang_max, xuat_search, cout_for_search);                    da_search_hk = 1;
                    trang_hien_tai = 0;
                }
                else if (isMouseSearchFirstNameCustomer(x, y)) {
                    nhapdulieu(802, 140, 801, 949, 131, 169, SearchFirstName, 30, 5);
                    STRCPYY(Search[2], SearchFirstName);
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


            //------------------TICKET

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
                    nhapdulieu(405, 305, 401, 1000, 291, 340, dl1, 12, 3);
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
                    nhapdulieu(414, 235, 410, 1009, 221, 265, dl1, 60, 4);
                    STRCPYY(ho, dl1);
                }
                if (isMouseNhapTen_mua_ve(x, y) && dangmuab2) {
                    nhapdulieu(414, 335, 410, 1009, 321, 365, dl2, 30, 5);
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
                        sochuyenbayco1 = 0;
                        s = nullptr;
                        docdulieu(s, sochuyenbayco);
                        tmpcb = s; addchuyenbay = false; suachuyenbay = false;
                        chuyen_trang_tim_kiem = 0;
                        sochuyenbayhien1 = 0;
                        sotrangcb1 = 1;
                        capnhapchuyenbaycotmp = sochuyenbayco1;
                        hientrangdau(chuyenbaycothedat, sochuyenbayhien1, sochuyenbayco1, sotrangcb1);
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
                    tranghientaicb1 = 1;
                    /*sochuyenbayco1 = 0;*/
                    s = NULL;
                    docdulieu(s, sochuyenbayco);
                    tmpcb = NULL; addchuyenbay = false; suathongtin = false; chuyen_trang_xem_ds = false;
                    chuyen_trang_tim_kiem = 0;
                    sochuyenbayhien1 = 0;
                    sotrangcb1 = 1;
                    muaticket = false;
                    capnhapchuyenbaycotmp = sochuyenbayco1;
                    hientrangdau(chuyenbaycothedat, sochuyenbayhien1, sochuyenbayco1, sotrangcb1);
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
                        while (chuyenbaycothedat!=NULL) {
                            ds qq;
                            qq = chuyenbaycothedat->next;
                            delete chuyenbaycothedat;
                            chuyenbaycothedat = qq;
                        }
                        sochuyenbayco1 = 0;
                        tranghientaicb1 = 0;
                        sotrangcb1 = 0;
                        sochuyenbayhien1 = 0;

                        lay_chuyen_bay_co_the_dat_ve(s, chuyenbaycothedat, sochuyenbayco1);
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
                    /*sochuyenbayco1 = 0;*/
                    s = NULL;
                    docdulieu(s, sochuyenbayco);
                    tmpcb = NULL; addchuyenbay = false; suathongtin = false; chuyen_trang_xem_ds = false;
                    chuyen_trang_tim_kiem = 0;
                    sochuyenbayhien1 = 0;
                    sotrangcb1 = 1;
                    muaticket = false;
                    capnhapchuyenbaycotmp = sochuyenbayco1;
                    hientrangdau(chuyenbaycothedat, sochuyenbayhien1, sochuyenbayco1, sotrangcb1);
                }
            }
        }
        //chuot phai
        else if (ismouseclick(WM_RBUTTONDOWN)) {
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
            if (TRANG_THAI_TAB == 2 && chuyen_trang_tim_kiem == 0 && addchuyenbay == false && suathongtin == false) {
                if (x >= 100 && x <= 1232 && y <= 689 && y >= 289) {
                    vitrisua = 0;
                    vitrisua = (y - 289) / 40 + 10 * (tranghientaicb - 1);
                    if (vitrisua < sochuyenbayco) {
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
            else if (TRANG_THAI_TAB == 2 && chuyen_trang_tim_kiem == 1 && addchuyenbay == false && suathongtin == false) {
                if (x >= 100 && x <= 1232 && y <= 689 && y >= 289) {
                    vitrisua = 0;
                    vitrisua = (y - 289) / 40 + 10 * (tranghientmp - 1);
                    if (vitrisua < cbcotmp) {
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
                if (x >= 100 && x <= 1232 && y <= 689 && y >= 289) {
                    vitrisua = 0;
                    vitrisua = (y - 289) / 40 + 10 * (tranghientaicb1 - 1);
                    if (vitrisua >= sochuyenbayco1) {
                        chon_ghe = 0;
                        continue;
                    }
                    else {
                        chuyenbay b;
                        b = laychuyenbay(chuyenbaycothedat, vitrisua);
                        ds duyet = NULL; duyet = s;
                        while (strcmp(duyet->cb.macb, b.macb) != 0) {
                            duyet = duyet->next;
                        }
                        tmpsua = duyet->cb;
                        TRC_30p(b);
                        if (duyet->cb.trangthai == 1) {
                            char a[30] = "chuyen bay da huy";
                            hienthiloi(a);
                        }
                        else if (duyet->cb.trangthai == 4) {
                            char a[30] = "chuyen bay da hoan thanh";
                            hienthiloi(a);
                        }
                        else {
                            cleardevice();

                            Screen_Default(4);
                            int soday = 10, sodong = 5;
                            soday = ds_mb.nodes[timkiem(ds_mb, duyet->cb.sohieu)]->soday;
                            sodong = ds_mb.nodes[timkiem(ds_mb, duyet->cb.sohieu)]->sodong;
                            Man_hinh_mua_ticket_b4(duyet->cb, soday, sodong);
                            dang_chon_chuyen_bay = 0;
                            chon_ghe = 1;
                            suathongtin = true;
                        }
                    }
                    /*if (isMousechuyenbay1(x, y) == 1) {
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

                }*/
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
                keepRunning = 0;
                t.join();
                break;
            }
        }
    }
}

int main() {

    cout << "no000000000" << endl;

    initwindow(1540, 800, "install_graphics_h");
    Screen_Default(0);
    AO_THAT_DAY();
    Lay_chi_so();
    getch();
    closegraph();



    //ds_hk.lay_du_lieu_tu_file();
    //ds_hk.printf_ds(ds_hk.getRoot());

    //ds_hk.remove(ds_hk.getRoot(), const_cast<char*>("000000000011"));
    //cout << "\n dda remove \n";
    //ds_hk.printf_ds(ds_hk.getRoot());

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