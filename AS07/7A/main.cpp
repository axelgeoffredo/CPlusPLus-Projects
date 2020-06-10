#include <iostream>

using namespace std;
class Time
{
protected:
	int hour;
	int min;
	int sec;
public:
	Time(int h, int m, int s)
		{ hour = h; min = m; sec = s; }

	int getHour()
		{ return hour; }

	int getMin()
		{ return min; }

	int getSec()
		{ return sec; }
};

class MilTime : public Time
{
private:
	int milHours;
    int milSeconds;
public:
//Exception 1
class BadHour{
private:
    int hour;
public:
    BadHour(int h){
    hour = h;
    }
    int getHour()
    {
        return hour;
    }
};
//Exception 2
class BadSeconds{
private:
    int seconds;
public:
    BadSeconds(int s){
    seconds = s;
    }
    int getSeconds()
    {
        return seconds;
    }
};
	MilTime(int, int);

    void convert();

	void setTime(int, int);

    int getHour()
		{ return milHours; }

    int getStandHr()
		{ return hour; }
    int getSec()
		{ return milSeconds; }

    void getTime(){
    cout << "The hour in military format is "
	    << getHour() << endl;
   cout << "The hour in standard format is "
	    << getStandHr() << endl;
   cout << "The minutes are "
	    << getMin() << endl;
   cout << "The seconds are "
	    << getSec() << endl;
	}
};

MilTime::MilTime(int h = 0, int s = 0) : Time(0, 0, s)
{
	if (h < 0 || h > 2359)
	{
		milHours = h;
		milSeconds = 0;
		throw BadHour(h);
	}
	else if (s < 0 || s > 59)
	{
        milSeconds = s;
		throw BadSeconds(s);
	}
	else
	{
		milHours = h;
   	    milSeconds = s;
	}
	convert();
}

void MilTime::convert()
{
	double temp;

	if (milHours > 1200)
		hour = milHours - 1200;
	else
		hour = milHours;

	hour /= 100;
	temp = (milHours - 1200) / 100.0;
	min = static_cast<int>(((temp - static_cast<int>(temp)) * 100));


}

void MilTime::setTime(int h, int s)
{
    if (h < 0 || h > 2359)
	{
		milHours = h;
		milSeconds = s;
		throw BadHour(h);
	}
	else if (s < 0 || s > 59)
	{
        milSeconds = s;
		throw BadSeconds(s);
	}
	else{
	milHours = h;
	milSeconds = s;
	convert();
	}
}

int main()
{
    MilTime t1;
    try{
	t1.setTime(2358, 58);
	t1.getTime();
    }
	catch(MilTime::BadHour h1){
        cout<<"Error: "<<h1.getHour()<<"is an invalid value for the MilTime's Hours.\n";
	}
	catch(MilTime::BadSeconds h1){
        cout<<"Error: "<<h1.getSeconds()<<"is an invalid value for the MilTime's Seconds.\n";
	}

	MilTime t2;
	try{
	t2.setTime(2359, 59);
	t2.getTime();
	}
	catch(MilTime::BadHour h2){
        cout<<"Error: "<<h2.getHour()<<" is an invalid value for the MilTime's Hours.\n";
	}
	catch(MilTime::BadSeconds h2){
        cout<<"Error: "<<h2.getSeconds()<<" is an invalid value for the MilTime's Seconds.\n";
	}
	MilTime t3;
	try{
	t3.setTime(2359, 60);
	t3.getTime();
	}
	catch(MilTime::BadHour h3){
        cout<<"Error: "<<h3.getHour()<<" is an invalid value for the MilTime's Hours.\n";
	}
	catch(MilTime::BadSeconds h3){
        cout<<"Error: "<<h3.getSeconds()<<" is an invalid value for the MilTime's Seconds.\n";
	}
	MilTime t4;
	try{
	t4.setTime(2360, 59);
	t4.getTime();
	}
	catch(MilTime::BadHour h4){
        cout<<"Error: "<<h4.getHour()<<" is an invalid value for the MilTime's Hours.\n";
	}
	catch(MilTime::BadSeconds h4){
        cout<<"Error: "<<h4.getSeconds()<<" is an invalid value for the MilTime's Seconds.\n";
	}
    return 0;
}
