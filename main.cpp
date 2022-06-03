#include <iostream>
#include <iomanip> //setw() �Լ��� ����� �� �ְ� ���� //setw() : ��� ĭ�� ������ �� ��ŭ ���� ������.
#include <conio.h>
#include <ctime>
#include <fstream>
#include <ostream>
#include <string>
#include "calendar.h"

#pragma warning(disable : 4996) //C4996 ���� ����
using namespace std;

#define SIZE 30


//CRUD ��� �߰��� ����.


int main()
{
	ttime t;

	int year;
	char option;
	year = 1900 + t.local_time->tm_year; //tm_year�� 1900�� ���� ����� �������� �����⶧���� +1900�� �������.
	string line;

	system("cls");




	do // do - while : ��� �ѹ� ����Ǵ� ����
	{
	menu:

		system("cls");
		
		

		cout << " --------------------------------------------" << endl;
		cout << "	       Digital Calendar" << endl;
		cout << " --------------------------------------------" << endl << endl;

		cout << " [����]" << endl;
		cout << " - A [���� �߰�]" << endl;
		cout << " - L [���� ����]" << endl << endl;

		cout << " - N [���� �⵵]" << endl;
		cout << " - P [���� �⵵]" << endl << endl;
		cout << " - E [������]" << endl << endl ;

		//Worldtime();
		t.PrindCurrentTime();
		t.PrintCalendar(year);

		cout << endl << endl;
		cout << "[����]" << endl;
		cout << " - N [���� �⵵]" << endl;
		cout << " - P [���� �⵵]" << endl;
		cout << " - E [������]" << endl;
		option = getche(); //getche : ȭ��ǥ��
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


			ofstream fout("planner.txt", ios::app); //app : ��� ����� ������ ���� �߰�.
			string s; 
			if (fout.is_open())
			{

				cout << "============== Planner ==============" << endl<< endl;
				
				cout << " ���� ���� : ";
				cin.getline(title, SIZE);
				cout << " ��¥ �Է� (��) : ";
				cin >> yearr ;
				cout << " ��¥ �Է� (��) : ";
				cin >> mon;
				cout << " ��¥ �Է� (��) : ";
				cin >> day;
				cin.ignore(1);
				cout << " �ð� �Է� (��) : ";
				cin >> time;
				cout << " �ð� �Է� (��) : ";
				cin >> min;
				cin.ignore(LLONG_MAX, '\n');
				cout << " ��� : ";
				cin.getline(place, SIZE);
				cout << " �� ���� :	";
				cin.getline(plan, SIZE);
				
				fout << " ���� : " << title << endl;
				fout << " ��¥ : " << yearr << "��" << mon << "��" << day << "��" << endl;
				fout << " �ð� : " << time << "��" << min << "��" << endl;
				fout << " ��� : " << place << endl;
				fout << " �� ���� : " << plan << endl<<endl;

				cout << "������ �߰��߽��ϴ�. " << endl<<endl; 

				cout << " - E : �޴��� ���ư���"<<endl <<endl;

				cout << " - R : �� �ۼ��ϱ� " << endl;
				
				
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
				cout << " - E : �޴��� ���ư���" << endl << endl;
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

