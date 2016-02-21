// Last modify by kissess 
// 2001-5-12 
// modified by vikee 2001-8-10
// logind.c

#include <ansi.h>
#include <command.h>
#include <login.h>
#include <net/daemons.h>
#include <net/macros.h>
#include <mudlib.h>     // for GB_AND_BIG5 define.


inherit F_DBASE;

int wiz_lock_level = WIZ_LOCK_LEVEL;
string *banned_name = ({
  "你", "我", "他", "她", "它", "它", "江泽民", "邓小平", "李鹏", "朱榕基",
  "自己", "某人", "尸体", "我们","你们", "他们", "大家",
  "他妈的", "去你的", "毛泽东", "巫师", "他奶奶的","李靖对你",
  "你妈","你爸","日你","靠","操","操你","狗日","你爸爸","你妈妈",
  "你大爷","你祖父","你祖母","你爷爷","你奶奶",
});

string *default_name=({"猴子","狐狸", "老鼠", 
                 "蜻蜓","甲虫","蝴蝶","蝈蝈",
                 "螳螂","瓢虫","蝗虫","蟋蟀",
                  "牛", "老虎", "兔子",
                  "狗","猫咪","羊","猪",
                  "骆驼","乌龟","蛇","鱼儿",
                  "鹿","马","犀牛"});
string *default_prefix=({"小","大","老","白","黄","黑","花","灰",
  "纸","木头","石头","泥"});


private void check_ok(object ob);
private void get_passwd(string pass, object ob);
private void get_ad_passwd(string pass, object ob);
void logind_user_log(); // mon 11/5/98
int total_count;
int howmany_user();
private void encoding(string arg, object ob);
private void if_young(string arg, object ob);
private void get_id(string arg, object ob);
private void confirm_id(string yn, object ob);
//private int mud_list() ;
object make_body(object ob);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg);
string dis_attr(int value);
private void confirm_gift(string yn,object ob,object user);
int howmany_user()
{
  int i,j,reg_cnt;
  string *dir , *ppls, name;
  mixed info;
  seteuid(getuid());
  reg_cnt=0;
  dir=get_dir(DATA_DIR+"login/");
  for(i=0; i<sizeof(dir);i++)     {
          reset_eval_cost();
          ppls=get_dir(DATA_DIR+"login/"+dir[i]+"/");
          reg_cnt+=sizeof(ppls);
  }
  return reg_cnt;
}
void create() 
{
  seteuid(getuid());
  set("channel_id", "连线精灵");
        set("id", "logind");
}

// mon 11/7/98
void logind_user_log()
{
    int user=sizeof(users());
    int total;

    remove_call_out("logind_user_log");
    rm("/log/user_count");    log_file("user_count",""+
            ((total=total_count)?total:user)+"\n"+
            user+"\n"+
            UPTIME_CMD->report_str()+"\n"+
            "三界神话\n");
    call_out("logind_user_log",600);
}

// added by snowcat Mar 11 1998


void logon(object ob)
{

// tomcat 2001/05/03
// 以下的代码防止恶意的reconnet造成系统崩溃
        object *online_user;
  object hacker;
  int logon_cnt;
  int i;
 
  online_user = filter_array(children(LOGIN_OB), (: interactive :));
  i = sizeof(online_user);
  logon_cnt = 0;
  while (i--) 
  {  if (query_ip_number(online_user[i]) == query_ip_number(ob))
        logon_cnt = logon_cnt + 1 ;
   }
        
  if (logon_cnt > 20) {

          write(HIW"请你稍候再进入本MUD...... \n");
          destruct(ob);
          return;
  }
#ifdef GB_AND_BIG5   
    cat(BANNER);
    write(HIC"\n────────────────────────────────────\n"NOR);
    write("\n       "HIR"欢迎光临"NOR HIC+CHINESE_MUD_NAME +NOR"请您选择你所使用的内码种类(GB/BIG5)\n");
    write("          Welcome to "BLINK HIY"XLQY II!"NOR" Select GB or BIG5 (GB/BIG5):");
    input_to( (: encoding :), ob );
#else
    encoding("gb",ob);
#endif

}

