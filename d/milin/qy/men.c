// 密林宝库 by Calvin

inherit ROOM;
void create ()
{
        set ("short", "密林入口");
        set ("long", @LONG
这是通往密林迷宫的唯一入口,入口处有两名守卫把守着。
LONG);

        set("exits", 
        ([ //sizeof() == 4
       "south" : "/d/milin/qy/n1",   
       "north" : "/d/milin/qy/scc",   
        ]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/milin/npc/guard" : 2,
       "/d/wizz/calvin/longzhu/zhu4" : 1,
        ]));

//       set("outdoors", "changan");
//        set("no_clean_up", 0);
        setup();
//       replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
//     object me = this_player();
        object a;
   if (dir == "north" ) {
                if(objectp(a=present("guard", environment(me))) &&
living(a) )
        return notify_fail("密林守卫拦住你说道:北方密林迷宫向来是有去无回,你还是回头吧。\n");
        }   
        return ::valid_leave(me, dir);
}
