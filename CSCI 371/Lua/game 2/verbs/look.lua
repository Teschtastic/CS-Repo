

function handleLook(a, b)
	local object = mapping[a];
	local person = mapping[b];
	local whom;
	local what;

	if ((object == nil)and(person == nil)) then	
		print ("You need to do that to someone/something!");
		return 0;
	end;
		
  if (person ~= nil) then whom = people[person[0]]; end;
  if (object ~= nil) then  what = items[object[0]]; end;

	if (what ~= nil) then
		what[4](17);
		return 0;
	end;

	if (whom ~= nil) then
		whom[3](17);
		return 0;
	end;

end
