// 赛亚世界 by Calvin

inherit ROOM;

void create ()
{
        set ("short", "赛亚星球");
        set ("long", @LONG
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
       "west" : "/d/longzhu/qy/saiya1",
       "east" : "/d/longzhu/qy/saiya4",
        ]));

        set("objects", 
        ([ //sizeof() == 1
      "/d/longzhu/npc/saiya1" : 1,
       "/d/longzhu/npc/saiya" : 4,
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
