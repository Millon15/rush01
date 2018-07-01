/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GUIDisplay.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 18:51:41 by dmaznyts          #+#    #+#             */
/*   Updated: 2018/06/30 18:51:44 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GUIDisplay.hpp>

GUIDisplay::GUIDisplay( void )
{
	this->init();
}
/* ************************************************************************** */
GUIDisplay::GUIDisplay( const GUIDisplay &toCopy )
{
	*this = toCopy;
}
/* ************************************************************************** */
GUIDisplay::~GUIDisplay( void )
{
	this->deleteAll();
	system("reset; clear; echo '\t\t\t\t\t\tGOODBYE'");
}
/* ************************************************************************** */
GUIDisplay				&GUIDisplay::operator=( const GUIDisplay &toCopy )
{
	static_cast<void>(toCopy);
	return *this;
}
/* ************************************************************************** */
GtkWidget*				GUIDisplay::GenerateWidget(std::string title, int counter)
{
	GtkWidget	*widget = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  	gtk_window_set_title(GTK_WINDOW(widget), title.c_str());
  	gtk_container_set_border_width (GTK_CONTAINER(widget), 10);
	gtk_widget_set_usize(widget, 300, 300);

	// gtk_container_add(GTK_CONTAINER(widget), gtk_label_new("test"));
	gtk_widget_set_uposition(widget, 300 * counter, 0);

	return (widget);
}
/* ************************************************************************** */
void					GUIDisplay::init( void )
{
	gtk_init(NULL, NULL);
	this->allocAll();
  	// g_signal_connect(G_OBJECT(_window1), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	for (	std::vector<int>::size_type i = 0;
			i < _modules.size();
			i++ )
	{
		_modules[i]->putInfo();
	}
	showAll();
	gtk_main();
}
/* ************************************************************************** */
void	GUIDisplay::allocAll( void )
{
	int			i = 0;
	// _modules.push_back(new Name( GenerateWidget("1. User info", 0) );
	// _modules.push_back(new OS( GenerateWidget("2. OS info", 1) );
	// _modules.push_back(new Time( GenerateWidget("3. Time", 2) );
	_modules.push_back(new CPU( GenerateWidget("4. CPU info", i++) ));
	// _modules.push_back(new RAM( GenerateWidget("5. RAM info", 4) );
	// _modules.push_back(new NetworkThro( GenerateWidget("6. Network throughput", 5) );
	// _modules.push_back(new NetworkInfo( GenerateWidget("7. Network interfaces", 6) );
	// _modules.push_back(new Cat( GenerateWidget("8. Matroskin", 7) );
}
/* ************************************************************************** */
void	GUIDisplay::deleteAll( void )
{
	for (	std::vector<AGUIModule*>::size_type i = 0;
			i < _modules.size();
			i++ )
	{
		gtk_widget_destroy(_modules[i]->getWin());
	}
}
/* ************************************************************************** */
void	GUIDisplay::showAll( void )
{
	for (	std::vector<AGUIModule*>::size_type i = 0;
			i < _modules.size();
			i++ )
	{
		gtk_widget_show_all(_modules[i]->getWin());
	}
}
