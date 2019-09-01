///Add
#ifdef ENABLE_SORT_INVEN
static bool SortMyItems(const LPITEM & s1, const LPITEM & s2) { return std::strcmp(s1->GetName(),s2->GetName()) < 0; }
void CHARACTER::EditMyInven()
{
	if (IsDead())
		return;
	std::vector<LPITEM> v;
    LPITEM myitems;
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
	int size = Inventory_Size();
#else
	int size = INVENTORY_MAX_NUM;
#endif

	for (int i = 0; i < size; ++i)
	{
		if (!(myitems = GetInventoryItem(i))) 
			continue;
		
		///add all items inven to vector
		v.push_back(myitems);
		
		///delete items from inven
		myitems->RemoveFromCharacter();
	}
	///Sort items
	std::sort(v.begin(), v.end(), SortMyItems);
	
	///Send vector items to inven
	itertype(v) it = v.begin();
	while (it != v.end()) {	
		LPITEM item = *(it++);
		if (item) {
			TItemTable * p = ITEM_MANAGER::instance().GetTable(item->GetVnum());
			/// isn't same function !
			if (p && p->dwFlags & ITEM_FLAG_STACKABLE && p->bType != ITEM_BLEND)
				AutoGiveItem(item->GetVnum(), item->GetCount(), -1, false); // create new item for stackable items
			else
				AutoGiveItem(item); // copy orginal items
		}
	}
	
	///message
	ChatPacket(CHAT_TYPE_INFO, "Your items sorted.");
}
#endif
