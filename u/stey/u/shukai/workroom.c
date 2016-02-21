#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
  set("short",HIW "疯人院" NOR);
set ("long", @LONG
            疯 子 们 住 的 地 方
LONG);
    set("exits",([
  "pig" : "/u/xintai/workroom.c",
  "ziye" : "/u/ziye/workroom.c",
    "south" : "/u/shukai/home.c",
  "kz" : "/d/city/kezhan.c",
]));
      set("objects",([
             "/u/shukai/npc/lol" : 1,
        ]));
        set("no_clean_up",0);
setup();
        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
    if ( dir == "south" ) {
      if ( me->query("id") == "shukai"  || me->query("id") == "aileen")
{
return ::valid_leave(me, dir);}

else
{
return notify_fail("闲人免进。\n");
}
return 1;
}
}
