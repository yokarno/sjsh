//changan city

inherit ROOM;
#include <ansi.h>
void create ()
{
        set ("short","济世堂" );
        set ("long", @LONG

这是长安城一家老字号的药铺的内堂．神医华佗老仙在这里
下凡济世救人．你可以跟他学些医术．
LONG);

        set("exits", 
        ([ //sizeof() == 4
                "west" : __DIR__"yaopu",
                "east" : __DIR__"yaofang",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/shenyi" : 1,
        ]));


        set("no_fight", 1);
        set("no_magic", 1);
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


