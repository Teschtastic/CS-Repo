verbs ={
    ["talk"] = 10, ["hello"] = 10,
    ["buy"] = 11,
    ["get"] = 12, ["acquire"] = 12, ["take"] = 12, ["pickup"] = 12,
    ["drop"] = 13, ["put"] = 13, ["throw"] = 13, ["toss"] = 13,
    ["use"] = 14,
    ["eat"] = 15,
    ["quit"] = 16,
    ["look"] = 17, ["examine"] = 17,
    ["i"] = 18, ["inventory"] = 18,
    ["smell"] = 20,
    ["taste"] = 21,
    ["touch"] = 22, ["feel"] = 22,
    ["lick"] = 23,
    ["wave"] = 24,
    ["hit"] = 25, ["kill"] = 25, ["destroy"] = 25, ["attack"] = 25,
    ["kick"] = 25, ["punch"] = 25,
    ["turn"] = 26,
    ["sell"] = 27,
    ["open"] = 28,
    ["close"] = 29,
    ["push"] = 30,
    ["pull"] = 31,
    ["move"] = 32,
    ["give"] = 33,
    ["read"] = 34,
    ["craft"] = 35, ["make"] = 35, ["create"] = 35,
    ["plugh"] = 90,
    ["xyzzy"] = 91,
    ["quit"] = 99, ["end"] = 99, ["exit"] = 99
};


function parseVerb(str)
	if (str == nil) then return 0, nil end;
	if (verbs[str] ~= nil) then 
		return verbs[str], str;
	end;
	return 100, str;
end;
