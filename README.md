# Racket-Ex
Racket Exercise

- #### .vscode/tasks.json文件: 配置自动执行(cmd+shift+B)

- #### "taskName": Use the label property instead(改用标签属性)
- #### "command": The actual command to execute(要执行的实际命令)
- #### "isShellCommand": Use the "type": "shell" property instead.(改用“type”：“shell”属性。)
- #### "isBuildCommand": Use the "group": "build" property instead.(使用“group”：“build”属性来代替。)
- #### "showOutput": 控制输出窗口的行为，always:输出窗口永远被放到前台。这是默认值.
- #### "args": ["${relativeFile}"] : 
```
- 运行输出的参数  
- the current opened file relative to the workspace folder containing the file
- 从当前打开的文件夹到当前打开的文件的路径 (> Executing task: racket 2.discount.rkt <)
- 如 当前打开的是test文件夹，当前的打开的是main.c，并有test / first / second / main.c
- 那么此变量代表的是  first / second / main.c 
```
- #### "presentation": {"panel": "new"} :重新打开一个terminal panel。

***
#### Hamming https://github.com/w326004741/Racket-Ex/tree/master/hamming


## Reference
- [VScode-tasks.json Chinese Document](https://jeasonstudio.gitbooks.io/vscode-cn-doc/content/md/%E7%BC%96%E8%BE%91%E5%99%A8/%E4%BB%BB%E5%8A%A1.html)
