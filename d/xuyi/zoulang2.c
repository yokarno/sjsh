// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

inherit ROOM;

void create ()
{
        set ("short", "走廊");
        set ("long", @LONG
 
你走在一条长廊上，两旁都是庭台堂庑，廊上弥漫著一股清香的
香烛味道，廊下是由青石砖铺成，尽头是一间小室。
LONG);

        set("exits", ([ //sizeof() == 4
       "south" : __DIR__"zoulang", 
       "northeast" : __DIR__"xiaoshi",        ]));

        setup();
}

