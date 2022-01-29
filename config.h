/* See LICENSE file for copyright and license details. */

/* Constants */
#define TERMINAL "st"
#define TERMCLASS "St"

/* appearance */
static unsigned int borderpx  = 3;        /* border pixel of windows */
static unsigned int snap      = 32;       /* snap pixel */
static unsigned int gappih    = 20;       /* horiz inner gap between windows */
static unsigned int gappiv    = 20;       /* vert inner gap between windows */
static unsigned int gappoh    = 20;       /* horiz outer gap between windows and screen edge */
static unsigned int gappov    = 20;       /* vert outer gap between windows and screen edge */
static int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */

static const int user_bh      = 34;        /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */

static const int vertpad            = 0;       /* vertical padding of bar */
static const int sidepad            = 0;       /* horizontal padding of bar */
static int showbar            = 1;        /* 0 means no bar */
static int topbar             = 1;        /* 0 means bottom bar */
static char *fonts[]          = { "JetBrainsMono Nerd Font:pixelsize=13:antialias=true:autohint=true", "JetBrainsMono Nerd Font:pixelsize=13:antialias=true:autohint=true"  };



/* Nord Colour Schemes */

static char sch_norm_fg[] = "#575268";
static char sch_norm_bg[] = "#1e1e2e";
static char sch_norm_border[] = "#4c566a";

static char sch_focused_fg[] = "#88C0D0";
static char sch_focused_bg[] = "#1e1e2e";
static char sch_focused_border[] = "#c9cbff";

static char sch_status_fg[] = "#88C0D0";
static char sch_status_bg[] = "#1e1e2e";

static char sch_tagfocused_fg[] = "#8FBCBB";
static char sch_tagfocused_bg[] = "#1e1e2e";

static char sch_tagnorm_fg[] = "#c9cbff";
static char sch_tagnorm_bg[] = "#1e1e2e";

static char sch_infofocused_fg[] = "#EBCB8B";
static char sch_infofocused_bg[] = "#1e1e2e";

static char sch_infonorm_fg[] = "#c9cbff";
static char sch_infonorm_bg[] = "#1e1e2e";

static char colour_a[] = "#c9cbff";
static char main_dark[] = "#1e1e2e"; // polar_a_darker
static char dark_light[] = "#576277"; // polar_d_lighter


static char *colors[][3] = {
       /*              		fg           bg           border   */
       [SchemeNorm] 	= { sch_norm_fg,         sch_norm_bg,       sch_norm_border  },   /* Non-focused border */
       [SchemeSel]  	= { sch_focused_fg,      sch_focused_bg,    sch_focused_border      },       /* Focused border */
       [SchemeStatus]  	= { sch_status_fg,       sch_status_bg,     "#000000"  }, // Statusbar right {text,background,not used but cannot be empty}
       [SchemeTagsSel]  = { sch_tagfocused_fg,   sch_tagfocused_bg, "#000000"  }, // Tagbar left selected {text,background,not used but cannot be empty}
       
       //left layout icon--
       [SchemeTagsNorm] = { sch_tagnorm_fg,      sch_tagnorm_bg,    "#000001"  }, // Tagbar left unselected {text,background,not used but cannot be empty}
       [SchemeInfoSel]  = { sch_infofocused_fg,  sch_infofocused_bg,"#000000"  }, // infobar middle  selected {text,background,not used but cannot be empty}
       [SchemeInfoNorm] = { sch_infonorm_fg,     sch_infonorm_bg,   "#000000"  }, // infobar middle  unselected {text,background,not used but cannot be empty}

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
static const char *tagsalt[] = { "", "", "", "", "", "", "", "", "" };
static const int momentaryalttags = 0; /* 1 means alttags will show only when key is held down*/

static const char *tagsel[][2] = {
	/* focused-colour	focused-bg*/
	{ colour_a,		main_dark},
	{ colour_a,		main_dark},
	{ colour_a,		main_dark},
	{ colour_a,		main_dark},
	{ colour_a,		main_dark},
	{ colour_a,		main_dark},
	{ colour_a,		main_dark},
	{ colour_a,		main_dark},
	{ colour_a,		main_dark},
};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	*/
	/* class    instance      title       	 tags mask    isfloating   isterminal  noswallow  monitor */
	{ "Gimp",     NULL,       NULL,       	    1 << 8,       0,           0,         0,        -1 },
	{ TERMCLASS,  NULL,       NULL,       	    0,            0,           1,         0,        -1 },
	{ NULL,       NULL,       "Event Tester",   0,            0,           0,         1,        -1 },
	{ NULL,      "spterm",    NULL,       	    SPTAG(0),     1,           1,         0,        -1 },
	{ NULL,      "spcalc",    NULL,       	    SPTAG(1),     1,           1,         0,        -1 },
};

