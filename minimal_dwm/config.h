#define TERMINAL "kitty"
#define TERMCLASS "kitty"
#define BROWSER "brave"

static unsigned int borderpx  = 2;        /* border pixel of windows */
static unsigned int snap      = 16;       /* snap pixel */
static unsigned int gappih    = 10;       /* horiz inner gap between windows */
static unsigned int gappiv    = 10;       /* vert inner gap between windows */
static unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static int showbar            = 1;        /* 0 means no bar */
static int topbar             = 1;        /* 0 means bottom bar */

static char *fonts[] = {
        // "JetBrainsMono Nerd Font:size=12:antialias=true:autohint=true",
        "FuraMono Nerd Font:pixelsize=14:antialias=true:autohint=true",
        "Siji:pixelsize=12",
        "Noto Color Emoji:pixelsize=12",
};

static char normfgcolor[]           = "#bbbbbb";
static char normbgcolor[]           = "#222222";

static char normbordercolor[]       = "#444444";
static char selfgcolor[]            = "#eeeeee";
static char selbordercolor[]        = "#005577";
static char selbgcolor[]            = "#005577";
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {TERMINAL, "-n", "spterm", "-g", "120x34", NULL };
const char *spcmd2[] = {TERMINAL, "-n", "spcalc", "-f", "monospace:size=16", "-g", "50x20", "-e", "bc", "-lq", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",      spcmd1},
	{"spcalc",      spcmd2},
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	*/
	/* class    instance      title       	 tags mask    isfloating   isterminal  noswallow  monitor */
	// { "Gimp",     NULL,       NULL,       	    1 << 8,       0,           0,         0,        -1 },
	// { TERMCLASS,  NULL,       NULL,       	    0,            0,           1,         0,        -1 },
	// { NULL,       NULL,       "Event Tester",   0,            0,           0,         1,        -1 },
	// { TERMCLASS,      "floatterm", NULL,       	    0,       1,           1,         0,        -1 },
	// { TERMCLASS,      "bg",        NULL,       	    1 << 7,       0,           1,         0,        -1 },
	// { TERMCLASS,      "spterm",    NULL,       	    SPTAG(0),     1,           1,         0,        -1 },
	{ TERMCLASS,      "spcalc",    NULL,       	    SPTAG(1),     1,           1,         0,        -1 },
};

/* layout(s) */
static float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static int nmaster     = 1;    /* number of clients in master area */
static int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "  ",	tile },			/* Default: Master on left, slaves on right */
	{ "  ",	deck },			/* Master on left, slaves in monocle-like mode on right */
	{ " 󰚄 ",	monocle },		/* All windows on top of eachother */

	{ "|M|",	centeredmaster },		/* Master in middle, slaves on sides */
	{ "TTT",	bstack },		/* Master on top, slaves on bottom */

	{ "  ",	NULL },			/* no layout function means floating behavior */
	{ NULL,		NULL },
};