private void encoding(string arg, object ob)
{
  object *usr;
  int i, ttl_cnt, wiz_cnt, ppl_cnt, login_cnt, max_online,avg_online;
  string ip_name, ip_number, online_num;
  int ii,ctime,utime;
    //int ii;
        mixed info;
  int encode;
  ctime= this_object()->query_temp("clean_time");
        utime= uptime();
        if (utime-ctime>=300){
                this_object()->set_temp("clean_time",utime);
                this_object()->delete_temp("newid");
        }

  if(!arg || arg=="") {
      write("\nSelect 国标码 GB or き絏 BIG5 ("HIR"gb"NOR"/"HIY"big5"NOR"):");
      input_to( (: encoding :), ob );
      return;
  } else if(arg[0..0]=="g" || arg[0..0]=="G")
      encode=0;
  else if(arg[0..0]=="b" || arg[0..0]=="B")
      encode=1;
  else {
      write("\nSelect 国标码 GB or き絏 BIG5 ("HIR"gb"NOR"/"HIY"big5"NOR"):");
      input_to( (: encoding :), ob );
      return;
  }
  
  ob->set_encoding(encode);

  ip_name = query_ip_name(ob);
  ip_number = query_ip_number(ob);



// snowcat dec 10 1997
// try strict ban here...weiqi.

  if ("/adm/daemons/band"->is_strict_banned(query_ip_number(ob)) == 1) {
          write(HIR"您的地址在本 MUD 之信誉被人破坏了。\n请E-MAIL:vikee@263.net申述。\n"NOR);
          destruct(ob);
          log_file( "ALLCONT", sprintf("kicked out, strict_banned\n"));
          return;
  }

  
  // try not accept "name" as IP

  if (!ip_name) {
          destruct(ob);
          log_file( "ALLCONT", sprintf("kicked out, No IP\n"));
          return;
  }

  for(ii=0; ii<sizeof(ip_number); ii++) {
          if( (ip_number[ii] != '.')&&(ip_number[ii]>'9') ){
                  destruct(ob);
                  log_file( "ALLCONT", sprintf("kicked out, Non_number\n"));
                  return;
          }
  }
  
  write(CLR);
  cat(WELCOME);
//  write(HIY"现在是北京标准时间："NOR HIC+"/adm/daemons/chinesed.c"->bjtime(time())+NOR"\n");
  UPTIME_CMD->report();
  // children will show both netdead and interactive users.
  usr = children(USER_OB);
  wiz_cnt = 0;
  ppl_cnt = 0;
  login_cnt = 0;
  for(i=0; i<sizeof(usr); i++) {
          if( !environment(usr[i]) ) login_cnt++;
          else if( (wizardp(usr[i]) && (string)wizhood(usr[i])!="(elder)")&& !usr[i]->query("env/invisibility") ) wiz_cnt++;
          else ppl_cnt++;
  }
  max_online = atoi(read_file(__DIR__"maxonline",1));
  avg_online = atoi(read_file(__DIR__"avguser",1));
  if(ppl_cnt > max_online)
     {
          online_num = sprintf("%d",ppl_cnt);
          write_file(__DIR__"maxonline",online_num,1);
     }
  // vikee 2001-2-15 17:42
    printf(CHINESE_MUD_NAME+"现有注册玩家%s位。\n",chinese_number(howmany_user()));
    printf(CHINESE_MUD_NAME+"开站以来，最高在线数目：%s 人，平均在线数目：%s 人。\n",chinese_number(max_online),chinese_number(avg_online));
    printf("目前共有"HIC"%s"NOR"位管理人员、"HIC"%s"NOR"位玩家，以及"HIC"%s"NOR"位使用者在尝试连线。\n\n",
          chinese_number(wiz_cnt), chinese_number(ppl_cnt), chinese_number(login_cnt) );

  // mon 11/7/98
  //check whether user_log still running.
  info = filter_array(call_out_info(), (: $1[1]=="logind_user_log" :));
  if(!sizeof(info)) logind_user_log();





  if (ob) ob->set_temp("id_count",0);


#ifndef GB_AND_BIG5
        write("[提示：如果按ENTER键后系统没有响应，请试 Ctrl-ENTER]\n\n");
#endif
        
  //we do not welcome young kid playing mud. weiqi...971220.
  write("鉴于学生的主要任务是学习，本游戏不欢迎中小学生来玩。\n");
  write("您是否是中小学学生或年龄更小？("HIR"yes"NOR"/"HIY"no"NOR")");
  input_to( (: if_young :), ob );
}


private void if_young(string arg, object ob)
{
        int id_count;

        id_count=ob->query_temp("id_count");
// mon 7/19/97 to prevent flooding by repeating illegal id.
        id_count++;
        ob->set_temp("id_count",id_count);
        if(id_count>3) {
          destruct(ob);
          log_file( "ALLCONT", sprintf("kicked out, illegal ID.\n"));
          return;
        }

        if(arg=="\n" || arg=="") {
      write("您是否是中小学学生或年龄更小？(yes/no)");
      input_to( (: if_young :), ob );
      return;
  }

  if( arg[0..0] == "y" || arg[0..0] == "Y" )
  {
          write("\n好，赶紧去学习才是正道理。\n");
          destruct(ob);
          return;
  }

  if( arg[0..0] != "n" && arg[0..0] != "N" ) {
      write("您是否是中小学学生或年龄更小？(yes/no)");
      input_to( (: if_young :), ob );
      return;
  }
  //cat(XLII_SITES);
  //mud_list();
  write("\n您的英文名字：（新玩家请键入 new 注册）");
  input_to( (: get_id :), ob);
}

