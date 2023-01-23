/*
File: lcs.h
Author: David Hinojosa Gonzalez
Date: 21/01/2023

Implementacion del algoritmo de Longest Common Subsequence (LCS)
Es un algoritmo de programacion dinamica que encuentra la subsecuencia comun mas 
larga entre dos strings
Se crea una matriz de m+1 x n+1, donde m y n son el tamaño de los strings
En esta matriz, cada celda representa la longitud de la subsecuencia comun mas 
larga entre los primeros i caracteres de s1 y los primeros j caracteres de s2

Time complexity: O(M*N)
Space complexity: O(M*N)
*/

string LCS(string s1, string s2)
{

    int m = s1.length();
    int n = s2.length();
    int L[m + 1][n + 1];
    int max_length = 0;
    int end_index = 0;

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                L[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                L[i][j] = L[i - 1][j - 1] + 1;
                if (L[i][j] > max_length)
                {
                    max_length = L[i][j];
                    end_index = i - 1;
                }
            }
            else
            {
                L[i][j] = 0;
            }
        }
    }
    int start = end_index - max_length + 1;

    return s1.substr(start, max_length);
}