#include <stdio.h>
#include <iostream>
#include <cctype>
#include "PermutationCipher.h"
#include <locale>
using namespace std;
void check(const wstring& Text, const int & key)
{
    wstring s=Text;
    try {
        PermutationCipher skey(key);
        wcout<<skey.CoderPermutationCipher(key, s)<<endl;
        wstring g=skey.CoderPermutationCipher(key, s);
        wcout<<skey.DecoderPermutationCipher(key,g)<<endl;
    } catch (const cipher_error & e) {
        cerr<<"Error: "<<e.what()<<endl;
    }
}
int main()
{
    int k;
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    check(L"pRograMpROCEsing",8);
    check(L"pRograMpROCEssing",10);
    check(L"TDFOXFCHVMN",3);
    return 0;
}