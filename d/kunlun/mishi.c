//kunlun
inherit ROOM;

void create ()
{
        set ("short", "密室");
        set ("long", @LONG

这里是另外一间石室，此处很安静，很适合仙家来次修炼。
原始天尊为了安静修炼，特让弟子姜子牙在此接待来这里的仙
客们。
LONG);

        set("exits", 
  ([ //sizeof() == 4
                "southeast" : __DIR__"dadian",
                "north" : __DIR__"houtang",
        ]));
        set("objects", ([
                __DIR__"npc/ziya" : 1,

   ]));
       setup();
	replace_program(ROOM);
}

