
// cnr_dealership

#define DEALERSHIP_TYPES   			10

#define DEALERSHIP_SPORTVEHICLES	0
#define DEALERSHIP_SALOONS			1
#define DEALERSHIP_BIKES			2
#define DEALERSHIP_UNIQUE			3
#define DEALERSHIP_INDUSTRIAL		4
#define DEALERSHIP_LOWRIDER			5
#define DEALERSHIP_OFFROAD			6
#define DEALERSHIP_AIR				7
#define DEALERSHIP_STATIONWAGONS    8
#define DEALERSHIP_CONVERTIBLES     9

new category_choice[MAX_PLAYERS];

enum dealershipEnum
{
	response_id,
	vehicle_model,
	vehicle_price,
	token_price,
	vehicle_type // 0 = sport, 1 = bikes
}

new dealershipData[][dealershipEnum] =
{
	{0, 451, 3000000, 3, DEALERSHIP_SPORTVEHICLES},
	{1, 411, 3000000, 3, DEALERSHIP_SPORTVEHICLES},
	{2, 415, 2500000, 3, DEALERSHIP_SPORTVEHICLES},
	{3, 402, 2500000, 3, DEALERSHIP_SPORTVEHICLES},
	{4, 541, 2500000, 3, DEALERSHIP_SPORTVEHICLES},
	{5, 477, 2000000, 2, DEALERSHIP_SPORTVEHICLES},
	{6, 603, 2000000, 2, DEALERSHIP_SPORTVEHICLES},
	{7, 565, 1500000, 2, DEALERSHIP_SPORTVEHICLES},
	{8, 429, 2000000, 2, DEALERSHIP_SPORTVEHICLES},
	{9, 506, 2000000, 2, DEALERSHIP_SPORTVEHICLES},
	{10, 589, 1250000, 2, DEALERSHIP_SPORTVEHICLES},
	{11, 559, 1500000, 2, DEALERSHIP_SPORTVEHICLES},

	{0, 560, 2000000, 2, DEALERSHIP_SALOONS},
	{1, 562, 1500000, 2, DEALERSHIP_SALOONS},
	{2, 426, 1000000, 1, DEALERSHIP_SALOONS},
	{3, 516, 1000000, 1, DEALERSHIP_SALOONS},
	{4, 518, 1000000, 1, DEALERSHIP_SALOONS},
	{5, 526, 1000000, 1, DEALERSHIP_SALOONS},
	{6, 550, 1000000, 1, DEALERSHIP_SALOONS},
	{7, 540, 500000, 1, DEALERSHIP_SALOONS},
	{8, 542, 500000, 1, DEALERSHIP_SALOONS},
	{9, 547, 500000, 1, DEALERSHIP_SALOONS},
	{10, 434, 1500000, 1, DEALERSHIP_SALOONS},
	
	{0, 522, 3500000, 3, DEALERSHIP_BIKES},
	{1, 463, 1500000, 2, DEALERSHIP_BIKES},
	{2, 468, 1500000, 2, DEALERSHIP_BIKES},
	{3, 471, 1000000, 2, DEALERSHIP_BIKES},
	{4, 462, 600000, 1, DEALERSHIP_BIKES},
	{5, 481, 500000, 1, DEALERSHIP_BIKES},
	{6, 510, 1000000, 1, DEALERSHIP_BIKES},
	{7, 521, 3000000, 3, DEALERSHIP_BIKES},

	{0, 556, 5000000, 3, DEALERSHIP_UNIQUE},
	{1, 557, 5000000, 3, DEALERSHIP_UNIQUE},
	{2, 539, 3000000, 3, DEALERSHIP_UNIQUE},
	{3, 588, 2000000, 3, DEALERSHIP_UNIQUE},
	{4, 571, 1000000, 3, DEALERSHIP_UNIQUE},
	{5, 572, 1000000, 3, DEALERSHIP_UNIQUE},
	{6, 508, 500000, 3, DEALERSHIP_UNIQUE},
	{7, 457, 500000, 3, DEALERSHIP_UNIQUE},
	
	{0, 455, 1000000, 1, DEALERSHIP_INDUSTRIAL},
	{1, 456, 1000000, 1, DEALERSHIP_INDUSTRIAL},
	{2, 499, 1000000, 1, DEALERSHIP_INDUSTRIAL},
	{3, 482, 1000000, 1, DEALERSHIP_INDUSTRIAL},
	{4, 543, 1000000, 1, DEALERSHIP_INDUSTRIAL},
	{5, 478, 350000, 1, DEALERSHIP_INDUSTRIAL},
	{6, 406, 3000000, 3, DEALERSHIP_INDUSTRIAL},
	{7, 409, 3000000, 3, DEALERSHIP_INDUSTRIAL},
	
	{0, 412, 1000000, 1, DEALERSHIP_LOWRIDER},
	{1, 534, 1000000, 1, DEALERSHIP_LOWRIDER},
	{2, 535, 1000000, 1, DEALERSHIP_LOWRIDER},
	{3, 536, 1000000, 1, DEALERSHIP_LOWRIDER},
	{4, 566, 1000000, 1, DEALERSHIP_LOWRIDER},
	{5, 567, 1000000, 1, DEALERSHIP_LOWRIDER},
	{6, 576, 1000000, 1, DEALERSHIP_LOWRIDER},
	{7, 575, 1000000, 1, DEALERSHIP_LOWRIDER},

	{0, 489, 750000, 1, DEALERSHIP_OFFROAD},
	{1, 495, 750000, 1, DEALERSHIP_OFFROAD},
	{2, 579, 750000, 1, DEALERSHIP_OFFROAD},
	{3, 400, 750000, 1, DEALERSHIP_OFFROAD},
	{4, 424, 1500000, 1, DEALERSHIP_OFFROAD},
	
	{0, 469, 6000000, 5, DEALERSHIP_AIR},
	{1, 487, 6000000, 5, DEALERSHIP_AIR},
	{2, 513, 6000000, 5, DEALERSHIP_AIR},
	
	{0, 479, 850000, 1, DEALERSHIP_STATIONWAGONS},
	{1, 561, 1000000, 1, DEALERSHIP_STATIONWAGONS},

	{0, 555, 750000, 1, DEALERSHIP_CONVERTIBLES},
	{1, 533, 750000, 1, DEALERSHIP_CONVERTIBLES},
	{2, 480, 1500000, 2, DEALERSHIP_CONVERTIBLES}
};

