//本程序有严重的版权问题,希望拿到本程序的站点请和本人联系!
//谢谢大家,希望大家不要乱改程序,谢谢!
//edit by leox 2001/05/29
#include <ansi.h>
#pragma save_binary

inherit F_DBASE;

void auto_save();

void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "安全精灵");
        CHANNEL_D->do_channel( this_object(), "sys", "\n自动安全防护系统已经启动。\n");
        call_out("auto_clear", 10);
}

void auto_clear()
{
        int i,mem;
        object *ob, link_ob;
        string id;
        CHANNEL_D->do_channel( this_object(), "sys",
     sprintf("系统自动清除 " + reclaim_objects() + " 个攻击数据包和废物包。\n"));
        remove_call_out("auto_clear");
        call_out("auto_clear", 480+random(120));
}
