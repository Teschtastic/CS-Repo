


function Minakerinit()
	local myNumber = nextNumber;
	nextNumber = nextNumber + 1;
	
	mapping["Minaker"] = {[0] = myNumber, [1] = 1};
	mapping["minaker"] = {[0] = myNumber, [1] = 1};
	mapping["Mr. Minaker"] = {[0] = myNumber, [1] = 1};
	mapping["Eric Minaker"] = {[0] = myNumber, [1] = 1};
	mapping["Eric"] = {[0] = myNumber, [1] = 1};
	mapping["eric"] = {[0] = myNumber, [1] = 1};

	people[myNumber] = {[0] = "Eric Minaker", [1] = 9, [2] = 0, [3] = talkMinaker};


end


function talkMinaker(arg)
	local mynum = mapping["Minaker"][0];
	local myStuff = people[mynum];


	if (arg == 0) then
		print (myStuff[0] .. " is standing here.");
	end


	if (arg == 10) then
		print (myStuff[0] .. " tells you he is collecting funds to help the ");
		print ("army expand.  Monetary donations Accepted (use give).");
		return;
	end

	if (arg == 33) then
		print (myStuff[0] .. " thanks you!  The money will be well spent");
		print ("upgrading his armed forces.");
		funds = 0;
		karma = karma + 1;
		return;
	end

	if (arg == 25) then
		print (myStuff[0] .. " summons the combined military forces of Canada ");
		print ("and Cuba.  They quickly overcome your feeble attack, and shortly ");
		print ("thereafter, dispose of you.");
		endgame();
	end


end


