//密林 yaopu

inherit ROOM;
#include <ansi.h>
void create ()
{
        set ("short","密林药铺" );
        set ("long", @LONG

这是密林一家不大的药铺，但这里的药品是应有尽有
这里的物廉价美是有了名的,所以常常看到一些商人
往返在这条路上.
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "south" : "/u/calvin/room/密林深处5",
        ]));

        set("objects", 
        ([ //sizeof() == 1
  "/u/boy/npc/shenyi" : 1,
        ]));

//        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
