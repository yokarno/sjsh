
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
                return notify_fail("「密剑·焰灵」只能对战斗中的对手使用。\n");
		if(me->query("family/family_name")!="剑客联盟")
 return notify_fail("“密剑·焰灵”只有剑客联盟弟子才可以使用！\n");
    if( (int)me->query_skill("doom-sword",1) < 200)
    return notify_fail("你的杀人剑法还不够纯熟!\n");
    if( (int)me->query("force") < 800)
    return notify_fail("你的内力不够了!\n");

      msg = RED
"\n$N长剑挥划，带着撕裂空气的速度与力量，向$n的胸口急刺而去。
因摩擦产生的高温更是将剑周围的空气燃烧起来。\n" NOR;msg += RED""+BLINK"
┏━━━━━━━┓
┃  密剑·焰灵  ┃
┗━━━━━━━┛" NOR;
myexp= me->query("combat_exp") /10000;
yourexp=target->query("combat_exp")/10000;
myskill=me->query_skill("sword");
yourskill=target->query_skill("parry");
ap=myexp+myskill;
dp=yourexp+yourskill;
if (random(ap+dp)>dp)
{
msg += RED

"\n\n$n一个躲闪不及，胸口被长剑刺个正着，剑上的炽热气息迅速在
$n身上散发开来，让$n如同置身炼狱!!\n" NOR;
damage=(int) target->query("max_kee")/2;
             target->receive_wound("kee",damage,me);
             target->apply_condition("fire",6);
             me->add("force",-500);
             me->start_busy(3);
} 
    else {
        msg += HIY "\n\n$n左躲右闪，终于避开了$P的这一击！！\n" NOR;
          me->start_busy(2+random(1));
        me->add("force",-300);
        }
//        if( wizardp(me) && (string)me->query("env/combat")=="verbose" )                       
//            tell_object(me, sprintf( GRN "AP：%d，DP：%d，伤害力：%d\n" NOR,ap/100, dp/100, damage));

message_vision(msg, me, target);
return 1;
}

