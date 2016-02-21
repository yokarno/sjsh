// Room: /d/mojie/guodao.c
inherit ROOM;

void create()
{
  set ("short", "过道");
  set ("long", @LONG
这是一条又长又窄的过道。过道两旁插满了火把，把整个过道照的
通亮。过道的墙壁上刻着许多吓人的石像。向前走就是无法大殿，
左边是练功房。望右是膳房。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"guodao",
  "east" : __DIR__"guodao4",
]));
        set("objects", 
        ([ //sizeof() == 1
    __DIR__"npc/humo" : 1,
        ]));
  setup();
  replace_program(ROOM);
}
