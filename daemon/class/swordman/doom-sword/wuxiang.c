#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra;
	int tmp;
	object weapon;
	extra = me->query_skill("doom-sword",1);
           if(me->query("family/family_name")!="剑客联盟")
           return notify_fail("［无想斩］只有剑客联盟弟子才可以使用！\n");
	if ( extra < 150) return notify_fail("你的［杀人剑法］还不够纯熟！\n");	
       if(me->query("swordman/wuxiang_perform")!=1)
                return notify_fail("你还没学会「无想斩」！\n");
        if( (int)me->query("force") < 1000 )      
                return notify_fail("你的内力不够。\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［无想斩］只能对战斗中的对手使用。\n");
	me->add_temp("apply/attack",extra);
//	me->add_temp("apply/damage",extra);
       me->add("force", -300);
	weapon = me->query_temp("weapon");
	message_vision(RED  "\n\n$N腾空越起，变换身行，手中的"+ weapon->name() +"划出森然剑气，一招「无想斩」一气呵成 ！！\n\n" NOR, me, target);
        message_vision(HIC  "「厉鬼缠身」，$N手中"+ weapon->name() +"带着一阵寒意直刺$n！" NOR, me, target);
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR  "\n「群魔夜宴」，$N手中"+ weapon->name() +"带着冷冷的剑气斜刺$n！" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIY  "\n「百鬼夜行」，$N手中"+ weapon->name() +"落叶般横刺$n！" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIW  "\n「十万神魔」，$N手中"+ weapon->name() +"闪电般猛刺$n！" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR  "\n「群魔乱舞」，$N手中"+ weapon->name() +"带着冷冷的剑气斜刺$n！" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIY  "\n「十万幻想」，$N手中"+ weapon->name() +"落叶般横刺$n！" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIW  "\n「万天神魔」，$N手中"+ weapon->name() +"闪电般猛刺$n！" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);me->start_busy(3);
        me->add_temp("apply/attack",-extra);
//      me->add_temp("apply/damage",-extra);
	return 1;
}
