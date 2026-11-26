stock _SetItemAmountPVar(playerid,item,Amount)
{
	new tmp[16];
	format(tmp,16,"PITEMAMOUNT%d",item);
	SetPVarInt(playerid,tmp,Amount);
}

stock AddItem(playerid,const ItemName[],Amount)
{
    if(!IsPlayerNPC(playerid))
    {
		new slot=-1;
		for(new item;item<MAX_ITEMS;item++)
		{
			if(!_GetItemAmountPVar(playerid,item))
			{
				if(slot==-1)slot=item;
				continue;
			}
			if(!strcmp(_GetItemNamePVar(playerid,item),ItemName,true))
			{
				_SetItemAmountPVar(playerid,item,_GetItemAmountPVar(playerid,item)+Amount);
				if(_GetItemAmountPVar(playerid,item)<=0)_SetItemAmountPVar(playerid,item,0);
				if(_GetItemAmountPVar(playerid,item)>MAX_ITEM_STACK)
				{
					_SetItemAmountPVar(playerid,item,MAX_ITEM_STACK);
					return 2;
				}
				return 1;
			}
		}
		if(slot>-1)
		{
			_SetItemNamePVar(playerid,slot,ItemName);
			_SetItemAmountPVar(playerid,slot,Amount);
			if(_GetItemAmountPVar(playerid,slot)>MAX_ITEM_STACK)
			{
				_SetItemAmountPVar(playerid,slot,MAX_ITEM_STACK);
				return 2;
			}
			return 1;
		}
	}
	return 0;
}

stock RemoveItem(playerid,const ItemName[],Amount)
{
    if(!IsPlayerNPC(playerid))
    {
		for(new item;item<MAX_ITEMS;item++)
		{
			if(!_GetItemAmountPVar(playerid,item))continue;
			if(!strcmp(_GetItemNamePVar(playerid,item),ItemName,true))
			{
				_SetItemAmountPVar(playerid,item,_GetItemAmountPVar(playerid,item)-Amount);
				if(_GetItemAmountPVar(playerid,item)<=0)_SetItemAmountPVar(playerid,item,0);
				if(_GetItemAmountPVar(playerid,item)>MAX_ITEM_STACK)
				{
					_SetItemAmountPVar(playerid,item,MAX_ITEM_STACK);
					return 2;
				}
				return 1;
			}
		}
	}
	return 0;
}

stock PlayerHasItem(playerid,const ItemName[])
{
	for(new item;item<MAX_ITEMS;item++)
	{
		if(!_GetItemAmountPVar(playerid,item))continue;
		if(!strcmp(_GetItemNamePVar(playerid,item),ItemName,false))return _GetItemAmountPVar(playerid,item);
	}
	return 0;
}

stock GetPlayerItemInfo(playerid,&idx,ItemName[],len=sizeof(ItemName),&Amount)
{
	if(idx>=MAX_ITEMS)return 0;
	format(ItemName,len,_GetItemNamePVar(playerid,idx));
	Amount=_GetItemAmountPVar(playerid,idx);
	idx++;
	return 1;
}

stock ResetPlayerInventory(playerid)
{
	for(new item;item<MAX_ITEMS;item++)_SetItemAmountPVar(playerid,item,0);
	pInfo[playerid][BackpackSlotsUsed] = 0;
}

stock GetBackpackName(playerid)
{
	new str[128];
	switch(pInfo[playerid][Backpack])
	{
		case 0: str = "Coyote Patrol Pack";
		case 1: str = "Czech Vest Pouch";
		case 2: str = "Alice Pack";
		case 3: str = "Coyote Backpack";
	}
	return str;
}

stock ShowInventory(playerid)
{
	new str[180];
    if(!IsPlayerNPC(playerid))
    {
		gItemList="";
		for(new item;item<MAX_ITEMS;item++)
		{
			if(!strlen(_GetItemNamePVar(playerid,item))||!_GetItemAmountPVar(playerid,item))continue;
			format(gItemList,sizeof(gItemList),"%s\n%d\t\t%s",gItemList,_GetItemAmountPVar(playerid,item),_GetItemNamePVar(playerid,item));
		}
		format(gItemList,sizeof(gItemList),"%s",gItemList);

		format(str,sizeof(str),""COL_WHITE"%s "COL_GREEN"%i |"COL_WHITE" %i",GetBackpackName(playerid),pInfo[playerid][BackpackSlotsUsed],pInfo[playerid][BackpackSlots]);
		ShowPlayerDialog(playerid,INV_DIALOG_ID,DIALOG_STYLE_LIST,str,gItemList,"Select","Close");
	}
	return 1;
}



GetXYInFrontOfPlayer(playerid, &Float:x, &Float:y, Float:distance)
{
	new Float:a;
	GetPlayerPos(playerid, x, y, a);
	GetPlayerFacingAngle(playerid, a);
	if (GetPlayerVehicleID(playerid)) {
	    GetVehicleZAngle(GetPlayerVehicleID(playerid), a);
	}
	x += (distance * floatsin(-a, degrees));
	y += (distance * floatcos(-a, degrees));
}

function DestroyRoadFlare(playerid)
{
	DestroyDynamicObject(RoadFlare[playerid]);
}

