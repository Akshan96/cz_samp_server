public placeAllCheckpoints()
{
	new i = 0;
	while(i < MAX_ROB_CHECKPOINT)
	{	
		checkpointIndex[i][0] = CreateDynamicCP(checkpointData[i][enterpointLoc][0], checkpointData[i][enterpointLoc][1], checkpointData[i][enterpointLoc][2], 1.5, -1, -1, -1, 100.0);
		checkpointIndex[i][1] = CreateDynamicCP(checkpointData[i][exitpointLoc][0], checkpointData[i][exitpointLoc][1], checkpointData[i][exitpointLoc][2], 1.5, checkpointData[i][virtualWorld], checkpointData[i][interiorWorld], -1, 100.0);
		checkpointIndex[i][2] = CreateDynamicCP(checkpointData[i][robpointLoc][0], checkpointData[i][robpointLoc][1], checkpointData[i][robpointLoc][2], 1.5, checkpointData[i][virtualWorld], checkpointData[i][interiorWorld], -1, 100.0);
		checkpointLabel[i][0][0] = Create3DTextLabel("[ENTER]", COLOR_YELLOW, checkpointData[i][enterpointLoc][0], checkpointData[i][enterpointLoc][1], checkpointData[i][enterpointLoc][2] + 0.2, 25.0, 0, 1);
		checkpointLabel[i][0][1] = Create3DTextLabel(checkpointData[i][storeName], COLOR_WHITE, checkpointData[i][enterpointLoc][0], checkpointData[i][enterpointLoc][1], checkpointData[i][enterpointLoc][2] + 0.05, 25.0, 0, 1);
		checkpointLabel[i][1][0] = Create3DTextLabel("[ROBBERY]", COLOR_YELLOW, checkpointData[i][robpointLoc][0], checkpointData[i][robpointLoc][1], checkpointData[i][robpointLoc][2] + 0.2, 7.5, checkpointData[i][virtualWorld], 1);
		checkpointLabel[i][1][1] = Create3DTextLabel(checkpointData[i][storeName], COLOR_WHITE, checkpointData[i][robpointLoc][0], checkpointData[i][robpointLoc][1], checkpointData[i][robpointLoc][2] + 0.05, 7.5, checkpointData[i][virtualWorld], 1);
		checkpointLabel[i][2][0] = Create3DTextLabel("[EXIT]", COLOR_YELLOW, checkpointData[i][exitpointLoc][0], checkpointData[i][exitpointLoc][1], checkpointData[i][exitpointLoc][2] + 0.2, 7.5, checkpointData[i][virtualWorld], 1);
		checkpointLabel[i][2][1] = Create3DTextLabel(checkpointData[i][storeName], COLOR_WHITE, checkpointData[i][exitpointLoc][0], checkpointData[i][exitpointLoc][1], checkpointData[i][exitpointLoc][2] + 0.05, 7.5, checkpointData[i][virtualWorld], 1);
		
		i++;
	}
	
	//roof1
	Rooftopenter1 = CreateDynamicCP(-1887.6549,907.1999,35.1719, 1.5, -1, -1, -1, 100.0);
	Create3DTextLabel("[ROOF TOP]", COLOR_YELLOW, -1887.6549,907.1999,35.1719 + 0.2, 7.5, 0, 1);
	
	Rooftopexit1 = CreateDynamicCP(-1859.4530,894.4468,60.1250, 1.5, -1, -1, -1, 100.0);
	Create3DTextLabel("[ROOF TOP]", COLOR_YELLOW, -1859.4530,894.4468,60.1250 + 0.2, 7.5, 0, 1);
	
	//roof2
	Rooftopenter2 = CreateDynamicCP(-1888.8352,749.5831,45.4453, 1.5, -1, -1, -1, 100.0);
	Create3DTextLabel("[ROOF TOP]", COLOR_YELLOW, -1888.8352,749.5831,45.4453 + 0.2, 7.5, 0, 1);
	
	Rooftopexit2 = CreateDynamicCP(-1849.5150,782.5520,113.2891, 1.5, -1, -1, -1, 100.0);
	Create3DTextLabel("[ROOF TOP]", COLOR_YELLOW, -1849.5150,782.5520,113.2891 + 0.2, 7.5, 0, 1);
	
	//roof3
	Rooftopenter3 = CreateDynamicCP(-1969.3051,558.4203,35.2082, 1.5, -1, -1, -1, 100.0);
	Create3DTextLabel("[ROOF TOP]", COLOR_YELLOW, -1969.3051,558.4203,35.2082 + 0.2, 7.5, 0, 1);
	
	Rooftopexit3 = CreateDynamicCP(-1965.3505,533.8412,202.2833, 1.5, -1, -1, -1, 100.0);
	Create3DTextLabel("[ROOF TOP]", COLOR_YELLOW, -1965.3505,533.8412,202.2833 + 0.2, 7.5, 0, 1);
	
	//roof
	Rooftopenter4 = CreateDynamicCP(-2260.6223,456.8575,35.1719, 1.5, -1, -1, -1, 100.0);
	Create3DTextLabel("[ROOF TOP]", COLOR_YELLOW, -2260.6223,456.8575,35.1719 + 0.2, 7.5, 0, 1);
	
	Rooftopexit4 = CreateDynamicCP(-2270.2310,475.9317,73.7422, 1.5, -1, -1, -1, 100.0);
	Create3DTextLabel("[ROOF TOP]", COLOR_YELLOW, -2270.2310,475.9317,73.7422 + 0.2, 7.5, 0, 1);
	
	//roof5
	Rooftopenter5 = CreateDynamicCP(-2621.6409,700.3747,27.9577, 1.5, -1, -1, -1, 100.0);
	Create3DTextLabel("[ROOF TOP]", COLOR_YELLOW, -2621.6409,700.3747,27.9577 + 0.2, 7.5, 0, 1);
	
	Rooftopexit5 = CreateDynamicCP(-2635.2007,682.2701,66.0938, 1.5, -1, -1, -1, 100.0);
	Create3DTextLabel("[ROOF TOP]", COLOR_YELLOW, -2635.2007,682.2701,66.0938 + 0.2, 7.5, 0, 1);
	
	//roof6
	Rooftopenter6 = CreateDynamicCP(-2018.8217,959.0989,45.7625, 1.5, -1, -1, -1, 100.0);
	Create3DTextLabel("[ROOF TOP]", COLOR_YELLOW, -2018.8217,959.0989,45.7625 + 0.2, 7.5, 0, 1);
	
	Rooftopexit6 = CreateDynamicCP(-2035.2806,965.5732,73.5953, 1.5, -1, -1, -1, 100.0);
	Create3DTextLabel("[ROOF TOP]", COLOR_YELLOW, -2035.2806,965.5732,73.5953 + 0.2, 7.5, 0, 1);
	
	//roof7
	Rooftopenter7 = CreateDynamicCP(-1494.5844,996.8623,7.1875, 1.5, -1, -1, -1, 100.0);
	Create3DTextLabel("[ROOF TOP]", COLOR_YELLOW, -1494.5844,996.8623,7.1875 + 0.2, 7.5, 0, 1);

	Rooftopexit7 = CreateDynamicCP(-1487.4585,993.5605,26.6625, 1.5, -1, -1, -1, 100.0);
	Create3DTextLabel("[ROOF TOP]", COLOR_YELLOW, -1487.4585,993.5605,26.6625 + 0.2, 7.5, 0, 1);
	
	
	// Hospital checkpoints
	hospitalCP[0] = CreateDynamicCP(-2646.3896, 637.6770, 14.4531, 1.5, -1, -1, -1, 100.0);
	Create3DTextLabel("[HOSPITAL]", COLOR_YELLOW, -2646.3896, 637.6770, 14.4531 + 0.2, 7.5, 0, 1);
	
	// paraCP	= CreateDynamicCP(1673.670043, 1447.932861, 10.784775, 1.5, -1, -1, -1, 100.0);
	// Create3DTextLabel("[SKYDIVE]", COLOR_YELLOW, 1673.670043, 1447.932861, 10.784775 + 0.2, 7.5, 0, 1);
	
	hospitalCP[1] = CreateDynamicCP(-1989.2262, 1039.9451, 55.7266, 1.5, -1, -1, -1, 100.0);
	Create3DTextLabel("[HOSPITAL]", COLOR_YELLOW, -1989.2262, 1039.9451, 55.7266 + 0.2, 7.5, 0, 1);
	
	hospitalCP[2] = CreateDynamicCP(1613.299682, 1817.051269, 10.820312, 1.5, -1, -1, -1, 100.0);
	Create3DTextLabel("[HOSPITAL]", COLOR_YELLOW, 1613.299682, 1817.051269, 10.820312 + 0.2, 7.5, 0, 1);
	
	// Gym checkpoint
	gymCP[0] = CreateDynamicCP(768.3436, -36.8582, 1000.6865, 1.5, 11, 6, -1, 100.0);
	Create3DTextLabel("[FIGHT STYLES]", COLOR_YELLOW, 768.3436, -36.8582, 1000.6865 + 0.2, 7.5, 11, 1);
	
	gymCP[1] = CreateDynamicCP(775.139648, -62.132026, 1000.718383, 1.5, 127, 7, -1, 100.0);
	Create3DTextLabel("[FIGHT STYLES]", COLOR_YELLOW, 775.139648, -62.132026, 1000.718383 + 0.2, 7.5, 127, 1);
	
	// Ammunation checkpoints
	ammuCP[0] = CreateDynamicCP(307.6529, -140.9446, 999.6016, 1.5, 14, 7, -1, 100.0);
	Create3DTextLabel("[BUY GUNS]", COLOR_YELLOW, 307.6529, -140.9446, 999.6016 + 0.2, 7.5, 14, 1);

	ammuCP[1] = CreateDynamicCP(290.1451, -109.1290, 1001.5156, 1.5, 30, 6, -1, 100.0);
	Create3DTextLabel("[BUY GUNS]", COLOR_YELLOW, 290.1451, -109.1290, 1001.5156 + 0.2, 7.5, 30, 1);
	
	ammuCP[2] = CreateDynamicCP(295.185638, -37.894130, 1001.515625, 1.5, 112, 1, -1, 100.0);
	Create3DTextLabel("[BUY GUNS]", COLOR_YELLOW, 295.185638, -37.894130, 1001.515625 + 0.2, 7.5, 112, 1);
	
	ammuCP[3] = CreateDynamicCP(311.274078, -165.135086, 999.601013, 1.5, 125, 6, -1, 100.0);
	Create3DTextLabel("[BUY GUNS]", COLOR_YELLOW, 311.274078, -165.135086, 999.601013 + 0.2, 7.5, 125, 1);
	
	ammuCP[4] = CreateDynamicCP(294.803466, -37.735492, 1001.515625, 1.5, 133, 1, -1, 100.0);
	Create3DTextLabel("[BUY GUNS]", COLOR_YELLOW, 294.803466, -37.735492, 1001.515625 + 0.2, 7.5, 133, 1);
	
	ammuCP[5] = CreateDynamicCP(289.319824, -108.282943, 1001.515625, 1.5, 140, 6, -1, 100.0);
	Create3DTextLabel("[BUY GUNS]", COLOR_YELLOW, 289.319824, -108.282943, 1001.515625 + 0.2, 7.5, 140, 1);
	
	// VIP Entrance
	VIPCP1 = CreateDynamicCP(-1782.9896, 572.3909, 35.1641, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("[VIP LOUNGE]", COLOR_YELLOW, -1782.9896, 572.3909, 35.1641 + 0.2, 7.5, 0, 1);
	
	VIPCP3 = CreateDynamicCP(2015.3485, 1183.4327, 10.8203, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("[VIP LOUNGE]", COLOR_YELLOW, 2015.3485, 1183.4327, 10.8203 + 0.2, 7.5, 0, 1);
	
	// VIP Exit
	VIPCP2 = CreateDynamicCP(1204.7449, -13.1403, 1000.9219, 1.5, 80, 2, -1, 100.0);
	Create3DTextLabel("[EXIT]", COLOR_YELLOW, 1204.7449, -13.1403, 1000.9219 + 0.2, 7.5, 80, 1);
	
	VIPCP4 = CreateDynamicCP(974.6344, -8.7106, 1001.1484, 1.5, 81, 3, -1, 100.0);
	Create3DTextLabel("[EXIT]", COLOR_YELLOW, 974.6344, -8.7106, 1001.1484 + 0.2, 7.5, 81, 1);
	
	// City Hall Entrance
	CITYHALL1 = CreateDynamicCP(-1881.7596, 823.4250, 35.1763, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("[JOB CENTRE]", COLOR_YELLOW, -1881.7596, 823.4250, 35.1763 + 0.2, 7.5, 0, 1);
	
	// City Hall Exit
	CITYHALL2 = CreateDynamicCP(388.7112, 173.7509, 1008.3828, 1.5, 80, 3, -1, 100.0);
	Create3DTextLabel("[EXIT]", COLOR_YELLOW, 388.7112, 173.7509, 1008.3828 + 0.2, 7.5, 80, 1);
	
	// City Hall Exit
	CITYHALL3 = CreateDynamicCP(364.6031, 173.7774, 1008.3893, 1.5, 80, 3, -1, 100.0);
	Create3DTextLabel("[CHANGE JOB]", COLOR_YELLOW, 364.6031,173.7774,1008.3893 + 0.2, 7.5, 80, 1);
	
	// City Hall Exit
	CITYHALL4 = CreateDynamicCP(1860.300292, 2418.923583, 20.831604 , 1.5, 146, 11, -1, 100.0);
	Create3DTextLabel("[CHANGE JOB]", COLOR_YELLOW, 1860.300292, 2418.923583, 20.831604 + 0.2, 7.5, 146, 1);
	
	// Undercover Police CP
	PoliceCP[0] = CreateDynamicCP(-1593.0814, 716.0906, -5.2422, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("/undercover", COLOR_YELLOW, -1593.0814, 716.0906, -5.2422 + 0.2, 7.5, 0, 1);
	
	PoliceCP[1] = CreateDynamicCP(297.279968, 183.204650, 1007.171875, 1.5, 142, 3, -1, 100.0);
	Create3DTextLabel("/undercover", COLOR_YELLOW, 297.279968, 183.204650, 1007.171875 + 0.2, 7.5, 142, 1);
	
	// CIA Dropoff CP
	Dropoff1CP = CreateDynamicCP(-2441.1772, 523.7015, 29.9075, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("/dropoff", COLOR_YELLOW, -2441.1772, 523.7015, 29.9075 + 0.2, 7.5, 0, 1);
	
	// Police Dropoff CP
	Dropoff2CP = CreateDynamicCP(-1606.5209, 674.1558, -5.2422, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("/dropoff", COLOR_YELLOW, -1606.5209, 674.1558, -5.2422 + 0.2, 7.5, 0, 1);
	
	// Helicopter Dropoff CP
	Dropoff3CP = CreateDynamicCP(-1687.4637, 705.8870, 30.6016, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("/helidropoff", COLOR_YELLOW, -1687.4637, 705.8870, 30.6016 + 0.2, 7.5, 0, 1);
	
	Dropoff4CP = CreateDynamicCP(962.809814, 1757.652954, 8.648437, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("/dropoff", COLOR_YELLOW, 962.809814, 1757.652954, 8.648437 + 0.2, 7.5, 0, 1);
	
	Dropoff5CP = CreateDynamicCP(2291.119873, 2474.975585, 10.820312, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("/dropoff", COLOR_YELLOW, 2291.119873, 2474.975585, 10.820312 + 0.2, 7.5, 0, 1);
	
	// Car Drop Off
	CardropCP = CreateDynamicCP(-1734.0756, 190.9162, 3.5547, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("/cardrop", COLOR_YELLOW, -1734.0756, 190.9162, 3.5547 + 0.2, 7.5, 0, 1);
	
	// Bank CP
	bankCP = CreateDynamicCP(293.3139, 1785.0350, 524.9329, 1.5, -1, 3, -1, 100.0);
	Create3DTextLabel("[BANK MENU]", COLOR_YELLOW, 293.3139, 1785.0350, 524.9329 + 0.2, 7.5, 32, 1);
	
	// Parachute fun CP
	skydiveCP = CreateDynamicCP(-1830.3862, 572.7914, 35.1641, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("Skydive", COLOR_YELLOW, -1830.3862, 572.7914, 35.1641 + 0.2, 7.5, 0, 1);

	// Explosive store
	explosiveStoreCP = CreateDynamicCP(-1787.0114, 1207.0797, 25.1250, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("[BOMB SHOP]", COLOR_YELLOW, -1787.0114, 1207.0797, 25.1250 + 0.2, 7.5, 0, 1);
	
	explosiveStoreCP2 = CreateDynamicCP(2490.360107, 1864.421875, 10.820312, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("[BOMB SHOP]", COLOR_YELLOW, 2490.360107, 1864.421875, 10.820312 + 0.2, 7.5, 0, 1);

	// Admin Lounge Entrance
	adminLounge1 = CreateDynamicCP(-2036.5284, 1196.7173, 46.2395, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("[ADMINISTRATION OFFICES]", COLOR_YELLOW, -2036.5284, 1196.7173, 46.2395 + 0.2, 7.5, 0, 1);

	// Dildo Dispenser
	dildoCP = CreateDynamicCP(2027.8969, -769.7808, 1933.2949, 1.5, 69, 69, -1, 100.0);
	Create3DTextLabel("[DILDO DISPENSER]", COLOR_YELLOW, 2027.8969, -769.7808, 1934.3079 + 0.2, 7.5, 69, 1);	
	
	// Vehicle Dealership
	dealership[0] = CreateDynamicCP(-1932.4017, 273.9533, 41.0391, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("{58D3F7}[VEHICLE DEALERSHIP]", COLOR_WHITE, -1932.4017, 273.9533, 41.0391 + 0.2, 7.5, 0, 1);	
	
	dealership[1] = CreateDynamicCP(1736.789916, 1861.472778, 10.820312, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("{58D3F7}[VEHICLE DEALERSHIP]", COLOR_WHITE, 1736.789916, 1861.472778, 10.820312 + 0.2, 7.5, 0, 1);	
	
	rooftop[0] = CreateDynamicCP(2487.744873, 2397.275390, 10.820312, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("{58D3F7}[ROOFTOP]", COLOR_WHITE, 2487.744873, 2397.275390, 10.820312 + 0.2, 7.5, 0, 1);
	
	rooftop[1] = CreateDynamicCP(2457.135986, 2356.289550, 71.049575, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("{58D3F7}[ROOFTOP]", COLOR_WHITE, 2457.135986, 2356.289550, 71.049575 + 0.2, 7.5, 0, 1);
	
	// ATM MACHINES
	atms[0] = CreateDynamicCP(-1494.5941, 930.8608, 7.1875, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("{58D3F7}[ATM]", COLOR_WHITE, -1494.5941, 930.8608, 7.1875 + 0.2, 7.5, 0, 1);		

	atms[1] = CreateDynamicCP(-1867.2999, 941.8069, 35.1719, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("{58D3F7}[ATM]", COLOR_WHITE, -1867.2999, 941.8069, 35.1719 + 0.2, 7.5, 0, 1);	

	atms[2] = CreateDynamicCP(-1622.1221, 718.2737, 14.6094, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("{58D3F7}[ATM]", COLOR_WHITE, -1622.1221, 718.2737, 14.6094 + 0.2, 7.5, 0, 1);	

	atms[3] = CreateDynamicCP(-2450.1624, 754.0579, 35.1719, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("{58D3F7}[ATM]", COLOR_WHITE, -2450.1624, 754.0579, 35.1719 + 0.2, 7.5, 0, 1);	

	atms[4] = CreateDynamicCP(-2727.4233, 387.8848, 4.3672, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("{58D3F7}[ATM]", COLOR_WHITE, -2727.4233, 387.8848, 4.3672 + 0.2, 7.5, 0, 1);		
	
	atms[5] = CreateDynamicCP(-2639.1309, 635.3391, 14.4531, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("{58D3F7}[ATM]", COLOR_WHITE, -2639.1309, 635.3391, 14.4531 + 0.2, 7.5, 0, 1);	
	
	atms[6] = CreateDynamicCP(-1764.6906, 1085.3811, 45.4453, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("{58D3F7}[ATM]", COLOR_WHITE, -1764.6906, 1085.3811, 45.4453 + 0.2, 7.5, 0, 1);
	
	atms[7] = CreateDynamicCP(-1937.6761, 265.3134, 41.0469, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("{58D3F7}[ATM]", COLOR_WHITE, -1937.6761, 265.3134, 41.0469 + 0.2, 7.5, 0, 1);

	atms[8] = CreateDynamicCP(1969.2300, 1721.0309, 10.8203, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("{58D3F7}[ATM]", COLOR_WHITE, 1969.2300, 1721.0309, 10.8203 + 0.2, 7.5, 0, 1);
	
	atms[9] = CreateDynamicCP(2195.3145, 962.4694, 10.9776, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("{58D3F7}[ATM]", COLOR_WHITE, 2195.3145, 962.4694, 10.9776 + 0.2, 7.5, 0, 1);
	
	atms[10] = CreateDynamicCP(2486.9468, 1021.2618, 10.8203, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("{58D3F7}[ATM]", COLOR_WHITE, 2486.9468, 1021.2618, 10.8203 + 0.2, 7.5, 0, 1);
	
	atms[11] = CreateDynamicCP(2409.4326, 1542.2832, 10.8203, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("{58D3F7}[ATM]", COLOR_WHITE, 2409.4326,1542.2832,10.8203 + 0.2, 7.5, 0, 1);
	
	atms[12] = CreateDynamicCP(2293.1919, 1885.1876, 10.8145, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("{58D3F7}[ATM]", COLOR_WHITE, 2293.1919, 1885.1876, 10.8145 + 0.2, 7.5, 0, 1);
	
	atms[13] = CreateDynamicCP(2511.4316, 2061.3333, 10.8203, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("{58D3F7}[ATM]", COLOR_WHITE, 2511.4316, 2061.3333, 10.8203 + 0.2, 7.5, 0, 1);
	
	atms[14] = CreateDynamicCP(2182.5444, 2461.2612, 10.8203, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("{58D3F7}[ATM]", COLOR_WHITE, 2182.5444, 2461.2612, 10.8203 + 0.2, 7.5, 0, 1);
	
	atms[15] = CreateDynamicCP(2095.4751, 2711.5986, 10.8203, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("{58D3F7}[ATM]", COLOR_WHITE, 2095.4751, 2711.5986, 10.8203 + 0.2, 7.5, 0, 1);
	
	atms[16] = CreateDynamicCP(1705.7324, 1853.7559, 10.8203, 1.5, -1, 0, -1, 100.0);
	Create3DTextLabel("{58D3F7}[ATM]", COLOR_WHITE, 1705.7324, 1853.7559, 10.8203 + 0.2, 7.5, 0, 1);
	
	// ARMY DOORS
	armyCP[0] = CreateDynamicCP(-1606.3251, 316.2504, 7.1875, 1.5, -1, 0, -1, 100.0);
	armyCP[1] = CreateDynamicCP(-1562.8190, 329.3299, 22.6412, 1.5, -1, 0, -1, 100.0);
	
	// GAMES ARENA
	arenaCP = CreateDynamicCP(999, -1495.6967, 945.2255, 7.1875, -1, 0, -1, 100.0);
}

public OnPlayerEnterDynamicCP(playerid, checkpointid)
{
	new message[128], tickCountResult = GetTickCount(), reducedValue;
	if(!IsPlayerInAnyVehicle(playerid))
	{
		if(playerData[playerid][playerJailTime] <= 0)
		{
			for(new i; i < MAX_ROB_CHECKPOINT; i++)
			{
				if(checkpointid == checkpointIndex[i][0])
				{
					reducedValue = tickCountResult - playerData[playerid][playerCheckpointTime];
					
					if(reducedValue > 3000)
					{
						playerData[playerid][playerCheckpointTime] = GetTickCount();
						
						SetPlayerPos(playerid, checkpointData[i][exitpointLoc][0], checkpointData[i][exitpointLoc][1], checkpointData[i][exitpointLoc][2]);
						SetPlayerInterior(playerid, checkpointData[i][interiorWorld]);
						SetPlayerVirtualWorld(playerid, checkpointData[i][virtualWorld]);
						
						loadObjects(playerid);
						playerData[playerid][lastEnteredID] = i;
					}
				}
			
				if(checkpointid == checkpointIndex[i][1])
				{
					reducedValue = tickCountResult - playerData[playerid][playerCheckpointTime];
				
					if(reducedValue > 3000)
					{
						new exitTo = playerData[playerid][lastEnteredID];
						playerData[playerid][playerCheckpointTime] = GetTickCount();
					
						SetPlayerPos(playerid, checkpointData[exitTo][enterpointLoc][0], checkpointData[exitTo][enterpointLoc][1], checkpointData[exitTo][enterpointLoc][2]);
						SetPlayerInterior(playerid, 0);
						SetPlayerVirtualWorld(playerid, 0);
						
						loadObjects(playerid);
					}
				}
			
				if(checkpointid == checkpointIndex[i][2])
				{
					if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
					{
						format(message, sizeof(message), "{FFFF00}[HELP] {FFFFFF}Use L ALT or /robstore to begin a robbery!");
						SendClientMessage(playerid, COLOR_WHITE, message);
					}
				}
			}
			
			// Army checkpoint 1
			if(checkpointid == armyCP[0])
			{
				if (playerData[playerid][playerClass] == CLASS_ARMY || playerData[playerid][playerLevel] >= 6)
				{
					// Allowed to enter
					reducedValue = tickCountResult - playerData[playerid][playerCheckpointTime];
					
					if(reducedValue > 3000)
					{
						playerData[playerid][playerCheckpointTime] = GetTickCount();
						
						SetPlayerPos(playerid, -1563.2822, 329.3594, 22.6412);
						SetPlayerFacingAngle(playerid, 87.5765);
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Only the army may use this door.");
				}
			}
			
			if(checkpointid == armyCP[1])
			{
				if (playerData[playerid][playerClass] == CLASS_ARMY || playerData[playerid][playerLevel] >= 6)
				{
					// Allowed to enter
					reducedValue = tickCountResult - playerData[playerid][playerCheckpointTime];
					
					if(reducedValue > 3000)
					{
						playerData[playerid][playerCheckpointTime] = GetTickCount();
						
						SetPlayerPos(playerid, -1606.3251, 316.2504, 7.1875);
						SetPlayerFacingAngle(playerid, 87.5765);
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Only the army may use this door.");
				}
			}

		
			// Hospital checkpoint
			if(checkpointid == hospitalCP[0] || checkpointid == hospitalCP[1] || checkpointid == hospitalCP[2])
			{
				ShowPlayerDialog(playerid, DIALOG_HOSPITAL, DIALOG_STYLE_LIST, "Hospital", "Full Health {D87C3E}$1,000{FFFFFF} \nCure STDs {D87C3E}$2,000{FFFFFF} \nHealth Insurance {D87C3E}$20,000{FFFFFF}", "Go", "Cancel");
			}
			
			// Arena Checkpoint
			if(checkpointid == arenaCP)
			{
				if (playerData[playerid][playerWantedLevel] == 0)
				{
					if(playerData[playerid][playerJailTime] <= 0)
					{
						if(!playerData[playerid][playerIsTied])
						{
							ShowPlayerDialog(playerid, DIALOG_MINIGAMES, DIALOG_STYLE_LIST, "Minigames", "Deathmatch Arena", "Go", "Cancel");
						}
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot do this whilst you have a wanted level.");
				}
			}
			
			// Dealership checkpoint
			if(checkpointid == dealership[0] || checkpointid == dealership[1])
			{
				if(checkpointid == dealership[0])
					SetPVarInt(playerid, "kodedealership", 0);
				else
					SetPVarInt(playerid, "kodedealership", 1);
					
				if (playerData[playerid][actualID] == 0 || playerData[playerid][actualID] == -1)
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Your session token is invalid, please quit and re-join to purchase a vehicle.");
				}
				else
				{
					showDealershipDialogTypes(playerid);
				}
			}
			
			// Gym checkpoint
			if(checkpointid == gymCP[0] || checkpointid == gymCP[1])
			{
				ShowPlayerDialog(playerid, DIALOG_GYM, DIALOG_STYLE_LIST, "Gym", "Default {D87C3E}FREE{FFFFFF} \nBoxing {D87C3E}$20,000{FFFFFF} \nKungfu {D87C3E}$15,000{FFFFFF} \nKnee-head {D87C3E}$12,000{FFFFFF} \nGrab-kick {D87C3E}$10,000{FFFFFF} \nElbow {D87C3E}$8,000{FFFFFF}", "Go", "Cancel");
			}
			
			if(checkpointid == paraCP)
			{
				SetPlayerInterior(playerid, 9);
            	SetPlayerPos(playerid, 1673.670043, 1447.932861, 1200.784775);
            	GivePlayerWeapon(playerid, 46, 1);
            	playerData[playerid][skydiveTimer] = SetTimerEx("SkydiveInteriorChanger", 5000, true, "d", playerid);
			}
			
			// Ammunation checkpoint
			if(checkpointid == ammuCP[0] || checkpointid == ammuCP[1] || checkpointid == ammuCP[2] || checkpointid == ammuCP[3] || checkpointid == ammuCP[4] || checkpointid == ammuCP[5])
			{
				ShowPlayerDialog(playerid, DIALOG_AMMU, DIALOG_STYLE_LIST, "Ammunation", "Melee\nHandguns\nSub-machine guns\nShotguns\nAssault rifles\nRifles\n{D87C3E}$10,000    {FFFFFF}Weapon Skills {FFBF00}(Permanent)", "Go", "Cancel");
			}
			
			// Bank checkpoint
			if(checkpointid == bankCP || checkpointid == atms[0] || checkpointid == atms[1] || checkpointid == atms[2] || checkpointid == atms[3] || checkpointid == atms[4] || checkpointid == atms[5] || checkpointid == atms[6] || checkpointid == atms[7] || checkpointid == atms[8] || checkpointid == atms[9] || checkpointid == atms[10] || checkpointid == atms[11] || checkpointid == atms[12] || checkpointid == atms[13] || checkpointid == atms[14] || checkpointid == atms[15] || checkpointid == atms[16])
			{
				ShowPlayerDialog(playerid, DIALOG_BANK, DIALOG_STYLE_LIST, "Bank of San Fierro", "Account Information \nWithdraw Cash \nDeposit Cash", "Go", "Cancel");
			}
			
			// City Hall checkpoint
			if(checkpointid == CITYHALL3 || checkpointid == CITYHALL4)
			{
				if (playerData[playerid][playerClass] == CLASS_CIVILIAN)
				{
					ShowPlayerDialog(playerid, DIALOG_CITYHALL, DIALOG_STYLE_LIST, "Job Center", "Job Change {D87C3E}$2,000{FFFFFF}\n", "Go", "Cancel");
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be a civilian to change your job.");
				}
			}
			
			if (checkpointid == skydiveCP)
			{
				// Skydive
				SetPlayerPos(playerid, -1813.0156, 576.6133, 234.8906);
			}
			
			// Admin Entrance
			if(checkpointid == adminLounge1)
			{
				if (playerData[playerid][playerLevel] >= 1)
				{
					// Allowed to enter
					reducedValue = tickCountResult - playerData[playerid][playerCheckpointTime];
					
					if(reducedValue > 3000)
					{
						playerData[playerid][playerCheckpointTime] = GetTickCount();
					
						SetPlayerPos(playerid, 2027.7118, -773.7289, 1934.3000);
						SetPlayerInterior(playerid, 69);
						SetPlayerVirtualWorld(playerid, 69);	
						SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[ADMIN LOUNGE] {FFFFFF}Welcome to the Admin Lounge. Type {FFDC2E}/exitlounge {FFFFFF}to leave.");
						
						loadObjects(playerid);
					}
				}
				else
				{
					// Not allowed to enter
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not have permission to enter this building.");
				}
			}
			
			if(checkpointid == dildoCP)
			{
				if (playerData[playerid][playerLevel] >= 1)
				{
					// Allowed to enter
					reducedValue = tickCountResult - playerData[playerid][playerCheckpointTime];
					
					if(reducedValue > 3000)
					{
						GivePlayerWeaponEx(playerid, 10, 1);
						SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[DILDO DISPENSER] {FFFFFF}You received a {FFDC2E}FREE DILDO{FFFFFF}.");
					}
				}
				else
				{
					// Not allowed to enter
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not have permission to obtain a free dildo.");
				}
			}
			
			// VIP Entrance
			if(checkpointid == VIPCP1)
			{
				if (playerData[playerid][playerVIPLevel] >= 1)
				{
					// Allowed to enter
					reducedValue = tickCountResult - playerData[playerid][playerCheckpointTime];
					
					if(reducedValue > 3000)
					{
						playerData[playerid][playerCheckpointTime] = GetTickCount();
					
						SetPlayerPos(playerid, 1204.7449, -13.1403, 1000.9219);
						SetPlayerInterior(playerid, 2);
						SetPlayerVirtualWorld(playerid, 80);
						SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[VIP LOUNGE] {FFFFFF}Welcome to the VIP Lounge.");
						
						loadObjects(playerid);
					}
				}
				else
				{
					// Not allowed to enter
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Only VIPs can enter the lounge.");
				}
			}
			
			// VIP Exit
			if(checkpointid == VIPCP2)
			{
				reducedValue = tickCountResult - playerData[playerid][playerCheckpointTime];
				
				if(reducedValue > 3000)
				{
					playerData[playerid][playerCheckpointTime] = GetTickCount();
				
					SetPlayerPos(playerid, -1782.9896, 572.3909, 35.1641);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);
					
					loadObjects(playerid);
				}
			}
			
			// VIP Entrance lv
			if(checkpointid == VIPCP3)
			{
				if (playerData[playerid][playerVIPLevel] >= 1)
				{
					// Allowed to enter
					reducedValue = tickCountResult - playerData[playerid][playerCheckpointTime];

					if(reducedValue > 3000)
					{
						playerData[playerid][playerCheckpointTime] = GetTickCount();

						SetPlayerPos(playerid, 974.6344, -8.7106, 1001.1484);
						SetPlayerInterior(playerid, 3);
						SetPlayerVirtualWorld(playerid, 81);
						SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[VIP LOUNGE] {FFFFFF}Welcome to the VIP Lounge.");

						loadObjects(playerid);
					}
				}
				else
				{
					// Not allowed to enter
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Only VIPs can enter the lounge.");
				}
			}

			// VIP Exit lv
			if(checkpointid == VIPCP4)
			{
				reducedValue = tickCountResult - playerData[playerid][playerCheckpointTime];

				if(reducedValue > 3000)
				{
					playerData[playerid][playerCheckpointTime] = GetTickCount();

					SetPlayerPos(playerid, 2015.3485, 1183.4327, 10.8203);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);

					loadObjects(playerid);
				}
			}
			
			// roof1
			if(checkpointid == Rooftopenter1)
			{
				if (playerData[playerid][playerVIPLevel] >= 1)
				{
					// Allowed to enter
					reducedValue = tickCountResult - playerData[playerid][playerCheckpointTime];

					if(reducedValue > 3000)
					{
						playerData[playerid][playerCheckpointTime] = GetTickCount();

						SetPlayerPos(playerid, -1859.4530,894.4468,60.1250);
						SetPlayerInterior(playerid, 0);
						SetPlayerVirtualWorld(playerid, 0);
						SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[ROOF top] {FFFFFF}Welcome to the ROOF TOP.");

						loadObjects(playerid);
					}
				}
				else
				{
					// Not allowed to enter
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Only VIPs can enter the ROOF TOP.");
				}
			}

			// roof1 exit
			if(checkpointid == Rooftopexit1)
			{
				reducedValue = tickCountResult - playerData[playerid][playerCheckpointTime];

				if(reducedValue > 3000)
				{
					playerData[playerid][playerCheckpointTime] = GetTickCount();

					SetPlayerPos(playerid, -1887.6549,907.1999,35.1719);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);

					loadObjects(playerid);
				}
			}
			
			// roof2
			if(checkpointid == Rooftopenter2)
			{
				if (playerData[playerid][playerVIPLevel] >= 1)
				{
					// Allowed to enter
					reducedValue = tickCountResult - playerData[playerid][playerCheckpointTime];

					if(reducedValue > 3000)
					{
						playerData[playerid][playerCheckpointTime] = GetTickCount();

						SetPlayerPos(playerid, -1849.5150,782.5520,113.2891);
						SetPlayerInterior(playerid, 0);
						SetPlayerVirtualWorld(playerid, 0);
						SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[ROOF top] {FFFFFF}Welcome to the ROOF TOP.");

						loadObjects(playerid);
					}
				}
				else
				{
					// Not allowed to enter
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Only VIPs can enter the ROOF TOP.");
				}
			}

			// roof2 exit
			if(checkpointid == Rooftopexit2)
			{
				reducedValue = tickCountResult - playerData[playerid][playerCheckpointTime];

				if(reducedValue > 3000)
				{
					playerData[playerid][playerCheckpointTime] = GetTickCount();

					SetPlayerPos(playerid, -1888.8352,749.5831,45.4453);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);

					loadObjects(playerid);
				}
			}
			
			// roof3
			if(checkpointid == Rooftopenter3)
			{
				if (playerData[playerid][playerVIPLevel] >= 1)
				{
					// Allowed to enter
					reducedValue = tickCountResult - playerData[playerid][playerCheckpointTime];

					if(reducedValue > 3000)
					{
						playerData[playerid][playerCheckpointTime] = GetTickCount();

						SetPlayerPos(playerid, -1965.3505,533.8412,202.2833);
						SetPlayerInterior(playerid, 0);
						SetPlayerVirtualWorld(playerid, 0);
						SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[ROOF top] {FFFFFF}Welcome to the ROOF TOP.");

						loadObjects(playerid);
					}
				}
				else
				{
					// Not allowed to enter
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Only VIPs can enter the ROOF TOP.");
				}
			}

			// roof3 exit
			if(checkpointid == Rooftopexit3)
			{
				reducedValue = tickCountResult - playerData[playerid][playerCheckpointTime];

				if(reducedValue > 3000)
				{
					playerData[playerid][playerCheckpointTime] = GetTickCount();

					SetPlayerPos(playerid, -1969.3051,558.4203,35.2082);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);

					loadObjects(playerid);
				}
			}
			
			// roof4
			if(checkpointid == Rooftopenter4)
			{
				if (playerData[playerid][playerVIPLevel] >= 1)
				{
					// Allowed to enter
					reducedValue = tickCountResult - playerData[playerid][playerCheckpointTime];

					if(reducedValue > 3000)
					{
						playerData[playerid][playerCheckpointTime] = GetTickCount();

						SetPlayerPos(playerid, -2270.2310,475.9317,73.7422);
						SetPlayerInterior(playerid, 0);
						SetPlayerVirtualWorld(playerid, 0);
						SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[ROOF top] {FFFFFF}Welcome to the ROOF TOP.");

						loadObjects(playerid);
					}
				}
				else
				{
					// Not allowed to enter
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Only VIPs can enter the ROOF TOP.");
				}
			}

			// roof4 exit
			if(checkpointid == Rooftopexit4)
			{
				reducedValue = tickCountResult - playerData[playerid][playerCheckpointTime];

				if(reducedValue > 3000)
				{
					playerData[playerid][playerCheckpointTime] = GetTickCount();

					SetPlayerPos(playerid, -2260.6223,456.8575,35.1719);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);

					loadObjects(playerid);
				}
			}
			
			// roof5
			if(checkpointid == Rooftopenter5)
			{
				if (playerData[playerid][playerVIPLevel] >= 1)
				{
					// Allowed to enter
					reducedValue = tickCountResult - playerData[playerid][playerCheckpointTime];

					if(reducedValue > 3000)
					{
						playerData[playerid][playerCheckpointTime] = GetTickCount();

						SetPlayerPos(playerid, -2635.2007,682.2701,66.0938);
						SetPlayerInterior(playerid, 0);
						SetPlayerVirtualWorld(playerid, 0);
						SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[ROOF top] {FFFFFF}Welcome to the ROOF TOP.");

						loadObjects(playerid);
					}
				}
				else
				{
					// Not allowed to enter
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Only VIPs can enter the ROOF TOP.");
				}
			}

			// roof5 exit
			if(checkpointid == Rooftopexit5)
			{
				reducedValue = tickCountResult - playerData[playerid][playerCheckpointTime];

				if(reducedValue > 3000)
				{
					playerData[playerid][playerCheckpointTime] = GetTickCount();

					SetPlayerPos(playerid, -2621.6409,700.3747,27.9577);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);

					loadObjects(playerid);
				}
			}
			
			// roof6
			if(checkpointid == Rooftopenter6)
			{
				if (playerData[playerid][playerVIPLevel] >= 1)
				{
					// Allowed to enter
					reducedValue = tickCountResult - playerData[playerid][playerCheckpointTime];

					if(reducedValue > 3000)
					{
						playerData[playerid][playerCheckpointTime] = GetTickCount();

						SetPlayerPos(playerid, -2035.2806,965.5732,73.5953);
						SetPlayerInterior(playerid, 0);
						SetPlayerVirtualWorld(playerid, 0);
						SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[ROOF top] {FFFFFF}Welcome to the ROOF TOP.");

						loadObjects(playerid);
					}
				}
				else
				{
					// Not allowed to enter
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Only VIPs can enter the ROOF TOP.");
				}
			}

			// roof6 exit
			if(checkpointid == Rooftopexit6)
			{
				reducedValue = tickCountResult - playerData[playerid][playerCheckpointTime];

				if(reducedValue > 3000)
				{
					playerData[playerid][playerCheckpointTime] = GetTickCount();

					SetPlayerPos(playerid, -2018.8217,959.0989,45.7625);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);

					loadObjects(playerid);
				}
			}
			
			//roof7 enter
			if(checkpointid == Rooftopenter7)
			{
				if (playerData[playerid][playerVIPLevel] >= 1)
				{
					// Allowed to enter
					reducedValue = tickCountResult - playerData[playerid][playerCheckpointTime];

					if(reducedValue > 3000)
					{
						playerData[playerid][playerCheckpointTime] = GetTickCount();

						SetPlayerPos(playerid, -1487.4585,993.5605,26.6625);
						SetPlayerInterior(playerid, 0);
						SetPlayerVirtualWorld(playerid, 0);
						SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[ROOF top] {FFFFFF}Welcome to the ROOF TOP.");

						loadObjects(playerid);
					}
				}
				else
				{
					// Not allowed to enter
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Only VIPs can enter the ROOF TOP.");
				}
			}

			// roof7 exit
			if(checkpointid == Rooftopexit7)
			{
				reducedValue = tickCountResult - playerData[playerid][playerCheckpointTime];

				if(reducedValue > 3000)
				{
					playerData[playerid][playerCheckpointTime] = GetTickCount();

					SetPlayerPos(playerid, -1494.5844,996.8623,7.1875);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);

					loadObjects(playerid);
				}
			}

			
			// City Hall Entrance
			if(checkpointid == CITYHALL1)
			{
				// Allowed to enter
				reducedValue = tickCountResult - playerData[playerid][playerCheckpointTime];
				
				if(reducedValue > 3000)
				{
					playerData[playerid][playerCheckpointTime] = GetTickCount();
				
					SetPlayerPos(playerid, 388.7112, 173.7509, 1008.3828);
					SetPlayerInterior(playerid, 3);
					SetPlayerVirtualWorld(playerid, 80);
					
					loadObjects(playerid);
				}
			}
			

			
			// City Hall Exit
			if(checkpointid == CITYHALL2)
			{
				reducedValue = tickCountResult - playerData[playerid][playerCheckpointTime];
				
				if(reducedValue > 3000)
				{
					playerData[playerid][playerCheckpointTime] = GetTickCount();
				
					SetPlayerPos(playerid, -1881.7596, 823.4250, 35.1763);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);
					
					loadObjects(playerid);
				}
			}
			
			if(checkpointid == rooftop[0] || checkpointid == rooftop[1])
			{
				reducedValue = tickCountResult - playerData[playerid][playerCheckpointTime];
				
				if(reducedValue > 3000)
				{
					if(playerData[playerid][playerClass] == CLASS_SECRETSERVICE)
					{
						if(checkpointid == rooftop[0])
							SetPlayerPos(playerid, 2457.135986, 2356.289550, 71.049575);
						else if(checkpointid == rooftop[1])
							SetPlayerPos(playerid, 2487.744873, 2397.275390, 10.820312);
						playerData[playerid][playerCheckpointTime] = GetTickCount();
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Only Secret Service can use this checkpoint.");
					}
				}
			}
			
			if(checkpointid == explosiveStoreCP || checkpointid == explosiveStoreCP2)
			{
				if (playerData[playerid][playerClass] == CLASS_CIVILIAN)
				{
					if (playerData[playerid][playerJob] == JOB_TERRORIST)
					{
						ShowPlayerDialog(playerid, DIALOG_EXPLOSIVE_STORE, DIALOG_STYLE_LIST, "CZCNR Bomb Shop", "1x Explosive {D87C3E}$1,000{FFFFFF} \n2x Explosives {D87C3E}$2,000{FFFFFF} \n5x Explosives {D87C3E}$5,000{FFFFFF} \n10x Explosives {D87C3E}$10,000{FFFFFF} \nSell explosives {D87C3E}$500{FFFFFF} each", "Select", "Cancel");
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be a terrorist to purchase explosives.");
					}
				}
			}
		}
	}
	
	return 1;
}
