/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwasny <kkwasny@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:57:01 by kkwasny           #+#    #+#             */
/*   Updated: 2023/12/09 01:58:21 by kkwasny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

void	Contact::addFirstName(void)
{
    std::string	first_name;

    while (std::getline(std::cin, first_name) && first_name != "EXIT")
    {
        if (first_name == "")
            std::cout << "Contact can’t have empty fields!" << std::endl;
        else
        {
            this->_firstName = first_name;
            break;
        }
    }
}

void	Contact::addLastName(void)
{
    std::string	last_name;

    while (std::getline(std::cin, last_name) && last_name != "EXIT")
    {
        if (last_name == "")
            std::cout << "Contact can’t have empty fields!" << std::endl;
        else
        {
            this->_lastName = last_name;
            break;
        }
    }
}

void	Contact::addNickname(void)
{
    std::string	nickname;

    while (std::getline(std::cin, nickname) && nickname != "EXIT")
    {
        if (nickname == "")
            std::cout << "Contact can’t have empty fields!" << std::endl;
        else
        {
            this->_nick = nickname;
            break;
        }
    }
}

bool validPhoneNumber(std::string input)
{
    try
    {
        if (std::atoi(input.c_str()) <= 0)
            return (false);
    }
    catch (std::invalid_argument)
    {
        return (false);
    }
    return (true);
}

void	Contact::addPhoneNumber(void)
{
    std::string	phone_num;

    while (std::getline(std::cin, phone_num) && phone_num != "EXIT")
    {
        if (phone_num == "")
            std::cout << "Contact can’t have empty fields!" << std::endl;
        else if (!validPhoneNumber(phone_num))
            std::cout << "Invalid phone number." << std::endl;
        else
        {
            this->_phoneNumber = phone_num;
            break;
        }
    }
}

void	Contact::addDarkestSecret(void)
{
    std::string	secret;

    while (std::getline(std::cin, secret) && secret != "EXIT")
    {
        if (secret == "")
            std::cout << "Contact can’t have empty fields!" << std::endl;
        else
        {
            this->_darkestSecret = secret;
            break;
        }
    }
}

std::string	Contact::getFirstName(void)const
{
    return (this->_firstName);
}

std::string	Contact::getLastName(void)const
{
    return (this->_lastName);
}

std::string	Contact::getNickname(void)const
{
    return (this->_nick);
}

std::string Contact::getPhoneNumber(void)const
{
    return (this->_phoneNumber);
}

std::string	Contact::getDarkestSecret(void)const
{
    return (this->_darkestSecret);
}

void Contact::printAllContacts(int index)
{
    std::cout << std::setw(10) << index << "\033[0;33m|\033[0m";

    if(getFirstName().length() > 10)
        std::cout << std::setw(9) << getFirstName().substr(0, 9) << ".\033[0;33m|\033[0m";
    else
        std::cout << std::setw(10) << getFirstName() << "\033[0;33m|\033[0m";

    if(getLastName().length() > 10)
        std::cout << std::setw(9) << getLastName().substr(0, 9) << ".\033[0;33m|\033[0m";
    else
        std::cout << std::setw(10) << getLastName() << "\033[0;33m|\033[0m";

    if(getNickname().length() > 10)
        std::cout << std::setw(9) << getNickname().substr(0, 9) << ".\033[0;33m|\033[0m";
    else
        std::cout << std::setw(10) << getNickname() << "\033[0;33m|\033[0m";
}

void Contact::printContact()
{
    std::cout << "\nFirst name:             \033[0;32m" << getFirstName() << "\033[0m\n" << std::endl;
    std::cout << "Last name:              \033[0;32m" << getLastName() << "\033[0m\n" << std::endl;
    std::cout << "Nickname:               \033[0;32m" << getNickname() << "\033[0m\n" << std::endl;
    std::cout << "Phone number:           \033[0;32m" << getPhoneNumber() << "\033[0m\n" << std::endl;
    std::cout << "Darkest secret:         \033[0;32m" << getDarkestSecret() << "\033[0m\n" << std::endl;
}