// fy-sword.c
inherit SKILL;
#include <ansi.h>
mapping *action = ({
        ([      "action":
"$N使出一招"+BLINK""+HIC"「翔尾闪」"NOR",手中的$w画了一道圆弧，向$n的$l刺来",
                "dodge":                -50,
                "damage":               50,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N左手轻轻拍出一掌，右手中的$w使出一招"+BLINK""+HIW"「无明剑」"NOR",斩向$n的$l",
                "dodge":                -10,
                "damage":               70,
                "damage_type":  "割伤"
        ]),
        ([      "action":
"$N使出一招"+BLINK""+HIB"「虚空杀」"NOR",身形婉如流水，手中$w从天而降，斩向$n的$l",
                "dodge":                -50,
                "damage":               40,
                "damage_type":  "割伤"
        ]),
        ([      "action":
"$N使出一式的"+BLINK""+MAG"「疾空杀」"NOR",对准$n的$l刺出一剑",
                "dodge":                -20,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N将手中$w连晃几个虚招，一招"+BLINK""+RED"「散华剑」"NOR"向$n刺去",
                "dodge":                -60,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N双手握剑，使出一招"+BLINK""+HIR"「天地斩」"NOR"劈向$n的$l",
                "dodge":                -100,
                "damage":               40,
                "damage_type":  "割伤"
        ]),
        ([      "action":
"$N手中剑轻轻一晃，$w化为一道电光，使出"+BLINK""+BLU"「劫炎剑」"NOR"刺向$n的$l",
                "dodge":                -10,
                "damage":               100,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练天然理心流。\n");
          if(me->query("family/master_id") != "master zhaitengyi" &&  me->query("family/master_id") != "master zongsi")
                return notify_fail("你按着所学练习了一遍天然理心流，但似乎总掌握不到剑术的要领。\n");


        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return  notify_fail("你的内力或气不够，没有办法练习天然理心流。\n"
);
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按著所学练了一遍天然理心流。\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("swordman") + "/lixin-sword/" + action;
}

int effective_level() { return 9;}

string *parry_msg = ({
        "$n以功代守，剑直向$N刺去。$N吓的连退数步，撤回了攻势。\n",
        "$n使出一招「步月」，将全身躲在了剑幕中。\n",
});

string *unarmed_parry_msg = ({
        "$n将手中的剑连续刺出，挡住$N的全部攻势。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

