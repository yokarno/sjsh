#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra;
	int tmp;
        string str;

	object weapon;
	extra = me->query_skill("feitian-sword",1);
	if ( extra < 180) return notify_fail("你的「飞天御剑流」还不够纯熟！\n");
           if(me->query("family/family_name")!="剑客联盟")
           return notify_fail("“九头龙闪”只有剑客联盟弟子才可以使用！\n");
       if(me->query("swordman/jiulong_perform")!=1)
                return notify_fail("你还没学会「九头龙闪」！\n");
        if( (int)me->query("max_force") < 1500 )      
                return notify_fail("你的内力不够。\n");
        if( (int)me->query("force") < 1000 )      
                return notify_fail("你的内力不足。\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("「九头龙闪」只能对战斗中的对手使用。\n");
	me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",extra);
	weapon = me->query_temp("weapon");
	  message_vision(WHT  "\n\n$N挥出飞天御剑流中的绝天灭地的一式－－－九－头－龙－闪－！！\n\n" NOR,me,target);
        message_vision(YEL  "\n土龙闪！" NOR,me,target);
	  COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision( HIC  "\n水龙闪！" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIW  "\n木龙闪！" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
              if( (int)me->query_skill("feitian-sword", 1) > 200 )   {
        message_vision(HIG  "\n金龙闪！" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIM  "\n雷龙闪！" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR  "\n火龙闪！" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
              }
  
              if( (int)me->query_skill("feitian-sword", 1) > 250 )   {
              message_vision(HIB  "\n狂龙闪！" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(MAG  "\n天龙闪！" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(RED  "\n九头龙闪！" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
              }
                     if (target->query("eff_kee")<0 || !living(target))  
{str=target->name()+"被"+""HIW""+me->name()+""HIM""+"用飞天御剑流奥义『"HIW"九头龙闪"HIM"』杀死了。";
        message("channel:rumor",HIM"【"HIW"空穴来风"HIM"】某人："+str+"\n"NOR,users());;
	               }

       me->add("force", -500);
        me->receive_damage("sen", 100);
       me->start_busy(2+random(2));
       me->add_temp("apply/attack",-extra);
       me->add_temp("apply/damage",-extra);
	return 1;
}
