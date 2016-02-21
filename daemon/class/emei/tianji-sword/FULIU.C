//������
// huiliu for emei by piao 2001 10-1

#include <ansi.h>
 
inherit F_DBASE;
inherit SSERVER;
 
void remove_effect(object me, object target, int amount);
 
int perform(object me, object target)
{
        int skill_sword, skill_dodge, dodge_amount,attack_amount;

        if( me->query_skill_mapped("dodge") != "zhutian-bu" )
                return notify_fail("��"HIC"������"NOR"������������컯��������ʹ�á�\n");
        skill_dodge=me->query_skill("dodge");        
        if (skill_dodge<100) return notify_fail("���Ṧ��Ϊ����������޷�ʩչ��"HIC"������"NOR"����\n");
        if (me->query_skill_mapped("force")!="emeiforce")
                return notify_fail("��"HIC"������"NOR"��������϶����ķ�����ʹ�á�\n");
        skill_sword=me->query_skill("force");        
        if (skill_sword<100) return notify_fail("����ڹ��ķ���Ϊ����������޷�ʩչ��"HIC"������"NOR"����\n");
        skill_sword=me->query_skill("sword");
        if (skill_sword<100) 
           return notify_fail("��Ļ���������Ϊ����������޷�ʩչ��"HIC"������"NOR"����\n");
        if( (int)me->query("force") < 50 )      
                return notify_fail("�������������\n");
        if( (int)me->query_temp("powerup") )
                return notify_fail("���Ѿ����˹����ˡ�\n");
        
        me->add("force", -50);
        message_vision(HIW"$N�������컯�����������Ṧ������Ǭ����ֻ��$Nʹ��һ�лط�������еġ�"HIC"������"HIW"����\n" NOR, me);
 
        attack_amount=skill_sword*random(6)/10;
        dodge_amount=skill_dodge*(5+random(6))/10; 
        me->add_temp("apply/attack", -attack_amount);  
        me->add_temp("apply/dodge",dodge_amount);  //trade offense for defense.  
        me->set_temp("powerup", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", 
           me, dodge_amount,attack_amount:), skill_sword/5);
 
         return 1;
}
 
void remove_effect(object me, int dodge_amount,int attack_amount)
{
        me->add_temp("apply/dodge", -dodge_amount);
        me->add_temp("apply/attack", attack_amount);
        me->delete_temp("powerup");
        message_vision(HIW"$N����������֧�����ò������Ų����Ż����С�\n"NOR,me);
}
