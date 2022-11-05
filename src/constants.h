/**
 * @file    constants.h
 * @date    17.10.2021
 * @author  Thang Bui Huy <thang@mailfence.com>
 * @brief   Define some constants which are common across modules
 */


#ifndef SIM_TELEX_CONSTANTS_H
#define SIM_TELEX_CONSTANTS_H

/**
 * In Vietnamese, the longest word is \b NGHIÊNG, which has 7 characters (8 bytes) in length.
 */
#define MAX_WORD_LENGTH_IN_CHARS    7

/**
 * Because the maximum length in bytes of Vietnamese's characters is 2, the maximum length in byte
 * for the longest word will double at most (although in fact it only occupies 8 bytes). Also, add
 * space for terminated character.
 */
#define MAX_WORD_LENGTH_IN_BYTES    (((MAX_WORD_LENGTH_IN_CHARS) + 1) << 1)


#endif /* SIM_TELEX_CONSTANTS_H */
