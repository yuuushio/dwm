/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx        = 2;   /* border pixel of windows */
static const unsigned int snap            = 16;  /* snap pixel */
static const int swallowfloating          = 0;   /* 1 means swallow floating windows by default */
static const unsigned int gappih          = 10;  /* horiz inner gap between windows */
static const unsigned int gappiv          = 10;  /* vert inner gap between windows */
static const unsigned int gappoh          = 10;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov          = 10;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact           = 1;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const int showbar                  = 1;   /* 0 means no bar */
static const int topbar                   = 1;   /* 0 means bottom bar */
static const int bar_height               = 40;  /* 0 means derive from font, >= 1 explicit height */
static const int statusmon                = -1;  /* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
static const int horizpadbar              = 0;   /* horizontal padding for statusbar */
static const int vertpadbar               = 0;   /* vertical padding for statusbar */
static const unsigned int systrayspacing  = 5;   /* systray spacing */
static const int showsystray              = 1;   /* 0 means no systray */
static const unsigned int ulinepad        = 0;   /* horizontal padding between the underline and tag */
static const unsigned int ulinestroke     = 0;   /* thickness / height of the underline */
static const unsigned int ulinevoffset    = 0;   /* how far above the bottom of the bar the line should appear */
static const int ulineall                 = 0;   /* 1 to show underline on all tags, 0 for just the active ones */

/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype               = INDICATOR_NONE;
static int tiledindicatortype             = INDICATOR_NONE;
static int floatindicatortype             = INDICATOR_NONE;

static const char *fonts[] = {
        // "JetBrainsMono Nerd Font:size=12:antialias=true:autohint=true",
        "FuraMono Nerd Font:pixelsize=14:antialias=true:autohint=true",
        "Siji:pixelsize=12",
        "Noto Color Emoji:pixelsize=12",
};

/* This font is used for layout symbol at all times */
static const char *lt_font[] = {
        "JetBrainsMono Nerd Font:size=14:antialias=true:autohint=true",
};


static char c000000[]                     = "#000000"; // placeholder value
static char normfgcolor[]                 = "#475d64";
static char normbgcolor[]                 = "#1a1a24";
static char normbordercolor[]             = "#3d4059";
static char normfloatcolor[]              = "#3d4059";

/* Layout symbol */
static char selfgcolor[]                  = "#8e9fcf";
static char selbgcolor[]                  = "#1a1a24";

/* Focused window border */
// static char selbordercolor[]              = "#6a8cbc";
static char selbordercolor[]              = "#8787bf";
static char selfloatcolor[]               = "#b8dceb";


/*****************************************************/
/************** Ignored since no titlee **************/
static char titlenormfgcolor[]            = "#77547e";
static char titlenormbgcolor[]            = "#1b1d1e";
static char titlenormbordercolor[]        = "#ae81ff";
static char titlenormfloatcolor[]         = "#ae81ff";

static char titleselfgcolor[]             = "#77547e";
static char titleselbgcolor[]             = "#1b1d1e";
static char titleselbordercolor[]         = "#ae81ff";
static char titleselfloatcolor[]          = "#ae81ff";
/*****************************************************/
/*****************************************************/

static char tagsnormfgcolor[]             = "#63718b";
static char tagsnormbgcolor[]             = "#1a1a24";
static char tagsnormbordercolor[]         = "#1a1a24";
static char tagsnormfloatcolor[]          = "#b8dceb";

static char tagsselfgcolor[]              = "#b8dceb";
static char tagsselbgcolor[]              = "#1a1a24";
static char tagsselbordercolor[]          = "#005577";
static char tagsselfloatcolor[]           = "#005577";

static char hidnormfgcolor[]              = "#005577";
static char hidselfgcolor[]               = "#227799";
static char hidnormbgcolor[]              = "#222222";
static char hidselbgcolor[]               = "#222222";

static char urgfgcolor[]                  = "#bbbbbb";
static char urgbgcolor[]                  = "#222222";
static char urgbordercolor[]              = "#b1dba4";
static char urgfloatcolor[]               = "#db8fd9";

static char scratchselfgcolor[]           = "#77547e";
static char scratchselbgcolor[]           = "#77547E";
static char scratchselbordercolor[]       = "#894B9F";
static char scratchselfloatcolor[]        = "#894B9F";

static char scratchnormfgcolor[]          = "#77547e";
static char scratchnormbgcolor[]          = "#664C67";
static char scratchnormbordercolor[]      = "#77547E";
static char scratchnormfloatcolor[]       = "#77547E";




