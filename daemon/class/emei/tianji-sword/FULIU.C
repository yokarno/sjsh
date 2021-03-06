//清风拂柳
// huiliu for emei by piao 2001 10-1

#include <ansi.h>
 
inherit F_DBASE;
inherit SSERVER;
 
void remove_effect(object me, object target, int amount);
 
int perform(object me, object target)
{
        int skill_sword, skill_dodge, dodge_amount,attack_amount;

        if( me->query_skill_mapped("dodge") != "zhutian-bu" )
                return notify_fail("「"HIC"清风拂柳"NOR"」必须配合诸天化身步才能使用。\n");
        skill_dodge=me->query_skill("dodge");        
        if (skill_dodge<100) return notify_fail("你轻功修为还不够高深，无法施展「"HIC"清风拂柳"NOR"」。\n");
        if (me->query_skill_mapped("force")!="emeiforce")
                return notify_fail("「"HIC"清风拂柳"NOR"」必须配合峨嵋心法才能使用。\n");
        skill_sword=me->query_skill("force");        
        if (skill_sword<100) return notify_fail("你的内功心法修为还不够高深，无法施展「"HIC"清风拂柳"NOR"」。\n");
        skill_sword=me->query_skill("sword");
        if (skill_sword<100) 
           return notify_fail("你的基本剑术修为还不够高深，无法施展「"HIC"清风拂柳"NOR"」。\n");
        if( (int)me->query("force") < 50 )      
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") )
                return notify_fail("你已经在运功中了。\n");
        
        me->add("force", -50);
        message_vision(HIW"$N运起诸天化身步，运起轻功，步走乾坤。只见$N使出一招回风拂柳剑中的「"HIC"清风拂柳"HIW"」！\n" NOR, me);
 
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
        message_vision(HIW"$N渐感气力不支，不得不放慢脚步，放缓剑招。\n"NOR,me);
}

