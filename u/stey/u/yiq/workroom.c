//by repoo
#include <ansi.h>
inherit ROOM;
void create ()
{
          set ("short",BLINK HIM"衣青"NOR+HIW"工作室"NOR);
        set ("long", @LONG
这里是系统管理员（衣青）为自己工作和学习而修建的工作室。
满目的清新的花草充满了整个的房间。
LONG);
        set("exits", 
        ([ //sizeof() == 3
                "kz" : "/d/city/kezhan",
           "wizroom" :  "/d/wiz/wizroom",
           "room" :  "/u/yiq/love",
                        ]));
        set("no_death", 1);
	 set("no_fight", 1);
        set("no_kill", 1);
        set("no_time", 1);
        set("sleep_room", 1);
        set("no_clean_up", 0);
  set("valid_startroom", 1);
        setup();
}
void init()
{
        object me = this_player();
        tell_room( environment(me), WHT"衣青"+HIM"喃喃"+WHT"的说到：热泪欢迎！\n"NOR);
}
