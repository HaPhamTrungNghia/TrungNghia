#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct
{
	char hoTen[35];
	char gioitinh[5];
	float diemPython;
	float diemC;
	float diemTB;
	char xeploai[15];
	char ketqua[15];
} SinhVien;

int nhapSoLuongSV(int n)
{
	do
	{
		printf("\nMoi ban nhap so luong sinh vien: ");
		scanf("%d", &n);
	}while (n <= 0);
	return n;
	
}

void nhapThongtinSV(SinhVien SV[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("\nNhap thong tin sinh vien thu %d", i + 1);
		printf("\nHo va ten: ");
		fflush(stdin);
		gets(SV[i].hoTen);
		
		printf("Gioi tinh: ");
		gets(SV[i].gioitinh);
		
		do
		{
			printf("\nDiem Python: ");
			scanf("%f", &SV[i].diemPython);
		}while (SV[i].diemPython < 0 || SV[i].diemPython > 10 );
		
		do
		{
			printf("Diem C: ");
			scanf("%f", &SV[i].diemC);
		}while (SV[i].diemC < 0 || SV[i].diemC > 10 );	
	}
}

void HienthiSinhVien(SinhVien SV[], int n)
{
	int i;
	printf("\n--------------------------------Thong tin sinh vien--------------------------------\n");
	printf("%-20s %-15s %-15s %-15s %-15s %-15s %-10s\n","Ho va ten", "Gioi tinh", "Diem python", "Diem C", "Diem TB", "Xep loai", "ket qua");
	for (i = 0; i < n; i++)
	{
		printf("%-20s %-15s %-15.2f %-15.2f %-15.2f %-15s %-10s\n", SV[i].hoTen, SV[i].gioitinh, SV[i].diemPython, SV[i].diemC, SV[i].diemTB, SV[i].xeploai, SV[i].ketqua);
	}	
}

void tinhDTB(SinhVien SV[], int n)
{
	int i;
	for(i = 0; i < n; i ++)
	{
		SV[i].diemTB = (SV[i].diemC*2 + SV[i].diemPython)/3; 
 	}
}

void xeploai(SinhVien SV[], int n)
{
	int i;
	for( i = 0; i < n; i ++)
	{
		if(SV[i].diemTB > 9)
		{
			strcpy(SV[i].xeploai, "Xuat xac");
		}
		else if(SV[i].diemTB > 8)
		{
			strcpy(SV[i].xeploai, "Gioi");
		}
		else if(SV[i].diemTB > 7)
		{
			strcpy(SV[i].xeploai, "Kha");
		}
		else if(SV[i].diemTB >= 5)
		{
			strcpy(SV[i].xeploai, "Trung binh");
		}
		else
		{
			strcpy(SV[i].xeploai, "Yeu");
		}
	} 
}
void ketqua(SinhVien SV[], int n)
{
	int i;
	for(i = 0; i <n; i++)
	{
		if(SV[i].diemTB < 5 || SV[i].diemC == 0 || SV[i].diemPython == 0)
		{
			strcpy(SV[i].ketqua, "Khong dat");
			
		}
		else
		{
			strcpy(SV[i].ketqua, "Dat");
		}
	}
}
		


int main()
{
	int n;
	SinhVien *SV;
	n = nhapSoLuongSV(n);
	// Cap phat bo nho cho n SV sua dung ham malloc(
	SV = (SinhVien*)malloc(n*sizeof(SinhVien));
	nhapThongtinSV(SV, n);
	tinhDTB(SV, n);
	xeploai(SV, n);
	ketqua(SV, n);
	HienthiSinhVien(SV, n);
	free(SV);
	return 0;
	
}
