
function room25()
	location = 25
	print ("-----------------------------------------------------------")
	print ("You are in Road to Brimley")
	list()
	show(location)
	local move = parse()
	if (move == 0) then return location; end

	-- North
	if (move == 1) then
		print("You can't move that way!")
		return location;
	end
	-- East
	if (move == 2) then return 11; end
	-- South
	if (move == 3) then
		print("You can't move that way!")
		return location;
	end
	-- West
	if (move == 4) then return 26; end
	print ("I don't understand your actions!")
	return location



end