//By angell 2001/5/15

#include <ansi.h>

int main(object me, string str)
{   
     string output;    
     seteuid(getuid(me)); 
     me->add("sen",-20); 
     me->start_busy(2);

    output = HIR"★ "HIW"三界神化"HIR" ★"HIG" 使命榜\n" NOR; 
    output += ""HIW"─────────────────────────────────────\n"NOR"";   
    output += TASK_D->dyn_quest_list();  
    output += ""HIW"────────────────────────────"HIG" 三界神化"HIW" ────\n\n"NOR""; 
    
     me->start_more(output);   
     return 1;
}

int help(object me)
{  
      write(@HELP

指令格式: task
这个指令是用来得知目前的所有使命.
为了减轻系统负担，不能连续用job，而且每用一次要掉20的精神。

HELP); 
       return 1;
}
