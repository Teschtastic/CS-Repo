
function room30()
    location = 30
    print ("-----------------------------------------------------------")
    print ("You are behind Pet's Plus")
    list()
    show(location)
    local move = parse()
    if (move == 0) then return location; end
    
    -- North
    if (move == 1) then
        print("You can't move that way!")
        return location;
    end
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
        return 28;
    end
    print ("I don't understand your actions!")
    return location
    

end
