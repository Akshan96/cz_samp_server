new glassObject[189];

forward glassZChecker();
public glassZChecker()
{
	new Float:x, Float:y, Float:z;
	
	for(new i = 0; i < MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i) && playerData[i][playerLoggedIn])
		{
			if (playerData[i][isInEvent])
			{
				if (GetPlayerVirtualWorld(i) == 500)
				{
					GetPlayerPos(i, x, y, z);
					
					if (z < 385.00)
					{
						// Player has fallen
						SetPlayerVirtualWorld(i, 0);
						SetPlayerInterior(i, 0);
						
						playerData[i][hasSpawned] = false;
						SpawnPlayer(i);
						
						// Alert all those in DM this player was eliminated
						for (new p=0; p<MAX_PLAYERS; p++)
						{
							if(playerData[p][isInEvent])
							{
								new eliminated[100];
								format(eliminated, sizeof(eliminated), "{FAAC58}%s(%i) {FFFFFF}was eliminated from the event.", playerData[i][playerNamee], i);
								SendClientMessage(p, COLOR_WHITE, eliminated);
							}
						}						
					}
				}
			}
		}
	}
}

stock createGlass()
{
	glassObject[0] = CreateDynamicObject(1649, -1740.44092, 845.66888, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[1] = CreateDynamicObject(1649, -1737.18042, 845.63318, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[2] = CreateDynamicObject(1649, -1740.48816, 841.32959, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[3] = CreateDynamicObject(1649, -1737.22803, 841.29327, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[4] = CreateDynamicObject(1649, -1743.76868, 841.38629, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[5] = CreateDynamicObject(1649, -1743.70081, 845.68628, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[6] = CreateDynamicObject(1649, -1743.67358, 850.00671, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[7] = CreateDynamicObject(1649, -1740.37341, 849.96948, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[8] = CreateDynamicObject(1649, -1737.11243, 849.93317, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[9] = CreateDynamicObject(1649, -1733.85181, 849.89679, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[10] = CreateDynamicObject(1649, -1733.93787, 845.51715, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[11] = CreateDynamicObject(1649, -1733.96399, 841.24866, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[12] = CreateDynamicObject(1649, -1730.74585, 841.14685, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[13] = CreateDynamicObject(1649, -1730.63953, 845.54553, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[14] = CreateDynamicObject(1649, -1730.59717, 849.84680, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[15] = CreateDynamicObject(1649, -1743.81250, 837.06433, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[16] = CreateDynamicObject(1649, -1740.53174, 837.00037, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[17] = CreateDynamicObject(1649, -1737.23096, 836.97479, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[18] = CreateDynamicObject(1649, -1734.09045, 836.91614, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[19] = CreateDynamicObject(1649, -1730.79199, 836.81165, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[20] = CreateDynamicObject(1649, -1747.12341, 837.09131, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[21] = CreateDynamicObject(1649, -1747.06689, 841.43445, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[22] = CreateDynamicObject(1649, -1747.01526, 845.75745, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[23] = CreateDynamicObject(1649, -1746.95740, 849.99884, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[24] = CreateDynamicObject(1649, -1730.82996, 832.48993, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[25] = CreateDynamicObject(1649, -1734.09753, 832.52924, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[26] = CreateDynamicObject(1649, -1737.34229, 832.58447, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[27] = CreateDynamicObject(1649, -1740.63342, 832.60742, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[28] = CreateDynamicObject(1649, -1743.83813, 832.65540, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[29] = CreateDynamicObject(1649, -1747.13342, 832.65881, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[30] = CreateDynamicObject(1649, -1750.43262, 832.73029, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[31] = CreateDynamicObject(1649, -1750.41174, 837.09027, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[32] = CreateDynamicObject(1649, -1750.32996, 841.42944, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[33] = CreateDynamicObject(1649, -1750.28845, 845.78906, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[34] = CreateDynamicObject(1649, -1750.24622, 850.10901, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[35] = CreateDynamicObject(1649, -1730.54651, 854.22644, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[36] = CreateDynamicObject(1649, -1733.78687, 854.29486, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[37] = CreateDynamicObject(1649, -1737.08728, 854.30304, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[38] = CreateDynamicObject(1649, -1740.26367, 854.29370, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[39] = CreateDynamicObject(1649, -1743.52954, 854.32788, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[40] = CreateDynamicObject(1649, -1746.84167, 854.36127, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[41] = CreateDynamicObject(1649, -1750.14624, 854.45685, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[42] = CreateDynamicObject(1649, -1753.71252, 832.77502, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[43] = CreateDynamicObject(1649, -1753.56506, 837.16809, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[44] = CreateDynamicObject(1649, -1753.59863, 841.46564, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[45] = CreateDynamicObject(1649, -1753.53516, 845.80377, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[46] = CreateDynamicObject(1649, -1753.46643, 850.09772, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[47] = CreateDynamicObject(1649, -1753.44092, 854.44940, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[48] = CreateDynamicObject(1649, -1730.49390, 858.64581, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[49] = CreateDynamicObject(1649, -1733.77344, 858.66431, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[50] = CreateDynamicObject(1649, -1737.05298, 858.68329, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[51] = CreateDynamicObject(1649, -1740.31287, 858.70197, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[52] = CreateDynamicObject(1649, -1743.45178, 858.75903, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[53] = CreateDynamicObject(1649, -1746.75024, 858.76831, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[54] = CreateDynamicObject(1649, -1750.05212, 858.79803, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[55] = CreateDynamicObject(1649, -1753.37537, 858.88470, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[56] = CreateDynamicObject(1649, -1756.61438, 858.90198, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[57] = CreateDynamicObject(1649, -1756.71008, 854.54590, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[58] = CreateDynamicObject(1649, -1756.71973, 850.21057, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[59] = CreateDynamicObject(1649, -1756.76819, 845.92291, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[60] = CreateDynamicObject(1649, -1756.84387, 841.63708, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[61] = CreateDynamicObject(1649, -1756.79749, 837.29614, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[62] = CreateDynamicObject(1649, -1756.81995, 832.97583, 388.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[63] = CreateDynamicObject(1649, -1740.44092, 845.66888, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[64] = CreateDynamicObject(1649, -1737.18042, 845.63318, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[65] = CreateDynamicObject(1649, -1740.48816, 841.32959, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[66] = CreateDynamicObject(1649, -1737.22803, 841.29327, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[67] = CreateDynamicObject(1649, -1743.76868, 841.38629, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[68] = CreateDynamicObject(1649, -1743.70081, 845.68628, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[69] = CreateDynamicObject(1649, -1743.67358, 850.00671, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[70] = CreateDynamicObject(1649, -1740.37341, 849.96948, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[71] = CreateDynamicObject(1649, -1737.11243, 849.93317, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[72] = CreateDynamicObject(1649, -1733.85181, 849.89679, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[73] = CreateDynamicObject(1649, -1733.93787, 845.51715, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[74] = CreateDynamicObject(1649, -1733.96399, 841.24866, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[75] = CreateDynamicObject(1649, -1730.74585, 841.14685, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[76] = CreateDynamicObject(1649, -1730.63953, 845.54553, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[77] = CreateDynamicObject(1649, -1730.59717, 849.84680, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[78] = CreateDynamicObject(1649, -1743.81250, 837.06433, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[79] = CreateDynamicObject(1649, -1740.53174, 837.00037, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[80] = CreateDynamicObject(1649, -1737.23096, 836.97479, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[81] = CreateDynamicObject(1649, -1734.09045, 836.91614, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[82] = CreateDynamicObject(1649, -1730.79199, 836.81165, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[83] = CreateDynamicObject(1649, -1747.12341, 837.09131, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[84] = CreateDynamicObject(1649, -1747.06689, 841.43445, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[85] = CreateDynamicObject(1649, -1747.01526, 845.75745, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[86] = CreateDynamicObject(1649, -1746.95740, 849.99884, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[87] = CreateDynamicObject(1649, -1730.82996, 832.48993, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[88] = CreateDynamicObject(1649, -1734.09753, 832.52924, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[89] = CreateDynamicObject(1649, -1737.34229, 832.58447, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[90] = CreateDynamicObject(1649, -1740.63342, 832.60742, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[91] = CreateDynamicObject(1649, -1743.83813, 832.65540, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[92] = CreateDynamicObject(1649, -1747.13342, 832.65881, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[93] = CreateDynamicObject(1649, -1750.43262, 832.73029, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[94] = CreateDynamicObject(1649, -1750.41174, 837.09027, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[95] = CreateDynamicObject(1649, -1750.32996, 841.42944, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[96] = CreateDynamicObject(1649, -1750.28845, 845.78906, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[97] = CreateDynamicObject(1649, -1750.24622, 850.10901, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[98] = CreateDynamicObject(1649, -1730.54651, 854.22644, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[99] = CreateDynamicObject(1649, -1733.78687, 854.29486, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[100] = CreateDynamicObject(1649, -1737.08728, 854.30304, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[101] = CreateDynamicObject(1649, -1740.26367, 854.29370, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[102] = CreateDynamicObject(1649, -1743.52954, 854.32788, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[103] = CreateDynamicObject(1649, -1746.84167, 854.36127, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[104] = CreateDynamicObject(1649, -1750.14624, 854.45685, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[105] = CreateDynamicObject(1649, -1753.71252, 832.77502, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[106] = CreateDynamicObject(1649, -1753.56506, 837.16809, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[107] = CreateDynamicObject(1649, -1753.59863, 841.46564, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[108] = CreateDynamicObject(1649, -1753.53516, 845.80377, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[109] = CreateDynamicObject(1649, -1753.46643, 850.09772, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[110] = CreateDynamicObject(1649, -1753.44092, 854.44940, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[111] = CreateDynamicObject(1649, -1730.49390, 858.64581, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[112] = CreateDynamicObject(1649, -1733.77344, 858.66431, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[113] = CreateDynamicObject(1649, -1737.05298, 858.68329, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[114] = CreateDynamicObject(1649, -1740.31287, 858.70197, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[115] = CreateDynamicObject(1649, -1743.45178, 858.75903, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[116] = CreateDynamicObject(1649, -1746.75024, 858.76831, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[117] = CreateDynamicObject(1649, -1750.05212, 858.79803, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[118] = CreateDynamicObject(1649, -1753.37537, 858.88470, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[119] = CreateDynamicObject(1649, -1756.61438, 858.90198, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[120] = CreateDynamicObject(1649, -1756.71008, 854.54590, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[121] = CreateDynamicObject(1649, -1756.71973, 850.21057, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[122] = CreateDynamicObject(1649, -1756.76819, 845.92291, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[123] = CreateDynamicObject(1649, -1756.84387, 841.63708, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[124] = CreateDynamicObject(1649, -1756.79749, 837.29614, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[125] = CreateDynamicObject(1649, -1756.81995, 832.97583, 408.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[126] = CreateDynamicObject(1649, -1740.44092, 845.66888, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[127] = CreateDynamicObject(1649, -1737.18042, 845.63318, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[128] = CreateDynamicObject(1649, -1740.48816, 841.32959, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[129] = CreateDynamicObject(1649, -1737.22803, 841.29327, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[130] = CreateDynamicObject(1649, -1743.76868, 841.38629, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[131] = CreateDynamicObject(1649, -1743.70081, 845.68628, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[132] = CreateDynamicObject(1649, -1743.67358, 850.00671, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[133] = CreateDynamicObject(1649, -1740.37341, 849.96948, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[134] = CreateDynamicObject(1649, -1737.11243, 849.93317, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[135] = CreateDynamicObject(1649, -1733.85181, 849.89679, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[136] = CreateDynamicObject(1649, -1733.93787, 845.51715, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[137] = CreateDynamicObject(1649, -1733.96399, 841.24866, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[138] = CreateDynamicObject(1649, -1730.74585, 841.14685, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[139] = CreateDynamicObject(1649, -1730.63953, 845.54553, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[140] = CreateDynamicObject(1649, -1730.59717, 849.84680, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[141] = CreateDynamicObject(1649, -1743.81250, 837.06433, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[142] = CreateDynamicObject(1649, -1740.53174, 837.00037, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[143] = CreateDynamicObject(1649, -1737.23096, 836.97479, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[144] = CreateDynamicObject(1649, -1734.09045, 836.91614, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[145] = CreateDynamicObject(1649, -1730.79199, 836.81165, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[146] = CreateDynamicObject(1649, -1747.12341, 837.09131, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[147] = CreateDynamicObject(1649, -1747.06689, 841.43445, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[148] = CreateDynamicObject(1649, -1747.01526, 845.75745, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[149] = CreateDynamicObject(1649, -1746.95740, 849.99884, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[150] = CreateDynamicObject(1649, -1730.82996, 832.48993, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[151] = CreateDynamicObject(1649, -1734.09753, 832.52924, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[152] = CreateDynamicObject(1649, -1737.34229, 832.58447, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[153] = CreateDynamicObject(1649, -1740.63342, 832.60742, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[154] = CreateDynamicObject(1649, -1743.83813, 832.65540, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[155] = CreateDynamicObject(1649, -1747.13342, 832.65881, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[156] = CreateDynamicObject(1649, -1750.43262, 832.73029, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[157] = CreateDynamicObject(1649, -1750.41174, 837.09027, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[158] = CreateDynamicObject(1649, -1750.32996, 841.42944, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[159] = CreateDynamicObject(1649, -1750.28845, 845.78906, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[160] = CreateDynamicObject(1649, -1750.24622, 850.10901, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[161] = CreateDynamicObject(1649, -1730.54651, 854.22644, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[162] = CreateDynamicObject(1649, -1733.78687, 854.29486, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[163] = CreateDynamicObject(1649, -1737.08728, 854.30304, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[164] = CreateDynamicObject(1649, -1740.26367, 854.29370, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[165] = CreateDynamicObject(1649, -1743.52954, 854.32788, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[166] = CreateDynamicObject(1649, -1746.84167, 854.36127, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[167] = CreateDynamicObject(1649, -1750.14624, 854.45685, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[168] = CreateDynamicObject(1649, -1753.71252, 832.77502, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[169] = CreateDynamicObject(1649, -1753.56506, 837.16809, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[170] = CreateDynamicObject(1649, -1753.59863, 841.46564, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[171] = CreateDynamicObject(1649, -1753.53516, 845.80377, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[172] = CreateDynamicObject(1649, -1753.46643, 850.09772, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[173] = CreateDynamicObject(1649, -1753.44092, 854.44940, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[174] = CreateDynamicObject(1649, -1730.49390, 858.64581, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[175] = CreateDynamicObject(1649, -1733.77344, 858.66431, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[176] = CreateDynamicObject(1649, -1737.05298, 858.68329, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[177] = CreateDynamicObject(1649, -1740.31287, 858.70197, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[178] = CreateDynamicObject(1649, -1743.45178, 858.75903, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[179] = CreateDynamicObject(1649, -1746.75024, 858.76831, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[180] = CreateDynamicObject(1649, -1750.05212, 858.79803, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[181] = CreateDynamicObject(1649, -1753.37537, 858.88470, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[182] = CreateDynamicObject(1649, -1756.61438, 858.90198, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[183] = CreateDynamicObject(1649, -1756.71008, 854.54590, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[184] = CreateDynamicObject(1649, -1756.71973, 850.21057, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[185] = CreateDynamicObject(1649, -1756.76819, 845.92291, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[186] = CreateDynamicObject(1649, -1756.84387, 841.63708, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[187] = CreateDynamicObject(1649, -1756.79749, 837.29614, 428.79611, -90.00000, 0.00000, -90.60000, 500);
	glassObject[188] = CreateDynamicObject(1649, -1756.81995, 832.97583, 428.79611, -90.00000, 0.00000, -90.60000, 500);
}

stock destroyGlass()
{
    for(new i = 0; i < 189; i++)
    {
        DestroyDynamicObject(glassObject[i]);
    }	
	
	KillTimer(glassTimer);
}

COMMAND:glassevent(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 4)
		{
			if (serverInfo[GlassEvent])
			{
				// Close Event
				serverInfo[GlassEvent] = 0;
				SendClientMessageToAll(COLOR_WHITE, "{58D3F7}[EVENT CLOSED] {FFFFFF}An administrator has closed the glass event.");
			}
			else
			{
				destroyGlass();
				createGlass();
						
				// Open Event
				serverInfo[GlassEvent] = 1;
				
				SendClientMessageToAll(COLOR_WHITE, "{58D3F7}[EVENT OPENED] {FFFFFF}An administrator has started a glass event! Type {FFDC2E}/joinglass{FFFFFF} to participate.");
				SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[EVENT HELP] {FFFFFF}To start the event, first type /glassevent again to close entry, then type /startglass to unfreeze players.");
				SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[EVENT HELP] {FFFFFF}When finished, please /destroyglass to free up object space.");
				
				GameTextForPlayer(playerid, "GLASS EVENT OPENED!", 5000, 5);
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:startglass(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 4)
		{
			for(new i = 0; i < MAX_PLAYERS; i++)
			{
				if(IsPlayerConnected(i) && playerData[i][playerLoggedIn])
				{
					if (playerData[i][isInEvent])
					{	
						TogglePlayerControllable(i, 1);
						GameTextForPlayer(i, "GLASS EVENT STARTED!", 5000, 5);
						
						glassTimer = SetTimer("glassZChecker", 3000, true);
					}
				}
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:destroyglass(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 4)
		{
			destroyGlass();
			
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Glass destroyed.");
		}
		else
		{
			return 0;
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:joinglass(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (playerData[playerid][playerWantedLevel] == 0)
		{
			if (playerData[playerid][playerJailTime] < 1)
			{
				if (!playerData[playerid][isInDM])
				{
					if (serverInfo[GlassEvent])
					{
						// Can join event
						new randSpawn = random(16);
						switch(randSpawn)
						{
							case 0:
							{
								SetPlayerPos(playerid, -1756.6765, 833.0526, 429.7961);
							}
							case 1:
							{
								SetPlayerPos(playerid, -1756.7405, 841.5081, 429.7961);
							}
							case 2:
							{
								SetPlayerPos(playerid, -1756.7408, 850.0634, 429.7961);
							}
							case 3:
							{
								SetPlayerPos(playerid, -1756.7194, 858.9014, 429.7961);
							}
							case 4:
							{
								SetPlayerPos(playerid, -1750.2263, 859.0184, 429.7961);
							}
							case 5:
							{
								SetPlayerPos(playerid, -1743.9375, 859.0184, 429.7961);
							}
							case 6:
							{
								SetPlayerPos(playerid, -1736.6906, 859.0184, 429.7961);
							}
							case 7:
							{
								SetPlayerPos(playerid, -1730.7318, 859.0184, 429.7961);
							}
							case 8:
							{
								SetPlayerPos(playerid, -1730.4872, 850.3536, 429.7961);
							}
							case 9:
							{
								SetPlayerPos(playerid, -1730.5259, 841.1364, 429.7961);
							}
							case 10:
							{
								SetPlayerPos(playerid, -1730.6837, 832.7377, 429.7961);
							}
							case 11:
							{
								SetPlayerPos(playerid, -1736.8262, 832.4484, 429.7961);
							}
							case 12:
							{
								SetPlayerPos(playerid, -1744.0161, 832.5099, 429.7961);
							}
							case 13:
							{
								SetPlayerPos(playerid, -1749.9906, 832.5613, 429.7961);
							}
							case 14:
							{
								SetPlayerPos(playerid, -1750.1062, 840.8447, 429.7961);
							}
							case 15:
							{
								SetPlayerPos(playerid, -1750.0922, 849.1535, 429.7961);
							}
							case 16:
							{
								SetPlayerPos(playerid, -1744.1351, 849.7830, 429.7961);
							}
							case 17:
							{
								SetPlayerPos(playerid, -1743.6621, 842.0274, 429.7961);
							}
							case 18:
							{
								SetPlayerPos(playerid, -1737.4501, 841.3073, 429.7961);
							}
							case 19:
							{
								SetPlayerPos(playerid, -1737.0245, 849.3864, 429.7961);
							}
						}
						
						// No team during DM
						SetPlayerTeam(playerid, NO_TEAM);
						
						SetPlayerVirtualWorld(playerid, 500);
						
						playerData[playerid][isInEvent] = true;
						TogglePlayerControllable(playerid, 0);
						
						// Remove armour
						SetPlayerArmour(playerid, 0);
						SetPlayerHealth(playerid, 10000);
						
						ResetPlayerWeapons(playerid);
						playerData[playerid][adminWeapon] = true;
						GivePlayerWeaponEx(playerid, 24, 5000);
						
						GameTextForPlayer(playerid, "THE EVENT WILL START SHORTLY!~n~~r~You are temporarily frozen", 10000, 5);
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}There is no glass event open right now.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Please leave the minigames arena before joining the glass event.");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot join events whilst jailed.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot join events if you have a wanted level.");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
	
	return 1;
}

