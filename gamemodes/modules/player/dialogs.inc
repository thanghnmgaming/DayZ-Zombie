public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(strfind(inputtext, "%") != -1) return SendClientMessage(playerid, -1, "*"COL_RED" Go crash another server douche!"),KickEx(playerid);
    if(HandleItemDialog(playerid, dialogid, response, listitem, inputtext)) return 1;
    switch(dialogid)
    {
		case DIALOG_LOGIN:
		{
			if(!response)
			{
				KickEx(playerid);
				return 1;
			}
			if(pInfo[playerid][pLogged] == 1) return 1;
			if(strlen(inputtext) >= 3 && strlen(inputtext) <= 64)
			{
				OnPlayerAccountLogin(playerid, inputtext);
			}
			else
			{
				ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "DayZ Login", "Type your account's password below:", "Login", "Exit");
			}
		}

		case DIALOG_REGISTER:
		{
			if(!response)
			{
				KickEx(playerid);
				return 1;
			}
			if(pInfo[playerid][pLogged] == 1 || gRegistred[playerid] == 1) return 1;
			if(strlen(inputtext) >= 3 && strlen(inputtext) <= 64)
			{
				OnPlayerRegister(playerid, inputtext);
			}
			else
			{
				ShowPlayerDialog(playerid, DIALOG_REGISTER, DIALOG_STYLE_PASSWORD, "DayZ Register", "Password must be 3-64 characters:", "Register", "Cancel");
			}
		}

		case DIALOG_COIN:

		{
		    if(response)
		    {
		        switch(listitem)
		        {
		            case 0:
		            {
						new strlist[180];
						strcat(strlist, "Police Cap - 5 Coins\nRed Hockey Mask - 15 Coins\nArmy Helmet - 20 Coins\n");
						ShowPlayerDialog(playerid, DIALOG_PLAYERITEMS, DIALOG_STYLE_LIST, "Select one of the following Player Items", strlist, "Purchase", "Cancel");
					}
				}
			}
		}


		case 5472:
		{
			if(response)
			{
			    switch(listitem)
			    {
			        case 0:
			        {
			        	new str[700];
			        	strcat(str, "/basickeys - keys to get you started\n/savestats - save your stats\n/pickupgun - pickup dropped gun\n/dropgun - drop your current weapon\n/survival - blood, hunger, thirst etc\n\
			        	/version - SA:MP version\n/getidid - Get a persons ID\n/stopambient - turn off ambient\n/firstperson - first person view\n/ask - Use this when you need help\n");
			        	strcat(str, "/r - send a radio message\n/ooc - Global Chat (needs radio device)\n/me - self expression command\n/shout - yell :)\n/local - local chat\n\
						/pm - Private message someone\n/blockpm & /unblockpm - self explained\n/inv - show inventory\n/acmds - Admin Commands\n/rules - List of server rules\n");
		                ShowPlayerDialog(playerid,4661,DIALOG_STYLE_MSGBOX,"DayZ - General CMDSs",str,"Close","");
					}

				    case 1:
				    {
				        new str[126];
				        strcat(str, "/stopanim - Stop all animations\n/wave - Wave your hand\n/sit - three sets of sitting animation\n/handsup - Put your hands up\n");
				        ShowPlayerDialog(playerid,4662,DIALOG_STYLE_MSGBOX,"DayZ - Animations CMDs",str,"Close","");
					}

				    case 2:
				    {
				        new str[400];
		          		strcat(str, "/makegroup - Create a group\n/destroygroup - Destroy your group\n/g - group chat\n/groupinfo - Group information\n/invitegroup - invite someone to your group\n\
						/acceptgroup - Self explained\n/denygroup - Self explained\n/kickgroup - kick someone from your group\n/leavegroup - self explained\n/groupfind - find a group player\n");
				        ShowPlayerDialog(playerid,4663,DIALOG_STYLE_MSGBOX,"DayZ - Group CMDs",str,"Close","");
					}
				}
			}
		}

		case 8341:
		{
			if(response)
			{
			    switch(listitem)
			    {
			        case 0:
			        {
			            ShowPlayerDialog(playerid,5472,DIALOG_STYLE_LIST,"DayZ - Commands","General Commands\nAnimation Commands\nGroup Commands\n","Select","Close");
					}

			        case 1:
			        {
			            new str[1400];
			            strcat(str, "{FFFFFF}Basic Survival Tips:\nThe Indicators on the bottom right of the screen, notifies you when you need more blood, food, water, and heat up (temperature)\n\
		            	{C9FFAB}Light Green = {FFFFFF}Safe\n{37DB45}Dark Green  = {FFFFFF}Safe\n{F3FF02}Yellow = Normal\n{F9B857}Orange = {FFFFFF}Below Normal\n{F81414}Red = {FFFFFF}Near death\n");
						strcat(str,"{37DB45}Food/Hunger{FFFFFF}: Always maintain a balance to keep yourself hydrated with water & full with food!\n\
						{37DB45}Thirst{FFFFFF}: Running, swimming, getting shot drops, makes you get thirsty alot, make sure you have drinks with you all the time!\n");
						strcat(str,"{37DB45}Blood{FFFFFF}: Important key in survival. Low blood causes blackend screen, shaking screen, less stamnia. Visit the hospitals!\n");
						strcat(str,"{37DB45}Temperature{FFFFFF}: Your temperature decreases if you swim or jump alot. It increases if you sprint alot or use a heatpack to increase it!\n\
						{37DB45}Humanity{FFFFFF}: If the skull if green means you are a hero or a normal player which is safe for most players.\nAs for Red it means you are a bandit you may be killed on sight!\n");
						strcat(str,"{37DB45}Noise{FFFFFF}: Vision sight for zombies. Name tag showns further if you're making alot of noise!\n\
						{37DB45}Eye Sight{FFFFFF}: Name Tag seen through walls.\n");
						ShowPlayerDialog(playerid, 8343, DIALOG_STYLE_MSGBOX, "DayZ - Survival Tips", str, "Close", "");
					}

					case 2:
					{
					    ShowPlayerDialog(playerid, 8343, DIALOG_STYLE_MSGBOX, "DayZ - Zombies", "Will be added when zombies are added again!", "Close", "");
					}
				}
			}
		}

		case DIALOG_OPTIONS:
		{
			if(response)
			{
			    switch(listitem)
			    {
			        case 0: ShowPlayerDialog(playerid, DIALOG_GENDEROPTION_2, DIALOG_STYLE_MSGBOX, "DayZ - Gender Selection", "Please, select the default gender you wish to spawn with.", "Male", "Female");
			        case 1: ShowPlayerDialog(playerid, DIALOG_AMBIENTOPTION_2, DIALOG_STYLE_MSGBOX, "DayZ - Ambient Background", "Enable or disable the background ambient?", "ON", "OFF");
				}
			}
		}

		case DIALOG_GENDEROPTION_2:
		{
			if(response)
			{
				pInfo[playerid][DefaultGender] = MALE_ID;
				SendClientMessage(playerid, -1, ""chat" You have sucessfully changed your default gender to MALE this will be saved.");
			}

			if(!response)
			{
				pInfo[playerid][DefaultGender] = FEMALE_ID;
				SendClientMessage(playerid, -1, ""chat" You have sucessfully changed your default gender to FEMALE this will be saved.");
			}
		}

		case DIALOG_AMBIENTOPTION_2:
		{
			if(response)
			{
				pInfo[playerid][pAmbientEnable] = 1;
				SendClientMessage(playerid, -1, ""chat" You have sucessfully changed ambient background to ON this will be saved.");
			}

			if(!response)
			{
				pInfo[playerid][pAmbientEnable] = 2;
				SendClientMessage(playerid, -1, ""chat" You have sucessfully changed ambient background to OFF this will be saved.");
			}
		}

	    case DIALOG_RADIO:
		{
			if(response)
			{
			    switch(listitem)
			    {
			        case 0: pInfo[playerid][pRadioFreq] = 60.0, SendClientMessage(playerid,-1,""chat" You've changed your radio frequency meter to low!");
			        case 1: pInfo[playerid][pRadioFreq] = 100.0, SendClientMessage(playerid,-1,""chat" You've changed your radio frequency meter to medium!");
			        case 2: pInfo[playerid][pRadioFreq] = 160.0, SendClientMessage(playerid,-1,""chat" You've changed your radio frequency meter to normal!");
			        case 3: pInfo[playerid][pRadioFreq] = 200.0, SendClientMessage(playerid,-1,""chat" You've changed your radio frequency meter to high!");
				}
			}
		}

		case DIALOG_SELECT_SKIN:
		{
		    if(response)
		    {
		        SetPlayerSkin(playerid,NORMAL);
          		ShowPlayerDialog(playerid,DIALOG_AMBIENT,DIALOG_STYLE_MSGBOX,""COL_LGREEN"DayZ Background Ambient",""COL_WHITE"Enabling the ambient gives more aspect of survival to the gamemode!\n"COL_LGREEN"Enabling ambient requires A average of 2mb Download speed!","Enable","Disable");

			}

			if(!response)
			{
			    SetPlayerSkin(playerid,FEMALE);
				ShowPlayerDialog(playerid,DIALOG_AMBIENT,DIALOG_STYLE_MSGBOX,""COL_LGREEN"DayZ Background Ambient",""COL_WHITE"Enabling the ambient gives more aspect of survival to the gamemode!\n"COL_LGREEN"Enabling ambient requires A average of 2mb Download speed!","Enable","Disable");
			}
		}

		case DIALOG_AMBIENT:
		{
			if(response)
			{
			    PlayAudioStreamForPlayer(playerid,"http://k007.kiwi6.com/hotlink/w3111dmsph/dayz_ost_-_ambient_music_hq_.mp3");
			    PlayerTextDrawHide(playerid, PlayerIntroBox[playerid]);
			}

			if(!response)
			{
			    PlayerTextDrawHide(playerid, PlayerIntroBox[playerid]);
			}
		}


		case 9921:
		{
		    if(response)
			{
		        ShowRulesToPlayer(playerid);
		    }
		}

		case 8618:
		{
			if(response)
			{
			    SendClientMessage(playerid,-1,"*"COL_LGREEN" Thank you for accepting our rules!");
			}

			if(!response)
			{
			    SendClientMessage(playerid,-1,"*"COL_RED" You have been kicked (Reason: Denying rules)");
				KickEx(playerid);
			}
		}


	}
	return 1;
}
