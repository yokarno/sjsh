//onesword.c by angell

#include <ansi.h>
#include <skill.h>

inherit SSERVER;

int perform(object me, object target)
{
        int i,j,k,damage;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁使用「返身一剑」？\n");

        if(!me->is_fighting())
                return notify_fail("你们没有在打架！\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("你的内力太差。\n");

        if((int)me->query("force") < 300 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 100 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
        if((int)me->query_skill("qixiu-jian", 1) < 100)
                return notify_fail("你的七修剑等级不够，不能使用这一招！\n");
        i=(int)me->query("combat_exp");
       j=(int)target->query("combat_exp");
             k=(int)me->query_skill("rake");
        
        me->delete("env/brief_message");
        target->delete("env/brief_message");
message_vision(HIB"\n$N忽然坐势欲走，$n刚要追来，孰料$N转身就是一剑。"NOR,me,target);
        if (random(i+j)>j) {
            damage=k/2+random(k);
        target->receive_damage("kee",damage);
       target->receive_wound("kee",damage/4);
             if (k>200) k=200;
target->apply_condition("zhushang",
(int)target->query_condition("zhushang")+1+k/50);
                COMBAT_D->report_status(target);
message_vision(HIR"\n$n一个躲闪不及，身上留下了几个深可见骨的血窟窿，鲜血如泉喷出！\n"NOR,me,target);
        }
else {
 message_vision(HIY"\n$n身子一闪，躲开了这突如其来的一击！\n"NOR,me,target);
}     
me->receive_damage("sen", 50);
        me->add("force", -200);
        me->receive_damage("kee", 30);
 if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
    me->start_busy(2+random(1));
        return 1;
}
