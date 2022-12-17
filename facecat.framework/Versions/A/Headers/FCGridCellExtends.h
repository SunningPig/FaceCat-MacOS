/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifndef __FCGRIDCELLEXTENDS_H__
#define __FCGRIDCELLEXTENDS_H__
#pragma once
#include "stdafx.h"
#include "FCGridCell.h"
#include "FCGridColumn.h"
#include "FCGridRow.h"
#include "FCGrid.h"

namespace FaceCat{
    class FCGridCell;
    class FCGridColumn;
    class FCGridRow;
    class FCGrid;
    class FCButton;
    class FCCheckBox;
    class FCComboBox;
    class FCDateTimePicker;
    class FCLabel;
    class FCSpin;
    class FCRadioButton;
    class FCTextBox;
    
    /*
     * 布尔型单元格
     */
    class FCGridBoolCell : public FCGridCell{
    public:
        /**
         * 数值
         */
        bool m_value;
    public:
        FCGridBoolCell();
        FCGridBoolCell(bool value);
        virtual ~FCGridBoolCell();
    public:
        /**
         * 单元格大小比较，用于排序
         */
        virtual int compareTo(FCGridCell *cell);
        /**
         * 获取布尔型数值
         */
        virtual bool getBool();
        /**
         * 获取双精度浮点值
         */
        virtual double getDouble();
        /**
         * 获取单精度浮点值
         */
        virtual float getFloat();
        /**
         * 获取整型数值
         */
        virtual int getInt();
        /**
         * 获取长整型数值
         */
        virtual Long getLong();
        /**
         * 获取字符型数值
         */
        virtual String getString();
        /**
         * 设置布尔型数值
         */
        virtual void setBool(bool value);
        /**
         * 设置双精度浮点值
         */
        virtual void setDouble(double value);
        /**
         * 设置单精度浮点值
         */
        virtual void setFloat(float value);
        /**
         * 设置整型数值
         */
        virtual void setInt(int value);
        /**
         * 设置长整型数值
         */
        virtual void setLong(Long value);
        /**
         * 设置字符型数值
         */
        virtual void setString(const String& value);
    };
    
    /*
     * 按钮型单元格
     */
    class FCGridButtonCell: public FCGridViewCell{
    public:
        FCGridButtonCell();
        virtual ~FCGridButtonCell();
        FCButton* getButton();
    };
    
    /*
     * 复选框型单元格
     */
    class FCGridCheckBoxCell : public FCGridViewCell{
    public:
    public:
        FCGridCheckBoxCell();
        virtual ~FCGridCheckBoxCell();
        FCCheckBox* getCheckBox();
    public:
        /**
         * 获取布尔型数值
         */
        virtual bool getBool();
        /**
         * 获取双精度浮点值
         */
        virtual double getDouble();
        /**
         * 获取单精度浮点值
         */
        virtual float getFloat();
        /**
         * 获取整型数值
         */
        virtual int getInt();
        /**
         * 获取长整型数值
         */
        virtual Long getLong();
        /**
         * 获取布尔型数值
         */
        virtual String getString();
        /**
         * 设置布尔型数值
         */
        virtual void setBool(bool value);
        /**
         * 设置双精度浮点值
         */
        virtual void setDouble(double value);
        /**
         * 设置单精度浮点值
         */
        virtual void setFloat(float value);
        /**
         * 设置整型数值
         */
        virtual void setInt(int value);
        /**
         * 设置长整型数值
         */
        virtual void setLong(Long value);
        /**
         * 设置字符型数值
         */
        virtual void setString(const String& value);
    };
    
    /*
     * 下拉列表单元格
     */
    class FCGridComboBoxCell : public FCGridViewCell{
    public:
        FCGridComboBoxCell();
        virtual ~FCGridComboBoxCell();
        FCComboBox* getComboBox();
    public:
        virtual bool getBool();
        virtual double getDouble();
        virtual float getFloat();
        virtual int getInt();
        virtual Long getLong();
        virtual String getString();
        virtual void setBool(bool value);
        virtual void setDouble(double value);
        virtual void setFloat(float value);
        virtual void setInt(int value);
        virtual void setLong(Long value);
        virtual void setString(const String& value);
    };
    
    /*
     * 日期时间选择单元格
     */
    class FCGridDateTimePickerCell : public FCGridViewCell{
    public:
        FCGridDateTimePickerCell();
        virtual ~FCGridDateTimePickerCell();
        FCDateTimePicker* getDatePicker();
    };
    
    /*
     * 图层单元格
     */
    class FCGridDivCell : public FCGridViewCell{
    public:
        FCGridDivCell();
        virtual ~FCGridDivCell();
        FCDiv* getDiv();
    };
    
