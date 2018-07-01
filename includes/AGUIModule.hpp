#ifndef AGUIMODULE_HPP
#define AGUIMODULE_HPP

#include <IMonitorModule.hpp>

class AGUIModule : public virtual IMonitorModule {

public:
	AGUIModule( void );
    AGUIModule( GtkWidget *window );
    AGUIModule( const AGUIModule &toCopy );
    virtual ~AGUIModule( void );

    AGUIModule				&operator=( const AGUIModule &toCopy );

	void		        	refresh( std::vector<GtkWidget*> , std::vector<std::string> ) const;
	virtual void			putInfo( void ) const;

    GtkWidget	       		*getWin( void ) const;

protected:
	GtkWidget               *_win;
    
    void		        	init( void );

};

#endif												// end of AGUIMODULE_HPP
