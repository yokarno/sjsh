// bagua.c ������ ����Ʈ(piao)

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        int bagua, ap, dp;
        if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("��"HIC"������"NOR"��ֻ����ս���в���ʹ�á�\n");
        if( (int)me->query_skill("tianjijue", 1) < 150 ) 
                return notify_fail("����������Ϊ�������ʹ������һ�У�\n");
        if( (int)me->query_skill("spells", 1) < 150 ) 
                return notify_fail("��ķ�����Ϊ�������ʹ������һ�У�\n");
	if( (int)me->query("mana") < 400 )
		return notify_fail("��ķ��������ˣ�\n");
        if( (int)me->query("max_mana") < 1960 )
                return notify_fail("��ķ������㣡\n");
	if( (int)me->query("sen") < (int)me->query("max_sen")/2 )
		return notify_fail("������ͷ�Բ����ѣ�����ʹ�ó��������󡹣�\n");

               message_vision(HIW"$N���˼���������һ�������ҡ�"HIY"������"HIW"��!ֻ��һ�Ű���£��$n��\n"NOR,me, target);
	ap = me->query_skill("spells");
	ap = ap * ap * ap /10 ;
	ap += (int)me->query("daoxing");
	ap = 3*ap; 
	dp = target->query("daoxing");
	if( random(ap + dp) < dp ) bagua = 0;
	ap = (int)me->query("max_mana");
	dp = (int)target->query("max_mana");
	if( ap < random(dp) ) bagua = 0;

	if( bagua == 0 )
	{
       message_vision(HIW"\n������ʧ֮��$n���Ƶ��˰������С�\n"NOR, me, target);
                target->move("/d/youxia/bagua/bagua0.c");
                target->start_busy(2);
                me->start_busy(1);
                me->add("mana",-500);
                me->add("sen",-100);

	}
	else
	{
                message_vision(HIR"$N�ġ�������ʧ����!"NOR"\n"NOR,me, target);
                me->start_busy(2);
                me->add("mana",-300);
                me->add("sen",-100);
	}

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
                me->kill_ob(target);
        }
	return 1;
}
