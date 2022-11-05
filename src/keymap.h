/**
 * @file    keymap.h
 * @date    18.09.2021
 * @author  Thang Bui Huy <thang@mailfence.com>
 * @brief   Build keymap for SIM Telex
 * @details The idea is build some kind of instant look-up each time a key event occurs to check
 * if that key, along with each Unicode character of current surrounding text (if any) make any
 * sense according to Vietnamese's Telex input rules. So I think using an array is reasonable.
 * The first array dimension (row) denotes Unicode code point of main character in which a valid
 * modifier which denoted by second dimension (column) in GDK key values might be applied upon.
 * So checking if a key combination is valid means checking if corresponding array element
 * has a value filled in. Typically, 0 means there is no such combination, and a valid Unicode
 * code point otherwise. The downside of this approach is kinda waste of space, because the array
 * is not being used in its full capacity, there are many zero-ed elements. The maximum number of
 * rows is the largest Unicode code point of a meaningful Vietnamese character, which is \b ỹ,
 * plus \b 1 (so we don't have to minus 1 to check key combination). And the maximum number of
 * columns is the GDK key value of character \b x, which is the largest modifier in Vietnamese's
 * Telex, plus \b 1 (reason as above).
 */

#ifndef SIM_TELEX_KEYMAP_H
#define SIM_TELEX_KEYMAP_H

#include <glib.h>


/**
 * Maximum number of rows (first dimension for SIM Telex keymap). \b 0x1EF9 is Unicode code point
 * of character \b ỹ in Vietnamese.
 */
#define SIM_TELEX_KEYMAP_N_ROWS    (0x1EF9 + 1)

/**
 * Maximum number of columns (second dimension for SIM Telex keymap). \b 0x0078 is GDK key value
 * of character \b x, which is valid modifier in Vietnamese with largest GDK key value.
 */
#define SIM_TELEX_KEYMAP_N_COLS    (0x0078 + 1)

/**
 * @brief The keymap, as explained above. As an example, suppose we need to access an element with
 * row and column indexes as \b i and \b j, respectively. Then, within <b>sim_telex_keymap[i][j]</b>
 * expression, row index \b i denotes the Unicode code point of a character which is valid
 * applicable by column index \b j which is GDK key value. The scenario is each time an key event
 * occurs, surrounding text should be acquired and each of character contained within will be
 * checked against key value \b j to see if a meaningful combination exists. As said, meaningful
 * here means there is value for that element, which is Unicode code point of some Vietnamese's
 * characters. And so, meaningless means there is no value for it, i.e. \b 0.
 */
extern gunichar sim_telex_keymap[SIM_TELEX_KEYMAP_N_ROWS][SIM_TELEX_KEYMAP_N_COLS];

/**
 * @brief Initializes SIM Telex keymap for specific Vietnamese's characters, simply by following
 * Vietnamese's alphabet and then listing one by one. Non-existent characters (key combinations)
 * are zero filled.
 */
void init_sim_telex_keymap();


#endif /* SIM_TELEX_KEYMAP_H */
