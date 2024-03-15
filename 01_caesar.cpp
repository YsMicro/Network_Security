//
// Created by Vojago on 2024/3/15.
//

#include "head.h"
#include <iostream>
#include <string>
using namespace std;

string caesar_encrypt(string s, int key);
string caesar_decipher(string s, int key);

int caesar_main()
{
    string s;
    int key;//密钥key
    cout << "输入密钥 K ：";
    cin>>key;
    cin.get();
    cout << "输入文本：";
    getline(cin,s);
    cout << "1-加密\n2-解密" << endl;
    int i;
    cin >> i;
    if (i == 1)
        cout << "密文为：" << caesar_encrypt(s, key) << endl;
    else
        cout << "明文为：" << caesar_decipher(s, key) << endl;
    return 0;
}


string caesar_encrypt(string s, int key){//凯撒加密
    key = (key + 26) % 26;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' ')continue;
        else if(islower(s[i]))
            s[i] = (s[i] - 'a' + key) % 26 + 'a';
        else if(isupper(s[i]))
            s[i] = (s[i] - 'A' + key) % 26 + 'A';
    }
    return s;
}


string caesar_decipher(string s, int key){//凯撒解密
    return caesar_encrypt(s,26 - key);
}
