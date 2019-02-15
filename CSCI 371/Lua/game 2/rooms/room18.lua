
function room18()
	location = 18
	print ("-----------------------------------------------------------")
	print ("You are in Japan Airport Terminal")
	list()
	show(location)
	local move = parse()
	if (move == 0) then return location; end

	-- North
	if (move == 1) then return 19; end
	-- East
	if (move == 2) then return 27; end
	-- South
	if (move == 3) then return 20; end
	-- West
	if (move == 4) then
		print("You can't move that way!")
		return location;
	end
	print ("I don't understand your actions!")
	return location



end
