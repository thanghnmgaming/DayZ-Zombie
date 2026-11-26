// ---------------------------------------------------------------------------
// Settings a server owner may want to change. Rebuild after editing.
// The server name, website, password and slots are set in config.json.
// ---------------------------------------------------------------------------

#define SERVER_TITLE        "DayZ Survival"     // loading screen and game mode text
#define SERVER_VERSION      "v16.0"
#define SERVER_TAG          "open.mp"           // small line at the top right of the screen

// Direct links to audio streams. Leave empty for silence.
#define MENU_MUSIC_URL      ""
#define AMBIENT_DAY_URL     ""
#define AMBIENT_NIGHT_URL   ""

stock PlayServerAudio(playerid, const url[])
{
	if(url[0]) PlayAudioStreamForPlayer(playerid, url);
	return 1;
}
