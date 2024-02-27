// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <iostream>
#include <set>
#include <cmath>

bool checkPrime(uint64_t value)
{
    // вставьте код функции
    set<uint64_t> numbers;
    for (uint64_t i = 2; i < (floor(sqrt(value)) + 1); i++)
    {
        if (value % i == 0)
        {
            numbers.insert(i);
            numbers.insert(value / i);
        }
    }
    if (numbers.size() == 0 && value != 1 && value != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

uint64_t nPrime(uint64_t n)
{
    // вставьте код функции
    uint64_t chislo = 2;
    uint64_t count = 0;
    while (count < n)
    {
        if (checkPrime(chislo) == true)
        {
            count++;
        }
        chislo++;
    }
    return (chislo - 1);
}

uint64_t nextPrime(uint64_t value)
{
    // вставьте код функции
    uint64_t next = value + 1;
    while (true)
    {
        if (checkPrime(next))
        {
            return next;
        }
        next++;
    }
}

uint64_t sumPrime(uint64_t hbound)
{
    // вставьте код функции
    uint64_t sum = 0;
    for (uint64_t i = 2; i < hbound; i++)
    {
        if (checkPrime(i))
        {
            sum += i;
        }
    }
    return sum;
}
