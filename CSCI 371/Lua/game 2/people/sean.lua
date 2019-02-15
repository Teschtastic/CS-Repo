


function Seaninit()
	local myNumber = nextNumber;
	nextNumber = nextNumber + 1;
	
	mapping["Sean"] = {[0] = myNumber, [1] = 1};
	mapping["sean"] = {[0] = myNumber, [1] = 1};
	mapping["gallagher"] = {[0] = myNumber, [1] = 1};
	mapping["Gallagher"] = {[0] = myNumber, [1] = 1};
	mapping["Mr. Gallagher"] = {[0] = myNumber, [1] = 1};
  mapping["Sean Gallagher"] = {[0] = myNumber, [1] = 1};

	people[myNumber] = {[0] = "Sean Gallagher", [1] = 2, [2] = 0, [3] = talkSean, [4] = tickSean};


end


function talkSean(arg)
	local mynum = mapping["Sean"][0];
	local myStuff = people[mynum];


	if (arg == 0) then
		print (myStuff[0] .. " is standing here.");
	end


	if (arg == 10) then
		print (myStuff[0] .. " says, 'Leave me alone, I'm not part of this game!'");
	end


end


function tickSean()
	if ((tickCount % 10) == 0) then
		local where = math.random(5);
		if (where == 1) then
			people[mapping["Sean"][0]][1] = 2;
			end
		if (where == 2) then
			people[mapping["Sean"][0]][1] = 3;
			end
		if (where == 3) then
			people[mapping["Sean"][0]][1] = 13;
			end
		if (where == 4) then
			people[mapping["Sean"][0]][1] = 26;
			end
		if (where == 5) then
			people[mapping["Sean"][0]][1] = 1;
			end
	end
end
