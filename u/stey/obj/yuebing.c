#include <ansi.h>                                                                           
//月饼，给新玩家鼓励 
                       
inherit ITEM;          
                                                                                            
int do_eat(string);                                                                         
void init();                                                                                
                                                                                            
void init()                                                                                 
{                                                                                           
  if (!wizardp(this_player())) {                                                            
    set("no_get","你手里一松，月饼从指间滑落！\n");                                       
    set("no_give","这么珍贵的药，哪能随便给人？\n");                                        
    set("no_drop","这么宝贵的药，扔了多可惜呀！\n");                                        
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }                                                                                         
  add_action("do_eat", "eat");                                                              
}                                                                                           
                                                                                            
void create()                                                                               
{                                                                                           
  set_name( HIY "月饼" NOR , ({"yue bing", "bing"}));                                     
  set_weight(90);                                                                           
  if (clonep())                                                                             
    set_default_object(__FILE__);                                                           
  else {                                                                                    
    set("unit", "颗");                                                                      
    set("long", "祝你中秋佳节幸福快乐。\n");                                                
    set("value", 0);                                                                        
    set("drug_type", "补品");                                                               
  }                                                                                         
//  set("is_monitored",1);                                                                  
  setup();                                                                                  
}                                                                                           
                                                                                            
int do_eat(string arg)                                                                      
{                                                                                           
  object me = this_player();                                                                
  if (arg!="cao" && arg!="wangyou cao")   return 0;                                         
                                                                                            
  me->set("eff_sen", (int)me->query("max_sen"));                                            
  me->set("sen", (int)me->query("max_sen"));                                                
  me->set("eff_gin", (int)me->query("max_gin"));                                            
  me->set("gin", (int)me->query("max_gin"));                                                
  me->set("eff_kee", (int)me->query("max_kee"));                                            
  me->set("kee", (int)me->query("max_kee"));                                                
  me->set("mana", (int)me->query("max_mana"));                                              
  me->set("force", (int)me->query("max_force"));                                            
   message_vision(HIG "$N一口把月饼吞了下去，差点就咽死了。                           
\n" NOR, me);                                                                               
  destruct(this_object());                                                                  
  return 1;                                                                                 
}                                                                                           