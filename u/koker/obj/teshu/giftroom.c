// entrance.c

#include <login.h>
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
  set ("short","��Ʒ���ߵ�");
        set("long", @LONG


�����ǳ������������ĵط�,��������Ϊ���￴���ķ羰��,ֻ����Ϊ����
�����п��˶�����ͨ������������������͵��ر�����.
�����ͨ��(paizi)֪����ȥ�ĵط�.

LONG);

        set("item_desc", ([
                "paizi": @TEXT
��������Ʒ�ݹ�����Ŀǰ���ǵ�·���У�

           down        ��¥����
           east        ������Ʒ��
           west        ������Ʒ��
           south       ������Ʒ��
           north       �����Ʒ��
           northwest   ������Ʒ��
           northeast   ������Ʒ��
           southeast   ������Ʒ��
           southwest   �к���Ʒ��

TEXT ]) );
        set("exits", ([
                "down" : "/d/wiz/entrance",
                     "east" : "/u/calvin/giftroom",
               "west" : "/u/koker/giftroom1",
//                "south" : "/u/stey/giftroom/",
               "north" : "/u/leoy/giftroom",
               "northeast" : "/u/vider/giftroom",
"northwest" : "/u/ivy/giftroom",
 //               "northeast" : "/u/flash/giftroom",
                  "southeast" : "/u/mudring/giftroom",
//                "southwest" : "/u/toyboy/giftroom/",
         ]) );
        set("no_time",1);
        set("no_fight", 1);
        set("no_magic", 1);

  set("objects", ([ /* sizeof() == 1 */
]));
        setup();
}
/*
int valid_leave(object me, string dir)
{
        
        if(me->query("id")=="clock") return ::valid_leave(me, dir);
        if(me->query("id")=="net") return ::valid_leave(me, dir);
        if(me->query("id")=="weiqi") return ::valid_leave(me, dir);

        if( dir=="north" && !wizardp(me) )
                return notify_fail("����ֻ����ʦ���ܽ�ȥ��\n");
        return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_accuse", "accuse");
}

int do_accuse(string arg)
{
        object ob;
        string s;

        if( ob = find_player(arg) ) {
                if( ob==this_player() )
                        return notify_fail("��Ҫ����Լ���\n");
                if( ob->is_ghost() )
                        return notify_fail( ob->name(1) +
"�Ѿ����ˣ�����һ���ɡ�\n");
                if( wizardp(ob) )
                        return notify_fail("�㲻�ܼ����ʦ��\n");
                tell_object(ob, HIW + this_player()->name(1) +
"������Ǹ������ˣ��������һ��СС�Ĳ��顣\n" NOR);
                ROBOT_CHECK->test_me(ob);
                write("Ok. �Ѿ������ٵĶ�����ȥ�����顣\n");

write("Ϊ�˱��������û������Ҽ��ɧ�ű��ˣ�����Ҳ������ͬ�Ĳ��顣\n");
                ROBOT_CHECK->test_me(this_player());
                log_file("robot_accuse",
                        sprintf("%s accused %s on %s.\n",
this_player()->query("id"), ob->query("id"), ctime(time())));
                return 1;
        }
        return notify_fail("Ŀǰ���ϲ�û����λ��ҡ�\n");
}
*/
void init()
{
    add_action("do_exert", "exert");
}
int do_exert(string arg)
{
        object who = this_player();
       object me = this_object();
   message_vision("���ﲻ����ʩչ�ڹ�����\n",who);
       return 1;
}
