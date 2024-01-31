/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwasny <kkwasny@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:56:39 by kkwasny           #+#    #+#             */
/*   Updated: 2023/12/07 18:03:32 by kkwasny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

class PhoneBook
{
private:
    int     _num_of_contacts;
    int     _index;
public:
    PhoneBook();
    ~PhoneBook();
    Contact array_of_contacts[8];
    void    addNewContact();
    void    displayContacts();
};

#endif