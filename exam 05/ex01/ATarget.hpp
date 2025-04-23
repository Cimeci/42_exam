/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:13:41 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/23 16:51:21 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>

class ASpell;

class ATarget{
	protected:
		std::string type;

	public:
		ATarget();
		ATarget(const ATarget &cp);
		ATarget &operator=(const ATarget &op);
		virtual ~ATarget();
	
		ATarget(const std::string &type);
	
		const std::string &getType() const;
	
		virtual ATarget *clone() const = 0;
	
		void getHitBySpell(const ASpell &src) const;
};