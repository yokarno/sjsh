// Room: /d/mojie/zuodian
inherit ROOM;

void create()
{
  set ("short", "左偏殿");
  set ("long", @LONG
殿内一片魔瘴之气，殿的两侧一边九根石柱，上面刻了十八尊魔
神之像，个个狰狞恐怖。让人不寒而栗。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"dadian",
]));
  set("objects",([
  __DIR__"npc/juxie" : 1,
]));
  setup();
  replace_program(ROOM);
}
