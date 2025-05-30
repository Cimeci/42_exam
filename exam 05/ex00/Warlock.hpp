/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:04:01 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/23 15:30:46 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>

class Warlock{
	
	private:
		std::string name;
		std::string title;
	
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
};