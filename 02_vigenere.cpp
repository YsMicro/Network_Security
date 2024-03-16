//
// Created by Vojago on 2024/3/16.
//

#include "head.h"
#include <iostream>
#include <string>
using namespace std;

string encrypt(string plainText, string key);
string decrypt(string cipherText, string key);

int vigenere_main() {
    string plainText, key;
    cout << "1-加密\n2-解密\n:" << endl;
    int i;
    cin >> i;
    if (i == 1) {
        cout << "输入明文：" << endl;
        cin.get();
        getline(cin, plainText);
        cout << "输入密钥：" << endl;
//        cin.get();
        getline(cin, key);
        cout << "输出密文：" <<
        encrypt(plainText, key) << endl;
    }
    if (i == 2) {
        cout << "输入密文：" << endl;
        cin.get();
        getline(cin, plainText);
        cout << "输入密钥：" << endl;
        getline(cin, key);
        cout << "输出明文：" <<
        decrypt(plainText, key) << endl;
    }

    return 0;
}

string encrypt(string plainText, string key)
{
    string cipherText = "";
    int key_len = key.size(), plainText_len = plainText.size(), s = 0;
    for (int i = 0; i < plainText_len; i++)
    {
        //其它字符
        if (plainText[i] >= 'a' && plainText[i] <= 'z')
        {
            int j = (i - s) % key_len;
            cipherText += (plainText[i] - 'a' + key[j] - 'a') % 26 + 'a';

        }
        else if (plainText[i] >= 'A' && plainText[i] <= 'Z')
        {
            int j = (i - s) % key_len;
            cipherText += (plainText[i] - 'A' + key[j] - 'a') % 26 + 'A';
        }
        else
        {
            cipherText += plainText[i];
            s++;
        }
    }
    return cipherText;
}

//解密
string decrypt(string cipherText, string key)
{
    string plainText = "";
    int key_len = key.size(), cipherText_len = cipherText.size(), s = 0;
    for (int i = 0; i < cipherText_len; i++)
    {
        //其它字符
        if (cipherText[i] >= 'a' && cipherText[i] <= 'z')
        {
            int j = (i - s) % key_len;
            plainText += (cipherText[i] - 'a' + 26 - (key[j] - 'a')) % 26 + 'a';
        }
        else if (cipherText[i] >= 'A' && cipherText[i] <= 'Z')
        {
            int j = (i - s) % key_len;
            plainText += (cipherText[i] - 'A' + 26 - (key[j] - 'a')) % 26 + 'a';
        }
        else
        {
            plainText += cipherText[i];
            s++;
        }
    }
    return plainText;
}
