// sticker.c

#include <ansi.h>

inherit ITEM;

void init()
{
        add_action("do_stick","stick");
        add_action("do_remove","remove");
        add_action("do_remove","drop");
        add_action("do_remove","give");

	if(environment()->query_temp("banned_talk")) {
      add_action("do_commu","say");
      add_action("do_commu","whisper");
      add_action("do_commu","chat");
      add_action("do_commu","shout");
      add_action("do_commu","wiz");
      add_action("do_commu","party");
      add_action("do_commu","tell");
      add_action("do_commu","reply");
      add_action("do_commu","rumor");
      add_action("do_commu","es");
	}
}

void create()
{
	set_name(HIM"OK绷"NOR, ({ "sticker" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("value", 0);
		set("no_get",1);
		set("long", "这是一张小叮当的OK绷，专门对付乱说话的人。\n");
	}
	setup();
}

int do_stick(string arg)
{
	object me, obj;
	
	me = this_player();

	if( !arg )
		return notify_fail("你想贴谁？\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("这里没有这个人。\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");

	if(obj == me)
		return notify_fail("just shutup.\n");

	if(me->query_temp("banned_talk"))
		return notify_fail("you shutup!!!\n");

	message_vision(HIM "\n$N拿出一张OK绷，轻轻托住$n的下巴，叭地贴了上去。\n\n" NOR, 
			me, obj);
	obj->set_temp("banned_talk",1);
	this_object()->move(obj);
	return 1;
}

int do_commu(string arg)
{
	object me=this_player();

	message_vision(BLU"$N张大了嘴巴，却什麽话也说不出来。\n"NOR,me);
	return 1;
}

int do_remove(string arg)
{
	object me=this_player();

	if(!me->query_temp("banned_talk")) return 0;

	if(!arg||arg!="小叮当的OK绷") {
		message_vision("$N用力想撕开OK绷，但是没成功。\n",me);
		return 1; }
	message_vision(HIR"$N把OK绷从嘴上撕了下来，鲜血流了一地。\n"NOR,me);
	return 1;
}