#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <module.hpp>

class Network : public module {

public:
	Network( void );
	Network( std::string, int );
	Network( const Network & );
	~Network( void );

	Network			&operator=( const Network & );

private:


};

#endif												// end of NETWORK_HPP
