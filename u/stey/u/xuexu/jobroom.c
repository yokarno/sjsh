#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short", HIW" 清风徐来 "NOR);
set ("long", @LONG

这里是一间有着清新空气的小房间。窗外看去，正是荷花摇动的西湖。节
时正值盛夏，房间里却是感觉十分清凉，旁边的茶几上放着菊花茶，上面
浮着几滴晶晶亮的冰珠，让人觉得清凉安静。

LONG);
set("exits", 
([ //sizeof() == 1
"west" : "/u/xuexu/changlang",
]));
set("no_fight", 1);
set("no_kill", 1);
set("no_time", 1);
set("no_clean_up", 0);
set("objects", ([
   "/u/xuexu/obj/cup" : 2,
]));
setup();
}
