function candyInit()
    local myNumber = nextNumber
    nextNumber = nextNumber + 1
    
    mapping["candy"] = {[0] = myNumber, [1] = 0}
    mapping["Candy"] = {[0] = myNumber, [1] = 0}
    
    items[myNumber] = {[0] = "candy", [1] = -1, [2] = 0, [3] = "a peice of ", [4] = buyCandy}
end
    
function buyCandy(arg)
    local myNum = mapping["candy"][0]
    local myStuff = items[myNum]

    if (arg == 0) then
        print (" "..myStuff[3].." "..myStuff[0])
    end
end