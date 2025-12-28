#include <bits/stdc++.h>
using namespace std;

const unsigned long long MAX_ARRAY = 1e7 + 1;
int spf[MAX_ARRAY];

void precomputeSPF(int n)
{
    if (n < 2)
        return;

    // Count SPF of even numbers(that's 2)
    spf[2] = 2;
    for (unsigned long long i = 2 * 2; i < n; i += 2)
    {
        spf[i] = 2;
    }

    for (unsigned long long i = 3; i <= n; i += 2)
    {
        if (spf[i] == 0)
        {
            spf[i] = i;

            for (unsigned long long j = i * i; j <= n; j += i)
            {
                if (spf[j] != 0)
                    spf[j] = min(spf[j], (int)i);
                else
                    spf[j] = i;
            }
        }
    }
}

bool isPrime(int n)
{
    return spf[n] == n;
}