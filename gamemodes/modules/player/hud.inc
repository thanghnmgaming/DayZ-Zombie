function FadeTextdraw ( playerid )
{
	switch( ScreenStatus [ playerid ] )
	{
		case 1:
		{
			TextDrawBoxColor( WholeScreen, 0x000000EE );
		}
		case 2:
		{
			TextDrawBoxColor( WholeScreen, 0x000000DD );
		}
		case 3:
		{
			TextDrawBoxColor( WholeScreen, 0x000000CC );
		}
		case 4:
		{
			TextDrawBoxColor( WholeScreen, 0x000000BB );
		}
		case 5:
		{
			TextDrawBoxColor( WholeScreen, 0x000000AA );
		}
		case 6:
		{
			TextDrawBoxColor( WholeScreen, 0x00000099 );
		}
		case 7:
		{
			TextDrawBoxColor( WholeScreen, 0x00000088 );
		}
		case 8:
		{
			TextDrawBoxColor( WholeScreen, 0x00000077 );
		}
		case 9:
		{
			TextDrawBoxColor( WholeScreen, 0x00000066 );
		}
		case 10:
		{
			TextDrawBoxColor( WholeScreen, 0x00000055 );
		}
		case 11:
		{
			TextDrawBoxColor( WholeScreen, 0x00000044 );
		}
		case 12:
		{
			TextDrawBoxColor( WholeScreen, 0x00000033 );
		}
		case 13:
		{
			TextDrawBoxColor( WholeScreen, 0x00000022 );
		}
		case 14:
		{
			TextDrawBoxColor( WholeScreen, 0x00000011 );
		}
		case 15:
		{
			TextDrawBoxColor( WholeScreen, 0x00000000 );
			KillTimer( FadeTDTimer [ playerid ] );
			TextDrawHideForPlayer( playerid, WholeScreen );
			ScreenStatus [ playerid ] = 0;
			return true;
		}
	}

	TextDrawHideForPlayer( playerid, WholeScreen );
	TextDrawShowForPlayer( playerid, WholeScreen );
	return ScreenStatus [ playerid ] ++;
}

