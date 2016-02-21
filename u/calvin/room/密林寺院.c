//密林 寺院

inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short","白龙寺" );
        set ("long", @LONG
白龙寺是密林地区唯一的一家正规的寺院,因为其名气盛远
所以这常常有许多远到而来的善男信女,若到了皇道吉日更
是人山人海。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "north" : "/u/calvin/room/密林深处4",
              "east" : "/u/calvin/room/讲经堂",
              "south" : "/u/calvin/room/藏经阁",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                 "/u/calvin/npc/宠物" : 2,
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
