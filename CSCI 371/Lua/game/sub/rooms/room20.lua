
function room20()
	location = 20
	print ("-----------------------------------------------------------")
	print ("You are in Sushi Resturant")
	list()
	show(location)
	local move = parse()
	if (move == 0) then return location; end

	-- North
	if (move == 1) then return 18; end
	-- East
	if (move == 2) then
		print("You can't move that way!")
		return location;
	end
	-- South
	if (move == 3) then
		print("You can't move that way!")
		return location;
	end
	-- West
	if (move == 4) then
		print("You can't move that way!")
		return location;
	end
	print ("I don't understand your actions!")
	return location



end
