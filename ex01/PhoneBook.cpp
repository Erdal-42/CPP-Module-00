#include "PhoneBook.hpp"

/*
 * Object constructor for Class PhoneBook.
 */

PhoneBook::PhoneBook(void)
{

}

/*
 * Object destructor for Class PhoneBook.
 */

PhoneBook::~PhoneBook()
{

}

/*
 * @brief initilizes the values of the data members of the 
 * PhoneBook class object. The three data members are the;
 * static int noRecords: number of phonebook contacts entered 
 * min_index: index of the contact in the array with the 
 *            smallest key value
 * max_key: the key value of the contact entered most recently.
 *  
 * @return void
 */

void    PhoneBook::initializePhoneBook(void)
{
    noRecords = 0;
    min_index = 0;
    max_key = 0;
}

/*
 * Object constructor for Class Contact.
 */

PhoneBook::Contact::Contact(void)
{

}

/*
 * Object destructor for Class Contact.
 */

PhoneBook::Contact::~Contact(void)
{

}

/*
 * @brief initilizes the values of the data members of the 
 * Contact class object. 
 * 
 * The six data members are the;
 * @param ind the key value for the defined object of Contact class.
 * @param name the first name for the contact.
 * @param sname the surname for the contact.
 * @param nick the nickname for the contact.
 * @param phone the phone number for the contact.
 * @classified the secret of the contact.   
 *  
 * @return void
 */

void    PhoneBook::Contact::initializeContact(int ind, std::string name, std::string sname, std::string nick, std::string phone, std::string classified)
{
    key = ind;
    firstname = name;
    lastname = sname;
    nickname = nick;
    phonenumber = phone;
    secret = classified;  
}

/*
 * @brief This function returns the key of the relevant contact object.
 *
 * @param void
 * 
 * @return integer key of the contact object.
 */

int    PhoneBook::Contact::getKey(void) const
{
    return (key);
}

/*
 * @brief This function returns the firstname of the relevant contact object.
 *
 * @param void
 * 
 * @return string first name of the contact object.
 */

std::string    PhoneBook::Contact::getFirstname(void) const
{
    return (firstname);
}

/*
 * @brief This function returns the last name of the relevant contact object.
 *
 * @param void
 * 
 * @return string last name of the contact object.
 */

std::string    PhoneBook::Contact::getLastname(void) const
{
    return (lastname);
}

/*
 * @brief This function returns the nick name of the relevant contact object.
 *
 * @param void
 * 
 * @return string nick name of the contact object.
 */

std::string    PhoneBook::Contact::getNickname(void) const
{
    return (nickname);
}

/*
 * @brief This function returns the phone number of the relevant contact object.
 *
 * @param void
 * 
 * @return string phone number of the contact object.
 */

std::string    PhoneBook::Contact::getPhone(void) const
{
    return (phonenumber);
}

/*
 * @brief This function returns the dark secret of the relevant contact object.
 *
 * @param void
 * 
 * @return string secret of the contact object.
 */

std::string     PhoneBook::Contact::getSecret(void) const
{
    return secret;
}

/*
 * @brief this is a general function for re-prompting the 
 * user to enter the requested input until it is valid. 
 * 
 * @param str1 is the prompt message requesting user for input.
 * @param str2 is the string varible used for storing input.   
 *  
 * @return void
 */

void    PhoneBook::addField(std::string str1, std::string *str2)
{
    while ((*str2).length() < 1)
    {
        std::cout << str1;
        getline(std::cin, *str2);
    }
}

/*
 * @brief this is the function for inserting contact into
 * phonebook. Each data member of the contact is entered
 * by the user in order and read by the function.
 * 
 * As the first 8 records are inserted only noRecords is
 * updated. Once the PhoneBook capacity is full we only
 * update the min_key  
 * 
 * @param str1 is the prompt message requesting user for input.
 * @param str2 is the string varible used for storing input.   
 *  
 * @return void
 */

void    PhoneBook::add(void)
{
    Contact     con;
    std::string fname; 
    std::string sname; 
    std::string nick;
    std::string phone;
    std::string classified;

    addField("Enter First Name: ", &fname);
    addField("Enter Surname: ", &sname);
    addField("Enter Nickname: ", &nick);
    addField("Enter Phone Number: ", &phone);
    addField("Enter Secret: ", &classified);
    con.initializeContact(++ max_key, fname, sname, nick, phone, classified);
    if (noRecords < MAX_RECORDS)
    {
        contacts[noRecords] = con;
        ++ noRecords;
    } 
    else
    {
        contacts[min_index] = con;
        min_index = (min_index + 1) % MAX_RECORDS;
    }
}

/*
 * @brief prints the header for the PhoneBook Table. The
 * display is invoked when the user wants to search. 
 * 
 * @param void  
 *  
 * @return void
 */

void    PhoneBook::printHeader(void) const
{
    std::cout << "\n\t\tPHONEBOOK\n\n";
    std::cout.setf(std::ios::right);
    std::cout.width(11);
    std::cout << "INDEX|";
    std::cout.setf(std::ios::right);
    std::cout.width(11);
    std::cout << "FIRSTNAME|";
    std::cout.setf(std::ios::right);
    std::cout.width(11);
    std::cout << "LASTNAME|";
    std::cout.setf(std::ios::right);
    std::cout.width(11);
    std::cout << "NICKNAME\n";
}