stock CreatePlayerTD(playerid)
{
    if(!IsPlayerNPC(playerid))
	{
		WebsiteLogo[playerid] = CreatePlayerTextDraw(playerid,509.000000, 4.000000, ""Web" / "Version"");
		PlayerTextDrawBackgroundColor(playerid,WebsiteLogo[playerid], 255);
		PlayerTextDrawFont(playerid,WebsiteLogo[playerid], TEXT_DRAW_FONT:2);
		PlayerTextDrawLetterSize(playerid,WebsiteLogo[playerid], 0.200000, 0.799999);
		PlayerTextDrawColor(playerid,WebsiteLogo[playerid], -16776961);
		PlayerTextDrawSetOutline(playerid,WebsiteLogo[playerid], 1);
		PlayerTextDrawSetProportional(playerid,WebsiteLogo[playerid], true);
		PlayerTextDrawSetSelectable(playerid,WebsiteLogo[playerid], false);

		MenuLogo[playerid] = CreatePlayerTextDraw(playerid,236.000000, 158.000000, "Project DayZ SA:MP");
		PlayerTextDrawBackgroundColor(playerid,MenuLogo[playerid], 255);
		PlayerTextDrawFont(playerid,MenuLogo[playerid], TEXT_DRAW_FONT:1);
		PlayerTextDrawLetterSize(playerid,MenuLogo[playerid], 0.489999, 2.399999);
		PlayerTextDrawColor(playerid,MenuLogo[playerid], 16711935);
		PlayerTextDrawSetOutline(playerid,MenuLogo[playerid], 1);
		PlayerTextDrawSetProportional(playerid,MenuLogo[playerid], true);
		PlayerTextDrawSetSelectable(playerid,MenuLogo[playerid], false);

		MenuPlay[playerid] = CreatePlayerTextDraw(playerid,251.000000, 187.000000, "     CONTINUE YOUR STORY");
		PlayerTextDrawBackgroundColor(playerid,MenuPlay[playerid], 255);
		PlayerTextDrawFont(playerid,MenuPlay[playerid], TEXT_DRAW_FONT:2);
		PlayerTextDrawLetterSize(playerid,MenuPlay[playerid], 0.229999, 1.100000);
		PlayerTextDrawColor(playerid,MenuPlay[playerid], -1);
		PlayerTextDrawSetOutline(playerid,MenuPlay[playerid], 1);
		PlayerTextDrawSetProportional(playerid,MenuPlay[playerid], true);
		PlayerTextDrawUseBox(playerid,MenuPlay[playerid], true);
		PlayerTextDrawBoxColor(playerid,MenuPlay[playerid], 3932250);
		PlayerTextDrawTextSize(playerid,MenuPlay[playerid], 389.000000, 10.0);
		PlayerTextDrawSetSelectable(playerid,MenuPlay[playerid], true);

		MenuBG[playerid] = CreatePlayerTextDraw(playerid,258.000000, 184.000000, "~n~");
		PlayerTextDrawBackgroundColor(playerid,MenuBG[playerid], 255);
		PlayerTextDrawFont(playerid,MenuBG[playerid], TEXT_DRAW_FONT:1);
		PlayerTextDrawLetterSize(playerid,MenuBG[playerid], 0.200000, 8.699995);
		PlayerTextDrawColor(playerid,MenuBG[playerid], -1);
		PlayerTextDrawSetOutline(playerid,MenuBG[playerid], 0);
		PlayerTextDrawSetProportional(playerid,MenuBG[playerid], true);
		PlayerTextDrawSetShadow(playerid,MenuBG[playerid], 1);
		PlayerTextDrawUseBox(playerid,MenuBG[playerid], true);
		PlayerTextDrawBoxColor(playerid,MenuBG[playerid], 110);
		PlayerTextDrawTextSize(playerid,MenuBG[playerid], 383.000000, 40.000000);
		PlayerTextDrawSetSelectable(playerid,MenuBG[playerid], false);

		MenuOptions[playerid] = CreatePlayerTextDraw(playerid,251.000000, 205.000000, "           CLIENT OPTIONS");
		PlayerTextDrawBackgroundColor(playerid,MenuOptions[playerid], 255);
		PlayerTextDrawFont(playerid,MenuOptions[playerid], TEXT_DRAW_FONT:2);
		PlayerTextDrawLetterSize(playerid,MenuOptions[playerid], 0.229999, 1.100000);
		PlayerTextDrawColor(playerid,MenuOptions[playerid], -1);
		PlayerTextDrawSetOutline(playerid,MenuOptions[playerid], 1);
		PlayerTextDrawSetProportional(playerid,MenuOptions[playerid], true);
		PlayerTextDrawUseBox(playerid,MenuOptions[playerid], true);
		PlayerTextDrawBoxColor(playerid,MenuOptions[playerid], 3932250);
		PlayerTextDrawTextSize(playerid,MenuOptions[playerid], 389.000000, 10.0);
		PlayerTextDrawSetSelectable(playerid,MenuOptions[playerid], true);

		MenuPremium[playerid] = CreatePlayerTextDraw(playerid,251.000000, 224.000000, "        PREMIUM PACKAGES");
		PlayerTextDrawBackgroundColor(playerid,MenuPremium[playerid], 255);
		PlayerTextDrawFont(playerid,MenuPremium[playerid], TEXT_DRAW_FONT:2);
		PlayerTextDrawLetterSize(playerid,MenuPremium[playerid], 0.229999, 1.100000);
		PlayerTextDrawColor(playerid,MenuPremium[playerid], -1);
		PlayerTextDrawSetOutline(playerid,MenuPremium[playerid], 1);
		PlayerTextDrawSetProportional(playerid,MenuPremium[playerid], true);
		PlayerTextDrawUseBox(playerid,MenuPremium[playerid], true);
		PlayerTextDrawBoxColor(playerid,MenuPremium[playerid], 3932250);
		PlayerTextDrawTextSize(playerid,MenuPremium[playerid], 389.000000, 10.0);
		PlayerTextDrawSetSelectable(playerid,MenuPremium[playerid], true);

		GeneralInfo[playerid] = CreatePlayerTextDraw(playerid,251.000000, 243.000000, "     GENERAL INFORMATION");
		PlayerTextDrawBackgroundColor(playerid,GeneralInfo[playerid], 255);
		PlayerTextDrawFont(playerid,GeneralInfo[playerid], TEXT_DRAW_FONT:2);
		PlayerTextDrawLetterSize(playerid,GeneralInfo[playerid], 0.229999, 1.100000);
		PlayerTextDrawColor(playerid,GeneralInfo[playerid], -1);
		PlayerTextDrawSetOutline(playerid,GeneralInfo[playerid], 1);
		PlayerTextDrawSetProportional(playerid,GeneralInfo[playerid], true);
		PlayerTextDrawUseBox(playerid,GeneralInfo[playerid], true);
		PlayerTextDrawBoxColor(playerid,GeneralInfo[playerid], 3932250);
		PlayerTextDrawTextSize(playerid,GeneralInfo[playerid], 389.000000, 10.0);
		PlayerTextDrawSetSelectable(playerid,GeneralInfo[playerid], true);

		MenuCredits[playerid] = CreatePlayerTextDraw(playerid,320.000000, 269.000000, "~w~Created by~g~ [pGA]AldenJ~w~~n~www.pgagaming.net to download!");
		PlayerTextDrawAlignment(playerid,MenuCredits[playerid], TEXT_DRAW_ALIGN:2);
		PlayerTextDrawBackgroundColor(playerid,MenuCredits[playerid], 255);
		PlayerTextDrawFont(playerid,MenuCredits[playerid], TEXT_DRAW_FONT:1);
		PlayerTextDrawLetterSize(playerid,MenuCredits[playerid], 0.350000, 0.699999);
		PlayerTextDrawColor(playerid,MenuCredits[playerid], -1);
		PlayerTextDrawSetOutline(playerid,MenuCredits[playerid], 1);
		PlayerTextDrawSetProportional(playerid,MenuCredits[playerid], true);
		PlayerTextDrawSetSelectable(playerid,MenuCredits[playerid], false);

		MenuBlackLayer1[playerid] = CreatePlayerTextDraw(playerid,642.000000, 1.000000, "~n~");
		PlayerTextDrawBackgroundColor(playerid,MenuBlackLayer1[playerid], 255);
		PlayerTextDrawFont(playerid,MenuBlackLayer1[playerid], TEXT_DRAW_FONT:1);
		PlayerTextDrawLetterSize(playerid,MenuBlackLayer1[playerid], 0.500000, 12.000000);
		PlayerTextDrawColor(playerid,MenuBlackLayer1[playerid], -1);
		PlayerTextDrawSetOutline(playerid,MenuBlackLayer1[playerid], 0);
		PlayerTextDrawSetProportional(playerid,MenuBlackLayer1[playerid], true);
		PlayerTextDrawSetShadow(playerid,MenuBlackLayer1[playerid], 1);
		PlayerTextDrawUseBox(playerid,MenuBlackLayer1[playerid], true);
		PlayerTextDrawBoxColor(playerid,MenuBlackLayer1[playerid], 255);
		PlayerTextDrawTextSize(playerid,MenuBlackLayer1[playerid], -10.000000, 40.000000);
		PlayerTextDrawSetSelectable(playerid,MenuBlackLayer1[playerid], false);

		MenuBlackLayer2[playerid] = CreatePlayerTextDraw(playerid,642.000000, 341.000000, "~n~");
		PlayerTextDrawBackgroundColor(playerid,MenuBlackLayer2[playerid], 255);
		PlayerTextDrawFont(playerid,MenuBlackLayer2[playerid], TEXT_DRAW_FONT:1);
		PlayerTextDrawLetterSize(playerid,MenuBlackLayer2[playerid], 0.500000, 12.000000);
		PlayerTextDrawColor(playerid,MenuBlackLayer2[playerid], -1);
		PlayerTextDrawSetOutline(playerid,MenuBlackLayer2[playerid], 0);
		PlayerTextDrawSetProportional(playerid,MenuBlackLayer2[playerid], true);
		PlayerTextDrawSetShadow(playerid,MenuBlackLayer2[playerid], 1);
		PlayerTextDrawUseBox(playerid,MenuBlackLayer2[playerid], true);
		PlayerTextDrawBoxColor(playerid,MenuBlackLayer2[playerid], 255);
		PlayerTextDrawTextSize(playerid,MenuBlackLayer2[playerid], -10.000000, 40.000000);
		PlayerTextDrawSetSelectable(playerid,MenuBlackLayer2[playerid], false);

		PlayerIntroBox[playerid] = CreatePlayerTextDraw(playerid,-39.000000, 1.000000, "~n~");
		PlayerTextDrawBackgroundColor(playerid,PlayerIntroBox[playerid], 255);
		PlayerTextDrawFont(playerid,PlayerIntroBox[playerid], TEXT_DRAW_FONT:1);
		PlayerTextDrawLetterSize(playerid,PlayerIntroBox[playerid], 0.500000, 50.000000);
		PlayerTextDrawColor(playerid,PlayerIntroBox[playerid], -1);
		PlayerTextDrawSetOutline(playerid,PlayerIntroBox[playerid], 0);
		PlayerTextDrawSetProportional(playerid,PlayerIntroBox[playerid], true);
		PlayerTextDrawSetShadow(playerid,PlayerIntroBox[playerid], 1);
		PlayerTextDrawUseBox(playerid,PlayerIntroBox[playerid], true);
		PlayerTextDrawBoxColor(playerid,PlayerIntroBox[playerid], 255);
		PlayerTextDrawTextSize(playerid,PlayerIntroBox[playerid], 647.000000, 10.000000);
		PlayerTextDrawSetSelectable(playerid,PlayerIntroBox[playerid], false);

		PlayerIntroVersion[playerid] = CreatePlayerTextDraw(playerid,389.000000, 50.000000, "DayZSA "Version"");
		PlayerTextDrawAlignment(playerid,PlayerIntroVersion[playerid], TEXT_DRAW_ALIGN:2);
		PlayerTextDrawBackgroundColor(playerid,PlayerIntroVersion[playerid], 255);
		PlayerTextDrawFont(playerid,PlayerIntroVersion[playerid], TEXT_DRAW_FONT:1);
		PlayerTextDrawLetterSize(playerid,PlayerIntroVersion[playerid], 0.899999, 6.000000);
		PlayerTextDrawColor(playerid,PlayerIntroVersion[playerid], -1);
		PlayerTextDrawSetOutline(playerid,PlayerIntroVersion[playerid], 1);
		PlayerTextDrawSetProportional(playerid,PlayerIntroVersion[playerid], true);
		PlayerTextDrawSetSelectable(playerid,PlayerIntroVersion[playerid], false);

		PlayerIntroNote[playerid] = CreatePlayerTextDraw(playerid,353.000000, 109.000000, "Welcome AldenJ~n~Please login");
		PlayerTextDrawAlignment(playerid,PlayerIntroNote[playerid], TEXT_DRAW_ALIGN:2);
		PlayerTextDrawBackgroundColor(playerid,PlayerIntroNote[playerid], 255);
		PlayerTextDrawFont(playerid,PlayerIntroNote[playerid], TEXT_DRAW_FONT:1);
		PlayerTextDrawLetterSize(playerid,PlayerIntroNote[playerid], 0.500000, 1.000000);
		PlayerTextDrawColor(playerid,PlayerIntroNote[playerid], -65281);
		PlayerTextDrawSetOutline(playerid,PlayerIntroNote[playerid], 1);
		PlayerTextDrawSetProportional(playerid,PlayerIntroNote[playerid], true);
		PlayerTextDrawSetSelectable(playerid,PlayerIntroNote[playerid], false);

	    PlayerFade[playerid] = CreatePlayerTextDraw(playerid,0.000000, 2.000000, "~n~");
		PlayerTextDrawBackgroundColor(playerid,PlayerFade[playerid], 255);
		PlayerTextDrawFont(playerid,PlayerFade[playerid], TEXT_DRAW_FONT:1);
		PlayerTextDrawLetterSize(playerid,PlayerFade[playerid], 0.500000, 50.000000);
		PlayerTextDrawColor(playerid,PlayerFade[playerid], -1);
		PlayerTextDrawSetOutline(playerid,PlayerFade[playerid], 0);
		PlayerTextDrawSetProportional(playerid,PlayerFade[playerid], true);
		PlayerTextDrawSetShadow(playerid,PlayerFade[playerid], 1);
		PlayerTextDrawUseBox(playerid,PlayerFade[playerid], true);
		PlayerTextDrawBoxColor(playerid,PlayerFade[playerid], 135);
		PlayerTextDrawTextSize(playerid,PlayerFade[playerid], 641.000000, -2.000000);
		PlayerTextDrawSetSelectable(playerid,PlayerFade[playerid], false);

		Map[playerid] = CreatePlayerTextDraw(playerid,89.000000, 13.000000, "samaps:map");
		PlayerTextDrawBackgroundColor(playerid,Map[playerid], 255);
		PlayerTextDrawFont(playerid,Map[playerid], TEXT_DRAW_FONT:4);
		PlayerTextDrawLetterSize(playerid,Map[playerid], 0.500000, 1.000000);
		PlayerTextDrawColor(playerid,Map[playerid], -1);
		PlayerTextDrawSetOutline(playerid,Map[playerid], 0);
		PlayerTextDrawSetProportional(playerid,Map[playerid], true);
		PlayerTextDrawSetShadow(playerid,Map[playerid], 1);
		PlayerTextDrawUseBox(playerid,Map[playerid], true);
		PlayerTextDrawBoxColor(playerid,Map[playerid], 255);
		PlayerTextDrawTextSize(playerid,Map[playerid], 470.000000, 410.000000);

		LegBroken[playerid] = CreatePlayerTextDraw(playerid,532.000000, 325.000000, "Broken Leg");
		PlayerTextDrawBackgroundColor(playerid,LegBroken[playerid], 255);
		PlayerTextDrawFont(playerid,LegBroken[playerid], TEXT_DRAW_FONT:2);
		PlayerTextDrawLetterSize(playerid,LegBroken[playerid], 0.200000, 0.899999);
		PlayerTextDrawColor(playerid,LegBroken[playerid], -16776961);
		PlayerTextDrawSetOutline(playerid,LegBroken[playerid], 0);
		PlayerTextDrawSetProportional(playerid,LegBroken[playerid], true);
		PlayerTextDrawSetShadow(playerid,LegBroken[playerid], 1);
		
		playerBandit[playerid] = CreatePlayerTextDraw(playerid,611.000000, 315.000000, "hud:radar_locosyndicate");
		PlayerTextDrawBackgroundColor(playerid,playerBandit[playerid], 255);
		PlayerTextDrawFont(playerid,playerBandit[playerid], TEXT_DRAW_FONT:4);
		PlayerTextDrawLetterSize(playerid,playerBandit[playerid], 0.600000, 2.000000);
		PlayerTextDrawColor(playerid,playerBandit[playerid], 866792277);
		PlayerTextDrawSetOutline(playerid,playerBandit[playerid], 0);
		PlayerTextDrawSetProportional(playerid,playerBandit[playerid], true);
		PlayerTextDrawSetShadow(playerid,playerBandit[playerid], 1);
		PlayerTextDrawUseBox(playerid,playerBandit[playerid], true);
		PlayerTextDrawBoxColor(playerid,playerBandit[playerid], 5243060);
		PlayerTextDrawTextSize(playerid,playerBandit[playerid], 15.000000, 16.000000);
		PlayerTextDrawSetSelectable(playerid,playerBandit[playerid], false);

		PlayerTemp[playerid] = CreatePlayerTextDraw(playerid,611.000000, 334.000000, "hud:radar_toreno");
		PlayerTextDrawBackgroundColor(playerid,PlayerTemp[playerid], 255);
		PlayerTextDrawFont(playerid,PlayerTemp[playerid], TEXT_DRAW_FONT:4);
		PlayerTextDrawLetterSize(playerid,PlayerTemp[playerid], 0.600000, 2.000000);
		PlayerTextDrawColor(playerid,PlayerTemp[playerid], 866792277);
		PlayerTextDrawSetOutline(playerid,PlayerTemp[playerid], 0);
		PlayerTextDrawSetProportional(playerid,PlayerTemp[playerid], true);
		PlayerTextDrawSetShadow(playerid,PlayerTemp[playerid], 1);
		PlayerTextDrawUseBox(playerid,PlayerTemp[playerid], true);
		PlayerTextDrawBoxColor(playerid,PlayerTemp[playerid], 5243060);
		PlayerTextDrawTextSize(playerid,PlayerTemp[playerid], 15.000000, 16.000000);
		PlayerTextDrawSetSelectable(playerid,PlayerTemp[playerid], false);

		/*PlayerTemp[playerid] = CreatePlayerTextDraw(playerid,606.000000, 330.000000, "temperature");
		PlayerTextDrawBackgroundColor(playerid,PlayerTemp[playerid], -256);
		PlayerTextDrawFont(playerid,PlayerTemp[playerid], TEXT_DRAW_FONT:5);
		PlayerTextDrawLetterSize(playerid,PlayerTemp[playerid], 0.500000, 1.000000);
		PlayerTextDrawColor(playerid,PlayerTemp[playerid], 866792277);
		PlayerTextDrawSetOutline(playerid,PlayerTemp[playerid], 0);
		PlayerTextDrawSetProportional(playerid,PlayerTemp[playerid], true);
		PlayerTextDrawSetShadow(playerid,PlayerTemp[playerid], 1);
		PlayerTextDrawUseBox(playerid,PlayerTemp[playerid], true);
		PlayerTextDrawBoxColor(playerid,PlayerTemp[playerid], 16711935);
		PlayerTextDrawTextSize(playerid,PlayerTemp[playerid], 26.000000, 29.000000);
		PlayerTextDrawSetPreviewModel(playerid, PlayerTemp[playerid], 19131);
		PlayerTextDrawSetPreviewRot(playerid, PlayerTemp[playerid], -16.000000, 95.000000, -55.000000, 1.000000);
		PlayerTextDrawSetSelectable(playerid,PlayerTemp[playerid], false);*/

		PlayerThirst[playerid] = CreatePlayerTextDraw(playerid,612.000000, 359.000000, "hud:radar_diner");
		PlayerTextDrawBackgroundColor(playerid,PlayerThirst[playerid], 255);
		PlayerTextDrawFont(playerid,PlayerThirst[playerid], TEXT_DRAW_FONT:4);
		PlayerTextDrawLetterSize(playerid,PlayerThirst[playerid], 0.600000, 2.000000);
		PlayerTextDrawColor(playerid,PlayerThirst[playerid], 866792277);
		PlayerTextDrawSetOutline(playerid,PlayerThirst[playerid], 0);
		PlayerTextDrawSetProportional(playerid,PlayerThirst[playerid], true);
		PlayerTextDrawSetShadow(playerid,PlayerThirst[playerid], 1);
		PlayerTextDrawUseBox(playerid,PlayerThirst[playerid], true);
		PlayerTextDrawBoxColor(playerid,PlayerThirst[playerid], 5243060);
		PlayerTextDrawTextSize(playerid,PlayerThirst[playerid], 15.000000, 16.000000);
		PlayerTextDrawSetSelectable(playerid,PlayerThirst[playerid], false);

		PlayerBlood[playerid] = CreatePlayerTextDraw(playerid,612.000000, 381.000000, "hud:radar_hostpital");
		PlayerTextDrawBackgroundColor(playerid,PlayerBlood[playerid], 255);
		PlayerTextDrawFont(playerid,PlayerBlood[playerid], TEXT_DRAW_FONT:4);
		PlayerTextDrawLetterSize(playerid,PlayerBlood[playerid], 0.600000, 2.000000);
		PlayerTextDrawColor(playerid,PlayerBlood[playerid], 866792277);
		PlayerTextDrawSetOutline(playerid,PlayerBlood[playerid], 0);
		PlayerTextDrawSetProportional(playerid,PlayerBlood[playerid], true);
		PlayerTextDrawSetShadow(playerid,PlayerBlood[playerid], 1);
		PlayerTextDrawUseBox(playerid,PlayerBlood[playerid], true);
		PlayerTextDrawBoxColor(playerid,PlayerBlood[playerid], 5243060);
		PlayerTextDrawTextSize(playerid,PlayerBlood[playerid], 15.000000, 16.000000);
		PlayerTextDrawSetSelectable(playerid,PlayerBlood[playerid], false);

		PlayerHunger[playerid] = CreatePlayerTextDraw(playerid,612.000000, 404.000000, "hud:radar_datefood");
		PlayerTextDrawBackgroundColor(playerid,PlayerHunger[playerid], 255);
		PlayerTextDrawFont(playerid,PlayerHunger[playerid], TEXT_DRAW_FONT:4);
		PlayerTextDrawLetterSize(playerid,PlayerHunger[playerid], 0.600000, 2.000000);
		PlayerTextDrawColor(playerid,PlayerHunger[playerid], 866792277);
		PlayerTextDrawSetOutline(playerid,PlayerHunger[playerid], 0);
		PlayerTextDrawSetProportional(playerid,PlayerHunger[playerid], true);
		PlayerTextDrawSetShadow(playerid,PlayerHunger[playerid], 1);
		PlayerTextDrawUseBox(playerid,PlayerHunger[playerid], true);
		PlayerTextDrawBoxColor(playerid,PlayerHunger[playerid], 5243060);
		PlayerTextDrawTextSize(playerid,PlayerHunger[playerid], 15.000000, 16.000000);
		PlayerTextDrawSetSelectable(playerid,PlayerHunger[playerid], false);
		
		PlayerVehicleName[playerid] = CreatePlayerTextDraw(playerid,54.000000, 238.000000, "Clover");
		PlayerTextDrawAlignment(playerid,PlayerVehicleName[playerid], TEXT_DRAW_ALIGN:2);
		PlayerTextDrawBackgroundColor(playerid,PlayerVehicleName[playerid], 255);
		PlayerTextDrawFont(playerid,PlayerVehicleName[playerid], TEXT_DRAW_FONT:1);
		PlayerTextDrawLetterSize(playerid,PlayerVehicleName[playerid], 0.460000, 0.899999);
		PlayerTextDrawColor(playerid,PlayerVehicleName[playerid], -1);
		PlayerTextDrawSetOutline(playerid,PlayerVehicleName[playerid], 1);
		PlayerTextDrawSetProportional(playerid,PlayerVehicleName[playerid], true);
		PlayerTextDrawSetSelectable(playerid,PlayerVehicleName[playerid], false);
		

		vehicleInfo[playerid] = CreatePlayerTextDraw(playerid,46.000000, 256.000000, "0 / 0~n~~n~0 / 0~n~~n~0 / 0~n~~n~22 KM/H");
		PlayerTextDrawAlignment(playerid,vehicleInfo[playerid], TEXT_DRAW_ALIGN:2);
		PlayerTextDrawBackgroundColor(playerid,vehicleInfo[playerid], 255);
		PlayerTextDrawFont(playerid,vehicleInfo[playerid], TEXT_DRAW_FONT:2);
		PlayerTextDrawLetterSize(playerid,vehicleInfo[playerid], 0.390000, 0.799998);
		PlayerTextDrawColor(playerid,vehicleInfo[playerid], -1);
		PlayerTextDrawSetOutline(playerid,vehicleInfo[playerid], 0);
		PlayerTextDrawSetProportional(playerid,vehicleInfo[playerid], true);
		PlayerTextDrawSetShadow(playerid,vehicleInfo[playerid], 1);
		PlayerTextDrawSetSelectable(playerid,vehicleInfo[playerid], false);

		
		EngineIcon[playerid] = CreatePlayerTextDraw(playerid,66.000000, 247.000000, "Engine");
		PlayerTextDrawBackgroundColor(playerid,EngineIcon[playerid], 0);
		PlayerTextDrawFont(playerid,EngineIcon[playerid], TEXT_DRAW_FONT:5);
		PlayerTextDrawLetterSize(playerid,EngineIcon[playerid], 0.300000, 3.300000);
		PlayerTextDrawColor(playerid,EngineIcon[playerid], -1);
		PlayerTextDrawSetOutline(playerid,EngineIcon[playerid], 0);
		PlayerTextDrawSetProportional(playerid,EngineIcon[playerid], true);
		PlayerTextDrawSetShadow(playerid,EngineIcon[playerid], 1);
		PlayerTextDrawUseBox(playerid,EngineIcon[playerid], true);
		PlayerTextDrawBoxColor(playerid,EngineIcon[playerid], -16776961);
		PlayerTextDrawTextSize(playerid,EngineIcon[playerid], 23.000000, 22.000000);
		PlayerTextDrawSetPreviewModel(playerid, EngineIcon[playerid], 19917);
		PlayerTextDrawSetPreviewRot(playerid, EngineIcon[playerid], -16.000000, 0.000000, -55.000000, 1.000000);
		PlayerTextDrawSetSelectable(playerid,EngineIcon[playerid], false);

		SpeedIcon[playerid] = CreatePlayerTextDraw(playerid,72.000000, 293.000000, "SpeedIcon");
		PlayerTextDrawBackgroundColor(playerid,SpeedIcon[playerid], 0);
		PlayerTextDrawFont(playerid,SpeedIcon[playerid], TEXT_DRAW_FONT:5);
		PlayerTextDrawLetterSize(playerid,SpeedIcon[playerid], 0.319999, 3.300000);
		PlayerTextDrawColor(playerid,SpeedIcon[playerid], -1);
		PlayerTextDrawSetOutline(playerid,SpeedIcon[playerid], 0);
		PlayerTextDrawSetProportional(playerid,SpeedIcon[playerid], true);
		PlayerTextDrawSetShadow(playerid,SpeedIcon[playerid], 1);
		PlayerTextDrawUseBox(playerid,SpeedIcon[playerid], true);
		PlayerTextDrawBoxColor(playerid,SpeedIcon[playerid], -16776961);
		PlayerTextDrawTextSize(playerid,SpeedIcon[playerid], 38.000000, 21.000000);
		PlayerTextDrawSetPreviewModel(playerid, SpeedIcon[playerid], 471);
		PlayerTextDrawSetPreviewRot(playerid, SpeedIcon[playerid], -16.000000, 0.000000, -55.000000, 1.000000);
		PlayerTextDrawSetSelectable(playerid,SpeedIcon[playerid], false);

		TireIcon[playerid] = CreatePlayerTextDraw(playerid,71.000000, 269.000000, "Tire");
		PlayerTextDrawBackgroundColor(playerid,TireIcon[playerid], 0);
		PlayerTextDrawFont(playerid,TireIcon[playerid], TEXT_DRAW_FONT:5);
		PlayerTextDrawLetterSize(playerid,TireIcon[playerid], 0.319999, 3.300000);
		PlayerTextDrawColor(playerid,TireIcon[playerid], -1);
		PlayerTextDrawSetOutline(playerid,TireIcon[playerid], 0);
		PlayerTextDrawSetProportional(playerid,TireIcon[playerid], true);
		PlayerTextDrawSetShadow(playerid,TireIcon[playerid], 1);
		PlayerTextDrawUseBox(playerid,TireIcon[playerid], true);
		PlayerTextDrawBoxColor(playerid,TireIcon[playerid], -16776961);
		PlayerTextDrawTextSize(playerid,TireIcon[playerid], 15.000000, 11.000000);
		PlayerTextDrawSetPreviewModel(playerid, TireIcon[playerid], 1327);
		PlayerTextDrawSetPreviewRot(playerid, TireIcon[playerid], -16.000000, 0.000000, -55.000000, 1.000000);
		PlayerTextDrawSetSelectable(playerid,TireIcon[playerid], false);

		FuelIcon[playerid] = CreatePlayerTextDraw(playerid,60.000000, 281.000000, "Fuel");
		PlayerTextDrawBackgroundColor(playerid,FuelIcon[playerid], 0);
		PlayerTextDrawFont(playerid,FuelIcon[playerid], TEXT_DRAW_FONT:5);
		PlayerTextDrawLetterSize(playerid,FuelIcon[playerid], 0.319999, 3.300000);
		PlayerTextDrawColor(playerid,FuelIcon[playerid], -1);
		PlayerTextDrawSetOutline(playerid,FuelIcon[playerid], 0);
		PlayerTextDrawSetProportional(playerid,FuelIcon[playerid], true);
		PlayerTextDrawSetShadow(playerid,FuelIcon[playerid], 1);
		PlayerTextDrawUseBox(playerid,FuelIcon[playerid], true);
		PlayerTextDrawBoxColor(playerid,FuelIcon[playerid], -16776961);
		PlayerTextDrawTextSize(playerid,FuelIcon[playerid], 33.000000, 18.000000);
		PlayerTextDrawSetPreviewModel(playerid, FuelIcon[playerid], 1650);
		PlayerTextDrawSetPreviewRot(playerid, FuelIcon[playerid], -16.000000, 0.000000, -55.000000, 1.000000);
		PlayerTextDrawSetSelectable(playerid,FuelIcon[playerid], false);

		HudBG_1[playerid] = CreatePlayerTextDraw(playerid,496.000000, 10.000000, "~n~");
		PlayerTextDrawBackgroundColor(playerid,HudBG_1[playerid], 255);
		PlayerTextDrawFont(playerid,HudBG_1[playerid], TEXT_DRAW_FONT:1);
		PlayerTextDrawLetterSize(playerid,HudBG_1[playerid], 0.500000, 10.000000);
		PlayerTextDrawColor(playerid,HudBG_1[playerid], -1);
		PlayerTextDrawSetOutline(playerid,HudBG_1[playerid], 0);
		PlayerTextDrawSetProportional(playerid,HudBG_1[playerid], true);
		PlayerTextDrawSetShadow(playerid,HudBG_1[playerid], 1);
		PlayerTextDrawUseBox(playerid,HudBG_1[playerid], true);
		PlayerTextDrawBoxColor(playerid,HudBG_1[playerid], 1077159679);
		PlayerTextDrawTextSize(playerid,HudBG_1[playerid], 615.000000, 0.000000);
		PlayerTextDrawSetSelectable(playerid,HudBG_1[playerid], false);

		DebugMonitor_Text[playerid] = CreatePlayerTextDraw(playerid,558.000000, 17.000000, "Debug Monitor");
		PlayerTextDrawAlignment(playerid,DebugMonitor_Text[playerid], TEXT_DRAW_ALIGN:2);
		PlayerTextDrawBackgroundColor(playerid,DebugMonitor_Text[playerid], 255);
		PlayerTextDrawFont(playerid,DebugMonitor_Text[playerid], TEXT_DRAW_FONT:2);
		PlayerTextDrawLetterSize(playerid,DebugMonitor_Text[playerid], 0.339999, 1.000000);
		PlayerTextDrawColor(playerid,DebugMonitor_Text[playerid], -16776961);
		PlayerTextDrawSetOutline(playerid,DebugMonitor_Text[playerid], 1);
		PlayerTextDrawSetProportional(playerid,DebugMonitor_Text[playerid], true);
		PlayerTextDrawSetSelectable(playerid,DebugMonitor_Text[playerid], false);

		DebugInfo[playerid]  = CreatePlayerTextDraw(playerid,554.000000, 29.000000, "Zombies Killed: %i~n~Headshots: %i~n~Murders: %i~n~Bandits Killed: %i~n~Blood: %i~n~Zombies: %i~n~Temperature: %0.2f F~n~Alive T");
		PlayerTextDrawAlignment(playerid,DebugInfo[playerid] , TEXT_DRAW_ALIGN:2);
		PlayerTextDrawBackgroundColor(playerid,DebugInfo[playerid] , 255);
		PlayerTextDrawFont(playerid,DebugInfo[playerid] , TEXT_DRAW_FONT:2);
		PlayerTextDrawLetterSize(playerid,DebugInfo[playerid] , 0.240000, 0.899999);
		PlayerTextDrawColor(playerid,DebugInfo[playerid] , -1);
		PlayerTextDrawSetOutline(playerid,DebugInfo[playerid] , 0);
		PlayerTextDrawSetProportional(playerid,DebugInfo[playerid] , true);
		PlayerTextDrawSetShadow(playerid,DebugInfo[playerid] , 1);
		PlayerTextDrawSetSelectable(playerid,DebugInfo[playerid] , false);

		Debug_GunIcon[playerid] = CreatePlayerTextDraw(playerid,491.000000, 110.000000, "hud:radar_emmetgun");
		PlayerTextDrawAlignment(playerid,Debug_GunIcon[playerid], TEXT_DRAW_ALIGN:2);
		PlayerTextDrawBackgroundColor(playerid,Debug_GunIcon[playerid], 255);
		PlayerTextDrawFont(playerid,Debug_GunIcon[playerid], TEXT_DRAW_FONT:4);
		PlayerTextDrawLetterSize(playerid,Debug_GunIcon[playerid], 0.339999, -1.100000);
		PlayerTextDrawColor(playerid,Debug_GunIcon[playerid], -1);
		PlayerTextDrawSetOutline(playerid,Debug_GunIcon[playerid], 0);
		PlayerTextDrawSetProportional(playerid,Debug_GunIcon[playerid], true);
		PlayerTextDrawSetShadow(playerid,Debug_GunIcon[playerid], 1);
		PlayerTextDrawUseBox(playerid,Debug_GunIcon[playerid], true);
		PlayerTextDrawBoxColor(playerid,Debug_GunIcon[playerid], 16711935);
		PlayerTextDrawTextSize(playerid,Debug_GunIcon[playerid], 15.000000, 7.000000);
		PlayerTextDrawSetSelectable(playerid,Debug_GunIcon[playerid], false);

		Debug_GunInfo[playerid]  = CreatePlayerTextDraw(playerid,511.000000, 110.000000, "Sniper Rifle / 10 Ammo");
		PlayerTextDrawBackgroundColor(playerid,Debug_GunInfo[playerid] , 255);
		PlayerTextDrawFont(playerid,Debug_GunInfo[playerid] , TEXT_DRAW_FONT:2);
		PlayerTextDrawLetterSize(playerid,Debug_GunInfo[playerid] , 0.190000, 0.799999);
		PlayerTextDrawColor(playerid,Debug_GunInfo[playerid] , -1);
		PlayerTextDrawSetOutline(playerid,Debug_GunInfo[playerid] , 1);
		PlayerTextDrawSetProportional(playerid,Debug_GunInfo[playerid] , true);
		PlayerTextDrawSetSelectable(playerid,Debug_GunInfo[playerid] , false);


		PlayerEye[playerid] = CreatePlayerTextDraw(playerid,610.000000, 164.000000, "hud:radar_light");
		PlayerTextDrawBackgroundColor(playerid,PlayerEye[playerid], 255);
		PlayerTextDrawFont(playerid,PlayerEye[playerid], TEXT_DRAW_FONT:4);
		PlayerTextDrawLetterSize(playerid,PlayerEye[playerid], 0.600000, 2.000000);
		PlayerTextDrawColor(playerid,PlayerEye[playerid], 866792277);
		PlayerTextDrawSetOutline(playerid,PlayerEye[playerid], 0);
		PlayerTextDrawSetProportional(playerid,PlayerEye[playerid], true);
		PlayerTextDrawSetShadow(playerid,PlayerEye[playerid], 1);
		PlayerTextDrawUseBox(playerid,PlayerEye[playerid], true);
		PlayerTextDrawBoxColor(playerid,PlayerEye[playerid], 5243060);
		PlayerTextDrawTextSize(playerid,PlayerEye[playerid], 15.000000, 16.000000);
		PlayerTextDrawSetSelectable(playerid,PlayerEye[playerid], false);

		PlayerNoise[playerid] = CreatePlayerTextDraw(playerid,626.000000, 205.000000, "hud:radar_spray");
		PlayerTextDrawBackgroundColor(playerid,PlayerNoise[playerid], 255);
		PlayerTextDrawFont(playerid,PlayerNoise[playerid], TEXT_DRAW_FONT:4);
		PlayerTextDrawLetterSize(playerid,PlayerNoise[playerid], 0.750000, 9.299999);
		PlayerTextDrawColor(playerid,PlayerNoise[playerid], 866792277);
		PlayerTextDrawSetOutline(playerid,PlayerNoise[playerid], 0);
		PlayerTextDrawSetProportional(playerid,PlayerNoise[playerid], true);
		PlayerTextDrawSetShadow(playerid,PlayerNoise[playerid], 1);
		PlayerTextDrawUseBox(playerid,PlayerNoise[playerid], true);
		PlayerTextDrawBoxColor(playerid,PlayerNoise[playerid], 5243060);
		PlayerTextDrawTextSize(playerid,PlayerNoise[playerid], -15.000000, 17.000000);
		PlayerTextDrawSetSelectable(playerid,PlayerNoise[playerid], false);

		EyeLevel1[playerid] = CreatePlayerTextDraw(playerid,605.000000, 159.000000, "(");
		PlayerTextDrawBackgroundColor(playerid,EyeLevel1[playerid], -256);
		PlayerTextDrawFont(playerid,EyeLevel1[playerid], TEXT_DRAW_FONT:1);
		PlayerTextDrawLetterSize(playerid,EyeLevel1[playerid], 0.800000, 2.400000);
		PlayerTextDrawColor(playerid,EyeLevel1[playerid], 85);
		PlayerTextDrawSetOutline(playerid,EyeLevel1[playerid], 0);
		PlayerTextDrawSetProportional(playerid,EyeLevel1[playerid], true);
		PlayerTextDrawSetShadow(playerid,EyeLevel1[playerid], 1);
		PlayerTextDrawSetPreviewModel(playerid, EyeLevel1[playerid], 18843);
		PlayerTextDrawSetPreviewRot(playerid, EyeLevel1[playerid], -16.000000, 0.000000, -55.000000, 1.000000);
		PlayerTextDrawSetSelectable(playerid,EyeLevel1[playerid], false);

		EyeLevel2[playerid] = CreatePlayerTextDraw(playerid,600.000000, 155.000000, "(");
		PlayerTextDrawBackgroundColor(playerid,EyeLevel2[playerid], -256);
		PlayerTextDrawFont(playerid,EyeLevel2[playerid], TEXT_DRAW_FONT:1);
		PlayerTextDrawLetterSize(playerid,EyeLevel2[playerid], 0.810000, 3.199999);
		PlayerTextDrawColor(playerid,EyeLevel2[playerid], 85);
		PlayerTextDrawSetOutline(playerid,EyeLevel2[playerid], 0);
		PlayerTextDrawSetProportional(playerid,EyeLevel2[playerid], true);
		PlayerTextDrawSetShadow(playerid,EyeLevel2[playerid], 1);
		PlayerTextDrawSetPreviewModel(playerid, EyeLevel2[playerid], 18843);
		PlayerTextDrawSetPreviewRot(playerid, EyeLevel2[playerid], -16.000000, 0.000000, -55.000000, 1.000000);
		PlayerTextDrawSetSelectable(playerid,EyeLevel2[playerid], false);

		EyeLevel3[playerid] = CreatePlayerTextDraw(playerid,595.000000, 151.000000, "(");
		PlayerTextDrawBackgroundColor(playerid,EyeLevel3[playerid], -256);
		PlayerTextDrawFont(playerid,EyeLevel3[playerid], TEXT_DRAW_FONT:1);
		PlayerTextDrawLetterSize(playerid,EyeLevel3[playerid], 0.800000, 3.799998);
		PlayerTextDrawColor(playerid,EyeLevel3[playerid], 85);
		PlayerTextDrawSetOutline(playerid,EyeLevel3[playerid], 0);
		PlayerTextDrawSetProportional(playerid,EyeLevel3[playerid], true);
		PlayerTextDrawSetShadow(playerid,EyeLevel3[playerid], 1);
		PlayerTextDrawSetPreviewModel(playerid, EyeLevel3[playerid], 18843);
		PlayerTextDrawSetPreviewRot(playerid, EyeLevel3[playerid], -16.000000, 0.000000, -55.000000, 1.000000);
		PlayerTextDrawSetSelectable(playerid,EyeLevel3[playerid], false);

		EyeLevel4[playerid] = CreatePlayerTextDraw(playerid,590.000000, 148.000000, "(");
		PlayerTextDrawBackgroundColor(playerid,EyeLevel4[playerid], -256);
		PlayerTextDrawFont(playerid,EyeLevel4[playerid], TEXT_DRAW_FONT:1);
		PlayerTextDrawLetterSize(playerid,EyeLevel4[playerid], 0.800000, 4.499999);
		PlayerTextDrawColor(playerid,EyeLevel4[playerid], 85);
		PlayerTextDrawSetOutline(playerid,EyeLevel4[playerid], 0);
		PlayerTextDrawSetProportional(playerid,EyeLevel4[playerid], true);
		PlayerTextDrawSetShadow(playerid,EyeLevel4[playerid], 1);
		PlayerTextDrawSetPreviewModel(playerid, EyeLevel4[playerid], 18843);
		PlayerTextDrawSetPreviewRot(playerid, EyeLevel4[playerid], -16.000000, 0.000000, -55.000000, 1.000000);
		PlayerTextDrawSetSelectable(playerid,EyeLevel4[playerid], false);

		NoiseLevel1[playerid] = CreatePlayerTextDraw(playerid,605.000000, 196.000000, "(");
		PlayerTextDrawBackgroundColor(playerid,NoiseLevel1[playerid], -256);
		PlayerTextDrawFont(playerid,NoiseLevel1[playerid], TEXT_DRAW_FONT:1);
		PlayerTextDrawLetterSize(playerid,NoiseLevel1[playerid], 0.800000, 2.400000);
		PlayerTextDrawColor(playerid,NoiseLevel1[playerid], 85);
		PlayerTextDrawSetOutline(playerid,NoiseLevel1[playerid], 0);
		PlayerTextDrawSetProportional(playerid,NoiseLevel1[playerid], true);
		PlayerTextDrawSetShadow(playerid,NoiseLevel1[playerid], 1);
		PlayerTextDrawSetPreviewModel(playerid, NoiseLevel1[playerid], 18843);
		PlayerTextDrawSetPreviewRot(playerid, NoiseLevel1[playerid], -16.000000, 0.000000, -55.000000, 1.000000);
		PlayerTextDrawSetSelectable(playerid,NoiseLevel1[playerid], false);

		NoiseLevel2[playerid] = CreatePlayerTextDraw(playerid,600.000000, 191.000000, "(");
		PlayerTextDrawBackgroundColor(playerid,NoiseLevel2[playerid], -256);
		PlayerTextDrawFont(playerid,NoiseLevel2[playerid], TEXT_DRAW_FONT:1);
		PlayerTextDrawLetterSize(playerid,NoiseLevel2[playerid], 0.810000, 3.199999);
		PlayerTextDrawColor(playerid,NoiseLevel2[playerid], 85);
		PlayerTextDrawSetOutline(playerid,NoiseLevel2[playerid], 0);
		PlayerTextDrawSetProportional(playerid,NoiseLevel2[playerid], true);
		PlayerTextDrawSetShadow(playerid,NoiseLevel2[playerid], 1);
		PlayerTextDrawSetPreviewModel(playerid, NoiseLevel2[playerid], 18843);
		PlayerTextDrawSetPreviewRot(playerid, NoiseLevel2[playerid], -16.000000, 0.000000, -55.000000, 1.000000);
		PlayerTextDrawSetSelectable(playerid,NoiseLevel2[playerid], false);

		NoiseLevel3[playerid] = CreatePlayerTextDraw(playerid,595.000000, 187.000000, "(");
		PlayerTextDrawBackgroundColor(playerid,NoiseLevel3[playerid], -256);
		PlayerTextDrawFont(playerid,NoiseLevel3[playerid], TEXT_DRAW_FONT:1);
		PlayerTextDrawLetterSize(playerid,NoiseLevel3[playerid], 0.800000, 3.799998);
		PlayerTextDrawColor(playerid,NoiseLevel3[playerid], 85);
		PlayerTextDrawSetOutline(playerid,NoiseLevel3[playerid], 0);
		PlayerTextDrawSetProportional(playerid,NoiseLevel3[playerid], true);
		PlayerTextDrawSetShadow(playerid,NoiseLevel3[playerid], 1);
		PlayerTextDrawSetPreviewModel(playerid, NoiseLevel3[playerid], 18843);
		PlayerTextDrawSetPreviewRot(playerid, NoiseLevel3[playerid], -16.000000, 0.000000, -55.000000, 1.000000);
		PlayerTextDrawSetSelectable(playerid,NoiseLevel3[playerid], false);

		NoiseLevel4[playerid] = CreatePlayerTextDraw(playerid,590.000000, 182.000000, "(");
		PlayerTextDrawBackgroundColor(playerid,NoiseLevel4[playerid], -256);
		PlayerTextDrawFont(playerid,NoiseLevel4[playerid], TEXT_DRAW_FONT:1);
		PlayerTextDrawLetterSize(playerid,NoiseLevel4[playerid], 0.800000, 4.499999);
		PlayerTextDrawColor(playerid,NoiseLevel4[playerid], 85);
		PlayerTextDrawSetOutline(playerid,NoiseLevel4[playerid], 0);
		PlayerTextDrawSetProportional(playerid,NoiseLevel4[playerid], true);
		PlayerTextDrawSetShadow(playerid,NoiseLevel4[playerid], 1);
		PlayerTextDrawSetPreviewModel(playerid, NoiseLevel4[playerid], 18843);
		PlayerTextDrawSetPreviewRot(playerid, NoiseLevel4[playerid], -16.000000, 0.000000, -55.000000, 1.000000);
		PlayerTextDrawSetSelectable(playerid,NoiseLevel4[playerid], false);

		IndicatorBox[playerid] = CreatePlayerTextDraw(playerid, 428.444458, 398.753326, "usebox");
		PlayerTextDrawLetterSize(playerid, IndicatorBox[playerid], 0.000000, -2.584319);
		PlayerTextDrawTextSize(playerid, IndicatorBox[playerid], 622.444458, 0.000000);
		PlayerTextDrawAlignment(playerid, IndicatorBox[playerid], TEXT_DRAW_ALIGN:1);
		PlayerTextDrawColor(playerid, IndicatorBox[playerid], 0);
		PlayerTextDrawUseBox(playerid, IndicatorBox[playerid], true);
		PlayerTextDrawBoxColor(playerid, IndicatorBox[playerid], 102);
		PlayerTextDrawSetShadow(playerid, IndicatorBox[playerid], 0);
		PlayerTextDrawFont(playerid, IndicatorBox[playerid], TEXT_DRAW_FONT:0);
		
		VehicleBG[playerid] = CreatePlayerTextDraw(playerid,12.000000, 238.000000, "~n~");
		PlayerTextDrawBackgroundColor(playerid,VehicleBG[playerid], 255);
		PlayerTextDrawFont(playerid,VehicleBG[playerid], TEXT_DRAW_FONT:1);
		PlayerTextDrawLetterSize(playerid,VehicleBG[playerid], 0.460000, 8.899999);
		PlayerTextDrawColor(playerid,VehicleBG[playerid], -1);
		PlayerTextDrawSetOutline(playerid,VehicleBG[playerid], 0);
		PlayerTextDrawSetProportional(playerid,VehicleBG[playerid], true);
		PlayerTextDrawSetShadow(playerid,VehicleBG[playerid], 1);
		PlayerTextDrawUseBox(playerid,VehicleBG[playerid], true);
		PlayerTextDrawBoxColor(playerid,VehicleBG[playerid], 225);
		PlayerTextDrawTextSize(playerid,VehicleBG[playerid], 105.000000, -235.000000);
		PlayerTextDrawSetSelectable(playerid,VehicleBG[playerid], false);


		Indicator[playerid] = CreatePlayerTextDraw(playerid, 540.000183, 380.826660, "Hit: 4 - 150 dmg");
		PlayerTextDrawLetterSize(playerid, Indicator[playerid], 0.227333, 1.346132);
		PlayerTextDrawAlignment(playerid, Indicator[playerid], TEXT_DRAW_ALIGN:1);
		PlayerTextDrawColor(playerid, Indicator[playerid], -1);
		PlayerTextDrawSetShadow(playerid, Indicator[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Indicator[playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, Indicator[playerid], 51);
		PlayerTextDrawFont(playerid, Indicator[playerid], TEXT_DRAW_FONT:1);
		PlayerTextDrawSetProportional(playerid, Indicator[playerid], true);

		IndicatorBox1[playerid] = CreatePlayerTextDraw(playerid, 428.444458, 382.753326, "usebox");
		PlayerTextDrawLetterSize(playerid, IndicatorBox1[playerid], 0.000000, -2.584319);
		PlayerTextDrawTextSize(playerid, IndicatorBox1[playerid], 622.444458, 0.000000);
		PlayerTextDrawAlignment(playerid, IndicatorBox1[playerid], TEXT_DRAW_ALIGN:1);
		PlayerTextDrawColor(playerid, IndicatorBox1[playerid], 0);
		PlayerTextDrawUseBox(playerid, IndicatorBox1[playerid], true);
		PlayerTextDrawBoxColor(playerid, IndicatorBox1[playerid], 102);
		PlayerTextDrawSetShadow(playerid, IndicatorBox1[playerid], 0);
		PlayerTextDrawFont(playerid, IndicatorBox1[playerid], TEXT_DRAW_FONT:0);

		Indicator1[playerid] = CreatePlayerTextDraw(playerid, 430.000183, 363.826660, "Hit: 4 - 150 dmg");
		PlayerTextDrawLetterSize(playerid, Indicator1[playerid], 0.227333, 1.346132);
		PlayerTextDrawAlignment(playerid, Indicator1[playerid], TEXT_DRAW_ALIGN:1);
		PlayerTextDrawColor(playerid, Indicator1[playerid], -1);
		PlayerTextDrawSetShadow(playerid, Indicator1[playerid], 0);
		PlayerTextDrawSetOutline(playerid, Indicator1[playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, Indicator1[playerid], 51);
		PlayerTextDrawFont(playerid, Indicator1[playerid], TEXT_DRAW_FONT:1);
		PlayerTextDrawSetProportional(playerid, Indicator1[playerid], true);
	}
	return 1;
}

stock DeletePlayerTD(playerid)
{
	PlayerTextDrawHide(playerid,DebugInfo[playerid]);
	PlayerTextDrawDestroy(playerid,DebugInfo[playerid]);
	PlayerTextDrawHide(playerid,Indicator1[playerid]);
	PlayerTextDrawDestroy(playerid,IndicatorBox1[playerid]);
	PlayerTextDrawHide(playerid,Indicator[playerid]);
	PlayerTextDrawDestroy(playerid,IndicatorBox[playerid]);
	PlayerTextDrawHide(playerid,LegBroken[playerid]);
	PlayerTextDrawDestroy(playerid,LegBroken[playerid]);
	PlayerTextDrawHide(playerid,vehicleInfo[playerid]);
	PlayerTextDrawDestroy(playerid,vehicleInfo[playerid]);
	PlayerTextDrawHide(playerid,PlayerBlood[playerid]);
	PlayerTextDrawDestroy(playerid,PlayerBlood[playerid]);
	PlayerTextDrawHide(playerid,PlayerHunger[playerid]);
	PlayerTextDrawDestroy(playerid,PlayerHunger[playerid]);
	PlayerTextDrawHide(playerid,PlayerThirst[playerid]);
	PlayerTextDrawDestroy(playerid,PlayerThirst[playerid]);
	PlayerTextDrawHide(playerid,PlayerNoise[playerid]);
	PlayerTextDrawDestroy(playerid,PlayerNoise[playerid]);
	PlayerTextDrawHide(playerid,Map[playerid]);
	PlayerTextDrawDestroy(playerid,Map[playerid]);
	PlayerTextDrawHide(playerid,PlayerEye[playerid]);
	PlayerTextDrawDestroy(playerid,PlayerEye[playerid]);
	PlayerTextDrawHide(playerid,playerBandit[playerid]);
	PlayerTextDrawDestroy(playerid,playerBandit[playerid]);
	PlayerTextDrawHide(playerid,PlayerTemp[playerid]);
	PlayerTextDrawDestroy(playerid,PlayerTemp[playerid]);
	PlayerTextDrawHide(playerid,NoiseLevel1[playerid]);
	PlayerTextDrawDestroy(playerid,NoiseLevel1[playerid]);
	PlayerTextDrawHide(playerid,NoiseLevel2[playerid]);
	PlayerTextDrawDestroy(playerid,NoiseLevel2[playerid]);
	PlayerTextDrawHide(playerid,NoiseLevel3[playerid]);
	PlayerTextDrawDestroy(playerid,NoiseLevel3[playerid]);
	PlayerTextDrawHide(playerid,NoiseLevel4[playerid]);
	PlayerTextDrawDestroy(playerid,NoiseLevel4[playerid]);
	PlayerTextDrawHide(playerid,EyeLevel1[playerid]);
	PlayerTextDrawDestroy(playerid,EyeLevel1[playerid]);
	PlayerTextDrawHide(playerid,EyeLevel2[playerid]);
	PlayerTextDrawDestroy(playerid,EyeLevel2[playerid]);
	PlayerTextDrawHide(playerid,EyeLevel3[playerid]);
	PlayerTextDrawDestroy(playerid,EyeLevel3[playerid]);
	PlayerTextDrawHide(playerid,EyeLevel4[playerid]);
	PlayerTextDrawDestroy(playerid,EyeLevel4[playerid]);
	return 1;
}

stock CreateTDS()
{

	Clock = TextDrawCreate(549,24, "00:00");
    TextDrawLetterSize(Clock,0.55,2);
    TextDrawFont(Clock,TEXT_DRAW_FONT:3);
    TextDrawBackgroundColor(Clock,0x000000AA);
    TextDrawSetOutline(Clock,2);

	Date = TextDrawCreate(500,3, "01.01.2008");
	TextDrawLetterSize(Date,0.55,2);
	TextDrawFont(Date,TEXT_DRAW_FONT:3);
	TextDrawBackgroundColor(Date,0x000000AA);
	TextDrawSetOutline(Date,2);

    BlockMap = GangZoneCreate(-2994,-2994,3000,3006);

	WholeScreen = TextDrawCreate(-20.000000, 0.000000, "_");
    TextDrawUseBox(WholeScreen, true);
    TextDrawBoxColor(WholeScreen, 0x000000FF);
    TextDrawAlignment(WholeScreen, TEXT_DRAW_ALIGN:0);
    TextDrawBackgroundColor(WholeScreen, 0x000000FF);
    TextDrawFont(WholeScreen, TEXT_DRAW_FONT:3);
    TextDrawLetterSize(WholeScreen, 1.000000, 52.200000);
    TextDrawColor(WholeScreen, 0x000000FF);

	Announcement = TextDrawCreate(260.000000, 426.000000, "DAYZSATEST IS NOW~r~ DEAD");
	TextDrawBackgroundColor(Announcement, 255);
	TextDrawFont(Announcement, TEXT_DRAW_FONT:2);
	TextDrawLetterSize(Announcement, 0.230000, 1.500000);
	TextDrawColor(Announcement, -1);
	TextDrawSetOutline(Announcement, 0);
	TextDrawSetProportional(Announcement, true);
	TextDrawSetShadow(Announcement, 1);

	DebugBox = TextDrawCreate(491.000000, 10.000000, "ld_drv:ribbw");
	TextDrawAlignment(DebugBox, TEXT_DRAW_ALIGN:2);
	TextDrawBackgroundColor(DebugBox, 255);
	TextDrawFont(DebugBox, TEXT_DRAW_FONT:4);
	TextDrawLetterSize(DebugBox, 0.339999, -1.100000);
	TextDrawColor(DebugBox, 255);
	TextDrawSetOutline(DebugBox, 0);
	TextDrawSetProportional(DebugBox, true);
	TextDrawSetShadow(DebugBox, 1);
	TextDrawUseBox(DebugBox, true);
	TextDrawBoxColor(DebugBox, 16711935);
	TextDrawTextSize(DebugBox, 150.000000, 100.000000);
	TextDrawSetSelectable(DebugBox, false);
	
	DebugText = TextDrawCreate(558.000000, 17.000000, "Debug Monitor");
	TextDrawAlignment(DebugText, TEXT_DRAW_ALIGN:2);
	TextDrawBackgroundColor(DebugText, 255);
	TextDrawFont(DebugText, TEXT_DRAW_FONT:2);
	TextDrawLetterSize(DebugText, 0.339999, 1.000000);
	TextDrawColor(DebugText, -16776961);
	TextDrawSetOutline(DebugText, 1);
	TextDrawSetProportional(DebugText, true);
	TextDrawSetSelectable(DebugText, false);

	DayZSA_Web = TextDrawCreate(509.000000, 4.000000, "pgagaming.net / v15.0");
	TextDrawBackgroundColor(DayZSA_Web, 255);
	TextDrawFont(DayZSA_Web, TEXT_DRAW_FONT:2);
	TextDrawLetterSize(DayZSA_Web, 0.200000, 0.799999);
	TextDrawColor(DayZSA_Web, -16776961);
	TextDrawSetOutline(DayZSA_Web, 1);
	TextDrawSetProportional(DayZSA_Web, true);
	TextDrawSetSelectable(DayZSA_Web, false);

	return 1;
}

stock ConnectVars(playerid)
{
	pInfo[playerid][pHunger] = 2500;
	pInfo[playerid][pThrist] = 1000;
	pInfo[playerid][pBlood] = 12000;
	pInfo[playerid][Humanity] = 2500;

	RemoveVends(playerid);
	DayZSA_RemoveLights(playerid);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_PISTOL, 1);
	pGABase_RemoveObjects(playerid);

    TeleportAllowed[playerid] = 1;
	gpInfo[playerid][hacker] = 0;
	gpInfo[playerid][firstspawn] = 1;
	GetPlayerName(playerid, gpInfo[playerid][pname23], MAX_PLAYER_NAME);

	for(new i=0;i<47;i++)
	{
		PlayerWeapons[playerid][i]=false;
 		Spawned[playerid]=false;
	}
	return 1;
}

stock DecreaseBars(playerid)
{
    if(IsSpecing[playerid] == 0)
    {
		pInfo[playerid][pHunger] -= random(3);
		pInfo[playerid][pThrist] -= random(3);
	}
	return 1;
}

stock CheckBars(playerid)
{
	if(pInfo[playerid][pIsSpawned] == 1)
	{
	    if(isPlayerInMenu[playerid] == 0)
	    {
			if(pInfo[playerid][pHunger] <= 0)
			{
				new str2[128];
				SetPlayerHealth(playerid, 0);
				format(str2,sizeof(str2),"*"COL_RED" %s(%i) has starved to death!",PlayerName(playerid),playerid);
				ProxDetector(60.0, playerid, str2, COLOR_GREY);
				pInfo[playerid][pHunger] = 2500;
				SendClientMessage(playerid,-1,"*"COL_RED" You starved to death!");
			}

			if(pInfo[playerid][pThrist] <= 0)
			{
				new str2[128];
				SetPlayerHealth(playerid, 0);
				format(str2,sizeof(str2),"*"COL_RED" %s(%i) has died of thirst!",PlayerName(playerid),playerid);
				ProxDetector(60.0, playerid, str2, COLOR_GREY);
				pInfo[playerid][pThrist] = 1000;
				SendClientMessage(playerid,-1,"*"COL_RED" You died of thirst!");
			}

			if(pInfo[playerid][pBlood] <= 0)
			{
				new str2[128];
				SetPlayerHealth(playerid, 0);
				format(str2,sizeof(str2),"*"COL_RED" %s(%i) has died of blood loss!",PlayerName(playerid),playerid);
				ProxDetector(60.0, playerid, str2, COLOR_GREY);
				pInfo[playerid][pBlood] = 12000;
				SendClientMessage(playerid,-1,"*"COL_RED" You died of blood loss!");
			}
		}
	}
	return 1;
}

stock DisconnectVars(playerid)
{
   	if(IsPlayerAttachedObjectSlotUsed(playerid, 1)) RemovePlayerAttachedObject(playerid, 0);

    if(pInfo[playerid][IsPlayerGroupOwner] == 1)
    {
		new str[24],gname[16];

		format(str,sizeof(str),"Destroyed");
		format(gname,sizeof(gname),"Destroyed");

		Groups[pInfo[playerid][IsPlayerInGroupID]][GroupID] = 0;
		Groups[pInfo[playerid][IsPlayerInGroupID]][GroupOwner] = str;
		Groups[pInfo[playerid][IsPlayerInGroupID]][GroupName] = gname;
		Groups[pInfo[playerid][IsPlayerInGroupID]][GroupMembers] = 0;

		new groupid = pInfo[playerid][IsPlayerInGroupID];
		foreach (new i : Player)
		{
			if(pInfo[i][IsPlayerInGroup] == 1 && pInfo[i][IsPlayerInGroupID] == groupid)
			{
				pInfo[i][IsPlayerInGroup] = 0;
				pInfo[i][IsPlayerInGroupID] = 0;

			}
		}

		pInfo[playerid][IsPlayerInGroup] = 0;
		pInfo[playerid][IsPlayerGroupOwner] = 0;
		pInfo[playerid][IsPlayerInGroupID] = 0;
	}
    return 1;
}

stock SendGlobal(Float:radi, playerid, const string[],color)
{
    new Float:x,Float:y,Float:z;
    GetPlayerPos(playerid,x,y,z);
    foreach (new i : Player)
    {
        if(globalStatus[i] == 0)
        {
        	if(IsPlayerInRangeOfPoint(i,radi,x,y,z))
        	{
        	    SendClientMessage(i,color,string);
        	}
		}
	}
}

stock ProxDetector(Float:radi, playerid, const string[],color)
{
    new Float:x,Float:y,Float:z;
    GetPlayerPos(playerid,x,y,z);
    foreach (new i : Player)
    {
        if(IsPlayerInRangeOfPoint(i,radi,x,y,z))
        {
            SendClientMessage(i,color,string);
        }
    }
}

function IsPlayerAimingTargetBodyPart(playerid, targetid, bodypart)
{
	new Float:x, Float:y, Float:z;
	new Float:vx, Float:vy, Float:vz;
	new Float:cx, Float:cy, Float:cz;
	GetPlayerCameraFrontVector(playerid, vx, vy, vz);
	GetPlayerCameraPos(playerid, cx, cy, cz);
	new Float:px, Float:py, Float:pz;
	GetPlayerPos(targetid, px, py, pz);
	new Float:dist = floatsqroot(((cx-px)*(cx-px)) + ((cy-py)*(cy-py)) + ((cz-pz)*(cz-pz)));
    x = vx*dist+cx;
    y = vy*dist+cy;
    z = vz*dist+cz;
    new Float:offset;
	switch (GetPlayerWeapon(playerid))
	{
	    case 24, 29, 22, 23, 25, 26, 27, 28, 32: offset = 0.1122047500310059125919013005129;
	    case 30, 31: offset = 0.07867820613690007867820613690008;
	    case 33, 34: offset = 0.0;
	}
	new Float:height;
	if (z > cz) height = z-cz;
	else height = cz-z;
	offset *= dist;
	height /= dist;
	new Float:part;
	if (bodypart == BODY_PART_HEAD) part = -0.4;
	else if (bodypart == BODY_PART_TORSO) part = 0.3;
	else if (bodypart == BODY_PART_LEGS) part = 1.0;
	z = z+offset-height+part;
    if (IsPlayerInRangeOfPoint(targetid, 0.5, x, y, z-0.5)) return 1;
	return 0;
}


function ShowGroupMarkers(playerid)
{
	foreach (new i : Player)
	{
		if(pInfo[playerid][IsPlayerInGroupID] == pInfo[i][IsPlayerInGroupID])
		{
		    if(pInfo[playerid][IsPlayerInGroupID] != 0)
			{
				if(pInfo[i][IsPlayerInGroupID] != 0)
				{
					SetPlayerMarkerForPlayer( playerid, i, 0x9900FFFF);
					SetPlayerMarkerForPlayer( i, playerid, 0x9900FFFF);
				}
			}
		}
		else
		{
			SetPlayerMarkerForPlayer( playerid, i, ( GetPlayerColor( i ) & 0xFFFFFF00 ) );
			SetPlayerMarkerForPlayer( i, playerid, ( GetPlayerColor( playerid ) & 0xFFFFFF00 ) );
		}
	}
}

function SpawnVars(playerid)
{
	// If First spawn is 2 means he's already spawned and been around!
	// If First spawn is 1 means he's new and hasn't spawned yet or died!

	if(!IsPlayerNPC(playerid))
	{
		SetPlayerVirtualWorld(playerid,0);
		SetPlayerHealth(playerid,100.0);
		RemovePlayerAttachedObject(playerid, 2);
		KillTimer(pInfo[playerid][Bleeding]);
		pInfo[playerid][pIsSpawned] = 1;
		SetPlayerSkillLevel(playerid, WEAPONSKILL_PISTOL, 1);

		if(pInfo[playerid][pIsMapOpened] == 0)
		{
			GangZoneShowForPlayer(playerid,BlockMap,0x000000FF);
			PlayerTextDrawShow(playerid, blockMap[playerid]);
		}

		PlayerTextDrawHide(playerid, PlayerIntroBox[playerid]);

		//TextDrawShowForPlayer(playerid,Clock);
		//TextDrawShowForPlayer(playerid,Date);
		PlayerTextDrawHide(playerid, LegBroken[playerid]);
		pInfo[playerid][IsPlayerLegBroken] = 0;

		if(pInfo[playerid][pFirstSpawn] == 1)
		{
			new randSpawn = random(sizeof(randomSpawns_DayZSA_Part1));
			SetPlayerPos_Allow(playerid,randomSpawns_DayZSA_Part1[randSpawn][0],randomSpawns_DayZSA_Part1[randSpawn][1],randomSpawns_DayZSA_Part1[randSpawn][2]);
			//SetPlayerFacingAngle(playerid,randomSpawns_DayZSA_Part1[randSpawn][3]);

            if(pInfo[playerid][DefaultGender] == MALE_ID)
            {
				SetPlayerSkin(playerid,NORMAL);
			}
			else
			{
			    SetPlayerSkin(playerid,FEMALE);
			}

			ResetPlayerWeapons(playerid);

			if(pInfo[playerid][pPremium] == 0)
			{
				pInfo[playerid][pHunger] = 2500;
				pInfo[playerid][pThrist] = 1000;
				pInfo[playerid][pBlood] = 12000;
				pInfo[playerid][Humanity] = 2500;
				pInfo[playerid][Backpack] = 0;
				pInfo[playerid][BackpackSlots] = 8;
				pInfo[playerid][BackpackSlotsUsed] = 0;
			}

			if(pInfo[playerid][pPremium] == 1)
			{
				pInfo[playerid][pHunger] = 2500;
				pInfo[playerid][pThrist] = 1000;
				pInfo[playerid][pBlood] = 16000;
				pInfo[playerid][Humanity] = 2980;
				pInfo[playerid][Backpack] = 1;
				pInfo[playerid][BackpackSlots] = 16;
				pInfo[playerid][BackpackSlotsUsed] = 0;
			}

			if(pInfo[playerid][pPremium] == 2)
			{
				pInfo[playerid][pHunger] = 2500;
				pInfo[playerid][pThrist] = 1000;
				pInfo[playerid][pBlood] = 18000;
				pInfo[playerid][Humanity] = 3200;
				pInfo[playerid][Backpack] = 2;
				pInfo[playerid][BackpackSlots] = 28;
				pInfo[playerid][BackpackSlotsUsed] = 0;
			}

			if(pInfo[playerid][pPremium] >= 3)
			{
				pInfo[playerid][pHunger] = 3000;
				pInfo[playerid][pThrist] = 1000;
				pInfo[playerid][pBlood] = 21000;
				pInfo[playerid][Humanity] = 3500;
				pInfo[playerid][Backpack] = 3;
				pInfo[playerid][BackpackSlots] = 38;
				pInfo[playerid][BackpackSlotsUsed] = 0;
				AddSlotToInventoryWorld(playerid,"Blood Bag",1);
				AddSlotToInventoryWorld(playerid,"Pistol",1);
				AddSlotToInventoryWorld(playerid,"Pistol Ammo",1);
			}

			if(pInfo[playerid][pPremium] >= 4)
			{
				pInfo[playerid][pHunger] = 3800;
				pInfo[playerid][pThrist] = 1800;
				pInfo[playerid][pBlood] = 26000;
				pInfo[playerid][Humanity] = 4500;
				AddSlotToInventoryWorld(playerid,"Blood Bag",2);
				AddSlotToInventoryWorld(playerid,"M4",1);
				AddSlotToInventoryWorld(playerid,"Assault Ammo",1);
				AddSlotToInventoryWorld(playerid,"Sniper Skin",1);
				AddSlotToInventoryWorld(playerid,"Full Water Bottle",1);
				AddSlotToInventoryWorld(playerid,"Shotgun",1);
			}

			AddSlotToInventoryWorld(playerid,"Bandage",1);
			AddSlotToInventoryWorld(playerid,"Full Water Bottle",1);
			AddSlotToInventoryWorld(playerid,"Painkiller",1);
			AddSlotToInventoryWorld(playerid,"Heat Pack Basic", 1);
			switch(random(5))
			{
				case 3: AddSlotToInventoryWorld(playerid,"Radio Device",1);
			}

			pInfo[playerid][pFirstSpawn] = 2;
		}

		else if(pInfo[playerid][pFirstSpawn] == 2)
		{
			PlayerTextDrawHide(playerid, PlayerIntroBox[playerid]);
			SetPlayerSkin(playerid,pInfo[playerid][pSkin]);
			if(giveWeaponAllow[playerid] == 1)
			{
				GivePlayerWeaponEx(playerid,pInfo[playerid][pWeap1],pInfo[playerid][pAmmo1]);
				GivePlayerWeaponEx(playerid,pInfo[playerid][pWeap2],pInfo[playerid][pAmmo2]);
				GivePlayerWeaponEx(playerid,pInfo[playerid][pWeap3],pInfo[playerid][pAmmo3]);
				GivePlayerWeaponEx(playerid,pInfo[playerid][pWeap4],pInfo[playerid][pAmmo4]);
				GivePlayerWeaponEx(playerid,pInfo[playerid][pWeap5],pInfo[playerid][pAmmo5]);
				GivePlayerWeaponEx(playerid,pInfo[playerid][pWeap6],pInfo[playerid][pAmmo6]);
				GivePlayerWeaponEx(playerid,pInfo[playerid][pWeap7],pInfo[playerid][pAmmo7]);
				GivePlayerWeaponEx(playerid,pInfo[playerid][pWeap8],pInfo[playerid][pAmmo8]);
				GivePlayerWeaponEx(playerid,pInfo[playerid][pWeap9],pInfo[playerid][pAmmo9]);
				giveWeaponAllow[playerid] = 0;
			}
			SetPlayerPos_Allow(playerid,pInfo[playerid][pX],pInfo[playerid][pY],pInfo[playerid][pZ]+0.7);

			if(pInfo[playerid][Humanity] <= 2000)
			{
				if(pInfo[playerid][IsPlayerBandit] == 0)
				{
					SetPlayerSkin(playerid,BANDIT);
					SendClientMessage(playerid,-1,""COL_GREY" You are an bandit now!");
					pInfo[playerid][IsPlayerBandit] = 1;
					RemovePlayerAttachedObject(playerid, 4);
					SetPlayerAttachedObject(playerid,4,19033,2,0.094999,0.076999,-0.012000,2.900000,83.200004,94.900001,1.000000,1.000000,1.000000);
				}
			}

			if(pInfo[playerid][Humanity] >= 3000)
			{
				if(pInfo[playerid][IsPlayerHero] == 0)
				{
					SetPlayerSkin(playerid,HERO);
					SendClientMessage(playerid,-1,""COL_GREY" You are an hero now!");
					pInfo[playerid][IsPlayerHero] = 1;
				}
			}
		}

		if(GetPlayerSkin(playerid) == 0)
		{
			SetPlayerSkin(playerid,NORMAL);
		}

		RemovePlayerAttachedObject(playerid, 1);

		if(pInfo[playerid][Backpack] == 0) { pInfo[playerid][BackpackSlots] = 8; }
		if(pInfo[playerid][Backpack] == 1) { pInfo[playerid][BackpackSlots] = 16; }
		if(pInfo[playerid][Backpack] == 2) { pInfo[playerid][BackpackSlots] = 28; }
		if(pInfo[playerid][Backpack] == 3) { pInfo[playerid][BackpackSlots] = 38; }

		if(pInfo[playerid][Backpack] == 0) { SetPlayerAttachedObject(playerid, 1, 3026, 1, -0.160000, -0.116000, 0.000000, 0.000000, 0.000000, 0.000000, 1.141000, 1.279999, 1.176001); } /*SetPlayerAttachedObject( playerid, 1, 1580, 1, 0.200000, -0.019999, 0.000000, 90.000000, 0.000000, 1.000000, 1.000000, 1.000000, 1.000000 );*/  // drug_red - Normal Backpack
		if(pInfo[playerid][Backpack] == 1) { SetPlayerAttachedObject( playerid, 1, 371, 1, 0.000000, -0.100000, 0.000000, 3.000000, 90.000000, 1.000000, 1.000000, 1.000000, 1.000000 );  } // Small backpack
		if(pInfo[playerid][Backpack] == 2) { SetPlayerAttachedObject( playerid, 1, 1310, 1, 0.000000, -0.100000, 0.000000, 3.000000, 90.000000, 1.000000, 1.000000, 1.000000, 1.000000 ); } // pikupparachute -
		if(pInfo[playerid][Backpack] == 3) { SetPlayerAttachedObject( playerid, 1, 1550, 1, 0.000000, -0.100000, 0.000000, 3.000000, 90.000000, 1.000000, 1.000000, 1.000000, 1.000000 ); } // CJ_MONEY_BAG - Coyote Back pack

		if(pInfo[playerid][pIsMapOpened] == 1)
		{
			PlayerTextDrawHide(playerid, blockMap[playerid]);
			GangZoneHideForPlayer(playerid,BlockMap);
		}

		if(IsSpecing[playerid] == 1)
		{
			SetPlayerPos_Allow(playerid,SpecX[playerid],SpecY[playerid],SpecZ[playerid]);
			SetPlayerInterior(playerid,Inter[playerid]);
			SetPlayerVirtualWorld(playerid,vWorld[playerid]);
			IsSpecing[playerid] = 0;
			IsBeingSpeced[spectatorid[playerid]] = 0;
		}




		if(GetPlayerSkin(playerid) == 29)
		{
			SetPlayerSkin(playerid,NORMAL);
		}

	}
	return 1;
}




function StopAnim(playerid) return ClearAnimations(playerid);

function LoosingBlood(playerid)
{
	pInfo[playerid][pBlood] -= random(450);
    SetPlayerAttachedObject(playerid, 2, 18668/*18706*/, 1, 0.000000, 0.000000, -1.500000, 0.000000, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000 ); // prt_blood - Bleeding
	return 1;
}

stock GetPlayerStyle(playerid)
{
	new styleString[128];
	switch(GetPlayerSkin(playerid))
	{
	    case BANDIT: styleString = ""COL_RED"Bandit";
	    case NORMAL: styleString = ""COL_GREY"Civilian";
	    case HERO: styleString = ""COL_GREEN"Hero";
	    case CIV: styleString = ""COL_GREY"Army";
	    case FEMALE: styleString = ""COL_PINK"Civilian";
	    case CIVSKIN: styleString = ""COL_GREY"Civilian";
	    case SNIP: styleString = ""COL_RED"Sniper";
	}
	return styleString;
}

stock IsPlayerInWater(playerid)
{
    new lib[16], anim[32];
    GetAnimationName(GetPlayerAnimationIndex(playerid), lib, sizeof(lib), anim, sizeof(anim));
    if(!strcmp(lib, "SWIM", true) && !isnull(lib)) return 1;
    return 0;
}

TimeConvert(time)
{
    new minutes;
    new seconds;
    new string[128];
    if(time > 59){
        minutes = floatround(time/60);
        seconds = floatround(time - minutes*60);
        if(seconds>9)format(string,sizeof(string),"%d:%d",minutes,seconds);
        else format(string,sizeof(string),"%d:0%d",minutes,seconds);
    }
    else{
        seconds = floatround(time);
        if(seconds>9)format(string,sizeof(string),"0:%d",seconds);
        else format(string,sizeof(string),"0:0%d",seconds);
    }
    return string;
}

// **** INVENTORY **** //

stock _GetItemNamePVar(playerid,item)
{
	new tmp[32];
	new tmp2[MAX_ITEM_NAME];
	format(tmp,32,"PITEMNAME%d",item);
	GetPVarString(playerid,tmp,tmp2,MAX_ITEM_NAME);
	return tmp2;
}

stock _SetItemNamePVar(playerid,item,const ItemName[])
{
	new tmp[MAX_ITEM_NAME];
	format(tmp,MAX_ITEM_NAME,"PITEMNAME%d",item);
 	SetPVarString(playerid,tmp,ItemName);
}

stock _GetItemAmountPVar(playerid,item)
{
	new tmp[16];
	format(tmp,16,"PITEMAMOUNT%d",item);
	return GetPVarInt(playerid,tmp);
}

