
function room23()
	location = 23
	print ("-----------------------------------------------------------")
	print ("You are in SSM Lakeshore Area")
	list()
	show(location)
	local move = parse()
	if (move == 0) then return location; end

	-- North
	if (move == 1) then return 24; end
	-- East
	if (move == 2) then return 16; end
	-- South
	if (move == 3) then return 25; end
	-- West
	if (move == 4) then return 11; end
	print ("I don't understand your actions!")
	return location



end
