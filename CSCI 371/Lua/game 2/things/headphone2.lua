

function Piece2Init()
    local myNumber = nextNumber;
    nextNumber = nextNumber + 1;

    mapping["piece 2"] = {[0] = myNumber, [1] = 0};

    items[myNumber] = {[0] = "piece 2", [1] = 8, [2] = 0, [3] = "", [4] = usePiece2};
end

function usePiece2(arg)
    local myNum = mapping["piece 2"][0];
    local myStuff = items[myNum];
    
    if (arg == 0) then
        print(" "..myStuff[3].." "..myStuff[0]);
    end
    
    if ((arg == 12) and (myStuff[1] == location))  then
        print ("You acquire "..myStuff[3].." "..myStuff[0]..".");
        myStuff[1] = 0;
    end
    
    if ((location == 4) and (arg == 33)) then
        print ("You give "..myStuff[3].." "..myStuff[0].." to Dr. Smith.\n");
        myStuff[1]=-1;
    end
    
    if ((arg == 13)and(myStuff[1]==0))  then
        print (myStuff[0].." dropped.");
        myStuff[1] = location;
    end
end