int
width_ltsymbol(Bar *bar, BarArg *a)
{
	return TEXTW(bar->mon->ltsymbol);
}

int
draw_ltsymbol(Bar *bar, BarArg *a)
{
	drw_setscheme(drw, scheme[SchemeLtSymbol]);
	return drw_text_ltsymbol(drw, a->x, a->y, a->w, a->h, lrpad / 2, bar->mon->ltsymbol, 0, False);
} 

int
click_ltsymbol(Bar *bar, Arg *arg, BarArg *a)
{
	return ClkLtSymbol;
}

