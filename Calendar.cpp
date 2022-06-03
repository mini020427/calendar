#include <iostream>
#include <iomanip> //setw() �Լ��� ����� �� �ְ� ���� //setw() : ��� ĭ�� ������ �� ��ŭ ���� ������.
#include <conio.h>
#include <ctime>
#include <fstream>
#include <ostream>
#include "calendar.h"
using namespace std;




void ttime::PrindCurrentTime()
{
	int cyear = local_time->tm_year + 1900;
	int cmonth = local_time->tm_mon + 1;
	int cday = local_time->tm_mday;
	int chour = local_time->tm_hour;
	int cmin = local_time->tm_min;
	int csec = local_time->tm_sec;
	int cw = local_time->tm_wday;

	cout << " ----- KST ( �ѱ� ǥ�ؽ� )----- " << endl << endl;
	cout << " ���� ��¥(Y, M, D) : " << cyear << "�� " << cmonth << "�� " << cday << "�� " << endl << endl;
	cout << " ���� �ð�(H, M, S) : " << chour << "�� " << cmin << "�� " << csec << "�� " << endl << endl;
	cout << " ���� ����(��:0~��:6) : " << cw << endl << endl;

	cout << " GMT(�׸���ġ ǥ�ؽ�) : " << chour + 16 << "�� " << cmin << "�� " << csec << "�� " << endl << endl;


}


void ttime::PrintCalendar(int year)
{

	string mList[] = { "January", "February", "March" , "April" , "May" , "Jun" , "July" , "August" , "September" , "October" , "November" , "December" };
	int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };     // ����, ��� ���߱� ����.
	int m[12] = { 31, 28, 31, 30, 31 , 30, 31,31, 30, 31, 30, 31 };




	cout << "          << " << year << " Year >> " << endl;
	int days;
	int TS;  //���� ������ ��� �������� �˱� ���� �ʿ�

	int y = year - 1;
	TS = (y + y / 4 - y / 100 + y / 400 + t[0] + 1) % 7; //Tomohiko Sakamoto�� �˰��� 

	for (int i = 0; i < 12; i++)
	{
		if (i == 1)
			if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
				days = 29;
			else
				days = m[i];
		else
			days = m[i];

		cout << endl << " -----------[" << mList[i] << "]--------------" << endl << endl;

		cout << "  Sun  Mon  Tue  Wen  Thu  Fri  Sat  " << endl;
		cout << " ----------------------------------" << endl;



		int k;
		for (k = 0; k < TS; k++)
			cout << "     ";

		for (int j = 1; j <= days; j++)
		{
			k++;
			cout << setw(5) << j;
			if (k > 6)           //���� ���� �������� �ʰ� ���ִ�..
			{
				k = 0;           //�ƹ��͵� ���� �� �ٳѱ�.
				cout << endl;
			}
		}

		if (k)
			cout << endl << endl;
		TS = k;



	}

	return;

}
