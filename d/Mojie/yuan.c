// Room: /d/mojie/yuan.c
inherit ROOM;

void create()
{
  set ("short", "黑水之渊");
  set ("long", @LONG
这是便是令三界为之胆寒的黑水之渊，此水对除了天蓬元帅
能渡过，三界之中无人能渡。如果不慎进入的话，是不可能
再出来了。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yuan",
  "west" : __DIR__"yuan",
  "east" : __DIR__"yuan",
  "north" : __DIR__"yuan",
]));
  setup();
  replace_program(ROOM);
}
