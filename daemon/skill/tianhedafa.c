// tianhe_dafa
// by Calvin and Leox 共同开发
//版权所有,未经许可不得翻录

inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("spells",1) < 20 )
        return notify_fail("你的法术修为还不够高深，无法学习天河大法。\n");
        return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("tianpeng") + "/tianhedafa/" + spell;
}

string type() { return "magic";} 
