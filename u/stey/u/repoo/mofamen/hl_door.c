// by Repoo
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", HIB"黑龙城城门"NOR);
  set ("long", @LONG
只见这城门非金非木非石;上面雕刻这一条黑色
的巨龙，看样子，应该是黑龙城的护卫。
LONG);
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"hlcity",
]));
  create_door("east", "黑龙城城门", "west", DOOR_CLOSED);
  set("objects", ([
]));
  set("outdoors", 1);
  setup();
}
