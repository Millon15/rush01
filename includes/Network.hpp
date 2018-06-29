#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <ACursesModule.hpp>

class Network : public ACursesModule {

public:
	Network( void );
	Network( std::string, int );
	Network( const Network & );
	~Network( void );

	Network			&operator=( const Network & );

private:


};

#endif												// end of NETWORK_HPP
