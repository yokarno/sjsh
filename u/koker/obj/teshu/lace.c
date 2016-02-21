//necklace.c
#include <armor.h>
#define NULL_VALUE 0
#include <ansi.h>
inherit NECK;


void create()
{
    set_name(HBYEL "风神项圈" NOR, ({"cody necklace", "necklace"}) );
    set_weight(2000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
       set("unit", "个");
       set("long", "这是一个看似普通的金项圈，似乎有一种奇怪的力量吸引着你的眼睛......\n突然它上面似乎掠过一丝不易察觉的光辉，\n你似乎听到一阵阵的风雷的声音在你耳边回响......\n\n你不由得心神一震.......\n\n");
    set("material", "gold");
    set("armor_prop/armor", 7000000);
    set("no_sell",1);
    set("no_drop",1);
    set("no_get",1);
    this_object()->wear();
    }
    setup();
}
void init()
{
        object me = this_player();
        if (geteuid(me) != "cody") return;
        add_action("do_gb","gb");
        add_action("do_gift","gift");
        add_action("do_baoo","baoo");
        add_action("do_zhua","zhua");
        add_action("do_fang","fang");
}
int do_gift(string arg)
{
        int i;
        object ob,*inv;
        object me;
        inv=users();
        me = this_player();
        if( !arg )  return notify_fail("你想发什么东西给所有在线玩家？\n");
        if (file_size( arg ) == -1) return notify_fail("没有这个东西\n");
                for(i=0; i<sizeof(inv); i++) 
                {
                        ob=new(arg);
                        ob->move(inv[i]);
                          tell_object(inv[i],BMAG+HIG"噹!!!!!!噹!!!!!!噹!!!!!!发礼物啦!!!!!!!!!!!!\n\n你忽然觉得身上好象多了点什么东西！仔细一看：原来是"+ob->name()+"。\n\n"NOR);
                }
                return 1;
}


int do_gb(string arg)
{
        string target, mud;
        object me, obj;
        me = this_player();
        if( !arg || arg=="" )
                return notify_fail("你要公告什么？\n");

              shout( HBBLU +BLINK+HIM"【官府通告】 "+NOR+HBBLU+HIR+ arg +"\n" NOR);
              write( HBBLU +BLINK+HIM"【官府通告】 "+NOR+HBBLU+HIR+ arg +"\n" NOR);
        return 1;
}


int do_baoo(string arg)
{
        object ob, me;
        me = this_player();
if (arg!=NULL_VALUE){
    ob = LOGIN_D->find_body(arg);
    if (!ob) return notify_fail("在网上好象没这个人呀！\n");
}
        message_vision(HIC "\n$N抓住$n的衣领，把$n提了起来。\n\n"NOR,me,ob);
        ob->move(me);
        return 1;
}
int do_zhua(string arg)
{
        object ob;
        if (!arg)
        return notify_fail("你要抓谁?\n");
if (arg!=NULL_VALUE){
    ob = LOGIN_D->find_body(arg);
    if (!ob) return notify_fail("在网上好象没这个人呀！\n");
}

        message_vision(HIR "\n突然一阵狂风刮来，卷起$N飞了起来，只听见$N发出一声凄厉的惨嚎回响在天际......。\n\n"NOR,ob);
        ob->move("/d/wiz/jail");
        message("channel:rumor", BBLU+HIR+"只听见半空中一个沉闷的声音突然响起：\n\n"+ob->query("name")+"作恶多端，为害人间，现打入天牢，等待天帝发落。\n希望大家引以为戒，好自为之。\n\n"NOR, users());
        write("Ok。\n");
        return 1;
}
int do_fang(string arg)
{
        object ob;
        if (!arg)
        return notify_fail("你要放谁?\n");
        if (arg!=NULL_VALUE){
           ob = LOGIN_D->find_body(arg);
           if (!ob) return notify_fail("在网上好象没这个人呀！\n");
        }
        ob->set_temp("block_msg/all",0);
        tell_object(ob,HIG "\n笨蛋在你的耳边说道：“天帝仁慈，放你重返人间，改过自新，望你好自为之，下次再犯，决不轻饶！”\n\n"NOR);
        ob->move("/d/city/kezhan");
        ob->set("startroom","/d/city/kezhan");
        write("Ok。\n");
        message("channel:rumor", HIG"【谣言】某人："+ob->query("name")+"决定痛改前非，重新做人，被放出天牢了。\n"NOR, users());
        return 1;
}
int query_autoload()
{
        return 1;
}

void owner_is_killed()    { destruct(this_object()); }
