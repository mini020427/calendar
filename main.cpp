#include <iostream>
#include <iomanip> //setw() 함수를 사용할 수 있게 해줌 //setw() : 출력 칸을 지정한 수 만큼 정렬 시켜줌.
#include <conio.h>
#include <ctime>
#include <fstream>
#include <ostream>
#include <string>
#include "calendar.h"

#pragma warning(disable : 4996) //C4996 에러 제거
using namespace std;

#define SIZE 30


//CRUD 기능 추가할 것임.


int main()
{
	ttime t;

	int year;
	char option;
	year = 1900 + t.local_time->tm_year; //tm_year은 1900년 이후 몇년이 지났는지 나오기때문에 +1900을 해줘야함.
	string line;

	system("cls");




	do // do - while : 적어도 한번 실행되는 루프
	{
	menu:

		system("cls");
		
		

		cout << " --------------------------------------------" << endl;
		cout << "	       Digital Calendar" << endl;
		cout << " --------------------------------------------" << endl << endl;

		cout << " [선택]" << endl;
		cout << " - A [일정 추가]" << endl;
		cout << " - L [일정 보기]" << endl << endl;

		cout << " - N [다음 년도]" << endl;
		cout << " - P [이전 년도]" << endl << endl;
		cout << " - E [나가기]" << endl << endl ;

		//Worldtime();
		t.PrindCurrentTime();
		t.PrintCalendar(year);

		cout << endl << endl;
		cout << "[선택]" << endl;
		cout << " - N [다음 년도]" << endl;
		cout << " - P [이전 년도]" << endl;
		cout << " - E [나가기]" << endl;
		option = getche(); //getche : 화면표시
		switch (option)
		{
		case 'n':
			year++;
			break;
		case 'p':
			year--;
			break;
		case 'a':
		{


		add:

			system("cls");

			int yearr;
			int mon;
			int day;
			int time;
			int min;
			char title[SIZE];
			char place[SIZE];
			char plan[SIZE];


			ofstream fout("planner.txt", ios::app); //app : 모든 출력을 파일의 끝에 추가.
			string s; 
			if (fout.is_open())
			{

				cout << "============== Planner ==============" << endl<< endl;
				
				cout << " 일정 제목 : ";
				cin.getline(title, SIZE);
				cout << " 날짜 입력 (년) : ";
				cin >> yearr ;
				cout << " 날짜 입력 (월) : ";
				cin >> mon;
				cout << " 날짜 입력 (일) : ";
				cin >> day;
				cin.ignore(1);
				cout << " 시간 입력 (시) : ";
				cin >> time;
				cout << " 시간 입력 (분) : ";
				cin >> min;
				cin.ignore(LLONG_MAX, '\n');
				cout << " 장소 : ";
				cin.getline(place, SIZE);
				cout << " 상세 일정 :	";
				cin.getline(plan, SIZE);
				
				fout << " 제목 : " << title << endl;
				fout << " 날짜 : " << yearr << "년" << mon << "월" << day << "일" << endl;
				fout << " 시간 : " << time << "시" << min << "분" << endl;
				fout << " 장소 : " << place << endl;
				fout << " 상세 일정 : " << plan << endl<<endl;

				cout << "일정을 추가했습니다. " << endl<<endl; 

				cout << " - E : 메뉴로 돌아가기"<<endl <<endl;

				cout << " - R : 더 작성하기 " << endl;
				
				
			}

			fout.close();
				char cho;
				cho = getche();
				if (cho == 'e' || cho == 'E' )
				{
					goto menu;
				}
				if (cho == 'r' || cho =='R')
				{
					goto add;
				}
				else
				{
					goto menu;
				}
		}
	
	
		case 'l':
		{

		list:

			system("cls");
			cout << "============== Plan List ==============" << endl;

			ifstream file("planner.txt");
			if (file.is_open())
			{
				while (getline(file, line))
				{
					cout <<endl << line << endl;
				
				}
				cout << " - E : 메뉴로 돌아가기" << endl << endl;
				char cho;
				file.close();
				cho = getche();
				if (cho == 'e' || cho == 'E')
				{
					goto menu;
				}
				if (cho == 'r' || cho == 'R')
				{
					goto list;
				}
				else
				{
					goto menu;
				}
			}
			

		}


			}
	


	} while (option != 'e' && option != 'E');

	return 0;


}

