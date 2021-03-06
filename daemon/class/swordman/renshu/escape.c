//cast function: escape.c 可用于各种逃遁。
//useful only when fighting, other cases only waste fali.
//modified for wudidong, 10-4-97 pickle

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	string msg,start;
	int ap, dp, success;
	target = offensive_target(me);
	//always use the one who is fighting me as target.

	if( me->is_busy())
		return notify_fail("你正忙着呢，先应付眼前的事吧。\n");

	if( (int)me->query("mana") < 100 )
		return notify_fail("你的法力不够了！\n");

	if( (int)me->query("sen") < (int)me->query("max_sen")/5 )
		return notify_fail("你精神太差，难以集中精力念咒。\n");

	if( (int)me->query_skill("renshu", 1) < 40)
		return notify_fail("你未曾学会逃遁之术。\n");

	ap=me->query_skill("spells")+me->query("max_mana")/10;
	if(target) dp=target->query_skill("spells")+target->query("max_mana")/10;

	if(!me->is_fighting() )
	{
		message_vision(HIB"$N喃喃念了句咒，只见一团蓝色的烟雾包围住了$N的身体，
烟雾散去时,已不见了$N的身影。\n"NOR,me);
		me->add("sen", -me->query("max_sen")/8);
		me->add("mana", -80);
		success=1;
	}
	else
	{
		msg=HIB"激战中，$N突然跳出战圈，喃喃念了几句咒。\n"NOR;
		if(random(ap+dp)>dp/2)
		{
			msg+=HIB"只听$N喝了一声「遁！」，人影已经不见了。\n"NOR;
			me->add("sen", -me->query("max_sen")/6);
			me->add("mana", -50);
			success=1;
		}
		else msg+=HIB"但$n的身影已紧紧跟上，将$N拦了下来。\n"NOR;
		me->add("mana", -50);
		message_vision(msg, me, target);
	}
	if(success)
	{
		start=me->query("env/destination");
		start=me->query("记号/"+start);
		if(!start || !find_object(start))
			start=me->query("startroom");
//		if(!start) start="/d/qujing/wudidong/kitchen";
		me->move(start);
		message("vision", HIB+me->name()+"的身影突然出现在一团烟雾中。\n"NOR,
				  environment(me), me);
		tell_object(me, HIB"一团烟雾中渐渐现出了你的身影。\n"NOR);
		return 3+random(3);
	}
	return 5+random(5);
	//if failed, can't use for a while.
}

