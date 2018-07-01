#include <AGUIModule.hpp>

AGUIModule::AGUIModule( void )
{
	init();
}
AGUIModule::AGUIModule( GtkWidget *window ) : _win(window)
{
	init();
}
AGUIModule::AGUIModule( const AGUIModule &toCopy )
{
	*this = toCopy;
}
AGUIModule::~AGUIModule( void )
{
	return ;
}
AGUIModule				&AGUIModule::operator=( const AGUIModule &toCopy )
{
    static_cast<void>(toCopy);
	return *this;
}

void			AGUIModule::init( void )
{
	return ;
}

void			AGUIModule::putInfo( void ) const
{
	return ;
}

void			AGUIModule::refresh( std::vector<GtkWidget*> lables, std::vector<std::string> strs ) const
{
    for (	std::vector<GtkWidget*>::size_type i = 0;
		    i < lables.size();
	    	i++ )
	{
		gtk_label_set_text( GTK_LABEL(lables[i]), strs[i].c_str() );
	}
}


															/* GETTERS */
GtkWidget	    		*AGUIModule::getWin( void ) const
{
	return this->_win;
}
