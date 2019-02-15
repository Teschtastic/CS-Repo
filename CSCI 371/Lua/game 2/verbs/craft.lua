

function handleCraft(a, b)
   local object = mapping[a]
   local person = mapping[b]
   local whom
   local what
   
   if ((object == nil) and (person == nil)) then
       print("Nothing to craft")
       return 0
    end
   
    if (person ~= nil) then whom = people[person[0]] end
    if (object ~= nil) then what = items[object[0]] end
    
    if (what[1] == location) then
        what[4](35)
        return 0
    end
end