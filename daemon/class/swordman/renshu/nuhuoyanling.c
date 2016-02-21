// nuhuoyanling.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;
        string str;

//	success_adj = 200;
//	damage_adj = 190;
        success_adj = 200;
	damage_adj = 190;
 

	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("你要用怒火焰灵烧谁？\n");

        if(me->query("family/family_name")!="剑客联盟")
                return notify_fail("不是剑客联盟弟子不能用「怒火焰灵」！\n");

	if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 20 )
		return notify_fail("你无法集中精力，别烧中自己了！\n");

	me->add("mana", -25-2*(int)me->query("mana_factor"));
	me->receive_damage("sen", 10);

	if( random(me->query("max_mana")) < 50 ) {
		write("好象没反应，再来一次吧！\n");
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
		HIR "$N双手合一，念了几句咒语,身上冒出火焰,逼向$n身旁~!\n" NOR,
			//initial message
		HIR "结果烧了个正着，差点没把$n烧死！\n" NOR, 
			//success message
		HIR "但是$n在千钧一发之际躲了开来。\n" NOR, 
			//fail message
		HIR "但是怒火焰灵被$n以法力一引，反而飘到到了$N的顶门！\n" NOR, 
			//backfire initial message
		HIR "结果烧个正着，差点没把$n烧死！\n" NOR
			//backfire hit message. note here $N and $n!!!
	);
        if (target->query("eff_kee")<0 || !living(target))  
{str=target->name()+"被"+""HIW""+me->name()+""HIM""+"用剑客联盟绝招『"HIR"怒火焰灵"HIM"』烧死了。听说"+target->name()+"尸体都已经烧焦了!";
        message("channel:rumor",HIM"【"HIW"剑客联盟"HIM"】某人："+str+"\n"NOR,users());

        }
        me->start_busy(1+random(1));
	return 3+random(5);
}

