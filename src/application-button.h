/*
 * application-button: A button representing an application
 *                     (either by menu item or desktop file)
 * 
 * Copyright 2012-2013 Stephan Haller <nomad@froevel.de>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#ifndef __XFOVERVIEW_APPLICATION_BUTTON__
#define __XFOVERVIEW_APPLICATION_BUTTON__

#include <garcon/garcon.h>
#include <gio/gdesktopappinfo.h>

#include "button.h"

G_BEGIN_DECLS

#define XFDASHBOARD_TYPE_APPLICATION_BUTTON				(xfdashboard_application_button_get_type())
#define XFDASHBOARD_APPLICATION_BUTTON(obj)				(G_TYPE_CHECK_INSTANCE_CAST((obj), XFDASHBOARD_TYPE_APPLICATION_BUTTON, XfdashboardApplicationButton))
#define XFDASHBOARD_IS_APPLICATION_BUTTON(obj)			(G_TYPE_CHECK_INSTANCE_TYPE((obj), XFDASHBOARD_TYPE_APPLICATION_BUTTON))
#define XFDASHBOARD_APPLICATION_BUTTON_CLASS(klass)		(G_TYPE_CHECK_CLASS_CAST((klass), XFDASHBOARD_TYPE_APPLICATION_BUTTON, XfdashboardApplicationButtonClass))
#define XFDASHBOARD_IS_APPLICATION_BUTTON_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE((klass), XFDASHBOARD_TYPE_APPLICATION_BUTTON))
#define XFDASHBOARD_APPLICATION_BUTTON_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS((obj), XFDASHBOARD_TYPE_APPLICATION_BUTTON, XfdashboardApplicationButtonClass))

typedef struct _XfdashboardApplicationButton			XfdashboardApplicationButton;
typedef struct _XfdashboardApplicationButtonClass		XfdashboardApplicationButtonClass;
typedef struct _XfdashboardApplicationButtonPrivate		XfdashboardApplicationButtonPrivate;

struct _XfdashboardApplicationButton
{
	/* Parent instance */
	XfdashboardButton						parent_instance;

	/* Private structure */
	XfdashboardApplicationButtonPrivate		*priv;
};

struct _XfdashboardApplicationButtonClass
{
	/*< private >*/
	/* Parent class */
	XfdashboardButtonClass					parent_class;

	/*< public >*/
	/* Virtual functions */
};

/* Public API */
GType xfdashboard_application_button_get_type(void) G_GNUC_CONST;

ClutterActor* xfdashboard_application_button_new(void);
ClutterActor* xfdashboard_application_button_new_from_desktop_file(const gchar *inDesktopFilename);
ClutterActor* xfdashboard_application_button_new_from_menu(GarconMenuElement *inMenuElement);

GarconMenuElement* xfdashboard_application_button_get_menu_element(XfdashboardApplicationButton *self);
void xfdashboard_application_button_set_menu_element(XfdashboardApplicationButton *self, GarconMenuElement *inMenuElement);

const gchar* xfdashboard_application_button_get_desktop_filename(XfdashboardApplicationButton *self);
void xfdashboard_application_button_set_desktop_filename(XfdashboardApplicationButton *self, const gchar *inDesktopFilename);

gboolean xfdashboard_application_button_get_show_description(XfdashboardApplicationButton *self);
void xfdashboard_application_button_set_show_description(XfdashboardApplicationButton *self, gboolean inShowDescription);

gboolean xfdashboard_application_button_execute(XfdashboardApplicationButton *self);

G_END_DECLS

#endif	/* __XFOVERVIEW_APPLICATION_BUTTON__ */