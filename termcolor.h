/* COLORIZE TERMINAL TEXT WITH GRUVBOX PALETTE IN
 * TERMCOLOR (256 COLORS) OR TRUECOLOR (RGB CODE)
 * BY #define TERMCOLOR_CODE OR TRUECOLOR MANUALLY
 */
// clang-format off

#ifndef TERMCOLOR_H
#define TERMCOLOR_H

// CONTROL SEQUENCE INTRODUCER (CSI) SETUP
#define CSI             "\e[" // "\033["
#define RESET           CSI  "0m"
#define RESET_FG_COLOR  CSI "38m"
#define RESET_BG_COLOR  CSI "48m"
#define BOLD_TEXT       "1"
// STYLES
#define BOLD(x)         CSI BOLD_TEXT "m" x RESET
#define BOLD_C          CSI BOLD_TEXT "m"

// STANDARD FOREGROUND ANSI COLORS
#define      ANSI_BLA(x) CSI  "30m" x RESET
#define      ANSI_RED(x) CSI  "31m" x RESET
#define      ANSI_GRE(x) CSI  "32m" x RESET
#define      ANSI_YEL(x) CSI  "33m" x RESET
#define      ANSI_BLU(x) CSI  "34m" x RESET
#define      ANSI_MAG(x) CSI  "35m" x RESET
#define      ANSI_CYA(x) CSI  "36m" x RESET
#define      ANSI_WHI(x) CSI  "37m" x RESET
#define      ANSI_BLAC   CSI  "30m"
#define      ANSI_REDC   CSI  "31m"
#define      ANSI_GREC   CSI  "32m"
#define      ANSI_YELC   CSI  "33m"
#define      ANSI_BLUC   CSI  "34m"
#define      ANSI_MAGC   CSI  "35m"
#define      ANSI_CYAC   CSI  "36m"
#define      ANSI_WHIC   CSI  "37m"
// STANDARD BACKGROUND ANSI COLORS
#define   BG_ANSI_BLA(x) CSI  "40m" x RESET
#define   BG_ANSI_RED(x) CSI  "41m" x RESET
#define   BG_ANSI_GRE(x) CSI  "42m" x RESET
#define   BG_ANSI_YEL(x) CSI  "43m" x RESET
#define   BG_ANSI_BLU(x) CSI  "44m" x RESET
#define   BG_ANSI_MAG(x) CSI  "45m" x RESET
#define   BG_ANSI_CYA(x) CSI  "46m" x RESET
#define   BG_ANSI_WHI(x) CSI  "47m" x RESET
#define   BG_ANSI_BLAC   CSI  "40m"
#define   BG_ANSI_REDC   CSI  "41m"
#define   BG_ANSI_GREC   CSI  "42m"
#define   BG_ANSI_YELC   CSI  "43m"
#define   BG_ANSI_BLUC   CSI  "44m"
#define   BG_ANSI_MAGC   CSI  "45m"
#define   BG_ANSI_CYAC   CSI  "46m"
#define   BG_ANSI_WHIC   CSI  "47m"
// BRIGHTER FOREGROUND ANSI COLORS
#define    ANSI_B_BLA(x) CSI  "90m" x RESET
#define    ANSI_B_RED(x) CSI  "91m" x RESET
#define    ANSI_B_GRE(x) CSI  "92m" x RESET
#define    ANSI_B_YEL(x) CSI  "93m" x RESET
#define    ANSI_B_BLU(x) CSI  "94m" x RESET
#define    ANSI_B_MAG(x) CSI  "95m" x RESET
#define    ANSI_B_CYA(x) CSI  "96m" x RESET
#define    ANSI_B_WHI(x) CSI  "97m" x RESET
#define    ANSI_B_BLAC   CSI  "90m"
#define    ANSI_B_REDC   CSI  "91m"
#define    ANSI_B_GREC   CSI  "92m"
#define    ANSI_B_YELC   CSI  "93m"
#define    ANSI_B_BLUC   CSI  "94m"
#define    ANSI_B_MAGC   CSI  "95m"
#define    ANSI_B_CYAC   CSI  "96m"
#define    ANSI_B_WHIC   CSI  "97m"
// BRIGHTER BACKGROUND ANSI COLORS
#define BG_ANSI_B_BLA(x) CSI "100m" x RESET
#define BG_ANSI_B_RED(x) CSI "101m" x RESET
#define BG_ANSI_B_GRE(x) CSI "102m" x RESET
#define BG_ANSI_B_YEL(x) CSI "103m" x RESET
#define BG_ANSI_B_BLU(x) CSI "104m" x RESET
#define BG_ANSI_B_MAG(x) CSI "105m" x RESET
#define BG_ANSI_B_CYA(x) CSI "106m" x RESET
#define BG_ANSI_B_WHI(x) CSI "107m" x RESET
#define BG_ANSI_B_BLAC   CSI "100m"
#define BG_ANSI_B_REDC   CSI "101m"
#define BG_ANSI_B_GREC   CSI "102m"
#define BG_ANSI_B_YELC   CSI "103m"
#define BG_ANSI_B_BLUC   CSI "104m"
#define BG_ANSI_B_MAGC   CSI "105m"
#define BG_ANSI_B_CYAC   CSI "106m"
#define BG_ANSI_B_WHIC   CSI "107m"

