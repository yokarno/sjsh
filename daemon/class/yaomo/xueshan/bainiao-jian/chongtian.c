//By exp
#include <condition.h>
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string str;
        string msg;
        int extra;
        object weapon;
        extra = me->query_skill("bainiao-jian",1);
        if ( extra < 260) return notify_fail("你的百鸟剑法还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［剑气冲天］只能对战斗中的对手使用。\n");
if(me->query("family/family_name")!="大雪山")
    return notify_fail("你从哪偷学来的?\n");
if( (int)me->query_skill("sword", 1) < 280 )
    return notify_fail("你的基本剑法太低！\n");
        if( (int)me->query_skill("force", 1) < 250 )
    return notify_fail("你的内功不够娴熟，使不出［剑气冲天］！\n");
if( (int)me->query("max_force") < 2500 )
    return notify_fail("你现在内力修为不足，使不出［剑气冲天］！\n");    
 if( (int)me->query("force") < 1000 )
         return notify_fail("你现在内力不足，使不出［剑气冲天］！\n");         
    weapon = me->query_temp("weapon");
       me->add_temp("apply/damage",extra*5);
        message_vision(HIW"$N手中的"+ weapon->name()+  "一出鞘，就化做一道光华击向$n，一道弧形的光华：灿烂、辉煌、美丽。\n" + HIG"光华在闪动、变幻、高高在上，轻云飘忽，$n只觉得这道光华彷佛就在自己眉睫
间，却又不能确定它在那里？它的变化，几乎已超越了人类能力的极限，几乎已令人无法置信。"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       message_vision(HIY"可是它确实在那里，而且无处不在。可是就在$n已确定它存在时，它忽然又不见
了。"NOR,me,target);
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(WHT"又奇迹般忽然出现，又奇迹般忽然消失。"NOR,me,target);
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       message_vision(HIR"所有的动作和变化，都已在一刹那间完成，终止。就像是流星，却又像是闪电，却又比
流星和闪电更接近奇迹。因为催动这变化的力量，是由$N发出来的。"NOR,me,target);
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       me->add_temp("apply/damage",-extra*5);
           me->start_busy(1+random(1));
        if (target->query("eff_kee")<0 || (!living(target) && target->query("kee")<0)) 
{str=HIW+target->name()+HIM"被"HIG+me->name()+HIM"的百鸟剑之绝学"+HIY+"「剑气冲天」"+HIM+"杀死了，听说"+target->name()+"尸体上残留下了无数道剑痕！";
message("channel:rumor",HIM"【"+HIR+"江湖传闻"+HIM+"】某人："+str+"\n"NOR,users());
}

        return 1;
}


