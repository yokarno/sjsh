//shulin 兰陵

inherit ROOM;

void create ()
{
        set ("short", "兰陵东郊");
        set ("long", @LONG

这里是兰陵城的东郊,宽阔的马路两边树木林立,美不胜数.

LONG);
        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "west" : "/u/calvin/兰陵/地区/兰陵东郊1",
                "east" : "/u/calvin/兰陵/地区/兰陵东郊3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
