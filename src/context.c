#include "context.h"
#include "keymap.h"
#include "rules.h"

#include <stdlib.h>
#include <pthread.h>
#include <pango/pango-break.h>


#define DEBUG_PRINT_GDK_EVENT_KEY   0


GType               sim_telex_type_id;
static GObjectClass *parent_class;


/**
 * @brief Class initialization function
 * @param class
 */
static void init_class_sim_telex(SIMTelexContextClass *class);


/**
 * @brief Instance initialization function
 * @param instance
 */
static void init_instance_sim_telex(SIMTelexContext *instance);


/**
 * @brief Overwrites #get_preedit_string from #GtkIMContext
 * @param context
 * @param str
 * @param attrs
 * @param cursor_pos
 */
static void get_preedit_string_sim_telex_context(GtkIMContext  *context,
                                                 gchar         **str,
                                                 PangoAttrList **attrs,
                                                 gint          *cursor_pos);


/**
 * @brief Notify the input method that the widget to which this input context corresponds has lost
 * focus. The input method may, for example, change the displayed feedback or reset the contexts
 * state to reflect this change.
 * @param context
 */
static void focus_out_sim_telex_context(GtkIMContext *context);


/**
 * @brief Overwrites #filter_keypress from #GtkIMContext to handle key press and release events.
 * @param context Input method context
 * @param event   Key event
 * @return TRUE to indicate callers that the event was consumed by the input method. In that case,
 *         the "commit" signal should be emitted upon completion of a key sequence to pass the
 *         resulting text back to the input widget.
 *         FALSE to indicate that the event wasn't handled by the input method.
 */
static gboolean filter_keypress_sim_telex_context(GtkIMContext *context, GdkEventKey *event);


/**
 * @brief
 * @param
 */
static void reset_sim_telex_context(SIMTelexContext *context);




/**
 * @brief
 * @param context
 * @param keyval
 */
static void scan_buffer(SIMTelexContext* context, guint keyval);


/**
 * @brief
 * @param context
 * @return
 */
static gboolean submit_resulting_text(SIMTelexContext *context);


/**
 * @brief Prepare preedit string and attributes (if any) for it
 * @param[in]       input_text      Base text to copy preedit string from, should be null-terminated
 * @param[in,out]   preedit_string  Resulting preedit string
 * @param[in,out]   attrs           Attributes for preedit string
 * @param[in,out]   cursor_pos      Cursor position (in term of character) within preedit string
 */
static void prepare_preedit_attributes(gchar            *input_text,
                                       gchar            **preedit_string,
                                       PangoAttrList    **attrs,
                                       gint             *cursor_pos);


void print_gdk_event_key(GdkEventKey event);


void register_type_sim_telex(GTypeModule *module)
{
    const GTypeInfo sim_telex_type_info =
    {
        (guint16) sizeof (SIMTelexContextClass),    /* Size of the class structure */
        (GBaseInitFunc) NULL,                       /* Location of base initialization function */
        (GBaseFinalizeFunc) NULL,                   /* Location of base finalization funtion */
        (GClassInitFunc) init_class_sim_telex,      /* Location of class initialization function */
        (GClassFinalizeFunc) NULL,                  /* Location of class finialization function */
        (gconstpointer) NULL,                       /* User-supplied data passed to class's init
                                                       and finalize functions */
        (guint16) sizeof (SIMTelexContext),         /* Size of instance (object) structure */
        (guint16) 0,                                /* Number of pre-allocated (cached) instances */
        (GInstanceInitFunc) init_instance_sim_telex,/* Location of instance initialization
                                                       function */
        (const GTypeValueTable*) NULL               /* Function table for generic handling */
    };

    sim_telex_type_id =
            g_type_module_register_type(module,
                                        GTK_TYPE_IM_CONTEXT,    /* Type of parent class */
                                        "SIMTelexContext",      /* Type name */
                                        &sim_telex_type_info,   /* Type information structure */
                                        0);                     /* Type flags mask */
}


GtkIMContext *create_instance_sim_telex(void)
{
    SIMTelexContext *instance = GTK_SIM_TELEX_CONTEXT(g_object_new(sim_telex_type_id, NULL));

    g_print("SIM Telex type ID is %lu\n", sim_telex_type_id);
    g_print("SIM Telex instance created\n");

    return GTK_IM_CONTEXT(instance);
}


