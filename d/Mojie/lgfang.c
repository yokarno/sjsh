// Room: /d/mojie/lgfang.c
inherit ROOM;

void create()
{
  set ("short", "练功房");
  set ("long", @LONG
这里是魔界的弟子们用来打坐练功的地方，房里有各式各样的兵器。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"guodao2",
]));
  set("objects", ([ 
   __DIR__"npc/xiongmo" : 1,
]));
  setup();
  replace_program(ROOM);
}
