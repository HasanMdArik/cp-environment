const unsigned long long MAX_ARRAY = 1e7 + 1;
bool isNotPrime[MAX_ARRAY] = {true, true};
int primes[MAX_ARRAY];
int pc = 0;

void sieve(int n)
{
    if (n < 2)
        return;
    primes[pc++] = 2;
    for (unsigned long long d = 2 * 2; d <= n; d += 2)
    {
        isNotPrime[d] = true;
    }
    for (int i = 3; i <= n; i += 2)
    {
        if (!isNotPrime[i])
        {
            primes[pc++] = i;
            for (unsigned long long j = i * i; j <= n; j += i)
            {
                isNotPrime[j] = true;
            }
        }
    }
}