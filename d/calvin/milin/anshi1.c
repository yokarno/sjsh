//Cracked by Roath
//Cracked by Roath
// ajax

#include <room.h>
inherit ROOM;

void create()
{
set("short", "密林暗室");
set("long", @LONG

        这是一个很独特的暗室,因为这个森林
平时就显得人烟稀少,所以这的暗室几乎没被发
现过,这里显的很僻静,很安全。
LONG );

set("exits", ([
                "enter" : "/d/calvin/milin/anshi",
                "out" : "/d/calvin/milin/anshi",
              "up" : "/d/calvin/milin/bed",

]));
set("objects", ([
]));

create_door("enter", "石门", "out", DOOR_CLOSED);
set("no_clean_up", 0);

setup();
}