/*
 * @brief this sub function is used to print individual fields 
 * in the PhoneBook table. When the field breaches 10 characters 
 * it truncates with a '.'. Therefore maximum 9 characters 
 * followed by a dot are * displayed. The library function substr
 * truncates the characters after the max_chars-1'th character.
 * Field is right alligned.  
 * 
 * @param str is the string (if it has more characters than max_chars
 * it will be truncated.
 * @param max_chars is maximum numbers of characters allowed, 
 * otherwise truncation is executed.
 * @param ending is the character('|') used to separate neighbouring
 * columns.  
 *  
 * @return void
 */

void    PhoneBook::printField(std::string str, unsigned int max_chars, std::string ending) const
{
    std::string  substr;
    
    if (str.length() > max_chars)
        -- max_chars;
    substr = str.substr(0, max_chars);
    std::cout.width(max_chars);
    std::cout << std::right << substr;
    if (max_chars != 10)
        std::cout << '.';
    std::cout << ending;
}

/*
 * @brief displayRecord displays four fields of a single contacts 
 * record as a row. Only the key is printed by this function whilst the 
 * string fields are printed using the sub-function printField().
 * 
 * @param i is the index of the record in the contacts array of the 
 * PhoneBook.    
 *  
 * @return void
 */

void    PhoneBook::displayRecord(int i) const
{
    int max_chars;

    max_chars = 10; 
    std::cout.width(max_chars);
    std::cout << std::right << contacts[i].getKey();
    std::cout << "|";

    printField(contacts[i].getFirstname(), max_chars, "|");
    printField(contacts[i].getLastname(), max_chars, "|");
    printField(contacts[i].getNickname(), max_chars, "\n");    
}

/*
 * @brief display is main function for displaying the PhoneBook. It
 * iterates in order to print every individual contact using the sub-
 * function dispaly_record.
 * 
 * @param void    
 *  
 * @return void
 */

void    PhoneBook::display() const
{
    int     i;

    i = 0;
    if (!noRecords)
        return ;
    printHeader();
    while (i < noRecords)
    {
        displayRecord(i);
        ++ i;
    }
}

/*
 * @brief displaySearchResult is the sub-function for searching,
 * and finding the contact. It then displays all the fields in 
 * consecutive rows. 
 * 
 * @param index value entered at the search prompt corresponding 
 * to the index of the contact that is being searched for.  
 *  
 * @return void
 */

void    PhoneBook::displaySearchResult(int index) const
{
    int i;

    i = 0;
    while (i < noRecords)
    {
        if (contacts[i].getKey() == index)
            break ;
        ++ i;
    }
    std::cout << "INDEX     : " << contacts[i].getKey() << std::endl;
    std::cout << "FIRST NAME: " << contacts[i].getFirstname() << std::endl;
    std::cout << "LAST NAME : " << contacts[i].getLastname() << std::endl;
    std::cout << "NICK NAME : " << contacts[i].getNickname() << std::endl;
    std::cout << "PHONE NO  : " << contacts[i].getPhone() << std::endl;
    std::cout << "SECRET    : " << contacts[i].getSecret() << std::endl;
}

/*
 * @brief search prompts the user to enter the index of the 
 * contact that they are looking for. The string input is 
 * converted to an integer. It is then tested to see if it
 * is an existing index. Once a valid index has been entered the
 * index is passed over to the sub-function displaySearchResult
 * to find the contact and display the contact. 
 * 
 * @param void 
 *  
 * @return void
 */

void    PhoneBook::search(void) const
{
    std::string input;
    int         index;

    if (!noRecords)
    {
        std::cout << "Phonebook is empty!\n";
        return ;
    }
    display();
    while (input.length() < 1)
    {
        std::cout << "\nPlease enter the index of record you are looking for: ";
        std::cin >> input;
        if (!is_digit(input))
            input = "";
        else
        {
            index = ft_atoi(input);
            if (index < contacts[min_index].getKey() || index > max_key)
            {
                std::cout << "Please enter index value between and including " <<  contacts[min_index].getKey() 
                            << " and " << max_key << std::endl; 
                input = ""; 
            }
            else
                break ;
        }
    }
    displaySearchResult(index);
}


/*
 * This is a PhoneBook program that maintains upto 8 contacts. Users
 * have the option of 
 * 
 * ADD; adding a new contact. If the user enters this 
 * command, they are prompted to input the information of the new 
 * contact one field at a time. Once all the fields have been completed,
 * add the contact to the phonebook.
 * The contact fields are: first name, last name, nickname, phone number
 * and darkest secret. A saved contact can’t have empty fields.
 * 
 * SEARCH: displaying a specific contact. Displays the saved contacts as
 * a list of 4 columns: index, first name, last, name and nickname. Each 
 * column is 10 characters wide. A pipe character (’|’) separates them. 
 * The text is right-aligned. If the text is longer than the column, it 
 * is truncated and the last displayable character is replaced by a dot 
 * (’.’). Then, prompt the user again for the index of the entry to display. 
 * If the index is out of range or wrong, a relevant message is diplayed. 
 * Otherwise, the contact information is displayed one field per line.
 * 
 * EXIT: The program quits and the contacts are lost forever!
 */   

int main()
{
    PhoneBook   pb;
    std::string str;

    pb.initializePhoneBook();
    std::cout << "\nWELCOME TO CPP00/EX01 PHONEBOOK\n";
    while (1)
    {
        std::cout << "\nPlease enter a command (ADD/SEARCH/EXIT): ";
        getline(std::cin, str);
        while (str.empty())
            getline(std::cin, str);
        if (!ft_strcmp("ADD", str))
        {
            pb.add();
        }
        else if (!ft_strcmp("SEARCH", str))
        {
            pb.search();
        }
        else if (!ft_strcmp("EXIT", str))
            return (0);
    }
    return (0);
}
