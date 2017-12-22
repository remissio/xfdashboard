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

#ifndef __LIBXFDASHBOARD_LAYOUTABLE__
#define __LIBXFDASHBOARD_LAYOUTABLE__

#if !defined(__LIBXFDASHBOARD_H_INSIDE__) && !defined(LIBXFDASHBOARD_COMPILATION)
#error "Only <libxfdashboard/libxfdashboard.h> can be included directly."
#endif

#include <clutter/clutter.h>

#include <libxfdashboard/types.h>

G_BEGIN_DECLS

/* Object declaration */
#define XFDASHBOARD_TYPE_LAYOUTABLE					(xfdashboard_layoutable_get_type())
#define XFDASHBOARD_LAYOUTABLE(obj)					(G_TYPE_CHECK_INSTANCE_CAST((obj), XFDASHBOARD_TYPE_LAYOUTABLE, XfdashboardLayoutable))
#define XFDASHBOARD_IS_LAYOUTABLE(obj)				(G_TYPE_CHECK_INSTANCE_TYPE((obj), XFDASHBOARD_TYPE_LAYOUTABLE))
#define XFDASHBOARD_LAYOUTABLE_GET_IFACE(obj)		(G_TYPE_INSTANCE_GET_INTERFACE((obj), XFDASHBOARD_TYPE_LAYOUTABLE, XfdashboardLayoutableInterface))

typedef struct _XfdashboardLayoutable				XfdashboardLayoutable;
typedef struct _XfdashboardLayoutableInterface		XfdashboardLayoutableInterface;

/**
 * XfdashboardLayoutableInterface:
 * @fetch: Called to fetch sub-actors, layout, constraint, etc. object instances
 *   when an interface was create as defined in a layout xml file of theme
 * @fallback: Called when no interface was defined in any layout xml file of theme
 * @post_create: Called after the layoutable actor was created regardless if it
 *   was created as defined in a layout xml file of theme or via the @fallback
 *   function.
 */
struct _XfdashboardLayoutableInterface
{
	/*< private >*/
	/* Parent interface */
	GTypeInterface				parent_interface;

	/*< public >*/
	/* Virtual functions */
	void (*fetch)(XfdashboardLayoutable *inLayoutable, const gchar *inStyle);
	void (*fallback)(XfdashboardLayoutable *inLayoutable, const gchar *inStyle);
	void (*post_create)(XfdashboardLayoutable *inLayoutable, const gchar *inStyle);
};


/* Public API */
GType xfdashboard_layoutable_get_type(void) G_GNUC_CONST;

G_END_DECLS

#endif	/* __LIBXFDASHBOARD_LAYOUTABLE__ */
