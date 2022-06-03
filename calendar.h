//calendar.h
#pragma warning(disable : 4996) //C4996 에러 제거


class ttime
{

public:

	time_t timer; //time_t : 1970년 1월1일 00:00:00부터 초단위로 카운트한 타입. //time() 함수는 1970년 1월1일 자정 이후 경과된 초의 값을 반환
	tm* local_time; // tm* local_time은 변환 결과를 가리킨다


public:
	ttime()
	{
		timer = time(0);
		local_time = localtime(&timer);	//localtime : time_t 형식을 년월일시초분 형태로 분할

	}

public:
	void PrindCurrentTime();
	void PrintCalendar(int year);


};

