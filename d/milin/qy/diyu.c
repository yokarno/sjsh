// 三重门

#include <ansi.h>
inherit ROOM;

void create ()
{
        set ("short", "地狱门");
        set ("long", @LONG
这里是地下城的出口之门-地狱门-,再往下便是-死城-。
破烂的墙上写着:
                   ********************
                   ****地***狱***门****
                   ********************
LONG);

        set("exits", 
        ([ //sizeof() == 4
        ]));

        set("objects", 
        ([ //sizeof() == 1
         "/d/milin/npc/diyu" : 1,
        ]));

        set("no_quit", 1);
        setup();
}

void init()
{
        add_action("do_wa", "wa");
}

int do_wa()
{
        object  me, horse;
        me = this_player();
/*        
        if(me->query_temp("ridee")){
                horse=me->query_temp("ridee");
                me->command_function("dismount "+horse->query("id"));
        }
*/
message_vision(HIY "$N使劲的挖啊挖,累的满头是汗。忽然只见$N身边一道黑光,之后就不见了身影。\n" NOR, me);
        me->move("/d/milin/qy/sc");
        message_vision(HIY "只见$N浑身黑土,狼狈的掉了下来。\n" NOR, me);
        me->receive_damage("kee", 100);
        me->receive_damage("sen", 100);
        return 1;
}
