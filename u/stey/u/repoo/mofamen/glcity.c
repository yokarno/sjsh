#include <room.h>
#include <ansi.h>
inherit ROOM;
inherit F_SAVE;
string SAVE_NAME;
void create ()
{
set ("short", HIW"骨龙城"NOR);
set ("long", @LONG
 
这是一座古老的城堡。城堡到处是奇形怪状的白骨，时
不时的冒出星星磷火，阴森森的，充满了怪异。和其他龙
城一样，中间也有一个标志型的建筑，骨制图腾。其上有
一个正六边形的孔。

LONG);
  set("exits", ([ /* sizeof() == 1 */
    "northeast" : "/u/repoo/mofamen/gl_door",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/gulong" : 1,
  ]));
    create_door("northeast", "骨龙城城门", "southwest", DOOR_CLOSED);
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
         object glcity, ob, me;
        me=this_player();
   if(!me->query_temp("gulong_killed"))
              return notify_fail("你最好先杀了守城护卫？\n");
        if( !arg)
                return notify_fail("你要放什么东西？\n");
 if( !arg || arg!="liubian manao" || !(ob=present(arg, me)))
                return notify_fail("似乎孔中放不下这个东西。\n");

           if( !(glcity = find_object(__DIR__"shendian_door")) )
                glcity = load_object(__DIR__"shendian_door");
       if( glcity = find_object(__DIR__"shendian_door") ) 
{
                set("exits/enter", __DIR__"shendian_door");
message_vision("$N将$n塞入六角形的孔，一道彩光闪过，出现一条通道。\n", me, ob);
               message("vision", "通道从外面打开了。。\n", glcity );
                  glcity->set("exits/out", __DIR__"glcity");
                destruct(ob);
        call_out("close_down", 600);
        }
        return 1;
}
void close_down()
{
        object glcity;
        message("vision", "通道消失在彩光中。\n", this_object() );
        if( glcity= find_object(__DIR__"shendian_door")) {
         message("vision", "通道消失在彩光中。\n", glcity);
        glcity->delete("exits/out");
        }
        delete("exits/enter");
}
