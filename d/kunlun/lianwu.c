//kunlun
inherit ROOM;

void create ()
{
        set ("short", "练武场");
        set ("long", @LONG

这是玉虚洞前的一块平地，供本派弟子练功之用。几个仙童
正在练习剑术。
LONG);

        set("exits", 
  ([ //sizeof() == 4
                "south" : __DIR__"lingyun",
                "north" : __DIR__"dadian",
        ]));
        set("objects", ([
                __DIR__"npc/xiao" : 2,
   ]));
        set("outdoors", "changan");
       setup();
	replace_program(ROOM);
}

