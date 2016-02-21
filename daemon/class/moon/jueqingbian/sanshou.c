// sanshou.c by piao
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int i;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「三无三不手」？\n");

        if(!me->is_fighting())
                return notify_fail("「三无三不手」只能在战斗中使用！\n");

        if((int)me->query("max_force") < 1000 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 1000 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

	i=(int)me->query_skill("jueqingbian",1)+(int)me->query_kar();

        if( i < 120)
                return notify_fail("你的绝情鞭法级别还不够，使用这一招会有困难！\n");

        message_vision(HIR"\n　问世间情为何物？直叫人生死相许！$N心中一阵酸楚，鞭法忽然变得灵动异常！\n"NOR,me);

	me->delete("env/brief_message");
	target->delete("env/brief_message");

        me->set_temp("QJB_perform", 17);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

             if( (int)me->query_skill("jueqingbian", 1) > 150 )   {
        me->set_temp("QJB_perform", 17);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->set_temp("QJB_perform", 18);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); }

             if( (int)me->query_skill("jueqingbian", 1) > 180 )   {
        me->set_temp("QJB_perform", 19);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); }

        me->delete_temp("QJB_perform");
        me->receive_damage("sen", 100+random(100));
        me->add("force", -200);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(3+random(1));
        return 1;
}

