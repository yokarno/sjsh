// chalk.c
// by kittt

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIC"粉笔" NOR, ({ "chalk" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "支");
	      set("long","小叮当的空间交换机。\n");
		set("value", 0);
	}
	setup();
}

void init()
{
        add_action("do_circle","circle");
}

int do_circle(string arg)
{
	object me, obj, ob;
	
	me = this_player();
	ob = me->query_temp("circle_obj");

	if( !arg )
		return notify_fail("你想在哪里画圈？\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("这里没有这个东西。\n");

	if(obj == me)  
		return notify_fail("you can't circle yourself.\n");

	if(ob == obj) return notify_fail("you just circled it .\n");
	if(ob && present(ob, environment(obj))) 
		return notify_fail("They are already in the same room lah.\n");

		message_vision(HIW "$N在$n的周围画了一个圆圈。\n" NOR,me,obj);
		if(ob) { 
	tell_room(environment(obj), MAG"结果"+obj->name()+"奇迹般地消失在了圆圈里，接著"+ob->name()+"出现在了圆圈中。\n"NOR, ({obj}));
	tell_room(environment(ob), MAG"突然"+ob->name()+"消失在了圆圈里，接著"+ob->name()+"出现在了圆圈中。\n"NOR, ({ob}));

			obj->move(environment(ob));
			ob->move(environment(me));
			write (ob->name()+"和"+obj->name()+"空间交换成功。\n");
			me->delete_temp("circle_obj");
			 return 1; }			
		me->set_temp("circle_obj",obj);
		return 1;
}

