//来去若无形 wuying.c
// write by piao 2001-10-04

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
void wuying_ok(object); 
inherit SSERVER; 

void remove_effect(object me, int a_amount, int d_amount);

int perform(object me, object target)
{
        object weapon,ob;
        string str;
        int skill;
	int extra;
        string msg;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「"HIW"分身无影"NOR"」只能在战斗中使用。\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
              return notify_fail(" 你使用的武器不对，无法施展「"HIW"分身无影"NOR"」。\n");
        if((int)me->query("sen") < 800 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
        if( (int)me->query_skill("shaolin-sword", 1) < 150 )
                return notify_fail("你的少林无影剑不够娴熟，无法施展「"HIW"分身无影"NOR"」。\n");
        if( (int)me->query_skill("shaolin-shenfa", 1) < 150 )
                return notify_fail("你的少林身法不够娴熟，无法施展「"HIW"分身无影"NOR"」。\n");
        if( (int)me->query_skill("yijinjing", 1) < 150 )
                return notify_fail("你的易筋经不够娴熟，无法施展「"HIW"分身无影"NOR"」。\n");
        if( (int)me->query("force") < 800  ) 
                return notify_fail("你的内力不够。\n");
        if( (int)me->query("max_force") < 2500  ) 
                return notify_fail("你的内力不足，无法施展「"HIW"分身无影"NOR"」。\n");
        if((int)me->query("combat_exp") < 1000000 )
                return notify_fail("你武学经验不够，领悟不到「"HIW"分身无影"NOR"」！\n");
//-------------------------------------------------------------------
        skill = me->query_skill("shaolin-sword");
	extra = me->query_skill("shaolin-sword",1) / 10;
	extra += me->query_skill("shaolin-sword",1) /10;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);

        msg = HIC "\n$N身行突变，一招"HIW"「分身无影」"HIC"瞬间犹如分出无数身影闪电般的向$n攻去！\n"NOR;
        message_vision(msg, me, target);
        me->set_temp("QJB_perform", 5); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        me->set_temp("QJB_perform", 6); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        me->set_temp("QJB_perform", 7); 
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

message_vision(HIW"              ┏━━┓  ┏━━┓  ┏━━┓  ┏━━┓  ┏━━┓\n"NOR,me,target); 
message_vision(HIW"              ┃ "HIR"来"HIW" ┃  ┃ "HIY"去"HIW" ┃  ┃ "HIG"若"HIW" ┃  ┃ "HIB"无"HIW" ┃  ┃ "HIM"形"HIW" ┃\n"NOR,me,target); 
message_vision(HIW"              ┗━━┛  ┗━━┛  ┗━━┛  ┗━━┛  ┗━━┛\n"NOR,me,target); 
        me->set_temp("DLB_perform", 8);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("QJB_perform", 9);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

//--------------------------------------------------------------
        if( (int)me->query_skill("shaolin-sword", 1) > 159 ){
message_vision(HIR"      来字决！\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
}
        if( (int)me->query_skill("shaolin-sword", 1) > 169 ){
message_vision(HIY"            去字决！\n"NOR,me,target); 
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
}
        if( (int)me->query_skill("shaolin-sword", 1) > 179 ){
message_vision(HIG"                 若字决！\n"NOR,me,target); 
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
}
        if( (int)me->query_skill("shaolin-sword", 1) > 189 ){
message_vision(HIB"                        无字决！\n"NOR,me,target); 
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
}
        if( (int)me->query_skill("shaolin-sword", 1) > 199 ){
message_vision(HIM"                           形字决！\n"NOR,me,target); 
       
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
}
//-------------------------------------------------------------------
                     if (target->query("eff_kee")<0 || !living(target))
{str=target->name()+"被"+""HIW""+me->name()+""HIM""+"用少林寺的绝招『"HIW"分身无影"HIM"』杀死了。听说尸体上千疮百孔！";
        message("channel:rumor",HIM"【"HIW"空穴来风"HIM"】某人："+str+"\n"NOR,users());
	               }
        me->start_busy(3);
         me->add("force", -150);
//        me->set_temp("no_wuying",1);
        me->receive_damage("sen", 50+random(50));
        call_out("wuying_ok",10+random(10),me); 
        me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);

        return 1;
}
void wuying_ok(object me)
{ if (!me) return; 
      me->delete_temp("no_wuying"); 
}          

