// 大唐西游记·幻想
// 5-8-2001 piao

#include <ansi.h>

int exert(object me, object target)
{
        int sp, dp;

        if( !objectp(target) || target->query("id") == "piao" )
                return notify_fail("你要吸纳谁的法力？\n");

        if ( me->query_temp("sucked") )
                return notify_fail("你刚刚吸纳过法力！\n");


        if( !me->is_fighting() || !target->is_fighting())
                return notify_fail("你必须在战斗中才能吸纳对方的法力！\n");

        if( (int)me->query_skill("yijinjing",1) <80)
                return notify_fail("你的易筋经神功功力不够，不能吸纳对方的法力！n");

        if( (int)me->query("force",1) < 500 )
                return notify_fail("你的内力不够，不能使用海纳千山。\n");

        if( (int)target->query("max_mana") <= 0 )
                return notify_fail( target->name() +
                        "没有任何法力！\n");

        if( (int)target->query("mana") < (int)target->query("max_mana") / 10 )
                return notify_fail( target->name() +
                        "已经法力涣散，你已经无法从他体内吸纳任何法力了！\n");

        message_vision(
              HIY "$N运气易筋经神功，金光一闪，大喊一声：“海纳千山”！\n\n" NOR,
                me, target );

        if( !target->is_killing(me) ) target->kill_ob(me);

        sp = me->query_skill("force") + me->query_skill("dodge") + me->query("kar");
        dp = target->query_skill("force") + target->query_skill("dodge") - me->query("kar");

        me->set_temp("sucked", 1);              

        if( random(sp*2) > random(dp) )
        {
        tell_object(target, HIR "你猛觉全身如针刺般剧痛，神志迷困，头脑中一片空白！\n" NOR);
     tell_object(me, HIG "你觉得" + target->name() + "的法力自手掌源源不绝地流入你的身体。\n" NOR);

                target->add("mana", -1*(int)me->query_skill("yijinjing", 1) );
                me->add("mana", (int)me->query_skill("yijinjing", 1) );

                if( target->query("combat_exp") >= me->query("combat_exp") ) {          
                        if( (int)me->query("potential") - (int)me->query("learned_points") < 100 )
                                me->add("potential", 1);
                        me->add("combat_exp", 1);
                }

                me->start_busy(random(3));
                target->start_busy(random(3));
                 me->add("force", -300);

                call_out("del_sucked", 2, me);
        }
        else
        {       
                message_vision(HIY "可是$p看破了$P的企图，机灵地闪了开去。\n" NOR, me, target);
                me->start_busy(2);
                call_out("del_sucked", 4, me);
        }

        return 1;
}

void del_sucked(object me)
{
        if ( me->query_temp("sucked"))
        me->delete_temp("sucked");
}
