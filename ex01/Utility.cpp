//#include "PhoneBook.hpp"
#include <iostream>
#include <cstring>


int     is_digit(std::string str)
{
    unsigned int i;

    i = 0;

    while (i < str.length())
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        ++ i;
    }
    return (1);
}

int     ft_atoi(std::string str)
{
    int     i;
    int     total;

    i = 0;
    total = 0;
    while (str[i])
    {
        total *= 10;
        total += str[i] - '0';
        ++ i; 
    }
    return (total);
}

char    ft_toupper(char c)
{
    if (c >= 'a' && c <= 'z')
        c -= 'a' - 'A';
    return (c);
}

/*
 * @brief ft_strcmp is a case-insensitive function that compares
 * two strings.  
 * 
 * @param void 
 *  
 * @return void
 */

int ft_strcmp(std::string str1, std::string str2)
{
    int i;

    i = 0;
    while (str1[i] && (ft_toupper(str1[i]) == ft_toupper(str2[i])))
        ++ i;
    return (str1[i] - str2[i]);
}
