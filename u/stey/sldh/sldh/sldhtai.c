
//   水陆大会发奖台

#include <ansi.h>
inherit ITEM;
inherit F_SAVE;

mapping sldher;
#define sldhdoc "/d/kaifeng/obj/sldhdoc"

void setup()
{
  object env=environment(this_object());
 if(clonep() && env)
   move(env);
  set("no_get", 1);
  restore();
}

void create ()
{
    set_name(HIC"水陆大会发奖台"NOR, ({ "fajiang tai"}) );
    set ("long", "

　这是一个水陆大会发奖台。当水陆大会完成后，玩家可以站到
发奖台(stand)上领取奖品。巫师要了解该发奖台如何使用，请
键入help fajiang。

");
    set("unit","个");
    set("type","misc");
    seteuid(getuid());
    set("no_put",1);
    set("no_get",1);
    set("no_steal",1);
    set("no_give",1);
    set("value",10000);
    setup();
}

string short()
{
 string str;
 str="无限";
 return HIC"水陆大会发奖台"NOR+"(fajiang tai)"+"(目前启动中，"+str+"小时后停止发奖)";
}

string long()
{
 string msg;
 msg="\n这是一个水陆大会发奖台。当水陆大会完成后，玩家可以站到\n";
  msg+="发奖台(stand)上领取奖品。巫师要了解该发奖台如何使用，请";
  msg+="键入help fajiang。\n";
 return msg; 
}

void init ()
{
  object who = this_player();
   add_action("do_stand","stand");
   add_action("do_start","start");
   add_action("do_finish","finish");
   add_action("do_list_sldh","lists");
}

string query_save_file()
{
   return DATA_DIR + "sldh/sldhprt";
}
int can_give(string id)
{
 mapping tmp=([]);
 string *list,*list1;
 int i,j,k,g;   
 if(!sldher)
  return 0;
 list=keys(sldher);
 k=sizeof(list);
 if(k<=0) return 0;
 for(i=0;i<k;i++)
  {
   tmp=sldher[list[i]];
   list1=keys(tmp);
   g=sizeof(list1);
   if(g<=0) continue;
   for(j=0;j<g;j++)
    if(list1[j]==id) return 1;
  }
 return 0;
}

int have_give(string id)
{
 mapping tmp=([]);
 string *list,*list1;
 int i,j,k,g;   
 if(!sldher)
  return 1;
 list=keys(sldher);
 k=sizeof(list);
 if(k<=0) return 1;
 for(i=0;i<k;i++)
  {
   tmp=sldher[list[i]];
   list1=keys(tmp);
   g=sizeof(list1);
   if(g<=0) continue;
   for(j=0;j<g;j++)
    if(list1[j]==id)
       if(tmp[id]["price"]=="Y")
         return 1;
  }
 return 0;
}
int give_promotion(object who)
{
 mapping tmp=([]);
 string *list,*list1,id,msg;
 object doc;
 int i,j,k,g,found,kind,fight;
 int potential,base_qn,step_qn;
 
 if(!sldher)
  return 0;
 list=keys(sldher);
 k=sizeof(list);
 found=0;
 id=who->query("id");
 if(k<=0) return 0;
 fight=0;
 for(i=0;i<k;i++)
  {
   tmp=sldher[list[i]];
   list1=keys(tmp);
   g=sizeof(list1);
   if(g<=0) continue;
   for(j=0;j<g;j++)
    if(list1[j]==id) {
     if(tmp[id]["winner"]>0) set("first/"+id,1);
     if(tmp[id]["fight"]=="Y") fight=1;
     
      tmp[id]["price"]="Y";
      sldher[list[i]]=tmp;
      save();
      doc=new(sldhdoc);
     if(doc) {
       doc->set("file_name",query("filename"));
       doc->restore();  
       doc->set("joiner",sldher);
       doc->save();
       destruct(doc);
      }
      found=1;
      sscanf(list[i],"%d",kind);
     break; 
    }
   if(found) break; 
  }    


 //end match id 
 base_qn=query("base_qn");
 step_qn=query("step_qn");
 i=query("value_give");//给多少法力和内力
 //设置基本qn和步进潜能。
 if(base_qn<5000) base_qn=10000;
 if(step_qn<1000) base_qn=5000;
  if(found)
  {
    potential=base_qn+(kind-1)*step_qn;
    if(query("first/"+id))
    {
     potential=potential*2-potential/2;
     j=i-(kind-1)*10;
     if(j<20) j=20;
    } else if(!fight) potential=potential/2;
   } else return 0;

 msg="第"+chinese_number(query("sldh_num"))+"届水陆大会"+chinese_number(kind)+"组";
 
 if(query("first/"+id))
  msg+="冠军得主　"+who->query("name")+"("+id+")";
 else if(fight) msg+="鼓励比赛奖得主　"+who->query("name")+"("+id+")";
      else msg+="鼓励报名奖得主　"+who->query("name")+"("+id+")";

 msg+="获得"+sprintf("%d",potential)+"点潜能";
 if(query("first/"+id)) {
        msg+="加"+sprintf("%d点法力%d点内力奖励。",j,j);
        who->add("potential",potential); 
        who->add("max_mana",j);
        who->add("max_force",j);
 }      
 else {
        msg+="奖励。\n";
        who->add("potential",potential); 
 }      
 msg=HIC+msg+NOR;
 CHANNEL_D->do_channel(this_object(), "sldh", msg);
 save();
 who->save();
 return 1; 
}
        
string get_first()
{

 mapping tmp=([]);
 string *list,*list1;
 int i,j,k,g;   
 string msg;
 msg="";
 if(!sldher)
  return "没有冠军。\n";
 list=keys(sldher);
 k=sizeof(list);
 if(k<=0) return "没有冠军数据。\n";
 msg="";
 for(i=0;i<k;i++)
  {
   tmp=sldher[list[i]];
   list1=keys(tmp);
   g=sizeof(list1);
   if(g<=0) continue;
   for(j=0;j<g;j++)
    if(tmp[list1[j]]["winnum"]>0) {
      set("first/"+list1[j],1);
      msg+="第"+list[i]+"组"+list1[j]+"\n";
    }  
  }
if(msg!="")  
 msg="本届冠军得主为：\n"+msg;   
else msg="本届冠军尚未产生。\n"; 
 return msg;
}

int notify_failed(object ob,string str)
{
 if(ob)
  tell_object(ob,str);
 return 1;
}


int do_stand(string arg)
{
 object who=this_player();
 string id;
 if(!arg) 
  return notify_failed(who,"你要站起来？\n");
 if(arg!="fajiang tai" && arg!="发奖台")
  return notify_failed(who,"你要站到什么地方上去？\n");  
 if(!query("start"))

  return notify_failed(who,"对不起，现在还没开始发奖？\n");  
 if(!query("init"))
  return notify_failed(who,"对不起，现在还没开始发奖？\n");  
 if(!query("finish"))
  return notify_failed(who,"对不起，现在还没开始发奖？\n");  
  
 id=who->query("id");
 if(!can_give(id))
  return notify_failed(who,"对不起，你不能获得水陆大会奖励。\n");
 if(have_give(id))
  return notify_failed(who,"你已经拿过水陆大会奖励，请不要再来了。 \n");
 if(!give_promotion(who))
  return notify_failed(who,"你不能获得奖励，原因尚未知，如果觉得不公正，请向巫师协会投诉。\n");
 return 1;
}
//输入冠军
private void input_first(string arg,object me,object who)
{
 string first;
 int i;
 if(!arg) {
    tell_object(who,"\n请重新输入数据(y退出)：");
    input_to("input_first",0,me,who);
    return;             
 }      

 if(arg=="y") return;
 if(sscanf(arg,"%d %s",i,first)!=2) {
    tell_object(who,"\n请重新输入数据(y退出)：");
    input_to("input_first",0,me,who);
    return;             
 }
 set("first/"+first,1);
 save();
 return;
}
//输入潜能和法力内力
private void input_qn(string arg,object me,object who)
{
 int base_qn,step_qn,value_give;
 if(sscanf(arg,"%d %d %d",base_qn,step_qn,value_give)!=3)
 {
    tell_object(who,"\n请重新输入基本潜能，倍进潜能，法力和内力值(0 0 0退出)：");
    input_to("input_qn",0,me,who);
    return;             
 }
 
 if(base_qn==0) return;
 if(base_qn<1000||step_qn<1000||value_give<30) {
    tell_object(who,"\n太小气了吧？请重新输入基本潜能，倍进潜能，法力和内力值(0 0 0退出)：");
    input_to("input_qn",0,me,who);
    return;             
 }      
 if(base_qn>20000||step_qn>15000||value_give>100) {
    tell_object(who,"\n太多了吧？请重新输入基本潜能，倍进潜能，法力和内力值(0 0 0退出)：");
    input_to("input_qn",0,me,who);
    return;             
 }
 set("base_qn",base_qn);
 set("step_qn",step_qn);
 set("value_give",value_give);

 save();
 tell_object(who,"好，输入发奖数值完成，下一步输入冠军ID。\n");
 tell_object(who,get_first());
 tell_object(who,"上面数据正确吗？如果正确请按y,如果不正确请输入组别和冠军ID。\n例:1 smile。\n");
 tell_object(who,"请输入数据：");
 input_to("input_first",0,me,who);
 return; 
}

//输入届数
private int input_num(string sldhnum,object me,object who)

{
  object doc;
  int i;
  string filename;
  
  if(sscanf(sldhnum,"%d",i)!=1) {
    tell_object(who,"\n输入的水陆大会届数必须是数字，请重新输入(0退出)：");
    input_to("input_num",0,me,who);
    return 0;    
   }    
  if(i==0) return 0;
  
  filename=sprintf("%s%d%s",DATA_DIR + "sldh/joiner",i,".o");
  if(file_size(filename)<0) {
     tell_object(who,"\n没有这样的水陆大会届数，请重新输入(0退出)：");
     input_to("input_num",0,me,who);
     return 0;
   } 
  doc=new(sldhdoc);
  if(!doc)
    return notify_failed(who,"\n生成水陆大会报名表对象失败，可能是文件不存在，退出设置。\n");
      
  filename=sprintf("%s%d",DATA_DIR+"sldh/joiner",i);
  doc->set("file_name",filename);
  doc->restore();
  sldher=doc->query("joiner");
  if(!sldher) {
    destruct(doc);
    return notify_failed(who,"获取水陆大会报名数据失败，无法进行发奖。\n");     
   } 
  set("init",1);
  set("sldh_num",i);
  set("filename",filename);
  save();
  destruct(doc);
  tell_object(who,"输入水陆大会届数成功，请输入发奖数据。\n输入格式(基本潜能 倍进潜能 法力和内力 例:10000 5000 50\n");
  tell_object(who,"缺省的数据为"+sprintf("%d %d %d\n",query("base_qn"),query("step_qn"),query("value_give")));
  tell_object(who,"请输入发奖数据(0 0 0退出)：");
  input_to("input_qn",0,me,who);
  return 1;
}

//开始发奖
int do_start(string arg)
{
  object who=this_player();
  if(!arg)
   return notify_failed(who,"你要启动什么？\n");
  if(wiz_level(who)<1)
   return notify_failed(who,"你无权启动发奖台。\n"); 
  if(arg!="发奖"&&arg!="promotion")
   return notify_failed(who,"要启动发奖台，请用start 发奖。\n");
  set("start",1);
  delete("init");
  delete("first");
  delete("finish");
  save();
  tell_object(who,"好，现在进入发奖台设置工作，请输入正确的水陆大会的届数：");
  input_to("input_num",0,this_object(),who);
  tell_object(who,"好，发奖台设置完成，请输入finish setting以便确认发奖。\n如有错，请用start 发奖重新设置。\n");
  return 1;
}

int do_list_sldh(string arg)
{
 return 1;
}

int do_finish(string arg)
{
  object who=this_player();
  if(!arg)
   return notify_failed(who,"你要设定什么？\n");
  if(wiz_level(who)<1)
   return notify_failed(who,"你无权关闭水陆大会发奖台设定。\n"); 
  if(arg!="setting" && arg!="发奖台设定")
   return notify_failed(who,"要完成设定，请用finish setting\n");
  if(!query("start"))
   return notify_failed(who,"你还没启动发奖台呢。\n");
  if(!query("init"))
   return notify_failed(who,"你还没设定水陆大会届数呢。\n");
  set("finish",1);
  save();  
  tell_object(who,"发奖台设置完成，请玩家stand fajiang tai就可以给他们发奖了。\n");
 return 1;
}