// DECISION OF SELECT GRAPHIC RENDITION (SGR) PARAMETERS AND COLOR CODE
#if defined TRUECOLOR_CODE
    #define FG "38;2;"
    #define BG "48;2;"

    #define DARK0_HARD
    #define DARK0
    #define DARK0_SOFT
    #define DARK1
    #define DARK2
    #define DARK3
    #define DARK4
   
    #define GRAY0
    #define GRAY1
   
    #define LIGHT0_HARD
    #define LIGHT0
    #define LIGHT0_SOFT
    #define LIGHT1
    #define LIGHT2
    #define LIGHT3
    #define LIGHT4
   
    #define BRIGHT_RED
    #define BRIGHT_GREEN
    #define BRIGHT_YELLOW
    #define BRIGHT_BLUE
    #define BRIGHT_PURPLE
    #define BRIGHT_AQUA
    #define BRIGHT_ORANGE
   
    #define NEUTRAL_RED
    #define NEUTRAL_GREEN
    #define NEUTRAL_YELLOW
    #define NEUTRAL_BLUE
    #define NEUTRAL_PURPLE
    #define NEUTRAL_AQUA
    #define NEUTRAL_ORANGE
   
    #define FADED_RED
    #define FADED_GREEN
    #define FADED_YELLOW
    #define FADED_BLUE
    #define FADED_PURPLE
    #define FADED_AQUA
    #define FADED_ORANGE

    // #define NEUTRAL_RED "204;36;29"
    // #define NEUTRAL_GREEN "215;153;33"
#else // default using TERMINAL_CODE (256)
    #define TERMCOLOR_CODE

    #define FG "38;5;"
    #define BG "48;5;"

    #define DARK0_HARD "234"
    #define DARK0 "235"
    #define DARK0_SOFT "236"
    #define DARK1 "237"
    #define DARK2 "239"
    #define DARK3 "241"
    #define DARK4 "243"
    
    #define GRAY0 "245"
    #define GRAY1 "244"
    
    #define LIGHT0_HARD "230"
    #define LIGHT0 "229"
    #define LIGHT0_SOFT "228"
    #define LIGHT1 "223"
    #define LIGHT2 "250"
    #define LIGHT3 "248"
    #define LIGHT4 "246"
    
    #define BRIGHT_RED "167"
    #define BRIGHT_GREEN "142"
    #define BRIGHT_YELLOW "214"
    #define BRIGHT_BLUE "109"
    #define BRIGHT_PURPLE "175"
    #define BRIGHT_AQUA "108"
    #define BRIGHT_ORANGE "208"
    
    #define NEUTRAL_RED "124"
    #define NEUTRAL_GREEN "106"
    #define NEUTRAL_YELLOW "172"
    #define NEUTRAL_BLUE "66"
    #define NEUTRAL_PURPLE "132"
    #define NEUTRAL_AQUA "72"
    #define NEUTRAL_ORANGE "166"
    
    #define FADED_RED "88"
    #define FADED_GREEN "100"
    #define FADED_YELLOW "136"
    #define FADED_BLUE "24"
    #define FADED_PURPLE "96"
    #define FADED_AQUA "66"
    #define FADED_ORANGE "130"