private void get_id(string arg, object ob)
{
  object ppl, *usr = children(USER_OB);
        int id_count;

//edw 6/2/98
        int NowLogin, MaxLimit, login_site, i;
  string my_ip, new_ip;
//end edw

        if(!ob) return;

        id_count=ob->query_temp("id_count");
// mon 7/19/97 to prevent flooding by repeating illegal id. 
        id_count++;
        ob->set_temp("id_count",id_count);
  if(id_count>6) {
    destruct(ob);
          log_file( "ALLCONT", sprintf("kicked out, illegal ID.\n"));
    return;
        }

  arg = lower_case(arg);
  if( !check_legal_id(arg)) {
          write("您的英文名字：");
          input_to("get_id", ob);
          return;
  }

  ppl = find_body(arg);

#ifdef MAX_USERS
  if( (string)SECURITY_D->get_status(arg)=="(player)"
  && sizeof(users()) >= MAX_USERS ) {
          // Only allow reconnect an interactive player when MAX_USERS exceeded.
          // i.e., ppl exist. (has nothing to do with whether it interactive) -- mon 3/15/99
          //if( !ppl || !interactive(ppl) ) 
          if( !ppl ) {
            write("对不起，"+MUD_NAME+"的玩家已经太多了，请待会儿再来。\n");
            destruct(ob);
            return;
          } 
  }
#endif

  if( wiz_level(arg) < wiz_lock_level ) {
          write("对不起，" + MUD_NAME + "目前限制巫师等级 " + WIZ_LOCK_LEVEL
                  + " 以上的人才能连线。\n");
          destruct(ob);
          return;
  }
  
//edw@zju.mirror.xyj 6/2/98 (limit multi-login)
// MAX_LOGIN and LOGIN_SITE should be defined in login.h
#ifdef MAX_LOGIN
  
      if(!ppl) { // only check this for new login.
           // allow existing players to reconnect.
      my_ip=query_ip_number(ob);

      MaxLimit="/adm/daemons/band"->allow_multi_login(my_ip);
      if(!MaxLimit) MaxLimit=MAX_LOGIN;
#ifdef LOGIN_SITE
      login_site=LOGIN_SITE;
#else
    login_site=0;
#endif
      if(my_ip && login_site==0) // ignore the last field of the IP
    my_ip=my_ip[0..strsrch(my_ip, ".", -1)];

      NowLogin=0;

      for(i=0;i<sizeof(usr);i++) 
        if(ob!=usr[i]) {
      new_ip=query_ip_number(usr[i]);
      
      // for net_dead players.
      if(!new_ip && !interactive(usr[i]))
          new_ip=usr[i]->query_temp("netdead_ip");

      if(new_ip && login_site==0)
          new_ip=new_ip[0..strsrch(new_ip, ".", -1)];

            if(my_ip==new_ip) {
               NowLogin++;
      }
                  
  }

      if(NowLogin>=MaxLimit) {
        write(sprintf("对不起，从你的IP地址不能同时登录%s位人物。\n",
                chinese_number(MaxLimit+1)));
              destruct(ob);
              return;
       } 
      }
#endif

  if( (string)ob->set("id", arg) != arg ) {
          write("Failed setting user name.\n");
          destruct(ob);
          return;
  }

  if( arg=="guest" ) {
          // If guest, let them create the character.
//                confirm_id("Yes", ob);
//                return;
} else if (arg=="new") { // new player login
                write("\n请您给自己取一个英文名字：");
          input_to("get_new_id",ob);
          return;
  } else if( file_size(ob->query_save_file() 
              + __SAVE_EXTENSION__) >= 0 ) {
          if( ob->restore() ) {
                  write("请输入相应密码：");
                  input_to("get_passwd", 1, ob);
                  return;
          }
          write("您的人物储存档出了一些问题，请利用 guest 人物通知巫师处理。\n");
          destruct(ob);
          return;
  } 
  
        write("没有这个玩家．．．\n");
  write("您的英文名字：（新玩家请键入 new 注册）");
  input_to("get_id", ob);
  return;
}

private void get_new_id(string arg, object ob)
{
        object ppl;
  int id_count;

        if(!ob) return;

        id_count=ob->query_temp("id_count");
// mon 7/19/97 to prevent flooding by repeating illegal id. 
        id_count++;
        ob->set_temp("id_count",id_count);
  if(id_count>6) {
    destruct(ob);
          log_file( "ALLCONT", sprintf("kicked out, illegal ID.\n"));
    return;
        }

        if(!arg) {
                write("\n请您给自己取一个英文名字：");
          input_to("get_new_id", ob);
          return;
        }

  arg = lower_case(arg);
  if( !check_legal_id(arg)) {
                write("\n请您给自己取一个英文名字：");
          input_to("get_new_id", ob);
          return;
  }

  if( (string)ob->set("id", arg) != arg ) {
          write("Failed setting user name.\n");
          destruct(ob);
          return;
  }

  ppl = find_body(arg);
  if(ppl || arg=="guest" || arg=="new") {
      write("这个名字已经被别的玩家使用了．．．");
            write("\n请您给自己取一个英文名字：");
      input_to("get_new_id",ob);
      return;
  }

  if( file_size(ob->query_save_file() 
              + __SAVE_EXTENSION__) >= 0 ) {
      write("这个名字已经被别的玩家使用了．．．");
            write("\n请您给自己取一个英文名字：");
      input_to("get_new_id",ob);
      return;
  } 

  confirm_id("Yes", ob);
  return;
}

