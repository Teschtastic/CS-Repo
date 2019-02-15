-- Sean Tesch   3/29/16  CSCI 371
-- Assignment 5 Stats

-- Initializes variables for filenames and tables
file = 'people.data'
file2 = 'adventure.data'

i = 1

-- Reads in the contents of the first file and assigns
-- each item in a line to a variable
for line in io.lines(file) do
    name, stat, value = string.match(line, "(.*) (.*) (.*)")
    -- Opens second file and reads in the data
    for line1 in io.lines(file2) do
        name2, stat2 = string.match(line1, "(.*) (.*)")
        -- Prints the requested data       
        if (name2 == name and stat2 == stat) then
            print('------------------------------')
            print('Line[' .. i .. ']: ' .. name2 .. " " .. stat2 .. " " .. value)
            print('------------------------------')
            i = i + 1
        if not stat2 == stat then
            print('------------------------------')
            print('Line[' .. i .. ']: ' .. name2 .. " " .. stat2 .. " " .. 0)
            print('------------------------------')
            i = i + 1
            end
        end
    end
end