#endif


/* QUICK GUIDE
 * (work properly with array of char and string object)
 * [BG_]<B|N|F>_<COLOR>[_C]
 * by default, ForeGround and wrapped with RESET
 * - optional BG_ - BackGround
 * - mandatory B|N|F - either Bright, Neutral or Faded
 * - mandatory COLOR - RED, GREEN, YELLOW, BLUE, PURPLE, AQUA, ORANGE
 * - optional _C - continue the control sequence for following text
 * e.g. B_RED(text): wrap text in Bright RED
 *      F_RED_C: keep the Faded Red format until meet up RESET
 *      BG_N_AQUA(text): wrap text in Neutral AQUA BackGround
 */

// BRIGHT
#define    B_RED(x)   CSI FG BRIGHT_RED     "m" x RESET
#define    B_GRE(x)   CSI FG BRIGHT_GREEN   "m" x RESET
#define    B_YEL(x)   CSI FG BRIGHT_YELLOW  "m" x RESET
#define    B_BLU(x)   CSI FG BRIGHT_BLUE    "m" x RESET
#define    B_PUR(x)   CSI FG BRIGHT_PURPLE  "m" x RESET
#define    B_AQU(x)   CSI FG BRIGHT_AQUA    "m" x RESET
#define    B_ORA(x)   CSI FG BRIGHT_ORANGE  "m" x RESET
#define    B_REDC     CSI FG BRIGHT_RED     "m"
#define    B_GREC     CSI FG BRIGHT_GREEN   "m"
#define    B_YELC     CSI FG BRIGHT_YELLOW  "m"
#define    B_BLUC     CSI FG BRIGHT_BLUE    "m"
#define    B_PURC     CSI FG BRIGHT_PURPLE  "m"
#define    B_AQUC     CSI FG BRIGHT_AQUA    "m"
#define    B_ORAC     CSI FG BRIGHT_ORANGE  "m"
#define BG_B_RED(x)   CSI BG BRIGHT_RED     "m" x RESET
#define BG_B_GRE(x)   CSI BG BRIGHT_GREEN   "m" x RESET
#define BG_B_YEL(x)   CSI BG BRIGHT_YELLOW  "m" x RESET
#define BG_B_BLU(x)   CSI BG BRIGHT_BLUE    "m" x RESET
#define BG_B_PUR(x)   CSI BG BRIGHT_PURPLE  "m" x RESET
#define BG_B_AQU(x)   CSI BG BRIGHT_AQUA    "m" x RESET
#define BG_B_ORA(x)   CSI BG BRIGHT_ORANGE  "m" x RESET
#define BG_B_REDC     CSI BG BRIGHT_RED     "m"
#define BG_B_GREC     CSI BG BRIGHT_GREEN   "m"
#define BG_B_YELC     CSI BG BRIGHT_YELLOW  "m"
#define BG_B_BLUC     CSI BG BRIGHT_BLUE    "m"
#define BG_B_PURC     CSI BG BRIGHT_PURPLE  "m"
#define BG_B_AQUC     CSI BG BRIGHT_AQUA    "m"
#define BG_B_ORAC     CSI BG BRIGHT_ORANGE  "m"
// NEUTRAL
#define    N_RED(x)   CSI FG NEUTRAL_RED    "m" x RESET
#define    N_GRE(x)   CSI FG NEUTRAL_GREEN  "m" x RESET
#define    N_YEL(x)   CSI FG NEUTRAL_YELLOW "m" x RESET
#define    N_BLU(x)   CSI FG NEUTRAL_BLUE   "m" x RESET
#define    N_PUR(x)   CSI FG NEUTRAL_PURPLE "m" x RESET
#define    N_AQU(x)   CSI FG NEUTRAL_AQUA   "m" x RESET
#define    N_ORA(x)   CSI FG NEUTRAL_ORANGE "m" x RESET
#define    N_REDC     CSI FG NEUTRAL_RED    "m"
#define    N_GREC     CSI FG NEUTRAL_GREEN  "m"
#define    N_YELC     CSI FG NEUTRAL_YELLOW "m"
#define    N_BLUC     CSI FG NEUTRAL_BLUE   "m"
#define    N_PURC     CSI FG NEUTRAL_PURPLE "m"
#define    N_AQUC     CSI FG NEUTRAL_AQUA   "m"
#define    N_ORAC     CSI FG NEUTRAL_ORANGE "m"
#define BG_N_RED(x)   CSI BG NEUTRAL_RED    "m" x RESET
#define BG_N_GRE(x)   CSI BG NEUTRAL_GREEN  "m" x RESET
#define BG_N_YEL(x)   CSI BG NEUTRAL_YELLOW "m" x RESET
#define BG_N_BLU(x)   CSI BG NEUTRAL_BLUE   "m" x RESET
#define BG_N_PUR(x)   CSI BG NEUTRAL_PURPLE "m" x RESET
#define BG_N_AQU(x)   CSI BG NEUTRAL_AQUA   "m" x RESET
#define BG_N_ORA(x)   CSI BG NEUTRAL_ORANGE "m" x RESET
#define BG_N_REDC     CSI BG NEUTRAL_RED    "m"
#define BG_N_GREC     CSI BG NEUTRAL_GREEN  "m"
#define BG_N_YELC     CSI BG NEUTRAL_YELLOW "m"
#define BG_N_BLUC     CSI BG NEUTRAL_BLUE   "m"
#define BG_N_PURC     CSI BG NEUTRAL_PURPLE "m"
#define BG_N_AQUC     CSI BG NEUTRAL_AQUA   "m"
#define BG_N_ORAC     CSI BG NEUTRAL_ORANGE "m"
// FADED
#define    F_RED(x)   CSI FG FADED_RED      "m" x RESET
#define    F_GRE(x)   CSI FG FADED_GREEN    "m" x RESET
#define    F_YEL(x)   CSI FG FADED_YELLOW   "m" x RESET
#define    F_BLU(x)   CSI FG FADED_BLUE     "m" x RESET
#define    F_PUR(x)   CSI FG FADED_PURPLE   "m" x RESET
#define    F_AQU(x)   CSI FG FADED_AQUA     "m" x RESET
#define    F_ORA(x)   CSI FG FADED_ORANGE   "m" x RESET
#define    F_REDC     CSI FG FADED_RED      "m"
#define    F_GREC     CSI FG FADED_GREEN    "m"
#define    F_YELC     CSI FG FADED_YELLOW   "m"
#define    F_BLUC     CSI FG FADED_BLUE     "m"
#define    F_PURC     CSI FG FADED_PURPLE   "m"
#define    F_AQUC     CSI FG FADED_AQUA     "m"
#define    F_ORAC     CSI FG FADED_ORANGE   "m"
#define BG_F_RED(x)   CSI FG FADED_RED      "m" x RESET
#define BG_F_GRE(x)   CSI FG FADED_GREEN    "m" x RESET
#define BG_F_YEL(x)   CSI FG FADED_YELLOW   "m" x RESET
#define BG_F_BLU(x)   CSI FG FADED_BLUE     "m" x RESET
#define BG_F_PUR(x)   CSI FG FADED_PURPLE   "m" x RESET
#define BG_F_AQU(x)   CSI FG FADED_AQUA     "m" x RESET
#define BG_F_ORA(x)   CSI FG FADED_ORANGE   "m" x RESET
#define BG_F_REDC     CSI FG FADED_RED      "m"
#define BG_F_GREC     CSI FG FADED_GREEN    "m"
#define BG_F_YELC     CSI FG FADED_YELLOW   "m"
#define BG_F_BLUC     CSI FG FADED_BLUE     "m"
#define BG_F_PURC     CSI FG FADED_PURPLE   "m"
#define BG_F_AQUC     CSI FG FADED_AQUA     "m"
#define BG_F_ORAC     CSI FG FADED_ORANGE   "m"

