#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
int myexp, yourexp, myskill, yourskill;
int ap, dp, damage, def;
string msg;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「牙突·无式」只能对战斗中的对手使用。\n");
    if(me->query("family/family_name")!="剑客联盟")
    return notify_fail("“牙突·无式”只有剑客联盟弟子才可以使用！\n");
    if( (int)me->query_skill("lixin-sword",1) < 180)
    return notify_fail("你的天然理心流还不够纯熟!\n");
    if(me->query("swordman/wu_perform")!=1)
    return notify_fail("你还没学会「牙突·无式」！\n");
    if( (int)me->query("force") < 800)
    return notify_fail("你的内力不够了!\n");

msg = HIR
"\n$N身形突然退后，左腿向前微踏一步，剑向前平指，剑尖微向下，左手中指
平贴在剑尖之上，人剑合一，如同闪电般向$n袭去。\n" NOR;
myexp= me->query("combat_exp") /1000;
yourexp=target->query("combat_exp")/1000;
myskill=me->query_skill("sword");
yourskill=target->query_skill("parry");
ap=myexp*myskill;
dp=yourexp*yourskill;
if (random(3*ap)>random(2*dp))
{
msg += HIR
"\n\n$n一个躲闪不及，胸口被刺了个血肉模糊的大洞!!\n" NOR;
damage=(int) target->query("max_kee")/3;
target->receive_wound("kee",damage,me);
target->start_busy(3);
me->add("force",-500);
 } 
else
{
msg += HIY "\n\n$n左躲右闪，终于避开了$P的这一击！！\n" NOR;
me->start_busy(3);
me->add("force",-300);
}
message_vision(msg, me, target);
return 1;
}

