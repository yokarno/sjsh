
//Room: huacangan.c 华藏庵
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	  set("short","华藏庵");
	  set("long",@LONG
华藏庵是金顶的主要建筑，规模宏大，中祀普贤菩萨，旁列万佛。
LONG);
	  set("outdoors", "emei");
	  set("exits",([ /* sizeof() == 1 */
	  "enter"	  : __DIR__"hcazhengdian",
	  "north"	  : __DIR__"jinding",

	  ]));
	  set("no_clean_up", 0);
	  setup();
	  replace_program(ROOM);
}
