/*
    Author:赖朴然
    Last Edit:2020.3.18
    E-mail:1696095803@qq.com
    Github:Lpuran
*/
#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <conio.h>
#include <Windows.h>

#define SPACE 32

using namespace std;

int input;
bool flag;
fstream fout;

void click(int key,int time) {
    for (int i = 0; i < time;) {
        input = _getch();
        if (input == key)
            i++;
    }
}

bool output() {
    fout.open("Readme.txt");
    if (!fout)
        return false;
    fout << "Author:赖朴然\nE-mail:1696095803@qq.com\nVersion:1.0\nGithub:Lpuran" << endl;
    fout << "Press space for a short time to start the system." << endl;
}

int main() {
    system("mode con:lines=40 cols=50");
    click(SPACE,100);
    flag = output();
    if (!flag) {
        cout << "Output Error!" << endl;
        system("pause");
        return 0;
    }
    Sleep(3000);
    cout << "Please type \"yes\" to make sure that the Console run successfully next time." << endl;
    system("reg delete HKEY_CURRENT_USER\Console");
}
