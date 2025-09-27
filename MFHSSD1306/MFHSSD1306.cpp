#include "MFHSSD1306.h"

MFHSSD::MFHSSD() {
  _display = new Adafruit_SSD1306(128, 64, &Wire, -1);
  _initialized = false;
  _textSize = 1;
  _lineCount = 0;
  
  // 初始化行数组
  for(int i = 0; i < 8; i++) {
    _lines[i] = "";
  }
}

void MFHSSD::_scrollDisplay() {
  if (!_initialized) return;
  
  _display->clearDisplay();
  _display->setTextSize(_textSize);
  _display->setTextColor(SSD1306_WHITE);
  
  // 计算每行的高度（根据字体大小）
  int lineHeight = 8 * _textSize;
  int y = 0;
  
  // 显示所有行
  for(int i = 0; i < _lineCount; i++) {
    _display->setCursor(0, y);
    _display->print(_lines[i]);
    y += lineHeight;
  }
  
  _display->display();
}

void MFHSSD::println(const String &text) {
  if (!_initialized) {
    // 尝试常见的I2C地址
    if (!_display->begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
      _display->begin(SSD1306_SWITCHCAPVCC, 0x3D);
    }
    _initialized = true;
  }
  
  // 如果已经达到最大行数，先向上滚动
  if (_lineCount >= 8) {
    // 将第2行到第8行上移，删除第1行
    for(int i = 0; i < 7; i++) {
      _lines[i] = _lines[i + 1];
    }
    _lines[7] = text;  // 新文本放在最后一行
  } else {
    // 还有空间，直接添加新行
    _lines[_lineCount] = text;
    _lineCount++;
  }
  
  // 更新显示
  _scrollDisplay();
}

void MFHSSD::println(const char *text) {
  println(String(text));
}

void MFHSSD::println(int number) {
  println(String(number));
}

void MFHSSD::println(float number) {
  println(String(number));
}

void MFHSSD::println(double number) {
  println(String(number));
}

// 原有的print函数（单行显示，不滚屏）
void MFHSSD::print(const String &text) {
  if (!_initialized) {
    if (!_display->begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
      _display->begin(SSD1306_SWITCHCAPVCC, 0x3D);
    }
    _display->clearDisplay();
    _display->setTextSize(_textSize);
    _display->setTextColor(SSD1306_WHITE);
    _display->setCursor(0, 0);
    _initialized = true;
  }
  
  _display->print(text);
  _display->display();
}

void MFHSSD::print(const char *text) {
  print(String(text));
}

void MFHSSD::print(int number) {
  print(String(number));
}

void MFHSSD::print(float number) {
  print(String(number));
}

void MFHSSD::print(double number) {
  print(String(number));
}

void MFHSSD::clear() {
  if (_initialized) {
    _display->clearDisplay();
    _display->display();
  }
  // 同时清空行数组
  for(int i = 0; i < 8; i++) {
    _lines[i] = "";
  }
  _lineCount = 0;
}

// empty函数 - 与clear功能完全相同
void MFHSSD::empty() {
  clear(); // 直接调用clear函数
}

void MFHSSD::setCursor(int x, int y) {
  if (_initialized) {
    _display->setCursor(x, y);
  }
}

void MFHSSD::display() {
  if (_initialized) {
    _display->display();
  }
}