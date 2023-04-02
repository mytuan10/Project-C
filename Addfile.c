// /* Khai bao kieu du lieu Sinh Vien cac truong Ho ten, Gioi tinh, diem toan, diem hoa, diem van diem trung binh.
// Nhap vao danh sach Sinh Vien 
// Xuat danh sach Sinh Vien
// Tong diem trung binh cua Sinh Vien 
// Sap xep Sinh Vien theo thu tu tang dan, cac diem trung binh 
// Xep loai N sinh vien
// Xuat danh sach N sinh vien ra File
// Viet chuong trinh menu cho phep su dung cac tinh nang tren 
// cac kien thuc o day la: struct, file, ham, su dung cau dieu kien, re nhanh if else, switch case, 
// */

#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

struct SinhVien
{
    char name[30];
    char gt[30];
    int age ;
    float math, physics, chemistry;
    float dtb = 0;
};

typedef SinhVien SV;

void nhap(SV &sv);
void nhapN(SV a[], int n);
void tinhDTB(SV &sv);
void xuat(SV sv);
void xuatN(SV a[], int n);
void sapXep(SV a[], int n);
void xepLoai(SV a[], int n);
void xepLoaiN(SV a[], int n);
void xuatFile(SV a[], int n, char fileName[]);

int main()
{
    int key; 
    char fileName[] = "DSSV.txt";
    int n;
    bool daNhap = false;
    do
    {
        printf("Nhap so luong SV n = ");
        scanf("%d",&n);

    } while (n <= 0);
    
    SV a[n];
    while(true)
    {
        system("cls");                                                      // dung de xoa man hÃ¬nh, luc nay chuong cua minh se in ra Cac dong phia duoi.          
        printf("****************************************************\n");
        printf("*****      CHUONG TRINH QUAN LY SINHVIEN       *****\n");
        printf("*****         1. Nhap du lieu                  *****\n");
        printf("*****         2. In danh sach sinhvien         *****\n");
        printf("*****         3. Sap xep SinhVien theo dTB     *****\n");
        printf("*****         4. Xep loai SinhVien             *****\n");
        printf("*****         5. Xuat danh sach sinhvien       *****\n");
        printf("*****         0. Thoat                         *****\n");
        printf("****************************************************\n");
        printf("*****         Nhap lua chon cua ban            *****\n");
        scanf("%d",&key);
        switch(key)
        {
            case 1:
                printf(" Moi ban nhap DS SinhVien: ");
                nhapN(a, n);
                printf("\nBan da nhap thanh cong ");
                daNhap = true ;
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;

            case 2:
                if(daNhap)
                {
                    printf("\nBan da chon xuat DS Sinhvien");
                    xuatN(a, n);                          // xuat_NDS_SV
		}
                else
                {
                    printf("Chua nhap gi af: ");
                }
                printf("\nBam phim bat ky de tiep tuc! ");
                getch();
                break;

	     case 3:
                if(daNhap)
                {
                    printf("\nBan da sap xep Sinhvien");
                    sapXep(a, n);                         
                	xuatN(a, n); 
		}
                else
                {
                    printf("Chua nhap gi af: ");
                }
                printf("\nBam phim bat ky de tiep tuc! ");
                getch();
                break;

	   case 4:
                if(daNhap)
                {
                    printf("\nBan da chon xep loai Sinhvien");
                    xepLoaiN(a, n);                          
                	
		}
                else
                {
                    printf("Chua nhap gi af: ");
                }
                printf("\nBam phim bat ky de tiep tuc! ");
                getch();
                break;
                
	   case 5:
                if(daNhap)
                {
                    printf("\nBan da Xuat danh sach Sinhvien");
                    xuatFile(a, n, fileName);                         
		}
                else
                {
                    printf("Chua nhap gi af: ");
                }
                printf("\nXuat DSSV thanh cong vao file %s!", fileName);
		printf("\nBam phim bat ky de tiep tuc! ");
                getch();
                break;
			
	     case 0:
		printf("\nbam da chon thoat chuong trinh !");
		getch();
		return 0;
				
             default:
                printf("\nKhong co chuc nang nay!");
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
        }
    }
     
    return 0;
}

void nhap(SV &sv)
{
    printf("\nNhap ten sv: ");
    fflush(stdin);
    gets(sv.name);

    printf("Nhap gioi tinh: ");
    gets(sv.gt);

    printf("Nhap tuoi: ");
    scanf("%d", &sv.age);

    printf("Nhap diem 3 mon: ");
    scanf("%f%f%f", &sv.math, &sv.physics, &sv.chemistry);     // math, physics, chemistry
    tinhDTB(sv);
}
// 
// 
void nhapN(SV a[], int n)
{
	printf("\n****************************************************\n");
	for(int i= 0; i < n; i++)
	{
		printf("\n 	Nhap SV thu: %d", i+1);
		nhap(a[i]);
	}
	printf("\n****************************************************\n");
}

void tinhDTB(SV &sv)
{
    sv.dtb = (sv.math + sv.physics + sv.chemistry)/3;
}

void xuat(SV sv)
{
    printf("\nTen SV: %s\n", sv.name);
    printf("Gioi tinh SV: %s\n", sv.gt);
    printf("Tuoi SV: %d\n", sv.age);
    printf("Diem 3 mon cua SV: Toan %.2f Ly %.2f Hoa %.2f\n", sv.math, sv.physics, sv. chemistry);
    printf("Diem tb 3 mon: %.2f\n", sv.dtb);
    printf("------------------------------------------------------\n");
}

void xuatN(SV a[], int n)
{
    printf("\n****************************************************\n");
    for(int i= 0; i < n; i++)
    {
        printf("\n	Thong tin SV thu %d:", i+1);
        xuat(a[i]);
    }  
    printf("\n****************************************************\n");
}

void sapXep(SV a[], int n)								// tang dan 
{
 	SV tmp ;
 	for(int i = 0 ; i < n - 1; i++)
 	{
 		for(int j = i + 1; j < n; j++)
 		{
 			if(a[i].dtb < a[j].dtb )
 			{
 				tmp  = a[j];
				a[j] = a[i];
				a[i] = tmp ;	
			}	
		}
	}
}

void xepLoai(SV sv)
{
	if(sv.dtb >= 8)
	{
		printf("Loai Gioi\n");
	}
	else if( (sv.dtb >= 5) && (sv.dtb < 8) )
	{
		printf("Loai Kha\n");
	}
	else
	printf("Loai Yeu\n");
} 
 
void xepLoaiN(SV a[], int n)
{
	printf("\n****************************************************\n");
	for(int i = 0; i < n ;i ++)
	{
		printf("\n Xep loai cua SV thu %d:", i  + 1);
		xepLoai(a[i]);
	}
	printf("\n****************************************************\n");
}

void xuatFile(SV a[], int n,char fileName[])
{
	FILE *fp;
	fp = fopen(fileName,"w");
	fprintf(fp, "%20s%5s%5s%10s%10s%10s%10s\n", "Ho Ten","GioiTinh", "Tuoi", "math", "physics", "chemistry", "DTB");
	for(int i = 0; i < n; i++)
	{
		fprintf(fp,"%20s%5s%5s%10s%10s%10s%10s\n", a[i].name, a[i].gt, a[i].age, a[i].math, a[i].physics, a[i].chemistry, a[i].dtb);
	}
	fclose(fp);
}
