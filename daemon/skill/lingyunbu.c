#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
"$n身形微晃，有惊无险地避开了$N这一招。\n"
"$n身可是你一个"+BLINK""+HIM"「凌空几片飞霞」"NOR"，长袖翻飞，躲过$N这一招。\n",
"但是$n身形飘忽，轻轻一纵，早已避开。\n",
"只见$n身子向后一翻，一招"+BLINK""+HIR"「别是一般风味」"NOR"，后荡而起，掠向一旁。\n",
"$n身随意转，倏地往一旁挪开了三尺，避过了这一招。\n",
"$n一招"+BLINK""+HIC"「清水池边明月」"NOR"，$N只觉眼前一花，不见了$n的身影。\n",
"可是$n侧身一让，$N这一招扑了个空。\n",
"$n一招"+BLINK""+HIG"「绿柳堤畔桃花」"NOR"，身形微晃，有惊无险地避开了$N这一招。\n",
"却见$n足不点地，往旁窜开数尺，躲了开去。\n",
});

int valid_enable(string usage)
{
	return (usage=="dodge");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 0 )
		return notify_fail("你的内力不够，没有办法练凌云步。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的气或内力不够，不能练凌云步。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}

