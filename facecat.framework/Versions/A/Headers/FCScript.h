/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifndef __FCSCRIPT_H__
#define __FCSCRIPT_H__
#pragma once
#define FUNCTIONID_CHUNK 40
#define FUNCTIONID_FUNCVAR 10
#define FUNCTIONID_FUNCTION 9
#define FUNCTIONID_VAR 82

#include "stdafx.h"
#include "FCTran.h"
#include "Enums.h"
#include "FCDataTable.h"
#include "ChartDiv.h"
#include "BaseShape.h"

namespace FaceCat{
    class FCScript;
    class CMathElement;
    
    /*
     * 传递数据
     */
    struct LPDATA
    {
    public:
        LPDATA()
        {
        };
        /*
         * 最后一个值
         */
        double lastvalue;
        /*
         * 第一个值
         */
        double first_value;
        /*
         * 模式
         */
        int mode;
        /*
         * 和
         */
        double sum;
    };
    
    /*
     * 变量
     */
    class CVariable{
    public:
        /**
         * 变量
         */
        CVariable();
        /*
         * 构造函数
         */
        virtual ~CVariable();
        /**
         * 柱状图
         */
        BarShape *m_barShape;
        /**
         * K线
         */
        CandleShape *m_candleShape;
        /**
         * 表达式
         */
        String m_expression;
        /**
         * 字段
         */
        int m_field;
        /**
         * 字段的索引
         */
        int m_fieldIndex;
        /**
         * 显示字段
         */
        String m_fieldText;
        /**
         * 方法的编号
         */
        int m_functionID;
        /**
         * 方法名称
         */
        String m_funcName;
        /**
         * 指标
         */
        FCScript *m_script;
        /**
         * 行数
         */
        int m_line;
        PointShape *m_pointShape;
        /**
         * 折线图
         */
        PolylineShape *m_polylineShape;
        /**
         * 键值
         */
        String m_name;
        /**
         * 变量
         */
        CVariable **m_parameters;
        /*
         * 变量长度
         */
        int m_parametersLength;
        /**
         * 分割后的表达式
         */
        CMathElement **m_splitExpression;
        /*
         * 表达式长度
         */
        int m_splitExpressionLength;
        /**
         * 临时字段
         */
        int *m_tempFields;
        /*
         * 临时字段长度
         */
        int m_tempFieldsLength;
        /**
         * 置临时字段的索引
         */
        int *m_tempFieldsIndex;
        /*
         * 置临时字段的长度
         */
        int m_tempFieldsIndexLength;
        /**
         * 文字
         */
        TextShape *m_textShape;
        /**
         * 类型
         */
        int m_type;
        /**
         * 常量数值
         */
        double m_value;
        /**
         * 创建空的字段
         */
        void createTempFields(int count);
    };
    
    /*
     * 算术单元
     */
    class CMathElement{
    public:
        /*
         * 构造函数
         */
        CMathElement();
        /*
         * 构造函数
         */
        CMathElement(int type, double value);
        /*
         * 析构函数
         */
        virtual ~CMathElement();
        /**
         * 类型
         */
        int m_type;
        /**
         * 常量数值
         */
        double m_value;
        /**
         * 变量
         */
        CVariable *m_var;
    };
    
    /*
     * 算术单元扩展
     */
    class CMathElementEx : public CMathElement{
    public:
        /*
         * 下个单元
         */
        CMathElementEx *m_next;
        /*
         * 构造函数
         */
        CMathElementEx(int type, double value):CMathElement(type, value){
            m_next = 0;
        }
        /*
         * 析构函数
         */
        virtual ~CMathElementEx(){
            if(m_next){
                delete m_next;
                m_next = 0;
            }
        }
    };
    
    /*
     * 方法
     */
    class CFunction{
    public:
        /*
        * 构造函数
        */
        CFunction();
        /*
        * 构造函数
        */
        CFunction(int pID, String name);
        /*
         * 析构函数
         */
        virtual ~CFunction();
        /*
         * ID
         */
        int m_ID;
        /*
         * 名称
         */
        String m_name;
        /*
         * 类型
         */
        int m_type;
    public:
        /*
         * 计算表
         */
        virtual double onCalculate(CVariable *var);
    };
    
