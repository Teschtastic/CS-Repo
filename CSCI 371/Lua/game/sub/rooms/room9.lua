
function room9()
	location = 9
	print ("-----------------------------------------------------------")
	print ("You are in Northwest SSM")
	list()
	show(location)
	local move = parse()
	if (move == 0) then return location; end

	-- North
	if (move == 1) then return 7; end
	-- East
	if (move == 2) then return 10; end
	-- South
	if (move == 3) then return 11; end
	-- West
	if (move == 4) then return 17; end
	print ("I don't understand your actions!")
	return location



end
