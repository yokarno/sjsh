//kunlun
inherit ROOM;

void create ()
{
        set ("short", "大殿");
        set ("long", @LONG

这是玉虚洞前的一块平地，供本派弟子练功之用。几个仙童
正在练习剑术。
LONG);

        set("exits", 
  ([ //sizeof() == 4
                "south" : __DIR__"lianwu",
                "northwest" : __DIR__"mishi",
        ]));
        set("objects", ([
                 __DIR__"npc/zhangmen" : 1,
                __DIR__"npc/luya" : 1,

   ]));
       setup();
	replace_program(ROOM);
        "obj/board/kunlun_b"->foo();

}

