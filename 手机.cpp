/*
    Author:赖朴然
    Last Edit:2020.3.31
    E-mail:1696095803@qq.com
    Vesion:1.0 Debug
    Github:Lpuran
    Information:A simple phone, build on C++ Console app.
*/
#pragma once

#include "手机.h"

using namespace std;


int main() {
    system("mode con:lines=40 cols=50");
    flag = Output();
    if (!flag) {
        cout << "Output the readme text error!" << endl;
        system("pause");
        return 0;
    }
    Wait(SPACE, 50);
    thread music(music);
    music.detach();
    cout << setw(GetSize(11)) << "Starting..." << endl;
    GetConfig();
    Sleep(3000);
    if (password.empty()) {
        cout << "This is your first time start this phone." << endl;
        INSERT_PWD:
        cout << "Create a password:" << endl;
        cin >> password;
        if (password.length() > 15) {
            cout << "Over the max size (15)." << endl;
            system("pause");
            goto INSERT_PWD;
        }
        while (password != str2) {
            cout << "Please verify your password:" << endl;
            cin >> str2;
            if (password != str2) {
                cout << "Please insert the same password" << endl;
                cout << "Do you want to change the password?(Y/N)" << endl;
                in = _getch();
                if (in == 'y')
                    goto INSERT_PWD;
            }
        }
        Configout << "Password = " << password << endl;
    }
    else{
        for (input = 0; input < 10; input++) {
            cout << setw(GetSize(9)) << "Password:" << endl;
            cin >> str2;
            if (password == str2)
                break;
        }
        if (input==10){
            cout << "You have insert the wrong password for ten times!" << endl;
            cout << "Forget the password?(Y/N)" << endl;
            cout << "Y Ask questions you had insert to reset your password." << endl;
            cout << "N Del the configure to reset this software." << endl;
            in = _getch();
            if (in == 'y') {
                cout << "Question:" << endl;
            }
            cout << "We will delete the config to reset" << endl;
            Configout.close();
            system("del config.txt");
            return 0;
        }
    }
    if (DelReg) {
        cout << "Please type \"yes\" to change the Console's to the default size." << endl;
        system("reg delete HKEY_CURRENT_USER\\Console");
        cout << "May I show you next time?(Y/N)";
        in = _getch();
        if (in == 'n') {
            Configout.seekp(loc_DelReg, ios::beg);
            Configout << "ShowDeleteRegedit = false" << endl;
            Configout.close();
        }
    }
    cout << endl;
    system("pause");
    return 0;
}
