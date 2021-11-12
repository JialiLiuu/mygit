#include "common.h"

struct TreeNode
{
    string name;
    string flag;             //flag="1":union "app_xxx":表名
    vector<TreeNode *> List; //from+
    vector<string> index;    //select+
    vector<string> where;    //where+
};

class Solution
{
    string s_select;
    string s_from;
    string s_where;

public:
    string getSelect()
    {
        return s_select;
    }
    string getFrom()
    {
        return s_from;
    }
    string getWhere()
    {
        return s_where;
    }
    string getFlag(string s)
    {
        string::iterator s1 = s.begin();
        int n = 0;
        string f = "0";
        while (s1 != s.end())
        {
            if (*s1 == '(')
                n++;
            else if (*s1 == ')')
                n--;
            else if (*s1 == 'u' & n == 0 & (s.end() - s1) > 5)
            {
                string ss = s.substr(s1 - s.begin() - 1, 7);
                if (ss == " union ")
                {
                    f = "1";
                    break;
                }
            }
            s1++;
        }
        if (f == "1")
        {
            s_select = "";
            s_from = s;
            s_where = "";
        }
        else
        {
            int select = s.find(" select ") + 1;
            int from = s.find(" from ") + 1;
            int where = -1;
            s1 = s.begin() + select;
            n = 0;
            while (s1 != s.end())
            {
                if (*s1 == '(')
                    n++;
                else if (*s1 == ')')
                    n--;
                else if (*s1 == 'w' & n == 0 & (s.end() - s1) > 5)
                {
                    string ss = s.substr(s1 - s.begin() - 1, 7);
                    if (ss == " where ")
                    {
                        where = s1 - s.begin();
                        break;
                    }
                }
                s1++;
            }
            if (where == -1)
                where = s.length();
            s_select = s.substr(select + 6, from - select - 6);
            s_from = s.substr(from + 4, where - from - 4);
            if (where + 5 > s.length())
                s_where = "";
            else
                s_where = s.substr(where + 5, s.length() - where - 5);
        }
        return f;
    }
};

class Tree
{
    TreeNode *node;

public:
    void setNode(TreeNode *n)
    {
        node = n;
    }
    TreeNode *getNode()
    {
        return node;
    }
    void setFlag(string f)
    {
        node->flag = f;
    }
    void setList(vector<string> v)
    {
        vector<TreeNode *> v1 = {};
        for (int i = 0; i < v.size(); i++)
        {
            TreeNode *node1 = new TreeNode;
            node1->flag = v[i];
            v1.push_back(node1);
        }
        node->List = v1;
    }
    void setIndex(vector<string> v)
    {
        node->index = v;
    }
    void setWhere(vector<string> v)
    {
        node->where = v;
    }
    vector<string> getList(string s)
    {
        int t = s.find("select");
        if (t == s.npos)
        {
            node->flag = s;
            return {};
        }
        else if (node->flag != "1")
        {
            vector<string> v;
            int s1 = 0;
            int n = 0;
            int start = 0;
            while (s1 < s.length())
            {
                if (s.at(s1) == '(')
                    n++;
                else if (s.at(s1) == ')')
                    n--;
                else if (s.at(s1) == 'j' & n == 0 & (s.length() - s1) > 4)
                {
                    if (s.substr(s1 - 1, 6) == " join ")
                    {
                        v.push_back(s.substr(start, s1 - start));
                        start = s1 + 4;
                    }
                }
                s1++;
            }
            v.push_back(s.substr(start, s1 - start));
            return v;
        }
        else
        {
            vector<string> v;
            int s1 = 0;
            int n = 0;
            int start = 0;
            while (s1 < s.length())
            {
                if (s.at(s1) == '(')
                    n++;
                else if (s.at(s1) == ')')
                    n--;
                else if (s.at(s1) == 'u' & n == 0 & (s.length() - s1) > 5)
                {
                    if (s.substr(s1 - 1, 7) == " union ")
                    {
                        v.push_back(s.substr(start, s1 - start));
                        start = s1 + 5;
                    }
                }
                s1++;
            }
            v.push_back(s.substr(start, s1 - start));
            return v;
        }
    }
    vector<string> getIndex(string s)
    {
        vector<string> v;
        string ss = "";
        int n = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                n++;
            else if (s[i] == ')')
                n--;
            else if (n == 0 & s[i] == ',')
            {
                v.push_back(ss);
                ss = "";
                continue;
            }
            ss += s[i];
        }
        v.push_back(ss);
        return v;
    }
    vector<string> getWhere(string s)
    {
        return {s};
    }
};

