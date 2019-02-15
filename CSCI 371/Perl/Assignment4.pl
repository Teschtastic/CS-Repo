#!/usr/bin/Perl

# Sean Tesch
# 03/17/16
# CSCI 371
# Use Perl to be able to take a string from a file
# and use ROT 1-25 rules to decode the string

# Take an input from the command line as the name for the file
open SECRET, $ARGV[0];

# Creates a subroutine that uses ROT 13 as a base
# and searches for the letters and replaces them
sub decode
{
    return shift =~ tr/A-Za-z/B-ZAb-za/r;
}

# Sets the encoded message to the string in the secret file
while (<SECRET>)
{
	chomp;
	$encoded .= $_ . "\n";
    print $encoded;
}

# Closes the file, it's no longer needed
close $secret;

# Sets the decoded message to the value
# of the encoded message
my $decoded = $encoded;

# Creates a variable used to detect if the
# message was decoded or not
my $found;

# Loops through each typ of ROT until the
# phrase is decoded using the word 'the'
my $count = 1;
for (1 .. 25)
{
    # Sets the value of $decoded to the
    # decode subroutine of $decoded
    $decoded = decode($decoded);
    
    # If the value of decoded contains the word 'the',
    # Print the decoded message, then gives $found
    # a value used for the unless statement
    if ($decoded =~ /\bthe\b/)
    {
        print ($decoded);
        print ("ROT: ");
        print ($count);
        print ("\n");
        $found = 1;
    }
    $count = $count + 1;
}

# If the message wasn't decoded because it didn't contain the
# secret word, the console prints saying the secret word isn't there
print ("File does not contain the secret word.\nUse a different file that has the secret word.\n")
unless $found;

