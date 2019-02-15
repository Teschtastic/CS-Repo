


function Kylerinit()
	local myNumber = nextNumber;
	nextNumber = nextNumber + 1;
	
	mapping["Kyler"] = {[0] = myNumber, [1] = 1};
	mapping["kyler"] = {[0] = myNumber, [1] = 1};
	mapping["orange kyler"] = {[0] = myNumber, [1] = 1};
	mapping["silly orange kyler"] = {[0] = myNumber, [1] = 1};
	mapping["very silly orange kyler"] = {[0] = myNumber, [1] = 1};

	people[myNumber] = {[0] = "Kyler", [1] = 1, [2] = 0, [3] = talkKyler};


end


function talkKyler(arg)
	local mynum = mapping["Kyler"][0];
	local myStuff = people[mynum];


	if (arg == 0) then
		print (myStuff[0] .. " is standing here.");
		if (myStuff[2] == 0) then
			print ("He has candy!");
		end
	end

	if (arg == 10) then
		print (myStuff[0] .. " says Hello!");
    end
    
    if (arg == 11) then
        if (funds == 150) then
            if(myStuff[2] == 0)then
                myStuff[2] = 1
                items[mapping["candy"][0]][1] = 0
                print ("You buy one piece of candy from "..myStuff[0])
                print ("You win!")
                funds = funds - 150
                endgame()
                return
            end
            print ("Kyler has no more candy")
        end
        print ("You don't have enough money. It costs 150")
    end


end


function tickKyler()
	

end
