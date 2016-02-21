
//Room: huayanding.c 华严顶
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	  set("short","华严顶");
	  set("long",@LONG
华严顶挺拔高峭，古刹云深，殿宇孤耸，风景奇险。这里视野开阔，仰可
见金顶巍巍，俯可望群峰罗列，许多蹲伏山间的寺院也在眼底。由此向西过十
二盘，即到莲花石。北面是一间马厩。
LONG);
	  set("objects", ([
           __DIR__"npc/yingke" : 1,
	  ]));
	  set("outdoors", "emei");
	  set("exits",([ /* sizeof() == 1 */
          "northup"   : __DIR__"shierpan",
	  ]));
//	  set("no_clean_up", 0);
	  setup();
	  replace_program(ROOM);
        "obj/board/emei_b"->foo();

}

