function catnipinit()
    local myNumber = nextNumber;
    nextNumber = nextNumber + 1;

    mapping["catnip"] = {[0] = myNumber, [1] = 0};
    mapping["Catnip"] = {[0] = myNumber, [1] = 0};

    items[myNumber] = {[0] = "catnip", [1] = 30, [2] = 0, [3] = "the ", [4] = useCatnip};
end

function useCatnip(arg)
    local mynum = mapping["catnip"][0];
    local myStuff = items[mynum];

    if (arg == 0) then
        print (" "..myStuff[3].." "..myStuff[0]);
    end

    -- Get
    if ((arg == 12)and(myStuff[1]==location))  then
        print ("You acquire "..myStuff[3].." "..myStuff[0]..".");
        myStuff[1] = 0;
    end
    
    if ((location == 16) and (arg == 33)) then
        print ("You give "..myStuff[3].." "..myStuff[0].." to Kyler's cat.\n")
        myStuff[1]=-1
    end

    -- Drop
    if ((arg == 13)and(myStuff[1]==0))  then
        print (myStuff[0].." dropped.");
        myStuff[1] = location;
    end
end