    /*
     * 临时变量
     */
    class CVar{
    public:
        /**
         * 是否静态变量
         */
        bool m_isStatic;
        /**
         * 列表
         */
        ArrayList<String> *m_list;
        /**
         * 哈希表
         */
        HashMap<String, String> *m_map;
        /**
         * 数值
         */
        double m_num;
        /**
         * 字符串
         */
        String m_str;
        /**
         * 类型
         */
        int m_type;
        /**
         * 上级变量
         */
        CVar *m_parent;
    public:
        /*
         * 构造函数
         */
        CVar(){
            m_isStatic = false;
            m_list = 0;
            m_map = 0;
            m_parent = 0;
        }
        /*
         * 析构函数
         */
        virtual ~CVar(){
            if (m_list){
                delete m_list;
                m_list = 0;
            }
            if (m_map){
                delete m_map;
                m_map = 0;
            }
            m_parent = 0;
        }
    public:
        /**
         * 获取文字
         * @param script   指标
         * @param name        名称
         * @returns 数值
         */
        virtual String getText(FCScript *script, CVariable *name);
        /**
         * 获取值
         * @param script   指标
         * @param name        名称
         * @returns 数值
         */
        virtual double getValue(FCScript *script, CVariable *name);
        /**
         * 创建变量
         * @param script   指标
         * @param name        名称
         * @param value       值
         */
        virtual double onCreate(FCScript *script, CVariable *name, CVariable *value);
        /**
         * 设置值
         * @param script   指标
         * @param name        名称
         * @param value       值
         */
        virtual void setValue(FCScript *script, CVariable *name, CVariable *value);
    };
    
    /*
     * 临时变量工厂
     */
    class CVarFactory{
    public:
        /**
         * 创建变量
         * @returns 变量
         */
        virtual CVar* createVar(){
            return new CVar;
        }
    };
    
