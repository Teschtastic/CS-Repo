

function handleDrop(a, b)
	local object = mapping[a];
	local person = mapping[b];
	local whom;
	local what;

	if ((object == nil)and(person == nil)) then	
		print ("You need to do that to someone/something!");
		return 0;
	end;
		
  if (person ~= nil) then whom = people[person[0]]; end;
  if (object ~= nil) then what = items[object[0]]; end;


  -- Handling DROP
  if (what ~= nul) then -- Dropping an item
    if (what[1] == 0) then
      what[4](13);
      return 0;
    end;
    print ("You aren't carrying "..a..".");
    return 0;
  end;
  if (whom ~= nil) then -- Dropping a person
    if (whom[1] == 0) then
      whom[3](13);
      return 0
    end;
    print (b .. " isn't with you.");
    return 0
  end

end
