// sanjie tianyilang5.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG
	
走廊穿梭在莲花池边，云雾就在池中升起，雾中带有莲花香
气，果然是人间仙景。
LONG);

  set("exits", ([
  "north" : __DIR__"tianyirest",
  "west" : __DIR__"tianyidian4",
  "south" : __DIR__"tianyilang3",
]));
  set("outdoors", 1);

  setup();
}
