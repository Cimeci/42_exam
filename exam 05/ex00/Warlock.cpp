/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:03:57 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/23 15:32:31 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title): name(name), title (title){
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(){
	std::cout << name << ": My job here is done!" << std::endl;
}


const std::string &Warlock::getName() const {return name;}

const std::string &Warlock::getTitle() const {return title;}

void Warlock::setTitle(const std::string &title){this->title = title;}

void Warlock::introduce() const{std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;}