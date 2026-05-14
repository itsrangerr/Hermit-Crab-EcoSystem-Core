#include <iostream>
#include <cstring>

void layTenLoai(char* log, char* ketQua){
    int count = 0;
    char* ptr = log;

    while (*ptr != '\0') {
        if (*ptr == ':') {
            count++;
            if (count == 3) {
                ptr++; 
                break;
            }
        }
        ptr++;
    }

    
    int i = 0;
    while (*ptr != '\0') {
        ketQua[i++] = *ptr++;
    }
    ketQua[i] = '\0'; 
}
bool kiemTraLotXac(int* a, int n){
    if(*(a+n-1)<80)
        return false;
    if (n == 1)
        return true;    
    return kiemTraLotXac(a, n-1);
}
int **taoMangDong(int m, int n){
    int **a = new int*[m];
    for (int i = 0; i < m; i++) {
        a[i] = new int[n];
    }
    return a;
}
int* timKhuVucKhoNhat(int **a, int r, int c){
    int min = INT_MAX;
    int rM , cM;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (*(*(a+i)+j) < min){
                min = *(*(a+i)+j);
                rM= i;
                cM = j;
                }

        }
        
    }
    return &*(*(a+rM)+cM);

    }

void xuatMang(int **a , int r , int c){
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            std::cout << *(*(a+i)+j) << " ";
        }
        std::cout << std::endl;
    }
}
int main() {
    
    char log[] = "TMP:28-HUM:82-CRAB:Violascens";
    
    char ketQua[100] = "";
    layTenLoai(log, ketQua);
    
    std::cout << "Ket qua: " << ketQua << std::endl;

    int doAm[7] = {82, 85, 80, 88, 81, 83, 86};
    bool lotXac = kiemTraLotXac(doAm, 7);
    std::cout << "Lot xac: " << (lotXac ? "Do am tot" : "Do am te") << std::endl;

    int r,m;
    std::cout << "Nhap so hang: ";
    std::cin >> r;
    std::cout << "Nhap so cot: ";
    std::cin >> m;
    
    int **a = taoMangDong(r, m);

    std::cout << "Nhap gia tri cho mang: " << std::endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
        }
    }
    xuatMang(a,r,m);
    int *max = timKhuVucKhoNhat(a, r, m);
    std::cout << "Gia tri nho nhat trong mang: " << *max << std::endl;
    *max = 85;
    std::cout << "Gia tri nho nhat sau khi thay doi: " << *max << std::endl;
    xuatMang(a,r,m);
    
    for (int i = 0; i < r; i++) {
        delete[] a[i];
    }
    delete[] a;

    system("pause");
    return 0;
}
