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

	gtk_container_add(GTK_CONTAINER(widget), gtk_label_new("test"));
	gtk_widget_set_uposition(widget, 300 * counter, 0);

	return (widget);
}
/* ************************************************************************** */
void					GUIDisplay::init( void )
{
  	GtkWidget *window;

	gtk_init(NULL, NULL);
	this->allocAll();
  	g_signal_connect(G_OBJECT(_window1), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	showAll();
	gtk_main();
}
/* ************************************************************************** */
void	GUIDisplay::allocAll( void )
{
	_window1 = GenerateWidget("1. User info", 0);
	_window2 = GenerateWidget("2. OS info", 1);
	_window3 = GenerateWidget("3. Time", 2);
	_window4 = GenerateWidget("4. CPU info", 3);
	_window5 = GenerateWidget("5. RAM info", 4);
	_window6 = GenerateWidget("6. Network throughput", 5);
	_window7 = GenerateWidget("7. Network interfaces", 6);
	_window8 = GenerateWidget("8. Matroskin", 7);
}
/* ************************************************************************** */
void	GUIDisplay::deleteAll( void )
{
	gtk_widget_destroy(_window1);
	gtk_widget_destroy(_window2);
	gtk_widget_destroy(_window3);
	gtk_widget_destroy(_window4);
	gtk_widget_destroy(_window5);
	gtk_widget_destroy(_window6);
	gtk_widget_destroy(_window7);
	gtk_widget_destroy(_window8);
}
/* ************************************************************************** */
void	GUIDisplay::showAll( void )
{
	gtk_widget_show_all(_window1);
	gtk_widget_show_all(_window2);
	gtk_widget_show_all(_window3);
	gtk_widget_show_all(_window4);
	gtk_widget_show_all(_window5);
	gtk_widget_show_all(_window6);
	gtk_widget_show_all(_window7);
	gtk_widget_show_all(_window8);
}