/**
 * @file    context.h
 * @date    02.10.2021
 * @author  Thang Bui Huy <thang@mailfence.com>
 * @brief   Context implementation for SIM Telex
 * @details This module defines some data structures and functions to initialize SIM Telex class
 * and instance according to requirement of \b GtkIMContext. It is also responsible for handling
 * of key events (filtering key pressed event) and other important stuff which an input method need
 * to take into account like management of preedit string, handling focus out event, submitting
 * of resulting text, and so on...
 */

#ifndef SIM_TELEX_CONTEXT_H
#define SIM_TELEX_CONTEXT_H

#include "constants.h"

#include <gtk/gtk.h>

G_BEGIN_DECLS


/**
 * Checks that \b obj is an instance of the type \b GTK_TYPE_IM_CONTEXT and issues a warning if
 * this is not the case. Returns instance casted to a pointer to #SIMTelexContext.
 * No warning will be issued if instance is NULL, and NULL will be returned.
 * This macro should only be used in type implementations.
 */
#define GTK_SIM_TELEX_CONTEXT(obj)  \
    (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_IM_CONTEXT, SIMTelexContext) )


/**
 * @brief Type ID of SIM Telex as a result of registering the input method with GTK type system.
 * It then will be used to create an instance of #SIMTelexContext.
 */
extern GType    sim_telex_type_id;


/**
 * SIM Telex context instance structure
 */
typedef struct
{
    GtkIMContext    object; /*!< Parent instance in which this struct derived from */
    gchar           text[MAX_WORD_LENGTH_IN_BYTES];     /*!< Final text to be submitted*/
    glong           length;             /*!< Number of characters #text has at current moment */
    gboolean        done;               /*!< Ready to submit resulting text or not */
    gboolean        preedit_started;    /*!< Current status of preediting: started or not */
} SIMTelexContext;


/**
 * SIM Telex context class structure
 */
typedef struct
{
    GtkIMContextClass parent_class; /*!< Parent class in which this struct derived from */
} SIMTelexContextClass;


/**
 * @brief
 * @param module
 */
void            register_type_sim_telex(GTypeModule *module);

/**
 * @brief
 * @return
 */
GtkIMContext    *create_instance_sim_telex(void);


G_END_DECLS


#endif // SIM_TELEX_CONTEXT_H
