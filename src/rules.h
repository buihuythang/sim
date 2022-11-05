/**
 * @file    rules.h
 * @date    17.10.2021
 * @author  Thang Bui Huy <thang@mailfence.com>
 * @brief   Rule implementation of SIM Telex context
 * @details There are 2 kinds of rules which this module implements. The first one is in charge of
 * Vietnamese's \e diacritics (I don't know if this is correct word in English). For example, 2 <b>
 * a</b>s form an \b â or a \b d combined with a \b d should result in a \b đ and so on... This is
 * pretty much Vietnamese Telex's standard, plus a minor modification derived from personal typing
 * style so it can handle some mistyping issues and to some extent, making the typing order more
 * flexible. As another example, \b â is the result of \b aa, but \b âw is undefined according to
 * standard rule (I guess so). So I make it (\b âw) equivalent to the [valid] \b aw, which forms \b
 * ă character. Sometimes we're done with typing a word and realize that we've just mistyped a
 * single character, and so we want to correct it without deleting the whole word. There are many
 * other cases like this one, including those with tonal marks (keep reading for details) as well.
 * This rule already been expressed by #sim_telex_keymap (see keymap.h) itself. Here basically I
 * just do some minor check. The second relates to tonal marks processing, i.e. an \b â followed by
 * a \b f produces character \b ầ, etc. AFAIK, there are 2 different versions/variations for this.
 * They called it the \e old and \e new one. Because I'm familiar with the later, the former is
 * kinda strange to my eyes. The reference source to implement \e new rule can be found at:
 * <a href="http://www.vietlex.com/xu-li-ngon-ngu/28-Quy_tac_dat_dau_thanh_trong_tieng_Viet">
 * Vietlex</a>, it also included within the \b reference directory of the repo, though.
 * It's also worth mentioning that the rules do not check for correct spelling of Vietnamese words.
 * Given the context, they check if modifier is applicable. And in case it is for not only one but
 * several characters, they decide which character to apply (tonal mark) to. Therefore, it's user
 * responsibility to type correct ones.
 */

#ifndef SIM_TELEX_RULES_H
#define SIM_TELEX_RULES_H

#include <glib.h>


/**
 * @brief Depends on modifier, either apply the first rule, second rule, or nothing at all (when no
 * meaningful key combination found)
 * @param[in]       modifier    GDK key symbol, should be received from key pressed event
 * @param[in]       source      Original text to examine. Each of its characters shall be checked
 * against modifier key for a valid combination. It should be null-terminated.
 * @param[in,out]   target      Output result in case modifier has been applied at least once
 * @return \b TRUE if modifier has been applied, and \b FALSE otherwise
 * @note As said, I suppose users know how to type correct Vietnamese words, so the function will
 * not check against invalid ones.
 */
gboolean apply_modifier(guint modifier, const gchar *source, gchar *target);


#endif  /* SIM_TELEX_RULES_H */