int main()
{
    Solution S;
    string s = " set mapred.output.compress=true;  set hive.exec.compress.output=true;  set mapred.output.compression.codec=com.hadoop.compression.lzo.lzopcodec; set hive.default.fileformat=orc; use app;  insert overwrite table app.app_xz_version_index  partition             (                     dt = ' + day_str +  '             )  --平台版 select   c.bot_num,   a.bot_reception bot_session,   a.pure_bot_reception pure_bot_session,  a.bot_transfer bot_transfer_session,   b.assist_open fz_open_session,   b.assist_reception fz_answer_session,   c.xz_session_num xz_session,   c.allnum all_session,   a.version_id from  (   select    a.dt,    count(distinct sid) allnum,    count(distinct    case     when is_bot = 1      or fz_answer_msg_num > 0     then sid    end) xz_session_num,    count(distinct a.bot_id) bot_num,    '1' version_id   from    (     select      dt,      sid,      bot_id,      is_bot,      fz_answer_msg_num     from      app.app_xz_session_di     where      dt = ' + day_str +  '      and bot_id > 0    )    a   join    (     select distinct      bot_id     from      fdm.fdm_isobk_bot_vender_chain     where      dp = 'active'      and yn = 1      and bot_id not in(80, 74)      and version_id in(439, 440, 445, 452)    )    b   on    a.bot_id = b.bot_id   group by    a.dt  )  c join  (   select    a.dt,    sum(a.fz_session_num) assist_open, --辅助开启    sum(a.fz_answer_session_num) assist_reception, --辅助回复    '1' version_id   from    (     select      dt,      bot_id,      fz_session_num, --辅助开启      fz_answer_session_num --辅助回复     from      app.app_xz_fz_index     where      dt = ' + day_str +  '    )    a   join    (     select distinct      bot_id     from      fdm.fdm_isobk_bot_vender_chain     where      dp = 'active'      and yn = 1      and bot_id not in(80, 74)      and version_id in(439, 440, 445, 452)    )    b   on    a.bot_id = b.bot_id   group by    a.dt  )  b on c.dt = b.dt join  (   select    a.dt,    sum(a.consult_num) + sum(a.transfer_num) bot_reception, --机器接待    sum(a.consult_num) pure_bot_reception, --纯机接待    sum(a.transfer_num) bot_transfer, --机转    '1' version_id   from    (     select      dt,      bot_id,      consult_num, --纯机      transfer_num --机转出     from      app.app_xz_bot_index     where      dt = ' + day_str +  '    )    a   join    (     select distinct      bot_id     from      fdm.fdm_isobk_bot_vender_chain     where      dp = 'active'      and yn = 1      and bot_id not in(80, 74)      and version_id in(439, 440, 445, 452)    )    b   on    a.bot_id = b.bot_id   group by    a.dt  )  a on a.dt = b.dt  union all  --企业版 select   c.bot_num,   a.bot_reception bot_session,   a.pure_bot_reception pure_bot_session,   a.bot_transfer bot_transfer_session,   b.assist_open fz_open_session,   b.assist_reception fz_answer_session,  c.xz_session_num xz_session,   c.allnum all_session,   a.version_id from  (   select    a.dt,    count(distinct    case     when is_bot = 1     then sid    end) + count(distinct    case     when fz_answer_msg_num > 0     then sid    end) xz_session_num,    count(distinct sid) allnum,    count(distinct a.bot_id) bot_num,    '2' version_id   from    (     select      dt,      sid,      bot_id,      is_bot,      fz_answer_msg_num     from      app.app_xz_session_di     where      dt = ' + day_str +  '      and bot_id > 0    )    a   join    (     select distinct      bot_id     from      fdm.fdm_isobk_bot_vender_chain     where      dp = 'active'      and yn = 1      and bot_id not in(80, 74)      and version_id in(458, 460)    )    b   on    a.bot_id = b.bot_id   group by    a.dt  )  c join  (   select    a.dt,    sum(a.fz_session_num) assist_open,     sum(a.fz_answer_session_num) assist_reception,    '2' version_id   from    (     select      dt,      bot_id,      fz_session_num,       fz_answer_session_num      from      app.app_xz_fz_index     where      dt = ' + day_str +  '    )    a   join    (     select distinct      bot_id     from      fdm.fdm_isobk_bot_vender_chain     where      dp = 'active'      and yn = 1      and bot_id not in(80, 74)      and version_id in(458, 460)    )    b   on    a.bot_id = b.bot_id   group by    a.dt  )  b on c.dt = b.dt join  (   select    a.dt,    sum(a.consult_num) + sum(a.transfer_num) bot_reception, --机器接待    sum(a.consult_num) pure_bot_reception, --纯机接待    sum(a.transfer_num) bot_transfer, --机转    '2' version_id   from    (     select      dt,      bot_id,      consult_num, --纯机      transfer_num --机转出     from      app.app_xz_bot_index     where      dt = ' + day_str +  '    )    a   join    (     select distinct      bot_id     from      fdm.fdm_isobk_bot_vender_chain     where      dp = 'active'      and yn = 1      and bot_id not in(80, 74)      and version_id in(458, 460)    )    b   on    a.bot_id = b.bot_id   group by    a.dt  )  a on a.dt = b.dt  union all  --其他版 select  c.bot_num, --机器人量  a.bot_reception bot_session, --机器接待会话量  a.pure_bot_reception pure_bot_session, --纯机接待会话量  a.bot_transfer bot_transfer_session, --机转出会话量  b.assist_open fz_open_session, --辅助开启会话量  b.assist_reception fz_answer_session, --辅助回复会话量  c.xz_session_num xz_session, --小智服务会话量  c.allnum all_session, --总会话量  a.version_id--版本号 from  (   select    a.dt,    count(distinct    case     when is_bot = 1     then sid    end) + count(distinct    case     when fz_answer_msg_num > 0     then sid    end) xz_session_num,    count(distinct sid) allnum,    count(distinct a.bot_id) bot_num,    '3' version_id   from    (     select      dt,      sid,      bot_id,      is_bot,      fz_answer_msg_num     from      app.app_xz_session_di     where      dt = ' + day_str +  '      and bot_id > 0    )    a   join    (     select distinct      bot_id     from      fdm.fdm_isobk_bot_vender_chain     where      dp = 'active'      and yn = 1      and bot_id not in(80, 74)      and version_id not in(458, 460, 439, 440, 445, 452)    )    b   on    a.bot_id = b.bot_id   group by    a.dt  )  c join  (   select    a.dt,    sum(a.fz_session_num) assist_open, --辅助开启    sum(a.fz_answer_session_num) assist_reception, --辅助回复    '3' version_id   from    (     select      dt,      bot_id,      fz_session_num, --辅助开启      fz_answer_session_num --辅助回复     from      app.app_xz_fz_index     where      dt = ' + day_str +  '    )    a   join    (     select distinct      bot_id     from      fdm.fdm_isobk_bot_vender_chain     where      dp = 'active'      and yn = 1      and bot_id not in(80, 74)      and version_id not in(458, 460, 439, 440, 445, 452)    )    b   on    a.bot_id = b.bot_id   group by    a.dt  )  b on c.dt = b.dt join  (   select    a.dt,    sum(a.consult_num) + sum(a.transfer_num) bot_reception, --机器接待    sum(a.consult_num) pure_bot_reception, --纯机接待    sum(a.transfer_num) bot_transfer, --机转    '3' version_id   from    (     select      dt,      bot_id,      consult_num, --纯机      transfer_num --机转出     from      app.app_xz_bot_index     where      dt = ' + day_str +  '    )    a   join    (     select distinct      bot_id     from      fdm.fdm_isobk_bot_vender_chain     where      dp = 'active'      and yn = 1      and bot_id not in(80, 74)      and version_id not in(458, 460, 439, 440, 445, 452)    )    b   on    a.bot_id = b.bot_id   group by    a.dt  )  a on a.dt = b.dt ";

    vector<TreeNode *> nodes;
    TreeNode *firstNode = new TreeNode;
    firstNode->flag = s;
    nodes.push_back(firstNode);
    Tree T;
    for (int i = 0; i < nodes.size(); i++)
    {
        string flag = S.getFlag(nodes[i]->flag);
        string select = S.getSelect();
        string from = S.getFrom();
        string where = S.getWhere();

        T.setNode(nodes[i]);
        T.setFlag(flag);
        T.setIndex(T.getIndex(select));
        T.setList(T.getList(from));
        T.setWhere(T.getWhere(where));
        TreeNode *node = T.getNode();
        for (int j = 0; j < node->List.size(); j++)
        {
            nodes.push_back(node->List[j]);
        }
    }
    //遍历nodes数组,List为空的是根节点,记录其flag
    vector<string> tables;
    for (int i = 0; i < nodes.size(); i++)
    {
        if (nodes[i]->List.size() > 0)
            continue;
        else
            tables.push_back(nodes[i]->flag);
    }
    cout << firstNode->flag << endl;
}