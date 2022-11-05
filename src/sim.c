/**
 * @file    sim.c
 * @date    17.10.2021
 * @author  Thang Bui Huy <thang@mailfence.com>
 * @brief   SIM Telex main module
 * @details Implement 4 mandatory functions from #GtkIMContext
 */

#include "config.h"
#include <string.h>

#include "gtk/gtk.h"
#include "gdk/gdkkeysyms.h"

#include "gtk/gtkimmodule.h"
#include "gtk/gtkintl.h"

#include "context.h"


/* Bookkeeping information about a loadable input method. */
static const GtkIMContextInfo sim_telex_context_info =
{
    "sim-telex",            /* Unique identification string of the input method */
                            /* Human readable name */
    NC_("input method menu", "Phương thức nhập tiếng Việt"),
    GETTEXT_PACKAGE,        /* Translation domain */

    #ifdef GTK_LOCALEDIR    /* Name of locale directory for use */
    GTK_LOCALEDIR,
    #else
    "/usr/local/share/locale",
    #endif
    "en"                    /* A colon-separated list of locales where this input method
                             * should be the default */
};

static const GtkIMContextInfo *context_info_list[] =
{
    &sim_telex_context_info
};


/**
 * @brief
 * @param module
 */
void im_module_init(GTypeModule *module)
{
    register_type_sim_telex(module);
}


/**
 * @brief
 */
void im_module_exit(void)
{
}


/**
 * @brief
 * @param contexts
 * @param n_contexts
 */
void im_module_list(const GtkIMContextInfo ***contexts, int *n_contexts)
{
    *contexts = context_info_list;
    *n_contexts = G_N_ELEMENTS(context_info_list);
}


/**
 * @brief
 * @param context_id
 * @return
 */
GtkIMContext *im_module_create(const gchar *context_id)
{
    if (!strcmp(context_id, sim_telex_context_info.context_id))
    {
        return create_instance_sim_telex();
    }

    return NULL;
}
