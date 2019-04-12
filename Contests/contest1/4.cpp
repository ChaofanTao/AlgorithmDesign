#include <cstdio>
#include <iostream>
using namespace std;
 
const int Time_Max = 24 * 60 * 60; 
const int MAXN = 100 + 10;
int From[MAXN], To[MAXN]; int N;
int Qiang_Time, Qiang_Interval, Qiang_Wait;
 
int Time_Conversion()
{
	int hour, min, sec;
	scanf("%d:%d:%d", &hour, &min, &sec);
	return hour * 60 * 60 + min * 60 + sec;
}
 
void output(int seconds)
{
	int hour = seconds / (60 * 60);
	int min = (seconds - hour * (60 * 60)) / 60;
	int sec = seconds - hour * (60 * 60) - min * 60;
	if(seconds >= Time_Max)
		printf("-1\n");
	else
		printf("%02d:%02d:%02d\n", hour, min, sec);
	exit(0);
}
 
void read()
{
	cin >> N;
	int h1, m1, s1, h2, m2, s2;
	for(int i = 0;i < N; ++i)
	{
		From[i] = Time_Conversion();
		To[i] = Time_Conversion();
	}
	Qiang_Time = Time_Conversion();
	Qiang_Interval = Time_Conversion();
	Qiang_Wait = Time_Conversion();
	return;
}
 
void find()
{
	for(int i = 0;i < N; ++i)
	{	
		while(Qiang_Time <= To[i])
		{
			if(Qiang_Time < From[i])
				output(Qiang_Time);
			if(Qiang_Time + Qiang_Wait >= To[i])
				output(To[i]);
			Qiang_Time += Qiang_Interval;
		}
	}
	output(Qiang_Time);
	return;
}
 
int main()
{
	read(); find();
	return 0;
}

