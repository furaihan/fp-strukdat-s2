//  Copyright © 2021-2022 Yahya Handarestanto, Pijar Pahlawan Qolbu, Aldi Putra Miftaqul Ullum, Valen Achmad Apiliawan, Michael Mardiansyah, Tifani Dea Shafira, Putra Budi Rahayu, Muhammad Zhafar Al Fathi, Nabella Ayu Giwanti
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
// http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// 

#pragma once
#include <iostream>
#include <sstream>
#include <fstream>


/* fungsi untuk memeriksa apakah dalam angka terdapat huruf 
    - akan true jika inputan tidak ada string (all int)
    - akan false jika inputan terdapat string (sekali dapat) */
bool IsStringAllDigit(const std::string &str)
{
    //inisialisasi instansi dari iterator string
    std::string::const_iterator it = str.begin();
    //jika iterator bukan digit, maka hentikan loop
    while (it != str.end() && isdigit(*it))
        ++it;
    //mengembalikan kondisi apakah iterator sudah mencapai akhir
    return !str.empty() && it == str.end();
}

bool IsNameValid(const std::string &name)
{
    /*
        Allowed characters:
        - A-Z
        - a-z
        - [space] = 32; tanda kutip (') = 39; tanda hubung (-) = 45; titik (.) = 46
    */
    for (int i = 0; i < name.size(); i++)
    {
        int asciiCode = int(name[i]);
        if (!(asciiCode == 32 || asciiCode == 39 || asciiCode == 45 || asciiCode == 46 || (asciiCode > 64 && asciiCode < 91) || (asciiCode > 96 && asciiCode < 123)))
            return false;
    }
    //cek ulang apakah semua karakter terdiri atas [spasi] ' - atau .
    std::string::const_iterator first = name.begin();
    std::string::const_iterator last = name.end();
    std::string::const_iterator it = name.begin();
    while (it != last)
    {
        int asciiCode = int(*it);
        if (asciiCode == 32 || asciiCode == 39 || asciiCode == 45 || asciiCode == 46)
            first++;
        it++;
    }
    return !name.empty() && first != last;
}

/* fungsi untuk mengubah string ke lowercase */
std::string MakeLowercase(const std::string &str)
{
    std::string result = str;
    for (int i = 0; i < str.size(); i++)
    {
        if (result[i] > 64 && result[i] < 91)
            result[i] = result[i] + 32;
    }
    return result;
}

/* fungsi untuk mengubah string ke titlecase */
std::string Capitalize(const std::string &str)
{
    std::string result = str;
    int len = str.size();
    for (int i = 0; i < len; i++)
    {
        // 32 = karakter spasi; 45 = karakter tanda hubung; 46 = karakter titik; 97 s/d 122 = lower case
        if ((i == 0 || result[i - 1] == 32 || result[i - 1] == 45 || result[i - 1] == 46) && result[i] > 96 && result[i] < 123)
        {
            result[i] = result[i] - 32;
        }
        else if (!(i == 0 || result[i - 1] == 32 || result[i - 1] == 45 || result[i - 1] == 46) && result[i] > 64 && result[i] < 91)
            result[i] = result[i] + 32;
    }
    return result;
}

/* fungsi untuk mengkonversi string ke integer */
int StrToInt(std::string str)
{
    int isInt;
    std::stringstream ToInt(str);
    ToInt >> isInt;
    return isInt;
}

/* fungsi untuk mengkonversi integer ke string */
std::string IntToString(int a)
{
    std::ostringstream temp;
    temp << a;
    return temp.str();
}
//swap memory reference value from a to b and vice versa
template<typename T>
void tukar(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}