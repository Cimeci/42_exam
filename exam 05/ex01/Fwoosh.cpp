/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:05:50 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/23 17:10:12 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed"){}

Fwoosh::~Fwoosh(){}

ASpell *Fwoosh::clone() const{
	return new Fwoosh();
}