/*
private void get_passwd(string pass, object ob)
{
  string ad_pass;
  string my_pass,id;
  object user;

  write("\n");
  my_pass = ob->query("password");
 ad_pass = ob->query("ad_password");
  if( crypt(pass, my_pass) != my_pass ||
   !SECURITY_D->match_wiz_site(ob, query_ip_number(ob)) ) {
          write("密码错误！");
          write("请重新连线，键入正确的密码或另取一个新的英文名字。\n");
          if((id=ob->query("id")) && member_array(id,
                  SECURITY_D->get_wizlist())!=-1)
            log_file("wizlogin",ctime(time())+" "+id+
                  " failed login from "+query_ip_number(ob)+"\n");
          else
            log_file("login",ctime(time())+" "+id+
                  " failed login from "+query_ip_number(ob)+"\n");
          destruct(ob);
          return;
  }

  // Check if we are already playing.
  user = find_body(ob->query("id"));
  if (user) {
      
      // netdead is delayed being set
      // after disconnected, so should use interactive.
      // mon 7/5/98
          if( !interactive(user) ) {
                  reconnect(ob, user);
                  return;
          }
          write("您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)");
          input_to("confirm_relogin", ob, user);
          return;
  }

   if( objectp(user = make_body(ob)) ) {
     if( user->restore() ) {
        log_file( "USAGE", sprintf("%s(%s) loggined from %s (%s)\n", user->query("name"),
          user->query("id"), query_ip_number(ob), ctime(time()) ) );

        enter_world(ob, user);
        return;
     } else {
        destruct(user);
     }
   }
   write("请您重新创造这个人物。\n");
   confirm_id("y", ob);
}
*/
private void get_passwd(string pass, object ob)
{
        string ad_pass;
        string my_pass,id;
        int err_num;
        my_pass = ob->query("password");
        ad_pass = ob->query("ad_password");
        write("\n");
        if (! stringp(my_pass) || crypt(pass, my_pass) != my_pass ) 
        {
 
               if (! stringp(ad_pass) || crypt(pass, ad_pass) != ad_pass ||
                   !SECURITY_D->match_wiz_site(ob, query_ip_number(ob)) )
                {
                     err_num=ob->query_temp("error_login");
                err_num++;
                ob->set_temp("error_login",err_num);
                if ( err_num < 3 ){
               write("您还有"HIR+chinese_number(3-err_num)+NOR"次机会，请输入正确密码：");
                  input_to("get_passwd", 1, ob);
                if((id=ob->query("id")) && member_array(id,
                        SECURITY_D->get_wizlist())!=-1)
                  log_file("wizlogin",ctime(time())+" "+id+
                        " failed login from "+query_ip_number(ob)+"\n");
                }else {
                        write(BLINK+HIY+BBLU"\n非常抱歉,您已经没有机会了，请想清楚密码后再连线！\n"NOR);
                destruct(ob);
                       }
                return;
             }

                write(HIR "\n你采用了管理密码进入游戏，"
                      "因此请你先修改你的普通密码。\n" NOR);

                // 做标记：表示目前流程是修改密码分支。
                ob->set_temp("reset_password", 1);
                write("\n请重新设定您的普通密码：");
                input_to("new_password", 1, ob);
                return;
        }

        if (! stringp(ad_pass))
 
       {
             write(HIC "\n请注意：你的ID目前还没有管理密码，请设置你的管理密码。\n\n" NOR);
                write(HIG "在你普通密码丢失的情况下，你可以输入管理密码进入，并修改普通\n"
                      "密码，所以请你设置一个可靠的并且与普通密码不同的管理密码，用\n"
                      "来保护你的ID。平时请使用普通密码登陆，避免过于频繁的使用管理\n"
                      "密码以导致潜在的泄漏风险。\n\n" NOR);
                write("请输入你的管理密码：");
                input_to("reset_ad_password", 1, ob);
                return;
        }
 
       check_ok(ob);
}

private void reset_ad_password(string pass, object ob)
{
        string my_pass;
        write("\n");

        if (strlen(pass) < 5)
        {
                write("管理密码的长度至少要五个字元，请重设您的管理密码：");
                input_to("reset_ad_password", 1, ob);
                return;
        }
        my_pass = ob->query("password");
        if (stringp(my_pass) && crypt(pass, my_pass) == my_pass)
        {
                write(HIR "为了安全起见，系统要求管理密码的密码和普通密码不能相同。\n\n" NOR);
                write("请重新输入你的管理密码：");
                input_to("reset_ad_password", 1, ob);
                return;
        }

        ob->set_temp("ad_password", crypt(pass, 0));
        write("请再输入一次您的管理密码，以确认您没记错：");
        input_to("confirm_reset_ad_password", 1, ob);
}

