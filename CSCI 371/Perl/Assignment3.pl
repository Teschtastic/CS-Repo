#!/usr/bin/perl

#   Sean Tesch  02/23/16
#   CSCI371     Assignment 3
#   Create the perfect class
#   in the perl language

open MALE, "boynames";
open FEMALE, "girlnames";
open LAST, "lastnames";

#initialize the first, last, and initials arrays
@initials = ('A' .. 'Z');
@firstLetters;
@lastLetters;

# reads boy names from a file and then, writes them into a new array
while (<MALE>)
{
    chomp;
    $boy = $_;
    #splits the names by whitespace and puts them in new lines
    my @boys = split /\s+/, $boy;
    $firstLetters = substr($boy, 0, 1);
    # if the first letter is the same a
    if ($boyHolder =~ m/$firstLetters/)
    {
    }
    else
    {
        chomp;
        push (@boynames , $boy);
        $boyHolder .= $firstLetters;
    }
}

#same as boy names
while (<FEMALE>)
{
    chomp;
    $girl = $_;
    my @girls = split /\s+/, $girl;
    $firstLetters = substr($girl, 0, 1);
    if ($girlHolder =~ m/$firstLetters/)
    {
    }
    else
    {
        chomp;
        push (@girlnames, $girl);
        $girlHolder .= $firstLetters;
    }
}

#same as boy names
while (<LAST>)
{
    chomp;
    $last = $_;
    my @lasts = split /\s+/, $last;
    $lastLetters = substr($last, 0, 1);
    if ($lastHolder =~ m/$lastLetters/)
    {
    }
    else
    {
        chomp;
        push (@lastnames, $last);
        $lastHolder .= $lastLetters;
    }
}

open(my $file, '>', "PerfectClass");
foreach $number ((1 .. 20))
{
    #gives 10 girl and boy names and puts them into a new array
    if ($number <= 10)
    {
        $first = @girlnames[int (rand $#girlnames + 1)];
    }
    else
    {
        $first = @boynames[int (rand $#boynames + 1)];
    }
    
    #gets random initial and last names and puts them in a new array
    $middles = @initials[int(rand 26)];
    $lastss = @lastnames[int (rand $#lastnames + 1)];
    
    #creats a bunch of random doubles in the range of 3.20 and 4.00, formats them,
    #then put them in an array
    my $range = 0.80;
    my $min = 3.20;
    my $random_number = rand($range) + $min;
    my $rounded = sprintf("%.2f", $random_number);
    @gpa = $rounded;
    $gpas = @gpa[int (rand)];
    
    #creats a variable that is made up of all the elemants
    @fullClass = $first . " " . $middles . ". " . $lastss . " " . $gpas;
    
    #creates and writes to a file called 'PerfectClass'
    print $file "@fullClass\n ";
    #print $fullClass . "\n";
}
close $file;
