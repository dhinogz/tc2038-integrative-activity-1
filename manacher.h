/*
File: manacher.h
Author: David Hinojosa Gonzalez
Date: 21/01/2023

This function implements the Manacher algorithm, which is an efficient 
algorithm to find the longest palindrome substring in a given string.

Time complexity: O(N)
Space complexity: O(N)
*/

string Manacher(string s, int &start, int &end)
{
    // Initialize the string with a special character
    int n = s.length();
    string t = "#";
    for (int i = 0; i < n; ++i)
    {
        t += s[i];
        t += "#";
    }

    // Create a vector to store the length of the longest palindrome substring
    n = 2 * n + 1;
    vector<int> p(n);
    int center = 0, right_boundary = 0;
    for (int i = 0; i < n; ++i)
    {
        int mirror = 2 * center - i;
        if (i < right_boundary)
            p[i] = min(right_boundary - i, p[mirror]);
        int left = i + (1 + p[i]);
        int right = i - (1 + p[i]);
        while (left < n && right >= 0 && t[left] == t[right])
        {
            p[i]++;
            left++;
            right--;
        }
        if (i + p[i] > right_boundary)
        {
            center = i;
            right_boundary = i + p[i];
        }
    }

    int palindrome_center = 0, len = 0;
    for (int i = 0; i < n; ++i)
    {
        if (p[i] > len)
        {
            palindrome_center = i;
            len = p[i];
        }
    }

    //start position of the palindrome
    start = (palindrome_center - len) / 2;

    //end position of the palindrome
    end = start + len;

    return s.substr(start, len);
}