static char *colors[][ColCount] = {
        /*                      fg                  bg                  border                  float                */
        [SchemeNorm]        = { normfgcolor,        normbgcolor,        normbordercolor,        normfloatcolor        },
        [SchemeSel]         = { selfgcolor,         selbgcolor,         selbordercolor,         selfloatcolor         },

        [SchemeTitleNorm]   = { titlenormfgcolor,   titlenormbgcolor,   titlenormbordercolor,   titlenormfloatcolor   },
        [SchemeTitleSel]    = { titleselfgcolor,    titleselbgcolor,    titleselbordercolor,    titleselfloatcolor    },

        [SchemeTagsNorm]    = { tagsnormfgcolor,    tagsnormbgcolor,    tagsnormbordercolor,    tagsnormfloatcolor    },

        // Skipped
        [SchemeTagsSel]     = { tagsselfgcolor,     tagsselbgcolor,     tagsselbordercolor,     tagsselfloatcolor     },

        [SchemeHidNorm]     = { hidnormfgcolor,     hidnormbgcolor,     c000000,                c000000               },
        [SchemeHidSel]      = { hidselfgcolor,      hidselbgcolor,      c000000,                c000000               },
        [SchemeUrg]         = { urgfgcolor,         urgbgcolor,         urgbordercolor,         urgfloatcolor         },
        [SchemeScratchSel]  = { scratchselfgcolor,  scratchselbgcolor,  scratchselbordercolor,  scratchselfloatcolor  },
        [SchemeScratchNorm] = { scratchnormfgcolor, scratchnormbgcolor, scratchnormbordercolor, scratchnormfloatcolor },
        [SchemeLtSymbol]    = { selfgcolor,         selbgcolor,         selbordercolor,         selfloatcolor         }
};


static char *tagsel[][2] = {
        /* focused-colour     focused-bg    */
        {  tagsselfgcolor,    tagsselbgcolor },
        {  tagsselfgcolor,    tagsselbgcolor },
        {  tagsselfgcolor,    tagsselbgcolor },
        {  tagsselfgcolor,    tagsselbgcolor },
        {  tagsselfgcolor,    tagsselbgcolor },
        {  tagsselfgcolor,    tagsselbgcolor },
        {  tagsselfgcolor,    tagsselbgcolor },
        {  tagsselfgcolor,    tagsselbgcolor },
        {  tagsselfgcolor,    tagsselbgcolor },
        {  tagsselfgcolor,    tagsselbgcolor },
        {  tagsselfgcolor,    tagsselbgcolor },
        {  tagsselfgcolor,    tagsselbgcolor },
        {  tagsselfgcolor,    tagsselbgcolor },
        {  tagsselfgcolor,    tagsselbgcolor },
        {  tagsselfgcolor,    tagsselbgcolor },
};

