//kunlun
inherit ROOM;

void create ()
{
        set ("short", "休息室");
        set ("long", @LONG

玉虚洞的弟子休息室。陈设相当简陋，连张床都没有。
LONG);

        set("exits", 
  ([ //sizeof() == 1
                "northwest" : __DIR__"lingyun",
        ]));
        set("objects", ([
   ]));
        set("no_clean_up", 0);
        set("sleep_room",1);
        set("if_bed",1);
        set("no_get",1);
        set("no_fight",1);
        set("no_cast",1);
       setup();
	replace_program(ROOM);
}

