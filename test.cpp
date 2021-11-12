#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

//Q1:Tree.Class setList找出别名a/b/...,添加TreeNode*->name

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
            int kk = s.find(")");
            if (kk == s.npos)
                node->flag = s;
            else
                node->flag = s.substr(0, kk);
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

class Test
{
public:
    char *function(char *sql, char *tables)
    {
        Solution S;

        std::string s = std::string(sql);

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
        for (int i = 0; i < nodes.size(); i++)
        {
            if (nodes[i]->List.size() > 0)
                continue;
            else
            {
                strcat(tables, "+");
                strcat(tables, nodes[i]->flag.c_str());
            }
            // tables = tables + "+" + nodes[i]->flag;
        }

        return tables;
    }
};

int main()
{
    Test t;
    char *s = (char *)"  set mapred.output.compress=true;  set hive.exec.compress.output=true;  set mapred.output.compression.codec=com.hadoop.compression.lzo.lzopcodec; set hive.default.fileformat=orc; use app;  insert overwrite table app.app_xz_bot_index  partition             (                     dt = ' + day_str +  '             )  select  a.bot_id,  a.vender_id,  consult_num,  transfer_num,  evaluation_num,  satisfied_num,  customer_msg_num,  customer_num,  pure_customer_num,  transfer_customer_num,  trigger_transfer_num,  transfer24h_num,  hit_msg_num,  config_err_msg_num,  answer_msg_num from  (   select    bot_id,    vender_id,    count(distinct    case     when transfer_type = 0     then sid    end) as consult_num,    count(distinct    case     when transfer_type = 3     then sid    end) as transfer_num,    count(distinct    case     when degree >= 0     then sid    end) as evaluation_num,    count(distinct    case     when degree > 50     then sid    end) as satisfied_num,    sum(customer_msg_num) as customer_msg_num,    count(distinct customer) as customer_num,    count(distinct    case     when transfer_type = 0     then customer    end) as pure_customer_num,    count(distinct    case     when transfer_type = 3     then customer    end) as transfer_customer_num,    count(distinct    case     when bot_trigger_transfer = 1     then sid    end) as trigger_transfer_num   from    app.app_xz_session_di   where    dt = ' + day_str +  '    and is_bot = 1   group by    bot_id,    vender_id  )  a join  (   select    day24h_before_jimi.bot_id,    day24h_before_jimi.vender_id,    count(distinct day24h_before_jimi.sid) as transfer24h_num   from    (     select      bot_id,      vender_id,      sid,      customer,      open_time,      transfer_to_cid     from      app.app_xz_session_di     where      dt = ' + day_str2 +  '      and is_bot = 1    )    day24h_before_jimi   join    (     select      bot_id,      vender_id,      dd_mall_id     from      app.app_aixiaozhi_vender_mall_info_da_bak_v2    )    mall   on    day24h_before_jimi.bot_id = mall.bot_id    and day24h_before_jimi.vender_id = mall.vender_id   join    (     select      customer,      open_time,      mall_id     from      app.app_xz_session_di     where      dt >= ' + day_str2 +  '      and dt <= ' + day_str +  '      and is_bot = 0    )    day24h_im   on    day24h_before_jimi.customer = day24h_im.customer    and mall.dd_mall_id = day24h_im.mall_id   where    (     day24h_im.customer is not null     and unix_timestamp(day24h_before_jimi.open_time) < unix_timestamp(day24h_im.open_time)     and unix_timestamp(day24h_im.open_time) - unix_timestamp(day24h_before_jimi.open_time) < 24 * 60 * 60    )    or transfer_to_cid is not null   group by    day24h_before_jimi.bot_id,    day24h_before_jimi.vender_id  )  b on a.bot_id = b.bot_id  and a.vender_id = b.vender_id join  (   select    a.bot_id,    a.vender_id,    count(distinct a.message_id) as ask_msg_num,    count(distinct b.up_id) as hit_msg_num,    count(distinct c.message_id) as config_err_msg_num,    count(distinct d.message_id) as answer_msg_num   from    (     --所有上行消息     select      dt,      bot_id,      vender_id,      message_id,      final_cate_name     from      app.app_jimi3_ask_info_clean     where      dt = ' + day_str +  '      and app_name = 'xz-jimi3-nlu'      and bot_type = '2'    )    a   join    (     --识别的消息     --以下特殊答案不计入识别：猜你想问、猜你还想问、usp卖点推荐、智能推荐、转人工     select      dt,      up_id,      answer_type,      classify_name     from      app.app_jimi3_intention_result     where      dt = ' + day_str +  '      and app_name = 'xz-jimi3-am'      and      (       (        answer_type in('nlu_key', 'quick_entry', 'welcome', 'deep_qa', 'content', 'answer_id', 'kb_qa', 'answer', 'crop_image')        and classify_name <> 'other'       )       or       (        --faq输出，必须答案list包含faq提供的答案（存在全部是guess提供答案的情况，这种不算识别）        answer_type = 'faq_id'        and answer_values like '%answergrouptype___faq%'       )       or       (        --高危敏感词、单字符、乱码不算识别        answer_type = 'custom'        and sub_answer_type not in('singe_word', 'garbled', 'sensitive_high')       )      )    )    b   on    a.message_id = b.up_id   join    (     --由于答案配置原因未识别的消息     --因为答案配置原因导致未出答案的消息：答案未配置、时效不匹配、答案不匹配等8种情况     select      dt,      message_id,      no_answer_reason     from      app.app_xz_robot_no_answer_reason_info     where      dt = ' + day_str +  '      and no_answer_reason in('答案未配置', '时效不匹配', '答案不匹配', '未命中答案关键词', '未命中商品属性', '未命中订单状态', '未指定sku参数', '答案超长')    )    c   on    b.up_id = c.message_id   join    (     -- 应答成功的消息     select      dt,      message_id,      answer_node,      no_answer_reason     from      app.app_xz_robot_no_answer_reason_info     where      dt = ' + day_str +  '      and no_answer_reason is null      and answer_node not in('guess', '高危敏感词', '单字符', '乱码')    )    d   on    b.up_id = d.message_id   group by    a.bot_id,    a.vender_id  )  c on a.bot_id = c.bot_id  and a.vender_id = c.vender_id ";
    char tables[1000];
    // char *ans = (char *)(std::string("  ")).c_str();
    cout << t.function(s, tables) << endl;
}

// extern "C"
// {
//     Test *test_new()
//     {
//         return new Test;
//     }
//     char *main1(Test *t, char *ss)
//     {
//         char *tables = new char[1000];
//         try
//         {
//             return t->function(ss, tables);
//         }
//         catch (exception e)
//         {
//             return "wrong";
//         }
//     }
// }
