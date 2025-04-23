/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:03:20 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/23 16:59:36 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>

class ATarget;

class ASpell{
	protected:
		std::string name;
		std::string effects;

	public:
		ASpell();
		ASpell(const ASpell &cp);
		ASpell &operator=(const ASpell &op);
		virtual ~ASpell();
	
		ASpell(std::string const &name, std::string const &effects);

		std::string getName() const;
		std::string getEffects() const;

		virtual ASpell *clone() const = 0;

		void launch(const ATarget &src) const;
};