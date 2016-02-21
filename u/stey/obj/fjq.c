// 发奖器
#include <ansi.h>
inherit ITEM;
#define DEBUG 0
mapping sldhwho;

void create ()
{
    set_name("发奖器", ({ "fajiang qi"}) );
    set ("long", @LONG
这是一个供巫师专用发奖器。
指令格式：
        jiangli 玩家的ID 冠军否的标志。
        举例:jiangli angel no1   (表示给冠军angel发奖)
             jiangli angel       (表示给普通玩家发鼓励奖)
        jiangall 奖励所有在线人员。
LONG);
    set("unit","个");
    set("type", "misc");
    setup();
}
void init ()
{
   add_action("do_jiangli","jiangli");
   add_action("do_jiangall","jiangall");
}
void announcing (string str)
{
  if (DEBUG)
  {
    object angel = find_player ("angel");
    if (wizardp(angel))
      tell_object (angel,"  注意发奖器=>"+str);
  }
  else
  {
    object wei = load_object ("/d/kaifeng/npc/wei");
    wei->command_function("sldh "+str);
  }
}
void announce (string str)
{
  string s = str;
  int i, j;
  while ((i = strlen(s)) > 0)
  {
    j = strsrch (s, "\n");
    if (j < 0)
    {
      announcing (s);
      return;
    }  
    announcing (s[0..j]);
    s = s[j+1..i];
  }
}
int do_jiangli(string arg)
{
  object who=this_player();
  object ob=this_object();
  object sldhwho;
  object gold,guo;
  string id,no1s="";
 int i=0,dx=0,no1=0;
    if(!wizardp(who)) {
         tell_object(who,"你没有权限使用这个命令。\n");
         tell_room(environment(who),ob->name()+"腾空而去。\n");
         destruct(ob);
          return 1;
        }
    if(!arg) 
         return notify_fail("你要给谁发奖？\n");
    if(!sscanf(arg,"%s %s",id,no1s)) 
      if(!sscanf(arg,"%s",id))
         return notify_fail("你给的参数好象有点问题，用(look fajiang qi)查看。\n");
    if(no1s=="no1") no1=1;
    sldhwho=find_player(id);
    if(!sldhwho)
         return notify_fail("没找到你说的这个人！\n");
    if(!environment(sldhwho))
         return notify_fail("没找到你说的这个人！\n");
  if(ob->query("sldh/"+id))
   {
    tell_object(who,sldhwho->name()+"已经拿过奖励了，可不能发第二次。\n");
    return 1;
   }
  else {
     dx=sldhwho->query("combat_exp");
    if(dx<10000) {
        tell_object(who,sldhwho->name()+"的武学过低，不能给奖励。\n");
        return 1;}
    if(dx>10000&&dx<=100000) i=0;
    if(dx>100000&&dx<=500000) i=2;
    if(dx>500000&&dx<=1000000) i=4;
    if(dx>1000000&&dx<=1500000) i=6;
    if(dx>1500000) i=8;
       ob->set("sldh/"+sldhwho->query("id"),1);
    tell_object(who,"玩家"+sldhwho->query("name")+"获得奖励：\n");
    tell_object(sldhwho,HIG"你现在获得奖励如下：\n"NOR);
    tell_object(who,"  "+chinese_number(1500*i)+"点潜能！\n");
    tell_object(sldhwho,"  "+chinese_number(1500*i)+"点潜能！\n");
    sldhwho->add("potential",1500*i);
    if(no1) {
        tell_object(who,"  小组第一名再给"+chinese_number(2000*i)+"点潜能！\n");
        tell_object(sldhwho,"  小组第一名再给"+chinese_number(2000*i)+"点潜能！\n");
        sldhwho->add("potential",2000*i);
      }
           tell_object(who,no1==1?"小组第一"+sldhwho->query("name")+"获得奖励。\n":"");
           announce(""+sldhwho->name()+"("+sldhwho->query("id")+")"+"获得奖励。");
     }
    return 1;
}
int do_jiangall()
{
  int j;
  object who=this_player();
  object ob=this_object();
  object sldhwho;
  object *list;
    if(!wizardp(who)) {
         tell_object(who,"你没有权限使用这个命令。\n");
         tell_room(environment(who),ob->name()+"腾空而去。\n");
         destruct(ob);
          return 1;
  }
  list = users();
 j = sizeof(list);
  while (j--)
  {
    sldhwho = list[j];
  who->command_function("jiangli " + sldhwho->query("id") );
    }
  return 1;
}
