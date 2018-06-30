/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkInfo.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:08:11 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/30 14:29:09 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <NetworkInfo.hpp>

NetworkInfo::NetworkInfo( void )
{
	return ;
}
NetworkInfo::NetworkInfo( std::string a, int b ) : ACursesModule(a, b)
{
	return ;
}
NetworkInfo::NetworkInfo( const NetworkInfo &toCopy )
{
	*this = toCopy;
}
NetworkInfo::~NetworkInfo( void )
{
	return ;
}

NetworkInfo			&NetworkInfo::operator=( const NetworkInfo &toCopy )
{
	ACursesModule::operator=(toCopy);
	static_cast<void>(toCopy);

	return *this;
}


void				NetworkInfo::putInfo( void ) const
{
	int									y = _winStStr;
	const std::string					interfaces = saveExec(\
	"cat sysInfo | grep -A 29 'Network:' | grep '\\w:$' | awk '{gsub(\"Network:\", \"\", $1); printf \"%s %s \", $1, $2}'");
	const std::string					types = saveExec("cat sysInfo | grep -A 29 'Network:' | grep 'Type: '");
	const std::string					bsd = saveExec("cat sysInfo | grep -A 29 'Network:' | grep 'BSD' | awk '{print $4}'");
	const std::vector<std::string>		Ivec = explode(interfaces, ':');
	const std::vector<std::string>		Tvec = explode(types, '\n');
	const std::vector<std::string>		Bvec = explode(bsd, '\n');
	const std::vector<int>::size_type	smallestSize = std::min( Ivec.size(), std::min(Tvec.size(), Bvec.size()) );

	for (	std::vector<int>::size_type i = 0;
			i < smallestSize;
			i++ )
	{
		mvwprintw(this->_w, y++, 1, "%d. %s:", i + 1, Ivec[i].c_str());
		mvwprintw(this->_w, y++, 1, "%s", Bvec[i].c_str());
		mvwprintw(this->_w, y++, 1, "    %s", Tvec[i].c_str());
	}

	this->refresh();
}
