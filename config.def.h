/* See LICENSE file for copyright and license details. */

#define XF86MonBrightnessDown 0x1008ff03
#define XF86MonBrightnessUp 0x1008ff02

/* appearance */
static const unsigned int borderpx = 1; /* border pixel of windows */
static const unsigned int default_border =
    0; // to switch back to default border after dynamic border resizing via
       // keybinds
static const unsigned int snap = 32;   /* snap pixel */
static const unsigned int gappih = 10; /* horiz inner gap between windows */
static const unsigned int gappiv = 10; /* vert inner gap between windows */
static const unsigned int gappoh =
    10; /* horiz outer gap between windows and screen edge */
static const unsigned int gappov =
    10; /* vert outer gap between windows and screen edge */
static int smartgaps =
    0; /* 1 means no outer gap when there is only one window */
static const unsigned int systraypinning =
    0; /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor
          X */
static const unsigned int systrayspacing = 2; /* systray spacing */
static const int systraypinningfailfirst =
    1; /* 1: if pinning fails,display systray on the 1st monitor,False: display
          systray on last monitor*/
static const int showsystray = 1; /* 0 means no systray */
static const int showbar = 1;     /* 0 means no bar */
static const int showtab = showtab_auto;
static const int toptab = True;
static const int topbar = 1; /* 0 means bottom bar */
static const int horizpadbar = 5;
static const int vertpadbar = 11;
static const int vertpadtab = 33;
static const int horizpadtabi = 15;
static const int horizpadtabo = 15;
static const int scalepreview = 4;
static int tag_preview = 0; /* 1 means enable, 0 is off */

static const char *fonts[] = {
    "Fira Code:size=14:antialias=true:autohint=true",
    "Material Design Icons-Regular:size=16:antialias=true:autohint=true"};
static const int colorfultag =
    1; /* 0 means use SchemeSel for selected non vacant tag */

// theme
// #include "themes/nord.h"

static char color1[] = "#366C93";
static char color2[] = "#1B9AAD";
static char color3[] = "#7898B2";
static char color4[] = "#8C9AB4";
static char color5[] = "#A6A1B1";
static char color6[] = "#DFB1B5";
static char color7[] = "#f5dccf"; // forground
static char color8[] = "#ab9a90";
static char gray[] = "#3B4252";
static char background[] = "#10111d";

static const char *colors[][3] = {
    /*                      fg     bg   border   */
    [SchemeNorm] = {color8, background, gray},
    [SchemeSel] = {gray, color1, color4},
    [TabSel] = {color7, background, background},
    [TabNorm] = {gray, background, background},
    [SchemeTag] = {gray, background, background},
    [SchemeTag1] = {color1, background, background},
    [SchemeTag2] = {color3, background, background},
    [SchemeTag3] = {color4, background, background},
    [SchemeTag4] = {color2, background, background},
    [SchemeTag5] = {color5, background, background},
    [SchemeLayout] = {color4, background, background},
    [SchemeBtnPrev] = {color4, background, background},
    [SchemeBtnNext] = {color6, background, background},
    [SchemeBtnClose] = {color2, background, background},
};

/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
    {"color1", STRING, &color1},         {"color2", STRING, &color2},
    {"color3", STRING, &color3},         {"color4", STRING, &color4},
    {"color5", STRING, &color5},         {"color6", STRING, &color6},
    {"color7", STRING, &color7},         {"color8", STRING, &color8},
    {"background", STRING, &background},
};

/* tagging */
static char *tags[] = {"󰞷", "󰈹", "󰉋", "󰭹", "󰿎"};
/* static char *tags[] = { "  ", "  ", "  ", "  ", "  "}; */

static const int tagschemes[] = {SchemeTag1, SchemeTag2, SchemeTag3, SchemeTag4,
                                 SchemeTag5};

static const unsigned int ulinepad =
    5; /* horizontal padding between the underline and tag */
static const unsigned int ulinestroke =
    2; /* thickness / height of the underline */
static const unsigned int ulinevoffset =
    0; /* how far above the bottom of the bar the line should appear */
static const int ulineall =
    0; /* 1 to show underline on all tags, 0 for just the active ones */

