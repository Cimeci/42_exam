/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:05:50 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/23 17:12:20 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy"){}

Dummy::~Dummy(){}

ATarget *Dummy::clone() const{
	return new Dummy();
}