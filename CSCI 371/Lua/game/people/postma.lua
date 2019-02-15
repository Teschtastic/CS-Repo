


function Postmainit()
	local myNumber = nextNumber;
	nextNumber = nextNumber + 1;
	
	mapping["Postma"] = {[0] = myNumber, [1] = 1};
	mapping["postma"] = {[0] = myNumber, [1] = 1};
	mapping["Mr. Postma"] = {[0] = myNumber, [1] = 1};
	mapping["Tyler Postma"] = {[0] = myNumber, [1] = 1};
	mapping["Tyler"] = {[0] = myNumber, [1] = 1};
	mapping["tyler"] = {[0] = myNumber, [1] = 1};

	people[myNumber] = {[0] = "Tyler Postma", [1] = 20, [2] = 0, [3] = talkPostma};


end


function talkPostma(arg)
	local mynum = mapping["Postma"][0];
	local myStuff = people[mynum];


	if (arg == 0) then
		print (myStuff[0] .. " is standing here.");
	end


	if (arg == 10) then
		if (myStuff[2] == 0) then 
			print (myStuff[0] .. " says Hello!  I was on my way to hack the Yakuza");
			print ("headquarters with this Linux Mint USB that I got from Linus Torvalds,.");
			print ("but, I got sidetracked at this Sushi Bar.  Have you tried the Okonomiyaki?")
			print ("It's really good.  I wish I had more money to buy more.");
			return;
		end
		if (myStuff[2] == 1) then
			print (myStuff[0] .. " is busy eating.  To get his attention now, you");
			print ("would need to become an automated file structure, or AF.");
			return;
		end
	end

	if (arg == 25) then
		print ("Several Ninjas appear and remove you from the premisis.");
		print ("You have been banned from the room.");
		banned = 1;
		location = 18;
		return;
	end

	if (arg == 11) then
    if (funds >= 30) then
      if (myStuff[2] == 0) then
        myStuff[2] = 1;
        items[mapping["usb"][0]][1] = 0;
        print("You bought a Hacker USB key.");
        funds = funds - 30;
        return
      end
      print (myStuff[0] .. " ignores you.");
      return;
    end
    print("You don't have enough money, it costs 30.");
  end
	


end


