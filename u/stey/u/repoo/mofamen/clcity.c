#include <room.h>
#include <ansi.h>
inherit ROOM;
inherit F_SAVE;
string SAVE_NAME;
void create ()
{
set ("short", "赤龙城");
set ("long", @LONG
 
这是一座古老的城堡。以完全被冰雪所覆盖。身边的寒风
呼呼的肆虐着。在城堡中间有一个龙形的冰雕，上面有个
正方形的孔，好象可以放进什么东西。

LONG);
  set("exits", ([ /* sizeof() == 1 */
    "southeast" : "/u/repoo/mofamen/cl_door",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/chilong" : 1,
  ]));
  create_door("southeast", "赤龙城城门", "northwest", DOOR_CLOSED);
  set("no_clean_up", 1);
  setup();
}
void init()
{
        add_action("do_insert", "insert");
        set("no_clean_up", 1);
}

int do_insert(string arg)
{
        object hlcity, ob, me;
        me=this_player();

   if(!me->query_temp("chilong_killed"))
                 return notify_fail("你最好先杀了守城护卫？\n");
        if( !arg)
                return notify_fail("你要放什么东西？\n");

if( !arg || arg!="fang jing" || !(ob=present(arg, me)))
                return notify_fail("似乎孔中放不下这个东西。\n");

          if( !(hlcity = find_object(__DIR__"hl_door")) )
                hlcity = load_object(__DIR__"hl_door");

        if( hlcity = find_object(__DIR__"hl_door") ) 
        {
                set("exits/enter", __DIR__"hl_door");
                message_vision("$N将$n塞入方孔，一道黑光闪过，出现一条通道。\n", me, ob);
                message("vision", "通道从外面打开了。。\n", hlcity );
                 hlcity->set("exits/out", __DIR__"clcity");
                destruct(ob);
        call_out("close_down", 600);
        }
        return 1;
}
void close_down()
{
        object hlcity;

        message("vision", "通道消失在红光中。\n", this_object() );
        if( hlcity= find_object(__DIR__"hl_door")) {
        message("vision", "通道消失在红光中。\n", hlcity);
        hlcity->delete("exits/out");
        }
        delete("exits/enter");
}
