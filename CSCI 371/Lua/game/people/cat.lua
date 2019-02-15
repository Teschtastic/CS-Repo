


function Catinit()
	local myNumber = nextNumber;
	nextNumber = nextNumber + 1;
	
	mapping["cat"] = {[0] = myNumber, [1] = 1};
	mapping["kyler's cat"] = {[0] = myNumber, [1] = 1};
	mapping["Kyler's cat"] = {[0] = myNumber, [1] = 1};

	people[myNumber] = {[0] = "Kyler's cat", [1] = 16, [2] = 0, [3] = talkCat, [4] = tickCat};


end


function talkCat(arg)
	local mynum = mapping["cat"][0];
	local myStuff = people[mynum];


	if (arg == 0) then
		print (myStuff[0] .. " is curled up in a corner.  It appears to be sleeping.");
	end


	if (arg == 10) then
		print (myStuff[0] .. " ignores you.");
	end

    if (arg == 33) then
        if (myStuff[2] == 0) then
            myStuff[2] = 1
            items[mapping["catnip"][0]][1] = 0
            print ("You gave "..myStuff[0].." catnip")
            print (myStuff[0].." ran off in a drug enduced craze!")
            myStuff[1] = -1
            return
        end
    end


end


function tickCat()
	if ((tickCount % 5) == 0) then
		if (location == people[mapping["cat"][0]][1]) then
			print ("Meow!");
		end
	end
end
