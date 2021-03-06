 /* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx = 0;     /* border pixel of windows */
static const unsigned int gappx    = 1;     /* border pixel of windows */
static const unsigned int snap     = 32;    /* snap pixel */
static const int showbar           = 1;     /* 0 means no bar */
static const int topbar            = 0;     /* 0 means bottom bar */
static const char *fonts[]         = { "Roboto Mono:size=14" };
static const char dmenufont[]      = "Roboto Mono:size=14";
static const char col_gray1[]      = "#0e111a";
static const char col_gray2[]      = "#0e111a";
static const char col_gray3[]      = "#c1c6da";
static const char col_gray4[]      = "#0e111a";
static const char col_cyan[]       = "#e393d6";
static const char *colors[][3]     = {
    /*                  fg         bg        border  */
    [SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
    [SchemeSel]  = { col_gray4, col_cyan,  col_gray2 },
};

/* staticstatus */
static const int statmonval = 0;

/* tagging */
static const char *tags[] = { "_", "_", "_", "_", "_" };

static const Rule rules[] = {
    /* xprop(1):
     *  WM_CLASS(STRING) = instance, class
     *  WM_NAME(STRING) = title
     */
    /* class     instance title    tags mask isfloating monitor */
    { "qemu",    NULL,    NULL,    0,        1,         -1}
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
    /* symbol   arrange function */
    { "[]=",    tile    }, /* first entry is default */
    { "><>",    NULL    }, /* no layout function means floating behavior */
    { "[M]",    monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,    view,       {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,    toggleview, {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,    tag,        {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,    toggletag,  {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2]              = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]        = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]         = { "st", NULL };
static const char *screenshot_area[] = { "/usr/bin/scrot", "-s", "/home/everly/Pictures/screenshots/%Y-%m-%d-%T.png", "-q", "90", "-f", "-e", "xclip -selection clipboard -t image/png -i $f", NULL };
static const char *screenshot_wind[] = { "/usr/bin/scrot", "-u", "/home/everly/Pictures/screenshots/%Y-%m-%d-%T.png", "-q", "90", "-e", "xclip -selection clipboard -t image/png -i $f", NULL };
static const char *upvol[]           = { "/usr/bin/amixer", "-q", "-D", "pulse", "sset", "Master", "5%+", NULL };
static const char *downvol[]         = { "/usr/bin/amixer", "-q", "-D", "pulse", "sset", "Master", "5%-", NULL };
static const char *ranger[]          = { "st", "ranger", NULL };
static const char *htop[]            = { "st", "htop", NULL };
static const char *playpause[]       = { "/usr/bin/playerctl", "play-pause", NULL };

static Key keys[] = {
    /* modifier             key           function        argument */
    { MODKEY,               XK_p,         spawn,          { .v = dmenucmd } },
    { MODKEY | ShiftMask,   XK_Return,    spawn,          { .v = termcmd } },
    { MODKEY,               XK_v,         togglebar,      { 0 } },
    { MODKEY,               XK_k,         focusstack,     { .i = +1 } },
    { MODKEY,               XK_l,         focusstack,     { .i = -1 } },
    { MODKEY,               XK_o,         incnmaster,     { .i = +1 } },
    { MODKEY,               XK_i,         incnmaster,     { .i = -1 } },
    { MODKEY,               XK_h,         setmfact,       { .f = -0.05 } },
    { MODKEY,               XK_j,         setmfact,       { .f = +0.05 } },
    { MODKEY,               XK_Return,    zoom,           { 0 } },
    { MODKEY,               XK_Tab,       view,           { 0 } },
    { MODKEY | ShiftMask,   XK_c,         killclient,     { 0 } },
    { MODKEY,               XK_a,         setlayout,      { .v = &layouts[0] } },
    { MODKEY,               XK_s,         setlayout,      { .v = &layouts[1] } },
    { MODKEY,               XK_d,         setlayout,      { .v = &layouts[2] } },
    { MODKEY,               XK_space,     setlayout,      { 0 } },
    { MODKEY | ShiftMask,   XK_space,     togglefloating, { 0 } },
    { MODKEY,               XK_0,         view,           { .ui = ~0 } },
    { MODKEY | ShiftMask,   XK_0,         tag,            { .ui = ~0 } },
    { MODKEY,               XK_comma,     focusmon,       { .i = +1 } },
    { MODKEY,               XK_period,    focusmon,       { .i = -1 } },
    { MODKEY | ShiftMask,   XK_comma,     tagmon,         { .i = +1 } },
    { MODKEY | ShiftMask,   XK_period,    tagmon,         { .i = -1 } },
    TAGKEYS(                XK_1,                         0)
    TAGKEYS(                XK_2,                         1)
    TAGKEYS(                XK_3,                         2)
    TAGKEYS(                XK_4,                         3)
    TAGKEYS(                XK_5,                         4)
    { MODKEY | ShiftMask,   XK_BackSpace, quit,           { 0 } },
    { MODKEY | ShiftMask,   XK_s,         spawn,          { .v = screenshot_area } },
    { MODKEY | ShiftMask,   XK_a,         spawn,          { .v = screenshot_wind } },
    { MODKEY,               XK_b,         spawn,          { .v = downvol } },
    { MODKEY,               XK_n,         spawn,          { .v = upvol } },
    { MODKEY,               XK_m,         spawn,          { .v = playpause } },
    { MODKEY,               XK_e,         spawn,          { .v = ranger } },
    { MODKEY,               XK_q,         spawn,          { .v = htop } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click         event mask  buttons  function        argument */
    { ClkLtSymbol,   0,          Button1, setlayout,      { 0 } }, 
    { ClkLtSymbol,   0,          Button3, setlayout,      { .v = &layouts[2] } },
    { ClkWinTitle,   0,          Button2, zoom,           { 0 } },
    { ClkStatusText, 0,          Button2, spawn,          { .v = termcmd } },
    { ClkClientWin,  MODKEY,     Button1, movemouse,      { 0 } },
    { ClkClientWin,  MODKEY,     Button2, togglefloating, { 0 } },
    { ClkClientWin,  MODKEY,     Button3, resizemouse,    { 0 } },
    { ClkTagBar,     0,          Button1, view,           { 0 } },
    { ClkTagBar,     0,          Button3, toggleview,     { 0 } },
    { ClkTagBar,     MODKEY,     Button1, tag,            { 0 } },
    { ClkTagBar,     MODKEY,     Button3, toggletag,      { 0 } },
};
