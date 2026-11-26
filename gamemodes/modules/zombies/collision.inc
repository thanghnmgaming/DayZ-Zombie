// ---------------------------------------------------------------------------
// World collision through ColAndreas. Without its database everything is
// treated as open, so the server still runs.
// ---------------------------------------------------------------------------

native CA_Init();
native CA_RayCastLine(Float:StartX, Float:StartY, Float:StartZ, Float:EndX, Float:EndY, Float:EndZ, &Float:x, &Float:y, &Float:z);
native CA_CreateObject(modelid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, bool:add = false);

#define CA_WATER_OBJECT 20000

stock InitCollision()
{
	CollisionReady = CA_Init() != 0;
	if(!CollisionReady) print("[COLLISION] ColAndreas.cadb is missing: zombies can walk through the map.");
	return 1;
}

// Makes the server's own map objects solid too (ids first..last of the streamer)
stock RegisterMapCollision(first, last)
{
	if(!CollisionReady) return 0;
	new count;
	for(new id = first; id <= last; id++)
	{
		if(!IsValidDynamicObject(id)) continue;
		new Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz;
		GetDynamicObjectPos(id, x, y, z);
		GetDynamicObjectRot(id, rx, ry, rz);
		CA_CreateObject(Streamer_GetIntData(STREAMER_TYPE_OBJECT, id, E_STREAMER_MODEL_ID), x, y, z, rx, ry, rz, true);
		count++;
	}
	printf("[COLLISION] %d server map object(s) made solid.", count);
	return 1;
}

// True when solid world geometry lies between the two points
stock bool:IsWorldBlocked(Float:ax, Float:ay, Float:az, Float:bx, Float:by, Float:bz)
{
	if(!CollisionReady) return false;
	new Float:x, Float:y, Float:z, model = CA_RayCastLine(ax, ay, az, bx, by, bz, x, y, z);
	return model != 0 && model != CA_WATER_OBJECT;
}

// Floor under a point, found from just above it, so roofs and bridges overhead are ignored
stock bool:FindFloor(Float:x, Float:y, Float:fromZ, &Float:floorZ)
{
	if(!CollisionReady) return false;
	new Float:hx, Float:hy, Float:hz, model = CA_RayCastLine(x, y, fromZ + 1.5, x, y, fromZ - 8.0, hx, hy, hz);
	if(model == 0 || model == CA_WATER_OBJECT) return false;
	floorZ = hz;
	return true;
}
