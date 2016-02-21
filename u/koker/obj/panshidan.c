//panshidan.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIC "叛师丹" NOR,({"panshidan"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	HIC "一颗能够忘记现在师门所有事情的灵丹。\n"NOR);
		set("unit","颗");
		set("value", 100000000);
	}
}

void init()
{
	if(environment()==this_player())
		add_action("eat_guo","eat");
}

int eat_guo(string arg)
{
	if ( arg == "panshidan")
	{
   message_vision(HIC"$N小心翼翼的服下一颗叛师丹，一股清香直冲面门，现在师门所有事情仿佛都成了过去。\n"NOR,this_player());
		this_player()->add("betrayer",-1);
		if (this_player()->query("betrayer")< 0) 
			this_player()->delete("betrayer");
//     this_player()->delete("family");
//     this_player()->set("title","普通百姓");
//     this_player()->delete("class");
		destruct(this_object());
		return 1;
	}
	return	0; 
}
