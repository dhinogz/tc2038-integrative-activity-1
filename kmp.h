/*
File: kmp.h
Author: David Hinojosa Gonzalez
Date: 21/01/2023

This file contains the implementation of the KMP (Knuth-Morris-Pratt) algorithm for pattern matching in strings.
Time complexity: O(N + M)
Space complexity: O(M)
*/

// Function to compute the longest prefix suffix array
void computeLPSArray(string pat, int M, int* lps)
{
    int len = 0;
    lps[0] = 0;

    // the loop calculates lps[i] for 1:M-1
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else 
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}


// Function to find the first occurrence of the pattern in the text
int KMPSearch(string pattern, string txt)
{
    int M = pattern.length();
    int N = txt.length();
    int lps[M];

    // Calculate lps[] array
    computeLPSArray(pattern, M, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pattern[]
    while (i < N)
    {
        if (pattern[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            // Pattern found. Return starting position
            return i - j;
        }

        // mismatch after j matches
        else if (i < N && pattern[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    // if the pattern is not found in the text, return -1
    return -1;
}