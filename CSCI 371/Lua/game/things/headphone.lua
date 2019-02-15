

function headphoneInit()
    local myNumber = nextNumber
    nextNumber = nextNumber + 1
    
    mapping["headphones"] = {[0] = myNumber, [1] = 0}
    
    items[myNumber] = {[0] = "headphones", [1] = -1, [2] = 0, [3] = "a pair of", [4] = useHeadphone};
end

function useHeadphone(arg)
    local myNum = mapping["headphones"][0]
    local myStuff = items[myNum]
    
    if (arg == 0) then
        print(" "..myStuff[3].." "..myStuff[0])
    end
    
    if ((arg == 12)and(myStuff[1]==location))  then
        print ("You acquire "..myStuff[3].." "..myStuff[0]..".");
        myStuff[1] = 0;
    end
    
    if ((arg == 13)and(myStuff[1]==0))  then
        print (myStuff[0].." dropped.");
        myStuff[1] = location;
    end
end