#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
#include<sstream>
#include"graphics.h"
using namespace std;
void hienthiloi(char a[]) {

    std::wstring message = std::wstring(a, a + strlen(a));


    LPCWSTR messagePtr = message.c_str();


    MessageBox(NULL, messagePtr, L"notification", MB_OK);
}
void STRCPYY(char a[], char b[]) {
    for (int i = 0; i < strlen(b); i++) {
        a[i] = b[i];
    }
    a[strlen(b)] = '\0';
}
void chuyencharsint(char a[], int& b) {
    int dem = 0;
    for (int i = 0; a[i] != '\0'; i++) {
        dem++;
    }
    for (int i = 0; i < dem; i++) {
        char c = a[i];
        b = b * 10 + (c - '0');
    }
}
void chuyenintschar(char a[], int b) {
    int tmp = 0;
    int i = 0;

    if (b == 0) {
        a[0] = '0';
        a[1] = '\0'; // K?t thúc chu?i
        return;
    }

    do {
        tmp = b % 10;
        a[i] = tmp + '0';
        b = b / 10;
        i++;
    } while (b != 0);

    for (int d = 0; d < i / 2; d++) {
        char tmp1 = a[d];
        a[d] = a[i - 1 - d];
        a[i - 1 - d] = tmp1;
    }
    a[i] = '\0'; // K?t thúc chu?i
}
void chuyencharssint(char a[], long long& b) {
    int dem = 0;
    for (int i = 0; a[i] != '\0'; i++) {
        dem++;
    }
    b = 0;
    for (int i = 0; i < dem; i++) {
        char c = a[i];
        if (c >= '0' && c <= '9') {
            b = b * 10 + (c - '0');
        }
        else {
            break;
        }
    }
}
int sosanh_CMND(char a[], char b[]) {

    long long cmnd1, cmnd2;
    chuyencharssint(a, cmnd1);
    chuyencharssint(b, cmnd2);


    if (cmnd1 < cmnd2) {
        return -1;
    }
    else if (cmnd1 > cmnd2) {
        return 1;
    }
    else {
        return 0;
    }
}
struct HanhKhach {
    char soCMND[30];
    string ho;
    string ten;
    string phai;
};
void nhap_thong_tin_HanhKhach(HanhKhach& hk) {
    std::cin >> hk.soCMND;
    std::cin >> hk.ho >> hk.ten >> hk.phai;
}
struct Node {
    HanhKhach data;
    Node* left;
    Node* right;
    int height;
};
class QLHK {
private:
    //goc
    Node* root;
    int so_luong;
    int height(Node* N) {
        if (N == NULL) {
            return 0;
        }
        return N->height;
    }
    Node* newNode(HanhKhach hanhkhack) {
        Node* newnode = new Node();
        newnode->data = hanhkhack;
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->height = 1;
        return newnode;
    }
    Node* rightRotate(Node* y) {
        
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }
    Node* leftRotate(Node* x) {
        
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }
    int getBlance(Node* N) {
        if (N == NULL) {
            return 0;
        }
        return height(N->left) - height(N->right);
    }
    Node* insertUtil(Node* node, HanhKhach hanhkhach) {
        if (node == NULL) {
            return newNode(hanhkhach);
        }
        int a, b;

        if (sosanh_CMND(hanhkhach.soCMND, node->data.soCMND) == -1) {
            node->left = insertUtil(node->left, hanhkhach);
        }
        else if (sosanh_CMND(hanhkhach.soCMND, node->data.soCMND) == 1) {
            node->right = insertUtil(node->right, hanhkhach);
        }
        else {
            //trung nhau bao loi 
            return node;
        }

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBlance(node);

        if (balance > 1 && sosanh_CMND(hanhkhach.soCMND, node->left->data.soCMND) == -1) {
            return rightRotate(node);
        }

        if (balance < -1 && sosanh_CMND(hanhkhach.soCMND, node->right->data.soCMND) == 1) {
            return leftRotate(node);
        }

        if (balance > 1 && sosanh_CMND(hanhkhach.soCMND, node->left->data.soCMND) == 1) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && sosanh_CMND(hanhkhach.soCMND, node->right->data.soCMND) == -1) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

public:
    QLHK() {
        root = NULL;
        so_luong = 0;
    }
    Node* insert(HanhKhach hanhkhach) {
        root = insertUtil(root, hanhkhach);
        so_luong++;
        return root;
    }
    void printf_ds(Node* run) {
        if (run == NULL) {
            return;
        }
        printf_ds(run->left); // Duyệt qua cây con trái
        cout << "CMND: " << run->data.soCMND << endl;
        cout << "ho: " << run->data.ho << endl << "ten: " << run->data.ten << endl;
        cout << "Gen: " << run->data.phai << endl;
        cout << "---------------------" << endl;
        printf_ds(run->right); // Duyệt qua cây con phải
    }
    HanhKhach search(char CMND[]) {
        Node* curr = root;
        while (curr != NULL) {

            if (sosanh_CMND(CMND, curr->data.soCMND) == -1) {
                curr = curr->left;
            }
            else if (sosanh_CMND(CMND, curr->data.soCMND) == 1) {
                curr = curr->right;
            }
            else {
                cout << curr->data.soCMND << endl;
                return curr->data;
            }
        }
        HanhKhach empty;
        empty.soCMND[0] = '\0'; // Set soCMND to empty string
        empty.ho = "";
        empty.ten = "";
        empty.phai = "";
        //cout << "k trung" << endl;
        return empty;
    }

       
    Node* remove(Node* run, char CMND[30]) {
        if (run == NULL) {
            return run;
        }

        int result = strcmp(run->data.soCMND, CMND);

        if (result > 0) {
            run->left = remove(run->left, CMND);
        }
        else if (result < 0) {
            run->right = remove(run->right, CMND);
        }
        else {
            // Nút cần xóa có một hoặc không có con
            if (run->left == NULL) {
                Node* temp = run->right;
                delete run;
                so_luong--;
                return temp;
            }
            else if (run->right == NULL) {
                Node* temp = run->left;
                delete run;
                so_luong--;
                return temp;
            }

            // Nút cần xóa có hai con
            Node* temp = minValueNode(run->right);

            run->data = temp->data;

            run->right = remove(run->right, temp->data.soCMND);
            so_luong--;
        }
        if (run == NULL) {
            return run;
        }
        //can bang cayyyyyyyyyyyyyy wtf
        run->height = 1 + max(height(run->left), height(run->right));

        int balance = getBlance(run);

        if (balance > 1 && getBlance(run->left) >= 0)
            return rightRotate(run);

        if (balance > 1 && getBlance(run->left) < 0) {
            run->left = leftRotate(run->left);
            return rightRotate(run);
        }

        if (balance < -1 && getBlance(run->right) <= 0)
            return leftRotate(run);

        if (balance < -1 && getBlance(run->right) > 0) {
            run->right = rightRotate(run->right);
            return leftRotate(run);
        }


        return run;
    }

