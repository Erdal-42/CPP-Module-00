#include <iostream>
#include <cstring>
#include <iomanip>

#define MAX_RECORDS 8

/*
 * Class PhoneBook stores a list of upto 8 
 * contacts. The constacts are managed by a separate 
 * class Contact that is nested within the class 
 * PhoneBook. In order to manage the contacts, class 
 * PhoneBook maintains; 
 * noRecords: the number of existing contacts 
 *            in the PhoneBook, it is defined as 
 *            static, asit is a common valu to all
 *            contacts.
 * min_index: the index of an existing contact 
 *            with the smallest key in the PhoneBook
 * max_key  : the key value for the most recently 
 *            entered contact.  
 *
 * The nested class Contact maintains the contact 
 * information for every individual person entered.
 * 
 * All data types and library functions are according
 * to the version C++98 version.
 *   
 */

class PhoneBook
{
    private:
        class Contact
        {
            private:
                int         key;
                std::string firstname;
                std::string lastname;
                std::string nickname;
                std::string phonenumber;
                std::string secret;
            public:
                Contact(void);
                ~Contact();
                void            initializeContact(int, std::string, std::string, std::string, std::string, std::string);
                int             getKey(void) const;
                std::string     getFirstname(void) const;
                std::string     getLastname(void) const;
                std::string     getNickname(void) const;
                std::string     getPhone(void) const;
                std::string     getSecret(void) const;
        };
        void    addField(std::string, std::string *);    
    public:
        PhoneBook(void);
        ~PhoneBook();
        void        initializePhoneBook(void);
        static int  noRecords;
        int         min_index;
        int         max_key;
        Contact     contacts[MAX_RECORDS];
        void        add(void);
        void        display(void) const;
        void        displayRecord(int) const;
        void        search(void) const;
        void        displaySearchResult(int) const;
        void        printHeader(void) const;
        void        printField(std::string, unsigned int, std::string) const;
};

int     PhoneBook::noRecords; 
int     is_digit(std::string);
int     ft_atoi(std::string);
char    ft_toupper(char);
int     ft_strcmp(std::string, std::string);