forward showDealershipDialogTypes(playerid);
public showDealershipDialogTypes(playerid)
{	
	ShowPlayerDialog(playerid, 699, DIALOG_STYLE_LIST, "Vehicle Dealership - Categories", "Sports vehicles\nSaloons\nBikes\nUnique vehicles \nIndustrial \nLowriders \nOff Road \nAir Vehicles \nStation Wagons \nConvertibles", "OK", "Close");
}

forward showDealershipDialogCategory(playerid, category_type);
public showDealershipDialogCategory(playerid, category_type)
{
	
	new dialog_category_list[800];
	category_choice[playerid] = category_type;
	
	for(new i = 0; i < sizeof(dealershipData); i++)
	{
		if(dealershipData[i][vehicle_type] == category_type)
		{
			if (dealershipData[i][vehicle_price] == 0) // No price, token only
			{
				format(dialog_category_list, sizeof(dialog_category_list), "%s\n%s {FACC2E}%i Token(s){FFFFFF}", dialog_category_list, vehicleNames[dealershipData[i][vehicle_model] - 400], dealershipData[i][token_price]);			
			}
			else
			{
				format(dialog_category_list, sizeof(dialog_category_list), "%s\n%s {D87C3E}$%s {FFFFFF}/ {FACC2E}%i Token(s){FFFFFF}", dialog_category_list, vehicleNames[dealershipData[i][vehicle_model] - 400], FormatNumber(dealershipData[i][vehicle_price]), dealershipData[i][token_price]);
			}
		}
	}
	
	ShowPlayerDialog(playerid, 701, DIALOG_STYLE_LIST, "Wang Cars - Dealership", dialog_category_list, "OK", "Close");	
}
