#ifndef MFHSSD1306_h
#define MFHSSD1306_h

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class MFHSSD {
  public:
    MFHSSD();
    
    // 基本显示功能
    void print(const String &text);
    void print(const char *text);
    void print(int number);
    void print(float number);
    void print(double number);
    
    // 滚屏功能
    void println(const String &text);  // 打印并换行（真正的滚屏）
    void println(const char *text);
    void println(int number);
    void println(float number);
    void println(double number);
    
    void clear();                      // 清屏
    void empty();                      // 清屏（与clear功能相同）
    void setCursor(int x, int y);      // 设置光标位置（用于单行显示）
    
    // 显示控制
    void display();                    // 更新显示

  private:
    Adafruit_SSD1306 *_display;
    bool _initialized;
    int _textSize;
    
    // 滚屏相关变量
    String _lines[8];  // 存储8行文本（128x64屏幕大约显示8行）
    int _lineCount;    // 当前存储的行数
    void _scrollDisplay(); // 内部滚屏函数
};

#endif