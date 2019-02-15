


function USBinit()
	local myNumber = nextNumber;
	nextNumber = nextNumber + 1;
	
	mapping["usb"] = {[0] = myNumber, [1] = 0};
	mapping["Linux usb"] = {[0] = myNumber, [1] = 0};
	mapping["Mint usb"] = {[0] = myNumber, [1] = 0};
	mapping["USB"] = {[0] = myNumber, [1] = 0};
	mapping["Mint USB"] = {[0] = myNumber, [1] = 0};
	mapping["Linux Mint usb"] = {[0] = myNumber, [1] = 0};
	mapping["Linux Mint USB"] = {[0] = myNumber, [1] = 0};

	items[myNumber] = {[0] = "hacker usb", [1] = -1, [2] = 0, [3] = "a", [4] = useUSB};


end


function useUSB(arg)
	local mynum = mapping["usb"][0];
	local myStuff = items[mynum];


	if (arg == 0) then
		print ("  "..myStuff[3].." "..myStuff[0]);
	end

	-- Get
	if ((arg == 12)and(myStuff[1]==location))  then
		print ("You acquire "..myStuff[3].." "..myStuff[0]..".");
		myStuff[1] = 0;
	end

	-- Drop
	if ((arg == 13)and(myStuff[1]==0))  then
		print (myStuff[0].." dropped.");
		myStuff[1] = location;
	end

	if ((arg == 17)and(myStuff[1]==0)) then
		print("You will need an appropriate place to use this.  One hasn't");
		print("been invented yet.");
	end
		

end


