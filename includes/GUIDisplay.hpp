/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GUIDisplay.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 18:44:57 by dmaznyts          #+#    #+#             */
/*   Updated: 2018/06/30 18:44:59 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUIDISPLAY_HPP
#define GUIDISPLAY_HPP

#include <Name.hpp>
#include <OS.hpp>
#include <Time.hpp>
#include <CPU.hpp>
#include <RAM.hpp>
#include <NetworkInfo.hpp>
#include <main.hpp>
#include <gtk/gtk.h>

class GUIDisplay {

public:
	GUIDisplay( void );
	GUIDisplay( const GUIDisplay & );
	~GUIDisplay( void );

	GUIDisplay			&operator=( const GUIDisplay & );

	void				WDialog (GtkButton *button, gpointer data);

private:
	void				allocAll( void );
	void				deleteAll( void );
	void				showAll( void );
	GtkWidget*			GenerateWidget(std::string title, int counter);
	void				init( void );


	GtkWidget			*_window0;
	GtkWidget			*_window1;
	GtkWidget			*_window2;
	GtkWidget			*_window3;
	GtkWidget			*_window4;
	GtkWidget			*_window5;
	GtkWidget			*_window6;
	GtkWidget			*_window7;
	GtkWidget			*_window8;

};

#endif												// end of GUIDISPLAY_HPP
