#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short", HIR" 长廊 "NOR);
set ("long", @LONG

一条无尽的长廊，东面似乎是通往一个地方去的。一个相貌凶狠的巨神
拦住了你的去路。你抬头看去，不由得心里吓了一跳。

LONG);
set("exits", 
([ //sizeof() == 2
"west" : "/u/xuexu/workroom",
"east" : "/u/xuexu/jobroom",
]));
set("no_time", 1);
set("no_clean_up", 0);
set("objects", ([
   "/u/xuexu/npc/luohou" : 1,
]));
setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "east" ) {
if (objectp(present("luo hou", environment(me))))
return notify_fail("罗睺喝道：后面是避暑之地，要去先过了老夫这关！\n");
}   
return ::valid_leave(me, dir);
}