    // Hàm hỗ trợ tìm nút nhỏ nhất 
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }
    Node* getRoot() {
        return root;
    }
    void xoa_va_cap_nhat_file(Node* root) {

        ofstream file("hanhkhach.txt");
        file.close();
        // Gọi hàm để ghi lại nội dung mới từ cây nhị phân vào tệp
        them_vao_file(root);
    }

    void them_vao_file(Node* run) {
        if (run == NULL) {
            return;
        }
        ofstream file;
        file.open("hanhkhach.txt", ios::app);
        string tmp(run->data.soCMND);
        cout << run->data.soCMND;
        file << tmp << ",";
        file << run->data.ho << "," << run->data.ten << ",";
        file << run->data.phai << endl;
        file.close();
        them_vao_file(run->left);
        them_vao_file(run->right);
    }
    void lay_du_lieu_tu_file() {
        ifstream file("hanhkhach.txt");
        if (!file.is_open()) {
            cout << "Khong the mo file hanhkhach.h!" << endl;
            return;
        }
        string line;
        while (getline(file, line)) {
            HanhKhach hk;
            stringstream ss(line);
            string item, ho, CMND, ten, phai;
            int dem = 0;
            ss.getline(hk.soCMND, sizeof(hk.soCMND), ',');
            getline(ss, line, ',');
            hk.ho = line;
            getline(ss, line, ',');
            hk.ten = line;
            getline(ss, line, ',');
            hk.phai = line;
            root = insert(hk);
        }
        file.close();
    }
    void cap_nhat_so_ve_hk_da_mua() {

    }
    int getSo_luong_hk() {
        return so_luong;
    }

};
int so_luong_hanh_khach = 1;//sau nay viet trong hanhkhach.h
int so_trang_hanh_khach = 0;
QLHK ds_hk;
