#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP

class IMonitorModule {

public:
	virtual ~IMonitorModule( void ) { return ; };

	virtual void			refresh( void ) const = 0;
	virtual void			putInfo( void ) const = 0;

protected:
	
	virtual void				init( void ) = 0;

};

#endif												// end of IMONITORMODULE_HPP
