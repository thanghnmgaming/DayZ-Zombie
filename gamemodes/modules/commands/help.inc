// ---------------------------------------------------------------------------
// In-game guide: /help. One entry per topic; edit the pages here.
// ---------------------------------------------------------------------------

#define DIALOG_HELP       5003
#define DIALOG_HELP_PAGE  5004
#define DIALOG_COMMANDS   5472    // the existing command list menu

new const HelpTopics[][] =
{
	"Controls", "Staying alive", "Weapons and loot", "Zombies", "Crafting and fire", "Building and tents", "Vehicles", "Missions, zones and groups", "Command list"
};

stock ShowHelpMenu(playerid)
{
	new list[256];
	for(new i; i < sizeof(HelpTopics); i++)
	{
		strcat(list, HelpTopics[i]);
		strcat(list, "\n");
	}
	ShowPlayerDialog(playerid, DIALOG_HELP, DIALOG_STYLE_LIST, "How to play", list, "Open", "Close");
	return 1;
}

stock ShowHelpPage(playerid, topic)
{
	new text[1200];
	switch(topic)
	{
		case 0:
		{
			strcat(text, "{37DB45}Y{FFFFFF} or /inv - open your backpack, pick an item, then Use or Drop\n");
			strcat(text, "{37DB45}N{FFFFFF} - pick up loot lying in the world and zombie loot, destroy your tent\n");
			strcat(text, "{37DB45}Left ALT{FFFFFF} - dropped items, crates, tents, vehicle storage, camp fires\n");
			strcat(text, "{37DB45}C{FFFFFF} at a gas station - fill an empty jerry can\n");
			strcat(text, "{37DB45}Hold H{FFFFFF} - lie down\n");
			strcat(text, "{37DB45}Numpad 4{FFFFFF} in a vehicle - engine on/off\n");
			strcat(text, "{37DB45}/dropgun /pickupgun{FFFFFF} - drop or take a weapon");
		}
		case 1:
		{
			strcat(text, "Watch the icons at the bottom right. Green is safe, red means you are close to death.\n\n");
			strcat(text, "{37DB45}Blood{FFFFFF}: food restores a little, Blood Bag and Medical Kit fill it\n");
			strcat(text, "{37DB45}Hunger{FFFFFF}: burgers, beans, fruit, cooked meat\n");
			strcat(text, "{37DB45}Thirst{FFFFFF}: water, milk, soda. Swim with an empty bottle to fill it\n");
			strcat(text, "{37DB45}Temperature{FFFFFF}: Heat Pack\n");
			strcat(text, "{37DB45}Bleeding{FFFFFF}: Bandage\n");
			strcat(text, "{37DB45}Broken leg{FFFFFF}: Morphine or Splint\n");
			strcat(text, "{37DB45}Infection{FFFFFF}: Antibiotics, or you keep losing blood\n\n");
			strcat(text, "When you die, everything you carry drops where you fell.");
		}
		case 2:
		{
			strcat(text, "To arm yourself you need the weapon {37DB45}and{FFFFFF} the matching ammo in your backpack, then Use the weapon.\n");
			strcat(text, "To reload, hold the weapon and Use another box of its ammo.\n\n");
			strcat(text, "Pistols: Pistol Ammo. Shotguns: Shotgun Ammo. AK-47 and M4: Assault Ammo.\n");
			strcat(text, "MP5: SMG Ammo. Rifles: Sniper Ammo.\n\n");
			strcat(text, "Bigger backpacks carry more: Czech Vest Pouch, Alice Pack, Coyote Backpack.\n");
			strcat(text, "Military areas, hospitals and supply crates hold the best loot.");
		}
		case 3:
		{
			strcat(text, "Zombies see what is in front of them and hear noise. Walls block their sight, not your noise.\n\n");
			strcat(text, "Walk or crouch to stay quiet. A gunshot draws them from far away.\n\n");
			strcat(text, "{37DB45}Walkers{FFFFFF} are common. {F3FF02}Runners{FFFFFF} are fast. {F81414}Brutes{FFFFFF} are tough and hit hard.\n");
			strcat(text, "A hit can infect you. Kill them for loot.");
		}
		case 4:
		{
			strcat(text, "{37DB45}/craft{FFFFFF} shows the recipes:\n");
			strcat(text, "Bandage: 2 Cloth\nSplint: 1 Wood, 1 Cloth\nHeat Pack Basic: 1 Cloth (carry a Lighter)\n");
			strcat(text, "Pistol Ammo: 2 Scrap Metal (Toolbox)\nShotgun Ammo: 2 Scrap Metal, 1 Nails (Toolbox)\n");
			strcat(text, "Wooden Wall: 2 Wood, 1 Nails (Toolbox)\nWooden Gate: 2 Wood, 2 Nails (Toolbox)\n\n");
			strcat(text, "{37DB45}Camp fire{FFFFFF}: carry Wood and a Lighter and Use one of them.\n");
			strcat(text, "Press Left ALT next to the fire to cook raw meat and boil dirty water.");
		}
		case 5:
		{
			strcat(text, "{37DB45}Walls and gates{FFFFFF}: face the way you want to block and Use the item in your backpack.\n");
			strcat(text, "/gate opens your gate (owner and group). /demolish takes your structure back (Toolbox).\n");
			strcat(text, "Up to 20 each. No building near spawn points, supply crates or strangers.\n");
			strcat(text, "Gunfire and zombies can destroy structures.\n\n");
			strcat(text, "{37DB45}Tent{FFFFFF}: Use it to place your one tent. It stores 16 items. Left ALT opens it,\n");
			strcat(text, "N destroys it (Toolbox).");
		}
		case 6:
		{
			strcat(text, "Most vehicles need parts before they run.\n\n");
			strcat(text, "Stand next to it, press {37DB45}Left ALT{FFFFFF}, pick a slot, choose Add Item and add:\n");
			strcat(text, "an {37DB45}Engine{FFFFFF}, enough {37DB45}Tires{FFFFFF} for its wheels, and a {37DB45}Full Jerry Can{FFFFFF}.\n\n");
			strcat(text, "A Toolbox repairs a damaged vehicle. Free slots store items.");
		}
		case 7:
		{
			strcat(text, "{37DB45}/mission{FFFFFF}: kill zombies for a reward.\n\n");
			strcat(text, "{F81414}Red areas{FFFFFF} on the map are danger zones: more zombies, better loot.\n");
			strcat(text, "A supply crate is dropped every few minutes and marked on the map.\n\n");
			strcat(text, "{37DB45}Groups{FFFFFF}: /makegroup, /invitegroup, /acceptgroup, /leavegroup, /g to chat.");
		}
		default: return ShowPlayerDialog(playerid, DIALOG_COMMANDS, DIALOG_STYLE_LIST, "DayZ - Commands", "General Commands\nAnimation Commands\nGroup Commands\n", "Select", "Close");
	}
	ShowPlayerDialog(playerid, DIALOG_HELP_PAGE, DIALOG_STYLE_MSGBOX, HelpTopics[topic], text, "Back", "Close");
	return 1;
}

stock HandleHelpDialog(playerid, dialogid, response, listitem)
{
	if(dialogid == DIALOG_HELP)
	{
		if(response && 0 <= listitem < sizeof(HelpTopics))
		{
			ShowHelpPage(playerid, listitem);
		}
		return 1;
	}
	if(dialogid == DIALOG_HELP_PAGE)
	{
		if(response) ShowHelpMenu(playerid);
		return 1;
	}
	return 0;
}

CMD:guide(playerid) return ShowHelpMenu(playerid);
