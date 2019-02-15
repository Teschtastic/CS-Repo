
function room12()
	location = 12
	print ("-----------------------------------------------------------")
	print ("You are in Southeast SSM")
	list()
	show(location)
	local move = parse()
	if (move == 0) then return location; end

	-- North
	if (move == 1) then return 9; end
	-- East
	if (move == 2) then return 23; end
	-- South
	if (move == 3) then
		print("You can't move that way!")
		return location;
	end
	-- West
	if (move == 4) then return 11; end
	print ("I don't understand your actions!")
	return location



end
