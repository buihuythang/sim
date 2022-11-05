/**
 * @file    sim-telex-keymap.c
 * @date    18.09.2021
 * @author  Thang Bui Huy <thang@mailfence.com>
 */

#include "keymap.h"
#include <gdk/gdkkeysyms.h>


/**
 * A(0x0041) À(0x00C0) Ạ(0x1EA0) Ả(0x1EA2) Á(0x00C1) Ã(0x00C3) Ă(0x0102) Ằ(0x1EB0) Ặ(0x1EB6)
 * Ẳ(0x1EB2) Ắ(0x1EAE) Ẵ(0x1EB4) Â(0x00C2) Ầ(0x1EA6) Ậ(0x1EAC) Ẩ(0x1EA8) Ấ(0x1EA4) Ẫ(0x1EAA)
 * D(0x0044) Đ(0x0110) E(0x0045) È(0x00C8) Ẹ(0x1EB8) Ẻ(0x1EBA) É(0x00C9) Ẽ(0x1EBC) Ê(0x00CA)
 * Ề(0x1EC0) Ệ(0x1EC6) Ể(0x1EC2) Ế(0x1EBE) Ễ(0x1EC4) I(0x0049) Ì(0x00CC) Ị(0x1ECA) Ỉ(0x1EC8)
 * Í(0x00CD) Ĩ(0x0128) O(0x004F) Ò(0x00D2) Ọ(0x1ECC) Ỏ(0x1ECE) Ó(0x00D3) Õ(0x00D5) Ơ(0x01A0)
 * Ờ(0x1EDC) Ợ(0x1EE2) Ở(0x1EDE) Ớ(0x1EDA) Ỡ(0x1EE0) Ô(0x00D4) Ồ(0x1ED2) Ộ(0x1ED8) Ổ(0x1ED4)
 * Ố(0x1ED0) Ỗ(0x1ED6) U(0x0055) Ù(0x00D9) Ụ(0x1EE4) Ủ(0x1EE6) Ú(0x00DA) Ũ(0x0168) Ư(0x01AF)
 * Ừ(0x1EEA) Ự(0x1EF0) Ử(0x1EEC) Ứ(0x1EE8) Ữ(0x1EEE) Y(0x0059) Ỳ(0x1EF2) Ỵ(0x1EF4) Ỷ(0x1EF6)
 * Ý(0x00DD) Ỹ(0x1EF8) a(0x0061) à(0x00E0) ạ(0x1EA1) ả(0x1EA3) á(0x00E1) ã(0x00E3) ă(0x0103)
 * ằ(0x1EB1) ặ(0x1EB7) ẳ(0x1EB3) ắ(0x1EAF) ẵ(0x1EB5) â(0x00E2) ầ(0x1EA7) ậ(0x1EAD) ẩ(0x1EA9)
 * ấ(0x1EA5) ẫ(0x1EAB) d(0x0064) đ(0x0111) e(0x0065) è(0x00E8) ẹ(0x1EB9) ẻ(0x1EBB) é(0x00E9)
 * ẽ(0x1EBD) ê(0x00EA) ề(0x1EC1) ệ(0x1EC7) ể(0x1EC3) ế(0x1EBF) ễ(0x1EC5) i(0x0069) ì(0x00EC)
 * ị(0x1ECB) ỉ(0x1EC9) í(0x00ED) ĩ(0x0129) o(0x006F) ò(0x00F2) ọ(0x1ECD) ỏ(0x1ECF) ó(0x00F3)
 * õ(0x00F5) ơ(0x01A1) ờ(0x1EDD) ợ(0x1EE3) ở(0x1EDF) ớ(0x1EDB) ỡ(0x1EE1) ô(0x00F4) ồ(0x1ED3)
 * ộ(0x1ED9) ổ(0x1ED5) ố(0x1ED1) ỗ(0x1ED7) u(0x0075) ù(0x00F9) ụ(0x1EE5) ủ(0x1EE7) ú(0x00FA)
 * ũ(0x0169) ư(0x01B0) ừ(0x1EEB) ự(0x1EF1) ử(0x1EED) ứ(0x1EE9) ữ(0x1EEF) y(0x0079) ỳ(0x1EF3)
 * ỵ(0x1EF5) ỷ(0x1EF7) ý(0x00FD) ỹ(0x1EF9)
 */
gunichar sim_telex_keymap[SIM_TELEX_KEYMAP_N_ROWS][SIM_TELEX_KEYMAP_N_COLS] = {{0}};


