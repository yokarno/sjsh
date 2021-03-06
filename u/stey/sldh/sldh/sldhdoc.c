// /d/kaifeng/obj/sldhdoc.c
//使用该名单可以轻松设置报名者的状态信息。
#include <ansi.h>

inherit ITEM;
inherit F_SAVE;

#define DEBUG 0
#define BAOMINGSHI "/d/kaifeng/npc/baomingshi"
#define ZHONGLOU   "/d/city/zhonglou"
#define WEI        "/d/kaifeng/npc/wei"
#define SLDHGROUND "/d/kaifeng/ground"

private string listone(int num);
private string list(string arg);

void create()
{
        set_name("水陆大会报名表", ({ "sldhdoc" }));
        set("long","
这是水陆大会报名表清单，请巫师使用help sldhdoc来查看
帮助信息。\n");        
        if (clonep()) {
          set_default_object(__FILE__);

          set("unit","张");
          set("weight",3000);
         }       
        setup();
}

string query_save_file()
{
  return this_object()->query("file_name");
}

int do_help(string arg)
{
 object who=this_player();
 string msg;
 if(!who) return 0;
 if(arg!="sldhdoc") return 0;
  msg="\n水陆大会报名表主要是为巫师方便管理水陆大会的进行而写。\n";
 msg+="首先巫师必须使用startreport在长安钟楼呼出报名使，设好\n";
 msg+="配置，开始报名，注意不要有重复的报名使，如果曾发生过报\n";
 msg+="名的情况，必须重新update钟楼。报名使使用方法请到报名使\n";
 msg+="那里，help report查看。然后用init指定水陆大会届数，用\n";
 msg+="lists查看报名者，用set和unset一系列命令进行设置工作，\n";

 msg+="用dofight xxx和xxx1在水陆\n";
 msg+="大会场地进行竞技活动。\n";
 msg+="主要命令及功能：\n";
 msg+="一、产生报名使者，得知水陆大会届数，命令为startreport。\n";
 msg+="二、初始化，命令init，使用方法init [n] n是表示水陆大会届数。\n";
 msg+="三、命令lists，使用方法lists [n] n表示分组或不使用参数显示全部。\n";
 msg+="　　　　第一次设置水陆大会的届数后，以后使用时不指定届数\n";
 msg+="　　　　缺省就用你上次指定的届数。\n";
 msg+="四、各项设置功能，一共有６个设置命令，使用参数都相同，\n";
 msg+="　　[un]set_xxxxx [n] [id] 具体参数意义如下：\n";

 msg+="　　　　  xxxxx为设置类型，n表示组别，id为玩家标识号。\n";
 msg+="　　命令解释如下：\n";
 msg+="　　set_price：　　设置用户为已获过奖励。\n";
 msg+="　　unset_price：　取消用户的获奖状态。\n";
 msg+="　　set_fight：　　设置用户为已比赛。\n";
 msg+="　　unset_fight：　取消用户的比赛状态。\n";

 msg+="　　set_winner：　 设置用户为该组冠军得主。\n";
 msg+="　　unset_winner： 取消用户的冠军称号。\n";
 msg+="五、进行两玩家的竞技活动，命令dofight xxx xxx1，参数为两玩家\n";
 msg+="　　的ID，该命令会自动设置参加过竞技的玩家状态，但本组冠军必\n";
 msg+="　　须由巫师设置。\n";
 msg+="附录：关于颜色的说明，使用lists列表处理亮绿色的玩家为得到奖励的\n";
 msg+="　　白色的为比赛过的，兰色为报名者，黄色为冠军得主。\n\n";
 msg+="\n ２０００年／８月　更新\n";
 tell_object(who,msg);
 return 1; 
}

void init()
{
 add_action("do_start","startreport");
 add_action("do_init","init");
 add_action("do_lists","lists");
 add_action("do_price","set_price");
 add_action("do_fight","set_fight");
 add_action("do_winner","set_winner");
 add_action("do_unwinner","unset_winner");
 add_action("do_unfight","unset_fight");
 add_action("do_unprice","unset_price"); 
 add_action("do_dofight","dofight");
 add_action("do_help","help");
}

int do_start()
{

 object who=this_player();
 object ob;
 object room;
 if(!who)
  return 0;
 if(!wizardp(who))
  return notify_fail(HIG"\n你没有使用这个命令的权限。\n"NOR);
 room=load_object(ZHONGLOU);
if(present("sldh baoming shi",room)) 
 return notify_fail(HIG"\n钟楼处还有一个水陆大会报名使，请先更新钟楼。\n"NOR);
 ob=new(BAOMINGSHI);
 ob->move(ZHONGLOU);
 who->move(ZHONGLOU);
 tell_object(who,HIY"\n现在已经启动水陆大会报名程序，请稍后在这里设置报名\n"+
                 "参数。如果不清楚如何使用请到时help report参看帮助。\n"NOR);
 return 1;
}

int do_init(string arg)

{
 object who=this_player();
 int num;
 if(!who) return 0;
 if(!wizardp(who))
  return notify_fail("你没有使用这个命令的权限。\n");
 
 if(!arg) return notify_fail("请用阿拉伯数字参数设定水陆大会届数。例：init 1表示第一届水陆大会。\n");
 if(sscanf(arg,"%d",num)!=1)
   return notify_fail("请加数字参数来指定第几届水陆大会。\n");
 set("sldh_num",num);
 return 1;      
}

int do_lists(string arg)
{
 object who=this_player();
 int num;
 if(!who) return 0;
 if(!(num=query("sldh_num")))
  return notify_fail("请首先用init设定水陆大会届数。例：init 1表示第一届水陆大会。\n");
 
   set("file_name",DATA_DIR+"sldh/joiner"+sprintf("%d",query("sldh_num")));
   if(file_size(query("file_name")+".o")==-1)
    return notify_fail("没有这届水陆大会，请设定正确的水陆大会届数！\n");
   restore();
   set("sldh_num",num); 

   set("unit","张");
   set("weight",3000);  
   tell_object(who,list(arg));
  return 1;
}

private string listone(int num)
{
 int i;
 string msg,kindstr,str;
 mapping kindlist,joinerlist,typestr; 
 string *list,type;
 
 kindstr=sprintf("%d",num);
 kindlist=([]);
 kindlist=query("kindlist");
 joinerlist=query("joiner");
 typestr=query("typestring");
 type=query("type");
 str="\n";
 if(mapp(kindlist))
  msg="　第"+chinese_number(num)+typestr[type]+"("+HIR+
       chinese_number(kindlist[kindstr]["min_num"])+"岁至"+

       chinese_number(kindlist[kindstr]["max_num"])+"岁"+NOR+")：\n";
 if(mapp(joinerlist)&&mapp(joinerlist[kindstr]))
  {
   list=keys(joinerlist[kindstr]);
   if(!list) msg+="　本组没有玩家参加报名。\n";
   else
   { 
     if(sizeof(list)==0) {
        msg+="　本组没有玩家参加报名。\n";
        return msg;
      } 
     
     for(i=1;i<=sizeof(list);i++) {
       string str1;
       str1=sprintf("%-10s",list[i-1]);
       if((i%7)==0) str1=str1+"\n\n";
       if((i%7)==1) str1="　"+str1;

       if(joinerlist[kindstr][list[i-1]]["winnum"]>0)
         str1=HIY+str1+NOR;  
       else if(joinerlist[kindstr][list[i-1]]["price"]=="Y")
               str1=HIG+str1+NOR;
            else if(joinerlist[kindstr][list[i-1]]["fight"]=="Y")
                  str1=HIW+str1+NOR;
                 else str1=HIC+str1+NOR;
       str+=str1;
      } 
     (i-1)%7!=0?str+="\n\n":str=str;
     msg+=str;
     msg+=HIW+"　总共"+chinese_number(sizeof(list))+"名玩家参加本组报名。"+NOR+"\n";
     if(!query("total_num")) set("total_num",sizeof(list));
     else set("total_num",query("total_num")+sizeof(list));
   }
  }
 else msg+="　本组没有玩家参加报名。\n";
 return msg;
}

private string list(string arg)
{
 int i,num,kinds;
 string msg,str;
 
 num=-1;
 set("total_num",0);
 msg=HIY"第"+chinese_number(query("sldh_num"))+"届水陆大会分组及报名者列表：\n"NOR;
 msg+=HIG"┏————————————————————————————————————————┓"NOR+"\n";

 kinds=query("kinds");
 if(!arg||sscanf(arg,"%d",num)!=1) {
  if(kinds>0)
   for(i=1;i<=kinds;i++) {
    msg+=listone(i);
    if(i!=kinds) 
     msg+=HIG"┡————————————————————————————————————————┩"NOR+"\n";    
   }
 } 
 else if(num!=-1){
     msg+=listone(num);         
 }      
 msg+=HIG"┗————————————————————————————————————————┛"NOR+"\n";       
 str=sprintf("%70s","总共有"+chinese_number(query("total_num"))+"名玩家参加本次水陆大会报名");
 str=HIY+str+NOR+"\n\n";
 msg+=str;
 return msg;
}

int notify_failed(object ob,string str)
{
 if(!ob) return 0;
 tell_object(ob,str);

 return 1; 
}

//查找相应的kind中是否有指定的用户
int user_in_kinds(string id,int kind)
{
 mapping joiner;
 string kindstr;
 int i,kind1;
 string *list;
 object me=this_object();
 
 if(!mapp(me->query("kindlist")))
   return 0;//返回false表示没有发现
 if(!(kind1=me->query("kinds")))
   return 0;//返回false表示没有发现
 if(kind>kind1 || kind<1)
   return 0;//返回false表示没有发现
 kindstr=sprintf("%d",kind);
 joiner=([]);
 joiner=query("joiner");
 if(!mapp(joiner)&&!mapp(joiner[kindstr]))
   return 0;

 list=keys(joiner[kindstr]);  
 for(i=0;i<sizeof(list);i++)
   if(list[i]==id) return 1;//返回true
 return 0;
}

private int set_property(object who,int type,string arg)
{
 string id;     
 int kind;
 mapping joiner=([]);
 string kindstr;
 if(!who) return 0; 
 if(!arg)
   return notify_failed(who,"你要干什么？\n");
 if(!wizardp(who))
   return notify_failed(who,"你不是巫师，无权设置比赛信息。\n");
 if(sscanf(arg,"%d %s",kind,id)!=2)
   return notify_failed(who,"设置参数个数不对。例：set_price 1 smile\n");
 if(!user_in_kinds(id,kind))

   return notify_failed(who,"这个组中没有这个报名者。\n");
 joiner=query("joiner"); 
 kindstr=sprintf("%d",kind);  

 switch(type) {
  //set 
  case 1: joiner[kindstr][id]["price"]="Y";
          save();
          return notify_failed(who,"设置"+sprintf("%d组%s为",kind,id)+"已获奖励。\n"); 
  case 2: joiner[kindstr][id]["fight"]="Y";
          save();
          return notify_failed(who,"设置"+sprintf("%d组%s为",kind,id)+"已比赛。\n"); 
  case 3: joiner[kindstr][id]["winnum"]=1;
          save();
          return notify_failed(who,"设置"+sprintf("%d组%s为",kind,id)+"冠军。\n"); 
  //unset        

  case 4: joiner[kindstr][id]["price"]="N";
          save();
          return notify_failed(who,"取消"+sprintf("%d组%s的",kind,id)+"奖励状态。\n"); 
  case 5: joiner[kindstr][id]["fight"]="N";
          save();
          return notify_failed(who,"取消"+sprintf("%d组%s的",kind,id)+"比赛状态。\n"); 
  case 6: joiner[kindstr][id]["winnum"]=0;
          save();
          return notify_failed(who,"取消"+sprintf("%d组%s的",kind,id)+"冠军称号。\n"); 
  }     
}

int do_price(string arg)
{
  object who=this_player();     
 return set_property(who,1,arg);
}

int do_fight(string arg)
{
  object who=this_player();     
 return set_property(who,2,arg);
}

int do_winner(string arg)
{
  object who=this_player();     
 return set_property(who,3,arg);
}

int do_unprice(string arg)
{
  object who=this_player();     
 return set_property(who,4,arg);
}
int do_unfight(string arg)
{
  object who=this_player();     
 return set_property(who,5,arg);
}

int do_unwinner(string arg)
{
  object who=this_player();     
 return set_property(who,6,arg);
}

void announcing (string str)
{
  if (DEBUG)
  {
    object smile = find_player ("smile");
    if (wizardp(smile))
      tell_object (smile,"水陆大会："+str);
  } else
    {

     object wei = load_object (WEI);
     wei->command_function("chat "+str);
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


//查找出用户相应的组别
int query_user_kinds(object who)
{
 mapping kindlist;
 string kindstr;
 string type;
 int kind,i,num;
 object me=this_object();
 
 if(!who) return 0;
 if(!mapp(me->query("kindlist")))
   return 0;//返回false表示没有发现
 kindlist=me->query("kindlist");
 if(!(kind=me->query("kinds")))
   return 0;//返回false表示没有发现
 type=me->query("type");
 if(type=="1") num=who->query("age");
 else if(type=="2") num=who->query("combat_exp")/1000;
      else return 0;
      
 for(i=1;i<=kind;i++)
  {
   kindstr=sprintf("%d",i);

//玩家在[min_num,max_num]中吗？那就返回这个组别
   if(   num>=kindlist[kindstr]["min_num"] 
      && num<=kindlist[kindstr]["max_num"] )
     return i;//返回组别
  }
 return 0;
}

private void fullstate(object who)
{
 who->delete_temp("apply/id");
 who->delete_temp("apply/name");
 who->delete_temp("apply/short");
 who->delete_temp("apply/long");
 who->set("sen",who->query("max_sen"));
 who->set("eff_sen",who->query("max_sen"));
 who->set("kee",who->query("max_kee"));
 who->set("eff_kee",who->query("max_kee")); 

 who->set("water",who->query("max_water"));
 who->set("food",who->query("max_food"));
 who->set("force",who->query("max_force"));
 who->set("mana",who->query("max_mana"));
 who->delete_temp("no_move");

 who->clear_condition();
 message_vision(HIG"水陆力士给$N吃了一颗还魂丹，$N只觉得精神全恢复了。\n",who);
}

void start_fight(object player1,object player2)
{
 string id1,id2;
 if(!player1 || !player2) return;

 reset_eval_cost(); 
 fullstate(player1);
 fullstate(player2);
 player1->kill_ob(player2);
 player2->kill_ob(player1);
}

int do_dofight(string arg)
{
  object who=this_player();
  object player1,player2;
  string id1,id2;
  int i,j;
  

  if(!who)
   return 0; 
  if(!wizardp(who))
   return notify_fail("你没有使用这个命令的权限。\n");
  if(!query("sldh_num"))
   return notify_fail("请先初始化，然后用lists列表显示一次。\n");
  if(!arg||sscanf(arg,"%s %s",id1,id2)!=2)
   return notify_fail("请指明是哪两个玩家进行战斗，例：dofight smile smile1\n");
  if(!(player1=find_player(id1))) 
   return notify_fail("没有这个玩家："+id1+"\n");
  if(!(player2=find_player(id2)))
   return notify_fail("没有这个玩家："+id2+"\n");
   i=query_user_kinds(player1);
   j=query_user_kinds(player2);
  if(i!=j)
   return notify_fail("这两个玩家不是同一个组别的。\n");
  if(player1->query_temp("netdead"))
   return notify_fail(sprintf("%s(%s)正在断线中，不能参与比赛。\n",player1->query("name"),id1)); 
  if(player2->query_temp("netdead"))
   return notify_fail(sprintf("%s(%s)正在断线中，不能参与比赛。\n",player2->query("name"),id2)); 
  if(!present("wei zheng",environment(who)))
   return notify_fail("魏大人不在场，怎能开始比赛呢？\n");
  if(!environment(who))
   return notify_fail("你在悠悠九天九地无思无虑之地，怎能进行比赛活动？\n");
  if(!environment(who)->query("match_ground"))
   return notify_fail("这里不是水陆大会举行比赛的地方，怎能进行比赛活动？\n");
  //设置fight状态 
  set_property(who,2,sprintf("%d %s",i,id1));
  set_property(who,2,sprintf("%d %s",j,id2));
  message_vision(HIR+sprintf("%s被一只大手凌空抓走了。\n",player1->query("name"))+NOR,who);
  player1->move(SLDHGROUND);
  message_vision(HIR+sprintf("%s被一只大手凌空抓走了。\n",player2->query("name"))+NOR,who);
  player2->move(SLDHGROUND);
  message_vision(HIR+sprintf("%s和%s被一双大手抓了过来。\n",player1->query("name"),player2->query("name"))+NOR,who);
  announce(sprintf("本场比赛由 %s(%s) VS %s(%s)",player1->query("name"),id1,player2->query("name"),id2));
  remove_call_out("start_fight");
  call_out("start_fight",5,player1,player2);
  return 1;
}
