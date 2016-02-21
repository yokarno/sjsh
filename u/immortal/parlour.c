#include <ansi.h>
inherit ROOM;
void create()
{
set ("short",HIW "迎 客 厅" NOR);
set ("long",@LONG

           四  方  宾  客         欢  迎  光  临

  out : 出去神宫大殿。
  south : 去药房。
  north : 去书房。
  west : 去练功房。
  east : 去观礼台。
  enter : 进去神宫大仙的睡房。

LONG);
set("exits",([
"out" : __DIR__"workroom",
"south" : __DIR__"dispensary",
"north" : __DIR__"study",
"west" : __DIR__"drill",
"east" : __DIR__"watch",
"enter" : __DIR__"sleep",
]));
set("outdoors", 0);
setup();
}
