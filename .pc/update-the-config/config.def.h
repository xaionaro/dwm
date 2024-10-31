/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=28" };
static const char dmenufont[]       = "monospace:size=28";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const int taglayouts[] = { 0, 2, 0, 0, 0, 0, 0, 0, 2 };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      		instance    title       tags mask     	isfloating  monitor */
	{ "Gimp",     		NULL,       NULL,       0,            	1,          0 },
	{ "Firefox",  		NULL,       NULL,       1<<1,			0,          0 },
	{ NULL,  			NULL,       "Mozilla Firefox", 2,		0,          0 },
	{ "Chromium",  		NULL,       NULL,       1<<1,			0,          0 },
	{ "Fyne",  			NULL,       NULL,       0,				1,          -1 },
	{ "Pomodoro",  		NULL,       NULL,       0xFF,			1,          1 },
	{ "Fynodoro",  		NULL,       NULL,       0xFF,			1,          1 },
	{ "StreamPanel",  	NULL,       NULL,       0,				1,          1 },
	{ "pinentry",  		NULL,       NULL,       0,				1,          0 },
	{ NULL,  			NULL,       "ZynAddSubFX", 1<<7,		1,          0 },
	{ "Code",  			NULL,       NULL,       1<<0,			0,          0 },
	{ NULL,  			NULL,       "OBS",      1<<8,			0,          0 },
	{ NULL,  			NULL,       "Easy Effects", 1<<8,		0,          0 },
	{ NULL,  			NULL,       "Fullscreen Projector", 1,  0,          3 },
	{ "Spotify",  		NULL,       NULL,       1<<8,			0,          1 },
	{ NULL,				NULL,		"A PipeWire Graph Qt GUI Interface", 1<<7, 0, 0 },
	{ "Logseq",			NULL,		NULL, 		1<<2,			0,			0 },
	{ "Discord",		NULL,		NULL, 		1<<2,			0,			0 },
	{ "Bazecor",		NULL,		NULL, 		1<<6,			0,			0 },
	{ "Element",		NULL,		NULL, 		1<<1,			0,			1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 2;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define ALTMODKEY (ControlMask|Mod1Mask)
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ ControlMask|ShiftMask,        KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ ALTMODKEY,             		KEY,      tag,            {.ui = 1 << TAG} }, \
	{ ALTMODKEY|ShiftMask,          KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "alacritty", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ ALTMODKEY,             		XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },	
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ ALTMODKEY,             		XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_e,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ ALTMODKEY,             		XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_f,      togglefullscreen, {0} },
	{ ALTMODKEY,             		XK_f,      togglefakefullscreen, {0} },
	//{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ ALTMODKEY,             		XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
 	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ ALTMODKEY,             		XK_comma,  tagmon,         {.i = -1 } },
	{ ALTMODKEY,             		XK_period, tagmon,         {.i = +1 } },
	{ ALTMODKEY,             		XK_s,      focusnthmon,    {.ui = 1 } },
	{ ALTMODKEY,             		XK_d,      focusnthmon,    {.ui = 0 } },
	{ ALTMODKEY,             		XK_f,      focusnthmon,    {.ui = 3 } },
	{ ALTMODKEY,             		XK_g,      focusnthmon,    {.ui = 2 } },
	{ ALTMODKEY|ShiftMask, 			XK_s,      tagnthmon,      {.ui = 1 } },
	{ ALTMODKEY|ShiftMask, 			XK_d,      tagnthmon,      {.ui = 0 } },
	{ ALTMODKEY|ShiftMask, 			XK_f,      tagnthmon,      {.ui = 3 } },
	{ ALTMODKEY|ShiftMask, 			XK_g,      tagnthmon,      {.ui = 2 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ ALTMODKEY,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

