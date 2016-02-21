// 神话世界·西游记·版本（世纪）
/* <SecCrypt CPL V3R05> */

//created by night 8/18/2000

inherit ROOM;
void create()
{
        set("short","密林");
        set("long",@LONG
        
这里是蠙城野外荒郊，林荫蔽日，人迹罕至，不禁令人感到有些阴森。脚
下很多腐烂的树叶，一不小心就会摔上一跤。从这里往南可以通往海边，
但海风从来也吹不进这片密林。
LONG);
        set("exits",([
        "northwest" : __DIR__"xiaolu0",
        "east"  : __DIR__"milin2",
        "south"     : __DIR__"milin1",
        "west" : __DIR__"milin1",
        ]));

        set("dangerous", 1);
        setup();
//      replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
   if((string)me->query("id")!="monster" || userp(me)) return 1;
//        if( wizardp(me)) return 1;

        if (dir == "northwest") {

        return notify_fail("山精海妖不能离开这里。\n");

        }   
        return ::valid_leave(me, dir);
}

