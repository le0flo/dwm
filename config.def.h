/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx = 2;
static const unsigned int gappx = 7;
static const unsigned int snap = 10;
static const int showbar = 1;
static const int topbar = 0;

/* fonts */
static const char *fonts[] = { "BigBlueTermPlus Nerd Font:size=8" };
static const char dmenufont[] = "BigBlueTermPlus Nerd Font:size=8";

/* colors */
static const char col_gray1[] = "#222222";
static const char col_gray2[] = "#444444";
static const char col_gray3[] = "#bbbbbb";
static const char col_gray4[] = "#eeeeee";
static const char col_cyan[] = "#005577";
static const char col_green[] = "#97bb72";

static const char *colors[][3] = {
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_green,  col_green  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

/* rules */
static const Rule rules[] = { 0 };

/* layout(s) */
static const float mfact = 0.55;
static const int nmaster = 1;
static const int resizehints = 1;
static const int lockfullscreen = 1;

static const Layout layouts[] = {
	{ "tiling",		tile },
	{ "floating",	NULL },
};

/* key definitions */
#define MODKEY Mod1Mask

#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} },

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0";

static const char *termcmd[] = { "alacritty", NULL };
static const char *dmenucmd[] = { "rofi", "-show", "drun", NULL };

static const Key keys[] = {
	{ MODKEY|ShiftMask,             XK_Return,	spawn,			{.v = termcmd } },
	{ MODKEY,                       XK_p,		spawn,			{.v = dmenucmd } },
	{ MODKEY,                       XK_j,		focusstack,		{.i = +1 } },
	{ MODKEY,                       XK_k,		focusstack,		{.i = -1 } },
	{ MODKEY,                       XK_comma,	focusmon,		{.i = -1 } },
	{ MODKEY,                       XK_period,	focusmon,		{.i = +1 } },
	{ MODKEY,                       XK_h,		setmfact,		{.f = -0.02} },
	{ MODKEY,                       XK_l,		setmfact,		{.f = +0.02} },
	{ MODKEY,                       XK_t,		setlayout,		{.v = &layouts[0]} },
	{ MODKEY,                       XK_f,		setlayout,		{.v = &layouts[1]} },
	{ MODKEY,                       XK_Tab,		view,			{.ui = ~0 } },
	{ MODKEY,                       XK_b,		togglebar,		{0} },
	{ MODKEY|ShiftMask,             XK_k,		killclient,		{0} },
	{ MODKEY|ShiftMask,				XK_q,		quit,			{0} },
	TAGKEYS(						XK_1,						0)
	TAGKEYS(						XK_2,						1)
	TAGKEYS(						XK_3,						2)
	TAGKEYS(						XK_4,						3)
	TAGKEYS(						XK_5,						4)
	TAGKEYS(						XK_6,						5)
	TAGKEYS(						XK_7,						6)
	TAGKEYS(						XK_8,						7)
	TAGKEYS(						XK_9,						8)
};

/* button definitions */
static const Button buttons[] = {
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