    /*
     * 双精度单元格
     */
    class FCGridDoubleCell : public FCGridCell{
    public:
        int m_digit;
        double m_value;
    public:
        FCGridDoubleCell();
        FCGridDoubleCell(double value);
        virtual ~FCGridDoubleCell();
        virtual int getDigit();
        virtual void setDigit(int value);
        virtual String getPaintText();
    public:
        virtual int compareTo(FCGridCell *cell);
        virtual bool getBool();
        virtual double getDouble();
        virtual float getFloat();
        virtual int getInt();
        virtual Long getLong();
        virtual String getString();
        virtual void setBool(bool value);
        virtual void setDouble(double value);
        virtual void setFloat(float value);
        virtual void setInt(int value);
        virtual void setLong(Long value);
        virtual void setString(const String& value);
    };
    
    /*
     * 单精度单元格
     */
    class FCGridFloatCell : public FCGridCell{
    public:
        float m_value;
    public:
        FCGridFloatCell();
        FCGridFloatCell(float value);
        virtual ~FCGridFloatCell();
    public:
        virtual int compareTo(FCGridCell *cell);
        virtual bool getBool();
        virtual double getDouble();
        virtual float getFloat();
        virtual int getInt();
        virtual Long getLong();
        virtual String getString();
        virtual void setBool(bool value);
        virtual void setDouble(double value);
        virtual void setFloat(float value);
        virtual void setInt(int value);
        virtual void setLong(Long value);
        virtual void setString(const String& value);
    };
    
    /*
     * 整型单元格
     */
    class FCGridIntCell : public FCGridCell{
    public:
        int m_value;
    public:
        FCGridIntCell();
        FCGridIntCell(int value);
        virtual ~FCGridIntCell();
    public:
        virtual int compareTo(FCGridCell *cell);
        virtual bool getBool();
        virtual double getDouble();
        virtual float getFloat();
        virtual int getInt();
        virtual Long getLong();
        virtual String getString();
        virtual void setBool(bool value);
        virtual void setDouble(double value);
        virtual void setFloat(float value);
        virtual void setInt(int value);
        virtual void setLong(Long value);
        virtual void setString(const String& value);
    };
    
    /*
     * 标签单元格
     */
    class FCGridLabelCell : public FCGridViewCell{
    public:
        FCGridLabelCell();
        virtual ~FCGridLabelCell();
        FCLabel* getLabel();
    };
    
    /*
     * 长整型单元格
     */
    class FCGridLongCell : public FCGridCell{
    public:
        Long m_value;
    public:
        FCGridLongCell();
        FCGridLongCell(Long value);
        virtual ~FCGridLongCell();
    public:
        virtual int compareTo(FCGridCell *cell);
        virtual bool getBool();
        virtual double getDouble();
        virtual float getFloat();
        virtual int getInt();
        virtual Long getLong();
        virtual String getString();
        virtual void setBool(bool value);
        virtual void setDouble(double value);
        virtual void setFloat(float value);
        virtual void setInt(int value);
        virtual void setLong(Long value);
        virtual void setString(const String& value);
    };
    
    /*
     * 单选框单元格
     */
    class FCGridRadioButtonCell : public FCGridViewCell{
    public:
        FCGridRadioButtonCell();
        virtual ~FCGridRadioButtonCell();
        FCRadioButton* getRadioButton();
    public:
        virtual bool getBool();
        virtual double getDouble();
        virtual float getFloat();
        virtual int getInt();
        virtual Long getLong();
        virtual String getString();
        virtual void setBool(bool value);
        virtual void setDouble(double value);
        virtual void setFloat(float value);
        virtual void setInt(int value);
        virtual void setLong(Long value);
        virtual void setString(const String& value);
    };
    
    /*
     * 数值文本框单元格
     */
    class FCGridSpinCell : public FCGridViewCell{
    public:
        FCGridSpinCell();
        virtual ~FCGridSpinCell();
        FCSpin* getSpin();
    public:
        virtual bool getBool();
        virtual double getDouble();
        virtual float getFloat();
        virtual int getInt();
        virtual Long getLong();
        virtual void setBool(bool value);
        virtual void setDouble(double value);
        virtual void setFloat(float value);
        virtual void setInt(int value);
        virtual void setLong(Long value);
    };
    
    /*
     * 字符串单元格
     */
    class FCGridStringCell : public FCGridCell{
    public:
        String m_value;
    public:
        FCGridStringCell();
        FCGridStringCell(const String& value);
        virtual ~FCGridStringCell();
    public:
        virtual int compareTo(FCGridCell *cell);
        virtual bool getBool();
        virtual double getDouble();
        virtual float getFloat();
        virtual int getInt();
        virtual Long getLong();
        virtual String getString();
        virtual void setString(const String& value);
    };
    
    /*
     * 密码单元格
     */
    class FCGridPasswordCell : public FCGridStringCell{
    public:
        FCGridPasswordCell();
        virtual ~FCGridPasswordCell();
    public:
        virtual String getPaintText();
    };
    
    /*
     * 文本框单元格
     */
    class FCGridTextBoxCell: public FCGridViewCell{
    public:
        FCGridTextBoxCell();
        virtual ~FCGridTextBoxCell();
        FCTextBox* getTextBox();
    };

    /*
    * 小数点型文本框
    */
    class FCGridPercentCell : public FCGridDoubleCell{
    public:
        FCGridPercentCell();
        FCGridPercentCell(double value);
    public:
        virtual String getPaintText();
    };
}
#endif
