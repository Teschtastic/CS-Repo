

require("parse")
require("superparser");
require("verbs");
require("support")

require("rooms/roomsetup");


require("people/kyler");
require("people/sean");
require("people/gerberding");
require("people/minaker");
require("people/postma");
require("people/cat");
require("people/smith")

require("things/map");
require("things/usb");
require("things/atm");
require("things/atmcard");
require("things/catnip");
require("things/candy")
require("things/headphone1")
require("things/headphone2")
require("things/headphone3")
require("things/headphone")


require("verbs/talk");
require("verbs/buy");
require("verbs/get");
require("verbs/drop");
require("verbs/inventory");
require("verbs/look");
require("verbs/attack");
require("verbs/give");
require("verbs/use");
require("verbs/craft")

funds = 50
lastVerb=nil;
karma = 1;
banned= 0;

-- -------------------------------------------------------
-- Initialize the Tables for mappings, items, and people


-- Mapping consists of a ID and a type [0 = item, 1 = person]
mapping = { };

--[[ Items are indexed by ID, and consist of a formal name[0],
 a location[1] (-1, 0, or room)
 a status[2]
 an article [3]
 a use function[4]
--]]
items = { };

--[[ People are indexed by ID, and conists of a formal name[0], 
 a location[1],
 a status[2],	 
 an interact function[3],
 a tick function[4]
--]]

people = { };
nextNumber = 0;

-- --------------------------------------------------------


Kylerinit();
Seaninit();
Gerberdinginit();
Minakerinit();
Postmainit();
Catinit();
smithInit()


Mapinit();
USBinit();
Atminit();
AtmCardinit();
catnipinit();
candyInit();
headphoneInit()
Piece1Init()
Piece2Init()
Piece3Init()


-- -------------------------------------------------------------
-- Start main loop
-- 
-- New for Spring 16 - Added a tick to the main loop
--
-- ------------------------------------------------------------
location = 1
tickCount = 0;
while ( true ) do
	location = roomMap[location]()
	tickCount = tickCount + 1;
	tick()
end	