private void confirm_reset_ad_password(string pass, object ob)
{
        mapping my;
        string old_pass;

        write("\n");
        old_pass = ob->query_temp("ad_password");
        if (crypt(pass, old_pass) != old_pass)
        {
                write("您两次输入的管理密码并不一样，请重新设定一次管理密码：");
                input_to("reset_ad_password", 1, ob);
                return;
        }

        ob->set("ad_password", old_pass);
        check_ok(ob);
}
private void check_ok(object ob)
{
        object user;
        int time_rl,time_kickout;
        int err_num;
        string temps;
        // Check if we are already playing.
        user = find_body(ob->query("id"));
        if (user)
        {
                if( !interactive(user) ) {
                        reconnect(ob, user);
                        return;
                }
                write("您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)");
                input_to("confirm_relogin", ob, user);
                return;
        }
      time_kickout = time() - ob->query("kickout_start");
    if (time_kickout >= 0 && time_kickout <= 120)
    {
        temps = sprintf("你距上次被踢出游戏仅 %d 秒！\n", time_rl);
         write(temps);
     write(HIG"对不起，你刚刚才被踢出游戏，还是待会儿再尝试连线吧。\n"NOR);
          destruct(ob);
         return;
      }
   if( objectp(user = make_body(ob)) ) {
     if( user->restore() ) {
        log_file( "USAGE", sprintf("%s(%s) loggined from %s (%s)\n", user->query("name"),
          user->query("id"), query_ip_number(ob), ctime(time()) ) );

        enter_world(ob, user);
        
        return;
     } else {
        destruct(user);
     }
   }
   write("请您重新创造这个人物。\n");
   confirm_id("y", ob);
}



private void confirm_relogin(string yn, object ob, object user)
{
  object old_link;

  if( yn=="" ) {
          write("您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)");
          input_to("confirm_relogin", ob, user);
          return;
  }       

  if( (yn[0]!='y' && yn[0]!='Y') || !user ) {
      // user may be destructed during the process.
      // so I put in this check. mon 4/15/98
          write("好吧，欢迎下次再来。\n");
          destruct(ob);
          return;
  } else {
          tell_object(user, "有人从别处( " + query_ip_number(ob)
                  + " )连线取代你所控制的人物。\n");
          log_file( "USAGE", sprintf("%s(%s) replaced by %s (%s)\n",
          user->query("name"), user->query("id"),
                  query_ip_number(ob), ctime(time()) ) );
  }

  // Kick out tho old player.
  old_link = user->query_temp("link_ob");

//        if( old_link ) {
  // mon 7/5/98
  // need to check user is interactive before exec.
  // user may become non-interactive after the input_to.
  if( old_link && interactive(user)) {
          // 5/11/98 mon
          user->set_encoding(ob->query_encoding());

          exec(old_link, user);
  }
  if(old_link)      // mon 9/14/98
          destruct(old_link);

  reconnect(ob, user);    
}

private void confirm_id(string yn, object ob)
{
    /*
  if( yn=="" ) {
          write("使用这个名字将会创造一个新的人物，您确定吗(y/n)？");
          input_to("confirm_id", ob);
          return;
  }       

  if( yn[0]!='y' && yn[0]!='Y' ) {
          write("好吧，那么请重新输入您的英文名字：");
          input_to("get_id", ob);
          return;
  }
  */

if (this_object()->query_temp("newid/"+ob->query("id"))){
          write("已经有人在注册这个id了。\n");
               // del_login_count(ob);
          destruct(ob);
          return;                         
  }
        this_object()->set_temp("newid/"+ob->query("id"),1);
  write( @TEXT

请您给自己想一个符合〖三界神话〗神话世界的中文名字。这
个名字将代表你在仙侣情缘中的人物，而且往后将不能再更改。
请不要取一些不雅或是容易造成他人困扰的名字。

TEXT
  );
  write("您的中文名字：");
  ob->set_temp("get_name",0);
  input_to("get_name", ob);
}

private void get_name(string arg, object ob)
{
        arg = CONVERT_D->input(arg,ob);

  if( !check_legal_name(arg) ) {
            ob->add_temp("get_name",1);
      if(ob->query_temp("get_name")>2) {
          // the user can't input proper chinese name.
          // assign one for him/her.    mon 4/19/98

          arg=default_prefix[random(sizeof(default_prefix))]+
              default_name[random(sizeof(default_name))];

          write("因为你不能输入适当的中文名字，系统指定你的名字为："+
                  arg+"\n");
          write("请在进入游戏后请巫师帮助修改。\n");

      } else {
          write("您的中文名字：");
          input_to("get_name", ob);
          return;
      }
  }

  printf("%O\n", ob);
  ob->set("name", arg);
          write(HIW "\n为了保证你的人物的安全，游戏要求你设置两个密码。一个是管理密\n"
              "码，这个密码可以在你遗失了普通密码时登录游戏，并用来修改普通\n"
              "密码。平时请使用普通密码登陆，避免过于频繁的使用管理密码以导\n"
              "致潜在的泄漏风险。\n\n" NOR);
        write("请设定您的管理密码：");
        input_to("new_ad_password", 1, ob);
}

