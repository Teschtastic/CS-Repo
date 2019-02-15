
function room10()
	location = 10
	print ("-----------------------------------------------------------")
	print ("You are in Northeast SSM")
	list()
	show(location)
	local move = parse()
	if (move == 0) then return location; end

	-- North
	if (move == 1) then return 15; end
	-- East
	if (move == 2) then return 14; end
	-- South
	if (move == 3) then return 12; end
	-- West
	if (move == 4) then return 9; end
	print ("I don't understand your actions!")
	return location



end
