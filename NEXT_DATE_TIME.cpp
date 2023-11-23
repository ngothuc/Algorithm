#include <bits/stdc++.h>

#define loop(i, a, b) for (int i = a; i <= b; i++)
#define N 1000001

using namespace std;

string date;
string Time;
int y, m, d, h, mi, s;
int addTime;
int addD, addH, addMi, addS;
int dayOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void getDate() {
    sscanf(date.c_str(), "%d-%d-%d", &y, &m, &d);
    // cout << y << " " << m << " " << d << endl;
}

void getTime() {
    sscanf(Time.c_str(), "%d:%d:%d", &h, &mi, &s);
    // cout << h << " " << mi << " " << s << endl;
}

void getAddTime() {
    addD = addTime / 86400;
    addTime -= addD * 86400;
    addH = addTime / 3600;
    addTime -= addH * 3600;
    addMi = addTime / 60;
    addTime -= addMi * 60;
    addS = addTime;
}

void addMonth(int addM) {
    while (m + addM > 12) {
        addM = addM - (12 - m);
        y++;
        m = 0;
    }
    m += addM;
}

int getDay() {
    if (y % 4 == 0 && y % 100 != 0 && m == 2)
        return 29;
    return dayOfMonth[m - 1];
}

void addDay(int addD) {
    int day = getDay();
    while (d + addD > day) {
        addD = addD - (day - d);
        d = 0;
        addMonth(1);
        day = getDay();
    }
    d += addD;
}

void addHour(int addH) {
    while (h + addH > 23) {
        addH = addH - (24 - h);
        addDay(1);
        h = 0;
    }
    h += addH;
}

void addMinute(int addMi) {
    while (mi + addMi > 59) {
        addMi = addMi - (60 - mi);
        addHour(1);
        mi = 0;
    }
    mi += addMi;
}

void addSecond(int addS) {
    while (s + addS > 59) {
        addS = addS - (60 - s);
        addMinute(1);
        s = 0;
    }
    s += addS;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("ngothuc.txt", "r", stdin);

    while (1) {
        cin >> date;
        if (date == "*")
            break;
    }

    while (1) {
        cin >> date;
        if (date == "***")
            break;
        getDate();
        cin >> Time;
        getTime();
        cin >> addTime;
        getAddTime();
        addDay(addD);
        addHour(addH);
        addMinute(addMi);
        addSecond(addS);
        printf("%d-%.2d-%.2d %.2d:%.2d:%.2d\n", y, m, d, h, mi, s);
    }

    return 0;
}

