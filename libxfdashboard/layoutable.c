/*
 * layoutable: An interface which can be inherited by actors to become
 *             themable, i.e. defining child actors, layout of actor and
 *             child actors etc.
 * 
 * Copyright 2012-2017 Stephan Haller <nomad@froevel.de>
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <libxfdashboard/layoutable.h>

#include <clutter/clutter.h>
#include <glib/gi18n-lib.h>

#include <libxfdashboard/compat.h>
#include <libxfdashboard/debug.h>


/* Define this interface in GObject system */
G_DEFINE_INTERFACE(XfdashboardLayoutable,
					xfdashboard_layoutable,
					G_TYPE_OBJECT)


/* IMPLEMENTATION: GObject */

/* Interface initialization
 * Set up default functions
 */
void xfdashboard_layoutable_default_init(XfdashboardLayoutableInterface *iface)
{
	static gboolean		initialized=FALSE;

	/* Define signals and actions */
	if(!initialized)
	{
		/* Set flag that base initialization was done for this interface */
		initialized=TRUE;
	}
}
