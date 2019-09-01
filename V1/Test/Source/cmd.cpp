///Add
#ifdef ENABLE_SORT_INVEN
ACMD(do_item_check)
{
	ch->EditMyInven();
}
#endif

//Find
	{ "set",		do_set,			0,			POS_DEAD,	GM_IMPLEMENTOR	},

///Add
#ifdef ENABLE_SORT_INVEN
	{ "item_check",		do_item_check,		0,			POS_DEAD,	GM_PLAYER	},
#endif
