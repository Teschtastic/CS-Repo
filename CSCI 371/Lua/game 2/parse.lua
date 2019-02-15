
function parse()
	local str = io.read()

	lastVerb = nil;			-- Make sure that old verbs don't survive

	if str == "north" then return 1 end
	if str == "east" then return 2 end
	if str == "south" then return 3 end
	if str == "west" then return 4 end

	if str == "northwest" then return 5 end
	if str == "northeast" then return 6 end
	if str == "southwest" then return 7 end
	if str == "southeast" then return 8 end

	if str == "go north" then return 1 end
	if str == "go east" then return 2 end
	if str == "go south" then return 3 end
	if str == "go west" then return 4 end

	if str == "go northwest" then return 5 end
	if str == "go northeast" then return 6 end
	if str == "go southwest" then return 7 end
	if str == "go southeast" then return 8 end

	if str == "n" then return 1 end
	if str == "e" then return 2 end
	if str == "s" then return 3 end
	if str == "w" then return 4 end

	if str == "nw" then return 5 end
	if str == "ne" then return 6 end
	if str == "sw" then return 7 end
	if str == "se" then return 8 end

	local verb, object, person = superparser(str);

	local num, special = parseVerb(verb);


--	local verb, object = string.match(str, "^([%a]+) (.*)$");
--	if (verb == nil) then
--		verb = str;
--	end

-- Add blocks here to handle certain types of verbs with certain 
-- combinations of people and items
	if (num == 10) then return handleTalk(object, person) end;
	if (num == 11) then return handleBuy(object, person) end;
	if (num == 12) then return handleGet(object, person) end;
	if (num == 13) then return handleDrop(object, person) end;
	if (num == 14) then return handleUse(object, person) end;
	if (num == 17) then return handleLook(object, person) end;
	if (num == 18) then return handleInventory(nil, nil) end;
	if (num == 25) then return handleAttack(object, person) end;
    if (num == 33) then return handleGive(object, person) end;
    if (num == 35) then return handleCraft(object, person) end

	if (num == 99) then endgame() end;

	if (num == 100) then 	-- Handle non-standard verbs in the room functions
		lastVerb = special;
		return 100;
		end;

	print "Command not understood"
return -1
end


-- Function endgame 
-- Handle the end of the game
function endgame()
	print "Game Over"
	os.exit()
end

