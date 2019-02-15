


function AtmCardinit()
	local myNumber = nextNumber;
	nextNumber = nextNumber + 1;
	
	mapping["card"] = {[0] = myNumber, [1] = 0};
	mapping["Card"] = {[0] = myNumber, [1] = 0};
	mapping["atmcard"] = {[0] = myNumber, [1] = 0};
	mapping["ATM Card"] = {[0] = myNumber, [1] = 0};

	items[myNumber] = {[0] = "ATMCard", [1] = 16, [2] = 0, [3] = "an", [4] = useAtmCard};


end


function useAtmCard(arg)
	local mynum = mapping["atmcard"][0];
	local myStuff = items[mynum];


	if (arg == 0) then
		print ("  "..myStuff[3].." "..myStuff[0]);
	end

	if ((arg == 12)and(myStuff[1]==location))  then
		print ("You acquire "..myStuff[3].." "..myStuff[0]..".");
		myStuff[1] = 0;
	end

	if ((arg == 13)and(myStuff[1]==0))  then
		print (myStuff[0].." dropped.");
		myStuff[1] = location;
	end

		

end