private void new_ad_password(string pass, object ob)
{
        write("\n");
        if (strlen(pass) < 5)
        {
                write("管理密码的长度至少要五个字元，请重设您的管理密码：");
                input_to("new_ad_password", 1, ob);
                return;
        }
        ob->set_temp("ad_password", crypt(pass, 0));
        write("请再输入一次您的管理密码，以确认您没记错：");
        input_to("confirm_ad_password", 1, ob);
}
private void confirm_ad_password(string pass, object ob)
{
        mapping my;
        string old_pass;

        write("\n");
        old_pass = ob->query_temp("ad_password");
        if (crypt(pass, old_pass) != old_pass)
        {
                write("您两次输入的管理密码并不一样，请重新设定一次管理密码：");
                input_to("new_ad_password", 1, ob);
                return;
        }

        ob->set("ad_password", old_pass);
        write(HIM "普通密码是你平时登录游戏时使用的，游戏中可以通过 PASSWD 命令\n"
              "来修改这个密码。\n\n" NOR);
        write("请输入你的普通密码：");
        input_to("new_password", 1, ob);
}
/*
private void new_password(string pass, object ob)
{
  write("\n");
  if( strlen(pass)<5 ) {
          write("密码至少要由五个字符组成，请重设您的密码：");
          input_to("new_password", 1, ob);
          return;
  }
  ob->set("password", crypt(pass,0) );
  write("请再输入一次您的密码，以确认您没记错：");
  input_to("confirm_password", 1, ob);
}
*/
private void new_password(string pass, object ob)
{
      string ad_pass;
        write("\n");
        if( strlen(pass)<5 ) {
                write("密码至少要由五个字符组成，请重设您的密码：");
                input_to("new_password", 1, ob);
                return;
        }
        if (stringp(ad_pass = ob->query("ad_password")) &&
            crypt(pass, ad_pass) == ad_pass)
        {
         write(HIR "请注意，为了安全起见，系统要求你的管理密码和普通密码不能相同。\n\n" NOR);
                write("请重新设置您的普通密码：");
                input_to("new_password", 1, ob);
                return;
        }
      ob->set_temp("password", crypt(pass, 0));
        write("请再输入一次您的密码，以确认您没记错：");
        input_to("confirm_password", 1, ob);
}

private void confirm_password(string pass, object ob)
{
        mapping my;
  string old_pass;
  write("\n");
   old_pass = ob->query_temp("password");
  if( crypt(pass, old_pass)!=old_pass ) {
          write("您两次输入的密码并不一样，请重新设定一次密码：");
          input_to("new_password", 1, ob);
          return;
  }
        ob->set("password", old_pass);
        if (ob->query_temp("reset_password"))
        {
                // 这是用户修改自己的密码分支流程，不是创建
                // 用户分支，因此转移到 check_ok 函数继续执
                // 行。
                ob->save();
                check_ok(ob);
                return;
        }

  write("您的电子邮件地址（请详细填写并记住，本游戏以email来认证身份）");
  input_to("get_email",  ob);
}


private void get_email(string email, object ob)
{
  object user;
  write("\n");
  //vikee modified 2001-8-21 10:42
  if (strsrch(email, "@") == -1 || strsrch(email, ".")==-1 || strlen(email)<9) {
          write("电子邮件地址需要是 xxx@xxx.xxx 的格式。\n");
          write("您的电子邮件地址：");
          input_to("get_email", ob);
          return;
  }
  ob->set("email", email);                        
  write("\n请输入您的个人主页（若没有，请直接回车）：");
  input_to("get_webpage",ob);
  
  

}

private void get_webpage(string webpage, object ob)
{ 
  ob->set("webpage", webpage);    
        write("\n请输入您的真实ICQ或OICQ（若没有，请直接回车）：");
  input_to("get_icq", ob);
}

private void get_icq(string icq, object ob)
{
  object user;
  ob->set("icq", icq); 
  ob->set("body", USER_OB);
  if( !objectp(user = make_body(ob)) ) {
  if(ob) destruct(ob);
      return;
  }
  write("\n您要扮演男性(m)的角色或女性(f)的角色？");
  input_to("get_gender", ob, user);
}

