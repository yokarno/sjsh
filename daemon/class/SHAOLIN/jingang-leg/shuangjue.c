// shuangjue.c  掌腿双绝

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

void remove_effect(object me, int a_amount, int d_amount);

inherit SSERVER;
int perform(object me, object target)
{
        string msg;
	 int extra;
	 object weapon;
        extra = me->query_skill("jingang-leg",1);
        
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) || !living(target))
                return notify_fail("「"HIC"掌腿双绝"NOR"」只能在战斗中使用。\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能使用「"HIC"掌腿双绝"NOR"」！\n");

        if (me->query_skill_mapped("force")!="yijinjing")
                return notify_fail("「"HIC"掌腿双绝"NOR"」必须配合易筋经才能使用。\n");

        if( (int)me->query_skill("banruo-zhang", 1) < 1 )
                return notify_fail("「"HIC"掌腿双绝"NOR"」必须配合般若掌才能使用。\n");
        
                if( (int)me->query_skill("unarmed", 1) < 120 )
                return notify_fail("你的基本功不扎实，无法施展「"HIC"掌腿双绝"NOR"」！\n");
                if( (int)me->query_skill("yijinjing", 1) < 120 )
                 return notify_fail("你的易筋经未成，不能使用「"HIC"掌腿双绝"NOR"」！\n");

                if( (int)me->query_skill("jingang-leg", 1) < 120 )
                return notify_fail("你的大力金刚腿不够娴熟，无法施展「"HIC"掌腿双绝"NOR"」。\n");
        if ((int)me->query("max_force") < 1500)
                return notify_fail("你的内力不足，无法施展出「"HIC"掌腿双绝"NOR"」。\n");
        if((int)me->query("force") < 1000 )
                return notify_fail("你的内力不够！\n");
        if( (int)me->query_str() < 20)
                return notify_fail("你的膂力不足，无法发挥「"HIC"掌腿双绝"NOR"」的气势。\n");
        if( (int)me->query_con() < 20)
                return notify_fail("你的根骨欠佳，无法发挥「"HIC"掌腿双绝"NOR"」的气势。\n");

	                 me->add_temp("apply/strength", extra);
                         me->add_temp("apply/attack", extra);

                 msg = HIR "\n$N一声清啸，拳脚齐施，使出少林绝学"HIC"「掌腿双绝」"HIR"迅捷无伦地攻向$n！\n" NOR;
       	         message_vision(msg, me, target);                
message_vision(HIC"$N拳脚齐施，左一拳！\n"NOR,me,target); 
	if (! present(target,environment(me))) return 1;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIC"$N拳脚齐施，右一腿！\n"NOR,me,target); 
        if (! present(target,environment(me))) return 1;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
//--------------------------------------------------------------------

        if( (int)me->query_skill("jingang-leg", 1) > 150 
        && (int)me->query_skill("yijinjing", 1) > 150 ){
message_vision(HIC"$N拳脚齐施，上一拳！\n"NOR,me,target); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIC"$N拳脚齐施，下一腿！\n"NOR,me,target); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        }
//----------------------------------------------------------
        if( (int)me->query_skill("jingang-leg", 1) > 179 
        && (int)me->query_skill("yijinjing", 1) > 179 ){
       message_vision(HIC"$N拳脚齐施，中间再是一腿！\n"NOR,me,target); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

       }
//-----------------------------------------------------------

        me->add_temp("apply/strength", -extra);
        me->add_temp("apply/attack", -extra);
        me->receive_damage("sen", 100+random(100));
         me->add("force", -500);
        me->start_busy(2+random(1));
        return 1;
}
