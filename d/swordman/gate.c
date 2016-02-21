// Room: /d/4world/northgate.c
inherit ROOM;

void create ()
{
  set ("short", "东瀛之滨城门");
  set ("long", @LONG

一座高大的城墙耸立于前者，城上不断有守城的官兵走过。城中
往往来来的人很多，东瀛国人风淳朴，民富而知足，到处也都是
一幅喜气洋洋的景色。
LONG);

  set("light_up", 1);
  set("no_magic", 1);
  set("outdoors", __DIR__"");
  set("objects", ([
                __DIR__"npc/jianshi": 4]) );

  set("exits", ([ /* sizeof() == 2 */
      "east"  : __DIR__"dalu1",
      "west":__DIR__"haian",
]));
  set("no_fight", 1);

  setup();
}