void init_class_sim_telex(SIMTelexContextClass *class)
{
    /* Check if #class is class structure of the typed identified by #GTK_TYPE_IM_CONTEXT
     * and issues a warning if this is not the case. Returns #class casted to a pointer to
     * #GtkIMContextClass.
     */
    GtkIMContextClass *im_context_class = GTK_IM_CONTEXT_CLASS(class);

    /* Same as above, but for #GObjectClass */
    GObjectClass *object_class = G_OBJECT_CLASS(class);
    (void) object_class;

    /* Returns the class structure of the immediate parent type of the class passed in. Since
     * derived classes hold a reference count on their parent classes as long as they are
     * instantiated, the returned class will always exist.
     */
    parent_class = g_type_class_peek_parent(class);

    im_context_class->filter_keypress = filter_keypress_sim_telex_context;
    im_context_class->get_preedit_string = get_preedit_string_sim_telex_context;
    im_context_class->focus_out = focus_out_sim_telex_context;

    init_sim_telex_keymap();

    g_print("Keymap initialized with size of %lu\n", sizeof(sim_telex_keymap));
    g_print("SIM Telex class initialized\n");
}


void init_instance_sim_telex(SIMTelexContext *instance)
{
    reset_sim_telex_context(instance);

    g_print("SIM Telex instance initialized\n");
}


void get_preedit_string_sim_telex_context(GtkIMContext  *context,
                                          gchar         **str,
                                          PangoAttrList **attrs,
                                          gint          *cursor_pos)
{
    SIMTelexContext *sim_telex_context = GTK_SIM_TELEX_CONTEXT(context);

    if (sim_telex_context->length && sim_telex_context->preedit_started)
    {
        /* Preedit sequence has been started and text for it is available */
        prepare_preedit_attributes(sim_telex_context->text, str, attrs, cursor_pos);
    }
    else
    {
        /* There is no text available for preedit string or preediting sequence has already ended.
         * Either case, an empty text should be returned to widget.
         */
        prepare_preedit_attributes("", str, attrs, cursor_pos);
    }
}


static void focus_out_sim_telex_context(GtkIMContext *context)
{
    (void) context;

    g_print("SIM Telex context lost its focus\n");
}


static gboolean filter_keypress_sim_telex_context(GtkIMContext* context, GdkEventKey* event)
{
    SIMTelexContext *sim_telex_context = GTK_SIM_TELEX_CONTEXT(context);

    switch (event->type)
    {
    case GDK_KEY_PRESS:
    {
        scan_buffer(sim_telex_context, event->keyval);
        gboolean key_handled = submit_resulting_text(sim_telex_context);

        return key_handled;

    }   /* End of case #GDK_KEY_PRESS */

    default: return FALSE;

    }   /* End of switch-case #event->type */

}   /* End of #filter_keypress_sim_telex_context */


void print_gdk_event_key(GdkEventKey event)
{
    g_print("GdkEventKey\n");
    g_print("\t GdkEventType: %d \n", event.type);
    g_print("\t send_event: %d \n", event.send_event);
    g_print("\t time: %d \n", event.time);
    g_print("\t state: %d \n", event.state);
    g_print("\t keyval: %d \n", event.keyval);
    g_print("\t length: %d \n", event.length);
    g_print("\t hardware_keycode: %d \n", event.hardware_keycode);
    g_print("\t group: %d \n", event.group);
    g_print("\t is_modifier: %d \n", event.is_modifier);
}


static void reset_sim_telex_context(SIMTelexContext *context)
{
    memset(context->text, 0, MAX_WORD_LENGTH_IN_BYTES);
    context->length = 0;
    context->done = FALSE;
    context->preedit_started = FALSE;
}


