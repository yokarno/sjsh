#include <ansi.h>
#include <armor.h>
inherit FINGER;
void create()
{
set_name(HIW"神仙"NOR+HIC"魔戒"NOR, ({ "shenxian mojie" ,"mojie" , "jiezhi"  , "finger" }));
set_weight(0);
set("unit", "只");
set("long", HIW"神仙"NOR+HIC"魔戒"NOR+HIM"，你可以(file)看看有什么可以查。\n"NOR);
if (clonep())
set_default_object(__FILE__);
else
{
set("material", "gold");
set("armor_prop/armor", 65536);
set("armor_prop/dodge", 65536);
set("armor_prop/spells", 65536);
}
set("value", 0);
setup();
}
int query_autoload() { return 1; }
void init()
{
if (!wizardp(this_player()))
{
set("no_get",HIR"不是你的东西，不要乱拿。\n"NOR);
set("no_give",HIR"这么宝贵的宝物，哪能随便给人？\n"NOR);
set("no_drop",HIR"你想扔了他？！你疯了？\n"NOR);
set("no_sell",HIR"凡人哪里知道他的价值？还是自己留着吧。\n"NOR);
}
if(this_player()==environment())
call_out("greeting", 1, this_player());
add_action("do_file","file");
add_action("do_base","base");
add_action("do_watch","watch");
add_action("do_rsg","rsg");
add_action("do_life","life");
}
int do_file(string arg)
{
object who=this_player();
message_vision(
  HIW"$N"NOR+HIY"对天求拜：“神啊！请赐我力量！”\n"NOR+
  HIW"base"NOR+HIC" : "NOR+HIM"查看某玩家的所有基本属性。\n"NOR+
  HIW"watch"NOR+HIC" : "NOR+HIM"查看某玩家的其他状态。\n"NOR+
  HIW"rsg"NOR+HIC" : "NOR+HIM"查看某玩家的吃果数量。\n"NOR+
  HIW"life"NOR+HIC" : "NOR+HIM"查看某玩家的阳寿。\n"NOR
,who);
return 1;
}
int do_base(string arg)
{
object me;
object ob;
mapping my;
string str1;
string str2;
string str3;
string str4;
string str5;
seteuid(geteuid());
me = this_player();
if(!arg) ob = me;
else
if (wizardp(me))
{
ob = present(arg, environment(me));
if (!ob) ob = find_player(arg);
if (!ob) ob = find_living(arg);
if (!ob) return notify_fail("您要察看谁的状态？\n");
}
else return notify_fail("你现在还不能察看别人的状态。\n");
if (my = ob->query_entire_dbase())
{
str1 = "  〖姓名〗  "+ob->name()+"  〖性别〗  "+ob->query("gender")+"  〖ＩＤ〗  "+ob->query("id");
str2 = "  〖容貌〗  "+ob->query("per")+"  〖胆识〗  "+ob->query("cor")+"  〖定力〗  "+ob->query("cps")+"  〖福缘〗  "+ob->query("kar");
str3 = "  〖体格〗  "+ob->query("str")+"  〖筋骨〗  "+ob->query("con")+"  〖悟性〗  "+ob->query("per")+"  〖灵性〗  "+ob->query("spi");
str4 = "  〖ＰＫ〗  "+ob->query("PKS")+"  〖ＮＫ〗  "+ob->query("MKS")+"  〖道路〗  "+ob->query("ziyouchoose");
str5 = "  〖捐钱〗  "+(ob->query("donation")/1000000);
message_vision(HIW"$N要查的信息如下:\n"+str1+"\n"+str2+"\n"+str3+"\n"+str4+str5+"\n"NOR,me);
return 1;
}
}
int do_watch(string arg)
{
object me;
object ob;
mapping my;
string str1;
string str2;
string str3;
seteuid(geteuid());
me = this_player();
if(!arg) ob = me;
else
if (wizardp(me))
{
ob = present(arg, environment(me));
if (!ob) ob = find_player(arg);
if (!ob) ob = find_living(arg);
if (!ob) return notify_fail("您要察看谁的状态？\n");
}
else return notify_fail("你现在还不能察看别人的状态。\n");
if (my = ob->query_entire_dbase())
{
str1 = "  〖气血〗  "+ob->query("eff_kee")+"/"+ob->query("max_kee")+"  〖精神〗  "+ob->query("eff_sen")+"/"+ob->query("max_sen");
str2 = "  〖内力〗  "+ob->query("force")+"/"+ob->query("max_force")+"  〖内力〗  "+ob->query("mana")+"/"+ob->query("max_mana");
str3 = "  〖武学〗  "+ob->query("combat_exp")+"  〖潜能〗  "+ob->query("potential")+"  〖道行〗  "+ob->query("daoxing")+"  〖官职〗  "+ob->query("office_number");
message_vision(HIW"$N要查的信息如下:\n"+str1+str2+"\n"+str3+"\n"NOR,me);
return 1;
}
}
int do_rsg(string arg)
{
object me;
object ob;
mapping my;
seteuid(geteuid());
me = this_player();
if(!arg) ob = me;
else
if (wizardp(me))
{
ob = present(arg, environment(me));
if (!ob) ob = find_player(arg);
if (!ob) ob = find_living(arg);
if (!ob) return notify_fail("您要察看谁的状态？\n");
}
else return notify_fail("你现在还不能察看别人的状态。\n");
my = ob->query_entire_dbase();
message_vision(HIW"$N要查的信息如下:\n  〖吃果〗  已经吃了"+chinese_number(ob->query("rsg_eaten"))+"颗人参果！\n"NOR,me);
return 1;
}
int do_life(string arg)
{
object me;
object ob;
mapping my;
seteuid(geteuid());
me = this_player();
if(!arg) ob = me;
else
if (wizardp(me))
{
ob = present(arg, environment(me));
if (!ob) ob = find_player(arg);
if (!ob) ob = find_living(arg);
if (!ob) return notify_fail("您要察看谁的状态？\n");
}
else return notify_fail("你现在还不能察看别人的状态。\n");
my = ob->query_entire_dbase();
if(ob->query("life/live_forever"))
{
message_vision(HIW"$N要查的信息如下:\n  〖阳寿〗  "+ob->name()+"跳出三界外，不在五行中，已是戡破生死大限了！\n"NOR,me);
return 1;
}
else
message_vision(HIW"$N要查的信息如下:\n  〖阳寿〗  "+ob->name()+"有"+chinese_number(ob->query("life/life_time"))+"年的阳寿！\n"NOR,me);
return 1;
}
void greeting(object who)
{
string str;
if(who->query("id") != "immortal")
{
message_vision(HIR"天上穿来"NOR+HIC"神宫大仙"NOR+HIR"的一阵怒骂：“你这小子敢偷仙家宝物？我要惩罚你！”\n"NOR,who);
who->set("eff_kee",-1);
who->set("max_gin",-1);
who->set("max_sen",-1);
str=who->name();
message("channel:rumor",HIM"【空穴来风】某人："+str+"因私盗仙物，被"NOR+HIW"神仙"NOR+HIC"魔戒"NOR+HIM"分解而死。\n"NOR,users());
}
}
