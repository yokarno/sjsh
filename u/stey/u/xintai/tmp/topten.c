// toptenadd.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string str,*astr;
        int i;
        seteuid(geteuid(me));
        if (!arg||arg=="")
                return notify_fail("指令格式 : topten <类型:rich|quests|pker|nker|pker|exp|dx|force|spells|per|age|task...>\n");
        str=TOPTEN_D->topten_query(arg);
        write(str+"\n");
        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : topten <类型> <玩家ID>
        类型:rich|quests|pker|nker|pker|exp|dx|force|spells|per|age|task...
HELP
    );
    return 1;
}