static void scan_buffer(SIMTelexContext* context, guint keyval)
{
    /* Convert GDK key symbol to Unicode code point. Potentially each key symbol is a modifier. */
    gunichar mod = gdk_keyval_to_unicode(keyval);

    /* No valid equivalent Unicode code point or it's not printable for GDK key symbol */
    if (!mod || !g_unichar_isprint(mod)) return;


    if (!g_unichar_isalpha(mod))
    {
        /* #mod is not alphabetic, append it to context buffer to submit */

        /* Find current position within resulting text to insert #mod */
        gchar *resulting_pos = g_utf8_offset_to_pointer(context->text, context->length);

        /* Append #mod to the end of main text, increse current length by 1 character and we're
         * done
         */
        g_unichar_to_utf8(mod, resulting_pos);
        context->length += 1;
        context->done = TRUE;
    }
    else
    {
        gboolean mod_applied = apply_modifier(mod, context->text, context->text);

        /* If no valid keymap found W.R.T current main text, then #mod is not a modifier at all,
         * append it to resulting text
         */
        if (!mod_applied)
        {
            gchar *resulting_pos = g_utf8_offset_to_pointer(context->text, context->length);
            g_unichar_to_utf8(mod, resulting_pos);

            /* Update final length */
            context->length += 1;
        }


//        /* Temporary buffer which holds a copy of resulting text to examine. Final result will be
//         * written back to main text.
//         */
//        gchar tmp[MAX_WORD_LENGTH_IN_BYTES];
//        g_utf8_strncpy(tmp, context->text, context->length);

//        gboolean mod_applied = FALSE;   /* Has #mod been applied to any character within context */

//        /* Currently be examining character position within temporary buffer */
//        gchar *examining_pos;

//        /* Current position within main text to write resulting character to */
//        gchar *resulting_pos;

//        /* For each character of temporary buffer, check if #mod is applicable. If it is, write
//         * resulting character back to main buffer. If it is not, copy character at corresponding
//         * position from temporary buffer back to main text.
//         */
//        for (glong i = 0; i < context->length; ++i)
//        {
//            examining_pos = g_utf8_offset_to_pointer(tmp, i);

//            /* Find next UTF-8 character start @ #examining_pos */
//            gchar *utf8 = g_utf8_find_next_char(examining_pos - 1, NULL);

//            /* Convert that character to code point so to be able to check for key combination
//             * in SIM Telex keymap
//             */
//            gunichar code_point = g_utf8_get_char_validated(utf8, -1);


//            resulting_pos = g_utf8_offset_to_pointer(context->text, i);

//            if (sim_telex_keymap[code_point][keyval])
//            {
//                /* Valid keymap found, write result keymap to main text */
//                g_unichar_to_utf8(sim_telex_keymap[code_point][keyval], resulting_pos);

//                if (!mod_applied) mod_applied = TRUE;
//            }
//            else
//            {
//                /* No valid keymap found, keep current character as it is */
//                g_unichar_to_utf8(code_point, resulting_pos);
//            }
//        }


    }
}


static gboolean submit_resulting_text(SIMTelexContext* context)
{
    /* Empty resulting text, nothing to do */
    if (!context->length) return FALSE;

    if (!context->done)
    {
        g_print("Not done yet, preedit string is \"%s\"\n", context->text);

        if (!context->preedit_started)
        {
            context->preedit_started = TRUE;
            g_signal_emit_by_name(context, "preedit-start");
        }

        g_signal_emit_by_name(context, "preedit-changed");
    }
    else
    {
        g_print("Preparing to submit final result \"%s\"\n", context->text);

        /* Notify widget that preedit is now ended */
        context->preedit_started = FALSE;
        g_signal_emit_by_name(context, "preedit-changed");
        g_signal_emit_by_name(context, "preedit-end");

        /* Submit final result, started at start position of interested region, previous things
         * ignored
         */
        g_signal_emit_by_name(context, "commit", context->text);

        reset_sim_telex_context(context);
    }

    return TRUE;
}


static void prepare_preedit_attributes(gchar            *input_text,
                                       gchar            **preedit_string,
                                       PangoAttrList    **attrs,
                                       gint             *cursor_pos)
{
    if (!preedit_string)
    {
        g_printerr("Invalid preedit string pointer \n");

        return;
    }

    glong length = 0;

    if (input_text)
    {
        length = g_utf8_strlen(input_text, -1 /* Null-terminated */);
        *preedit_string = g_strdup(input_text);
    }
    else
    {
        *preedit_string = g_strdup("");
    }

    if (attrs)      /* Attribute is optional I think, so not printing error */
    {
        *attrs = pango_attr_list_new();

        /* I think attributes are only useful if preedit string is not empty */
        if (length)
        {
            PangoAttribute *underline = pango_attr_underline_new(PANGO_UNDERLINE_LOW);
            pango_attr_list_insert(*attrs, underline);
        }
    }

    if (cursor_pos) /* Cursor position is optional I think, so not printing error */
    {
        *cursor_pos = length;
    }
}
