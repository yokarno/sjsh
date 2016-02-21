// zhaoyaojing.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;

success_adj = 130;
damage_adj = 130;

	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("你要对谁施展照妖镜？\n");

	if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 50 )
		return notify_fail("你无法集中精力瞄准！\n");

	me->add("mana", -25-2*(int)me->query("mana_factor"));
		me->receive_damage("sen", 10);

	if( random(me->query("max_mana")) < 50 ) {
		write("你的法力不纯，不能自由运用，再施一次吧！\n");
		return 1;
	}

	SPELL_D->attacking_cast(
		me, 
			//attacker 
		target, 
			//target
		success_adj, 	
			//success adjustment
		damage_adj, 	
			//damage adjustment
		"both", 		
			//damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
		HIC "$N口中念了几句咒文，天空中出现一位老人！手持一面宝镜。\n只见他手中的宝镜向$n照去！\n" NOR,
			//initial message
		HIC "结果宝镜的神光$n身上透体而过，顿时血花飞溅！\n" NOR, 
			//success message
		HIC "只见$n轻轻一跳，躲了过去！\n" NOR, 
			//fail message
        HIC "但是$n以法力一拨，神光折向$N！\n" NOR,
			//backfire initial message
		HIC "结果宝镜的神光$n身上透体而过，顿时血花飞溅！\n" NOR, 

			//backfire hit message. note here $N and $n!!!
	);

	me->start_busy(1+random(2));
	return 3+random(5);
}