/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
    { "color0",		STRING,	&normbordercolor },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define STACKKEYS(MOD,ACTION) \
	{ MOD,	XK_j,	ACTION##stack,	{.i = INC(+1) } }, \
	{ MOD,	XK_k,	ACTION##stack,	{.i = INC(-1) } }, \
	{ MOD,  XK_v,   ACTION##stack,  {.i = 0 } }, \
	/* { MOD, XK_grave, ACTION##stack, {.i = PREVSEL } }, \ */
	/* { MOD, XK_a,     ACTION##stack, {.i = 1 } }, \ */
	/* { MOD, XK_z,     ACTION##stack, {.i = 2 } }, \ */
	/* { MOD, XK_x,     ACTION##stack, {.i = -1 } }, */

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[]  = { TERMINAL, NULL };


#include <X11/XF86keysym.h>
#include "shiftview.c"

/**************************************/
/**** Extra Defs -- for modularity ****/
/**************************************/
#define SCRIPTDIR        "~/.dwm/"
#define SCRIPTCMD(cmd)   { .v = (const char*[]){ "/bin/sh", "-c", SCRIPTDIR cmd, NULL         } }
#define SHCMD(cmd)       { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL                   } }

// #define TERMCMD(...)     { .v = (const char*[]){ "st", "-e", __VA_ARGS__, NULL                } }
// #define TERMSHCMD(cmd)   { .v = (const char*[]){ "st", "-e", "dash", "-c", cmd, NULL          } }

#define REDSHIFT(arg)    { .v = (const char*[]){ "redshift", "-PO" arg, NULL                  } }
#define REDSHIFTDEFAULT  { .v = (const char*[]){ "redshift", "-x", NULL                       } }

#define ROFIDRUN         { .v = (const char*[]){ "rofi", "-show", "drun", "-show-icons", NULL } }
#define ROFIRUN          { .v = (const char*[]){ "rofi", "-show", "run", NULL } }
#define ROFICALC         { .v = (const char*[]){ "rofi", "-show", "calc", "-modi", "calc", "-no-show-match", "-no-sort", NULL} }

#define PLAYERT          { .v = (const char*[]){ "playerctl", "play-pause", NULL              } }
#define PLAYERP          { .v = (const char*[]){ "playerctl", "previous", NULL                } }
#define PLAYERN          { .v = (const char*[]){ "playerctl", "next", NULL                    } }

#define TOGGLEVPN       SHCMD("killall -INT riseup-vpn 2>/dev/null || riseup-vpn --start-vpn on")
#define PAMIXER(cmd)    SHCMD("pamixer " cmd "; pkill -RTMIN+22 $STATUSBAR")


static const Key keys[] = {
	/* modifier                     key        function        argument */
	STACKKEYS(MODKEY,                          focus)
	STACKKEYS(MODKEY|ShiftMask,                push)
	TAGKEYS(			XK_1,		0)
	TAGKEYS(			XK_2,		1)
	TAGKEYS(			XK_3,		2)
	TAGKEYS(			XK_4,		3)
	TAGKEYS(			XK_5,		4)
	TAGKEYS(			XK_6,		5)
	TAGKEYS(			XK_7,		6)
	TAGKEYS(			XK_8,		7)
	TAGKEYS(			XK_9,		8)

    // a
    { MODKEY,              XK_a,                     togglegaps,         {0} },
    { MODKEY|ShiftMask,    XK_a,                     defaultgaps,        {0} },

    // b
    { MODKEY,              XK_b,                     spawn,              SHCMD("brave") },

    // c
    { MODKEY,              XK_c,                     spawn,              SCRIPTCMD("color_under_cursor.sh") },
    { MODKEY|ControlMask,  XK_c,                     spawn,              ROFICALC },

    // d
    { MODKEY,              XK_d,                     spawn,              ROFIRUN },

    // e
    
    
    
    // f
    { MODKEY,              XK_f,                     togglefullscr,   {0} },
    
    // g
    { MODKEY|ShiftMask,    XK_g,                     spawn,              SHCMD("slock; musicctl pause") },


    // i
    { MODKEY,              XK_i,                     incrgaps,           {.i = +1 } },
    { MODKEY|ShiftMask,    XK_i,                     incrgaps,           {.i = -1 } },


    // h --
    // j --
    // k -- 
    // l --
    { MODKEY,              XK_h,                     setmfact,           {.f = -0.05} },
    { MODKEY,              XK_l,                     setmfact,           {.f = +0.05} },

    // m
    { MODKEY,			   XK_m,                     view,		         {0} },

    // n

    // o
	{ MODKEY,              XK_o,                     incnmaster,         {.i = +1 } },
	{ MODKEY|ShiftMask,    XK_o,                     incnmaster,         {.i = -1 } },

    // p
    {MODKEY,               XK_p,                     view,               {0} }, // last active tag


    // q /** not patched **/
    { MODKEY|ShiftMask,    XK_q,                     quit,               {0} }, // quit dwm
    { MODKEY|ControlMask,  XK_q,                     quit,               {1} }, // restart dwm


    // r /** not patched **/
    {MODKEY,               XK_r,                     reorganizetags,     {0} },


    // s
    {MODKEY,               XK_s,                     spawn,              SHCMD("st -e tmux new-session nnn -a -P p") },

    // t
    { MODKEY,              XK_t,                     setlayout,          {.v = &layouts[0]} }, // set layout back to tile from whatever

    // u
    // RESTART BLUTOOTH etc
    { MODKEY,              XK_u,                     spawn,              SHCMD("pavucontrol") },
    
    
    // v
    // Already bind to `focus master`
    
    // w
    { MODKEY,              XK_w,                     killclient,         {0} },
    
    // x
    { MODKEY,              XK_x,                     spawn,              SHCMD("~/.config/Obsidian/Obsidian-1.1.16.AppImage") },
    
    // y
    
    // z
    { MODKEY,              XK_z,                     spawn,              SCRIPTCMD("mouse_sens.sh") },
    


	{ MODKEY,			XK_Return,	spawn,		{.v = termcmd } },


	/* V is automatically bound above in STACKKEYS */
    // ^ focuses master
    

    /****************/
    /**** F-Keys ****/
    /****************/

    // { MODKEY,              XK_F1,                    mpdchange,          {.i = -1} },
    // { MODKEY,              XK_F2,                    mpdchange,          {.i = +1} },
    { MODKEY,              XK_F4,                    spawn,              SHCMD("terminal -e pulsemixer; pkill -RTMIN+22 $STATUSBAR") },
    { MODKEY,              XK_F9,                    cyclelayout,        {.i = -1 } },
    { MODKEY,              XK_F10,                   cyclelayout,        {.i = +1 } },


    /**********************/
    /**** Special Keys ****/
    /**********************/

    { MODKEY,              XK_semicolon,             shiftview,   { .i = -1 } }, 
    { MODKEY,              XK_apostrophe,            shiftview,   { .i = +1 } },

    // - monitor
    { MODKEY,              XK_comma,                 focusmon,           {.i = -1 } },
    { MODKEY,              XK_period,                focusmon,           {.i = +1 } },
    { MODKEY|ShiftMask,    XK_comma,                 tagmon,             {.i = -1 } },
    { MODKEY|ShiftMask,    XK_period,                tagmon,             {.i = +1 } },
    
    { MODKEY,              XK_slash,                 spawn,              SCRIPTCMD("rl_jar.sh") },
    { MODKEY,              XK_backslash,             spawn,              SHCMD("pcmanfm") },

    // { MODKEY,              XK_Escape,                mpdcontrol,         {0} },
    { MODKEY|ShiftMask,    XK_space,                 togglefloating,     {0} }, 

    // - expands current window
	// { MODKEY,			XK_Tab,		view,		{0} },
    
    // - swap client with master
    { MODKEY,              XK_space,                 zoom,               {0} },
    
    // - screenshot
    { 0,                   XK_Print,                 spawn,              SCRIPTCMD("ss_selection.sh") },
    { MODKEY,              XK_Print,                 spawn,              SCRIPTCMD("maimpick") },

    /********************************/
    /**** Keyboard Media Control ****/
    /********************************/

    /* volume section needs to have signal "10" for this to work since we need +34 to call */
    { MODKEY,              XK_minus,                 spawn,              SHCMD("pamixer --allow-boost -d 5; ~/.dwm/volume.sh; ~/.dwm/kill_vol.sh")   },
    { MODKEY|ShiftMask,    XK_minus,                 spawn,              SHCMD("pamixer --allow-boost -d 15; ~/.dwm/volume.sh; ~/.dwm/kill_vol.sh)") },
    { MODKEY,              XK_equal,                 spawn,              SHCMD("pamixer --allow-boost -i 5; ~/.dwm/volume.sh; ~/.dwm/kill_vol.sh")   },
    { MODKEY|ShiftMask,    XK_equal,                 spawn,              SHCMD("pamixer --allow-boost -i 15; ~/.dwm/volume.sh; ~/.dwm/kill_vol.sh")  },
    { 0,                   XF86XK_AudioMute,         spawn,              SHCMD("pamixer -t; ~/.dwm/kill_vol.sh") },
     
    { 0,                   XF86XK_AudioRaiseVolume,  spawn,              SHCMD("pamixer --allow-boost -i 3; ~/.dwm/volume.sh; ~/.dwm/kill_vol.sh") },
    { 0,                   XF86XK_AudioLowerVolume,  spawn,              SHCMD("pamixer --allow-boost -d 3; ~/.dwm/volume.sh; ~/.dwm/kill_vol.sh") },
     
    { 0,                   XF86XK_AudioPrev,         spawn,              SHCMD("musicctl prev") },
    { 0,                   XF86XK_AudioNext,         spawn,              SHCMD("musicctl next") },
    { 0,                   XF86XK_AudioPause,        spawn,              SHCMD("musicctl pause") },
    { 0,                   XF86XK_AudioPlay,         spawn,              SHCMD("musicctl play") },
    { 0,                   XF86XK_AudioStop,         spawn,              SHCMD("musicctl stop") },
    { 0,                   XF86XK_AudioRewind,       spawn,              SHCMD("musicctl seek -10") },
    { 0,                   XF86XK_AudioForward,      spawn,              SHCMD("musicctl seek +10") },
    { 0,                   XF86XK_AudioMicMute,      spawn,              SHCMD("toggle-mic") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
#ifndef __OpenBSD__
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
	{ ClkStatusText,        ShiftMask,      Button1,        sigdwmblocks,   {.i = 6} },
#endif
	{ ClkStatusText,        ShiftMask,      Button3,        spawn,          SHCMD(TERMINAL " -e nvim ~/.local/src/dwmblocks/config.h") },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        defaultgaps,	{0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkClientWin,		MODKEY,		Button4,	incrgaps,	{.i = +1} },
	{ ClkClientWin,		MODKEY,		Button5,	incrgaps,	{.i = -1} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkTagBar,		0,		Button4,	shiftview,	{.i = -1} },
	{ ClkTagBar,		0,		Button5,	shiftview,	{.i = 1} },
	{ ClkRootWin,		0,		Button2,	togglebar,	{0} },
};

