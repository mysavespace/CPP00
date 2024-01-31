/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwasny <kkwasny@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:11:38 by kkwasny           #+#    #+#             */
/*   Updated: 2023/12/08 22:52:23 by kkwasny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void start_info()
{
    std::cout << "\n=============================================" << std::endl;
    std::cout << "     Enter   One   Of   Three   Commands  " << std::endl;
    std::cout << "\033[0;31m     ADD           SEARCH           EXIT\033[0m" << std::endl;
    std::cout << "=============================================\n" << std::endl;
}

int main()
{
    PhoneBook   phonebook;
    std::string command;
    start_info();
    while (std::getline(std::cin, command) && command != "EXIT")
    {
        if (command == "ADD")
            phonebook.addNewContact();
        else if (command == "SEARCH")
            phonebook.displayContacts();
        start_info();
    }
    return (0);
}