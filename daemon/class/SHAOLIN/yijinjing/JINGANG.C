//jiz
#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( target != me ) 
                return notify_fail(HIY"你只能用易筋经神功保护自己。\n"NOR);

        if( (int)me->query("force") < 100 )     
                return notify_fail(HIY"你的内力不够。无法运用金刚罩！\n"NOR);
	if( (int)me->query("kee") < 50 )
                return notify_fail(HIY"你的气血不足。无法运用金刚罩！\n"NOR);
	if( (int)me->query("sen") < 50 )
                return notify_fail(HIY"你的精神不足。无法运用金刚罩！\n"NOR);
        if( (int)me->query_temp("powerup") ) 
                return notify_fail(HIY"你已经在运功中了。\n"NOR);

        skill = me->query_skill("force");

        me->add("force", -100);
        me->receive_damage("kee", 30);
	me->receive_damage("sen", 30);

        message_vision(
         HIY"$N微一凝神，运起易筋经神功,顿时身上出现了金光，正是少林正宗的金刚罩!\n" NOR, me);

        me->add_temp("apply/armor", skill/3);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/armor", - amount);
        me->delete_temp("powerup");
        tell_object(me, HIY"你的易筋经神功运行一周天完毕，金刚罩渐渐消去了。NOR\n");
	return;
}

