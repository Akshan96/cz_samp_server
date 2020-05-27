forward OnPlayerDamageObject(playerid, objectid, Float:damage, destroyed); // To detect, for example, when a player shoots an explosive barrel (object destruction could/should also be synced with other players)
forward OnPlayerEnterVehicle(playerid, vehicleid, seatid); // Add seatid parameter, and returning 0 should prevent entrance
forward OnPlayerClickPlayer(playerid, clickedplayerid, source); // Add sources: CLICK_SOURCE_CHAT and CLICK_SOURCE_NAMETAG (MP2: how would CLICK_SOURCE_CHAT work when using SendClientMessage for chat as I do in my server (to add IDs)? I'm guessing this would only work for default chat.
forward OnPlayerVend(playerid, oldmoney, newmoney, machinetype);
forward OnPlayerCasinoPlay(playerid, oldmoney, newmoney, casinoid, machinetype); // Machine type is like vending machine, blackjack, etc. casinoid is the casino (4 dragons, casigulas, redsands)
forward OnPlayerRecieveStuntBonus(playerid, amount, details[]); // 'details' contains a string of the details of the stunt, such as distance and height (like GetPlayerNetworkStats)
forward OnPlayerMouseClick(playerid, press, buttonid); // Press would be 1 if the button was pressed, 0 if released. buttonid would be LMB, RMB, MMB, etc.
forward OnPlayerShoot(playerid, weaponid, Float:x, Float:y, Float:z); // x y z are where the bullet hits
forward OnVehicleDeath(vehicleid, reason); // Reason would be explosion or water
forward OnEnterExitModShop(playerid, enterexit, interiorid); // returning 0 here will prevent the player from entering

