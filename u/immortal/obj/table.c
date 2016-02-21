#include <ansi.h>
inherit ITEM;
void create()
{
set_name("书桌", ({ "table" }) );
set_weight(500000);
set("unit", "张");
set("long", "神宫大仙平时用来工作的书桌，上面摆了许多书，你可以(list)看看有什么书可以看。\n");
set("value", 0);
setup();
}
void init()
{
add_action("do_list","list");
add_action("do_base","base");
add_action("do_watch","watch");
add_action("do_rsg","rsg");
add_action("do_life","life");
}
int do_list(string arg)
{
object who=this_player();
message_vision("
  $N在书桌上左翻翻右翻翻，找到点东西。\n
  base : 查看某玩家的所有基本属性。\n
  cha : 查看某玩家的其他状态。\n
  rsg : 查看某玩家的吃果数量。\n
  life : 查看某玩家的阳寿。\n
",who);
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