/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by changing the number
 * of strings in the tags array. This build does things a bit different which has some added
 * benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 * [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 * [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1 through 9, while the
 * tags for the second monitor would be named A through I. A third monitor would start again at
 * 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
 * count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
 * the array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both cases work the
 * same from a technical standpoint - the icon index is derived from the tag index and the monitor
 * index. If the icon index is is greater than the number of tag icons then it will wrap around
 * until it an icon matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration patches.
 */
/* static char *tagicons[][NUMTAGS] = {
 [DEFAULT_TAGS]= { "1", "2", "3", "4", "5", "1", "2", "3", "4", "5", "1", "2", "3", "4", "5" },
 [ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "D", "E", "F", "G", "H", "I"},
 [ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
}; */

static char *tagicons[][NUMTAGS] = {
    [DEFAULT_TAGS]        = { "1", "2", "3", "4", "5", "6", "7", "8", "9" },
    [ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
    [ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};


/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,  -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,  -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */
#define TAG(n) (1 << (n - 1))
static const Rule rules[] = {
    /* xprop(1):
     * WM_CLASS(STRING) = instance, class
     * WM_NAME(STRING) = title
     * WM_WINDOW_ROLE(STRING) = role
     * _NET_WM_WINDOW_TYPE(ATOM) = wintype
    */
    RULE(.wintype = WTYPE "DIALOG",  .isfloating = 1 )
    RULE(.wintype = WTYPE "UTILITY", .isfloating = 1 )
    RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1 )
    RULE(.wintype = WTYPE "SPLASH",  .isfloating = 1 )
    RULE(.role    = "pop-up",        .isfloating = 1 )

    // RULE(.class = "St", .isterminal = 1)

    // RULE(.class = "ClipGrab", .isfloating = 1, .noswallow = 1)

    // RULE(.class = "Brave-browser", .role = "browser", .tags = TAG(1))


    
};

static const MonitorRule monrules[] = {
    /* monitor  tag   layout   mfact  nmaster  showbar  topbar */
    {  1,       -1,   0,      -1,     -1,      -1,      -1      }, // use a different layout for the second monitor
    {  -1,      -1,   0,      -1,     -1,      -1,      -1      }, // default
};


/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
    /* monitor    bar   alignment         widthfunc        drawfunc         clickfunc         hoverfunc     name      */
    {  -1,        0,    BAR_ALIGN_LEFT,   width_ltsymbol,  draw_ltsymbol,   click_ltsymbol,   NULL,         "layout"   },
    {  -1,        0,    BAR_ALIGN_LEFT,   width_tags,      draw_tags,       click_tags,       hover_tags,   "tags"     },
    {  'A',       0,    BAR_ALIGN_RIGHT,  width_systray,   draw_systray,    click_systray,    NULL,         "systray"  },
    {  statusmon, 0,    BAR_ALIGN_RIGHT,  width_status2d,  draw_status2d,   click_statuscmd,  NULL,         "status2d" },
};

/* layout(s) */
static const float mfact        = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster        = 1;    /* number of clients in master area */
static const int nstack         = 0;    /* number of clients in primary stack area */
static const int resizehints    = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1;    /* 1 will force focus on the fullscreen window */


/* mouse scroll resize */
static const int scrollsensetivity = 30; /* 1 means resize window by 1 pixel for each scroll event */

/* resizemousescroll direction argument list */
static const int scrollargs[][2] = {
    /* width-change        height-change */
    { +scrollsensetivity,  0                  },
    { -scrollsensetivity,  0                  },
    { 0,                   +scrollsensetivity },
    { 0,                   -scrollsensetivity },
};

static const Layout layouts[] = {
    /* symbol   arrange function, { nmaster, nstack, layout,          master axis,    stack axis,     secondary stack axis, symbol func } */
    {  "  ",    flextile,         { -1,      -1,     SPLIT_VERTICAL,  TOP_TO_BOTTOM,  TOP_TO_BOTTOM,  0,                    NULL        }  }, // default tile layout
    {  "  ",    flextile,         { -1,      -1,     SPLIT_VERTICAL,  TOP_TO_BOTTOM,  MONOCLE,        0,                    NULL        }  }, // deck
    {  " 󰕰 ",    flextile,         { -1,      -1,     NO_SPLIT,        GAPPLESSGRID,   GAPPLESSGRID,   0,                    NULL        }  }, // gappless grid
    {  " 󰚄 ",    flextile,         { -1,      -1,     NO_SPLIT,        MONOCLE,        MONOCLE,        0,                    NULL        }  }, // monocle
    {  "  ",    NULL,             { 0 } },    /* no layout function means floating behavior */
 

    //{ "",      tile,     {0} },
    //{ "[M]",      monocle,  {0} },
    //{ NULL,       NULL,     {0} },
};


/* key definitions */
/* 
 * shift = ShiftMask
 * control = ControlMask
 * alt = Mod1Mask
 * super = Mod4Mask
 */ 

#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask

#define TAGKEYS(KEY,TAG) \
    { MODKEY,                         KEY,      view,         {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,             KEY,      toggleview,   {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,               KEY,      tag,          {.ui = 1 << TAG} }, \
    { MODKEY|Mod1Mask|ShiftMask,      KEY,      toggletag,    {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask,   KEY,      swaptags,     {.ui = 1 << TAG} },


#define STACKKEYS(MOD,ACTION) \
    { MOD, XK_j,     ACTION##stack, {.i = INC(+1) } }, \
    { MOD, XK_k,     ACTION##stack, {.i = INC(-1) } }, \
 // { MOD, XK_s,     ACTION##stack, {.i = PREVSEL } }, \
 // { MOD, XK_w,     ACTION##stack, {.i = 0 } }, \
 // { MOD, XK_e,     ACTION##stack, {.i = 1 } }, \
 // { MOD, XK_a,     ACTION##stack, {.i = 2 } }, \
 // { MOD, XK_z,     ACTION##stack, {.i = -1 } },



/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static const char *roficmd[]  = { "rofi", "-show", "run", NULL };
static const char *termcmd[]  = { "alacritty", NULL };

/* This defines the name of the executable that handles the bar (used for signalling purposes) */
#define STATUSBAR "dwmblocks"



/* --------- EXTRA DEFS ---------- */
#define SCRIPTDIR        "~/.dwm/"
#define SCRIPTCMD(cmd)   { .v = (const char*[]){ "/bin/sh", "-c", SCRIPTDIR cmd, NULL         } }
#define SHCMD(cmd)       { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL                   } }

#define TERMCMD(...)     { .v = (const char*[]){ "st", "-e", __VA_ARGS__, NULL                } }
#define TERMSHCMD(cmd)   { .v = (const char*[]){ "st", "-e", "dash", "-c", cmd, NULL          } }

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

#include <X11/XF86keysym.h>

static Key keys[] = {
    /* modifier            key                       function            argument */

    /* Terminal */
    { MODKEY,              XK_Return,                spawn,              {.v = termcmd } },
    
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
    { MODKEY,              XK_f,                     togglefullscreen,   {0} },
    
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
    { MODKEY,              XK_m,                     togglemax,          {0} },
    
    // n

  
    // o
    { MODKEY|ShiftMask,    XK_o,                     setcfact,           {0} }, // reset facts
    
    // p
    {MODKEY,               XK_p,                     view,               {0} }, // last active tag
    
    // q
    { MODKEY|ShiftMask,    XK_q,                     quit,               {0} }, // quit dwm
    { MODKEY|ControlMask,  XK_q,                     quit,               {1} }, // restart dwm
    
    // r
    {MODKEY,               XK_r,                     reorganizetags,     {0} },
    
    // s
    {MODKEY,               XK_s,                     spawn,              SHCMD("st -e tmux new-session nnn -a -P p") },
    
    
    // t
    { MODKEY,              XK_t,                     setlayout,          {.v = &layouts[0]} }, // set layout back to tile from whatever
    { MODKEY|ShiftMask,    XK_t,                     mirrorlayout,       {0} }, /* flextile, flip master and stack areas */
    
    // u
    // RESTART BLUTOOTH etc
    { MODKEY,              XK_u,                     spawn,              SHCMD("pavucontrol") },
    
    
    // v
    { MODKEY,              XK_v,                     focusmaster,        {0} },
    
    // w
    { MODKEY,              XK_w,                     killclient,         {0} },
    
    // x
    { MODKEY,              XK_x,                     spawn,              SHCMD("~/.config/Obsidian/Obsidian-1.1.16.AppImage") },
    
    // y
    { MODKEY|ControlMask,  XK_y,                     rotatelayoutaxis,   {.i = +1 } },   /* flextile, 1 = layout axis */
    
    // z
    { MODKEY,              XK_z,                     spawn,              SCRIPTCMD("mouse_sens.sh") },
    
    
    
    /** F-keys **/
    { MODKEY,              XK_F1,                    mpdchange,          {.i = -1} },
    { MODKEY,              XK_F2,                    mpdchange,          {.i = +1} },
    { MODKEY,              XK_F4,                    spawn,              SHCMD("terminal -e pulsemixer; pkill -RTMIN+22 $STATUSBAR") },
    { MODKEY,              XK_F9,                    cyclelayout,        {.i = -1 } },
    { MODKEY,              XK_F10,                   cyclelayout,        {.i = +1 } },

    /**************** Special ****************/
    
    // - cycle tags
    { MODKEY,              XK_semicolon,             shiftviewclients,   { .i = -1 } }, 
    { MODKEY,              XK_apostrophe,            shiftviewclients,   { .i = +1 } },

    // - monitor
    { MODKEY,              XK_comma,                 focusmon,           {.i = -1 } },
    { MODKEY,              XK_period,                focusmon,           {.i = +1 } },
    { MODKEY|ShiftMask,    XK_comma,                 tagmon,             {.i = -1 } },
    { MODKEY|ShiftMask,    XK_period,                tagmon,             {.i = +1 } },
    
    { MODKEY,              XK_slash,                 spawn,              SCRIPTCMD("rl_jar.sh") },
    { MODKEY,              XK_backslash,             spawn,              SHCMD("pcmanfm") },

    { MODKEY,              XK_Escape,                mpdcontrol,         {0} },
    { MODKEY|ShiftMask,    XK_space,                 togglefloating,     {0} }, // note: probs change to return
    
    // - swap client with master
    { MODKEY,              XK_space,                 zoom,               {0} },
    
    // - screenshot
    { 0,                   XK_Print,                 spawn,              SCRIPTCMD("ss_selection.sh") },
    { MODKEY,              XK_Print,                 spawn,              SCRIPTCMD("maimpick") },
    
    /*****************************************/

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
    
    TAGKEYS(               XK_1,                                         0)
    TAGKEYS(               XK_2,                                         1)
    TAGKEYS(               XK_3,                                         2)
    TAGKEYS(               XK_4,                                         3)
    TAGKEYS(               XK_5,                                         4)
    TAGKEYS(               XK_6,                                         5)
    TAGKEYS(               XK_7,                                         6)
    TAGKEYS(               XK_8,                                         7)
    TAGKEYS(               XK_9,                                         8)
    
    
    // ------------------------------------------- //
    { MODKEY,              XK_Left,                  setmfact,           {.f = -0.05} },
    { MODKEY,              XK_Right,                 setmfact,           {.f = +0.05} },
    
    STACKKEYS(MODKEY,                                focus)
    STACKKEYS(MODKEY|ShiftMask,                      push)
    { MODKEY|ShiftMask|ControlMask,  XK_comma,       tagswapmon,         {.i = +1 } },
    { MODKEY|ShiftMask|ControlMask,  XK_period,      tagswapmon,         {.i = -1 } },
    // -------------------------------------------  //

    /* -- todo -- */
    // { MODKEY,       XK_period,     togglesticky,   {0} },
    // 
    // { MODKEY|ControlMask,   XK_u,  incnstack,      {.i = -1 } },
    // { MODKEY,       XK_i,  incnmaster,     {.i = +1 } },
    // { MODKEY|ShiftMask,     XK_i,  incnmaster,     {.i = -1 } },
    // { MODKEY|ControlMask,   XK_i,  incnstack,      {.i = +1 } },
    // { MODKEY,       XK_e,  spawn,  SHCMD("terminal -e $FILE_MANAGER") },
    // { MODKEY|ShiftMask,     XK_e,  spawn,  SHCMD("terminal -e htop") },
    // set_to_o { MODKEY,       XK_b,  togglebar,      {0} },
    // { MODKEY,       XK_Tab,view,   {0} },
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* clickevent     mask       button    function            argument */
    { ClkLtSymbol,    0,         Button1,  setlayout,          {0} },
    { ClkLtSymbol,    0,         Button3,  setlayout,          {.v = &layouts[2]} },
    { ClkWinTitle,    0,         Button2,  zoom,               {0} },
    { ClkStatusText,  0,         Button1,  sigstatusbar,       {.i = 1 } },
    { ClkStatusText,  0,         Button2,  sigstatusbar,       {.i = 2 } },
    { ClkStatusText,  0,         Button3,  sigstatusbar,       {.i = 3 } },
    { ClkStatusText,  0,         Button4,  sigstatusbar,       {.i = 4 } },
    { ClkStatusText,  0,         Button5,  sigstatusbar,       {.i = 5 } },
    /* placemouse options, choose which feels more natural:
     *    0 - tiled position is relative to mouse cursor
     *    1 - tiled postiion is relative to window center
     *    2 - mouse pointer warps to window center
     *
     * The moveorplace uses movemouse or placemouse depending on the floating state
     * of the selected client. Set up individual keybindings for the two if you want
     * to control these separately (i.e. to retain the feature to move a tiled window
     * into a floating position).
     */
    { ClkClientWin,   MODKEY,    Button1,  moveorplace,        {.i = 1} },
    { ClkClientWin,   MODKEY,    Button2,  togglefloating,     {0} },
    { ClkClientWin,   MODKEY,    Button3,  resizemouse,        {0} },
    { ClkClientWin,   MODKEY,    Button4,  resizemousescroll,  {.v = &scrollargs[0]} },
    { ClkClientWin,   MODKEY,    Button5,  resizemousescroll,  {.v = &scrollargs[1]} },
    { ClkClientWin,   MODKEY,    Button6,  resizemousescroll,  {.v = &scrollargs[2]} },
    { ClkClientWin,   MODKEY,    Button7,  resizemousescroll,  {.v = &scrollargs[3]} },
    { ClkTagBar,      0,         Button1,  view,               {0} },
    { ClkTagBar,      0,         Button3,  toggleview,         {0} },
    { ClkTagBar,      MODKEY,    Button1,  tag,                {0} },
    { ClkTagBar,      MODKEY,    Button3,  toggletag,          {0} },
};


