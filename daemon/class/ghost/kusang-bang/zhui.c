#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
string msg;
int extra;
object weapon;
if (extra = me->query_skill("kusang-bang",1)<100) return notify_fail("你的你的哭丧棒法还不够纯熟！\n");
if( !target ) target = offensive_target(me);
if( !target
||      !target->is_character()
||      !me->is_fighting(target) )
return notify_fail("［追命］只能对战斗中的对手使用。\n");
weapon = me->query_temp("weapon");
message_vision(HIY  "\n$N使出哭丧棒法，第一招----小鬼勾魂，手中的"+ weapon->name()+  "闪电般向$n攻出第一棒！" NOR,me,target);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
message_vision(HIC"\n$N第二招——饿鬼索命！"NOR,me,target);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg
);
message_vision(HIC"\n$N第三招——阎王怒斥！"NOR,me,target);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg
);
 me->start_busy(1);
return 1;
}
