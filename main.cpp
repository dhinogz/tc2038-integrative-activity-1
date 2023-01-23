// =========================================================
// File: main.cpp
// Author: David Hinojosa Gonzalez
// Date: 17/01/2023
// =========================================================

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

#include "lcs.h"
#include "kmp.h"
#include "manacher.h"



int main(int argc, char const *argv[])
{
    ifstream t1, t2, mc1, mc2, mc3;

    string t1s, t2s, mc1s, mc2s, mc3s;

    t1.open("transmission1.txt");
    t2.open("transmission2.txt");
    mc1.open("mcode1.txt");
    mc2.open("mcode2.txt");
    mc3.open("mcode3.txt");

    if (t1.fail() or t2.fail() or mc1.fail() or mc2.fail() or mc3.fail())
    {
        cout << "Error opening files" << "\n";
        return 1;
    }

    t1 >> t1s;
    t2 >> t2s;
    mc1 >> mc1s;
    mc2 >> mc2s;
    mc3 >> mc3s;

    t1.close();
    t2.close();
    mc1.close();
    mc2.close();
    mc3.close();

    // Parte 1
    // transmission1.txt
    cout << "transmission1.txt:\n";
    int pos = KMPSearch(mc1s, t1s);
    if (pos != -1)
    {
        cout << "mcode1.txt - true, start at position " << pos << "\n";
    }    
    else 
    {
        cout << "mcode1.txt - false\n";
    }

    pos = KMPSearch(mc2s, t1s);
    if (pos != -1) 
    {
        cout << "mcode2.txt - true, start at position " << pos << "\n";
    }
    else 
    {
        cout << "mcode2.txt - false\n";
    }

    pos = KMPSearch(mc3s, t1s);
    if (pos != -1) 
    {
        cout << "mcode3.txt - true, start at position " << pos << "\n";
    }
    else 
    {
        cout << "mcode3.txt - false\n";
    }

    // transmission2.txt
    cout << "\ntransmission2.txt:\n";
    pos = KMPSearch(mc1s, t2s);
    if (pos != -1) 
    {
        cout << "mcode1.txt - true, start at position " << pos << "\n";
    }
    else 
    {
        cout << "mcode1.txt - false\n";
    }

    pos = KMPSearch(mc2s, t2s);
    if (pos != -1) 
    {
        cout << "mcode2.txt - true, start at position " << pos << "\n";
    }
    else
    {
        cout << "mcode2.txt - false\n";
    }
    pos = KMPSearch(mc3s, t2s);
    if (pos != -1) 
    {
        cout << "mcode3.txt - true, start at position " << pos << "\n";
    }
    else 
    {
        cout << "mcode3.txt - false\n";
    }


    // Parte 2
    // transmission1.txt
    int start, end;
    string longestPalindrome;
    cout << "\ntransmission1.txt:\n";
    longestPalindrome = Manacher(t1s, start, end);
    cout << "mirrored code found, start at " << start << ", ended at " << end << "\n";

    // transmission2.txt
    cout << "\ntransmission2.txt:\n";
    longestPalindrome = Manacher(t2s, start, end);
    cout << "mirrored code found, start at " << start << ", ended at " << end << "\n\n";


    // Parte 3
    string longest_common_subst = LCS(t1s, t2s);
    cout << "the longest common substring between transmission1.txt and transmission2.txt is " << longest_common_subst.size() << " characters long\n";

    return 0;
}

