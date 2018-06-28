#ifndef IMONITORDISPLAY_HPP
#define IMONITORDISPLAY_HPP

class IMonitorDisplay {

public:
	IMonitorDisplay( void );
	IMonitorDisplay( const IMonitorDisplay & );
	virtual ~IMonitorDisplay( void ) = 0;

	virtual IMonitorDisplay			&operator=( const IMonitorDisplay & ) = 0;

private:


};

#endif												// end of IMONITORDISPLAY_HPP
