# jquery教程
- jquery代码全部写在以下代码块内
    $(document).ready(function(){
      <!-- jquery代码 -->
      });
## 一些特效函数

- 隐藏 hide()
- 显示 show()
- 隐藏和显示依次 toggle()
- 淡入 fadeIn()
- 淡出 fadeOut()
- 淡入 淡出依次执行 fadeToggle()
- 渐变成指定的不透明度 fadeTo()
- 向上滑动 slideUp()
- 向下滑动 slideDown()
- 向上 向下滑动依次执行 slideToggle()
- 动画 animate({css代码},speed,callback)
- 停止 stop() 这一函数适用于所有jquery效果函数

## 对html的内容、属性、值

- 获取或者修改指定标签的文本内容（不包括其中的html标签） text()
- 获取或者修改指定标签的内容 （包括其中的html标签） html()
- 获取或者修改表单的value值 val()
- 获取或者修改指定标签的属性值 attr()

## 添加html元素标签
- 在被选元素内部的结尾添加元素或者文本内容  append()
- 在被选元素内部的开头添加元素或者文本内容  prepend()
- 在被选元素之后添加内容  after()
- 在被选元素之前添加内容  before()

## 删除html元素
- 删除被选元素，包括子元素  remove()
- 删除被选元素的子元素  empty()

## 对css进行操作
- 给被选元素添加一个或者多个类 addClass()
- 删除被选元素的类 removeClass()
- 切换进行被选元素的添加、删除  toggleClass()
- 设置或者返回被选元素的css样式  css()

## 改变或者返回被选元素的高度、宽度
- width()
- height()
- innerWidth()
- innerHeight()
- outerWidth()
- outerHeight()

## 遍历DOM树
- 向上遍历
  - 返回直接父元素 parent()
  - 返回所有祖先元素 parents()
  - 返回被选元素与指定元素之间的所有祖先元素 parentsUntil()
- 向下遍历
  - 返回被选元素的所有直接子元素 children()
  - 返回被选元素的所有子元素 find()
- 水平遍历
  - 返回被选元素的所有同胞元素 siblings()   sublings ‘兄弟姐妹’的意思
  - 返回下一个同胞元素  next()
  - 返回所有同胞元素 nextAll()
  - 返回被选元素与指定元素之间的所有同胞元素 nextUntil()
  - 返回上一个同胞元素 prev()
  - 返回位于前面的所有同胞元素 prevAll()
  - prevUntil()

## Ajax
> Ajax 简单来说就是在不重载整个页面的情况下，Ajax通过后台加载数据并现实

- 从服务器加载数据并放到被选元素中  load(url,data,callback)
  > calloback函数有三个参数：
    - responseTxt - 包含调用成功时的结果内容
    - statusTXT - 包含调用的状态
    - xhr - 包含 XMLHttpRequest 对象

- $.get(url,data,callback)
- $.post(url,data,callback)
- $.ajax()   这个函数通常在前面的无法实现功能时使用

