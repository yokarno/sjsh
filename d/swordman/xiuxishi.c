// xiuxishi.c by yushu 2000.11

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short",HIR "「" HIY "卧室" HIR "」" NOR);
	set("long", @LONG

这里是神谷道场内的休息室，屋子有点点旧，但是打扫的非常干净，
一排床铺靠墙摆着，东面过去就是大厅，不断的有人进来休息或醒后
离去，你悄悄的找个空铺睡了下来。
LONG
	);
        set("exits", ([
	    	     "east" : __DIR__"dating",
		]));

           set("sleep_room",1);  
       setup();
	replace_program(ROOM);
}

