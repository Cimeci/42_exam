/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:16:52 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/23 17:01:39 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ATarget.hpp"
# include "ASpell.hpp"

ATarget::ATarget(): type("default"){}
ATarget::ATarget(const ATarget &cp){*this = cp;}
ATarget &ATarget::operator=(const ATarget &op){
	if (this != &op)
	{
		type = op.type;
	}
	return *this;
}
ATarget::~ATarget(){}

ATarget::ATarget(const std::string &type): type(type){}

const std::string &ATarget::getType() const{return type;}

void ATarget::getHitBySpell(const ASpell &src) const{
	std::cout << type << " has been " << src.getEffects() << "!" << std::endl;
}