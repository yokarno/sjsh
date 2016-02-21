#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short", HIB" 碧水居 "NOR);
set ("long", @LONG

你轻轻踏入这个充满着幽香的房间，看到满室的清蓝色，中间放着一张瑶琴，
旁边零散丢着一些书籍，你捡起一本看去，封面上写着《玄狐长恨刀法》，你
才突然惊觉这个房间的主人是个女子。你心惊之下，正要回身退出，背后一股
幽香飘入你的鼻子，回头看去，一柄闪着耀眼寒光的长剑正指着你的喉咙...

LONG);
set("exits", 
([ //sizeof() == 4
"rainy" : "/u/rainy/workroom",
"kz" : "/d/city/kezhan",
"repoo" : "/u/repoo/workroom",
"fayu" : "/u/fayu/workroom",
"wiz" : "/d/wiz/wizroom",
"east" : "/u/xuexu/changlang",
]));
set("no_fight", 1);
set("no_kill", 1);
set("no_time", 1);
set("sleep_room", 1);
set("no_clean_up", 0);
set("objects", ([
   "/u/xuexu/npc/feixue" : 1,
   "/u/xuexu/obj/xuehua" : 2,
]));
setup();
}
