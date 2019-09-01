//Find
		BYTE		GetAttributeType(int i)	{ return m_aAttr[i].bType;	}
		
///Add
#ifdef ENABLE_SORT_INVEN
		BYTE CustomSort()	{
			std::map<BYTE,BYTE> Sort;
			Sort[ITEM_WEAPON] = 1;
			Sort[ITEM_ARMOR] = 2;
			Sort[ITEM_USE] = 3;
			Sort[ITEM_BELT] = 4;
			Sort[ITEM_COSTUME] = 5;
			Sort[ITEM_SKILLBOOK] = 6;
			Sort[ITEM_SKILLFORGET] = 6;
			const auto & it = Sort.find(m_pProto->bType);
			if (it != Sort.end())
				return it->second;
			return Sort.rbegin()->second + 1;
		}
#endif
