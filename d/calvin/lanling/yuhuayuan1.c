// 九天三门 by Calvin
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "御花园");
  set ("long", @LONG

这里是皇宫的后院 - "御花园",这里四季长青,其中最显眼的就是
花园中间的那棵"千紫藤(qianzi teng)",它高耸入云,一眼看不到
顶.据说曾经有人试着爬过,但是没到一半就返回了,尽管这样也花
了好多天,不过你也可以试试爬上去,据说如果拿到这藤最顶上的一
件宝物并交给皇帝的话可以得到赏赐,你可以使用(climb)试试 ...
如果你是个精明的人也许你也会在无意之间发现什么...
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yuhuayuan",
]));

        set("objects", 
        ([ //sizeof() == 1
              "/d/longzhu/npc/king" : 1,
        ]));

  set("outdoors", 1);

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
        me->move("/d/milin/qy/duanyang");
        message_vision(HIY "只见$N浑身黑土,狼狈的掉了下来。\n" NOR, me);
        me->receive_damage("kee", 20);
        me->receive_damage("sen", 20);
        return 1;
}




