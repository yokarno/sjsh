// feitian-jian.c  飞天剑
// Modified by Cody March.2001
// Write by Cody

#include <ansi.h>

inherit SSERVER;


int perform(object me, object target)
{
        object weapon, ob;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
            return notify_fail("你要对谁施展这一招「吸魂摄魄」?\n");
	if(me->query("family/family_name")!="大雪山")
         return notify_fail("不是一个门派怎么能用别人的工夫呢？？？\n");

        if( !me->is_fighting() )
        return notify_fail("「吸魂摄魄」只能在战斗中使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
             || (string)weapon->query("skill_type") != "blade")
                        return notify_fail("你使用的武器不对。\n");

        if( environment(me)->query("no_fight") )
                return notify_fail("在这里不能攻击他人。\n");

        if( (int)me->query_skill("bingpo-blade", 1) < 150)
                 return notify_fail("你的冰魄刀法等级不到150，怎么能使出「吸魂摄魄」。\n");

      if( (int)me->query("combat_exp",1) < 250000 )
          return notify_fail("你的经验不足，不能使出「吸魂摄魄」。\n");

        if (me->query("force") < 300)
               return notify_fail("你内力不继，难以使出「吸魂摄魄」。\n");



     msg = HIG "$N使出冰魄寒刀的绝技「吸魂摄魄」，向对手发出了强大的攻击！\n\n" NOR;
        message_vision(msg, me);

        me->clean_up_enemy();
        ob = me->select_opponent();

        message_vision(HIW"只见一道剑光直刺向$n。"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
       message_vision(HIW"一道寒光过后，$n身上多了一个深深的伤口。"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

         message_vision(HIW"只见刀光一闪，一把锋利的冰刀指向$n的咽喉。"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

         message_vision(HIW"$n虽然躲过了刀锋，却被刀上的寒气冻伤，脸上一片紫红。"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

 message_vision(HIW"$N大喊一声，跳将起来，举起手里的冰刀，劈头盖脸的砍向$n。"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

 message_vision(HIW"$N说道：吃我一刀$n。"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

 message_vision(HIW"$N说道：就你这点道行还要和我斗？真是找死！"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        
me->add("force", -100);
        me->start_busy(3);
target->start_busy(4);

target->reisve_damage(50);
target->reisve_wounder(10);


        return 1;  

}
