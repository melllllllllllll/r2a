#RomanNumeralsConverter
##使用说明
在linux命令行输入以下命令：
`cd RomanNumeralsConverter`
`gcc r2b.c`
`./a.out`
即进入交互界面:
- 输入罗马数字如`CXXIII`**(大写字母)**, 则输出对应阿拉伯数字`123`的字符图像表示；
- 内置命令`set size n`**(小写字母)**可以设置输出字符图像的大小，n为任意大于等于`1`的数字；
- `exit`**(小写字母)**命令退出程序；
- 非以上输入**(大小写敏感)**则视为非法输入，则输出字符`E`的字符图像表示，程序等待下一输入。

##源代码注释
程序包含两个源文件`graph.h`和`r2b.c`。
`graph.h`中以字符数组定义了`012345679E`的字符图像表示，如下为`0`的表示方法:
```c
char zero[5][3] = {{' ', '-', ' '},
                   {'|', ' ', '|'},
                   {' ', ' ', ' '},
                   {'|', ' ', '|'},
                   {' ', '-', ' '}};
```
在此头文件中，使用如下语句创建了各个字符与对应字符表示数组的映射:
```c
typedef char graph_arr[5][3];
graph_arr *graphs[70] = {['0'] = &zero,
                         ['1'] = &one,
                         ['2'] = &two,
                         ['3'] = &three,
                         ['4'] = &four,
                         ['5'] = &five,
                         ['6'] = &six,
                         ['7'] = &seven,
                         ['8'] = &eight,
                         ['9'] = &nine,
                         ['E'] = &error};
```
------------
`r2b.c`中负责罗马数字的转化和输出字符图像绘制。
此源文件定义了四个函数，如下:
```c
int r2a(char *str);
void draw(int num);
void draw_str(char *str);
int check(char *str);
```
`main`函数如下:
```c
int main(int argc, char *argv[])
{
    char input[50] = "";
    while (fgets(input, sizeof(input), stdin) != NULL)
    {
        // 若遇到空行，进入下个命令等待环节
        if (input[0] == '\n')
            continue;
        // 将读入的换行符替换，方便后续处理
        if (input[strlen(input) - 1] == '\n')
            input[strlen(input) - 1] = '\0';

        if (strcmp(input, "exit") == 0)
            break;
        else if (strstr(input, "set size"))
            size = atoi(input + strlen("set size "));
        else if(check(input))
            draw(-1);
        else
            draw(r2a(input));
    }
    return 0;
}
```
`check`函数负责验证输入字符串的合法性，源代码如下:
```c
int check(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        // 只要含有非罗马数字字符，则视为非法输入
        if (strchr("IVXLCDM", str[i]) == NULL)
            return -1;
    return 0;
}
```
`r2b`函数进行罗马数字字符串到阿拉伯数字的转换，源代码如下:
```c
int r2a(char *str)
{
    int roman[89] = {['I'] = 1,
                     ['V'] = 5,
                     ['X'] = 10,
                     ['L'] = 50,
                     ['C'] = 100,
                     ['D'] = 500,
                     ['M'] = 1000};
    int sum = roman[str[0]];
    int len = strlen(str);

    for (int i = 0; i < len - 1; i++)
        if (roman[str[i]] >= roman[str[i + 1]])
            sum += roman[str[i + 1]];
        else
            sum += roman[str[i + 1]] - 2 * roman[str[i]];
    return sum;
}
```
字符图像绘制功能由两个函数实现，分别为`draw`和`draw_str`，源代码如下:
```c
// 在此函数中，将错误码 -1 或转换成功的阿拉伯数字的
// 对应字符串传给draw_str函数去绘制
void draw(int num)
{
    if (num == -1)
        draw_str("E");
    else
    {
        char str[50] = "";
        sprintf(str, "%d", num);
        draw_str(str);
    }
}

void draw_str(char *str)
{
    char *p = NULL;
    graph_arr *graph;

    // 在基础的字符图形阵列里，共有五行需要绘制
    for (int i = 0; i < 5; i++)
        // 在奇数行需要将横行绘制size次
        for (int j = 0; j < size; j++)
        {
            //绘制相应字符的第i行
            p = str;
            while (*p != '\0')
            {
                graph = graphs[*p];
                printf("%c", (*graph)[i][0]);
                // 在基础的字符图像阵列里，第1列需要绘制size次
                for (int k = 0; k < size; k++)
                    printf("%c", (*graph)[i][1]);
                printf("%c", (*graph)[i][2]);
                p++;
            }
            printf("\n");
            // 若为偶数行，直接break，绘制下一行
            if (i % 2 == 0)
                break;
        }
}
```
改变输出字符图像的功能直接使用了全局变量`size`实现，每次输出字符图像时，相关函数`draw_str`会访问`size`变量，默认大小为`1`。
