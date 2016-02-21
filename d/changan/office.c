// Room: /u/wuliao/housingoffice
#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short", "房管所");
        set ("long", @LONG
泾水河边的居民逐渐增多，因此特别在此设立房管所，临时由
一个不知名的老头负责。
LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "hole" : "洞中似乎是个机关，能放(insert)下什么东西。\n",
]));

        set("exits", 
        ([ //sizeof() == 4
  "east" : __DIR__"ph",
        ]));

        set("objects", 
        ([ //sizeof() == 1
  __DIR__"officer" : 1,
        ]));

        set("no_clean_up", 0);
        set("no_fight", 1);
        set("no_magic", 1);
  set("outdoors", 1);
        setup();
//      replace_program(ROOM);
}

void init()
{
        add_action("do_insert", "insert");
}
int do_insert(string arg)
{
        object mishi, ob, me;
        me=this_player();
        if( !arg )
                return notify_fail("你要放什么东西？\n");

        if( !arg || arg!="yao pai" || !(ob=present(arg, me)) || ob->query("name")!="水晶腰牌" )
                return notify_fail("似乎孔中放不下这个东西。\n");

        if( !(mishi = find_object(__DIR__"mishi1")) )
                mishi = load_object(__DIR__"mishi1");

        if( mishi = find_object(__DIR__"mishi1") ) 
        {
                set("exits/enter", __DIR__"mishi1");

                message_vision("$N将$n塞入小孔，只听喀喀几声，一座大石移开，露出向下一个通口。\n", me, ob);
                message("vision", "大石被人从外推开了。。\n", mishi );
                mishi->set("exits/out", __DIR__"jiashan1");
                destruct(ob);
        call_out("close_down", 5);
        }
        return 1;
}

void close_down()
{
        object mishi;

        message("vision", "大石轰地又回到原位。\n", this_object() );
        if( mishi= find_object("/d/sea/inside3")) {
        message("vision", "大石轰地又回到原位。\n", mishi);
        mishi->delete("exits/out");
        }

        delete("exits/enter");

}