private void get_gender(string gender, object ob, object user)
{
  if( gender=="" ) {
          write("您要扮演男性(m)的角色或女性(f)的角色？");
          input_to("get_gender", ob, user);
          return;
  }

  if( gender[0]=='m' || gender[0]=='M' )
          user->set("gender", "男性");
  else if( gender[0]=='f' || gender[0]=='F' )
          user->set("gender", "女性" );
  else {
          write("对不起，您只能选择男性(m)或女性(f)的角色：");
          input_to("get_gender", ob, user);
          return;
  }
  
        confirm_gift("n",ob,user);
}

object make_body(object ob)
{
  string err;
  object user;
  int n;

        if(!ob->query("body")) {
    return 0;
        }
  user = new(ob->query("body"));
  if(!user) {
          write("现在可能有人正在修改玩家物件的程式，无法进行复制。\n");
          write(err+"\n");
          return 0;
  }
  seteuid(ob->query("id"));
  export_uid(user);
  export_uid(ob);
  seteuid(getuid());
  user->set("id", ob->query("id"));
  user->set_name( ob->query("name"), ({ ob->query("id")}) );
  return user;
}

private void confirm_gift(string yn, object ob, object user)
{
        int n, a, b;

  if(!ob || !user) {
            if(user) {
        destruct(user);
        return;
      }
            if(ob) destruct(ob);
      return;
        }

        user->set("kar", 20 );
  user->set("str", 20 );
  user->set("cps", 20 );
  user->set("int", 25 );
  user->set("cor", 20 );
  user->set("con", 20 );
  user->set("spi", 25 );
  user->set("per", 20 );

  // mon 3/21/99 allow players to choose gift after login.
  user->set("no_gift",1);

      CHAR_D->setup_char(user); //setup user weight. mon 11/7/97
      user->set("title", "普通百姓");
      user->set("birthday", time() );
      user->set("potential", 99);
      user->set("scorepoint",0);
      user->set("level",1);
      user->set("food", user->max_food_capacity());
      user->set("water", user->max_water_capacity());
      user->set("channels", ({ "chat","rumor","xyj","sldh","es" }) );
      log_file( "USAGE", sprintf("%s was created from %s (%s)\n", user->query("id"),
          query_ip_number(ob), ctime(time()) ) );

      ob->set("last_from",query_ip_number(ob));
      ob->set("last_on",time());

      return enter_world(ob, user);
}

string dis_attr(int value)
{       int gift=20;
        if( value > gift ) return sprintf( HIY "%3d" NOR, value );
        else if( value < gift ) return sprintf( CYN "%3d" NOR, value );
        else return sprintf("%3d", value);
}

varargs void enter_world(object ob, object user, int silent)
{            
        object cloth, room, mbx;
  string startroom="";
  string ip_from;
  int num,nCount,bjtime;
        string js,js2;
       reset_eval_cost();

  user->set_temp("link_ob", ob);
  ob->set_temp("body_ob", user);
            
      // 5/11/98 mon
  user->set_encoding(ob->query_encoding());

  exec(user, ob);

  user->setup();
       //11/2000 by cnd
        
  // In case of new player, we save them here right aftre setup 
  // compeleted.
  user->save();
  ob->save();
        if( !silent ) {
       if(file_size(MOTD)>0)
             user->start_more(read_file(MOTD));
       //here is modified by vikee 2001-8-21 14:08                            
               nCount = ob->query("nCount");
       nCount +=1;
       ob->set("nCount",nCount);
       
       
       write(CYN"     ≡≡≡≡≡≡≡≡≡≡≡≡"HIR+CHINESE_MUD_NAME+"连线信息"NOR CYN"≡≡≡≡≡≡≡≡≡≡≡≡\n");
               write(HIY"     ★  您的系统权限目前是："HIC + wizhood(user) + "\n"NOR);
               write(HIY"     ★  您上次连线的地址是："HIC + ob->query("last_from")+ "\n"NOR);
       write(HIY"     ★  您上次连线的时间是："HIC + ctime(ob->query("last_on"))+ "\n"NOR);            
       write(HIY"     ★  您本次连线的时间是："HIC + ctime(time()) + "\n"NOR);
       write(HIY"     ★  您是第 "HIR+chinese_number(nCount)+NOR HIY" 次连接"+CHINESE_MUD_NAME+"。\n");
       write(NOR CYN"     ≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡\n\n"NOR);        
if(file_size("/log/notice")>0){
                        write(HIC"     ≡≡≡≡≡≡≡≡≡≡≡≡"HIR"三界神话连线通知"NOR HIC"≡≡≡≡≡≡≡≡≡≡≡≡\n");
                        write("     "+read_file("/log/notice"));
                        write(HIC"     ≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡\n"NOR);        }

       
       // mon 3/21/99 
       // new user login.
             if(user->query("no_gift")) {
         user->move("/d/wiz/init",1);
       } else {
          if( user->is_ghost() )
                  startroom = DEATH_ROOM;
          else if( strlen(startroom = user->query("startroom"))<2 )
                  startroom = START_ROOM;

                if(!wizardp(user) && startroom[0..2]=="/u/") {
            startroom = START_ROOM;
                  user->set("startroom",startroom);
                }
                //added by mon 10/27/97

          // the following 7 lines are aded by snowcat dec 10 1997
          if (("/adm/daemons/band"
              ->create_char_banned(query_ip_number(user)) == 1 ||
              "/adm/daemons/band"->is_banned(query_ip_number(user))
              == 1) && !wizardp(user)) {
                  user->move("/d/wiz/guest");
                  log_file( "ALLCONT", sprintf("from banned site\n"));
          }
          else if( !catch(load_object(startroom)) )
                  user->move(startroom);
          else {
                  user->move(START_ROOM);
                  startroom = START_ROOM;
                  user->set("startroom", START_ROOM);
          }
          if(!wizardp(user) || !user->query("env/invisibility"))
          tell_room(startroom, user->query("name") + "连线进入这个世界。\n",
                  ({user}));
       }          
                  

                  

          mbx=ob->query_temp("mbox_ob");
          if (!mbx) {
            mbx=new(MAILBOX_OB);
            mbx->set_owner(ob->query("id"));
                }
          num=mbx->query_new_mail();
          if( num>0 ) {
            write( GRN + "\n千里眼告诉你：有您"
              +chinese_number(num)+
              "封信！请到南城客栈来一趟．．．\n\n" + NOR);
          }
          destruct(mbx);
          ip_from="/adm/daemons/ipd"->seek_ip_address(query_ip_number(user));
          CHANNEL_D->do_channel( this_object(), "sys",
          sprintf(NOR WHT "%s由 " HIG "%s" NOR WHT "连线进入,IP来自："HIG"%s"NOR,user->name()+"("+capitalize(user->query("id")) + ")", query_ip_number(user), ip_from));  
          }

NEWS_D->check_news(user);
  UPDATE_D->check_user(user, 0);

      {object caishen;
  if(objectp(caishen=find_object("/d/wiz/npc/caishen"))) {
    caishen->check_one(user);
        }
      }
}

