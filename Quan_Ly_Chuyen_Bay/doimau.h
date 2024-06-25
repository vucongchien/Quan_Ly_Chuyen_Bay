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

#include"FUNTION.h"
using namespace std;

enum dieukienpage
{
    LISTPLANE, ADDPLANE, LISTCUSTOMER
};
void threadFunction(int& TRANG_THAI_TAB, bool& keepRunning, dieukienpage& dieukien) {

    enum button_page1 { next, back };
    bool doimau_page1[2];
    for (int i = 0; i < 2; i++) {
        doimau_page1[i] = 0;
    }
    int xx1 = 88, yy1 = 214, rr=10;
    //900 680 fillellipse(xx, yy, rr, rr); 88 214

    enum button_page2 { ID, LASTNAME, FIRSTNAME };
    bool doimau_page2[3];
    doimau_page2[ID] = doimau_page2[LASTNAME] = doimau_page2[FIRSTNAME] = 0;

    while (keepRunning) {
        int x = mousex();
        int y = mousey();
        if (TRANG_THAI_TAB == 1 && dieukien == LISTPLANE)
        {
          
            if (isMouseNEXT_PAGE_MB(x, y)) {
                if (doimau_page1[next] == 0)
                {
                    ve_hinh_vuong(540, 700, 590, 735, COLOR(170, 215, 217), 0, const_cast<char*>(">"), 1, 0);
                    doimau_page1[next] = 1;
                }
            }
            else {
                if (doimau_page1[next] == 1)
                {
                    ve_hinh_vuong(540, 700, 590, 735, COLOR(217, 234, 211), 0, const_cast<char*>(">"), 1, 0);
                    doimau_page1[next] = 0;
                }
            }


            if (isMouseBACK_PAGE_MB(x, y)) {
                if (doimau_page1[back] == 0)
                {
                    ve_hinh_vuong(410, 700, 460, 735, COLOR(170, 215, 217), 0, const_cast<char*>("<"), 1, 0);
                    doimau_page1[back] = 1;
                }
            }
            else {
                if (doimau_page1[back] == 1)
                {
                    ve_hinh_vuong(410, 700, 460, 735, COLOR(217, 234, 211), 0, const_cast<char*>("<"), 1, 0);
                    doimau_page1[back] = 0;
                }
            }


        
        }

    }
}