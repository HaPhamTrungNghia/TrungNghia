#include<stdio.h>
	// Dinh nghia ham tim Max
	int timMax(int a, int b, int c)
	{
		int max = a;
		if(max < b)
		{
		max = b;
		}
		if(max < c)
		{
		max = c;
		}
		return max;
	}

	// Dinh nghia ham tim min
	int timMin(int a, int b, int c)
	{
		int min = a;
		if(min > b)
		{
			min = b;
		}
		if(min > c)
		{
			min = c;
		}
		return min;
	}

	//Dinh nghia ham tinh tong
	int tinh_tong(int a, int b, int c)
	{
		int tong;
		tong = a + b+ c;
		return tong;
	}

	int main()
	{
		int a, b, c;
		printf("Nhap 3 so a, b, c: ");
		scanf("%d %d %d", &a, &b, &c);
		int max = timMax(a, b, c); 
		int min = timMin(a, b, c);
		int tong = tinh_tong(a, b, c);
		printf("\nSo lon nhat trong 3 so vua nhap la: %d", max);
		printf("\nSo nho nhat trong 3 so vua nhap la: %d", min);
		printf("\nTong cua 3 so vua nhap la: %d", tong);
		return 0;
	}
	
