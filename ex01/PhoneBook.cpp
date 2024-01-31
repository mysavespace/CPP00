/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwasny <kkwasny@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:56:39 by kkwasny           #+#    #+#             */
/*   Updated: 2023/12/10 20:04:22 by kkwasny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void):_num_of_contacts(0), _index(0)
{
    return;
}

PhoneBook::~PhoneBook(void)
{
    return;
}

void PhoneBook::addNewContact(void)
{
    if ( _index > 7)
        _index = 0;
    std::cout << "\n---------------------------------------------" << std::endl;
    std::cout << "--------\033[0;34mYou are adding a new contact.\033[0m--------" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "--------------- \033[0;32mPlease enter: \033[0m---------------" << std::endl;
    std::cout << "\033[0;32m-first name:\033[0m                                -" << std::endl;
    array_of_contacts[_index].addFirstName();
    std::cout << "\033[0;32m-last name:\033[0m                                 -" << std::endl;
    array_of_contacts[_index].addLastName();
    std::cout << "\033[0;32m-nickname:\033[0m                                  -" << std::endl;
    array_of_contacts[_index].addNickname();
    std::cout << "\033[0;32m-phone number:\033[0m                              -" << std::endl;
    array_of_contacts[_index].addPhoneNumber();
    std::cout << "\033[0;32m-darkest secret:\033[0m                            -" << std::endl;
    array_of_contacts[_index].addDarkestSecret();
    std::cout << "---------------------------------------------" << std::endl;
    _index++;
    if (_num_of_contacts <= 7)
        _num_of_contacts++;
}

void search_info()
{
    std::cout << "\n---------------------------------------------" << std::endl;
    std::cout << "--------- \033[0;36mPlease enter the index of\033[0m ---------" << std::endl;
    std::cout << "--------\033[0;36m contact you want to display \033[0m--------" << std::endl;
    std::cout << "------------------\033[0;36m [1 - 8] \033[0m------------------" << std::endl;
}

int convertToInt(std::string input)
{
    int         index;

    try
    {
        index = std::stoi(input);
    }
    catch (std::invalid_argument)
    {
        return (-1);
    }
    return (index);
}

void PhoneBook::displayContacts(void)
{
    std::string	input;
    int         index;

    for (int i = 0; i < _num_of_contacts; i++)
    {
        array_of_contacts[i].printAllContacts(i + 1);
        std::cout << std::endl;
    }
    search_info();
    while (std::getline(std::cin, input) && input != "EXIT")
    {
        index = convertToInt(input);
        if (index == -1)
            std::cout << "Please put a number!" << std::endl;
        else if (index <= 0 || index >= 9)
            std::cout << "Invalid index. Try again!" << std::endl;
        else
            array_of_contacts[index - 1].printContact();
        search_info();
    }
}