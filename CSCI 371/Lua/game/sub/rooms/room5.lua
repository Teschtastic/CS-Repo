
function room5()
	location = 5
	print ("-----------------------------------------------------------")
	print ("You are in LSSU Parking Lot")
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
	if (move == 2) then return 2; end
	-- South
	if (move == 3) then return 7; end
	-- West
	if (move == 4) then return 6; end
	print ("I don't understand your actions!")
	return location



end
