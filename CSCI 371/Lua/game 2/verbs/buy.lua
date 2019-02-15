

function handleBuy(a, b)
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


    if (whom == nil) then return 0 end;
    if (what == nil) then return 0 end;

    if ((person[0] == mapping["Gerberding"][0])and
        (object[0] == mapping["map"][0])) then
        whom[3](11);
        return 0;
    end

    if ((person[0] == mapping["Postma"][0])and
        (object[0] == mapping["usb"][0])) then
        whom[3](11);
        return 0;
    end
    
    if ((person[0] == mapping["Kyler"][0]) and
        (object[0] == mapping["candy"][0])) then
        whom[3](11)
        return 0
    end
end
