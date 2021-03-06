//巫师备忘厅
//by Calvin

inherit ROOM;

void create ()
{
        set ("short", "巫师备忘厅");
        set ("long", @LONG
□ 巫师指令
[档案处理]:cd,more,ls,rm,cat,edit,mv,rmdir,cp,mkdir,tail
[物件处理]:call,dest,localcmds,update,clone,ilist
[查询指令]:config,mudlist,cost,whoami,ff,info,qload,mem,status,where,pwd,ulist
[系统管理]:dump,profile,purge,shutdown,callouts,chinese,cleanup,possess
[系统管理]:rehash,reclaim,reboot,promote,wizlock,edemote,snoop
[其他]:goto,halt,summon,smash

□ 巫师环境变数
1.immortal <anything>       设定自己成为不死之身，当状态达到昏迷或死亡时数值
2.invisibility <number>     设定隐形的程度。 0 - 10
3.msg_home <anything>       设定当自己打 home 回家时显示的讯息。
4.msg_min <anything>        设定当使用 goto 到达某处时, 别人所看到的讯息。
5.msg_mout <anything>       设定当使用 goto 离开时, 原来房间里的人所看到的讯息。
6.msg_clone <anything>      设定当 clone NPC 或 OBJ 时所显示的讯息。
7.msg_dest <anything>       设定当 dest NPC 或 OBJ 时所显示的讯息。但如果该 OBJ
7.msg_dest <anything>       是存在於自己身上时则不会有讯息。
LONG);

        set("exits", 
        ([ //sizeof() == 4
      "down" : __DIR__"wizroom",
        ]));

        set("objects", ([
                "/adm/object/bm" : 1,
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
