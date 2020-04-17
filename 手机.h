/*
    Author:赖朴然
    Last Edit:2020.3.31
    E-mail:1696095803@qq.com
    Vesion:1.1 Debug
    Github:Lpuran
    Information:A simple phone, build on C++ Console app.
*/

#pragma once

#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <thread>
#include <conio.h>
#include <dsound.h>
#include <mmsystem.h>
#include <Windows.h>

#pragma comment (lib,"WINMM.lib")

using namespace std;

constexpr auto SPACE = 0x20;
constexpr auto ESC = 0x1b;

int input, size;
int loc_DelReg, loc_Pwd;
bool flag, DelReg = true, ScreenMode = true;
char ch[50], in;
string password, str2;
stringstream ss;
ofstream  Configout, Readme;
ifstream Configin;

void music() {
    PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS);
}

int GetSize(int n) {
    int temp;
    if (ScreenMode) {
        temp = 50 - n;
        if (temp % 2 == 0)
            temp = temp / 2 + n;
        else
            temp = (temp + 1) / 2 + n;
        return temp;
    }
    else {
        temp = 120 - n;
        if (temp % 2 == 0)
            temp = temp / 2 + n;
        else
            temp = (temp + 1) / 2 + n;
        return temp;
    }
}

void Wait(int key, int time) {
    for (int i = 0; i < time;) {
        input = _getch();
        if (input == key)
            i++;
    }
}

bool Output() {
    Readme.open("Readme.txt", ios::ate | ios::out);
    if (!Readme)
        return false;
    Readme << "A simple phone" << endl << endl;
    Readme << "Author:赖朴然\nE-mail:1696095803@qq.com\nVersion:1.0\nGithub:Lpuran" << endl << endl;
    Readme << "Press space for a short time to start the system." << endl;
    return true;
}

bool Check(char c) {
    if (c == 't')
        return true;
    else
        return false;
}

void GetConfig() {
    Configin.open("config.txt");
    if (Configin.fail()) {
        Configin.close();
        Configout.open("config.txt");
        Configout << "ShowDeleteRegedit = true" << endl;
        Configout.close();
        Configin.open("config.txt");
    }
    while (!Configin.eof()) {
        Configin.getline(ch, 50, ' ');
        cout << ch << endl;
        switch (ch[0]) {
        case 'S':
            Configin.getline(ch, 50, ' ');
            loc_DelReg = Configin.tellg();
            cout << loc_DelReg << endl;
            Configin.getline(ch, 50, ' ');
            DelReg = Check(ch[0]);
            cout << "DelReg=" << DelReg << endl;
            break;
        case 'P':
            Configin.getline(ch,50, ' ');
            loc_Pwd = Configin.tellg();
            cout << loc_Pwd << endl;
            Configin.getline(ch, 50);
            ss << ch;
            ss >> password;
            cout << "Password : " << password << " length : " << password.length() << endl;
            break;
        default:
            break;
        }
    }
    Configin.close();
    Configout.open("config.txt", ios::out | ios::app);
}