native Attach3DTextLabelToObject(Text3D:id, objectid, Float:OffsetX, Float:OffsetY, Float:OffsetZ);
native TextDrawFadeInOut(Text:text, fade, time); // Fade: 0=out 1=in
native TogglePlayerInteriorEnterExits(playerid, entrance, bool:toggle); // 'entrance' would be something like ENTRANCE_AMMU, ENTRANCE_PIZZA, etc. (or perhaps coordinates with a radius like RemoveBuildingForPlayer)
native ToggleClientCommand(playerid, command[], bool:toggle); // Toggle the use of a client command, like disabling /save (some people use it to ripoff other servers). Should not work for /quit (/q)
native SetPlayerWayPoint(playerid, Float:x, Float:y, Float:z); // Set the waypoint for a player
native GetPlayerWayPoint(playerid, &Float:x, &Float:y, &Float:z); // Get the player's set waypoint (0, 0, 0 if none)
native GetVehicleParamsEx(vehicleid, &engine, &lights, &alarm, &doors, &bonnet, &boot, &objective, &feature) // Add 'feature' parameter (like the one on the packer, andromada, etc.)
native SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective, feature); // Add 'feature' parameter (like the one on the packer, andromada, etc.)
native ToggleVehicleBlip(vehicleid, bool:toggle); // Toggle grey blip on radar for a vehicle
native ToggleVehicleBlips(bool:toggle); // Toggle blips for all vehicles
native TogglePlayerTearGasEffect(playerid, bool:toggle);
native ToggleTearGasEffect(bool:toggle);
native Set3DTextLabelSize(Text3D:id, Float:size);
native ShowNameTags(bool:enabled, mode); // Modes: 0 = off, 1 = names, 2 = health/armour, 3 = all
native GetLOS(Float:x, Float:y, Float:z, Float:x2, Float:y2, Float:z2); // Returns the line-of-sight distance between 2 points.
native SetPlayerCheckpoint(playerid, Float:x, Float:y, Float:z, Float:size, color); // Add color parameter
native SetPlayerRaceCheckpoint(playerid, Float:x, Float:y, Float:z, Float:size, color); // Add color parameter
native SetPlayerChatBubble(playerid, text[], color, Float:drawdistance, expiretime, LOS); // Add LOS parameter
native WalkToPos(Float:x, Float:y, Float:z, mode); // Make the NPC walk to a point. The modes are: 0 = walking, 1 = jogging, 2 = sprinting
native CreatePlayerPickup(playerid, model, type, Float:X, Float:Y, Float:Z, Virtualworld)
native ToggleVehicleCollision(vehicleid, bool:toggle);
native ToggleVehicleCollisionForPlayer(playerid, vehicleid, bool:toggle);
native ToggleObjectCollision(objectid, bool:toggle);
native TogglePlayerObjectCollision(playerid, objectid, bool:toggle);
native FadePlayerCamera(playerid, bool:fade, Float:speed); // Not necessarily needed if TextDrawFade is added (though could prevent textdraw limit being used)
native SetWaterLevel(Float:height);
native SetWaveHeight(Float:height);
native GetPlayerCursorPos(playerid, &Float:x, &Float:y);
native GetMouseClickPos(playerid, &Float:x, &Float:y); // What is this meant to do? Same as above..?
native TogglePlayerRadar(playerid, bool:toggle);
native SetPlayerChatMode(playerid, mode); // mode - 0=off 1=on 2=no outline
native GetPlayerChatMode(playerid); // Returns: 0=off 1=on 2=no outline
native SetPlayerCameraLookAtVehicle (playerid, vehicleid);
native SetPlayerCameraLookAtPlayer (playerid, lookatplayerid);
native MovePlayerCamera(playerid, Float:x, Float:y, Float:z, Float:x2, Float:y2, Float:z2, Float:speed);
native SetVehicleHandling(?);
native PutPlayerInCrane(playerid, craneid);
native TogglePlayerSPCheat(playerid, cheatname[], bool:toggle);
native GetTrainDirection(vehicleid); // Returns true if the train is driving clockwise on the train track, false if it is going counterclockwise.
native SetTrainDirection(vehicleid, bool:clockwise);
native GetTrainSpeed(vehicleid, &Float:speed);
native SetTrainSpeed(vehicleid, Float:speed);
native UsePlayerCopShootAnim(); // Needs explanation
native SetPlayerGravity(playerid, Float:gravity);
native SetVehicleGravity(vehicleid, Float:gravity);
native IsPlayerUsingJoypad(playerid);
native TogglePlayerScoreboard(playerid, bool:toggle);
native SetScoreHeader(header[]); // or something similar - changes the 'score' header to header[]
native GetPlayerNoise(playerid, &Float:noise);  // just like in the burgulary missions (callback also)
native ToggleClassSelection(bool:toggle); // Disable class selection (players spawn straight away when joining (unless scripted otherwise))
native TogglePlayerClassSelection(playerid, bool:toggle); // Same as above but for a single player
native SetPlayerID(playerid, id); // Sets the ID of a player. Returns 1 if change was successful, returns 0 if it was unable to complete the request (invalid ID or ID taken)
native GetPlayerLungCapacity(playerid, &Float:capacity);
native SetPlayerLungCapacity(playerid, Float:capacity);
native SetPlayerParamsForPlayer(playerid, forplayerid, objective, color); // basically making objectives in selected color to show above players like in SP
native SetVehicleParamsForPlayer(vehicleid, playerid, objective, color, doorslocked); // being able to choose color of the objective
native TogglePlayerHUD(playerid, component, bool:toggle); // component - 0 - Radar, 1 - Money, 2 - HealthBar, etc.
native SetPlayerGameSpeed(playerid, Float:speed); // Pretty self explanatory, toggles the slow motion effect caused by the pill pickup.
native CreateFaced3DTextLabel(text[], color, Float:x, Float:y, Float:z, Float:angle, Float:drawdistance, virtualworld, LOS);
native TextDrawMove(Text:text, Float:x, Float:y, Float:speed);
native ToggleOcuppiedVehicleDamage(bool:toggle);
native ToggleOcuppiedVehicleDamageForVehicle(vehicleid, bool:toggle);
native ToggleWorldSun(bool:toggle);
native AddScoreboardColumn(name[], position) // Position is the position of the column (like before player id column, after player id column, etc).
native RemoveScoreboardColumn(name[]);
native SetScoreboardColumnValue(playerid, name[], value);
native SendDeathMessageForPlayer(playerid, killer, victim, reason);
native AttachVehicleToObject(vehicleid, objectid);
native ShowPlayerDialog(playerid, dialogid, style, caption[], info[], {Float,_}:...); // Change button1[] and button2[] to allow for 1 or more buttons
native TogglePlayerMouseCursor(playerid, bool:toggle);
native TogglePlayerControllable(playerid, mode) // modes: 0 - controllable 1 - cant move player or camera (current) 2 - can't move but can move camera
native SetPlayerMaxHealth(playerid, Float:health); // If health is above 100, it will increase the healthbar size
native GetPlayerMaxHealth(playerid, &Float:health);
native TogglePlayerSpeedBlur(playerid, bool:toggle);
native ToggleSpeedBlur(bool:toggle);
native ToggleVehicleDamage(vehicleid, bool:toggle); // Works on vacant vehicles too (vacant vehicles set to invincible by default).
native ToggleCombineHarvesterDeath(bool:toggle);
native TogglePlayerHead(playerid, bool:toggle);
native GetPlayerPageSize(playerid);
native SetVehicleWheelSize(vehicleid, size);
