
function room27()
	location = 27
	print ("-----------------------------------------------------------")
	print ("You are in SSM Airport Terminal")
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
	if (move == 2) then
		print("You can't move that way!")
		return location;
	end
	-- South
	if (move == 3) then return 17; end
	-- West
	if (move == 4) then return 18; end
	print ("I don't understand your actions!")
	return location



end
