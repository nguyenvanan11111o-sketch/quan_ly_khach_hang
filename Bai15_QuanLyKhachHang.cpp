#include <iostream>
#include <string>
using namespace std;

struct KhachHang
{
    int maKhachHang;
    string tenKhachHang;
    string soDienThoai;
    double tongTienThanhToan;
};

void nhapDanhSach(KhachHang a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap thong tin khach hang thu " << i + 1 << ":\n";
        cout << "Ma khach hang: ";
        cin >> a[i].maKhachHang;
        cin.ignore();

        cout << "Ten khach hang: ";
        getline(cin, a[i].tenKhachHang);

        cout << "So dien thoai: ";
        getline(cin, a[i].soDienThoai);

        cout << "Tong tien thanh toan: ";
        cin >> a[i].tongTienThanhToan;
    }
}

void xuatDanhSach(KhachHang a[], int n)
{
    cout << "\n===== DANH SACH KHACH HANG =====\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nKhach hang " << i + 1 << ":\n";
        cout << "Ma KH: " << a[i].maKhachHang << endl;
        cout << "Ten KH: " << a[i].tenKhachHang << endl;
        cout << "So dien thoai: " << a[i].soDienThoai << endl;
        cout << "Tong tien: " << a[i].tongTienThanhToan << endl;
    }
}

// Sap xep chen tang dan theo tong tien thanh toan
void insertionSort(KhachHang a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        KhachHang x = a[i];
        int j = i - 1;

        while (j >= 0 && a[j].tongTienThanhToan > x.tongTienThanhToan)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = x;
    }
}

// Tim kiem nhi phan
int binarySearch(KhachHang a[], int n, double X)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (a[mid].tongTienThanhToan == X)
            return mid;
        else if (a[mid].tongTienThanhToan < X)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

void hienThiKhachHangBangX(KhachHang a[], int n, double X)
{
    int vt = binarySearch(a, n, X);

    if (vt == -1)
    {
        cout << "\nKhong co khach hang nao co tong tien bang " << X << endl;
        return;
    }

    int i = vt;

    // Tim ve khach hang dau tien co tong tien bang X
    while (i >= 0 && a[i].tongTienThanhToan == X)
        i--;

    i++;

    cout << "\n===== KHACH HANG CO TONG TIEN BANG " << X << " =====\n";

    while (i < n && a[i].tongTienThanhToan == X)
    {
        cout << "\nMa KH: " << a[i].maKhachHang << endl;
        cout << "Ten KH: " << a[i].tenKhachHang << endl;
        cout << "So dien thoai: " << a[i].soDienThoai << endl;
        cout << "Tong tien: " << a[i].tongTienThanhToan << endl;
        i++;
    }
}

int main()
{
    int n;

    cout << "Nhap so luong khach hang: ";
    cin >> n;

    KhachHang a[100];

    // Cau 2: Nhap
    nhapDanhSach(a, n);

    // Cau 3: Xuat
    cout << "\n\nDANH SACH VUA NHAP:";
    xuatDanhSach(a, n);

    // Cau 4: Sap xep chen tang dan
    insertionSort(a, n);

    cout << "\n\nDANH SACH SAU KHI SAP XEP:";
    xuatDanhSach(a, n);

    // Cau 5: Tim kiem nhi phan
    double X;
    cout << "\n\nNhap X can tim: ";
    cin >> X;

    hienThiKhachHangBangX(a, n, X);

    return 0;
}
