#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP

class IMonitorModule {

public:
	IMonitorModule( void );
	IMonitorModule( const IMonitorModule & );
	virtual ~IMonitorModule( void ) = 0;

	virtual IMonitorModule			&operator=( const IMonitorModule & ) = 0;

	

private:


};

#endif												// end of IMONITORMODULE_HPP
