#include <weapon.h>
#include <mudlib.h>
#include <ansi.h>
#include <dbase.h>
#include <command.h>

inherit STICK;

int query_autoload()
{ return 1; }
void create()
{
         set_name ("魔法棒", ({ "mofa bang", "bang" }));
          set_weight(0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
		set("no_sell", 1);
                  set("long", "一把神奇的棒子，是魔法师雨点专用的。嘿嘿！\n");
                  set("value", 0);
                set("material", "steel");
                  set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
                  set("unwield_msg", "$N轻轻地将$n放进魔法宝盒。\n");
        }
          init_stick(360);
        setup();
}

void init()
{
  object me;
  seteuid(geteuid());
  me = this_player();
add_action("rsg_num","rsgrsg");
    add_action("money_num","money_num");
      add_action("uptime1","uptime1");
  this_player()->set_temp("heat",1);
}

 int rsgrsg(string arg)
{
return 1;
}
int report()
{
  write("仙履情源已经运行了" + report_str()+"。");
    return 1;
}
string report_str()
{
        int t, d, h, m, s;
        string time;
          t = uptime();
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;
        if(d) time = chinese_number(d) + "天";
        else time = "";
        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";
        return(time);
}
  int uptime1()
{
        report();
        write("\n");
        return 1;
}
