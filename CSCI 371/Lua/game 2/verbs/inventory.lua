

function handleInventory(a, n)
  print ("You are carrying:")
  for name, value in pairs(items) do
    if (value[1] == 0) then
      print (value[0])
    end
  end
  print ("You have " .. funds .. ".")
    return 0
end
