//calendar.h
#pragma warning(disable : 4996) //C4996 ���� ����


class ttime
{

public:

	time_t timer; //time_t : 1970�� 1��1�� 00:00:00���� �ʴ����� ī��Ʈ�� Ÿ��. //time() �Լ��� 1970�� 1��1�� ���� ���� ����� ���� ���� ��ȯ
	tm* local_time; // tm* local_time�� ��ȯ ����� ����Ų��


public:
	ttime()
	{
		timer = time(0);
		local_time = localtime(&timer);	//localtime : time_t ������ ����Ͻ��ʺ� ���·� ����

	}

public:
	void PrindCurrentTime();
	void PrintCalendar(int year);


};

