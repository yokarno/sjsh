// Room: /d/mojie/dadian
inherit ROOM;

void create()
{
  set ("short", "无法大殿");
  set ("long", @LONG
这里便是魔界的无法大殿，是无天花了近十年心血，请了无数的能
工巧匠建造而成的。大殿的正中间供着无天的神像。殿前还有几个
蒲团，是专门给魔界弟子参拜用的。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"guodao",
  "east" : __DIR__"youdian",
  "west" : __DIR__"zuodian",
  "northup" : __DIR__"neidian",
]));
  set("objects",([
   __DIR__"npc/zhangmen" : 1,
]));
  setup();
  replace_program(ROOM);
}