static const char scratchpadname[] = "scratchpad";
static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      instance    title       tags mask     iscentered   isfloating
       monitor */
    {"Gimp", NULL, NULL, 0, 0, 1, -1},
    {"Brave", NULL, NULL, 2, 0, 0, -1},
    {"eww", NULL, NULL, 0, 0, 1, -1},
    {"Gnome-calculator", NULL, NULL, 0, 1, 1, -1},
    {"St", "Music", NULL, 0, 1, 1, -1},
    {"St", scratchpadname, NULL, 0, 1, 1, -1},
    {"Pcmanfm", NULL, NULL, 1 << 2, 0, 0, -1},
    {NULL, "telegram-desktop", NULL, 1 << 3, 0, 0, -1},
};

/* layout(s) */
static const float mfact = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;    /* number of clients in master area */
static const int resizehints =
    0; /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen =
    1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT                                                           \
  1 /* nrowgrid layout: force two clients to always split vertically */
#include "functions.h"

static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[]=", tile}, /* first entry is default */
    {":::", gaplessgrid}, {">M>", centeredfloatingmaster}, {"[M]", monocle},
    {"><>", NULL}, /* no layout function means floating behavior */

    // Extra
    // =====
    /* { "[@]",      spiral }, */
    /* { "[\\]",     dwindle }, */
    /* { "H[]",      deck }, */
    /* { "TTT",      bstack }, */
    /* { "===",      bstackhoriz }, */
    /* { "HHH",      grid }, */
    /* { "###",      nrowgrid }, */
    /* { "---",      horizgrid }, */
    /* { "|M|",      centeredmaster }, */
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                                      \
  {MODKEY, KEY, view, {.ui = 1 << TAG}},                                       \
      {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}},               \
      {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}},                        \
      {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                                             \
  {                                                                            \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                       \
  }

/* commands */
static char dmenumon[2] =
    "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {"dmenu_run", "-l", "5", "-z", "300", NULL};
static const char *termcmd[] = {"st", NULL}; // change this to your term
static const char *scratchpadcmd[] = {"st", "-t",     scratchpadname,
                                      "-g", "120x34", NULL};

static Key keys[] = {
    /* modifier               key        function        argument */
    {MODKEY, XK_p, spawn, {.v = dmenucmd}},
    {MODKEY, XK_Return, spawn, {.v = termcmd}},
    {MODKEY, XK_grave, togglescratch, {.v = scratchpadcmd}},
    {MODKEY, XK_b, togglebar, {0}},
    {MODKEY | ControlMask, XK_w, tabmode, {-1}},
    {MODKEY, XK_j, focusstack, {.i = +1}},
    {MODKEY, XK_k, focusstack, {.i = -1}},
    {MODKEY, XK_i, incnmaster, {.i = +1}},
    {MODKEY, XK_d, incnmaster, {.i = -1}},
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    {MODKEY | ShiftMask, XK_h, setcfact, {.f = +0.25}},
    {MODKEY | ShiftMask, XK_l, setcfact, {.f = -0.25}},
    {MODKEY | ShiftMask, XK_o, setcfact, {.f = 0.00}},
    {MODKEY | ShiftMask, XK_j, movestack, {.i = +1}},
    {MODKEY | ShiftMask, XK_k, movestack, {.i = -1}},
    {MODKEY, XK_Return, zoom, {0}},
    {MODKEY, XK_Tab, view, {0}},

    // overall gaps
    {MODKEY | ControlMask, XK_i, incrgaps, {.i = +1}},
    {MODKEY | ControlMask, XK_d, incrgaps, {.i = -1}},

    // inner gaps
    {MODKEY | ShiftMask, XK_i, incrigaps, {.i = +1}},
    {MODKEY | ControlMask | ShiftMask, XK_i, incrigaps, {.i = -1}},

    // outer gaps
    {MODKEY | ControlMask, XK_o, incrogaps, {.i = +1}},
    {MODKEY | ControlMask | ShiftMask, XK_o, incrogaps, {.i = -1}},

    {MODKEY | ControlMask, XK_6, incrihgaps, {.i = +1}},
    {MODKEY | ControlMask | ShiftMask, XK_6, incrihgaps, {.i = -1}},
    {MODKEY | ControlMask, XK_7, incrivgaps, {.i = +1}},
    {MODKEY | ControlMask | ShiftMask, XK_7, incrivgaps, {.i = -1}},
    {MODKEY | ControlMask, XK_8, incrohgaps, {.i = +1}},
    {MODKEY | ControlMask | ShiftMask, XK_8, incrohgaps, {.i = -1}},
    {MODKEY | ControlMask, XK_9, incrovgaps, {.i = +1}},
    {MODKEY | ControlMask | ShiftMask, XK_9, incrovgaps, {.i = -1}},

    /* { MODKEY|ControlMask,            XK_t,      togglegaps,     {0} }, */
    {MODKEY | ControlMask | ShiftMask, XK_d, defaultgaps, {0}},

    {MODKEY, XK_q, killclient, {0}},
    {MODKEY | ShiftMask, XK_t, setlayout, {.v = &layouts[0]}}, // Tiling
    {MODKEY | ShiftMask, XK_m, setlayout, {.v = &layouts[3]}}, // Monocole
    {MODKEY | ShiftMask,
     XK_c,
     setlayout,
     {.v = &layouts[2]}}, // Centered floating
    {MODKEY | ShiftMask, XK_g, setlayout, {.v = &layouts[1]}}, // Grid View
    {MODKEY | ShiftMask, XK_f, setlayout, {.v = &layouts[4]}}, // Floating
    {MODKEY, XK_space, setlayout, {0}},
    {MODKEY | ControlMask, XK_comma, cyclelayout, {.i = -1}},
    {MODKEY | ControlMask, XK_period, cyclelayout, {.i = +1}},
    {MODKEY | ShiftMask, XK_space, togglefloating, {0}},
    {MODKEY, XK_f, togglefullscr, {0}},
    {MODKEY, XK_0, view, {.ui = ~0}},
    {MODKEY | ShiftMask, XK_0, tag, {.ui = ~0}},
    {MODKEY, XK_comma, focusmon, {.i = -1}},
    {MODKEY, XK_period, focusmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_comma, tagmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_period, tagmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_minus, setborderpx, {.i = -1}},
    {MODKEY | ShiftMask, XK_p, setborderpx, {.i = +1}},
    {MODKEY | ShiftMask, XK_w, setborderpx, {.i = default_border}},

    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3)
        TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5) TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7)
            TAGKEYS(XK_9, 8)

                {MODKEY | ControlMask, XK_q, quit, {0}},
    {MODKEY | ShiftMask, XK_r, quit, {1}},
    {MODKEY | ShiftMask, XK_F5, xrdb, {.v = NULL}},
    {MODKEY, XK_e, hidewin, {0}},
    {MODKEY | ShiftMask, XK_e, restorewin, {0}},
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function argument
     */
    {ClkLtSymbol, 0, Button1, cyclelayout, {.i = +1}},
    {ClkLtSymbol, 0, Button3, cyclelayout, {.i = +1}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button2, spawn, {.v = termcmd}},

    /* Keep movemouse? */
    /* { ClkClientWin,         MODKEY,         Button1,        movemouse, {0}
       }, */

    /* placemouse options, choose which feels more natural:
     *    0 - tiled position is relative to mouse cursor
     *    1 - tiled postiion is relative to window center
     *    2 - mouse pointer warps to window center
     *
     * The moveorplace uses movemouse or placemouse depending on the floating
     * state of the selected client. Set up individual keybindings for the two
     * if you want to control these separately (i.e. to retain the feature to
     * move a tiled window into a floating position).
     */
    {ClkClientWin, MODKEY, Button1, moveorplace, {.i = 0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkClientWin, ControlMask, Button1, dragmfact, {0}},
    {ClkClientWin, ControlMask, Button3, dragcfact, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
    {ClkTabBar, 0, Button1, focuswin, {0}},
    {ClkTabBar, 0, Button1, focuswin, {0}},
    {ClkTabPrev, 0, Button1, movestack, {.i = -1}},
    {ClkTabNext, 0, Button1, movestack, {.i = +1}},
    {ClkTabClose, 0, Button1, killclient, {0}},
};
