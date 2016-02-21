// by repoo
#include <ansi.h>
inherit F_DBASE;
inherit SSERVER;
void remove_effect(object me, object target, int amount);
int perform(object me, object target)
{
        int skill_whip, skill_dodge, dodge_amount,attack_amount;
        object weapon,tweapon;
        if( me->query_skill_mapped("dodge") != "sevensteps" )
                return notify_fail("你还没有施展七星步法呢。\n");
        skill_dodge = me->query_skill("dodge");            
        if (skill_dodge<100) return notify_fail("你轻功还不够高明。\n");
        if (me->query_skill_mapped("force")!="zixia-shengong")
                return notify_fail("『凤翔』必须配合紫霞神功才能使用。\n");
        skill_whip=me->query_skill("force");        
        if (skill_whip<100) return notify_fail("你的内功不够纯熟。\n");
        skill_whip=me->query_skill("whip");
        if (skill_whip<100) 
        return notify_fail("你的鞭术太差劲了。\n"); 
        if( (int)me->query("force") < 50 )      
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") )
                return notify_fail("你已经在运功中了。\n");
        if( (int)me->query_temp("no_fengxiang") )
                return notify_fail("你实在太累了，没法展开七星步法。\n");
          me->add("force", -150);
        message_vision(
        RED"$N跨后一步，脚尖在地上轻轻的一点，犹如一条"+HIM"凤凰"+HIW"在翩翩起舞。\n" NOR, me);
        attack_amount=skill_whip*random(6)*3/20;
        dodge_amount=skill_dodge*(5+random(6))*2/10; 
        me->add_temp("apply/attack", attack_amount);  
        me->add_temp("apply/dodge",dodge_amount); 
                 
        me->set_temp("powerup", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", 
           me, dodge_amount,attack_amount:), skill_whip/5);
         return 1;
}
void remove_effect(object me, int dodge_amount,int attack_amount)
{
        me->add_temp("apply/dodge", -dodge_amount);
        me->add_temp("apply/attack", -attack_amount);
        me->delete_temp("powerup");
        me->set_temp("no_wanqian",1);
        call_out("wanqian_ok",100+random(100),me);
        message_vision(HIM"$N一声轻啸,放慢脚步。\n"NOR,me);
}
void fengxiang_ok(object me)
{ if (!me) return;
      me->delete_temp("no_fengxiang");
}         
