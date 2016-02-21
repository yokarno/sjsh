// Room: /u/koker/wizroom
inherit ROOM;
//inherit PRIVATE_ROOM
void create()
{
  set ("short", "魔法门世界");
  set ("long", @LONG
巫师哦麦噶的小空间,里边不时的传出惨叫声.嘿嘿。。。不要去看啊！
LONG);
   set("exits", ([ /* sizeof() == 5 */
  "sl" : "/d/wiz/punish",
  "sy" : "/d/wiz/system",
  "kz" : "/d/city/kezhan",
  "wiz" : "/d/wiz/wizroom",
  "guest" : "/d/wiz/guest",
  "dx" : "/u/immortal/workroom",
  "wdd" :  "/d/qujing/wudidong/kitchen",
]));
set("objects", 
        ([ //sizeof() == 1
                __DIR__"obj/box" : 1,
        ]));

  set("chat_room",1);
  set("valid_startroom", 1);
  set("no_magic", 1);
  set("no_fight", 1);
     
   setup();
  call_other("/obj/board/koker_b", "???");
  
}
void init()
{   
        if (!wizardp(this_player())) 
             add_action("block_cmd","",1);      
        else
             add_action("read_book","read");
}

int block_cmd()
{
        string verb = query_verb();

        if (verb=="say") return 0; //allow say
        if (verb=="help") return 0;
        if (verb=="chat") return 0;//allow chat
        if (verb=="rumor") return 0;//allow rumor
        if (verb=="look") return 0;
        return 1;
}
int valid_leave(object me, string dir)
{
        object mbox;

        if( mbox = me->query_temp("mbox_ob") ) {
                tell_object(me, "你将信箱交回给邮差。\n");
                destruct(mbox);
        }

        return ::valid_leave(me, dir);
}

int read_book(string arg)
{
   if (!arg) return 0;
   if (arg!="death" && arg!="call" && arg!="mon" ) return 0;
   if (arg=="death") {
                if(file_size("/log/death")>0)
                this_player()->start_more( read_file("/log/death"));
        }
   if (arg=="call") {
                if(file_size("/log/static/call_player")>0)
                this_player()->start_more( read_file("/log/static/call_player"));
        }
   if (arg=="mon") {
                if(file_size("/log/monitord")>0)
                this_player()->start_more( read_file("/log/monitord"));
        }       
   write("\n");   
      return 1;
}