varargs void reconnect(object ob, object user, int silent)
{
        object old_link;
  
  // mon 9/15/98
  old_link=user->query_temp("link_ob");
  if(old_link && old_link!=ob)
      destruct(old_link);

  user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
  
  // 5/11/98 mon
  user->set_encoding(ob->query_encoding());

  exec(user, ob);

  user->reconnect();
  if( !silent && !user->query("env/invisibility")) {
          tell_room(environment(user), user->query("name") + "重新连线回到这个世界。Good Luck!\n",
          ({user}));
          CHANNEL_D->do_channel( this_object(), "sys",
                  sprintf("%s由%s重新连线进入。", user->query("name")+"(" + capitalize(user->query("id")) + ")", query_ip_name(user)) );
  }
  UPDATE_D->check_user(user, 1); // this is for reconnect.
}

int check_legal_id(string id)
{
  int i;
  string *legalid;

  i = strlen(id);
  
  if( (strlen(id) < 3) || (strlen(id) > 8 ) ) {
          write("对不起，你的英文名字必须是 3 到 8 个英文字母。\n");
          return 0;
  }
  while(i--)
          if( id[i]<'a' || id[i]>'z' ) {
                  write("对不起，你的英文名字只能用英文字母。\n");
                  return 0;
          }
  legalid = explode(read_file(BANNED_ID), "\n");
  for(i=0; i<sizeof(legalid); i++)   {
     if( id == legalid[i] )   {
            write("对不起，这种名字会造成其他人的困扰。\n");
            return 0;
       }
  }
  return 1;
}

int check_legal_name(string name)
{
  int i;

  i = strlen(name);
  
  if( (strlen(name) < 2) || (strlen(name) > 12 ) ) {
          write("对不起，你的中文名字必须是一到六个中文字。\n");
          return 0;
  }
  while(i--) {
          if( name[i]<=' ' ) {
                  write("对不起，你的中文名字不能用控制字符。\n");
                  return 0;
          }
          if( i%2==0 && !is_chinese(name[i..<0]) ) {
                  write("对不起，请您用「中文」取名字。\n");
                  return 0;
          }
  }
  if( member_array(name, banned_name)!=-1 ) {
          write("对不起，这种名字会造成其他人的困扰。\n");
          return 0;
  }

  return 1;
}

object find_body(string name)
{
  object ob, *body;

  if( objectp(ob = find_player(name)) )
          return ob;
  body = children(USER_OB);
  for(int i=0; i<sizeof(body); i++) {
          ob=body[i];
    if( clonep(ob) && getuid(ob) == name 
            && ob->query("max_gin")>0 ) return ob;
      //check max_gin to avoid damaged user object.
        }

  return 0;
}

int set_wizlock(int level)
{
  if( wiz_level(this_player(1)) <= level )
          return 0;
  if( geteuid(previous_object()) != ROOT_UID )
          return 0;
  wiz_lock_level = level;
  return 1;
}
