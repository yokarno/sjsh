
// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{

	if ((!target)||target->query("id")==me->query("id"))
		return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");
	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��˹����ˣ�\n");

        if( (int)me->query_skill("emeiforce",1) < 20 )
		return notify_fail("���������Ϊ������\n");

        if( (int)me->query("max_force") < 500 )
		return notify_fail("���������Ϊ������\n");

        if( (int)me->query("force") < 50)
		return notify_fail("�������������\n");

        if( (int)target->query("kee") < (int)target->query("max_kee") / 5 )
		return notify_fail( target->name() +
                        "�Ѿ����˹��أ����ܲ�����������𵴣�\n");

	message_vision(
		HIY "$N�������������ڹ�������������$n���ģ������ؽ���������$n����....\n\n"
		"���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�\n" NOR,
		me, target );

        target->receive_curing("kee", 10 + (int)me->query_skill("force")/2 );
        target->add("kee", 10 + (int)me->query_skill("force")/3 );
        target->receive_curing("sen", 10 + (int)me->query_skill("force")/2 );
        target->add("sen", 10 + (int)me->query_skill("force")/3 );
        if( (int)target->query("kee") > (int)target->query("eff_kee") ) target->set("kee", (int)target->query("eff_kee"));
        if( (int)target->query("sen") > (int)target->query("eff_sen") ) target->set("sen", (int)target->query("eff_sen"));

        me->add("force", -50);
	return 1;
}
