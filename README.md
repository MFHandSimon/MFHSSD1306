# MFHSSD1306
嘿嘿
此Arduino库为MFHandSimon所写，
以下为引导步骤：

i)
若你想添加此库：
首先，下载“MFHSSD1306.zip”；
      下载完成后放到绝对不会误删的文件夹中。
其次，在Arduino中选择 :  Sketch -> Include Library -> Add .Zip Library -> 选择你存放“MFHSSD1306.zip”的路径；
      当IDE显示如下：<img width="629" height="55" alt="image" src="https://github.com/user-attachments/assets/91a1891d-da46-4573-9aaf-ff359b2c5ab0" />时，你已成功添加此库
ii)
若你想使用此库：
以下是库全部包含的代码：
  print();        //简单的打印
  println();      //打印且换行
  empty();        //清屏
  clear();        //等同于empty(),根据个人习惯选择
是的没了
emmm关于使用，一下是实例代码：
<img width="533" height="300" alt="image" src="https://github.com/user-attachments/assets/4a16f9db-e779-414e-9fb1-51a52a78ac9a" />
可以看到，使用时:
                先用"  MFHSSD <名字>  " 
                再用"  <名字>.<功能>  "
来完成某功能。

需注意,MFHandSimon在写"println()"函数时考虑到了换行，所以如果让OLED显示的行数超过八行，OLED会删除第一杠，第二行变为第一行，以此类推，最后一行永远是最新的数据，示例代码：
<img width="409" height="311" alt="image" src="https://github.com/user-attachments/assets/a349160e-1ae7-4668-9145-f323dc0fd526" />
这个代码可以从1000显示到0；
可以自动滚屏。

以下代码是常用实例：
<img width="595" height="710" alt="image" src="https://github.com/user-attachments/assets/78e3eed8-67e7-41e4-b13e-8d7483bfd628" />
