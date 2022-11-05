/**
 * @file    rules.c
 * @date    17.10.2021
 * @author  Thang Bui Huy <thang@mailfence.com>
 */

#include "rules.h"
#include "keymap.h"
#include "constants.h"

#include <gdk/gdkkeysyms.h>


/**
 * @brief Check if diacritic is applicable for input source text and produce output accordingly
 * @param[in]       modifier    GDK key symbol, should be received from key pressed event
 * @param[in]       source      Original text to examine. Each of its characters shall be checked
 * against modifier key for a valid combination. It should be null-terminated.
 * @param[in,out]   target      Output result in case modifier has been applied at least once
 * @return \b TRUE if modifier has been applied, and \b FALSE otherwise
 * @note As said, I suppose users know how to type correct Vietnamese words, so the function will
 * not check against invalid ones.
 */
static gboolean apply_diacritic(guint modifier, const gchar *source, gchar *target);


/**
 * @brief Check if tonal mark is applicable for input source text and produce output accordingly
 * @param[in]       modifier    GDK key symbol, should be received from key pressed event
 * @param[in]       source      Original text to examine. Each of its characters shall be checked
 * against modifier key for a valid combination. It should be null-terminated.
 * @param[in,out]   target      Output result in case modifier has been applied at least once
 * @return \b TRUE if modifier has been applied, and \b FALSE otherwise
 * @note As said, I suppose users know how to type correct Vietnamese words, so the function will
 * not check against invalid ones.
 */
static gboolean apply_tone(guint modifier, const gchar *source, gchar *target);


gboolean apply_modifier(guint modifier, const gchar *source, gchar *target)
{
    switch (modifier)
    {
    case GDK_KEY_A:
    case GDK_KEY_D:
    case GDK_KEY_E:
    case GDK_KEY_O:
    case GDK_KEY_W:
    case GDK_KEY_a:
    case GDK_KEY_d:
    case GDK_KEY_e:
    case GDK_KEY_o:
    case GDK_KEY_w:
        return apply_diacritic(modifier, source, target);

    case GDK_KEY_F:
    case GDK_KEY_J:
    case GDK_KEY_R:
    case GDK_KEY_S:
    case GDK_KEY_X:
    case GDK_KEY_f:
    case GDK_KEY_j:
    case GDK_KEY_r:
    case GDK_KEY_s:
    case GDK_KEY_x:
        return apply_tone(modifier, source, target);

    default:
        return FALSE;
    }
}


static gboolean apply_diacritic(guint modifier, const gchar *source, gchar *target)
{
    /* There are only 10 modifiers which make diacritic (see #apply_modifier), so the condition is
     * somewhat beyond scope. But to boost-up the process (because it has already been catched up
     * by caller), criteria has been loosened.
     */
    if (modifier < GDK_KEY_A || modifier > GDK_KEY_z) return FALSE;

    /* Either source text or resulting pointer is invalid, nothing to do */
    if (!source || !target) return FALSE;


    gboolean    mod_applied = FALSE;    /* Has modifier been applied at least once to any character
                                           within source text? */
    glong       length      = g_utf8_strlen(source, -1 /* Null-terminated */);
    const gchar *buffer     = NULL;     /* Pointer to original text */

    /* Make a copy to examnine upon it instead of original one, because original text will now
     * hold the result
     */
    if (source == target)
    {
        gchar copy[MAX_WORD_LENGTH_IN_BYTES];
        g_utf8_strncpy(copy, source, length);
        buffer = copy;
    }
    else
    {
        buffer = source;
    }

    /* Currently be examining character position within original buffer */
    gchar *examining_pos;

    /* Current position within target buffer to write resulting character to */
    gchar *resulting_pos;

    /* For each character of t source text, check if modifier is applicable. If it is, write
     * resulting character back to target buffer. If it is not, copy character at corresponding
     * position from source back to target.
     */
    for (glong i = 0; i < length; ++i)
    {
        examining_pos = g_utf8_offset_to_pointer(buffer, i);

        /* Find next UTF-8 character start @ #examining_pos */
        gchar *utf8 = g_utf8_find_next_char(examining_pos - 1, NULL);

        /* Convert that character to code point so to be able to check for key combination
         * in SIM Telex keymap
         */
        gunichar code_point = g_utf8_get_char_validated(utf8, -1 /* Null-terminated */);


        resulting_pos = g_utf8_offset_to_pointer(target, i);

        if (sim_telex_keymap[code_point][modifier])
        {
            /* Valid keymap found, write resulting keymap to target text */
            g_unichar_to_utf8(sim_telex_keymap[code_point][modifier], resulting_pos);

            if (!mod_applied) mod_applied = TRUE;
        }
        else
        {
            /* No valid keymap found, keep current character as it is */
            g_unichar_to_utf8(code_point, resulting_pos);
        }
    }

    return mod_applied;
}


static gboolean apply_tone(guint modifier, const gchar *source, gchar *target)
{
    return FALSE;
}
