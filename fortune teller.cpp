#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<windows.h>
#include "ft.h"
#include "horoscopes.h"

using namespace std;

struct birthdate {
    int year;
    int month;
    int day;
};

struct loginfo {
    char name[50];
    char gender;
    int yr, mn, dy;
} a;

void delay(int seconds) {
    Sleep(seconds * 1000);
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main();

int main() {
    system("cls");
    int j;
    ofstream fp;
    struct birthdate bd;

    {//taking input of date of birth
        delay(1);
        gotoxy(45, 18); cout << "Enter your Date of Birth";
        gotoxy(45, 19); cout << "YEAR: ";
        cin >> bd.year;
        gotoxy(45, 20); cout << "MONTH: ";
        cin >> bd.month;
        gotoxy(45, 21); cout << "DAY: ";
        cin >> bd.day;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    {//checking errors
        //CHECKS FOR ERROR FIRST TIME
        if ((bd.month > 12) || (bd.month == 2 && bd.day >= 30) || (bd.month == 1, 3, 5, 7, 8, 10, 12 && bd.day > 31) ||
            (bd.month == 2, 4, 6, 9, 11 && bd.day > 30) || (2010 - bd.year > 100) || (bd.year > 2010)) {
            system("cls");
            gotoxy(30, 10); cout << "THE ENTRY YOU MADE WAS WRONG.....";
            gotoxy(10, 11); cout << "PLEASE ENTER CORRECT DATE OF BIRTH ACCORDING TO GREGORIAN CALENDAR";
            gotoxy(45, 18); cout << "Enter Your Date Of Birth";
            gotoxy(45, 19); cout << "YEAR: ";
            cin >> bd.year;
            gotoxy(45, 20); cout << "MONTH: ";
            cin >> bd.month;
            gotoxy(45, 21); cout << "DAY: ";
            cin >> bd.day;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        //CHECKS FOR ERROR SECOND TIME
        if ((bd.month > 12) || (bd.month == 2 && bd.day >= 30) || (bd.month == 1, 3, 5, 7, 8, 10, 12 && bd.day > 31) ||
            (bd.month == 2, 4, 6, 9, 11 && bd.day > 30) || (2010 - bd.year > 100) || (bd.year > 2010)) {
            gotoxy(45, 22); cout << "WRONG ENTRY";
            gotoxy(38, 23);
            delay(1);
            cout << "THE PROGRAM RESTARTS IN " << 3 << " SECONDS";
            delay(1);
            gotoxy(38, 23);
            cout << "THE PROGRAM RESTARTS IN " << 2 << " SECONDS";
            delay(1);
            gotoxy(38, 23);
            cout << "THE PROGRAM RESTARTS IN " << 1 << " SECONDS";
            delay(1);
            gotoxy(38, 23);
            cout << "THE PROGRAM RESTARTS IN " << 0 << " SECONDS";
            main();
        }
    }
    a.yr = bd.year;
    a.mn = bd.month;
    a.dy = bd.day;

    //taking names for records
    {
        system("cls");
        gotoxy(12, 5); cout << "REGISTRY DETAILS";
        gotoxy(12, 6); cout << "------------------------------------------------------------------";
        gotoxy(12, 9); cout << "------------------------------------------------------------------";
        gotoxy(17, 7); cout << "Enter Full Name:  ";
        cin.ignore(); // ignore newline left in buffer
        cin.getline(a.name, sizeof(a.name));
        gotoxy(17, 8); cout << "Enter Gender:  ";
        cin >> a.gender;

        gotoxy(50, 23); cout << "press any key to continue.....";
        cin.ignore(); // ignore newline left in buffer
        cin.get();
    }

    if ((fp = ofstream("records.txt", ios::binary | ios::app)) == NULL)
        exit(0);

    fp.write(reinterpret_cast<char*>(&a), sizeof(a));
    
    {//separating horoscopes and calling respective functions
        if ((bd.month == 3 && bd.day >= 21) || (bd.month == 4 && bd.day <= 19))
            aries(bd.day, bd.year, a.name, a.gender);
        if ((bd.month == 4 && bd.day >= 20) || (bd.month == 5 && bd.day <= 20))
            taurus(bd.day, bd.year, a.name, a.gender);
        if ((bd.month == 5 && bd.day >= 21) || (bd.month == 6 && bd.day <= 20))
            gemini(bd.day, bd.year, a.name, a.gender);
        if ((bd.month == 6 && bd.day >= 21) || (bd.month == 7 && bd.day <= 22))
            cancer(bd.day, bd.year, a.name, a.gender);
        if ((bd.month == 7 && bd.day >= 23) || (bd.month == 8 && bd.day <= 22))
            leo(bd.day, bd.year, a.name, a.gender);
        if ((bd.month == 8 && bd.day >= 23) || (bd.month == 9 && bd.day <= 22))
            virgo(bd.day, bd.year, a.name, a.gender);
        if ((bd.month == 9 && bd.day >= 23) || (bd.month == 10 && bd.day <= 22))
            libra(bd.day, bd.year, a.name, a.gender);
        if ((bd.month == 10 && bd.day >= 23) || (bd.month == 11 && bd.day <= 21))
            scorpio(bd.day, bd.year, a.name, a.gender);
        if ((bd.month == 11 && bd.day >= 22) || (bd.month == 12 && bd.day <= 21))
            saggitarius(bd.day, bd.year, a.name, a.gender);
        if ((bd.month == 12 && bd.day >= 22) || (bd.month == 1 && bd.day <= 19))
            capricorn(bd.day, bd.year, a.name, a.gender);
        if ((bd.month == 1 && bd.day >= 20) || (bd.month == 2 && bd.day <= 18))
            aquarius(bd.day, bd.year, a.name, a.gender);
        if ((bd.month == 2 && bd.day >= 19) || (bd.month == 3 && bd.day <= 20))
            pisces(bd.day, bd.year, a.name, a.gender);
    }

    return 0;
}