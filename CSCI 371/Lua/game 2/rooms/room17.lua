
function room17()
	location = 17
	print ("-----------------------------------------------------------")
	print ("You are in SSM Airport Area")
	list()
	show(location)
	local move = parse()
	if (move == 0) then return location; end

	-- North
	if (move == 1) then return 27; end
	-- East
	if (move == 2) then return 9; end
	-- South
	if (move == 3) then return 28; end
	-- West
	if (move == 4) then return 29; end
	print ("I don't understand your actions!")
	return location



end
