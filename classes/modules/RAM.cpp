/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAM.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:09:02 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/30 12:09:03 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RAM.hpp>

RAM::RAM( void )
{
	return ;
}
RAM::RAM( std::string a, int b ) : ACursesModule(a, b)
{
	return ;
}
RAM::RAM( const RAM &toCopy )
{
	*this = toCopy;
}
RAM::~RAM( void )
{
	return ;
}

RAM			&RAM::operator=( const RAM &toCopy )
{
	ACursesModule::operator=(toCopy);
	static_cast<void>(toCopy);

	return *this;
}


void		RAM::putInfo( void ) const
{
	const std::string	memCap = saveExec("cat sysInfo | grep 'Memory: \\d* ' | sed -e 's/^ *//'");
	const std::string	upgradeable = saveExec("cat sysInfo | grep 'Upgradeable Memory:' | sed 's/^ *//'");
	const std::string	banks = saveExec("cat sysInfo | grep -A 40 'Upgradeable Memory:' | grep 'BANK' | wc -l | sed 's/^ *//'");
	const std::string	types = saveExec("cat sysInfo | grep -A 40 'Upgradeable Memory:' | awk '/Type:/  {printf \"%s \", $2;}'");
	const std::string	sizes = saveExec("cat sysInfo | grep -A 40 'Upgradeable Memory:' | awk '/Size:/  {printf \"%s \", $2$3;}'");
	const std::string	speed = saveExec("cat sysInfo | grep -A 40 'Upgradeable Memory:' | awk '/Speed:/  {printf \"%s \", $2$3;}'");

	mvwprintw(this->_w, _winStStr, 1, "%s", memCap.c_str());
	mvwprintw(this->_w, _winStStr + 1, 1, "%s", upgradeable.c_str());
	mvwprintw(this->_w, _winStStr + 2, 1, "Memory slots: %s", banks.c_str());

	mvwprintw(this->_w, _winStStr + 3, alignCenter(13), "Slots' types:");
	mvwprintw(this->_w, _winStStr + 4, alignCenter(types), "%s", types.c_str());
	mvwprintw(this->_w, _winStStr + 5, alignCenter(13), "Slots' sizes:");
	mvwprintw(this->_w, _winStStr + 6, alignCenter(sizes), "%s", sizes.c_str());
	mvwprintw(this->_w, _winStStr + 7, alignCenter(13), "Slots' speed:");
	mvwprintw(this->_w, _winStStr + 8, alignCenter(speed), "%s", speed.c_str());

	this->refresh();
}