/* layout(s) */
static float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static int nmaster     = 1;    /* number of clients in master area */
static int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "",	      tile },				    /* Default: Master on left, slaves on right */
	
	{ "[BS]",	  bstack },			        /* Master on top, slaves on bottom */
	
	{ "[G]", 	  gaplessgrid },		    /* Equally sized grids  */

	{ "[Fib]",	  spiral },			        /* Fibonacci spiral */
	
	/* { "Dwindle",	dwindle },		 Decreasing in size right and leftward */

	{ "[||]",	  deck },				    /* Master on left, slaves in monocle-like mode on right */
	
	{ "[M]",	  monocle },			    /* All windows on top of eachother */

	{ "[CM]",	  centeredmaster },		    /* Master in middle, slaves on sides */
	
	{ "[CFM]",	  centeredfloatingmaster },	/* Same but master floats */

	{ "><>",	  NULL },				    /* no layout function means floating behavior */
	
	{ NULL,		  NULL },
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
	/* { MOD, XK_x,     ACTION##stack, {.i = 0 } }, */

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[]  = { TERMINAL, NULL };

ResourcePref resources[] = {
        
        /*
         * colours
        */
		{ "color0",		STRING,	&sch_norm_fg },
		{ "color1",		STRING,	&sch_norm_bg },
		{ "color2",		STRING,	&sch_norm_border },
		{ "color3",		STRING,	&sch_focused_fg },
		{ "color4",		STRING,	&sch_focused_bg },
		{ "color5",		STRING,	&sch_focused_border },
		{ "color6",		STRING,	&sch_status_fg },
		{ "color7",		STRING,	&sch_status_bg },
		{ "color8",		STRING,	&sch_tagfocused_fg },
		{ "color9",		STRING,	&sch_tagfocused_bg },
		{ "color10",		STRING,	&sch_tagnorm_fg },
		{ "color11",		STRING,	&sch_tagnorm_bg },
		{ "color12",		STRING,	&sch_infofocused_fg },
		{ "color13",		STRING,	&sch_infofocused_bg },
		{ "color14",		STRING,	&sch_infonorm_fg },
		{ "color15",		STRING,	&sch_infonorm_bg },
		{ "color16",		STRING,	&colour_a },
		{ "color17",		STRING,	&main_dark },
		{ "color18",		STRING,	&dark_light },
		
		
		{ "borderpx",   INTEGER, &borderpx },
		{ "mfact",		FLOAT,	&mfact },
};

#include <X11/XF86keysym.h>
#include "shiftview.c"

