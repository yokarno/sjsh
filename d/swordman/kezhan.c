//shop.c
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "东瀛客栈");
	set("long", @LONG

东瀛城内最大的客栈,来来往往的人很多，兼之价钱低廉，所以生意
非常的兴隆。往南是客房，可以在这里休息过夜。

LONG
        );
	set("no_clean_up", 1);
	set("resource/water", 1);
	set("exits",([
		"north"  : __DIR__"dalu5",
		"south" : __DIR__"kefang",
        ]));
	set("objects", ([
                __DIR__"npc/waiter" : 1,
        ]));
        set("valid_startroom", 1);
        setup();
}
int valid_leave(object me, string dir)
{
        if ( !me->query_temp("rent_paid") && dir == "south" )
                return notify_fail("没付房钱就想住店？\n");
        return ::valid_leave(me, dir); 
}
