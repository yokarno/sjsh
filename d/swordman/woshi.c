// xiuxishi.c by yushu 2000.11

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short",HIR "「" HIY "卧室" HIR "」" NOR);
	set("long", @LONG

很简陋的一间卧室，靠南面墙是几张床，除此外就没有其他的摆
设物品了。
LONG
	);
        set("exits", ([
	    	     "south" : __DIR__"workroom",
                                 "east":__DIR__"mishi",
		]));

           set("sleep_room",1);  
       setup();
	replace_program(ROOM);
}