void init_sim_telex_keymap()
{
    /**
     * Block
     * a(0x0061) à(0x00E0) ạ(0x1EA1) ả(0x1EA3) á(0x00E1) ã(0x00E3)
     */
    /* af ạf ảf áf ãf = à */
    sim_telex_keymap[0x0061][GDK_KEY_f] = sim_telex_keymap[0x0061][GDK_KEY_F] =
    sim_telex_keymap[0x1EA1][GDK_KEY_f] = sim_telex_keymap[0x1EA1][GDK_KEY_F] =
    sim_telex_keymap[0x1EA3][GDK_KEY_f] = sim_telex_keymap[0x1EA3][GDK_KEY_F] =
    sim_telex_keymap[0x00E1][GDK_KEY_f] = sim_telex_keymap[0x00E1][GDK_KEY_F] =
    sim_telex_keymap[0x00E3][GDK_KEY_f] = sim_telex_keymap[0x00E3][GDK_KEY_F] = 0x00E0;

    /* aj àj ảj áj ãj = ạ */
    sim_telex_keymap[0x0061][GDK_KEY_j] =  sim_telex_keymap[0x0061][GDK_KEY_J] =
    sim_telex_keymap[0x00E0][GDK_KEY_j] =  sim_telex_keymap[0x00E0][GDK_KEY_J] =
    sim_telex_keymap[0x1EA3][GDK_KEY_j] =  sim_telex_keymap[0x1EA3][GDK_KEY_J] =
    sim_telex_keymap[0x00E1][GDK_KEY_j] =  sim_telex_keymap[0x00E1][GDK_KEY_J] =
    sim_telex_keymap[0x00E3][GDK_KEY_j] =  sim_telex_keymap[0x00E3][GDK_KEY_J] = 0x1EA1;

    /* ar àr ạr ár ãr = ả */
    sim_telex_keymap[0x0061][GDK_KEY_r] = sim_telex_keymap[0x0061][GDK_KEY_R] =
    sim_telex_keymap[0x00E0][GDK_KEY_r] = sim_telex_keymap[0x00E0][GDK_KEY_R] =
    sim_telex_keymap[0x1EA1][GDK_KEY_r] = sim_telex_keymap[0x1EA1][GDK_KEY_R] =
    sim_telex_keymap[0x00E1][GDK_KEY_r] = sim_telex_keymap[0x00E1][GDK_KEY_R] =
    sim_telex_keymap[0x00E3][GDK_KEY_r] = sim_telex_keymap[0x00E3][GDK_KEY_R] = 0x1EA3;

    /* as às ạs ảs ãs = á */
    sim_telex_keymap[0x0061][GDK_KEY_s] = sim_telex_keymap[0x0061][GDK_KEY_S] =
    sim_telex_keymap[0x00E0][GDK_KEY_s] = sim_telex_keymap[0x00E0][GDK_KEY_S] =
    sim_telex_keymap[0x1EA1][GDK_KEY_s] = sim_telex_keymap[0x1EA1][GDK_KEY_S] =
    sim_telex_keymap[0x1EA3][GDK_KEY_s] = sim_telex_keymap[0x1EA3][GDK_KEY_S] =
    sim_telex_keymap[0x00E3][GDK_KEY_s] = sim_telex_keymap[0x00E3][GDK_KEY_S] = 0x00E1;

    /* ax àx ạx ảx áx = ã */
    sim_telex_keymap[0x0061][GDK_KEY_x] = sim_telex_keymap[0x0061][GDK_KEY_X] =
    sim_telex_keymap[0x00E0][GDK_KEY_x] = sim_telex_keymap[0x00E0][GDK_KEY_X] =
    sim_telex_keymap[0x1EA1][GDK_KEY_x] = sim_telex_keymap[0x1EA1][GDK_KEY_X] =
    sim_telex_keymap[0x1EA3][GDK_KEY_x] = sim_telex_keymap[0x1EA3][GDK_KEY_X] =
    sim_telex_keymap[0x00E1][GDK_KEY_x] = sim_telex_keymap[0x00E1][GDK_KEY_X] = 0x00E3;

    /**
     * Block
     * ă(0x0103) ằ(0x1EB1) ặ(0x1EB7) ẳ(0x1EB3) ắ(0x1EAF) ẵ(0x1EB5)
     * a(0x0061) à(0x00E0) ạ(0x1EA1) ả(0x1EA3) á(0x00E1) ã(0x00E3) (for reference)
     * â(0x00E2) ầ(0x1EA7) ậ(0x1EAD) ẩ(0x1EA9) ấ(0x1EA5) ẫ(0x1EAB) (for reference)
     */
    /* aw âw = ă */
    sim_telex_keymap[0x0061][GDK_KEY_w] = sim_telex_keymap[0x0061][GDK_KEY_W] =
    sim_telex_keymap[0x00E2][GDK_KEY_w] = sim_telex_keymap[0x00E2][GDK_KEY_W] = 0x0103;

    /* ăf ặf ẳf ắf ẵf àw ầw = ằ */
    sim_telex_keymap[0x0103][GDK_KEY_f] = sim_telex_keymap[0x0103][GDK_KEY_F] =
    sim_telex_keymap[0x1EB7][GDK_KEY_f] = sim_telex_keymap[0x1EB7][GDK_KEY_F] =
    sim_telex_keymap[0x1EB3][GDK_KEY_f] = sim_telex_keymap[0x1EB3][GDK_KEY_F] =
    sim_telex_keymap[0x1EAF][GDK_KEY_f] = sim_telex_keymap[0x1EAF][GDK_KEY_F] =
    sim_telex_keymap[0x1EB5][GDK_KEY_f] = sim_telex_keymap[0x1EB5][GDK_KEY_F] =
    sim_telex_keymap[0x00E0][GDK_KEY_w] = sim_telex_keymap[0x00E0][GDK_KEY_W] =
    sim_telex_keymap[0x1EA7][GDK_KEY_w] = sim_telex_keymap[0x1EA7][GDK_KEY_W] = 0x1EB1;

    /* ăj ằj ẳj ắj ẵj ạw ậw= ặ */
    sim_telex_keymap[0x0103][GDK_KEY_j] = sim_telex_keymap[0x0103][GDK_KEY_J] =
    sim_telex_keymap[0x1EB1][GDK_KEY_j] = sim_telex_keymap[0x1EB1][GDK_KEY_J] =
    sim_telex_keymap[0x1EB3][GDK_KEY_j] = sim_telex_keymap[0x1EB3][GDK_KEY_J] =
    sim_telex_keymap[0x1EAF][GDK_KEY_j] = sim_telex_keymap[0x1EAF][GDK_KEY_J] =
    sim_telex_keymap[0x1EB5][GDK_KEY_j] = sim_telex_keymap[0x1EB5][GDK_KEY_J] =
    sim_telex_keymap[0x1EA1][GDK_KEY_w] = sim_telex_keymap[0x1EA1][GDK_KEY_W] =
    sim_telex_keymap[0x1EAD][GDK_KEY_w] = sim_telex_keymap[0x1EAD][GDK_KEY_W] = 0x1EB7;

    /* ăr ằr ặr ắr ẵr ảw ẩw = ẳ */
    sim_telex_keymap[0x0103][GDK_KEY_r] = sim_telex_keymap[0x0103][GDK_KEY_R] =
    sim_telex_keymap[0x1EB1][GDK_KEY_r] = sim_telex_keymap[0x1EB1][GDK_KEY_R] =
    sim_telex_keymap[0x1EB7][GDK_KEY_r] = sim_telex_keymap[0x1EB7][GDK_KEY_R] =
    sim_telex_keymap[0x1EAF][GDK_KEY_r] = sim_telex_keymap[0x1EAF][GDK_KEY_R] =
    sim_telex_keymap[0x1EB5][GDK_KEY_r] = sim_telex_keymap[0x1EB5][GDK_KEY_R] =
    sim_telex_keymap[0x1EA3][GDK_KEY_w] = sim_telex_keymap[0x1EA3][GDK_KEY_W] =
    sim_telex_keymap[0x1EA9][GDK_KEY_w] = sim_telex_keymap[0x1EA9][GDK_KEY_W] = 0x1EB3;

    /* ăs ằs ặs ẳs ẵs áw ấw = ắ */
    sim_telex_keymap[0x0103][GDK_KEY_s] = sim_telex_keymap[0x0103][GDK_KEY_S] =
    sim_telex_keymap[0x1EB1][GDK_KEY_s] = sim_telex_keymap[0x1EB1][GDK_KEY_S] =
    sim_telex_keymap[0x1EB7][GDK_KEY_s] = sim_telex_keymap[0x1EB7][GDK_KEY_S] =
    sim_telex_keymap[0x1EB3][GDK_KEY_s] = sim_telex_keymap[0x1EB3][GDK_KEY_S] =
    sim_telex_keymap[0x1EB5][GDK_KEY_s] = sim_telex_keymap[0x1EB5][GDK_KEY_S] =
    sim_telex_keymap[0x00E1][GDK_KEY_w] = sim_telex_keymap[0x00E1][GDK_KEY_W] =
    sim_telex_keymap[0x1EA5][GDK_KEY_w] = sim_telex_keymap[0x1EA5][GDK_KEY_W] = 0x1EAF;

    /* ăx ằx ặx ẳx ắx ãw ẫw = ẵ */
    sim_telex_keymap[0x0103][GDK_KEY_x] = sim_telex_keymap[0x0103][GDK_KEY_X] =
    sim_telex_keymap[0x1EB1][GDK_KEY_x] = sim_telex_keymap[0x1EB1][GDK_KEY_X] =
    sim_telex_keymap[0x1EB7][GDK_KEY_x] = sim_telex_keymap[0x1EB7][GDK_KEY_X] =
    sim_telex_keymap[0x1EB3][GDK_KEY_x] = sim_telex_keymap[0x1EB3][GDK_KEY_X] =
    sim_telex_keymap[0x1EAF][GDK_KEY_x] = sim_telex_keymap[0x1EAF][GDK_KEY_X] =
    sim_telex_keymap[0x00E3][GDK_KEY_w] = sim_telex_keymap[0x00E3][GDK_KEY_W] =
    sim_telex_keymap[0x1EAB][GDK_KEY_w] = sim_telex_keymap[0x1EAB][GDK_KEY_W] = 0x1EB5;

    /**
     * Block
     * â(0x00E2) ầ(0x1EA7) ậ(0x1EAD) ẩ(0x1EA9) ấ(0x1EA5) ẫ(0x1EAB)
     * a(0x0061) à(0x00E0) ạ(0x1EA1) ả(0x1EA3) á(0x00E1) ã(0x00E3) (for reference)
     * ă(0x0103) ằ(0x1EB1) ặ(0x1EB7) ẳ(0x1EB3) ắ(0x1EAF) ẵ(0x1EB5) (for reference)
     */
    /* aa ăa = â */
    sim_telex_keymap[0x0061][GDK_KEY_a] = sim_telex_keymap[0x0061][GDK_KEY_A] =
    sim_telex_keymap[0x0103][GDK_KEY_a] = sim_telex_keymap[0x0103][GDK_KEY_A] = 0x00E2;

    /* âf ậf ẩf ấf ẫf àa ằa = ầ */
    sim_telex_keymap[0x00E2][GDK_KEY_f] = sim_telex_keymap[0x00E2][GDK_KEY_F] =
    sim_telex_keymap[0x1EAD][GDK_KEY_f] = sim_telex_keymap[0x1EAD][GDK_KEY_F] =
    sim_telex_keymap[0x1EA9][GDK_KEY_f] = sim_telex_keymap[0x1EA9][GDK_KEY_F] =
    sim_telex_keymap[0x1EA5][GDK_KEY_f] = sim_telex_keymap[0x1EA5][GDK_KEY_F] =
    sim_telex_keymap[0x1EAB][GDK_KEY_f] = sim_telex_keymap[0x1EAB][GDK_KEY_F] =
    sim_telex_keymap[0x00E0][GDK_KEY_a] = sim_telex_keymap[0x00E0][GDK_KEY_A] =
    sim_telex_keymap[0x1EB1][GDK_KEY_a] = sim_telex_keymap[0x1EB1][GDK_KEY_A] = 0x1EA7;

    /* âj ầj ẩj ấj ẫj ạa ặa = ậ */
    sim_telex_keymap[0x00E2][GDK_KEY_j] = sim_telex_keymap[0x00E2][GDK_KEY_J] =
    sim_telex_keymap[0x1EA7][GDK_KEY_j] = sim_telex_keymap[0x1EA7][GDK_KEY_J] =
    sim_telex_keymap[0x1EA9][GDK_KEY_j] = sim_telex_keymap[0x1EA9][GDK_KEY_J] =
    sim_telex_keymap[0x1EA5][GDK_KEY_j] = sim_telex_keymap[0x1EA5][GDK_KEY_J] =
    sim_telex_keymap[0x1EAB][GDK_KEY_j] = sim_telex_keymap[0x1EAB][GDK_KEY_J] =
    sim_telex_keymap[0x1EA1][GDK_KEY_a] = sim_telex_keymap[0x1EA1][GDK_KEY_A] =
    sim_telex_keymap[0x1EB7][GDK_KEY_a] = sim_telex_keymap[0x1EB7][GDK_KEY_A] = 0x1EAD;

    /* âr ầr ậr ấr ẫr ảa ẳa = ẩ */
    sim_telex_keymap[0x00E2][GDK_KEY_r] = sim_telex_keymap[0x00E2][GDK_KEY_R] =
    sim_telex_keymap[0x1EA7][GDK_KEY_r] = sim_telex_keymap[0x1EA7][GDK_KEY_R] =
    sim_telex_keymap[0x1EAD][GDK_KEY_r] = sim_telex_keymap[0x1EAD][GDK_KEY_R] =
    sim_telex_keymap[0x1EA5][GDK_KEY_r] = sim_telex_keymap[0x1EA5][GDK_KEY_R] =
    sim_telex_keymap[0x1EAB][GDK_KEY_r] = sim_telex_keymap[0x1EAB][GDK_KEY_R] =
    sim_telex_keymap[0x1EA3][GDK_KEY_a] = sim_telex_keymap[0x1EA3][GDK_KEY_A] =
    sim_telex_keymap[0x1EB3][GDK_KEY_a] = sim_telex_keymap[0x1EB3][GDK_KEY_A] = 0x1EA9;

    /* âs ầs ậs ẩs ẫs áa ắa = ấ */
    sim_telex_keymap[0x00E2][GDK_KEY_s] = sim_telex_keymap[0x00E2][GDK_KEY_S] =
    sim_telex_keymap[0x1EA7][GDK_KEY_s] = sim_telex_keymap[0x1EA7][GDK_KEY_S] =
    sim_telex_keymap[0x1EAD][GDK_KEY_s] = sim_telex_keymap[0x1EAD][GDK_KEY_S] =
    sim_telex_keymap[0x1EA9][GDK_KEY_s] = sim_telex_keymap[0x1EA9][GDK_KEY_S] =
    sim_telex_keymap[0x1EAB][GDK_KEY_s] = sim_telex_keymap[0x1EAB][GDK_KEY_S] =
    sim_telex_keymap[0x00E1][GDK_KEY_a] = sim_telex_keymap[0x00E1][GDK_KEY_A] =
    sim_telex_keymap[0x1EAF][GDK_KEY_a] = sim_telex_keymap[0x1EAF][GDK_KEY_A] = 0x1EA5;

    /* âx ầx ậx ẩx ấx ãa ẵa = ẫ */
    sim_telex_keymap[0x00E2][GDK_KEY_x] = sim_telex_keymap[0x00E2][GDK_KEY_X] =
    sim_telex_keymap[0x1EA7][GDK_KEY_x] = sim_telex_keymap[0x1EA7][GDK_KEY_X] =
    sim_telex_keymap[0x1EAD][GDK_KEY_x] = sim_telex_keymap[0x1EAD][GDK_KEY_X] =
    sim_telex_keymap[0x1EA9][GDK_KEY_x] = sim_telex_keymap[0x1EA9][GDK_KEY_X] =
    sim_telex_keymap[0x1EA5][GDK_KEY_x] = sim_telex_keymap[0x1EA5][GDK_KEY_X] =
    sim_telex_keymap[0x00E3][GDK_KEY_a] = sim_telex_keymap[0x00E3][GDK_KEY_A] =
    sim_telex_keymap[0x1EB5][GDK_KEY_a] = sim_telex_keymap[0x1EB5][GDK_KEY_A] = 0x1EAB;

    /**
     * Block
     * d(0x0064) đ(0x0111)
     */
    /* dd = đ */
    sim_telex_keymap[0x0064][GDK_KEY_d] =  sim_telex_keymap[0x0064][GDK_KEY_D] = 0x0111;

    /**
     * Block
     * e(0x0065) è(0x00E8) ẹ(0x1EB9) ẻ(0x1EBB) é(0x00E9) ẽ(0x1EBD)
     */
    /* ef ẹf ẻf éf ẽf = è */
    sim_telex_keymap[0x0065][GDK_KEY_f] = sim_telex_keymap[0x0065][GDK_KEY_F] =
    sim_telex_keymap[0x1EB9][GDK_KEY_f] = sim_telex_keymap[0x1EB9][GDK_KEY_F] =
    sim_telex_keymap[0x1EBB][GDK_KEY_f] = sim_telex_keymap[0x1EBB][GDK_KEY_F] =
    sim_telex_keymap[0x00E9][GDK_KEY_f] = sim_telex_keymap[0x00E9][GDK_KEY_F] =
    sim_telex_keymap[0x1EBD][GDK_KEY_f] = sim_telex_keymap[0x1EBD][GDK_KEY_F] = 0x00E8;

    /* ej èj ẻj éj ẽj = ẹ */
    sim_telex_keymap[0x0065][GDK_KEY_j] = sim_telex_keymap[0x0065][GDK_KEY_J] =
    sim_telex_keymap[0x00E8][GDK_KEY_j] = sim_telex_keymap[0x00E8][GDK_KEY_J] =
    sim_telex_keymap[0x1EBB][GDK_KEY_j] = sim_telex_keymap[0x1EBB][GDK_KEY_J] =
    sim_telex_keymap[0x00E9][GDK_KEY_j] = sim_telex_keymap[0x00E9][GDK_KEY_J] =
    sim_telex_keymap[0x1EBD][GDK_KEY_j] = sim_telex_keymap[0x1EBD][GDK_KEY_J] = 0x1EB9;

    /* er èr ẹr ér ẽr = ẻ */
    sim_telex_keymap[0x0065][GDK_KEY_r] = sim_telex_keymap[0x0065][GDK_KEY_R] =
    sim_telex_keymap[0x00E8][GDK_KEY_r] = sim_telex_keymap[0x00E8][GDK_KEY_R] =
    sim_telex_keymap[0x1EB9][GDK_KEY_r] = sim_telex_keymap[0x1EB9][GDK_KEY_R] =
    sim_telex_keymap[0x00E9][GDK_KEY_r] = sim_telex_keymap[0x00E9][GDK_KEY_R] =
    sim_telex_keymap[0x1EBD][GDK_KEY_r] = sim_telex_keymap[0x1EBD][GDK_KEY_R] = 0x1EBB;

    /* es ès ẹs ẻs ẽs = é */
    sim_telex_keymap[0x0065][GDK_KEY_s] = sim_telex_keymap[0x0065][GDK_KEY_S] =
    sim_telex_keymap[0x00E8][GDK_KEY_s] = sim_telex_keymap[0x00E8][GDK_KEY_S] =
    sim_telex_keymap[0x1EB9][GDK_KEY_s] = sim_telex_keymap[0x1EB9][GDK_KEY_S] =
    sim_telex_keymap[0x1EBB][GDK_KEY_s] = sim_telex_keymap[0x1EBB][GDK_KEY_S] =
    sim_telex_keymap[0x1EBD][GDK_KEY_s] = sim_telex_keymap[0x1EBD][GDK_KEY_S] = 0x00E9;

    /* ex èx ẹx ẻx éx = ẽ */
    sim_telex_keymap[0x0065][GDK_KEY_x] = sim_telex_keymap[0x0065][GDK_KEY_X] =
    sim_telex_keymap[0x00E8][GDK_KEY_x] = sim_telex_keymap[0x00E8][GDK_KEY_X] =
    sim_telex_keymap[0x1EB9][GDK_KEY_x] = sim_telex_keymap[0x1EB9][GDK_KEY_X] =
    sim_telex_keymap[0x1EBB][GDK_KEY_x] = sim_telex_keymap[0x1EBB][GDK_KEY_X] =
    sim_telex_keymap[0x00E9][GDK_KEY_x] = sim_telex_keymap[0x00E9][GDK_KEY_X] = 0x1EBD;

    /**
     * Block
     * ê(0x00EA) ề(0x1EC1) ệ(0x1EC7) ể(0x1EC3) ế(0x1EBF) ễ(0x1EC5)
     * e(0x0065) è(0x00E8) ẹ(0x1EB9) ẻ(0x1EBB) é(0x00E9) ẽ(0x1EBD) (for reference)
     */
    /* ee = ê */
    sim_telex_keymap[0x0065][GDK_KEY_e] = sim_telex_keymap[0x0065][GDK_KEY_E] = 0x00EA;

    /* êf ệf ểf ếf ễf èe = ề */
    sim_telex_keymap[0x00EA][GDK_KEY_f] = sim_telex_keymap[0x00EA][GDK_KEY_F] =
    sim_telex_keymap[0x1EC7][GDK_KEY_f] = sim_telex_keymap[0x1EC7][GDK_KEY_F] =
    sim_telex_keymap[0x1EC3][GDK_KEY_f] = sim_telex_keymap[0x1EC3][GDK_KEY_F] =
    sim_telex_keymap[0x1EBF][GDK_KEY_f] = sim_telex_keymap[0x1EBF][GDK_KEY_F] =
    sim_telex_keymap[0x1EC5][GDK_KEY_f] = sim_telex_keymap[0x1EC5][GDK_KEY_F] =
    sim_telex_keymap[0x00E8][GDK_KEY_e] = sim_telex_keymap[0x00E8][GDK_KEY_E] = 0x1EC1;

    /* êj ềj ểj ếj ễj ẹe = ệ */
    sim_telex_keymap[0x00EA][GDK_KEY_j] = sim_telex_keymap[0x00EA][GDK_KEY_J] =
    sim_telex_keymap[0x1EC1][GDK_KEY_j] = sim_telex_keymap[0x1EC1][GDK_KEY_J] =
    sim_telex_keymap[0x1EC3][GDK_KEY_j] = sim_telex_keymap[0x1EC3][GDK_KEY_J] =
    sim_telex_keymap[0x1EBF][GDK_KEY_j] = sim_telex_keymap[0x1EBF][GDK_KEY_J] =
    sim_telex_keymap[0x1EC5][GDK_KEY_j] = sim_telex_keymap[0x1EC5][GDK_KEY_J] =
    sim_telex_keymap[0x1EB9][GDK_KEY_e] = sim_telex_keymap[0x1EB9][GDK_KEY_E] = 0x1EC7;

    /* êr ềr ệr ếr ễr ẻe = ể */
    sim_telex_keymap[0x00EA][GDK_KEY_r] = sim_telex_keymap[0x00EA][GDK_KEY_R] =
    sim_telex_keymap[0x1EC1][GDK_KEY_r] = sim_telex_keymap[0x1EC1][GDK_KEY_R] =
    sim_telex_keymap[0x1EC7][GDK_KEY_r] = sim_telex_keymap[0x1EC7][GDK_KEY_R] =
    sim_telex_keymap[0x1EBF][GDK_KEY_r] = sim_telex_keymap[0x1EBF][GDK_KEY_R] =
    sim_telex_keymap[0x1EC5][GDK_KEY_r] = sim_telex_keymap[0x1EC5][GDK_KEY_R] =
    sim_telex_keymap[0x1EBB][GDK_KEY_e] = sim_telex_keymap[0x1EBB][GDK_KEY_E] = 0x1EC3;

    /* ês ềs ệs ểs ễs ée = ế */
    sim_telex_keymap[0x00EA][GDK_KEY_s] = sim_telex_keymap[0x00EA][GDK_KEY_S] =
    sim_telex_keymap[0x1EC1][GDK_KEY_s] = sim_telex_keymap[0x1EC1][GDK_KEY_S] =
    sim_telex_keymap[0x1EC7][GDK_KEY_s] = sim_telex_keymap[0x1EC7][GDK_KEY_S] =
    sim_telex_keymap[0x1EC3][GDK_KEY_s] = sim_telex_keymap[0x1EC3][GDK_KEY_S] =
    sim_telex_keymap[0x1EC5][GDK_KEY_s] = sim_telex_keymap[0x1EC5][GDK_KEY_S] =
    sim_telex_keymap[0x00E9][GDK_KEY_e] = sim_telex_keymap[0x00E9][GDK_KEY_E] = 0x1EBF;

    /* êx ềx ệx ểx ếx ẽe = ễ */
    sim_telex_keymap[0x00EA][GDK_KEY_x] = sim_telex_keymap[0x00EA][GDK_KEY_X] =
    sim_telex_keymap[0x1EC1][GDK_KEY_x] = sim_telex_keymap[0x1EC1][GDK_KEY_X] =
    sim_telex_keymap[0x1EC7][GDK_KEY_x] = sim_telex_keymap[0x1EC7][GDK_KEY_X] =
    sim_telex_keymap[0x1EC3][GDK_KEY_x] = sim_telex_keymap[0x1EC3][GDK_KEY_X] =
    sim_telex_keymap[0x1EBF][GDK_KEY_x] = sim_telex_keymap[0x1EBF][GDK_KEY_X] =
    sim_telex_keymap[0x1EBD][GDK_KEY_e] = sim_telex_keymap[0x1EBD][GDK_KEY_E] = 0x1EC5;

    /**
     * Block
     * i(0x0069) ì(0x00EC) ị(0x1ECB) ỉ(0x1EC9) í(0x00ED) ĩ(0x0129)
     */
    /* if ịf ỉf íf ĩf = ì */
    sim_telex_keymap[0x0069][GDK_KEY_f] = sim_telex_keymap[0x0069][GDK_KEY_F] =
    sim_telex_keymap[0x1ECB][GDK_KEY_f] = sim_telex_keymap[0x1ECB][GDK_KEY_F] =
    sim_telex_keymap[0x1EC9][GDK_KEY_f] = sim_telex_keymap[0x1EC9][GDK_KEY_F] =
    sim_telex_keymap[0x00ED][GDK_KEY_f] = sim_telex_keymap[0x00ED][GDK_KEY_F] =
    sim_telex_keymap[0x0129][GDK_KEY_f] = sim_telex_keymap[0x0129][GDK_KEY_F] = 0x00EC;

    /* ij ìj ỉj íj ĩj = ị */
    sim_telex_keymap[0x0069][GDK_KEY_j] = sim_telex_keymap[0x0069][GDK_KEY_J] =
    sim_telex_keymap[0x00EC][GDK_KEY_j] = sim_telex_keymap[0x00EC][GDK_KEY_J] =
    sim_telex_keymap[0x1EC9][GDK_KEY_j] = sim_telex_keymap[0x1EC9][GDK_KEY_J] =
    sim_telex_keymap[0x00ED][GDK_KEY_j] = sim_telex_keymap[0x00ED][GDK_KEY_J] =
    sim_telex_keymap[0x0129][GDK_KEY_j] = sim_telex_keymap[0x0129][GDK_KEY_J] = 0x1ECB;

    /* ir ìr ịr ír ĩr = ỉ */
    sim_telex_keymap[0x0069][GDK_KEY_r] = sim_telex_keymap[0x0069][GDK_KEY_R] =
    sim_telex_keymap[0x00EC][GDK_KEY_r] = sim_telex_keymap[0x00EC][GDK_KEY_R] =
    sim_telex_keymap[0x1ECB][GDK_KEY_r] = sim_telex_keymap[0x1ECB][GDK_KEY_R] =
    sim_telex_keymap[0x00ED][GDK_KEY_r] = sim_telex_keymap[0x00ED][GDK_KEY_R] =
    sim_telex_keymap[0x0129][GDK_KEY_r] = sim_telex_keymap[0x0129][GDK_KEY_R] = 0x1EC9;

    /* is ìs ịs ỉs ĩs = í */
    sim_telex_keymap[0x0069][GDK_KEY_s] = sim_telex_keymap[0x0069][GDK_KEY_S] =
    sim_telex_keymap[0x00EC][GDK_KEY_s] = sim_telex_keymap[0x00EC][GDK_KEY_S] =
    sim_telex_keymap[0x1ECB][GDK_KEY_s] = sim_telex_keymap[0x1ECB][GDK_KEY_S] =
    sim_telex_keymap[0x1EC9][GDK_KEY_s] = sim_telex_keymap[0x1EC9][GDK_KEY_S] =
    sim_telex_keymap[0x0129][GDK_KEY_s] = sim_telex_keymap[0x0129][GDK_KEY_S] = 0x00ED;

    /* ix ìx ịx ỉx ĩx = í */
    sim_telex_keymap[0x0069][GDK_KEY_x] = sim_telex_keymap[0x0069][GDK_KEY_X] =
    sim_telex_keymap[0x00EC][GDK_KEY_x] = sim_telex_keymap[0x00EC][GDK_KEY_X] =
    sim_telex_keymap[0x1ECB][GDK_KEY_x] = sim_telex_keymap[0x1ECB][GDK_KEY_X] =
    sim_telex_keymap[0x1EC9][GDK_KEY_x] = sim_telex_keymap[0x1EC9][GDK_KEY_X] =
    sim_telex_keymap[0x00ED][GDK_KEY_x] = sim_telex_keymap[0x00ED][GDK_KEY_X] = 0x0129;

    /**
     * Block
     * o(0x006F) ò(0x00F2) ọ(0x1ECD) ỏ(0x1ECF) ó(0x00F3) õ(0x00F5)
     */
    /* of ọf ỏf óf õf = ò */
    sim_telex_keymap[0x006F][GDK_KEY_f] = sim_telex_keymap[0x006F][GDK_KEY_F] =
    sim_telex_keymap[0x1ECD][GDK_KEY_f] = sim_telex_keymap[0x1ECD][GDK_KEY_F] =
    sim_telex_keymap[0x1ECF][GDK_KEY_f] = sim_telex_keymap[0x1ECF][GDK_KEY_F] =
    sim_telex_keymap[0x00F3][GDK_KEY_f] = sim_telex_keymap[0x00F3][GDK_KEY_F] =
    sim_telex_keymap[0x00F5][GDK_KEY_f] = sim_telex_keymap[0x00F5][GDK_KEY_F] = 0x00F2;

    /* oj òj ỏj ój õj = ọ */
    sim_telex_keymap[0x006F][GDK_KEY_j] = sim_telex_keymap[0x006F][GDK_KEY_J] =
    sim_telex_keymap[0x00F2][GDK_KEY_j] = sim_telex_keymap[0x00F2][GDK_KEY_J] =
    sim_telex_keymap[0x1ECF][GDK_KEY_j] = sim_telex_keymap[0x1ECF][GDK_KEY_J] =
    sim_telex_keymap[0x00F3][GDK_KEY_j] = sim_telex_keymap[0x00F3][GDK_KEY_J] =
    sim_telex_keymap[0x00F5][GDK_KEY_j] = sim_telex_keymap[0x00F5][GDK_KEY_J] = 0x1ECD;

    /* or òr ọr ór õr = ỏ */
    sim_telex_keymap[0x006F][GDK_KEY_r] = sim_telex_keymap[0x006F][GDK_KEY_R] =
    sim_telex_keymap[0x00F2][GDK_KEY_r] = sim_telex_keymap[0x00F2][GDK_KEY_R] =
    sim_telex_keymap[0x1ECD][GDK_KEY_r] = sim_telex_keymap[0x1ECD][GDK_KEY_R] =
    sim_telex_keymap[0x00F3][GDK_KEY_r] = sim_telex_keymap[0x00F3][GDK_KEY_R] =
    sim_telex_keymap[0x00F5][GDK_KEY_r] = sim_telex_keymap[0x00F5][GDK_KEY_R] = 0x1ECF;

    /* os òs ọs ỏs õs = ó */
    sim_telex_keymap[0x006F][GDK_KEY_s] = sim_telex_keymap[0x006F][GDK_KEY_S] =
    sim_telex_keymap[0x00F2][GDK_KEY_s] = sim_telex_keymap[0x00F2][GDK_KEY_S] =
    sim_telex_keymap[0x1ECD][GDK_KEY_s] = sim_telex_keymap[0x1ECD][GDK_KEY_S] =
    sim_telex_keymap[0x1ECF][GDK_KEY_s] = sim_telex_keymap[0x1ECF][GDK_KEY_S] =
    sim_telex_keymap[0x00F5][GDK_KEY_s] = sim_telex_keymap[0x00F5][GDK_KEY_S] = 0x00F3;

    /* ox òx ọx ỏx óx = õ */
    sim_telex_keymap[0x006F][GDK_KEY_x] = sim_telex_keymap[0x006F][GDK_KEY_X] =
    sim_telex_keymap[0x00F2][GDK_KEY_x] = sim_telex_keymap[0x00F2][GDK_KEY_X] =
    sim_telex_keymap[0x1ECD][GDK_KEY_x] = sim_telex_keymap[0x1ECD][GDK_KEY_X] =
    sim_telex_keymap[0x1ECF][GDK_KEY_x] = sim_telex_keymap[0x1ECF][GDK_KEY_X] =
    sim_telex_keymap[0x00F3][GDK_KEY_x] = sim_telex_keymap[0x00F3][GDK_KEY_X] = 0x00F5;

    /**
     * Block
     * ơ(0x01A1) ờ(0x1EDD) ợ(0x1EE3) ở(0x1EDF) ớ(0x1EDB) ỡ(0x1EE1)
     * o(0x006F) ò(0x00F2) ọ(0x1ECD) ỏ(0x1ECF) ó(0x00F3) õ(0x00F5) (for reference)
     * ô(0x00F4) ồ(0x1ED3) ộ(0x1ED9) ổ(0x1ED5) ố(0x1ED1) ỗ(0x1ED7) (for reference)
     */
    /* ow ôw = ơ */
    sim_telex_keymap[0x006F][GDK_KEY_w] = sim_telex_keymap[0x006F][GDK_KEY_W] =
    sim_telex_keymap[0x00F4][GDK_KEY_w] = sim_telex_keymap[0x00F4][GDK_KEY_W] = 0x01A1;

    /* ơf ợf ởf ớf ỡf òw ồw = ờ */
    sim_telex_keymap[0x01A1][GDK_KEY_f] = sim_telex_keymap[0x01A1][GDK_KEY_F] =
    sim_telex_keymap[0x1EE3][GDK_KEY_f] = sim_telex_keymap[0x1EE3][GDK_KEY_F] =
    sim_telex_keymap[0x1EDF][GDK_KEY_f] = sim_telex_keymap[0x1EDF][GDK_KEY_F] =
    sim_telex_keymap[0x1EDB][GDK_KEY_f] = sim_telex_keymap[0x1EDB][GDK_KEY_F] =
    sim_telex_keymap[0x1EE1][GDK_KEY_f] = sim_telex_keymap[0x1EE1][GDK_KEY_F] =
    sim_telex_keymap[0x00F2][GDK_KEY_w] = sim_telex_keymap[0x00F2][GDK_KEY_W] =
    sim_telex_keymap[0x1ED3][GDK_KEY_w] = sim_telex_keymap[0x1ED3][GDK_KEY_W] = 0x1EDD;

    /* ơj ờj ởj ớj ỡj ọw ộw = ợ */
    sim_telex_keymap[0x01A1][GDK_KEY_j] = sim_telex_keymap[0x01A1][GDK_KEY_J] =
    sim_telex_keymap[0x1EDD][GDK_KEY_j] = sim_telex_keymap[0x1EDD][GDK_KEY_J] =
    sim_telex_keymap[0x1EDF][GDK_KEY_j] = sim_telex_keymap[0x1EDF][GDK_KEY_J] =
    sim_telex_keymap[0x1EDB][GDK_KEY_j] = sim_telex_keymap[0x1EDB][GDK_KEY_J] =
    sim_telex_keymap[0x1EE1][GDK_KEY_j] = sim_telex_keymap[0x1EE1][GDK_KEY_J] =
    sim_telex_keymap[0x1ECD][GDK_KEY_w] = sim_telex_keymap[0x1ECD][GDK_KEY_W] =
    sim_telex_keymap[0x1ED9][GDK_KEY_w] = sim_telex_keymap[0x1ED9][GDK_KEY_W] = 0x1EE3;

    /* ơr ờr ợr ớr ỡr ỏw ổw = ở */
    sim_telex_keymap[0x01A1][GDK_KEY_r] = sim_telex_keymap[0x01A1][GDK_KEY_R] =
    sim_telex_keymap[0x1EDD][GDK_KEY_r] = sim_telex_keymap[0x1EDD][GDK_KEY_R] =
    sim_telex_keymap[0x1EE3][GDK_KEY_r] = sim_telex_keymap[0x1EE3][GDK_KEY_R] =
    sim_telex_keymap[0x1EDB][GDK_KEY_r] = sim_telex_keymap[0x1EDB][GDK_KEY_R] =
    sim_telex_keymap[0x1EE1][GDK_KEY_r] = sim_telex_keymap[0x1EE1][GDK_KEY_R] =
    sim_telex_keymap[0x1ECF][GDK_KEY_w] = sim_telex_keymap[0x1ECF][GDK_KEY_W] =
    sim_telex_keymap[0x1ED5][GDK_KEY_w] = sim_telex_keymap[0x1ED5][GDK_KEY_W] = 0x1EDF;

    /* ơs ờs ợs ởs ỡs ów ốw = ớ */
    sim_telex_keymap[0x01A1][GDK_KEY_s] = sim_telex_keymap[0x01A1][GDK_KEY_S] =
    sim_telex_keymap[0x1EDD][GDK_KEY_s] = sim_telex_keymap[0x1EDD][GDK_KEY_S] =
    sim_telex_keymap[0x1EE3][GDK_KEY_s] = sim_telex_keymap[0x1EE3][GDK_KEY_S] =
    sim_telex_keymap[0x1EDF][GDK_KEY_s] = sim_telex_keymap[0x1EDF][GDK_KEY_S] =
    sim_telex_keymap[0x1EE1][GDK_KEY_s] = sim_telex_keymap[0x1EE1][GDK_KEY_S] =
    sim_telex_keymap[0x00F3][GDK_KEY_w] = sim_telex_keymap[0x00F3][GDK_KEY_W] =
    sim_telex_keymap[0x1ED1][GDK_KEY_w] = sim_telex_keymap[0x1ED1][GDK_KEY_W] =  0x1EDB;

    /* ơx ờx ợx ởx ớx õw ỗw = ỡ */
    sim_telex_keymap[0x01A1][GDK_KEY_x] = sim_telex_keymap[0x01A1][GDK_KEY_X] =
    sim_telex_keymap[0x1EDD][GDK_KEY_x] = sim_telex_keymap[0x1EDD][GDK_KEY_X] =
    sim_telex_keymap[0x1EE3][GDK_KEY_x] = sim_telex_keymap[0x1EE3][GDK_KEY_X] =
    sim_telex_keymap[0x1EDF][GDK_KEY_x] = sim_telex_keymap[0x1EDF][GDK_KEY_X] =
    sim_telex_keymap[0x1EDB][GDK_KEY_x] = sim_telex_keymap[0x1EDB][GDK_KEY_X] =
    sim_telex_keymap[0x00F5][GDK_KEY_w] = sim_telex_keymap[0x00F5][GDK_KEY_W] =
    sim_telex_keymap[0x1ED7][GDK_KEY_w] = sim_telex_keymap[0x1ED7][GDK_KEY_W] = 0x1EE1;

    /**
     * Block
     * ô(0x00F4) ồ(0x1ED3) ộ(0x1ED9) ổ(0x1ED5) ố(0x1ED1) ỗ(0x1ED7)
     * o(0x006F) ò(0x00F2) ọ(0x1ECD) ỏ(0x1ECF) ó(0x00F3) õ(0x00F5) (for reference)
     * ơ(0x01A1) ờ(0x1EDD) ợ(0x1EE3) ở(0x1EDF) ớ(0x1EDB) ỡ(0x1EE1) (for reference)
     */
    /* oo ơo = ô */
    sim_telex_keymap[0x006F][GDK_KEY_o] = sim_telex_keymap[0x006F][GDK_KEY_O] =
    sim_telex_keymap[0x01A1][GDK_KEY_o] = sim_telex_keymap[0x01A1][GDK_KEY_O] = 0x00F4;

    /* ôf ộf ổf ốf ỗf òo ờo = ồ */
    sim_telex_keymap[0x00F4][GDK_KEY_f] = sim_telex_keymap[0x00F4][GDK_KEY_F] =
    sim_telex_keymap[0x1ED9][GDK_KEY_f] = sim_telex_keymap[0x1ED9][GDK_KEY_F] =
    sim_telex_keymap[0x1ED5][GDK_KEY_f] = sim_telex_keymap[0x1ED5][GDK_KEY_F] =
    sim_telex_keymap[0x1ED1][GDK_KEY_f] = sim_telex_keymap[0x1ED1][GDK_KEY_F] =
    sim_telex_keymap[0x1ED7][GDK_KEY_f] = sim_telex_keymap[0x1ED7][GDK_KEY_F] =
    sim_telex_keymap[0x00F2][GDK_KEY_o] = sim_telex_keymap[0x00F2][GDK_KEY_O] =
    sim_telex_keymap[0x1EDD][GDK_KEY_o] = sim_telex_keymap[0x1EDD][GDK_KEY_O] = 0x1ED3;

    /* ôj ồj ổj ốj ỗj ọo ợo = ộ */
    sim_telex_keymap[0x00F4][GDK_KEY_j] = sim_telex_keymap[0x00F4][GDK_KEY_J] =
    sim_telex_keymap[0x1ED3][GDK_KEY_j] = sim_telex_keymap[0x1ED3][GDK_KEY_J] =
    sim_telex_keymap[0x1ED5][GDK_KEY_j] = sim_telex_keymap[0x1ED5][GDK_KEY_J] =
    sim_telex_keymap[0x1ED1][GDK_KEY_j] = sim_telex_keymap[0x1ED1][GDK_KEY_J] =
    sim_telex_keymap[0x1ED7][GDK_KEY_j] = sim_telex_keymap[0x1ED7][GDK_KEY_J] =
    sim_telex_keymap[0x1ECD][GDK_KEY_o] = sim_telex_keymap[0x1ECD][GDK_KEY_O] =
    sim_telex_keymap[0x1EE3][GDK_KEY_o] = sim_telex_keymap[0x1EE3][GDK_KEY_O] = 0x1ED9;

    /* ôr ồr ộr ốr ỗr ỏo ởo = ổ */
    sim_telex_keymap[0x00F4][GDK_KEY_r] = sim_telex_keymap[0x00F4][GDK_KEY_R] =
    sim_telex_keymap[0x1ED3][GDK_KEY_r] = sim_telex_keymap[0x1ED3][GDK_KEY_R] =
    sim_telex_keymap[0x1ED9][GDK_KEY_r] = sim_telex_keymap[0x1ED9][GDK_KEY_R] =
    sim_telex_keymap[0x1ED1][GDK_KEY_r] = sim_telex_keymap[0x1ED1][GDK_KEY_R] =
    sim_telex_keymap[0x1ED7][GDK_KEY_r] = sim_telex_keymap[0x1ED7][GDK_KEY_R] =
    sim_telex_keymap[0x1ECF][GDK_KEY_o] = sim_telex_keymap[0x1ECF][GDK_KEY_O] =
    sim_telex_keymap[0x1EDF][GDK_KEY_o] = sim_telex_keymap[0x1EDF][GDK_KEY_O] = 0x1ED5;

    /* ôs ồs ộs ổs ỗs óo ớo = ố */
    sim_telex_keymap[0x00F4][GDK_KEY_s] = sim_telex_keymap[0x00F4][GDK_KEY_S] =
    sim_telex_keymap[0x1ED3][GDK_KEY_s] = sim_telex_keymap[0x1ED3][GDK_KEY_S] =
    sim_telex_keymap[0x1ED9][GDK_KEY_s] = sim_telex_keymap[0x1ED9][GDK_KEY_S] =
    sim_telex_keymap[0x1ED5][GDK_KEY_s] = sim_telex_keymap[0x1ED5][GDK_KEY_S] =
    sim_telex_keymap[0x1ED7][GDK_KEY_s] = sim_telex_keymap[0x1ED7][GDK_KEY_S] =
    sim_telex_keymap[0x00F3][GDK_KEY_o] = sim_telex_keymap[0x00F3][GDK_KEY_O] =
    sim_telex_keymap[0x1EDB][GDK_KEY_o] = sim_telex_keymap[0x1EDB][GDK_KEY_O] = 0x1ED1;

    /* ôx ồx ộx ổx ốx õo ỡo = ỗ */
    sim_telex_keymap[0x00F4][GDK_KEY_x] = sim_telex_keymap[0x00F4][GDK_KEY_X] =
    sim_telex_keymap[0x1ED3][GDK_KEY_x] = sim_telex_keymap[0x1ED3][GDK_KEY_X] =
    sim_telex_keymap[0x1ED9][GDK_KEY_x] = sim_telex_keymap[0x1ED9][GDK_KEY_X] =
    sim_telex_keymap[0x1ED5][GDK_KEY_x] = sim_telex_keymap[0x1ED5][GDK_KEY_X] =
    sim_telex_keymap[0x1ED1][GDK_KEY_x] = sim_telex_keymap[0x1ED1][GDK_KEY_X] =
    sim_telex_keymap[0x00F5][GDK_KEY_o] = sim_telex_keymap[0x00F5][GDK_KEY_O] =
    sim_telex_keymap[0x1EE1][GDK_KEY_o] = sim_telex_keymap[0x1EE1][GDK_KEY_O] = 0x1ED7;

    /**
     * Block
     * u(0x0075) ù(0x00F9) ụ(0x1EE5) ủ(0x1EE7) ú(0x00FA) ũ(0x0169)
     */
    /* uf ụf ủf úf ũf = ù */
    sim_telex_keymap[0x0075][GDK_KEY_f] = sim_telex_keymap[0x0075][GDK_KEY_F] =
    sim_telex_keymap[0x1EE5][GDK_KEY_f] = sim_telex_keymap[0x1EE5][GDK_KEY_F] =
    sim_telex_keymap[0x1EE7][GDK_KEY_f] = sim_telex_keymap[0x1EE7][GDK_KEY_F] =
    sim_telex_keymap[0x00FA][GDK_KEY_f] = sim_telex_keymap[0x00FA][GDK_KEY_F] =
    sim_telex_keymap[0x0169][GDK_KEY_f] = sim_telex_keymap[0x0169][GDK_KEY_F] = 0x00F9;

    /* uj ùj ủj új ũj = ụ */
    sim_telex_keymap[0x0075][GDK_KEY_j] = sim_telex_keymap[0x0075][GDK_KEY_J] =
    sim_telex_keymap[0x00F9][GDK_KEY_j] = sim_telex_keymap[0x00F9][GDK_KEY_J] =
    sim_telex_keymap[0x1EE7][GDK_KEY_j] = sim_telex_keymap[0x1EE7][GDK_KEY_J] =
    sim_telex_keymap[0x00FA][GDK_KEY_j] = sim_telex_keymap[0x00FA][GDK_KEY_J] =
    sim_telex_keymap[0x0169][GDK_KEY_j] = sim_telex_keymap[0x0169][GDK_KEY_J] = 0x1EE5;

    /* ur ùr ụr úr ũr = ủ */
    sim_telex_keymap[0x0075][GDK_KEY_r] = sim_telex_keymap[0x0075][GDK_KEY_R] =
    sim_telex_keymap[0x00F9][GDK_KEY_r] = sim_telex_keymap[0x00F9][GDK_KEY_R] =
    sim_telex_keymap[0x1EE5][GDK_KEY_r] = sim_telex_keymap[0x1EE5][GDK_KEY_R] =
    sim_telex_keymap[0x00FA][GDK_KEY_r] = sim_telex_keymap[0x00FA][GDK_KEY_R] =
    sim_telex_keymap[0x0169][GDK_KEY_r] = sim_telex_keymap[0x0169][GDK_KEY_R] = 0x1EE7;

    /* us ùs ụs ủs ũs = ú */
    sim_telex_keymap[0x0075][GDK_KEY_s] = sim_telex_keymap[0x0075][GDK_KEY_S] =
    sim_telex_keymap[0x00F9][GDK_KEY_s] = sim_telex_keymap[0x00F9][GDK_KEY_S] =
    sim_telex_keymap[0x1EE5][GDK_KEY_s] = sim_telex_keymap[0x1EE5][GDK_KEY_S] =
    sim_telex_keymap[0x1EE7][GDK_KEY_s] = sim_telex_keymap[0x1EE7][GDK_KEY_S] =
    sim_telex_keymap[0x0169][GDK_KEY_s] = sim_telex_keymap[0x0169][GDK_KEY_S] = 0x00FA;

    /* ux ùx ụx ủx úx = ũ */
    sim_telex_keymap[0x0075][GDK_KEY_x] = sim_telex_keymap[0x0075][GDK_KEY_X] =
    sim_telex_keymap[0x00F9][GDK_KEY_x] = sim_telex_keymap[0x00F9][GDK_KEY_X] =
    sim_telex_keymap[0x1EE5][GDK_KEY_x] = sim_telex_keymap[0x1EE5][GDK_KEY_X] =
    sim_telex_keymap[0x1EE7][GDK_KEY_x] = sim_telex_keymap[0x1EE7][GDK_KEY_X] =
    sim_telex_keymap[0x00FA][GDK_KEY_x] = sim_telex_keymap[0x00FA][GDK_KEY_X] = 0x0169;


    /**
     * Block
     * ư(0x01B0) ừ(0x1EEB) ự(0x1EF1) ử(0x1EED) ứ(0x1EE9) ữ(0x1EEF)
     * u(0x0075) ù(0x00F9) ụ(0x1EE5) ủ(0x1EE7) ú(0x00FA) ũ(0x0169) (for reference)
     */
    /* uw = ư */
    sim_telex_keymap[0x0075][GDK_KEY_w] = sim_telex_keymap[0x0075][GDK_KEY_W] = 0x01B0;

    /* ưf ựf ửf ứf ữf ùw = ừ */
    sim_telex_keymap[0x01B0][GDK_KEY_f] = sim_telex_keymap[0x01B0][GDK_KEY_F] =
    sim_telex_keymap[0x1EF1][GDK_KEY_f] = sim_telex_keymap[0x1EF1][GDK_KEY_F] =
    sim_telex_keymap[0x1EED][GDK_KEY_f] = sim_telex_keymap[0x1EED][GDK_KEY_F] =
    sim_telex_keymap[0x1EE9][GDK_KEY_f] = sim_telex_keymap[0x1EE9][GDK_KEY_F] =
    sim_telex_keymap[0x1EEF][GDK_KEY_f] = sim_telex_keymap[0x1EEF][GDK_KEY_F] =
    sim_telex_keymap[0x00F9][GDK_KEY_w] = sim_telex_keymap[0x00F9][GDK_KEY_W] = 0x1EEB;

    /* ưj ừj ửj ứj ữj ụw = ự */
    sim_telex_keymap[0x01B0][GDK_KEY_j] = sim_telex_keymap[0x01B0][GDK_KEY_J] =
    sim_telex_keymap[0x1EEB][GDK_KEY_j] = sim_telex_keymap[0x1EEB][GDK_KEY_J] =
    sim_telex_keymap[0x1EED][GDK_KEY_j] = sim_telex_keymap[0x1EED][GDK_KEY_J] =
    sim_telex_keymap[0x1EE9][GDK_KEY_j] = sim_telex_keymap[0x1EE9][GDK_KEY_J] =
    sim_telex_keymap[0x1EEF][GDK_KEY_j] = sim_telex_keymap[0x1EEF][GDK_KEY_J] =
    sim_telex_keymap[0x1EE5][GDK_KEY_w] = sim_telex_keymap[0x1EE5][GDK_KEY_W] = 0x1EF1;

    /* ưr ừr ựr ứr ữr ủw = ử */
    sim_telex_keymap[0x01B0][GDK_KEY_r] = sim_telex_keymap[0x01B0][GDK_KEY_R] =
    sim_telex_keymap[0x1EEB][GDK_KEY_r] = sim_telex_keymap[0x1EEB][GDK_KEY_R] =
    sim_telex_keymap[0x1EF1][GDK_KEY_r] = sim_telex_keymap[0x1EF1][GDK_KEY_R] =
    sim_telex_keymap[0x1EE9][GDK_KEY_r] = sim_telex_keymap[0x1EE9][GDK_KEY_R] =
    sim_telex_keymap[0x1EEF][GDK_KEY_r] = sim_telex_keymap[0x1EEF][GDK_KEY_R] =
    sim_telex_keymap[0x1EE7][GDK_KEY_w] = sim_telex_keymap[0x1EE7][GDK_KEY_W] = 0x1EED;

    /* ưs ừs ựs ửs ữs úw = ứ */
    sim_telex_keymap[0x01B0][GDK_KEY_s] = sim_telex_keymap[0x01B0][GDK_KEY_S] =
    sim_telex_keymap[0x1EEB][GDK_KEY_s] = sim_telex_keymap[0x1EEB][GDK_KEY_S] =
    sim_telex_keymap[0x1EF1][GDK_KEY_s] = sim_telex_keymap[0x1EF1][GDK_KEY_S] =
    sim_telex_keymap[0x1EED][GDK_KEY_s] = sim_telex_keymap[0x1EED][GDK_KEY_S] =
    sim_telex_keymap[0x1EEF][GDK_KEY_s] = sim_telex_keymap[0x1EEF][GDK_KEY_S] =
    sim_telex_keymap[0x00FA][GDK_KEY_w] = sim_telex_keymap[0x00FA][GDK_KEY_W] = 0x1EE9;


    /* ưx ừx ựx ửx ứx ũw = ữ */
    sim_telex_keymap[0x01B0][GDK_KEY_x] = sim_telex_keymap[0x01B0][GDK_KEY_X] =
    sim_telex_keymap[0x1EEB][GDK_KEY_x] = sim_telex_keymap[0x1EEB][GDK_KEY_X] =
    sim_telex_keymap[0x1EF1][GDK_KEY_x] = sim_telex_keymap[0x1EF1][GDK_KEY_X] =
    sim_telex_keymap[0x1EED][GDK_KEY_x] = sim_telex_keymap[0x1EED][GDK_KEY_X] =
    sim_telex_keymap[0x1EE9][GDK_KEY_x] = sim_telex_keymap[0x1EE9][GDK_KEY_X] =
    sim_telex_keymap[0x0169][GDK_KEY_w] = sim_telex_keymap[0x0169][GDK_KEY_W] = 0x1EEF;

    /**
     * Block
     * y(0x0079) ỳ(0x1EF3) ỵ(0x1EF5) ỷ(0x1EF7) ý(0x00FD) ỹ(0x1EF9)
     */
    /* yf ỵf ỷf ýf ỹf = ỳ */
    sim_telex_keymap[0x0079][GDK_KEY_f] = sim_telex_keymap[0x0079][GDK_KEY_F] =
    sim_telex_keymap[0x1EF5][GDK_KEY_f] = sim_telex_keymap[0x1EF5][GDK_KEY_F] =
    sim_telex_keymap[0x1EF7][GDK_KEY_f] = sim_telex_keymap[0x1EF7][GDK_KEY_F] =
    sim_telex_keymap[0x00FD][GDK_KEY_f] = sim_telex_keymap[0x00FD][GDK_KEY_F] =
    sim_telex_keymap[0x1EF9][GDK_KEY_f] = sim_telex_keymap[0x1EF9][GDK_KEY_F] = 0x1EF3;

    /* yj ỳj ỷj ýj ỹj = ỵ */
    sim_telex_keymap[0x0079][GDK_KEY_j] = sim_telex_keymap[0x0079][GDK_KEY_J] =
    sim_telex_keymap[0x1EF3][GDK_KEY_j] = sim_telex_keymap[0x1EF3][GDK_KEY_J] =
    sim_telex_keymap[0x1EF7][GDK_KEY_j] = sim_telex_keymap[0x1EF7][GDK_KEY_J] =
    sim_telex_keymap[0x00FD][GDK_KEY_j] = sim_telex_keymap[0x00FD][GDK_KEY_J] =
    sim_telex_keymap[0x1EF9][GDK_KEY_j] = sim_telex_keymap[0x1EF9][GDK_KEY_J] = 0x1EF5;

    /* yr ỳr ỵr ýr ỹr = ỷ */
    sim_telex_keymap[0x0079][GDK_KEY_r] = sim_telex_keymap[0x0079][GDK_KEY_R] =
    sim_telex_keymap[0x1EF3][GDK_KEY_r] = sim_telex_keymap[0x1EF3][GDK_KEY_R] =
    sim_telex_keymap[0x1EF5][GDK_KEY_r] = sim_telex_keymap[0x1EF5][GDK_KEY_R] =
    sim_telex_keymap[0x00FD][GDK_KEY_r] = sim_telex_keymap[0x00FD][GDK_KEY_R] =
    sim_telex_keymap[0x1EF9][GDK_KEY_r] = sim_telex_keymap[0x1EF9][GDK_KEY_R] = 0x1EF7;

    /* ys ỳs ỵs ỷs ỹs = ý */
    sim_telex_keymap[0x0079][GDK_KEY_s] = sim_telex_keymap[0x0079][GDK_KEY_S] =
    sim_telex_keymap[0x1EF3][GDK_KEY_s] = sim_telex_keymap[0x1EF3][GDK_KEY_S] =
    sim_telex_keymap[0x1EF5][GDK_KEY_s] = sim_telex_keymap[0x1EF5][GDK_KEY_S] =
    sim_telex_keymap[0x1EF7][GDK_KEY_s] = sim_telex_keymap[0x1EF7][GDK_KEY_S] =
    sim_telex_keymap[0x1EF9][GDK_KEY_s] = sim_telex_keymap[0x1EF9][GDK_KEY_S] = 0x00FD;

    /* yx ỳx ỵx ỷx ýx = ỹ */
    sim_telex_keymap[0x0079][GDK_KEY_x] = sim_telex_keymap[0x0079][GDK_KEY_X] =
    sim_telex_keymap[0x1EF3][GDK_KEY_x] = sim_telex_keymap[0x1EF3][GDK_KEY_X] =
    sim_telex_keymap[0x1EF5][GDK_KEY_x] = sim_telex_keymap[0x1EF5][GDK_KEY_X] =
    sim_telex_keymap[0x1EF7][GDK_KEY_x] = sim_telex_keymap[0x1EF7][GDK_KEY_X] =
    sim_telex_keymap[0x00FD][GDK_KEY_x] = sim_telex_keymap[0x00FD][GDK_KEY_X] = 0x1EF9;

    /**
     * Block
     * A(0x0041) À(0x00C0) Ạ(0x1EA0) Ả(0x1EA2) Á(0x00C1) Ã(0x00C3)
     */
    /* Af Ạf Ảf Áf Ãf = À */
    sim_telex_keymap[0x0041][GDK_KEY_f] = sim_telex_keymap[0x0041][GDK_KEY_F] =
    sim_telex_keymap[0x1EA0][GDK_KEY_f] = sim_telex_keymap[0x1EA0][GDK_KEY_F] =
    sim_telex_keymap[0x1EA2][GDK_KEY_f] = sim_telex_keymap[0x1EA2][GDK_KEY_F] =
    sim_telex_keymap[0x00C1][GDK_KEY_f] = sim_telex_keymap[0x00C1][GDK_KEY_F] =
    sim_telex_keymap[0x00C3][GDK_KEY_f] = sim_telex_keymap[0x00C3][GDK_KEY_F] = 0x00C0;

    /* Aj Àj Ảj Áj Ãj = Ạ */
    sim_telex_keymap[0x0041][GDK_KEY_j] = sim_telex_keymap[0x0041][GDK_KEY_J] =
    sim_telex_keymap[0x00C0][GDK_KEY_j] = sim_telex_keymap[0x00C0][GDK_KEY_J] =
    sim_telex_keymap[0x1EA2][GDK_KEY_j] = sim_telex_keymap[0x1EA2][GDK_KEY_J] =
    sim_telex_keymap[0x00C1][GDK_KEY_j] = sim_telex_keymap[0x00C1][GDK_KEY_J] =
    sim_telex_keymap[0x00C3][GDK_KEY_j] = sim_telex_keymap[0x00C3][GDK_KEY_J] = 0x1EA0;

    /* Ar Àr Ạr Ár Ãr = Ả */
    sim_telex_keymap[0x0041][GDK_KEY_r] = sim_telex_keymap[0x0041][GDK_KEY_R] =
    sim_telex_keymap[0x00C0][GDK_KEY_r] = sim_telex_keymap[0x00C0][GDK_KEY_R] =
    sim_telex_keymap[0x1EA0][GDK_KEY_r] = sim_telex_keymap[0x1EA0][GDK_KEY_R] =
    sim_telex_keymap[0x00C1][GDK_KEY_r] = sim_telex_keymap[0x00C1][GDK_KEY_R] =
    sim_telex_keymap[0x00C3][GDK_KEY_r] = sim_telex_keymap[0x00C3][GDK_KEY_R] = 0x1EA2;

    /* As Às Ạs Ảs Ãs = Á */
    sim_telex_keymap[0x0041][GDK_KEY_s] = sim_telex_keymap[0x0041][GDK_KEY_S] =
    sim_telex_keymap[0x00C0][GDK_KEY_s] = sim_telex_keymap[0x00C0][GDK_KEY_S] =
    sim_telex_keymap[0x1EA0][GDK_KEY_s] = sim_telex_keymap[0x1EA0][GDK_KEY_S] =
    sim_telex_keymap[0x1EA2][GDK_KEY_s] = sim_telex_keymap[0x1EA2][GDK_KEY_S] =
    sim_telex_keymap[0x00C3][GDK_KEY_s] = sim_telex_keymap[0x00C3][GDK_KEY_S] = 0x00C1;

    /* Ax Àx Ạx Ảx Áx = Ã */
    sim_telex_keymap[0x0041][GDK_KEY_x] = sim_telex_keymap[0x0041][GDK_KEY_X] =
    sim_telex_keymap[0x00C0][GDK_KEY_x] = sim_telex_keymap[0x00C0][GDK_KEY_X] =
    sim_telex_keymap[0x1EA0][GDK_KEY_x] = sim_telex_keymap[0x1EA0][GDK_KEY_X] =
    sim_telex_keymap[0x1EA2][GDK_KEY_x] = sim_telex_keymap[0x1EA2][GDK_KEY_X] =
    sim_telex_keymap[0x00C1][GDK_KEY_x] = sim_telex_keymap[0x00C1][GDK_KEY_X] = 0x00C3;

    /**
     * Block
     * Ă(0x0102) Ằ(0x1EB0) Ặ(0x1EB6) Ẳ(0x1EB2) Ắ(0x1EAE) Ẵ(0x1EB4)
     * A(0x0041) À(0x00C0) Ạ(0x1EA0) Ả(0x1EA2) Á(0x00C1) Ã(0x00C3) (for reference)
     * Â(0x00C2) Ầ(0x1EA6) Ậ(0x1EAC) Ẩ(0x1EA8) Ấ(0x1EA4) Ẫ(0x1EAA) (for reference)
     */
    /* Aw Âw = Ă */
    sim_telex_keymap[0x0041][GDK_KEY_w] = sim_telex_keymap[0x0041][GDK_KEY_W] =
    sim_telex_keymap[0x00C2][GDK_KEY_w] = sim_telex_keymap[0x00C2][GDK_KEY_W] = 0x0102;

    /* Ăf Ặf Ẳf Ắf Ẵf Àw Ầw = Ằ */
    sim_telex_keymap[0x0102][GDK_KEY_f] = sim_telex_keymap[0x0102][GDK_KEY_F] =
    sim_telex_keymap[0x1EB6][GDK_KEY_f] = sim_telex_keymap[0x1EB6][GDK_KEY_F] =
    sim_telex_keymap[0x1EB2][GDK_KEY_f] = sim_telex_keymap[0x1EB2][GDK_KEY_F] =
    sim_telex_keymap[0x1EAE][GDK_KEY_f] = sim_telex_keymap[0x1EAE][GDK_KEY_F] =
    sim_telex_keymap[0x1EB4][GDK_KEY_f] = sim_telex_keymap[0x1EB4][GDK_KEY_F] =
    sim_telex_keymap[0x00C0][GDK_KEY_w] = sim_telex_keymap[0x00C0][GDK_KEY_W] =
    sim_telex_keymap[0x1EA6][GDK_KEY_w] = sim_telex_keymap[0x1EA6][GDK_KEY_W] = 0x1EB0;

    /* Ăj Ằj Ẳj Ắj Ẵj Ạw Ậw = Ặ */
    sim_telex_keymap[0x0102][GDK_KEY_j] = sim_telex_keymap[0x0102][GDK_KEY_J] =
    sim_telex_keymap[0x1EB0][GDK_KEY_j] = sim_telex_keymap[0x1EB0][GDK_KEY_J] =
    sim_telex_keymap[0x1EB2][GDK_KEY_j] = sim_telex_keymap[0x1EB2][GDK_KEY_J] =
    sim_telex_keymap[0x1EAE][GDK_KEY_j] = sim_telex_keymap[0x1EAE][GDK_KEY_J] =
    sim_telex_keymap[0x1EB4][GDK_KEY_j] = sim_telex_keymap[0x1EB4][GDK_KEY_J] =
    sim_telex_keymap[0x1EA0][GDK_KEY_w] = sim_telex_keymap[0x1EA0][GDK_KEY_W] =
    sim_telex_keymap[0x1EAC][GDK_KEY_w] = sim_telex_keymap[0x1EAC][GDK_KEY_W] = 0x1EB6;

    /* Ăr Ằr Ặr Ắr Ẵr Ảw Ẩw = Ẳ */
    sim_telex_keymap[0x0102][GDK_KEY_r] = sim_telex_keymap[0x0102][GDK_KEY_R] =
    sim_telex_keymap[0x1EB0][GDK_KEY_r] = sim_telex_keymap[0x1EB0][GDK_KEY_R] =
    sim_telex_keymap[0x1EB6][GDK_KEY_r] = sim_telex_keymap[0x1EB6][GDK_KEY_R] =
    sim_telex_keymap[0x1EAE][GDK_KEY_r] = sim_telex_keymap[0x1EAE][GDK_KEY_R] =
    sim_telex_keymap[0x1EB4][GDK_KEY_r] = sim_telex_keymap[0x1EB4][GDK_KEY_R] =
    sim_telex_keymap[0x1EA2][GDK_KEY_w] = sim_telex_keymap[0x1EA2][GDK_KEY_W] =
    sim_telex_keymap[0x1EA8][GDK_KEY_w] = sim_telex_keymap[0x1EA8][GDK_KEY_W] = 0x1EB2;

    /* Ăs Ằs Ặs Ẳs Ẵs Áw Ấw = Ắ*/
    sim_telex_keymap[0x0102][GDK_KEY_s] = sim_telex_keymap[0x0102][GDK_KEY_S] =
    sim_telex_keymap[0x1EB0][GDK_KEY_s] = sim_telex_keymap[0x1EB0][GDK_KEY_S] =
    sim_telex_keymap[0x1EB6][GDK_KEY_s] = sim_telex_keymap[0x1EB6][GDK_KEY_S] =
    sim_telex_keymap[0x1EB2][GDK_KEY_s] = sim_telex_keymap[0x1EB2][GDK_KEY_S] =
    sim_telex_keymap[0x1EB4][GDK_KEY_s] = sim_telex_keymap[0x1EB4][GDK_KEY_S] =
    sim_telex_keymap[0x00C1][GDK_KEY_w] = sim_telex_keymap[0x00C1][GDK_KEY_W] =
    sim_telex_keymap[0x1EA4][GDK_KEY_w] = sim_telex_keymap[0x1EA4][GDK_KEY_W] = 0x1EAE;

    /* Ăx Ằx Ặx Ẳx Ắx Ãw Ẫw = Ẵ */
    sim_telex_keymap[0x0102][GDK_KEY_x] = sim_telex_keymap[0x0102][GDK_KEY_X] =
    sim_telex_keymap[0x1EB0][GDK_KEY_x] = sim_telex_keymap[0x1EB0][GDK_KEY_X] =
    sim_telex_keymap[0x1EB6][GDK_KEY_x] = sim_telex_keymap[0x1EB6][GDK_KEY_X] =
    sim_telex_keymap[0x1EB2][GDK_KEY_x] = sim_telex_keymap[0x1EB2][GDK_KEY_X] =
    sim_telex_keymap[0x1EAE][GDK_KEY_x] = sim_telex_keymap[0x1EAE][GDK_KEY_X] =
    sim_telex_keymap[0x00C3][GDK_KEY_w] = sim_telex_keymap[0x00C3][GDK_KEY_W] =
    sim_telex_keymap[0x1EAA][GDK_KEY_w] = sim_telex_keymap[0x1EAA][GDK_KEY_W] = 0x1EB4;

    /**
     * Block
     * Â(0x00C2) Ầ(0x1EA6) Ậ(0x1EAC) Ẩ(0x1EA8) Ấ(0x1EA4) Ẫ(0x1EAA)
     * A(0x0041) À(0x00C0) Ạ(0x1EA0) Ả(0x1EA2) Á(0x00C1) Ã(0x00C3) (for reference)
     * Ă(0x0102) Ằ(0x1EB0) Ặ(0x1EB6) Ẳ(0x1EB2) Ắ(0x1EAE) Ẵ(0x1EB4) (for reference)
     */
    /* Aa Ăa = Â */
    sim_telex_keymap[0x0041][GDK_KEY_a] = sim_telex_keymap[0x0041][GDK_KEY_A] =
    sim_telex_keymap[0x0102][GDK_KEY_a] = sim_telex_keymap[0x0102][GDK_KEY_A] = 0x00C2;

    /* Âf Ậf Ẩf Ấf Ẫf Àa Ằa = Ầ */
    sim_telex_keymap[0x00C2][GDK_KEY_f] = sim_telex_keymap[0x00C2][GDK_KEY_F] =
    sim_telex_keymap[0x1EAC][GDK_KEY_f] = sim_telex_keymap[0x1EAC][GDK_KEY_F] =
    sim_telex_keymap[0x1EA8][GDK_KEY_f] = sim_telex_keymap[0x1EA8][GDK_KEY_F] =
    sim_telex_keymap[0x1EA4][GDK_KEY_f] = sim_telex_keymap[0x1EA4][GDK_KEY_F] =
    sim_telex_keymap[0x1EAA][GDK_KEY_f] = sim_telex_keymap[0x1EAA][GDK_KEY_F] =
    sim_telex_keymap[0x00C0][GDK_KEY_a] = sim_telex_keymap[0x00C0][GDK_KEY_A] =
    sim_telex_keymap[0x1EB0][GDK_KEY_a] = sim_telex_keymap[0x1EB0][GDK_KEY_A] = 0x1EA6;

    /* Âj Ầj Ẩj Ấj Ẫj Ạa Ặa = Ậ */
    sim_telex_keymap[0x00C2][GDK_KEY_j] = sim_telex_keymap[0x00C2][GDK_KEY_J] =
    sim_telex_keymap[0x1EA6][GDK_KEY_j] = sim_telex_keymap[0x1EA6][GDK_KEY_J] =
    sim_telex_keymap[0x1EA8][GDK_KEY_j] = sim_telex_keymap[0x1EA8][GDK_KEY_J] =
    sim_telex_keymap[0x1EA4][GDK_KEY_j] = sim_telex_keymap[0x1EA4][GDK_KEY_J] =
    sim_telex_keymap[0x1EAA][GDK_KEY_j] = sim_telex_keymap[0x1EAA][GDK_KEY_J] =
    sim_telex_keymap[0x1EA0][GDK_KEY_a] = sim_telex_keymap[0x1EA0][GDK_KEY_A] =
    sim_telex_keymap[0x1EB6][GDK_KEY_a] = sim_telex_keymap[0x1EB6][GDK_KEY_A] = 0x1EAC;

    /* Âr Ầr Ậr Ấr Ẫr Ảa Ẳa = Ẩ */
    sim_telex_keymap[0x00C2][GDK_KEY_r] = sim_telex_keymap[0x00C2][GDK_KEY_R] =
    sim_telex_keymap[0x1EA6][GDK_KEY_r] = sim_telex_keymap[0x1EA6][GDK_KEY_R] =
    sim_telex_keymap[0x1EAC][GDK_KEY_r] = sim_telex_keymap[0x1EAC][GDK_KEY_R] =
    sim_telex_keymap[0x1EA4][GDK_KEY_r] = sim_telex_keymap[0x1EA4][GDK_KEY_R] =
    sim_telex_keymap[0x1EAA][GDK_KEY_r] = sim_telex_keymap[0x1EAA][GDK_KEY_R] =
    sim_telex_keymap[0x1EA2][GDK_KEY_a] = sim_telex_keymap[0x1EA2][GDK_KEY_A] =
    sim_telex_keymap[0x1EB2][GDK_KEY_a] = sim_telex_keymap[0x1EB2][GDK_KEY_A] = 0x1EA8;

    /* Âs Ầs Ậs Ẩs Ẫs Ás Ắs = Ấ */
    sim_telex_keymap[0x00C2][GDK_KEY_s] = sim_telex_keymap[0x00C2][GDK_KEY_S] =
    sim_telex_keymap[0x1EA6][GDK_KEY_s] = sim_telex_keymap[0x1EA6][GDK_KEY_S] =
    sim_telex_keymap[0x1EAC][GDK_KEY_s] = sim_telex_keymap[0x1EAC][GDK_KEY_S] =
    sim_telex_keymap[0x1EA8][GDK_KEY_s] = sim_telex_keymap[0x1EA8][GDK_KEY_S] =
    sim_telex_keymap[0x1EAA][GDK_KEY_s] = sim_telex_keymap[0x1EAA][GDK_KEY_S] =
    sim_telex_keymap[0x00C1][GDK_KEY_a] = sim_telex_keymap[0x00C1][GDK_KEY_A] =
    sim_telex_keymap[0x1EAE][GDK_KEY_a] = sim_telex_keymap[0x1EAE][GDK_KEY_A] = 0x1EA4;

    /* Âx Ầx Ậx Ẩx Ấx Ãa Ẵa = Ẫ */
    sim_telex_keymap[0x00C2][GDK_KEY_s] = sim_telex_keymap[0x00C2][GDK_KEY_X] =
    sim_telex_keymap[0x1EA6][GDK_KEY_s] = sim_telex_keymap[0x1EA6][GDK_KEY_X] =
    sim_telex_keymap[0x1EAC][GDK_KEY_s] = sim_telex_keymap[0x1EAC][GDK_KEY_X] =
    sim_telex_keymap[0x1EA8][GDK_KEY_s] = sim_telex_keymap[0x1EA8][GDK_KEY_X] =
    sim_telex_keymap[0x1EA4][GDK_KEY_s] = sim_telex_keymap[0x1EA4][GDK_KEY_X] =
    sim_telex_keymap[0x00C3][GDK_KEY_a] = sim_telex_keymap[0x00C3][GDK_KEY_A] =
    sim_telex_keymap[0x1EB4][GDK_KEY_a] = sim_telex_keymap[0x1EB4][GDK_KEY_A] = 0x1EAA;

    /**
     * Block
     * D(0x0044) Đ(0x0110)
     */
    /* Dd = Đ */
    sim_telex_keymap[0x0044][GDK_KEY_d] = sim_telex_keymap[0x0044][GDK_KEY_D] = 0x0110;

    /**
     * Block
     * E(0x0045) È(0x00C8) Ẹ(0x1EB8) Ẻ(0x1EBA) É(0x00C9) Ẽ(0x1EBC)
     */
    /* Ef Ẹf Ẻf Éf Ẽf = È */
    sim_telex_keymap[0x0045][GDK_KEY_f] = sim_telex_keymap[0x0045][GDK_KEY_F] =
    sim_telex_keymap[0x1EB8][GDK_KEY_f] = sim_telex_keymap[0x1EB8][GDK_KEY_F] =
    sim_telex_keymap[0x1EBA][GDK_KEY_f] = sim_telex_keymap[0x1EBA][GDK_KEY_F] =
    sim_telex_keymap[0x00C9][GDK_KEY_f] = sim_telex_keymap[0x00C9][GDK_KEY_F] =
    sim_telex_keymap[0x1EBC][GDK_KEY_f] = sim_telex_keymap[0x1EBC][GDK_KEY_F] = 0x00C8;

    /* Ej Èj Ẻj Éj Ẽj = Ẹ */
    sim_telex_keymap[0x0045][GDK_KEY_j] = sim_telex_keymap[0x0045][GDK_KEY_J] =
    sim_telex_keymap[0x00C8][GDK_KEY_j] = sim_telex_keymap[0x00C8][GDK_KEY_J] =
    sim_telex_keymap[0x1EBA][GDK_KEY_j] = sim_telex_keymap[0x1EBA][GDK_KEY_J] =
    sim_telex_keymap[0x00C9][GDK_KEY_j] = sim_telex_keymap[0x00C9][GDK_KEY_J] =
    sim_telex_keymap[0x1EBC][GDK_KEY_j] = sim_telex_keymap[0x1EBC][GDK_KEY_J] = 0x1EB8;

    /* Er Èr Ẹr Ér Ẽr = Ẻ */
    sim_telex_keymap[0x0045][GDK_KEY_r] = sim_telex_keymap[0x0045][GDK_KEY_R] =
    sim_telex_keymap[0x00C8][GDK_KEY_r] = sim_telex_keymap[0x00C8][GDK_KEY_R] =
    sim_telex_keymap[0x1EB8][GDK_KEY_r] = sim_telex_keymap[0x1EB8][GDK_KEY_R] =
    sim_telex_keymap[0x00C9][GDK_KEY_r] = sim_telex_keymap[0x00C9][GDK_KEY_R] =
    sim_telex_keymap[0x1EBC][GDK_KEY_r] = sim_telex_keymap[0x1EBC][GDK_KEY_R] = 0x1EBA;

    /* Es Ès Ẹs Ẻs Ẽs = É */
    sim_telex_keymap[0x0045][GDK_KEY_s] = sim_telex_keymap[0x0045][GDK_KEY_S] =
    sim_telex_keymap[0x00C8][GDK_KEY_s] = sim_telex_keymap[0x00C8][GDK_KEY_S] =
    sim_telex_keymap[0x1EB8][GDK_KEY_s] = sim_telex_keymap[0x1EB8][GDK_KEY_S] =
    sim_telex_keymap[0x1EBA][GDK_KEY_s] = sim_telex_keymap[0x1EBA][GDK_KEY_S] =
    sim_telex_keymap[0x1EBC][GDK_KEY_s] = sim_telex_keymap[0x1EBC][GDK_KEY_S] = 0x00C9;

    /* Ex Èx Ẹx Ẻx Éx = Ẽ */
    sim_telex_keymap[0x0045][GDK_KEY_x] = sim_telex_keymap[0x0045][GDK_KEY_X] =
    sim_telex_keymap[0x00C8][GDK_KEY_x] = sim_telex_keymap[0x00C8][GDK_KEY_X] =
    sim_telex_keymap[0x1EB8][GDK_KEY_x] = sim_telex_keymap[0x1EB8][GDK_KEY_X] =
    sim_telex_keymap[0x1EBA][GDK_KEY_x] = sim_telex_keymap[0x1EBA][GDK_KEY_X] =
    sim_telex_keymap[0x00C9][GDK_KEY_x] = sim_telex_keymap[0x00C9][GDK_KEY_X] = 0x1EBC;

    /**
     * Block
     * Ê(0x00CA) Ề(0x1EC0) Ệ(0x1EC6) Ể(0x1EC2) Ế(0x1EBE) Ễ(0x1EC4)
     * E(0x0045) È(0x00C8) Ẹ(0x1EB8) Ẻ(0x1EBA) É(0x00C9) Ẽ(0x1EBC) (for reference)
     */
    /* Ee = Ê */
    sim_telex_keymap[0x0045][GDK_KEY_e] = sim_telex_keymap[0x0045][GDK_KEY_E] = 0x00CA;

    /* Êf Ệf Ểf Ếf Ễf Èe = Ề */
    sim_telex_keymap[0x00CA][GDK_KEY_f] = sim_telex_keymap[0x00CA][GDK_KEY_F] =
    sim_telex_keymap[0x1EC6][GDK_KEY_f] = sim_telex_keymap[0x1EC6][GDK_KEY_F] =
    sim_telex_keymap[0x1EC2][GDK_KEY_f] = sim_telex_keymap[0x1EC2][GDK_KEY_F] =
    sim_telex_keymap[0x1EBE][GDK_KEY_f] = sim_telex_keymap[0x1EBE][GDK_KEY_F] =
    sim_telex_keymap[0x1EC4][GDK_KEY_f] = sim_telex_keymap[0x1EC4][GDK_KEY_F] =
    sim_telex_keymap[0x00C8][GDK_KEY_e] = sim_telex_keymap[0x00C8][GDK_KEY_E] = 0x1EC0;

    /* Êj Ềj Ểj Ếj Ễj Ẹe = Ệ */
    sim_telex_keymap[0x00CA][GDK_KEY_j] = sim_telex_keymap[0x00CA][GDK_KEY_J] =
    sim_telex_keymap[0x1EC0][GDK_KEY_j] = sim_telex_keymap[0x1EC0][GDK_KEY_J] =
    sim_telex_keymap[0x1EC2][GDK_KEY_j] = sim_telex_keymap[0x1EC2][GDK_KEY_J] =
    sim_telex_keymap[0x1EBE][GDK_KEY_j] = sim_telex_keymap[0x1EBE][GDK_KEY_J] =
    sim_telex_keymap[0x1EC4][GDK_KEY_j] = sim_telex_keymap[0x1EC4][GDK_KEY_J] =
    sim_telex_keymap[0x1EB8][GDK_KEY_e] = sim_telex_keymap[0x1EB8][GDK_KEY_E] = 0x1EC6;

    /* Êr Ềr Ệr Ếr Ễr Ẻe = Ể */
    sim_telex_keymap[0x00CA][GDK_KEY_r] = sim_telex_keymap[0x00CA][GDK_KEY_R] =
    sim_telex_keymap[0x1EC0][GDK_KEY_r] = sim_telex_keymap[0x1EC0][GDK_KEY_R] =
    sim_telex_keymap[0x1EC6][GDK_KEY_r] = sim_telex_keymap[0x1EC6][GDK_KEY_R] =
    sim_telex_keymap[0x1EBE][GDK_KEY_r] = sim_telex_keymap[0x1EBE][GDK_KEY_R] =
    sim_telex_keymap[0x1EC4][GDK_KEY_r] = sim_telex_keymap[0x1EC4][GDK_KEY_R] =
    sim_telex_keymap[0x1EBA][GDK_KEY_e] = sim_telex_keymap[0x1EBA][GDK_KEY_E] = 0x1EC2;

    /* Ês Ềs Ệs Ểs Ễs Ée = Ế */
    sim_telex_keymap[0x00CA][GDK_KEY_s] = sim_telex_keymap[0x00CA][GDK_KEY_S] =
    sim_telex_keymap[0x1EC0][GDK_KEY_s] = sim_telex_keymap[0x1EC0][GDK_KEY_S] =
    sim_telex_keymap[0x1EC6][GDK_KEY_s] = sim_telex_keymap[0x1EC6][GDK_KEY_S] =
    sim_telex_keymap[0x1EC2][GDK_KEY_s] = sim_telex_keymap[0x1EC2][GDK_KEY_S] =
    sim_telex_keymap[0x1EC4][GDK_KEY_s] = sim_telex_keymap[0x1EC4][GDK_KEY_S] =
    sim_telex_keymap[0x00C9][GDK_KEY_e] = sim_telex_keymap[0x00C9][GDK_KEY_E] = 0x1EBE;

    /* Êx Ềx Ệx Ểx Ếx Ẽe = Ễ */
    sim_telex_keymap[0x00CA][GDK_KEY_x] = sim_telex_keymap[0x00CA][GDK_KEY_X] =
    sim_telex_keymap[0x1EC0][GDK_KEY_x] = sim_telex_keymap[0x1EC0][GDK_KEY_X] =
    sim_telex_keymap[0x1EC6][GDK_KEY_x] = sim_telex_keymap[0x1EC6][GDK_KEY_X] =
    sim_telex_keymap[0x1EC2][GDK_KEY_x] = sim_telex_keymap[0x1EC2][GDK_KEY_X] =
    sim_telex_keymap[0x1EBE][GDK_KEY_x] = sim_telex_keymap[0x1EBE][GDK_KEY_X] =
    sim_telex_keymap[0x1EBC][GDK_KEY_e] = sim_telex_keymap[0x1EBC][GDK_KEY_E] = 0x1EC4;

    /**
     * Block
     * I(0x0049) Ì(0x00CC) Ị(0x1ECA) Ỉ(0x1EC8) Í(0x00CD) Ĩ(0x0128)
     */
    /* If Ịf Ỉf Íf Ĩf = Ì */
    sim_telex_keymap[0x0049][GDK_KEY_f] = sim_telex_keymap[0x0049][GDK_KEY_F] =
    sim_telex_keymap[0x1ECA][GDK_KEY_f] = sim_telex_keymap[0x1ECA][GDK_KEY_F] =
    sim_telex_keymap[0x1EC8][GDK_KEY_f] = sim_telex_keymap[0x1EC8][GDK_KEY_F] =
    sim_telex_keymap[0x00CD][GDK_KEY_f] = sim_telex_keymap[0x00CD][GDK_KEY_F] =
    sim_telex_keymap[0x0128][GDK_KEY_f] = sim_telex_keymap[0x0128][GDK_KEY_F] = 0x00CC;

    /* Ij Ìj Ỉj Íj Ĩj = Ị */
    sim_telex_keymap[0x0049][GDK_KEY_j] = sim_telex_keymap[0x0049][GDK_KEY_J] =
    sim_telex_keymap[0x00CC][GDK_KEY_j] = sim_telex_keymap[0x00CC][GDK_KEY_J] =
    sim_telex_keymap[0x1EC8][GDK_KEY_j] = sim_telex_keymap[0x1EC8][GDK_KEY_J] =
    sim_telex_keymap[0x00CD][GDK_KEY_j] = sim_telex_keymap[0x00CD][GDK_KEY_J] =
    sim_telex_keymap[0x0128][GDK_KEY_j] = sim_telex_keymap[0x0128][GDK_KEY_J] = 0x1ECA;

    /* Ir Ìr Ịr Ír Ĩr = Ỉ */
    sim_telex_keymap[0x0049][GDK_KEY_r] = sim_telex_keymap[0x0049][GDK_KEY_R] =
    sim_telex_keymap[0x00CC][GDK_KEY_r] = sim_telex_keymap[0x00CC][GDK_KEY_R] =
    sim_telex_keymap[0x1ECA][GDK_KEY_r] = sim_telex_keymap[0x1ECA][GDK_KEY_R] =
    sim_telex_keymap[0x00CD][GDK_KEY_r] = sim_telex_keymap[0x00CD][GDK_KEY_R] =
    sim_telex_keymap[0x0128][GDK_KEY_r] = sim_telex_keymap[0x0128][GDK_KEY_R] = 0x1EC8;

    /* Is Ìs Ịs Ỉs Ĩs = Í */
    sim_telex_keymap[0x0049][GDK_KEY_s] = sim_telex_keymap[0x0049][GDK_KEY_S] =
    sim_telex_keymap[0x00CC][GDK_KEY_s] = sim_telex_keymap[0x00CC][GDK_KEY_S] =
    sim_telex_keymap[0x1ECA][GDK_KEY_s] = sim_telex_keymap[0x1ECA][GDK_KEY_S] =
    sim_telex_keymap[0x1EC8][GDK_KEY_s] = sim_telex_keymap[0x1EC8][GDK_KEY_S] =
    sim_telex_keymap[0x0128][GDK_KEY_s] = sim_telex_keymap[0x0128][GDK_KEY_S] = 0x00CD;

    /* Ix Ìx Ịx Ỉx Íx = Ĩ */
    sim_telex_keymap[0x0049][GDK_KEY_x] = sim_telex_keymap[0x0049][GDK_KEY_X] =
    sim_telex_keymap[0x00CC][GDK_KEY_x] = sim_telex_keymap[0x00CC][GDK_KEY_X] =
    sim_telex_keymap[0x1ECA][GDK_KEY_x] = sim_telex_keymap[0x1ECA][GDK_KEY_X] =
    sim_telex_keymap[0x1EC8][GDK_KEY_x] = sim_telex_keymap[0x1EC8][GDK_KEY_X] =
    sim_telex_keymap[0x00CD][GDK_KEY_x] = sim_telex_keymap[0x00CD][GDK_KEY_X] = 0x0128;

    /**
     * Block
     * O(0x004F) Ò(0x00D2) Ọ(0x1ECC) Ỏ(0x1ECE) Ó(0x00D3) Õ(0x00D5)
     */
    /* Of Ọf Ỏf Óf Õf = Ò */
    sim_telex_keymap[0x004F][GDK_KEY_f] = sim_telex_keymap[0x004F][GDK_KEY_F] =
    sim_telex_keymap[0x1ECC][GDK_KEY_f] = sim_telex_keymap[0x1ECC][GDK_KEY_F] =
    sim_telex_keymap[0x1ECE][GDK_KEY_f] = sim_telex_keymap[0x1ECE][GDK_KEY_F] =
    sim_telex_keymap[0x00D3][GDK_KEY_f] = sim_telex_keymap[0x00D3][GDK_KEY_F] =
    sim_telex_keymap[0x00D5][GDK_KEY_f] = sim_telex_keymap[0x00D5][GDK_KEY_F] = 0x00D2;

    /* Oj Òj Ỏj Ój Õj = Ọ */
    sim_telex_keymap[0x004F][GDK_KEY_j] = sim_telex_keymap[0x004F][GDK_KEY_J] =
    sim_telex_keymap[0x00D2][GDK_KEY_j] = sim_telex_keymap[0x00D2][GDK_KEY_J] =
    sim_telex_keymap[0x1ECE][GDK_KEY_j] = sim_telex_keymap[0x1ECE][GDK_KEY_J] =
    sim_telex_keymap[0x00D3][GDK_KEY_j] = sim_telex_keymap[0x00D3][GDK_KEY_J] =
    sim_telex_keymap[0x00D5][GDK_KEY_j] = sim_telex_keymap[0x00D5][GDK_KEY_J] = 0x1ECC;

    /* Or Òr Ọr Ór Õr = Ỏ */
    sim_telex_keymap[0x004F][GDK_KEY_r] = sim_telex_keymap[0x004F][GDK_KEY_R] =
    sim_telex_keymap[0x00D2][GDK_KEY_r] = sim_telex_keymap[0x00D2][GDK_KEY_R] =
    sim_telex_keymap[0x1ECC][GDK_KEY_r] = sim_telex_keymap[0x1ECC][GDK_KEY_R] =
    sim_telex_keymap[0x00D3][GDK_KEY_r] = sim_telex_keymap[0x00D3][GDK_KEY_R] =
    sim_telex_keymap[0x00D5][GDK_KEY_r] = sim_telex_keymap[0x00D5][GDK_KEY_R] = 0x1ECE;

    /* Os Òs Ọs Ỏs Õs = Ó */
    sim_telex_keymap[0x004F][GDK_KEY_s] = sim_telex_keymap[0x004F][GDK_KEY_S] =
    sim_telex_keymap[0x00D2][GDK_KEY_s] = sim_telex_keymap[0x00D2][GDK_KEY_S] =
    sim_telex_keymap[0x1ECC][GDK_KEY_s] = sim_telex_keymap[0x1ECC][GDK_KEY_S] =
    sim_telex_keymap[0x1ECE][GDK_KEY_s] = sim_telex_keymap[0x1ECE][GDK_KEY_S] =
    sim_telex_keymap[0x00D5][GDK_KEY_s] = sim_telex_keymap[0x00D5][GDK_KEY_S] = 0x00D3;

    /* Ox Òx Ọx Ỏx Óx = Õ */
    sim_telex_keymap[0x004F][GDK_KEY_x] = sim_telex_keymap[0x004F][GDK_KEY_X] =
    sim_telex_keymap[0x00D2][GDK_KEY_x] = sim_telex_keymap[0x00D2][GDK_KEY_X] =
    sim_telex_keymap[0x1ECC][GDK_KEY_x] = sim_telex_keymap[0x1ECC][GDK_KEY_X] =
    sim_telex_keymap[0x1ECE][GDK_KEY_x] = sim_telex_keymap[0x1ECE][GDK_KEY_X] =
    sim_telex_keymap[0x00D3][GDK_KEY_x] = sim_telex_keymap[0x00D3][GDK_KEY_X] = 0x00D5;

    /**
     * Block
     * Ơ(0x01A0) Ờ(0x1EDC) Ợ(0x1EE2) Ở(0x1EDE) Ớ(0x1EDA) Ỡ(0x1EE0)
     * O(0x004F) Ò(0x00D2) Ọ(0x1ECC) Ỏ(0x1ECE) Ó(0x00D3) Õ(0x00D5) (for reference)
     * Ô(0x00D4) Ồ(0x1ED2) Ộ(0x1ED8) Ổ(0x1ED4) Ố(0x1ED0) Ỗ(0x1ED6) (for reference)
     */
    /* Ow Ôw = Ơ */
    sim_telex_keymap[0x004F][GDK_KEY_w] = sim_telex_keymap[0x004F][GDK_KEY_W] =
    sim_telex_keymap[0x00D4][GDK_KEY_w] = sim_telex_keymap[0x00D4][GDK_KEY_W] = 0x01A0;

    /* Ơf Ợf Ởf Ớf Ỡf Òw Ồw = Ờ */
    sim_telex_keymap[0x01A0][GDK_KEY_f] = sim_telex_keymap[0x01A0][GDK_KEY_F] =
    sim_telex_keymap[0x1EE2][GDK_KEY_f] = sim_telex_keymap[0x1EE2][GDK_KEY_F] =
    sim_telex_keymap[0x1EDE][GDK_KEY_f] = sim_telex_keymap[0x1EDE][GDK_KEY_F] =
    sim_telex_keymap[0x1EDA][GDK_KEY_f] = sim_telex_keymap[0x1EDA][GDK_KEY_F] =
    sim_telex_keymap[0x1EE0][GDK_KEY_f] = sim_telex_keymap[0x1EE0][GDK_KEY_F] =
    sim_telex_keymap[0x00D2][GDK_KEY_w] = sim_telex_keymap[0x00D2][GDK_KEY_W] =
    sim_telex_keymap[0x1ED2][GDK_KEY_w] = sim_telex_keymap[0x1ED2][GDK_KEY_W] = 0x1EDC;

    /* Ơj Ờj Ởj Ớj Ỡj Ọw Ộw = Ợ */
    sim_telex_keymap[0x01A0][GDK_KEY_j] = sim_telex_keymap[0x01A0][GDK_KEY_J] =
    sim_telex_keymap[0x1EDC][GDK_KEY_j] = sim_telex_keymap[0x1EDC][GDK_KEY_J] =
    sim_telex_keymap[0x1EDE][GDK_KEY_j] = sim_telex_keymap[0x1EDE][GDK_KEY_J] =
    sim_telex_keymap[0x1EDA][GDK_KEY_j] = sim_telex_keymap[0x1EDA][GDK_KEY_J] =
    sim_telex_keymap[0x1EE0][GDK_KEY_j] = sim_telex_keymap[0x1EE0][GDK_KEY_J] =
    sim_telex_keymap[0x1ECC][GDK_KEY_w] = sim_telex_keymap[0x1ECC][GDK_KEY_W] =
    sim_telex_keymap[0x1ED8][GDK_KEY_w] = sim_telex_keymap[0x1ED8][GDK_KEY_W] = 0x1EE2;

    /* Ơr Ờr Ợr Ớr Ỡr Ỏw Ổw = Ở */
    sim_telex_keymap[0x01A0][GDK_KEY_r] = sim_telex_keymap[0x01A0][GDK_KEY_R] =
    sim_telex_keymap[0x1EDC][GDK_KEY_r] = sim_telex_keymap[0x1EDC][GDK_KEY_R] =
    sim_telex_keymap[0x1EE2][GDK_KEY_r] = sim_telex_keymap[0x1EE2][GDK_KEY_R] =
    sim_telex_keymap[0x1EDA][GDK_KEY_r] = sim_telex_keymap[0x1EDA][GDK_KEY_R] =
    sim_telex_keymap[0x1EE0][GDK_KEY_r] = sim_telex_keymap[0x1EE0][GDK_KEY_R] =
    sim_telex_keymap[0x1ECE][GDK_KEY_w] = sim_telex_keymap[0x1ECE][GDK_KEY_W] =
    sim_telex_keymap[0x1ED4][GDK_KEY_w] = sim_telex_keymap[0x1ED4][GDK_KEY_W] = 0x1EDE;

    /* Ơs Ờs Ợs Ởs Ỡs Ów Ốw = Ớ */
    sim_telex_keymap[0x01A0][GDK_KEY_s] = sim_telex_keymap[0x01A0][GDK_KEY_S] =
    sim_telex_keymap[0x1EDC][GDK_KEY_s] = sim_telex_keymap[0x1EDC][GDK_KEY_S] =
    sim_telex_keymap[0x1EE2][GDK_KEY_s] = sim_telex_keymap[0x1EE2][GDK_KEY_S] =
    sim_telex_keymap[0x1EDE][GDK_KEY_s] = sim_telex_keymap[0x1EDE][GDK_KEY_S] =
    sim_telex_keymap[0x1EE0][GDK_KEY_s] = sim_telex_keymap[0x1EE0][GDK_KEY_S] =
    sim_telex_keymap[0x00D3][GDK_KEY_w] = sim_telex_keymap[0x00D3][GDK_KEY_W] =
    sim_telex_keymap[0x1ED0][GDK_KEY_w] = sim_telex_keymap[0x1ED0][GDK_KEY_W] = 0x1EDA;

    /* Ơx Ờx Ợx Ởx Ớx Õw Ỗw = Ỡ */
    sim_telex_keymap[0x01A0][GDK_KEY_x] = sim_telex_keymap[0x01A0][GDK_KEY_X] =
    sim_telex_keymap[0x1EDC][GDK_KEY_x] = sim_telex_keymap[0x1EDC][GDK_KEY_X] =
    sim_telex_keymap[0x1EE2][GDK_KEY_x] = sim_telex_keymap[0x1EE2][GDK_KEY_X] =
    sim_telex_keymap[0x1EDE][GDK_KEY_x] = sim_telex_keymap[0x1EDE][GDK_KEY_X] =
    sim_telex_keymap[0x1EDA][GDK_KEY_x] = sim_telex_keymap[0x1EDA][GDK_KEY_X] =
    sim_telex_keymap[0x00D5][GDK_KEY_w] = sim_telex_keymap[0x00D5][GDK_KEY_W] =
    sim_telex_keymap[0x1ED6][GDK_KEY_w] = sim_telex_keymap[0x1ED6][GDK_KEY_W] = 0x1EE0;

    /**
     * Block
     * Ô(0x00D4) Ồ(0x1ED2) Ộ(0x1ED8) Ổ(0x1ED4) Ố(0x1ED0) Ỗ(0x1ED6)
     * O(0x004F) Ò(0x00D2) Ọ(0x1ECC) Ỏ(0x1ECE) Ó(0x00D3) Õ(0x00D5) (for reference)
     * Ơ(0x01A0) Ờ(0x1EDC) Ợ(0x1EE2) Ở(0x1EDE) Ớ(0x1EDA) Ỡ(0x1EE0) (for reference)
     */
    /* Oo Ơo = Ô */
    sim_telex_keymap[0x004F][GDK_KEY_o] = sim_telex_keymap[0x004F][GDK_KEY_O] =
    sim_telex_keymap[0x01A0][GDK_KEY_o] = sim_telex_keymap[0x01A0][GDK_KEY_O] = 0x00D4;

    /* Ôf Ộf Ổf Ốf Ỗf Òo Ờo = Ồ */
    sim_telex_keymap[0x00D4][GDK_KEY_f] = sim_telex_keymap[0x00D4][GDK_KEY_F] =
    sim_telex_keymap[0x1ED8][GDK_KEY_f] = sim_telex_keymap[0x1ED8][GDK_KEY_F] =
    sim_telex_keymap[0x1ED4][GDK_KEY_f] = sim_telex_keymap[0x1ED4][GDK_KEY_F] =
    sim_telex_keymap[0x1ED0][GDK_KEY_f] = sim_telex_keymap[0x1ED0][GDK_KEY_F] =
    sim_telex_keymap[0x1ED6][GDK_KEY_f] = sim_telex_keymap[0x1ED6][GDK_KEY_F] =
    sim_telex_keymap[0x00D2][GDK_KEY_o] = sim_telex_keymap[0x00D2][GDK_KEY_O] =
    sim_telex_keymap[0x1EDC][GDK_KEY_o] = sim_telex_keymap[0x1EDC][GDK_KEY_O] = 0x1ED2;

    /* Ôj Ồj Ổj Ốj Ỗj Ọo Ợo = Ộ */
    sim_telex_keymap[0x00D4][GDK_KEY_j] = sim_telex_keymap[0x00D4][GDK_KEY_J] =
    sim_telex_keymap[0x1ED2][GDK_KEY_j] = sim_telex_keymap[0x1ED2][GDK_KEY_J] =
    sim_telex_keymap[0x1ED4][GDK_KEY_j] = sim_telex_keymap[0x1ED4][GDK_KEY_J] =
    sim_telex_keymap[0x1ED0][GDK_KEY_j] = sim_telex_keymap[0x1ED0][GDK_KEY_J] =
    sim_telex_keymap[0x1ED6][GDK_KEY_j] = sim_telex_keymap[0x1ED6][GDK_KEY_J] =
    sim_telex_keymap[0x1ECC][GDK_KEY_o] = sim_telex_keymap[0x1ECC][GDK_KEY_O] =
    sim_telex_keymap[0x1EE2][GDK_KEY_o] = sim_telex_keymap[0x1EE2][GDK_KEY_O] = 0x1ED8;

    /* Ôr Ồr Ộr Ốr Ỗr Ỏo Ởo = Ổ */
    sim_telex_keymap[0x00D4][GDK_KEY_r] = sim_telex_keymap[0x00D4][GDK_KEY_R] =
    sim_telex_keymap[0x1ED2][GDK_KEY_r] = sim_telex_keymap[0x1ED2][GDK_KEY_R] =
    sim_telex_keymap[0x1ED8][GDK_KEY_r] = sim_telex_keymap[0x1ED8][GDK_KEY_R] =
    sim_telex_keymap[0x1ED0][GDK_KEY_r] = sim_telex_keymap[0x1ED0][GDK_KEY_R] =
    sim_telex_keymap[0x1ED6][GDK_KEY_r] = sim_telex_keymap[0x1ED6][GDK_KEY_R] =
    sim_telex_keymap[0x1ECE][GDK_KEY_o] = sim_telex_keymap[0x1ECE][GDK_KEY_O] =
    sim_telex_keymap[0x1EDE][GDK_KEY_o] = sim_telex_keymap[0x1EDE][GDK_KEY_O] = 0x1ED4;

    /* Ôs Ồs Ộs Ổs Ỗs Óo Ớo = Ố */
    sim_telex_keymap[0x00D4][GDK_KEY_s] = sim_telex_keymap[0x00D4][GDK_KEY_S] =
    sim_telex_keymap[0x1ED2][GDK_KEY_s] = sim_telex_keymap[0x1ED2][GDK_KEY_S] =
    sim_telex_keymap[0x1ED8][GDK_KEY_s] = sim_telex_keymap[0x1ED8][GDK_KEY_S] =
    sim_telex_keymap[0x1ED4][GDK_KEY_s] = sim_telex_keymap[0x1ED4][GDK_KEY_S] =
    sim_telex_keymap[0x1ED6][GDK_KEY_s] = sim_telex_keymap[0x1ED6][GDK_KEY_S] =
    sim_telex_keymap[0x00D3][GDK_KEY_o] = sim_telex_keymap[0x00D3][GDK_KEY_O] =
    sim_telex_keymap[0x1EDA][GDK_KEY_o] = sim_telex_keymap[0x1EDA][GDK_KEY_O] = 0x1ED0;

    /* Ôx Ồx Ộx Ổx Ốx Õo Ỡo = Ỗ */
    sim_telex_keymap[0x00D4][GDK_KEY_x] = sim_telex_keymap[0x00D4][GDK_KEY_X] =
    sim_telex_keymap[0x1ED2][GDK_KEY_x] = sim_telex_keymap[0x1ED2][GDK_KEY_X] =
    sim_telex_keymap[0x1ED8][GDK_KEY_x] = sim_telex_keymap[0x1ED8][GDK_KEY_X] =
    sim_telex_keymap[0x1ED4][GDK_KEY_x] = sim_telex_keymap[0x1ED4][GDK_KEY_X] =
    sim_telex_keymap[0x1ED0][GDK_KEY_x] = sim_telex_keymap[0x1ED0][GDK_KEY_X] =
    sim_telex_keymap[0x00D5][GDK_KEY_o] = sim_telex_keymap[0x00D5][GDK_KEY_O] =
    sim_telex_keymap[0x1EE0][GDK_KEY_o] = sim_telex_keymap[0x1EE0][GDK_KEY_O] = 0x1ED6;

    /**
     * Block
     * U(0x0055) Ù(0x00D9) Ụ(0x1EE4) Ủ(0x1EE6) Ú(0x00DA) Ũ(0x0168)
     */
    /* Uf Ụf Ủr Úr Ũf = Ù */
    sim_telex_keymap[0x0055][GDK_KEY_f] = sim_telex_keymap[0x0055][GDK_KEY_F] =
    sim_telex_keymap[0x1EE4][GDK_KEY_f] = sim_telex_keymap[0x1EE4][GDK_KEY_F] =
    sim_telex_keymap[0x1EE6][GDK_KEY_f] = sim_telex_keymap[0x1EE6][GDK_KEY_F] =
    sim_telex_keymap[0x00DA][GDK_KEY_f] = sim_telex_keymap[0x00DA][GDK_KEY_F] =
    sim_telex_keymap[0x0168][GDK_KEY_f] = sim_telex_keymap[0x0168][GDK_KEY_F] = 0x00D9;

    /* Uj Ùj Ủj Új Ũj = Ụ */
    sim_telex_keymap[0x0055][GDK_KEY_j] = sim_telex_keymap[0x0055][GDK_KEY_J] =
    sim_telex_keymap[0x00D9][GDK_KEY_j] = sim_telex_keymap[0x00D9][GDK_KEY_J] =
    sim_telex_keymap[0x1EE6][GDK_KEY_j] = sim_telex_keymap[0x1EE6][GDK_KEY_J] =
    sim_telex_keymap[0x00DA][GDK_KEY_j] = sim_telex_keymap[0x00DA][GDK_KEY_J] =
    sim_telex_keymap[0x0168][GDK_KEY_j] = sim_telex_keymap[0x0168][GDK_KEY_J] = 0x1EE4;

    /* Ur Ùr Ụr Úr Ũr = Ủ */
    sim_telex_keymap[0x0055][GDK_KEY_r] = sim_telex_keymap[0x0055][GDK_KEY_R] =
    sim_telex_keymap[0x00D9][GDK_KEY_r] = sim_telex_keymap[0x00D9][GDK_KEY_R] =
    sim_telex_keymap[0x1EE4][GDK_KEY_r] = sim_telex_keymap[0x1EE4][GDK_KEY_R] =
    sim_telex_keymap[0x00DA][GDK_KEY_r] = sim_telex_keymap[0x00DA][GDK_KEY_R] =
    sim_telex_keymap[0x0168][GDK_KEY_r] = sim_telex_keymap[0x0168][GDK_KEY_R] = 0x1EE6;

    /* Us Ùs Ụs Ủs Ũs = Ú */
    sim_telex_keymap[0x0055][GDK_KEY_s] = sim_telex_keymap[0x0055][GDK_KEY_S] =
    sim_telex_keymap[0x00D9][GDK_KEY_s] = sim_telex_keymap[0x00D9][GDK_KEY_S] =
    sim_telex_keymap[0x1EE4][GDK_KEY_s] = sim_telex_keymap[0x1EE4][GDK_KEY_S] =
    sim_telex_keymap[0x1EE6][GDK_KEY_s] = sim_telex_keymap[0x1EE6][GDK_KEY_S] =
    sim_telex_keymap[0x0168][GDK_KEY_s] = sim_telex_keymap[0x0168][GDK_KEY_S] = 0x00DA;

    /* Ux Ùx Ụx Ủx Úx = Ũ */
    sim_telex_keymap[0x0055][GDK_KEY_x] = sim_telex_keymap[0x0055][GDK_KEY_X] =
    sim_telex_keymap[0x00D9][GDK_KEY_x] = sim_telex_keymap[0x00D9][GDK_KEY_X] =
    sim_telex_keymap[0x1EE4][GDK_KEY_x] = sim_telex_keymap[0x1EE4][GDK_KEY_X] =
    sim_telex_keymap[0x1EE6][GDK_KEY_x] = sim_telex_keymap[0x1EE6][GDK_KEY_X] =
    sim_telex_keymap[0x00DA][GDK_KEY_x] = sim_telex_keymap[0x00DA][GDK_KEY_X] = 0x0168;

    /**
     * Block
     * Ư(0x01AF) Ừ(0x1EEA) Ự(0x1EF0) Ử(0x1EEC) Ứ(0x1EE8) Ữ(0x1EEE)
     * U(0x0055) Ù(0x00D9) Ụ(0x1EE4) Ủ(0x1EE6) Ú(0x00DA) Ũ(0x0168) (for reference)
     */
    /* Uw = Ư */
    sim_telex_keymap[0x0055][GDK_KEY_w] = sim_telex_keymap[0x0055][GDK_KEY_W] = 0x01AF;

    /* Ưf Ựf Ửf Ứf Ữf Ùw = Ừ */
    sim_telex_keymap[0x01AF][GDK_KEY_f] = sim_telex_keymap[0x01AF][GDK_KEY_F] =
    sim_telex_keymap[0x1EF0][GDK_KEY_f] = sim_telex_keymap[0x1EF0][GDK_KEY_F] =
    sim_telex_keymap[0x1EEC][GDK_KEY_f] = sim_telex_keymap[0x1EEC][GDK_KEY_F] =
    sim_telex_keymap[0x1EE8][GDK_KEY_f] = sim_telex_keymap[0x1EE8][GDK_KEY_F] =
    sim_telex_keymap[0x1EEE][GDK_KEY_f] = sim_telex_keymap[0x1EEE][GDK_KEY_F] =
    sim_telex_keymap[0x00D9][GDK_KEY_w] = sim_telex_keymap[0x00D9][GDK_KEY_W] = 0x1EEA;

    /* Ưj Ừj Ửj Ứj Ữj Ụw = Ự */
    sim_telex_keymap[0x01AF][GDK_KEY_j] = sim_telex_keymap[0x01AF][GDK_KEY_J] =
    sim_telex_keymap[0x1EEA][GDK_KEY_j] = sim_telex_keymap[0x1EEA][GDK_KEY_J] =
    sim_telex_keymap[0x1EEC][GDK_KEY_j] = sim_telex_keymap[0x1EEC][GDK_KEY_J] =
    sim_telex_keymap[0x1EE8][GDK_KEY_j] = sim_telex_keymap[0x1EE8][GDK_KEY_J] =
    sim_telex_keymap[0x1EEE][GDK_KEY_j] = sim_telex_keymap[0x1EEE][GDK_KEY_J] =
    sim_telex_keymap[0x1EE4][GDK_KEY_w] = sim_telex_keymap[0x1EE4][GDK_KEY_W] = 0x1EF0;

    /* Ưr Ừr Ựr Ứr Ữr Ủw = Ử */
    sim_telex_keymap[0x01AF][GDK_KEY_r] = sim_telex_keymap[0x01AF][GDK_KEY_R] =
    sim_telex_keymap[0x1EEA][GDK_KEY_r] = sim_telex_keymap[0x1EEA][GDK_KEY_R] =
    sim_telex_keymap[0x1EF0][GDK_KEY_r] = sim_telex_keymap[0x1EF0][GDK_KEY_R] =
    sim_telex_keymap[0x1EE8][GDK_KEY_r] = sim_telex_keymap[0x1EE8][GDK_KEY_R] =
    sim_telex_keymap[0x1EEE][GDK_KEY_r] = sim_telex_keymap[0x1EEE][GDK_KEY_R] =
    sim_telex_keymap[0x1EE6][GDK_KEY_w] = sim_telex_keymap[0x1EE6][GDK_KEY_W] = 0x1EEC;

    /* Ưs Ừs Ựs Ửs Ữs Úw = Ứ */
    sim_telex_keymap[0x01AF][GDK_KEY_s] = sim_telex_keymap[0x01AF][GDK_KEY_S] =
    sim_telex_keymap[0x1EEA][GDK_KEY_s] = sim_telex_keymap[0x1EEA][GDK_KEY_S] =
    sim_telex_keymap[0x1EF0][GDK_KEY_s] = sim_telex_keymap[0x1EF0][GDK_KEY_S] =
    sim_telex_keymap[0x1EEC][GDK_KEY_s] = sim_telex_keymap[0x1EEC][GDK_KEY_S] =
    sim_telex_keymap[0x1EEE][GDK_KEY_s] = sim_telex_keymap[0x1EEE][GDK_KEY_S] =
    sim_telex_keymap[0x00DA][GDK_KEY_w] = sim_telex_keymap[0x00DA][GDK_KEY_W] = 0x1EE8;

    /* Ưx Ừx Ựx Ửx Ứx Ũw = Ữ */
    sim_telex_keymap[0x01AF][GDK_KEY_x] = sim_telex_keymap[0x01AF][GDK_KEY_X] =
    sim_telex_keymap[0x1EEA][GDK_KEY_x] = sim_telex_keymap[0x1EEA][GDK_KEY_X] =
    sim_telex_keymap[0x1EF0][GDK_KEY_x] = sim_telex_keymap[0x1EF0][GDK_KEY_X] =
    sim_telex_keymap[0x1EEC][GDK_KEY_x] = sim_telex_keymap[0x1EEC][GDK_KEY_X] =
    sim_telex_keymap[0x1EE8][GDK_KEY_x] = sim_telex_keymap[0x1EE8][GDK_KEY_X] =
    sim_telex_keymap[0x0168][GDK_KEY_w] = sim_telex_keymap[0x0168][GDK_KEY_W] = 0x1EEE;

    /**
     * Block
     * Y(0x0059) Ỳ(0x1EF2) Ỵ(0x1EF4) Ỷ(0x1EF6) Ý(0x00DD) Ỹ(0x1EF8)
     */
    /* Yf Ỵf Ỷf Ýf Ỹf = Ỳ */
    sim_telex_keymap[0x0059][GDK_KEY_f] = sim_telex_keymap[0x0059][GDK_KEY_F] =
    sim_telex_keymap[0x1EF4][GDK_KEY_f] = sim_telex_keymap[0x1EF4][GDK_KEY_F] =
    sim_telex_keymap[0x1EF6][GDK_KEY_f] = sim_telex_keymap[0x1EF6][GDK_KEY_F] =
    sim_telex_keymap[0x00DD][GDK_KEY_f] = sim_telex_keymap[0x00DD][GDK_KEY_F] =
    sim_telex_keymap[0x1EF8][GDK_KEY_f] = sim_telex_keymap[0x1EF8][GDK_KEY_F] = 0x1EF2;

    /* Yj Ỳj Ỷj Ýj Ỹj = Ỵ */
    sim_telex_keymap[0x0059][GDK_KEY_j] = sim_telex_keymap[0x0059][GDK_KEY_J] =
    sim_telex_keymap[0x1EF2][GDK_KEY_j] = sim_telex_keymap[0x1EF2][GDK_KEY_J] =
    sim_telex_keymap[0x1EF6][GDK_KEY_j] = sim_telex_keymap[0x1EF6][GDK_KEY_J] =
    sim_telex_keymap[0x00DD][GDK_KEY_j] = sim_telex_keymap[0x00DD][GDK_KEY_J] =
    sim_telex_keymap[0x1EF8][GDK_KEY_j] = sim_telex_keymap[0x1EF8][GDK_KEY_J] = 0x1EF4;

    /* Yr Ỳr Ỵr Ýr Ỹr = Ỷ */
    sim_telex_keymap[0x0059][GDK_KEY_r] = sim_telex_keymap[0x0059][GDK_KEY_R] =
    sim_telex_keymap[0x1EF2][GDK_KEY_r] = sim_telex_keymap[0x1EF2][GDK_KEY_R] =
    sim_telex_keymap[0x1EF4][GDK_KEY_r] = sim_telex_keymap[0x1EF4][GDK_KEY_R] =
    sim_telex_keymap[0x00DD][GDK_KEY_r] = sim_telex_keymap[0x00DD][GDK_KEY_R] =
    sim_telex_keymap[0x1EF8][GDK_KEY_r] = sim_telex_keymap[0x1EF8][GDK_KEY_R] = 0x1EF6;

    /* Ys Ỳs Ỵs Ỷs Ỹs = Ý */
    sim_telex_keymap[0x0059][GDK_KEY_s] = sim_telex_keymap[0x0059][GDK_KEY_S] =
    sim_telex_keymap[0x1EF2][GDK_KEY_s] = sim_telex_keymap[0x1EF2][GDK_KEY_S] =
    sim_telex_keymap[0x1EF4][GDK_KEY_s] = sim_telex_keymap[0x1EF4][GDK_KEY_S] =
    sim_telex_keymap[0x1EF6][GDK_KEY_s] = sim_telex_keymap[0x1EF6][GDK_KEY_S] =
    sim_telex_keymap[0x1EF8][GDK_KEY_s] = sim_telex_keymap[0x1EF8][GDK_KEY_S] = 0x00DD;

    /* Yx Ỳx Ỵx Ỷx Ýx = Ỹ */
    sim_telex_keymap[0x0059][GDK_KEY_x] = sim_telex_keymap[0x0059][GDK_KEY_X] =
    sim_telex_keymap[0x1EF2][GDK_KEY_x] = sim_telex_keymap[0x1EF2][GDK_KEY_X] =
    sim_telex_keymap[0x1EF4][GDK_KEY_x] = sim_telex_keymap[0x1EF4][GDK_KEY_X] =
    sim_telex_keymap[0x1EF6][GDK_KEY_x] = sim_telex_keymap[0x1EF6][GDK_KEY_X] =
    sim_telex_keymap[0x00DD][GDK_KEY_x] = sim_telex_keymap[0x00DD][GDK_KEY_X] = 0x1EF8;

} /* End of #init_sim_telex_keymap */
