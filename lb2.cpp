#include <cmath>
#include <iostream>
#include <iomanip> 
#include <conio.h>

using namespace std;

double func(double a, double b, int i);
double fuc2(double Yimax, double Yimin);
double modl(double number);
int modl(int number);

int main(void)
{
	double Yi = 0.0, amax = 0.0, amin = 0.0, da = 0.0, bmax = 0.0, bmin = 0.0, db = 0.0, Yimin = 0.0, Yimax = 0.0, G = 0.0;
	int n = 0.0;
	int temp1, temp2, temp3;
	char mmenu;
	setlocale(LC_ALL, "Russian");
	while(1)
	{
		system("cls");
		cout << "������� amax = ";
		cin >> amax;
		cout << "������� amin = ";
		cin >> amin;
		cout << "������� da = ";
		cin >> da;
		cout << "������� bmax = ";
		cin >> bmax;
		cout << "������� bmin = ";
		cin >> bmin;
		cout << "������� db = ";
		cin >> db;
		cout << "������� n = ";
		cin >> n;
		if (n <= 0)
		{
			cout << "����� n ������ ���� ������ ��� ����� 0!\n���������� ����� n �������� 1.\n";
			n = 1;
		}
		if (da == 0)
		{
			cout << "����� da ������ ���� ������ ��� ����� 0!\n���������� ����� n �������� 1.\n";
			da = 1;
		}
		if (db == 0)
		{
			cout << "����� db ������ ���� ������ ��� ����� 0!\n���������� ����� n �������� 1.\n";
			db = 1;
		}
		/*--------------------------------------------
		*/
		/*--------------------------------------------
		*/
		for(double cauntera = amin; cauntera <= amax; cauntera += da)
		{
			cout << "==============================\n";
			cout << "��� a = " << cauntera << endl;
			cout << "==============================\n";
			for(double caunterb = bmin; caunterb <= bmax; caunterb += db)
			{	
				cout << "��� b = " << caunterb << endl;
				for(int caunteri = 1; caunteri <= n; caunteri++)
				{
					Yi = func(cauntera, caunterb, caunteri);
					if(cauntera == amin && caunterb == amin && caunteri == 1)
					{
						Yimax = modl(Yi);
						Yimin = modl(Yi);
					}
					else
					{
						if( Yimax < modl(Yi) ) Yimax = modl(Yi);
						if( Yimin > modl(Yi) ) Yimin = modl(Yi);
					}
					cout.setf(ios::fixed);
					cout << setprecision(3) << Yi << "\t";
				}
				cout << endl;
			}
			cout << endl;
		}
		G = fuc2(Yimax, Yimin);
		cout << "��� Yimax = " << Yimax << " � Yimin = " << Yimin << " G = " << G << endl;
		system("pause");
		system("cls");
		cout << "�������� ���������� ��������. ��� ��������� ��������� ������� ������� 1.\n��� ������ ������� ������� 0, e ��� q, �� ���������� ��������� ����������.";
		mmenu = getch();
		if(mmenu == '0' || mmenu == 'e' || mmenu == 'q') break;
	}
return 0;
}

double modl(double number)
{
	if(number < 0) number = -1.0 * number;
	return number; 
}

int modl(int number)
{
	if(number < 0) number = -1.0 * number;
	return number; 
}

double fuc2(double Yimax, double Yimin)
{
	double g = 0.0;
	g = 0.5 * (Yimax + Yimin); 
	return g;
}

double func(double a, double b, int i)
{
	double tmp1 = 0.0, tmp2 = 0.0;
	tmp2 = pow(b, 2.0);
	tmp2 = tmp2 + i;
	tmp2 = sqrt(tmp2);
	tmp2 *= i;
	
	if(b > 0)
	{
		tmp1 = pow(-1.0, i);
		tmp1 = tmp1 * b;
		tmp1 *= i;
		tmp1 += a;
		tmp1 = pow(tmp1,2.0);
	}
	else
	{
		tmp1 = (b*(double)i);
		tmp1 += a;
		tmp1 = pow(tmp1,2.0);
	}
	tmp1 = tmp1 / tmp2;
	return tmp1;
}
