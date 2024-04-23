#include <iostream>
#include <cctype>

char    *megaphone_word(char *);


/**
 * @brief Entry point of the program.
 *
 * This function takes command-line arguments and prints them with a megaphone effect.
 *
 * @param ac The number of command-line arguments.
 * @param av An array of strings containing the command-line arguments.
 * @return Returns 0 to indicate successful execution.
 */
int main(int ac, char *av[])
{
    int i;

    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    i = 1;
    while (i < ac)
    {
        std::cout << megaphone_word(av[i]);
        ++ i;    
    }
    std::cout << std::endl;
    return (0);
}


/**
 * @brief Converts all lowercase letters in a string to uppercase.
 * 
 * This function takes a null-terminated string as input and converts
 * all lowercase letters in the string to uppercase. It modifies the
 * input string in place and returns a pointer to the modified string.
 * 
 * @param str The null-terminated string to be converted.
 * @return A pointer to the modified string.
 */
char    *megaphone_word(char *str)
{
    int i;

    if (!str)
        return (0);
    i = 0;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = toupper(str[i]);
        }
        ++ i;
    }
    return (str);
}
