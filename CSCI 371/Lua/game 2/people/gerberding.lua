


function Gerberdinginit()
	local myNumber = nextNumber;
	nextNumber = nextNumber + 1;
	
	mapping["Gerberding"] = {[0] = myNumber, [1] = 1};
	mapping["gerberding"] = {[0] = myNumber, [1] = 1};
	mapping["Mr. Gerberding"] = {[0] = myNumber, [1] = 1};
	mapping["James Gerberding"] = {[0] = myNumber, [1] = 1};
	mapping["James"] = {[0] = myNumber, [1] = 1};
	mapping["james"] = {[0] = myNumber, [1] = 1};

	people[myNumber] = {[0] = "Mr. Gerberding", [1] = 3, [2] = 0, [3] = talkGerberding};


end


function talkGerberding(arg)
	local mynum = mapping["Gerberding"][0];
	local myStuff = people[mynum];


	if (arg == 0) then
		print (myStuff[0] .. " is standing here.");
		if (myStuff[2] == 0) then
			print ("  He is waving a large piece of paper");
		end
	end


	if (arg == 10) then
		print (myStuff[0] .. " offers to sell you a map for your adventure!");
		print ("He will sell it for 40");
	end

	if (arg == 11) then
		if (funds >= 40) then
			if (myStuff[2] == 0) then
				myStuff[2] = 1;
			 	items[mapping["map"][0]][1] = 0;
				print("You bought a map.");
				funds = funds - 40;
				myStuff[1] = -1;
				return
			end
			print ("Mr. Gerberding has no more maps for sale!");
			return;
		end
		print("You don't have enough money, it costs 40.");
	end
		


end


