/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwasny <kkwasny@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:57:01 by kkwasny           #+#    #+#             */
/*   Updated: 2023/12/07 18:04:38 by kkwasny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cctype>

class Contact
{
private:
    std::string	_firstName;
    std::string	_lastName;
    std::string	_nick;
    std::string	_phoneNumber;
    std::string	_darkestSecret;
public:
    void        printAllContacts(int index);
    void        printContact();
    std::string	getFirstName()const;
    std::string	getLastName()const;
    std::string	getNickname()const;
    std::string getPhoneNumber()const;
    std::string	getDarkestSecret()const;
    void		addFirstName();
    void		addLastName();
    void		addNickname();
    void		addPhoneNumber();
    void		addDarkestSecret();
};

#endif