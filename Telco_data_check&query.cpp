#include<bits/stdc++.h>

#define loop(i, a, b) for(int i=a; i<=b; i++)

using namespace std;

map<string, pair<int, int>> info;

int checkPhone = 1;
int totalCall = 0;

int Check(string str)
{
	if(str.length() != 10) return 0;
	loop(i, 0, 9)
	{
		if(str[i] >= '0' && str[i] <= '9') continue;
		else return 0;
	}
	return 1;
}

int ConvertTime(string time)
{
	int hours, minutes, seconds;
	hours = 10 * time[0] + time[1] - 48 * 11;
	minutes = 10 * time[3] + time[4] - 48 * 11;
	seconds = 10 * time[6] + time[7] - 48 * 11;
	return 3600 * hours + 60 * minutes + seconds;
}

void Input()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	string cmd;
	string from_number, to_number, date, from_time, end_time;
	while(1)
	{
		cin >> cmd;
		if(cmd == "#") break;
		cin >> from_number >> to_number >> date >> from_time >> end_time;
		if(!Check(from_number) || !Check(to_number))
			checkPhone = 0;
		else
		{
			totalCall++;
			if(info.find(from_number) == info.end())
			{
				info.insert({from_number, {1, ConvertTime(end_time) - ConvertTime(from_time)}});
			}else{
				info[from_number].first++;
				info[from_number].second += (ConvertTime(end_time) - ConvertTime(from_time));
			}
		}
	}
	while(1)
	{
		cin >> cmd;
		if(cmd == "#") break;
		if(cmd == "?check_phone_number") cout << checkPhone << endl;
		else if(cmd == "?number_calls_from")
		{
			cin >> from_number;
			if(info.find(from_number) != info.end())
			{
				cout << info[from_number].first << endl;
			}else cout << 0 << endl;
		}
		else if(cmd == "?number_total_calls") cout << totalCall << endl;
		else if(cmd == "?count_time_calls_from")
		{
			cin >> from_number;
			if(info.find(from_number) != info.end())
			{
				cout << info[from_number].second << endl;
			}else cout << 0 << endl;
		}
	}
	return;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	Input();
	//cout << checkPhone;
	//cout << ConvertTime("23:59:59");
	return 0;
}
