//
// Created by Vojago on 2024/3/15.
//

#include "head.h"
#include <iostream>
#include <string>
using namespace std;

string caesar_encrypt(string string1, int key);
string caesar_decipher(string string1, int key);

int caesar_main()
{
    string string1;
    int key;//密钥key
    cout << "输入密钥 K ：";
    cin>>key;
    cin.get();
    cout << "输入文本：";
    getline(cin,string1);
    cout << "1-加密\n2-解密" << endl;
    int i;
    cin >> i;
    if (i == 1)
        cout << "密文为：" << caesar_encrypt(string1, key) << endl;
    if (i == 2)
        cout << "明文为：" << caesar_decipher(string1, key) << endl;
    return 0;
}


string caesar_encrypt(string string1, int key){//凯撒加密
    key = (key + 26) % 26;
    for(char & i : string1){
        if(i == ' ')continue;
        else if(islower(i))
            i = (i - 'a' + key) % 26 + 'a';
        else if(isupper(i))
            i = (i - 'A' + key) % 26 + 'A';
    }
    return string1;
}


string caesar_decipher(string string1, int key){//凯撒解密
    return caesar_encrypt(string1,26 - key);
}
