


function smithInit()
    local myNumber = nextNumber;
    nextNumber = nextNumber + 1;

    mapping["smith"] = {[0] = myNumber, [1] = 1};
    mapping["Smith"] = {[0] = myNumber, [1] = 1};
    mapping["Doctor Smith"] = {[0] = myNumber, [1] = 1};
    mapping["doctor smith"] = {[0] = myNumber, [1] = 1};
    mapping["Professor Smith"] = {[0] = myNumber, [1] = 1};
    mapping["professor smith"] = {[0] = myNumber, [1] = 1};

    people[myNumber] = {[0] = "Dr. Smith", [1] = 4, [2] = 0, [3] = talkSmith}
end

function talkSmith(arg)
    local myNum = mapping["Smith"][0]
    local myStuff = people[myNum]

    if (arg == 0) then
        print(myStuff[0].." is siiting at his desk")
    end
    
    if (arg == 10) then
       print(myStuff[0].." says he has a quest for you.")
       print("He explains there are three peices of something around town.")
       print("He also says if you find them all to bring them to him")
       print("(He might be able to help you on your quest for candy)")
    end
    
    if (arg == 35) then
        if (myStuff[2] == 0)then
            myStuff[2] = 1
            items[mapping["piece 1"][0]][1] = 0
            items[mapping["piece 2"][0]][1] = 0
            items[mapping["piece 3"][0]][1] = 0
            items[mapping["headphones"][0]][1] = 1
            print("crafted headphones")
            return
        end
        print ("you don't have all the pieces")
        print ("Keep looking.")
    end
end