    /*
     * 脚本
     */
    class FCScript{
    public:
        String KEYWORD_LIST;
        String KEYWORD_MAP;
        String KEYWORD_TRUE;
        String KEYWORD_FALSE;
        String KEYWORD_FUNCTION;
        String KEYWORD_CONST;
        String KEYWORD_EQ;
        String KEYWORD_MH;
        String KEYWORD_MHE;
        String KEYWORD_FUNCVAR;
        String KEYWORD_REF;
        String KEYWORD_VAR2;
        String KEYWORD_CHUNK;
        String KEYWORD_AND;
        String KEYWORD_OR;
        String KEYWORD_ELSE;
        String KEYWORD_ELSEIF;
        String KEYWORD_RETURN;
        String KEYWORD_VAR;
        String KEYWORD_SET;
        String KEYWORD_STATIC;
        String KEYWORD_BREAK;
        String KEYWORD_CONTINUE;
        String KEYWORD_FOR;
        String KEYWORD_WHILE;
        String KEYWORD_DOTIMES;
        char CHAR_MH;
        char CHAR_EQ;
        char CHAR_ADD;
        char CHAR_SUB;
        char CHAR_NEQ;
        String KEYWORD_GTE;
        String KEYWORD_LTE;
        String KEYWORD_NE1;
        String KEYWORD_NE2;
        String KEYWORD_ADD;
        String KEYWORD_MULTIPLY;
        String KEYWORD_DIVIDE;
        String KEYWORD_E;
        String KEYWORD_GT;
        String KEYWORD_LT;
        String KEYWORD_MOD;
    public:
        pthread_mutex_t mutex_x;
        /**
         * 参数列表
         */
        HashMap<String,double> m_defineParams;
        /**
         * 方法列表
         */
        HashMap<String, CFunction*> m_functions;
        /**
         * 方法的哈希表
         */
        HashMap<Integer, CFunction*> m_functionsMap;
        /**
         * 当前正在计算的索引
         */
        int m_index;
        /**
         * 语句集合
         */
        ArrayList<CVariable*> m_lines;
        /**
         * 系统颜色
         */
        ArrayList<Long> m_systemColors;
        /*
         * 是否停止
         */
        bool m_stop;
        /**
         * TAG值
         */
        Object m_tag;
        /**
         * 方法变量表
         */
        HashMap<String, CVariable*> m_tempFunctions;
        /**
         * 变量表
         */
        HashMap<String, CVariable*> m_tempVariables;
        /**
         * 方法缓存
         */
        ArrayList<CVariable*> m_variables;
        /**
         * 临时变量工厂
         */
        CVarFactory *m_varFactory;
        /**
         * 方法标识字符串
         */
        String VARIABLE;
        /**
         * 标识字符串2
         */
        String VARIABLE2;
        /**
         * 标识字符串3
         */
        String VARIABLE3;
    public:
        /**
         * 在左轴或右轴
         */
        AttachVScale m_attachVScale;
        /**
         * 跳出标识
         */
        int m_break;
        /**
         * 数据源
         */
        FCDataTable *m_dataSource;
        /**
         * 图层
         */
        ChartDiv *m_div;
        /**
         * 名称
         */
        String m_name;
        /**
         * 结果
         */
        double m_result;
        /**
         * 复合结果
         */
        CVar m_resultVar;
        /*
         * 脚本
         */
        String m_script;
        /*
        * 用Tab表示代码块
        */
        bool m_isTabBrick;
    public:
        Long m_downColor;
        Long m_midColor;
        Long m_upColor;
    public:
        /**
         * 分析语句中包含的方法和变量
         */
        void analysisVariables(String *sentence, int line, String funcName, String fieldText, bool isFunction);
        /**
         * 加载脚本行
         * @param line  脚本行
         */
        void analysisScriptLine(String line);
        /**
         * 对表达式进行求值，求值之前会先进行语法校验
         * @param expr      要求值的表达式
         * @returns 求值结果
         */
        double calculate(CMathElement **expr, int exprLength);
        /**
         * 调用方法
         * @param var   变量
         * @returns 结果
         */
        double callFunction(CVariable *var);
        /**
         * 删除临时变量
         */
        void deleteTempVars();
        /**
         * 删除临时变量
         * @param var  变量
         */
        void deleteTempVars(CVariable *var, int index);
        /**
         * 根据字符串获取颜色
         * @param strColor  字符串
         * @returns 颜色
         */
        Long getColor(const String& strColor);
        /**
         * 从数据源中获取计算指标需要的MATH_STRUCT结构
         * @param   fieldIndex   字段
         * @param   mafieldIndex  保存MA值字段
         * @param   index    数据索引
         * @param   n        周期
         * @returns MATH_STRUCT结构
         */
        LPDATA getDatas(int fieldIndex, int mafieldIndex, int index, int n, int mode);
        /**
         * 获取线的宽度
         * @param strLine  线的描述
         * @returns 线宽
         */
        float getLineWidth(const String& strLine);
        /**
         * 获取中间语言
         * @param script   脚本
         * @param lines    行
         */
        int getMiddleScript(const String& script, ArrayList<String> *lines);
        /**
         * 获取操作符号
         * @param   op    字符串
         * @returns 操作符号
         */
        int getOperator(const String& op);
        /*
         * 是否数字
         */
        bool isNumeric(const String& str);
        /**
         * 替换方法和变量
         * @param  parameter  参数
         * @returns 替换后语句
         */
        String replace(const String& parameter);
        /**
         * 把表达式拆分成字符串数组，用于后面的检查和求值
         * @param expression  表达式
         * @returns  从左到右返回从下标0开始的字符串数组
         */
        CMathElement** splitExpression(const String& expression, int *sLength);
        /**
         * 把表达式拆分成字符串数组，用于后面的检查和求值
         * @param expression  表达式
         * @returns  从左到右返回从下标0开始的字符串数组
         */
        String* splitExpression2(const String& expression, int *sLength);
    public:
        /*
         * 构造函数
         */
        FCScript();
        /*
         * 析构函数
         */
        virtual ~FCScript();
        /**
         * 主要变量
         */
        HashMap<String ,CVariable*> m_mainVariables;
        /**
         * 临时变量
         */
        HashMap<Integer, CVar*> m_tempVars;
        /**
         * 获取在左轴或右轴
         */
        virtual AttachVScale getAttachVScale();
        /**
         * 设置在左轴或右轴
         */
        virtual void setAttachVScale(AttachVScale value);
        /**
         * 获取数据源
         */
        virtual FCDataTable* getDataSource();
        /**
         * 设置数据源
         */
        virtual void setDataSource(FCDataTable *value);
        /**
         * 获取图层
         */
        virtual ChartDiv* getDiv();
        /**
         * 设置图层
         */
        virtual void setDiv(ChartDiv *value);
        /**
         * 获取当前正在计算的索引
         */
        virtual int getIndex();
        /**
         * 获取名称
         */
        virtual String getName();
        /**
         * 设置名称
         */
        virtual void setName(const String& value);
        /**
         * 获取结果
         */
        virtual double getResult();
        /*
         * 获取脚本
         */
        virtual String getScript();
        /**
         * 设置脚本
         */
        virtual void setScript(const String& value);
        /**
         * 获取系统颜色
         */
        virtual ArrayList<Long> getSystemColors();
        /**
         * 设置系统颜色
         */
        virtual void setSystemColors(ArrayList<Long> value);
        /*
        * 是否用Tab表示代码块
        */
        bool isTabBrick();
        /*
        * 设置是否用Tab表示代码块
        */
        void setTabBrick(bool value);
        /**
         * 获取TAG值
         */
        virtual Object getTag();
        /**
         * 设置TAG值
         */
        virtual void setTag(Object value);
        /**
         * 获取临时变量工厂
         */
        virtual CVarFactory* getVarFactory();
        /**
         * 设置临时变量工厂
         */
        virtual void setVarFactory(CVarFactory *value);
    public:
        /**
         * 添加方法
         * @param function  方法
         */
        void addFunction(CFunction *function);
        /**
         * 调用方法
         * @param funcName  方法名称
         * @returns 返回值
         */
        double callFunction(String funcName);
        /*
         * 清除数据
         */
        void clear();
        /**
         * 获取所有的方法
         */
        ArrayList<CFunction*> getFunctions();
        /**
         * 获取所有的图形
         */
        ArrayList<BaseShape*> getShapes();
        /**
         * 获取文本
         * @param   var   变量
         * @returns 文本
         */
        String getText(CVariable *var);
        /**
         * 获取数值
         * @param   var   变量
         * @returns  运算结果
         */
        double getValue(CVariable *var);
        /**
         * 获取变量
         * @param  name  名称
         * @returns 变量
         */
        CVariable* getVariable(const String& name);
        /*
         * 锁
         */
        void lock();
        /**
         * 计算指标
         * @param  index   索引
         */
        void onCalculate(int index);
        /**
         * 移除方法
         * @param function  方法
         */
        void removeFunction(CFunction *function);
        /**
         * 设置数据源字段
         * @param key   键
         * @param value  值
         */
        void setSourceField(const String& key, int value);
        /**
         * 设置数据源值
         * @param key   键
         * @param value  值
         */
        void setSourceValue(int index, const String& key, double value);
        /**
         * 设置变量的值
         * @param variable  变量
         * @param parameter  值
         */
        void setVariable(CVariable *variable, CVariable *parameter);
        /*
         * 解锁
         */
        void unLock();
    public:
        /**
         * 计算绝对值
         * @param var   变量
         * @returns  绝对值
         */
        double ABS2(CVariable *var);
        /**
         * 计算自适应均线值
         * @param var   变量
         * @returns  自适应均线值
         */
        double AMA(CVariable *var);
        /**
         * 计算反余弦值
         * @param var   变量
         * @returns  反余弦值
         */
        double ACOS(CVariable *var);
        /**
         * 计算反余弦值
         * @param var   变量
         * @returns  反正弦值
         */
        double ASIN(CVariable *var);
        /**
         * 计算反正切值
         * @param var   变量
         * @returns  反正切值
         */
        double ATAN(CVariable *var);
        /**
         * 计算平均绝对偏差
         * @param var   变量
         * @returns  平均绝对偏差
         */
        double AVEDEV(CVariable *var);
        /**
         * 计算数据条目
         * @param var   变量
         * @returns  数据条目
         */
        int BARSCOUNT(CVariable *var);
        /**
         * 计算上一次条件成立到当前的周期数
         * @param var   变量
         * @returns  周期数
         */
        int BARSLAST(CVariable *var);
        /**
         * 第一个条件成立到当前的周期数
         * @param var   变量
         * @returns  周期数
        */
        int BARSSINCE(CVariable *var);
        /**
         * N周期内第一个条件成立到当前的周期数
         * @param var   变量
         * @returns  周期数
        */
        int BARSSINCEN(CVariable *var);
        /**
         * 判断表达式
         * @param var   变量
         * @returns  结果
         */
        int BETWEEN(CVariable *var);
        /**
         * 跳出循环
         * @param var   变量
         * @returns  结果
         */
        int BREAK(CVariable *var);
        /**
         * 计算向上接近的整数
         * @param var   变量
         * @returns  向上接近的整数
         */
        double CEILING(CVariable *var);
        /**
         * 执行代码块
         * @param var   变量
         * @returns  返回值
         */
        double CHUNK(CVariable *var);
        /**
         * 取A最后的值(非序列值)转为字符串,小数位数N
         * @param var   变量
         * @returns  返回值
        */
        int CON2STR(CVariable *var);
        /**
         * 继续循环
         * @param var   变量
         * @returns  结果
         */
        int CONTINUE(CVariable *var);
        /**
         * 计算余弦值
         * @param var   变量
         * @returns  余弦值
         */
        double COS(CVariable *var);
        /**
         * 协方差
         * @param var   变量
         * @returns  结果
        */
        double COVAR(CVariable *var);
        /**
         * 统计满足条件的周期数
         * @param var   变量
         * @returns  周期数
         */
        int COUNT(CVariable *var);
        /**
         * 判断是否穿越
         * @param var   变量
         * @returns  穿越:1 不穿越:0
         */
        int CROSS(CVariable *var);
        /**
         * 获取当前数据索引
         * @param var   变量
         * @returns  数据索引
         */
        int CURRBARSCOUNT(CVariable *var);
        /**
         * 取得该周期从1900以来的的年月日.
         * @param var   变量
         * @returns  年月日
         */
        int DATE(CVariable *var);
        /**
         * 返回日期
         * @param var   变量
         * @returns  日期
         */
        int DAY(CVariable *var);
        /**
         * 删除变量
         * @param var   变量
         * @returns  结果
         */
        int DELETE2(CVariable *var);
        /*
        * 计算数据偏差平方和
         * @param var   变量
         * @returns  结果
        */
        double DEVSQ(CVariable *var);
        /**
         * 计算动态移动平均
         * @param var   变量
         * @returns  动态移动平均
         */
        double DMA(CVariable *var);
        /**
         * 循环执行一定次数
         * @param var   变量
         * @returns  状态
         */
        int DOTIMES(CVariable *var);
        /**
         * 执行DOWHILE循环
         * @param var   变量
         * @returns  状态
         */
        int DOWHILE(CVariable *var);
        /**
         * 返回是否连跌周期数
         * @param var   变量
         * @returns  是否连跌周期数
         */
        int DOWNNDAY(CVariable *var);
        /**
         * 绘制点图
         * @param var   变量
         * @returns  0
         */
        double DRAWICON(CVariable *var);
        /**
         * 绘制K线
         * @param var   变量
         * @returns  0
         */
        double DRAWKLINE(CVariable *var);
        /**
         * 返回无效数
         * @param var   变量
         * @returns  无效数
         */
        double DRAWNULL(CVariable *var);
        /**
         * 绘制文字
         * @param var   变量
         * @returns  0
         */
        double DRAWTEXT(CVariable *var);
        /**
         * 判断是否存在
         * @param var   是否存在
         * @returns  0
         */
        int EXIST(CVariable *var);
        /**
         * 判断是否存在
         * @param var   是否存在
         * @returns  0
        */
        int EXISTR(CVariable *var);
        /**
         * 计算指数移动平均
         * @param var   是否存在
         * @returns  指数移动平均
         */
        double EMA(CVariable *var);
        /**
         * 判断是否一直存在
         * @param var   是否存在
         * @returns  是否一直存在
         */
        int EVERY(CVariable *var);
        /**
         * 计算指数平滑移动平均
         * @param var   是否存在
         * @returns  指数平滑移动平均
         */
        double EXPMEMA(CVariable *var);
        /**
         * 计算e的X次幂
         * @returns e的X次幂
         */
        double EXP(CVariable *var);
        /**
         * 字符串查找
         * @param var 变量
         * @returns 状态
        */
        int FINDSTR(CVariable *var);
        /**
         * 计算向下接近的整数
         * @param var  变量
         * @returns 向下接近的整数
         */
        double FLOOR(CVariable *var);
        /**
         * 执行FOR循环
         * @returns 状态
         */
        int FOR(CVariable *var);
        /**
         * 线性回归预测值
         * @param var 变量
         * @returns 状态
        */
        int FORCAST(CVariable *var);
        /**
         * 执行方法
         * @param var  变量
         * @returns 返回值
         */
        double FUNCTION(CVariable *var);
        /**
         * 定义变量
         * @param var  变量
         * @returns 数值
         */
        double FUNCVAR(CVariable *var);
        /**
         * 计算指定字段一段区间内的最大值
         * @param var  变量
         * @returns 数值
         */
        double GET(CVariable *var);
        /**
         * 计算指定字段一段区间内的最大值
         * @param var  变量
         * @returns 最大值
         */
        double HHV(CVariable *var);
        /**
         * 计算指定字段一段区间内的最大值距今天的天数
         * @param var  变量
         * @returns 天数
         */
        double HHVBARS(CVariable *var);
        /**
         * 求高值名次
         * @param var  变量
         * @returns 天数
        */
        int HOD(CVariable *var);
        /**
         * 返回小时
         * @param var  变量
         * @returns 小时
         */
        int HOUR(CVariable *var);
        /**
         * 选择函数
         * @param var  变量
         * @returns 结果
         */
        double IF(CVariable *var);
        /**
         * 反选择函数
         * @param var  变量
         * @returns 反选择结果
         */
        double IFN(CVariable *var);
        /**
         * 计算沿X绝对值减小方向最接近的整数
         * @param var  变量
         * @returns 最接近的整数
         */
        double INTPART(CVariable *var);
        /**
         * 判断是否持续存在
         * @param var  变量
         * @returns 是否持续存在
         */
        int LAST(CVariable *var);
        /**
         * 求自然对数
         * @param var  变量
         * @returns 自然对数
         */
        double LN(CVariable *var);
        /**
         * 计算指定字段一段区间内的最小值
         * @param var  变量
         * @returns 最小值
         */
        double LLV(CVariable *var);
        /**
         * 计算指定字段一段区间内的最小值距离今天的天数
         * @param var  变量
         * @returns 天数
         */
        double LLVBARS(CVariable *var);
        /**
         * 求低值名次
         * @param var  变量
         * @returns 天数
        */
        int LOD(CVariable *var);
        /**
         * 计算常用对数
         * @param var  变量
         * @returns 常用对数
         */
        double LOG(CVariable *var);
        /**
         * 两条线维持一定周期后交叉
         * @param var  变量
         * @returns 数值
        */
        int LONGCROSS(CVariable *var);
        /**
         * 计算简单移动平均
         * @param var  变量
         * @returns 简单移动平均
         */
        double MA(CVariable *var);
        /**
         * 当前系统的日期
         * @param var  变量
         * @returns 值
        */
        int MACHINEDATE(CVariable *var);
        /**
         * 当前系统的时间
         * @param var  变量
         * @returns 值
        */
        int MACHINETIME(CVariable *var);
        /**
         * 当前系统的周
         * @param var  变量
         * @returns 值
        */
        int MACHINEWEEK(CVariable *var);
        /**
         * 计算最大值
         * @param var  变量
         * @returns 最大值
         */
        double MAX2(CVariable *var);
        /**
         * 计算最大值
         * @param var  变量
         * @returns 最大值
         */
        double MAX6(CVariable *var);
        /**
         * 计算指数移动平均
         * @param var  变量
         * @returns 指数移动平均
         */
        double MEMA(CVariable *var);
        /**
         * 计算最小值
         * @param var  变量
         * @returns 最小百货值
         */
        double MIN2(CVariable *var);
        /**
         * 计算最小值
         * @param var  变量
         * @returns 最小百货值
         */
        double MIN6(CVariable *var);
        /**
         * 返回分钟
         * @param var  变量
         * @returns 分钟
         */
        int MINUTE(CVariable *var);
        /**
         * 计算模
         * @param var  变量
         * @returns 模
         */
        double MOD(CVariable *var);
        /**
         * 返回月份
         * @param var  变量
         * @returns 月份
         */
        int MONTH(CVariable *var);
        /**
         * 返回累乘
         * @param var  变量
         * @returns 累乘
        */
        double MULAR(CVariable *var);
        /**
         * 返回是否持续存在X>Y
         * @param var  变量
         * @returns 是否存在
         */
        int NDAY(CVariable *var);
        /**
         * 当值为0时返回1,否则返回0
         * @param var  变量
         * @returns 1或0
         */
        int NOT(CVariable *var);
        /**
         * 添加线条
         * @param var  变量
         * @returns 0
         */
        double POLYLINE(CVariable *var);
        /**
        * A在B和C范围之间,B<A<C
         * @param var  变量
         * @returns 0
        */
        int RANGE(CVariable *var);
        /**
         * 计算次幂
         * @param var  变量
         * @returns 次幂
         */
        double POW(CVariable *var);
        /**
         * 获取随机数
         * @param var  变量
         * @returns 随机数
         */
        int RAND(CVariable *var);
        /**
         * 获取前推周期数值
         * @param var  变量
         * @returns 前推周期数值
         */
        double REF(CVariable *var);
        /**
         * 返回值
         * @param var  变量
         * @returns 值
         */
        double RETURN(CVariable *var);
        /**
         * 取反
         * @param var  变量
         * @returns 反值
         */
        double REVERSE(CVariable *var);
        /**
         * 计算四舍五入
         * @param var  变量
         * @returns 四舍五入值
         */
        double ROUND(CVariable *var);
        /**
         * 计算抛物线指标
         * @param var  变量
         * @returns 抛物线指标
         */
        double SAR(CVariable *var);
        /**
         * 抛物转向点
         * @param var  变量
         * @returns 状态
         */
        double SARTURN(CVariable *var);
        /**
         * 求0时后若干秒是什么时间
         * @param var  变量
         * @returns 状态
        */
        int SECTOTIME(CVariable *var);
        /**
         * 设置变量的值
         * @param var  变量
         * @returns 状态
         */
        double SET(CVariable *var);
        /**
         * 如果大于0则返回1,如果小于0则返回－1，否则返回0
         * @param var  变量
         * @returns 1,0,-1
         */
        int SGN(CVariable *var);
        /**
         * 计算正弦值
         * @param var  变量
         * @returns 正弦值
         */
        double SIN(CVariable *var);
        /**
         * 线性回归斜率
         * @param var  变量
         * @returns 结果
        */
        double SLOPE(CVariable *var);
        /**
         * 计算移动平均
         * @param var  变量
         * @returns 移动平均
         */
        double SMA(CVariable *var);
        /**
         * 计算平方根
         * @param var  变量
         * @returns 平方根
         */
        double SQRT(CVariable *var);
        /**
         * 计算平方
         * @param var  变量
         * @returns 平方
         */
        double SQUARE(CVariable *var);
        /**
         * 定义静态变量
         * @param var  变量
         * @returns 数值
         */
        double STATIC(CVariable *var);
        /**
         * 计算标准差
         * @param var  变量
         * @returns 标准差
         */
        double STDDEV(CVariable *var);
        /**
         * 计算估计标准差
         * @param var  变量
         * @returns 标准差
         */
        double STD(CVariable *var);
        /**
         * 添加柱状图
         * @param var  变量
         * @returns 0
         */
        double STICK(CVariable *var);
        /**
         * 添加柱状图
         * @param var  变量
         * @returns 0
         */
        double STICKLINE(CVariable *var);
        /*
        * 字符串转化为数字
        * @param var  变量
         * @returns 数值
        */
        double STR2CON(CVariable *var);
        /*
        * 将两个字符串A,B(非序列化)相加成一个字符串C.
        * @param var  变量
         * @returns 数值
        */
        int STRCAT(CVariable *var);
        /*
        * 字符串附带一空格
        * @param var  变量
         * @returns 数值
        */
        int STRSPACE(CVariable *var);
        /*
        * 比较两个字符串A,B是否相等.
        * @param var  变量
         * @returns 数值
        */
        int STRCMP(CVariable *var);
        /**
         * 计算求和
         * @param var  变量
         * @returns 和
         */
        double SUM(CVariable *var);
        /**
         * 计算正切值
         * @param var  变量
         * @returns 正切值
         */
        double TAN(CVariable *var);
        /**
         * 取得该周期的时分,适用于日线以下周期
         * @param var  变量
         * @returns 时分
         */
        int TIME(CVariable *var);
        /**
         * 取得该周期的时分,适用于日线以下周期
         * @param var  变量
         * @returns 时分秒
         */
        int TIME2(CVariable *var);
        /**
         * 求指定时刻距0时有多长时间
         * @param var  变量
         * @returns 数值
        */
        int TIMETOSEC(CVariable *var);
        /**
         * 计算递归移动平均
         * @param var  变量
         * @returns 递归移动平均
         */
        double TMA(CVariable *var);
        /*
        * 计算真实波幅
        * @param var  变量
         * @returns 数值
        */
        double TR(CVariable *var);
        /**
         * 返回是否连涨周期数
         * @param var  变量
         * @returns 是否连涨周期数
         */
        int UPNDAY(CVariable *var);
        /**
         * 添加柱状图
         * @param var  变量
         * @returns 0
         */
        double VOLSTICK(CVariable *var);
        /**
        * 取得该周是年内第几个周
         * @param var  变量
         * @returns 数值
        */
        int WEEKOFYEAR(CVariable *var);
        /**
        * 取得该周期的星期数
         * @param var  变量
         * @returns 数值
        */
        int WEEKDAY(CVariable *var);
        /**
         * 当条件成立时,取当前值,否则取上个值
         * @param var  变量
         * @returns 数值
         */
        double VALUEWHEN(CVariable *var);
        /**
         * 总体样本方差
         * @param var  变量
         * @returns 数值
        */
        double VARP(CVariable *var);
        /**
         * 估算样本方差
         * @param var  变量
         * @returns 数值
        */
        double VAR(CVariable *var);
        /**
         * 定义变量
         * @param var  变量
         * @returns 数值
         */
        double VAR2(CVariable *var);
        /**
         * 执行WHILE循环
         * @param var  变量
         * @returns 状态
         */
        int WHILE(CVariable *var);
        /**
         * 计算加权移动平均线
         * @param var  变量
         * @returns 加权移动平均
         */
        double WMA(CVariable *var);
        /**
         * 计算年份
         * @param var  变量
         * @returns 年份
         */
        int YEAR(CVariable *var);
        /**
         * 计算之字反转
         * @param var  变量
         * @returns 之字反转
         */
        double ZIG(CVariable *var);
    public:
        /**
         * 连接字符串
         * @param var  变量
         * @returns 结果
         */
        int STR_CONTACT(CVariable *var);
        /**
         * 比较字符串是否相等
         * @param var  变量
         * @returns 位置
         */
        int STR_EQUALS(CVariable *var);
        /**
         * 查找字符串中出现文字的位置
         * @param var  变量
         * @returns 位置
         */
        int STR_FIND(CVariable *var);
        /**
         * 查找字符串中最后出现文字的位置
         * @param var  变量
         * @returns 位置
         */
        int STR_FINDLAST(CVariable *var);
        /**
         * 获取字符串的长度
         * @param var  变量
         * @returns 长度
         */
        int STR_LENGTH(CVariable *var);
        /**
         * 截取字符串
         * @param var  变量
         * @returns 结果
         */
        int STR_SUBSTR(CVariable *var);
        /**
         * 替换字符串
         * @param var  变量
         * @returns 结果
         */
        int STR_REPLACE(CVariable *var);
        /**
         * 切割字符串
         * @param var  变量
         * @returns 结果
         */
        int STR_SPLIT(CVariable *var);
        /**
         * 字符串转化为小写
         * @param var  变量
         * @returns 结果
         */
        int STR_TOLOWER(CVariable *var);
        /**
         * 字符串转化为大写
         * @param var  变量
         * @returns 结果
         */
        int STR_TOUPPER(CVariable *var);
        /**
         * 添加数据到集合
         * @param var  变量
         * @returns 结果
         */
        int LIST_ADD(CVariable *var);
        /**
         * 清除集合
         * @param var  变量
         * @returns 结果
         */
        int LIST_CLEAR(CVariable *var);
        /**
         * 从集合中获取数据
         * @param var  变量
         * @returns 结果
         */
        int LIST_GET(CVariable *var);
        /**
         * 向集合中插入数据
         * @param var  变量
         * @returns 结果
         */
        int LIST_INSERT(CVariable *var);
        /**
         * 从集合中移除数据
         * @param var  变量
         * @returns 结果
         */
        int LIST_REMOVE(CVariable *var);
        /**
         * 获取集合的大小
         * @param var  变量
         * @returns 结果
         */
        int LIST_SIZE(CVariable *var);
        /**
         * 清除哈希表
         * @param var  变量
         * @returns 结果
         */
        int MAP_CLEAR(CVariable *var);
        /**
         * 哈希表是否包含键
         * @param var  变量
         * @returns 结果
         */
        int MAP_CONTAINSKEY(CVariable *var);
        /**
         * 获取哈希表的值
         * @param var  变量
         * @returns 结果
         */
        int MAP_GET(CVariable *var);
        /**
         * 获取哈希表的键
         * @param var  变量
         * @returns 结果
         */
        int MAP_GETKEYS(CVariable *var);
        /**
         * 从哈希表中移除
         * @param var  变量
         * @returns 结果
         */
        int MAP_REMOVE(CVariable *var);
        /**
         * 向哈希表中添加数据
         * @param var  变量
         * @returns 结果
         */
        int MAP_SET(CVariable *var);
        /**
         * 获取哈希表的尺寸
         * @param var  变量
         * @returns 结果
         */
        int MAP_SIZE(CVariable *var);
    public:
        /*
         * Avedev
         */
        static double avedev(double value, double *listForAvedev, int listForAvedev_length, double avg);
        /*
         * 平均值
         */
        static double avgValue(double *list, int length);
        /*
        * 协方差
        */
        double covar(double *list1, int length1, double avg1, double *list2, int length2, double avg2);
        /*
        * 数据偏差平方和
        */
        double devsq(double *list, int length, double avg);
        /*
         * 指数移动平滑平均
         */
        static double exponentialMovingAverage(int n, double value, double lastEMA);
        /*
         * 斐波那契
         */
        static int fibonacciValue(int index);
        /*
         * 线性回归
         */
        static void linearRegressionEquation(double *list, int length, float *k, float *b);
        /*
         * 最大值
         */
        static double maxValue(double *list, int length);
        /*
         * 最小值
         */
        static double minValue(double *list, int length);
        /*
         * 平均值
         */
        static double movingAverage(int index, int n, double value, struct LPDATA last_MA);
        /*
         * 标准差
         */
        static double standardDeviationDev(double *list, int length, double avg,  double standardDeviation);
        /*
         * 估计标准差
         */
        static double standardDeviation(double *list, int length, double avg,  double standardDeviation);
        /*
        * 估算样本方差
        */
        double standardVar(double *list, int length, double avg);
        /*
        * 总体样本方差
        */
        double standardVarDev(double *list, int length, double avg);
        /*
         * 简单移动平均
         */
        static double simpleMovingAverage(double close, double lastSma, int n, int m);
        /*
         * 求和
         */
        static double sumilationValue(int index, int n, double value, struct LPDATA last_SUM);
        /*
         * 求和
         */
        static double sumValue(double *list, int length);
        /*
         * 加权移动平均
         */
        static double weightMovingAverage(int n, int weight, double value, double lastWMA);
    };
}
#endif
