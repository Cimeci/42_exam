/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:08:34 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/23 17:01:37 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ASpell.hpp"
# include "ATarget.hpp"

ASpell::ASpell(): name("default"), effects("default"){}
ASpell::ASpell(const ASpell &cp){*this = cp;}
ASpell &ASpell::operator=(const ASpell &op){
	if (this != &op)
	{
		name = op.name;
		effects = op.effects;
	}
	return *this;
}
ASpell::~ASpell(){}

ASpell::ASpell(std::string const &name, std::string const &effects): name(name), effects(effects){}

std::string ASpell::getName() const{return name;}
std::string ASpell::getEffects() const{return effects;}

void ASpell::launch(const ATarget &src) const{
	src.getHitBySpell(*this);
}
