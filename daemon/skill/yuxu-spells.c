inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( 2*(int)me->query_skill("spells") <= (int)me->query_skill("yuxu-spells") )
        return notify_fail("你的法术修为还不够高深，无法学习「玉虚仙法」。\n");
        return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("kunlun") + "/yuxu-spells/"+spell;
}

string type() { return "magic"; } 
