# bigfigure-calculator
a calculator that can calculate big figures. 一个大数计算器
这个大数计算器 目前只完成了乘法 ，具体怎么用运行big_number.exe就知道了
我没有拿草稿纸进行过验算
但是我算过一些小的数 ，以及一些稍微大一点的数  他们和我的计算器答案一致


**这个计算器的目的是为了算出哪些难以用普通计算器计算出的巨大数字**
比如：38213845434531245322453242423242*345324532432456576867567866575675675
理论上来讲
无论你的手在数字键盘上滑多久，只要你按照提示输入，他都能得到正确的答案
但是为了防止意外发生，我将目前的可计算的数字长度设为了30000位（包括符号在内）
对确实这限制了计算器的能力
所以如果你想试一下更大的数，我建议你更改源码中的 algo.cpp
44行的数字（目前它是30000）。
但是你的电脑可能会有一定风险。

日后我会打算补全加减乘除四则运算


**原理**
这个计算器是通过将数字转为字符后，使用递归，以类似于人类的乘法方式，来进行计算，具体的原理较为复杂，可以看源码注释。
