//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5

inherit ROOM;

void create()
{
        set("short", "广场");
        set("long", @LONG
这里是蜀山剑派的广场，通常有许多蜀山剑派弟子在此习武练剑，所以
不欢迎外。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"dadian",
  "east" : __DIR__"jinglou",
  "south" : __DIR__"paifang",
]));

        set("objects",([
        __DIR__"npc/jiantong" : 2,
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
