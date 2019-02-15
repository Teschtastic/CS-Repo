


function Mapinit()
	local myNumber = nextNumber;
	nextNumber = nextNumber + 1;
	
	mapping["map"] = {[0] = myNumber, [1] = 0};

	items[myNumber] = {[0] = "map", [1] = -1, [2] = 0, [3] = "a", [4] = useMap};


end


function useMap(arg)
	local mynum = mapping["map"][0];
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

	if ((arg == 17)and(myStuff[1]==0)) then
		print("The map turns out to be for last years game.");
	end
		

end


