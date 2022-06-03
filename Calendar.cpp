#include <iostream>
#include <iomanip> //setw() 함수를 사용할 수 있게 해줌 //setw() : 출력 칸을 지정한 수 만큼 정렬 시켜줌.
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

	cout << " ----- KST ( 한국 표준시 )----- " << endl << endl;
	cout << " 현재 날짜(Y, M, D) : " << cyear << "년 " << cmonth << "월 " << cday << "일 " << endl << endl;
	cout << " 현재 시간(H, M, S) : " << chour << "시 " << cmin << "분 " << csec << "초 " << endl << endl;
	cout << " 현재 요일(일:0~토:6) : " << cw << endl << endl;

	cout << " GMT(그리니치 표준시) : " << chour + 16 << "시 " << cmin << "분 " << csec << "초 " << endl << endl;


}


void ttime::PrintCalendar(int year)
{

	string mList[] = { "January", "February", "March" , "April" , "May" , "Jun" , "July" , "August" , "September" , "October" , "November" , "December" };
	int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };     // 윤년, 평년 맞추기 위함.
	int m[12] = { 31, 28, 31, 30, 31 , 30, 31,31, 30, 31, 30, 31 };




	cout << "          << " << year << " Year >> " << endl;
	int days;
	int TS;  //달의 시작이 어느 요일일지 알기 위해 필요

	int y = year - 1;
	TS = (y + y / 4 - y / 100 + y / 400 + t[0] + 1) % 7; //Tomohiko Sakamoto의 알고리즘 

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
			if (k > 6)           //요일 줄을 오버하지 않게 해주는..
			{
				k = 0;           //아무것도 없을 때 줄넘김.
				cout << endl;
			}
		}

		if (k)
			cout << endl << endl;
		TS = k;



	}

	return;

}
