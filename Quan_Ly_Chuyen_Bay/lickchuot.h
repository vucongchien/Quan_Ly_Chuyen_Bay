#pragma once
bool isMouseInPlanes(int x, int y) {
    if (x >= 40 && x <= 250 && y >= 10 && y <= 80) {
        return 1;
    }
    return 0;
}
bool isMouseInFlight(int x, int y) {
    if (x >= 280 && x <= 490 && y >= 10 && y <= 80) {
        return 1;
    }
    return 0;
}
bool isMouseInCustomer(int x, int y) {
    if (x >= 520 && x <= 730 && y >= 10 && y <= 80) {
        return 1;
    }
    return 0;
}
bool isMouseInTicket(int x, int y) {
    if (x >= 760 && x <= 970 && y >= 10 && y <= 80) {
        return 1;
    }
    return 0;
}
bool isMouseInStatic(int x, int y) {
    if (x >= 1000 && x <= 1210 && y >= 10 && y <= 80) {
        return 1;
    }
    return 0;
}
bool isMousenhapidFlight(int x, int y) {
    if (x >= 180 && x <= 383 && y >= 140 && y <= 180) {
        return 1;
    }
    return 0;
}
bool isMouseaddFlight(int x, int y) {
    if (x >= 1294 && x <= 1390 && y >= 140 && y <= 180) {
        return 1;
    }
    return 0;
}
bool isMousenhapDAY(int x, int y) {
    if (x >= 466 && x <= 514 && y >= 140 && y <= 180) {
        return 1;
    }
    return 0;
}
bool isMousenhapMONTH(int x, int y) {
    if (x >= 550 && x <= 597 && y >= 140 && y <= 180) {
        return 1;
    }
    return 0;
}
bool isMousenhapYEAR(int x, int y) {
    if (x >= 634 && x <= 733 && y >= 140 && y <= 180) {
        return 1;
    }
    return 0;
}
bool isMousenhapsomaybay(int x, int y) {
    if (x >= 884 && x <= 1082 && y >= 140 && y <= 180) {
        return 1;
    }
    return 0;
}
// theem chuyeen bay
bool isMouseback(int x, int y) {
    if (x >= 56 && x <= 124 && y >= 135 && y <= 174) {
        return 1;
    }
    return 0;
}
bool isMouseaddidflight(int x, int y) {
    if (x >= 440 && x <= 1046 && y >= 221 && y <= 265) {
        return 1;
    }
    return 0;
}
bool isMouseaddmamaybay(int x, int y) {
    if (x >= 440 && x <= 1046 && y >= 320 && y <= 363) {
        return 1;
    }
    return 0;
}
bool isMouseaddnoiden(int x, int y) {
    if (x >= 440 && x <= 1046 && y >= 422 && y <= 457) {
        return 1;
    }
    return 0;
}
bool isMouseaddday(int x, int y) {
    if (x >= 440 && x <= 515 && y >= 519 && y <= 563) {
        return 1;
    }
    return 0;
}
bool isMouseaddthang(int x, int y) {
    if (x >= 527 && x <= 596 && y >= 519 && y <= 563) {
        return 1;
    }
    return 0;

}
bool isMouseaddyear(int x, int y) {
    if (x >= 610 && x <= 678 && y >= 519 && y <= 563) {
        return 1;
    }
    return 0;
}
bool isMouseaddgio(int x, int y) {
    if (x >= 703 && x <= 771 && y >= 519 && y <= 563) {
        return 1;
    }
    return 0;
}
bool isMouseaddphut(int x, int y) {
    if (x >= 785 && x <= 854 && y >= 519 && y <= 563) {
        return 1;
    }
    return 0;
}
bool isMousetimmaybay(int x, int y) {
    if (x >= 1071 && x <= 1142 && y >= 322 && y <= 357) {
        return 1;
    }
    return 0;
}
bool isMousesave(int x, int y) {
    if (x >= 1324 && x <= 1416 && y >= 660 && y <= 709) {
        return 1;
    }
    return 0;
}
bool isMousexemtrangtruoc(int x, int y) {
    if (x >= 689 && x <= 747 && y >= 720 && y <= 764) {
        return 1;
    }
    return 0;
}
bool isMousexemtrangsau(int x, int y) {
    if (x >= 821 && x <= 879 && y >= 720 && y <= 764) {
        return 1;
    }
    return 0;
}
//chon phan tu
bool isMousechuyenbay1(int x, int y) {
    if (x >= 100 && x <= 1232 && y >= 289 && y <= 329) {
        return 1;
    }
    return 0;
}
bool isMousexemds1(int x, int y) {
    if (x >= 1232 && x <= 1439 && y >= 289 && y <= 329) {
        return 1;
    }
    return 0;
}
bool isMousechuyenbay2(int x, int y) {
    if (x >= 100 && x <= 1232 && y >= 329 && y <= 369) {
        return 1;
    }
    return 0;
}
bool isMousexemds2(int x, int y) {
    if (x >= 1232 && x <= 1439 && y >= 329 && y <= 369) {
        return 1;
    }
    return 0;
}
bool isMousechuyenbay3(int x, int y) {
    if (x >= 100 && x <= 1232 && y >= 369 && y <= 409) {
        return 1;
    }
    return 0;
}
bool isMousexemds3(int x, int y) {
    if (x >= 1232 && x <= 1439 && y >= 369 && y <= 409) {
        return 1;
    }
    return 0;
}
bool isMousechuyenbay4(int x, int y) {
    if (x >= 100 && x <= 1232 && y >= 409 && y <= 449) {
        return 1;
    }
    return 0;
}
bool isMousexemds4(int x, int y) {
    if (x >= 1232 && x <= 1439 && y >= 409 && y <= 449) {
        return 1;
    }
    return 0;
}
bool isMousechuyenbay5(int x, int y) {
    if (x >= 100 && x <= 1232 && y >= 449 && y <= 489) {
        return 1;
    }
    return 0;
}
bool isMousexemds5(int x, int y) {
    if (x >= 1232 && x <= 1439 && y >= 449 && y <= 489) {
        return 1;
    }
    return 0;
}
bool isMousechuyenbay6(int x, int y) {
    if (x >= 100 && x <= 1232 && y >= 489 && y <= 529) {
        return 1;
    }
    return 0;
}
bool isMousexemds6(int x, int y) {
    if (x >= 1232 && x <= 1439 && y >= 489 && y <= 529) {
        return 1;
    }
    return 0;
}
bool isMousechuyenbay7(int x, int y) {
    if (x >= 100 && x <= 1232 && y >= 529 && y <= 569) {
        return 1;
    }
    return 0;
}
bool isMousexemds7(int x, int y) {
    if (x >= 1232 && x <= 1439 && y >= 529 && y <= 569) {
        return 1;
    }
    return 0;
}
bool isMousechuyenbay8(int x, int y) {
    if (x >= 100 && x <= 1232 && y >= 569 && y <= 609) {
        return 1;
    }
    return 0;
}
bool isMousexemds8(int x, int y) {
    if (x >= 1232 && x <= 1439 && y >= 569 && y <= 609) {
        return 1;
    }
    return 0;
}
bool isMousechuyenbay9(int x, int y) {
    if (x >= 100 && x <= 1232 && y >= 609 && y <= 649) {
        return 1;
    }
    return 0;
}
bool isMousexemds9(int x, int y) {
    if (x >= 1232 && x <= 1439 && y >= 609 && y <= 649) {
        return 1;
    }
    return 0;
}
bool isMousechuyenbay10(int x, int y) {
    if (x >= 100 && x <= 1232 && y >= 649 && y <= 689) {
        return 1;
    }
    return 0;
}
bool isMousexemds10(int x, int y) {
    if (x >= 1232 && x <= 1439 && y >= 649 && y <= 689) {
        return 1;
    }
    return 0;
}
//-------------mua ve 
bool isMouseNEXT(int x, int y) {
    if (x >= 1282 && x <= 1370 && y >= 420 && y <= 460)
        return 1;
    return 0;
}
bool isMouseNhapCMND_MUA_VE(int x, int y) {
    if (x >= 400 && x <= 1000 && y >= 290 && y <= 340) {
        return 1;
    }
    return 0;
}
bool isMouseNhapHo_mua_ve(int x, int y) {
    if (x >= 409 && y >= 220 && x <= 1009 && y <= 265) {
        return 1;
    }
    return 0;
}
bool isMouseNhapTen_mua_ve(int x, int y) {
    if (x >= 409 && y >= 320 && x <= 1009 && y <= 365) {
        return 1;
    }
    return 0;
}
bool isMouseLaNam(int x, int y) {
    if (x >= 409 && x <= 606 && y >= 420 && y <= 465) {
        return 1;
    }
    return 0;
}
bool isMouseLaNu(int x, int y) {
    if (x >= 635 && x <= 836 && y >= 420 && y <= 465) {
        return 1;
    }
    return 0;
}
bool isMouseSearchChuyenBay_mua_ve(int x, int y) {
    if (x >= 409 && x <= 1009 && y >= 520 && y <= 565) {
        return 1;
    }
    return 0;
}
bool isMouseChonGhe(int x, int y) {
    if (x >= 500 && y >= 130 && x <= 600 && y <= 170)
        return 1;
    return 0;
}
bool isMouse_dang_mua_ve_back_ve_chon_cb(int x, int y) {
    if (x >= 100 && y >= 130 && x <= 200 && y <= 170)
        return 1;
    return 0;
}
bool isMouse_No_huy_ve(int x, int y) {
    if (x >= 850 && y >= 440 && x <= 920 && y <= 480)
        return 1;
    return 0;
}
bool isMouse_Yes_huy_ve(int x, int y) {
    if (x >= 510 && y >= 440 && x <= 590 && y <= 480)
        return 1;
    return 0;
}
//-------------customer
bool isMouseSearchIdcustomer(int x, int y) {
    if (x >= 200 && x <= 400 && y >= 130 && y <= 170) {
        return 1;
    }
    return 0;
}
bool isMouseSearchFirstNameCustomer(int x, int y) {
    if (x >= 800 && x <= 950 && y >= 130 && y <= 170)
        return 1;
    return 0;
}
bool isMouseSearchLastNamecustomer(int x, int y) {
    if (x >= 500 && x <= 700 && y >= 130 && y <= 170)
        return 1;
    return 0;
}

