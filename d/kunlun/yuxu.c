//kunlun
inherit ROOM;

void create ()
{
        set ("short", "玉虚宫");
        set ("long", @LONG

这里玉虚宫了，面前一位老神仙正在入定打坐。
看到你来了冲你点了点头。
LONG);

        set("exits", 
  ([ //sizeof() == 4
                "south" : __DIR__"hundun",

        ]));
        set("objects", ([
                __DIR__"npc/tianzun" : 1,
                __DIR__"npc/tongzi" : 1,


   ]));
       setup();
	replace_program(ROOM);
}

