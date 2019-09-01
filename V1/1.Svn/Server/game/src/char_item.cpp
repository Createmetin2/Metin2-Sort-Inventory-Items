//Find
static bool FN_check_item_socket(LPITEM item)
{

///Add
#ifdef ENABLE_SORT_INVEN
	if (item->GetType() == ITEM_USE && item->GetSubType() == USE_AFFECT)
		return true;
#endif

//Find in LPITEM CHARACTER::AutoGiveItem(DWORD dwItemVnum, BYTE bCount, int iRarePct, bool bMsg)
	if (item->GetVnum() == dwItemVnum && FN_check_item_socket(item))
///Change
#ifdef ENABLE_SORT_INVEN
	if (item->GetOriginalVnum() == dwItemVnum && FN_check_item_socket(item))
#else
	if (item->GetVnum() == dwItemVnum && FN_check_item_socket(item))	
#endif