bool isMouseCHUYEN_TRANG_SANG_PHAI(int x, int y) {
    if (x >= 730 && x <= 780 && y >= 720 && y <= 750) {
        return 1;
    }
    return 0;
}
bool isMouseCHUYEN_TRANG_SANG_TRAI(int x, int y) {
    if (x >= 670 && x <= 720 && y >= 720 && y <= 750) {
        return 1;
    }
    return 0;
}
//plane
bool isMouseThemMayBay(int x, int y) {
    if (x >= 921 && x <= 1130 && y >= 371 && y <= 441)
        return 1;
    return 0;
}
bool isMouseXoaMayBay(int x, int y) {
    if (x >= 921 && x <= 1130 && y >= 447 && y <= 525)
        return 1;
    return 0;
}
bool isMouseSuaMayBay(int x, int y) {
    if (x >= 921 && x <= 1130 && y >= 233 && y <= 602)
        return 1;
    return 0;
}
bool isMouseNhapIdMayBay(int x, int y) {
    if (x >= 1028 && x <= 1299 && y >= 193 && y <= 229) {
        return 1;
    }
    return 0;
}
bool isMouseNhapTypeMayBay(int x, int y) {
    if (x >= 1028 && x <= 1299 && y >= 238 && y <= 274)
        return 1;
    return 0;
}
bool isMouseNhapDayMayNay(int x, int y) {
    if (x >= 1028 && x <= 1299 && y >= 284 && y <= 320) {
        return 1;
    }
    return 0;
}
bool isMouseNhapDongMayBay(int x, int y) {
    if (x >= 1028 && x <= 1299 && y >= 328 && y <= 365)
        return 1;
    return 0;
}
bool isMouseNhapDONG_them_mb(int x, int y) {
    if (x >= 440 && x <= 1046 && y >= 519 && y <= 563) {
        return 1;
    }
    return 0;
}
bool isMousechonmaybay(int x, int y) {
    if (x >= 1071 && x <= 1140 && y >= 320 && y <= 360) {
        return 1;
    }
    return 0;
}
bool isMouseNEXT_PAGE_MB(int x, int y) {
    if (x >= 540 && x <= 590 && y >= 700 && y <= 735) {
        return 1;
    }
    return 0;
}
bool isMouseBACK_PAGE_MB(int x, int y) {
    if (x >= 410 && x <= 460 && y >= 700 && y <= 735) {
        return 1;
    }
    return 0;
}