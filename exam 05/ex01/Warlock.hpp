/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:04:01 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/23 17:49:55 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <map>

class ASpell;
class ATarget;

class Warlock{
	
	private:
		std::string name;
		std::string title;
		std::map<std::string, ASpell * > map;
	
		Warlock();
		Warlock(const Warlock &cp);
		Warlock &operator=(const Warlock &op);

	public:
		~Warlock();
		Warlock(const std::string &name, const std::string &title);

		const std::string &getName() const;
		const std::string &getTitle() const;

		void setTitle(const std::string &title);
		void introduce() const;

		void learnSpell(ASpell *spell);
		void forgetSpell(std::string spellName);
		void launchSpell(std::string spellName, ATarget &src);
};