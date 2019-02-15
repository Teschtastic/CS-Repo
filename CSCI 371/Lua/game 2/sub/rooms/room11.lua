
function room11()
	location = 11
	print ("-----------------------------------------------------------")
	print ("You are in Southwest SSM")
	list()
	show(location)
	local move = parse()
	if (move == 0) then return location; end

	-- North
	if (move == 1) then return 9; end
	-- East
	if (move == 2) then return 12; end
	-- South
	if (move == 3) then return 13; end
	-- West
	if (move == 4) then return 25; end
	print ("I don't understand your actions!")
	return location



end