static Key keys[] = {
	/* modifier                      key               function             argument */
	STACKKEYS(MODKEY,           focus)
	STACKKEYS(MODKEY|ShiftMask, push)
	
	TAGKEYS(    XK_1,    0)
	TAGKEYS(    XK_2,    1)
	TAGKEYS(    XK_3,    2)
	TAGKEYS(    XK_4,    3)
	TAGKEYS(    XK_5,    4)
	TAGKEYS(    XK_6,    5)
	TAGKEYS(    XK_7,    6)
	TAGKEYS(    XK_8,    7)
	TAGKEYS(    XK_9,    8)
	
	//a
	{ MODKEY | ShiftMask,                       XK_a,            togglealttag,   	     {0} },	
	{ MODKEY,                       XK_a,            spawn,   	             SHCMD("~/.dwm/./agility.sh") },

	//b
	{ MODKEY,                       XK_b,            spawn,   	             SHCMD("brave") },
	
	//c
	{ MODKEY,                       XK_o,            togglealwaysontop,   	 {0} },	/* Tag a floating client to remain on top */
	
	//d
	{ MODKEY,                       XK_d,            spawn,   	             SHCMD("rofi -show run") },
	{ MODKEY|ShiftMask,             XK_d,            spawn,   	             SHCMD("dmenu_run") },
	
	//e
	{ MODKEY,                       XK_e,            spawn,   	             SHCMD("python ~/.dwm/ebooks.py") },
	
	//f
	{ MODKEY,                       XK_f,            togglefullscr,          {0} },
	{ MODKEY|ShiftMask,             XK_f,            setlayout,              {.v = &layouts[8]} },
	
	//g
	{ MODKEY|ShiftMask,             XK_g,            spawn,                  SHCMD("dm-tool switch-to-greeter") },
	
	//h
	{ MODKEY,                       XK_h,            setmfact,               {.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_h,            setcfact,               {.f = +0.25} },
		
	//i
	
	
	//--j--
	//focuses stack
	
	//--k--
	//focuses stack
	
	//l
	{ MODKEY,                       XK_l,            setmfact,               {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_l,            setcfact,               {.f = -0.25} },
	
	//m
	{ MODKEY,                       XK_m,            incnmaster,             {.i = +1 } },		/* Increment num. masters */
	{ MODKEY|ShiftMask,             XK_m,            incnmaster,             {.i = -1 } },	/* Decrement num. masters */
	
	//n
	
	{ MODKEY,                       XK_n,            togglegaps,             {0} },
	{ MODKEY|ShiftMask,             XK_n,            defaultgaps,            {0} },
	
	//o
	{ MODKEY|ControlMask,           XK_c,            togglesticky,		     {0} },
	
	//p
	{ MODKEY,                       XK_p,            view,                   {0} },		/* Previous tag */
	
	//q
	{ MODKEY,                       XK_q,            togglebar,              {0} },		/* Toggle bar */
	
	//r
	{ MODKEY,                       XK_r,            spawn,                  SHCMD("~/.dwm/./connect_bt.sh") },
	{ MODKEY|ShiftMask,             XK_r,            setcfact,               {.f =  0.00} },
	
	//s
	{ MODKEY,                       XK_s,            spawn,                  SHCMD("~/.dwm/./mouse_sens.sh") }, /* Mouse sensitivity */
	{ MODKEY|ControlMask,           XK_s,            spawn,                  SHCMD("~/.dwm/./swap_capslock") },
	
	//t
	{ MODKEY|ControlMask,           XK_t,            togglefloating,         {0} },
	
	//u
	{ MODKEY,                       XK_u,            spawn,                  SHCMD("pavucontrol") },
	{ MODKEY|ControlMask,           XK_u,            spawn,                  SHCMD("pkill pipewire") },
	
	//v
	
	
	//w
	{ MODKEY,                       XK_w,            killclient,             {0} },		/* Kill client */
	
	//x
	
	//y
	
	
	//z
	{ MODKEY,                       XK_z,            incrgaps,               {.i = +3 } },		/* Increase gaps */
	{ MODKEY|ControlMask,           XK_z,            incrgaps,               {.i = -3 } },	/* Decrease gaps */
	
	//F-KEYS
	{ MODKEY,                       XK_F9,           setlayout,              {.v = &layouts[0]} }, /* tile */
	{ MODKEY|ShiftMask,             XK_F9,           setlayout,              {.v = &layouts[1]} }, /* bstack */
	{ MODKEY,                       XK_F10,          setlayout,              {.v = &layouts[2]} }, /* gapless grid */
	{ MODKEY|ShiftMask,             XK_F10,          setlayout,              {.v = &layouts[3]} }, /* spiral */
	{ MODKEY,                       XK_F11,          setlayout,              {.v = &layouts[4]} }, /* deck */
	{ MODKEY|ShiftMask,             XK_F11,          setlayout,              {.v = &layouts[5]} }, /* monocle */
	{ MODKEY,                       XK_F12,          setlayout,              {.v = &layouts[6]} }, /* centeredmaster */
	{ MODKEY|ShiftMask,             XK_F12,          setlayout,              {.v = &layouts[7]} }, /* centeredfloatingmaster */
	{ MODKEY,                       XK_F5,           spawn,                  SHCMD("reboot") }, 					/*reboot*/
	{ MODKEY|ShiftMask,             XK_F1,           spawn,                  SHCMD("systemctl poweroff") }, 		/*shutdown*/
	
	//-SYMBOLS
    { 0,                            XK_Print,        spawn,                  SHCMD("maim -s | xclip -selection clipboard -t image/png") },
	{ MODKEY,                       XK_Print,        spawn,                  SHCMD("~/.dwm/./maimpick") },

	{ MODKEY,                       XK_minus,        spawn,                  SHCMD("pamixer --allow-boost -d 5; kill -44 $(pidof dwmblocks)") },
	{ MODKEY|ShiftMask,             XK_minus,        spawn,                  SHCMD("pamixer --allow-boost -d 15; kill -44 $(pidof dwmblocks)") },
	{ MODKEY,                       XK_equal,        spawn,                  SHCMD("pamixer --allow-boost -i 5; kill -44 $(pidof dwmblocks)") },
	{ MODKEY|ShiftMask,             XK_equal,        spawn,                  SHCMD("pamixer --allow-boost -i 15; kill -44 $(pidof dwmblocks)") },
	
	{ MODKEY,                       XK_backslash,    spawn,                  SHCMD("lf") },
	{ MODKEY|ControlMask,           XK_backslash,    spawn,                  SHCMD("thunar") },
	
	{ MODKEY,                       XK_Tab,          focusmaster,            {0} },

	{ MODKEY,                       XK_space,        zoom,                   {0} },
	
	{ MODKEY,                       XK_semicolon,    shiftview,              { .i = -1 } },		/* Cycle thru tags - cw */
	{ MODKEY|ShiftMask,             XK_semicolon,    shifttag,               { .i = -1 } },	/* Send focused client to next tag - cw */
	{ MODKEY,                       XK_apostrophe,   shiftview,              { .i = 1 } },		// Cycle thru tags - anti-cw
	{ MODKEY|ShiftMask,             XK_apostrophe,   shifttag,               { .i = 1 } },	// Send client to prev. tag - anti-cw
	
	{ MODKEY,                       XK_Return,       spawn,                  {.v = termcmd } },		/* Spawn terminal */

	{ MODKEY,                       XK_0,            view,                   {.ui = ~0 } },			/* View all tags then choose */
	{ MODKEY|ShiftMask,             XK_0,            tag,                    {.ui = ~0 } },		/* ^ but send client to chosen tag */
	{ MODKEY,                       XK_comma,        focusmon,               {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_comma,        tagmon,                 {.i = -1 } },
	{ MODKEY,                       XK_period,       focusmon,               {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_period,       tagmon,                 {.i = +1 } },
	{ MODKEY,                       XK_slash,        spawn,                  SHCMD("~/.dwm/./rl_jar.sh") },
	{ MODKEY|ControlMask,           XK_slash,        spawn,                  SHCMD("~/.dwm/./rl.sh") },

	/* J and K are bound above in STACKEYS */
	/* V is automatically bound above in STACKKEYS */
	
	{ 0, XF86XK_AudioMute,          spawn,           SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioRaiseVolume,   spawn,           SHCMD("pamixer --allow-boost -i 3; kill -44 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioLowerVolume,	spawn,           SHCMD("pamixer --allow-boost -d 3; kill -44 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioPrev,          spawn,           SHCMD("mpc prev") },
	{ 0, XF86XK_AudioNext,          spawn,           SHCMD("mpc next") },
	{ 0, XF86XK_AudioPause,         spawn,           SHCMD("mpc pause") },
	{ 0, XF86XK_AudioPlay,          spawn,           SHCMD("mpc play") },
	{ 0, XF86XK_AudioStop,          spawn,           SHCMD("mpc stop") },

	
	
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
#ifndef __OpenBSD__
	
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
	{ ClkClientWin,		    MODKEY,		    Button4,	    incrgaps,	    {.i = +1} },
	{ ClkClientWin,		    MODKEY,		    Button5,	    incrgaps,	    {.i = -1} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkTagBar,		    0,		        Button4,	    shiftview,	    {.i = -1} },
	{ ClkTagBar,		    0,		        Button5,	    shiftview,	    {.i = 1} },
	{ ClkRootWin,		    0,		        Button2,	    togglebar,	    {0} },
};
