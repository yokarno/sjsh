// shout.c
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        if( !wizardp(me) )
                return notify_fail("目前暂不开放玩家 shout。\n");
        if (!arg) return notify_fail("你想要大叫什么？\n");
         shout(BLINK HIM + me->name() +  "严重警告：" + arg + "\n" NOR);
          write(BLINK HIM "你提出严重警告："+ arg + "\n" NOR);
        return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : jinggao <讯息>
 
这个指令让你将 <讯息> 传送出去, 所有正在游戏中的人都
会听见你的话.
 
see also : tune
HELP
    );
    return 1;
}
 


