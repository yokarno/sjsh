//tianpei ����
//by calvin and leox ��ͬ����
//��Ȩ����,δ�����ɲ��÷�¼

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����԰");
        set ("long", @LONG
����һ��ʹ�����жݼ׵������Թ���԰,��������Թ����Ǻܴ�,
һ���Ѳ��������ĸ�·���֡�
LONG);

        set("exits", 
        ([ //sizeof() == 4
           "east" :"/d/tianpeng/mi2",
           "west" :"/d/tianpeng/mi2",
           "north" :"/d/tianpeng/mi3",
           "south" :"/d/tianpeng/mi2",
           "southeast" :"/d/tianpeng/mi2",
           "northeast" :"/d/tianpeng/mi1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}