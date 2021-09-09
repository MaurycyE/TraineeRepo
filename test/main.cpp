#include <iostream>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;

string convertNumberIntoWord (char digit, char teen, char hund)
 {
    string word = "";
    map <int, string> numberToWord;
    numberToWord [1] = "jeden ";
    numberToWord [2] = "dwa ";
    numberToWord [3] = "trzy ";
    numberToWord [4] = "cztery ";
    numberToWord [5] = "piec ";
    numberToWord [6] = "szesc ";
    numberToWord [7] = "siedem ";
    numberToWord [8] = "osiem ";
    numberToWord [9] = "dziewiec ";
    numberToWord [10] = "dziesiec ";
    numberToWord [11] = "jedenascie ";
    numberToWord [12] = "dwanascie ";
    numberToWord [13] = "trzynascie ";
    numberToWord [14] = "czternascie ";
    numberToWord [15] = "pietnascie ";
    numberToWord [16] = "szesnascie ";
    numberToWord [17] = "siedemnascie ";
    numberToWord [18] = "osiemnascie ";
    numberToWord [19] = "dziewietnascie ";
    numberToWord [20] = "dwadziescia ";
    numberToWord [30] = "trzydziesci ";
    numberToWord [40] = "czterdziesci ";
    numberToWord [50] = "piecdziesiat ";
    numberToWord [60] = "szescdziesiat ";
    numberToWord [70] = "siedemdziesiat ";
    numberToWord [80] = "osiemdziesiat ";
    numberToWord [90] = "dziewiecdziesiat ";
    numberToWord [100] = "sto " ;
    numberToWord [200] = "dwiescie ";
    numberToWord [300] = "trzysta ";
    numberToWord [400] = "czterysta ";
    numberToWord [500] = "piecset ";
    numberToWord [600] = "szescset ";
    numberToWord [700] = "siedemset ";
    numberToWord [800] = "osiemset ";
    numberToWord [900] = "dziewiecset ";
    if (hund != '0') word = word + numberToWord[(hund - '0') * 100];
    if (teen == '1')
    {
        word = word + numberToWord[10 + (digit - '0')];
        return word;
    }
    if (teen != '0')  word = word + numberToWord[(teen - '0') * 10];
    if (digit != '0') word = word + numberToWord[digit - '0'];
    return word;
}
int main()
{
    int howmuch = 0;
    cin >> howmuch ;
    map <int, string> bignumb;
    bignumb[0] = "";
    bignumb[3] = "tys. ";
    bignumb[6] = "mln. ";
    bignumb[9] = "mld. ";
    bignumb[12] = "bln. ";
    while (howmuch--)
    {
        string number = "", word = "";
        cin >> number;
        if (number.size() % 3 == 1) number = "00" + number;
        if (number.size() % 3 == 2) number = "0" + number;
        reverse(number.begin(), number.end());
        for (int i = 0; i < number.size(); i += 3)
        {
            string temp = convertNumberIntoWord(number[i], number[i + 1], number[i+2] );
            if (temp != "") word = temp + bignumb[i] + word;
        }
        word.pop_back();
        cout << word << "\n";

    }

}