/* - -- - -- - -- - -- - -- - -- - -- - -- - -- - -- - */

#if defined NEUTRAL
    #define  RED    N_RED
    #define  GRE    N_GRE
    #define  YEL    N_YEL
    #define  BLU    N_BLU
    #define  PUR    N_PUR
    #define  AQU    N_AQU
    #define  ORA    N_ORA
    #define BRBG    BG_N_RED
    #define BGRE    BG_N_GRE
    #define BYBG    BG_N_YEL
    #define BBBG    BG_N_BLU
    #define BPBG    BG_N_PUR
    #define BABG    BG_N_AQU
    #define BOBG    BG_N_ORA
    #define  REDC   N_REDC
    #define  YELC   N_YELC
    #define  GREC   N_GREC
    #define  BLUC   N_BLUC
    #define  PURC   N_PURC
    #define  AQUC   N_AQUC
    #define  ORAC   N_ORAC
    #define BREDC   BG_N_REDC
    #define BGREC   BG_N_GREC
    #define BYELC   BG_N_YELC
    #define BBLUC   BG_N_BLUC
    #define BPURC   BG_N_PURC
    #define BAQUC   BG_N_AQUC
    #define BORAC   BG_N_ORAC
#elif defined FADED
    #define  RED    F_RED
    #define  GRE    F_GRE
    #define  YEL    F_YEL
    #define  BLU    F_BLU
    #define  PUR    F_PUR
    #define  AQU    F_AQU
    #define  ORA    F_ORA
    #define BRBG    BG_F_RED
    #define BGRE    BG_F_GRE
    #define BYBG    BG_F_YEL
    #define BBBG    BG_F_BLU
    #define BPBG    BG_F_PUR
    #define BABG    BG_F_AQU
    #define BOBG    BG_F_ORA
    #define  REDC   F_REDC
    #define  YELC   F_YELC
    #define  GREC   F_GREC
    #define  BLUC   F_BLUC
    #define  PURC   F_PURC
    #define  AQUC   F_AQUC
    #define  ORAC   F_ORAC
    #define BREDC   BG_F_REDC
    #define BGREC   BG_F_GREC
    #define BYELC   BG_F_YELC
    #define BBLUC   BG_F_BLUC
    #define BPURC   BG_F_PURC
    #define BAQUC   BG_F_AQUC
    #define BORAC   BG_F_ORAC
