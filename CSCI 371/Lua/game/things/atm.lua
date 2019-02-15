


function Atminit()
	local myNumber = nextNumber;
	nextNumber = nextNumber + 1;
	
	mapping["atm"] = {[0] = myNumber, [1] = 0};
	mapping["ATM"] = {[0] = myNumber, [1] = 0};
	mapping["ATM machine"] = {[0] = myNumber, [1] = 0};
	mapping["atm machine"] = {[0] = myNumber, [1] = 0};

	items[myNumber] = {[0] = "ATM", [1] = 6, [2] = 0, [3] = "an", [4] = useAtm};


end


function useAtm(arg)
	local mynum = mapping["atm"][0];
	local myStuff = items[mynum];


	if (arg == 0) then
		print ("  "..myStuff[3].." "..myStuff[0]);
	end

	if ((arg == 12))  then
		print("The " .. myStuff[0] .. " is too heavy.");
		return 0;
	end

	if (arg == 13)  then
		print ("You were not carrying the " .. myStuff[0]);
		return 0;
	end

	if ((arg == 14)and(  ((bit32.band(myStuff[2],0x01)) == 0) )) then
		print("You remove your last 10 from your account.");
		funds = funds + 10;
		myStuff[2] = bit32.bor(myStuff[2], 0x01);
		return 0;
	end


	if ((arg == 14)and(  ((bit32.band(myStuff[2],0x02)) == 0) and
					(items[mapping["atmcard"][0]][1] == 0)       )) then
		print("You withdrawl 90 from some poor suckers account.");
		funds = funds + 90;
		myStuff[2] = bit32.bor(myStuff[2], 0x02);
		return 0;
	end


		

end


