# 算法练习
* Leetcode
* 牛客网

## vscode配置C++环境
* 见.vscode文件配置

## vscode添加Code Runner
* 下载Code Runner插件  
![图片找不到了](https://raw.githubusercontent.com/JialiLiuu/mygit/algorithm-question/picture/codeRunner_1.png)
* 文件 -> 首选项 -> 设置，打开VS Code设置页面，找到 Run Code configuration，勾上 Run In Terminal 选项。设置之后，代码就会在 Terminal 中运行了  
![图片找不到了](https://raw.githubusercontent.com/JialiLiuu/mygit/algorithm-question/picture/codeRunner_2.png)
* 找到 Executor Map 设置项，并且选择 在settings.json中编辑  
![图片找不到了](https://raw.githubusercontent.com/JialiLiuu/mygit/algorithm-question/picture/codeRunner_3.png)
```
"code-runner.executorMap": {
        
        "cpp": " cd $dir && g++ $fileName -D LOCAL -o        
        ..\\exe\\$fileNameWithoutExt.exe && 
        ..\\exe\\$fileNameWithoutExt.exe",
    },
```
[参考1](https://www.cnblogs.com/bananan/p/15039582.html)  
[参考2](https://blog.csdn.net/GU_bigbull/article/details/107265699)
