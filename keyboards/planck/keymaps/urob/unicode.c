#include QMK_KEYBOARD_H


// Greek letters and German umlauts
enum unicode_names {
    /* Greek letters (capitalized) */
    U_C_GAMM,
    U_C_DELT,
    U_C_THET,
    U_C_LAMB,
    U_C_XI,
    U_C_PI,
    U_C_SIGM,
    U_C_UPSI,
    U_C_PHI,
    U_C_PSI,
    U_C_OMEG,
    /* Greek letters */
    U_ALPH,
    U_BETA,
    U_GAMM,
    U_DELT,
    U_EPSI,
    U_ZETA,
    U_ETA,
    U_THET,
    U_IOTA,
    U_KAPP,
    U_LAMB,
    U_MU,
    U_NU,
    U_XI,
    U_PI,
    U_RHO,
    U_SIGM,
    U_TAU,
    U_UPSI,
    U_PHI,
    U_CHI,
    U_PSI,
    U_OMEG,
    /* German umlauts */
    U_AE, U_C_AE,
    U_OE, U_C_OE,
    U_UE, U_C_UE,
    U_SS,
};

#define ALPHA X(U_ALPH)
#define BETA X(U_BETA)
#define GAMMA XP(U_GAMM, U_C_GAMM)
#define DELTA XP(U_DELT, U_C_DELT)
#define EPSILON X(U_EPSI)
#define ZETA X(U_ZETA)
#define ETA X(U_ETA)
#define THETA XP(U_THET, U_C_THET)
#define IOTA X(U_IOTA)
#define KAPPA X(U_KAPP)
#define LAMBDA XP(U_LAMB, U_C_LAMB)
#define MUG X(U_MU) // MU conflicts with core variable
#define NU X(U_NU)
#define XI XP(U_XI, U_C_XI)
#define PI XP(U_PI, U_C_PI)
#define RHO X(U_RHO)
#define SIGMA XP(U_SIGM, U_C_SIGM)
#define TAU X(U_TAU)
#define UPSILON XP(U_UPSI, U_C_UPSI)
#define PHI XP(U_PHI, U_C_PHI)
#define CHI X(U_CHI)
#define PSI XP(U_PSI, U_C_PSI)
#define OMEGA XP(U_OMEG, U_C_OMEG)

#define AE XP(U_AE, U_C_AE)
#define OE XP(U_OE, U_C_OE)
#define UE XP(U_UE, U_C_UE)
#define ESZETT X(U_SS)


// Unicode definitions (see keymap.h for key definitions)
const uint32_t PROGMEM unicode_map[] = {
    /* Greek letters (capitalized) */
    [U_C_GAMM] = 0x0393,
    [U_C_DELT] = 0x0394,
    [U_C_THET] = 0x0398,
    [U_C_LAMB] = 0x039B,
    [U_C_XI]   = 0x039E,
    [U_C_PI]   = 0x03A0,
    [U_C_SIGM] = 0x03A3,
    [U_C_UPSI] = 0x03A5,
    [U_C_PHI]  = 0x03A6,
    [U_C_PSI]  = 0x03A8,
    [U_C_OMEG] = 0x03A9,
    /* Greek letters */
    [U_ALPH] = 0x03B1,
    [U_BETA] = 0x03B2,  
    [U_GAMM] = 0x03B3, 
    [U_DELT] = 0x03B4, 
    [U_EPSI] = 0x03F5, // varepsilon = 03B5 
    [U_ZETA] = 0x03B6, 
    [U_ETA]  = 0x03B7, 
    [U_THET] = 0x03B8, 
    [U_IOTA] = 0x03B9, 
    [U_KAPP] = 0x03BA, 
    [U_LAMB] = 0x03BB, 
    [U_MU]   = 0x03BC, 
    [U_NU]   = 0x03BD, 
    [U_XI]   = 0x03BE, 
    [U_PI]   = 0x03C0, 
    [U_RHO]  = 0x03C1, 
    [U_SIGM] = 0x03C3, 
    [U_TAU]  = 0x03C4, 
    [U_UPSI] = 0x03C5, 
    [U_PHI]  = 0x03D5, // varphi = 03C6 
    [U_CHI]  = 0x03C7, 
    [U_PSI]  = 0x03C8, 
    [U_OMEG] = 0x03C9,
    /* German umlauts */
    [U_AE] = 0x00E4,
    [U_OE] = 0x00F6,
    [U_UE] = 0x00FC,
    [U_C_AE] = 0x00C4,
    [U_C_OE] = 0x00D6,
    [U_C_UE] = 0x00DC,
    [U_SS] = 0x00DF,
};
