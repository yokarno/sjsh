#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "灌木丛");
  set ("long", @LONG

及人高的灌木从(guanmu)完全的挡住了道路，看来不推开
它们是无法前进的了。
LONG);


  set("outdoors", 1);

  set("exits", ([ /* sizeof() == 2 */
    "up" : "/d/swordman/crass",
]));

  setup();
}

void init()
{
  add_action("do_clean", "bo");
  add_action("do_clean", "clean");
  add_action("do_clean", "push");
  add_action("do_clean", "pushaside");
}
int do_clean(string arg)
{	int i;
	object ob=this_object();
	object me=this_player();
	object obj;
        if(!arg || arg != "guanmu" )
                return notify_fail("你要干什么？\n");
	
        if(query("clean"))
                return notify_fail("周围已经没有灌木丛了。\n");

	if((int)me->query("kee") <200)
                return notify_fail("你太累了，歇歇吧！\n");

	if(!(obj = me->query_temp("weapon")) ){
		message_vision("$N想用手去扯那灌木丛，却扎了满手鲜血！\n", me);
		return 1;
	} else {
		message_vision("$N挥舞手中$n，小心的去拨开那堆堆灌木丛。\n", me, obj);
		me->receive_damage("kee", 150);
		i=(int)me->query_str();
		ob->set("coe",(int)ob->query("coe") + i );
		
		if( i < 30 ){
			tell_room(environment(me), "结果只拨开几枝小刺。\n"); 
		}
		else if (i < 50 ) { 
			tell_room(environment(me), "结果拨倒一片灌木丛。\n");
		}
		else if (i < 100 ) {
			tell_room(environment(me), "只见灌木丛被推的不住后退。\n");
                }
		else tell_room(environment(me), "只见灌木丛如潮水般退后。\n");
	}
	
	if( (int)ob->query("coe") >= 1000 ) {
		tell_room(environment(me), "灌木丛被推到两旁，闪出一条道路。\n\n");
		me->set_temp("obstacle/guanmu/clean_1", 1);
		call_out("done", 0);
	}
	return 1;
}
int done()
{
	set("long", @LONG

推开丛丛灌木后,一条道路终于显现了出来。
LONG);
	set("clean", 1);
	set("coe", 0);
	set("exits/down", __DIR__"crass3");
	return 1;
}