#else // default using Bright
    #define BRIGHT
    #define  RED    B_RED
    #define  GRE    B_GRE
    #define  YEL    B_YEL
    #define  BLU    B_BLU
    #define  PUR    B_PUR
    #define  AQU    B_AQU
    #define  ORA    B_ORA
    #define BRBG    BG_B_RED
    #define BGRE    BG_B_GRE
    #define BYBG    BG_B_YEL
    #define BBBG    BG_B_BLU
    #define BPBG    BG_B_PUR
    #define BABG    BG_B_AQU
    #define BOBG    BG_B_ORA
    #define  REDC   B_REDC
    #define  YELC   B_YELC
    #define  GREC   B_GREC
    #define  BLUC   B_BLUC
    #define  PURC   B_PURC
    #define  AQUC   B_AQUC
    #define  ORAC   B_ORAC
    #define BREDC   BG_B_REDC
    #define BGREC   BG_B_GREC
    #define BYELC   BG_B_YELC
    #define BBLUC   BG_B_BLUC
    #define BPURC   BG_B_PURC
    #define BAQUC   BG_B_AQUC
    #define BORAC   BG_B_ORAC
#endif

// GLOBAL UNIVERSAL CUSTOMIZE COLOR RENDITION
#define    TERM_COL(c,x)     CSI "38;5;" #c "m" x RESET
#define BG_TERM_COL(c,x)     CSI "48;5;" #c "m" x RESET
#define    TERM_COLC(c)      CSI "38;5;" #c "m"
#define BG_TERM_COLC(c)      CSI "48;5;" #c "m"
#define    TRUE_COL(r,g,b,x) CSI "38;2;" #r ";" #g ";" #b "m" x RESET
#define BG_TRUE_COL(r,g,b,x) CSI "48;2;" #r ";" #g ";" #b "m" x RESET
#define    TRUE_COLC(r,g,b)  CSI "38;2;" #r ";" #g ";" #b "m"
#define BG_TRUE_COLC(r,g,b)  CSI "48;2;" #r ";" #g ";" #b "m"

/* - -- - -- - -- - -- - -- - -- - -- - -- - -- - -- - */

#endif
