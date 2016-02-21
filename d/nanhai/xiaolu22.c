// 神话世界·西游记（世纪）
// Room: /d/nanhai/xiaolu18-22.h

inherit ROOM;

void create ()
{
  set ("short", "羊肠小路");
  set ("long", @LONG
  
山路顺着山势起伏，道路很窄，凸凹不平，岔道密布，远处风吹过树木洒
洒之声不断传来，让人为之一寒。北面远远可以听到大圣禅寺传来的阵阵
钟声。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"xiaolu21",
  "north" : __DIR__"frontgate",
]));
  set("outdoors", "nanhai");

  setup();
}

